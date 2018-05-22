/*
/env/mac OS
/compiler/gcc
lexer written by flex
parser written by bison

After I kill all types except for integer, I feel so good.
Of course, users can use string constant still; However, we cannot define a string-type variable.
Moreover, real-type and bool-type variables cannot be defined either, but boolean expression like greater-than, less-than, etc, can be used normally.

May 16, 2018
No READ statements.
No declaration or use of arrays.
No floating-point numbers.
No string variables.

So good, I suppose. Therefore, I delete all the above, let alone the function return string.
In the main function, I deal with the new file for our king java.

May 17, 2018
Insert ID into symbol table at the parser, instead of in the scanner.
The constant variable just let it go now, and the bool-type is as well.
Statement part regarding with return
Fucking problem with the function, it can just print its shit upside-down.

May 18, 2018
Fn is the last part for code generation.
integer_exp return stringVal.
I have to deal with the confusion of function name.

May 20, 2018
Now, I have to deal with the problem between global variable and local variable.
Try to set a flag to stand for whether the variable is a global variable or not in symbol table.

May 21, 2018
Now, try to solve expression, conditional, and loop.
line 472, put arg name into arg table
Now, it is time to solve conditional and loop.
line 475 problem about bus error
line 736, now I have to clarify why it is going like this.
line 1181, think about how to solve that UMINUS in print statement.

May 22, 2018
try to deal with loop and local variable problem cause now every variable is global
Now, try to solve loop and UMINUS problem
*/
%{
#include "symbols.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define Trace(t, line)        printf(t, line) // Trace where the error occurs and print the line number
#define List(str)             strcat(buffer, str);
#define Write(str)            fprintf(javaa, str);

/* standard size for string type in rust- programming language */
#ifndef STRSIZE
#define STRSIZE     40
#endif

/* standard size for struct Parameter type */
#ifndef PARAMSIZE
#define PARAMSIZE   40
#endif

/* The global_declaration doesn't have function scope which means it doesn't in any function */
#ifndef PROGRAM
#define PROGRAM     ""
#endif

#ifndef MAX_LINE_SIZE
#define MAX_LINE_SIZE 1024
#endif

#define true 1
#define false 0

extern FILE* yyin;
extern FILE* yyout;
extern int linenum;
extern int yylex();
FILE* javaa;        //file for bytecode
char* file;         // filename without extension

char arg[STRSIZE][STRSIZE]; // record the names of arguments in the current function

char ifstmt[MAX_LINE_SIZE]; // if statement buffer
short ifFlag = 0;           // 1 means if only, 2 means if plus else

char loopstmt[MAX_LINE_SIZE]; // while statement buffer
short loopFlag = 0; // 1 means while statement exist now

char out[4][MAX_LINE_SIZE]; // print buffer

char opbuf[4][MAX_LINE_SIZE];  // operator buffer
short opcount = 0;

short cur_block = 0; // for ifstmt and loopstmt

char buffer[MAX_LINE_SIZE]; // reserve the code generation in the func

int counter = 0; // cause we have some local variables, I use this counter to record the number of next one.
char constant[STRSIZE][STRSIZE]; // record constant for generation

int L = 0; // stage counter

void yyerror(char* msg);
int             stoi(char *str);
char*           itos(int i, char b[]);
%}

%union{
    char* stringVal;
    double floatVal;
    int intVal;
    bool boolVal;
    list_t* symptr;
    Param* parptr; // struct Parameter type
}

/* tokens */
%token <floatVal> REAL
%token <stringVal> ID STRING INTEGER
%token <boolVal> TRUE FALSE
%token INT FLOAT STR BOOL
%token BREAK CHAR CONTINUE DO ELSE
%token ENUM EXTERN FOR
%token FN IF IN LET 
%token LOOP MATCH MUT PRINT PRINTLN
%token RETURN SELF STATIC STRUCT
%token USE WHERE WHILE
%token READ PUB

/* operator tokens */
%token COMMA COLON SEMICOLON L_BRACE R_BRACE L_SB R_SB L_B R_B
%token LESS GREATER ASSIGN EXCLAMATION ARROW
%token LE GE E NE AND OR AE ME TE DE
%token AA MM
%token ADD MINUS TIME DIVIDE
%token MODULUS

/* precedence for operators */
%left OR
%left AND
%left EXCLAMATION
%left LESS LE GE GREATER E NE
%left ADD MINUS
%left TIME DIVIDE MODULUS
%left UMINUS

/* types */
%type <stringVal> string_exp integer_exp
%type <boolVal> bool_exp
%type <parptr> formal_argument formal_arguments comma_separated_exps comma_separated_exp
%type <symptr> function_invocation

%start program              /* the initial entry point */

%%
program:        functions | global_declaration functions
                ;

global_declaration:     global_declaration constant_declaration
                        | global_declaration variable_declaration
                        | constant_declaration
                        | variable_declaration
                        ;

local_declaration:      local_declaration constant_declaration
                        | local_declaration variable_declaration
                        | constant_declaration
                        | variable_declaration
                        ;

block:          start local_declaration statements end               
                | start local_declaration end                         
                | start statements end                                
                | start end                                           
                ;

end:            R_B                                                 {
                                                                    incr_scope();
                                                                    counter = 0;
                                                                    }
                ;

start:          L_B                                                 {
                                                                    hide_scope();
                                                                    }
                ;

constant_declaration:   LET ID ASSIGN integer_exp SEMICOLON         {
                                                                    list_t* t_glob = lookup_scope($2, 0);
                                                                    list_t* t_cur = lookup($2);

                                                                    if (t_glob == NULL && t_cur == NULL)
                                                                    {
                                                                        insert($2, strlen($2), CONST_INT_TYPE, linenum, func);
                                                                        list_t* t = lookup($2);
                                                                        t->st_ival = stoi($4);
                                                                        t->st_sval = strdup($4);
                                                                        for (int i = 0; i < STRSIZE; i++)
                                                                        {
                                                                            if (constant[i] != NULL)
                                                                            {
                                                                                constant[i][0] = '\0';
                                                                                strncpy(constant[i], $2, strlen($2));
                                                                                break;
                                                                            }
                                                                        }
                                                                    }
                                                                    else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                    }        
                        | LET ID COLON INT ASSIGN integer_exp SEMICOLON     {
                                                                            list_t* t_glob = lookup_scope($2, 0);
                                                                            list_t* t_cur = lookup($2);

                                                                            if (t_glob == NULL && t_cur == NULL)
                                                                            {
                                                                                insert($2, strlen($2), CONST_INT_TYPE, linenum, func);
                                                                                list_t* t = lookup($2);
                                                                                t->st_ival = stoi($6);
                                                                                t->st_sval = strdup($6);
                                                                                for (int i = 0; i < STRSIZE; i++)
                                                                                {
                                                                                    if (constant[i] != NULL)
                                                                                    {
                                                                                        constant[i][0] = '\0';
                                                                                        strncpy(constant[i], $2, strlen($2));
                                                                                        break;
                                                                                    }
                                                                                }
                                                                            }
                                                                            else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                            }
                        ;

variable_declaration:   LET MUT ID SEMICOLON                            {
                                                                        list_t* t_glob = lookup_scope($3, 0);
                                                                        list_t* t_cur = lookup($3);

                                                                        if (t_cur == NULL && cur_scope == 1)
                                                                        {
                                                                            insert($3, strlen($3), UNDEF, linenum, func);
                                                                            list_t* t = lookup($3);
                                                                            t->glob_flag = 0;
                                                                            t->counter = counter;
                                                                            counter++;
                                                                        }
                                                                        if (t_glob == NULL && cur_scope == 0)
                                                                        {
                                                                            insert($3, strlen($3), UNDEF, linenum, func);
                                                                            t_glob = lookup($3);
                                                                            t_glob->glob_flag = 1;
                                                                            fprintf(javaa, "field static int %s\n", $3);
                                                                        }
                                                                        else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                        }
                        | LET MUT ID COLON INT SEMICOLON                {
                                                                        list_t* t_glob = lookup_scope($3, 0);
                                                                        list_t* t_cur = lookup($3);

                                                                        if (t_cur == NULL && cur_scope == 1)
                                                                        {
                                                                            insert($3, strlen($3), INT_TYPE, linenum, func);
                                                                            list_t* t = lookup($3);
                                                                            t->glob_flag = 0;
                                                                            t->counter = counter;
                                                                            counter++;
                                                                        }
                                                                        else if (t_glob == NULL && cur_scope == 0)
                                                                        {
                                                                            insert($3, strlen($3), INT_TYPE, linenum, func);
                                                                            t_glob = lookup($3);
                                                                            t_glob->glob_flag = 1;
                                                                            fprintf(javaa, "field static int %s\n", $3);
                                                                        }
                                                                        else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                        }
                        | LET MUT ID ASSIGN integer_exp SEMICOLON       {
                                                                        list_t* t_glob = lookup_scope($3, 0);
                                                                        list_t* t_cur = lookup($3);

                                                                        if (t_cur == NULL && cur_scope == 1)
                                                                        {
                                                                            insert($3, strlen($3), INT_TYPE, linenum, func);
                                                                            list_t* t = lookup($3);
                                                                            t->glob_flag = 0;
                                                                            t->counter = counter;
                                                                            t->st_ival = stoi($5);
                                                                            t->st_sval = strdup($5);
                                                                            counter++;
                                                                            List("  sipush ");
                                                                            
                                                                            List($5);
                                                                            
                                                                            List("\n");
                                                                            List("  istore_");
                                                                            
                                                                            char n[STRSIZE];
                                                                            sprintf(n, "%d", t->counter);
                                                                            List(n);
                                                                            
                                                                            List("\n\n");
                                                                        }
                                                                        else if (t_glob == NULL && cur_scope == 0)
                                                                        {
                                                                            insert($3, strlen($3), INT_TYPE, linenum, func);
                                                                            list_t* t = lookup($3);
                                                                            t->glob_flag = 1;
                                                                            t->st_ival = stoi($5);
                                                                            t->st_sval = strdup($5);
                                                                            fprintf(javaa, "field static int %s = %s\n", $3, $5);
                                                                        }
                                                                        else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                        }        
                        | LET MUT ID COLON INT ASSIGN integer_exp SEMICOLON     {
                                                                                list_t* t_glob = lookup_scope($3, 0);
                                                                                list_t* t_cur = lookup($3);

                                                                                if (t_cur == NULL && cur_scope == 1)
                                                                                {
                                                                                    insert($3, strlen($3), INT_TYPE, linenum, func);
                                                                                    list_t* t = lookup($3);
                                                                                    t->glob_flag = 0;
                                                                                    t->counter = counter;
                                                                                    t->st_ival = stoi($7);
                                                                                    t->st_sval = strdup($7);
                                                                                    counter++;
                                                                                    List("  sipush ");
                                                                                    
                                                                                    List($7);
                                                                                    
                                                                                    List("\n");
                                                                                    List("  istore_");

                                                                                    char n[STRSIZE];
                                                                                    sprintf(n, "%d", t->counter);
                                                                                    List(n);

                                                                                    List("\n\n");
                                                                                }
                                                                                else if (t_glob == NULL && cur_scope == 0)
                                                                                {
                                                                                    insert($3, strlen($3), INT_TYPE, linenum, func);
                                                                                    t_glob = lookup($3);
                                                                                    t_glob->glob_flag = 1;
                                                                                    fprintf(javaa, "field static int %s = %s\n", $3, $7);
                                                                                }
                                                                                else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                                }
                        ;

fn_start:       L_BRACE                 {
                                        incr_scope();
                                        }
                ;

fn_block:       L_B local_declaration statements end                
                | L_B local_declaration end                         
                | L_B statements end                                
                | L_B end                                           
                ;

functions:      functions functions                                      
                | function
                ;

function:       FN ID fn_start R_BRACE fn_block                     {
                                                                    func = strdup($2);
                                                                    list_t* t_glob = lookup_scope($2, 0);

                                                                    if (t_glob == NULL)
                                                                    {
                                                                        insert($2, strlen($2), FUNCTION_TYPE, linenum, func);
                                                                        list_t* t = lookup($2);
                                                                        t->inf_type = UNDEF;
                                                                        t->parameters = NULL;
                                                                        t->num_of_pars = 0;

                                                                        if (strcmp($2, "main") == 0)
                                                                            fprintf(javaa, "\nmethod public static void main(java.lang.String[])\n");
                                                                        else
                                                                            fprintf(javaa, "\nmethod public static void %s()\n", $2);
                                                                        
                                                                        fprintf(javaa, "max_stack 15\n");
                                                                        fprintf(javaa, "max_locals 15\n");
                                                                        fprintf(javaa, "{\n\n");
                                                                        fprintf(javaa, "%s", buffer);
                                                                        fprintf(javaa, "%s", ifstmt);
                                                                        ifstmt[0] = '\0';
                                                                        if (ifFlag == 2)
                                                                        {
                                                                            fprintf(javaa, "%s", out[1]);
                                                                            out[1][0] = '\0';
                                                                            fprintf(javaa, "%s", out[2]);
                                                                            out[2][0] = '\0';
                                                                            fprintf(javaa, "%s", out[0]);
                                                                            out[0][0] = '\0';
                                                                            if (out[3] != NULL)
                                                                            {
                                                                                fprintf(javaa, "%s", out[3]);
                                                                                out[3][0] = '\0';
                                                                            }
                                                                            ifFlag = 0;
                                                                        }
                                                                        else
                                                                        {
                                                                            for (int i = 0; i < 4; i++)
                                                                            {
                                                                                if (out[i] != NULL)
                                                                                {
                                                                                    fprintf(javaa, "%s", out[i]);
                                                                                    out[i][0] = '\0';
                                                                                }
                                                                                else
                                                                                {
                                                                                    break;
                                                                                }
                                                                            }
                                                                        }
                                                                        buffer[0] = '\0';
                                                                        fprintf(javaa, "  return\n");
                                                                        fprintf(javaa, "}\n");
                                                                    }
                                                                    else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                    }
                | FN ID fn_start formal_arguments R_BRACE fn_block  {
                                                                    func = strdup($2);
                                                                    list_t* t_glob = lookup_scope($2, 0);

                                                                    if (t_glob == NULL)
                                                                    {
                                                                        insert($2, strlen($2), FUNCTION_TYPE, linenum, func);
                                                                        list_t* t = lookup($2);
                                                                        t->inf_type = UNDEF;
                                                                        t->parameters = $4;
                                                                        t->num_of_pars = 0;

                                                                        Param *p = $4;
                                                                        while (p != NULL)
                                                                        {
                                                                            t->num_of_pars++;
                                                                            p = p->next;
                                                                        }
                                                                        printf("Num of pars is %d\n", t->num_of_pars);

                                                                        fprintf(javaa, "\nmethod public static void %s(", $2);
                                                                        for (int i = 0; i < t->num_of_pars - 1; i++)
                                                                        {
                                                                            fprintf(javaa, "int, ");
                                                                        }
                                                                        fprintf(javaa, "int)\n");
                                                                        fprintf(javaa, "max_stack 15\n");
                                                                        fprintf(javaa, "max_locals 15\n");
                                                                        fprintf(javaa, "{\n\n");
                                                                        fprintf(javaa, "%s", buffer);
                                                                        fprintf(javaa, "%s", ifstmt);
                                                                        ifstmt[0] = '\0';
                                                                        
                                                                        for (int i = 2; i >= 0; i--)
                                                                        {   
                                                                            if (out[i] != NULL)
                                                                            {
                                                                                fprintf(javaa, "%s", out[i]);
                                                                                out[i][0] = '\0';
                                                                            }
                                                                            else
                                                                            {
                                                                                break;
                                                                            }
                                                                        }
                                                                        buffer[0] = '\0';
                                                                        fprintf(javaa, "  return\n");
                                                                        fprintf(javaa, "}\n");

                                                                        //clear argument table after exit current func
                                                                        for(int i = 0; i < STRSIZE; i++) arg[i][0] = '\0';
                                                                    }
                                                                    else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                    }
                | FN ID fn_start R_BRACE ARROW INT fn_block         {
                                                                    func = strdup($2);
                                                                    list_t* t_glob = lookup_scope($2, 0);

                                                                    if (t_glob == NULL)
                                                                    {
                                                                        insert($2, strlen($2), FUNCTION_TYPE, linenum, func);
                                                                        list_t* t = lookup($2);
                                                                        t->inf_type = INT_TYPE;
                                                                        t->parameters = NULL;
                                                                        t->num_of_pars = 0;

                                                                        fprintf(javaa, "\nmethod public static int %s()\n", $2);
                                                                        fprintf(javaa, "max_stack 15\n");
                                                                        fprintf(javaa, "max_locals 15\n");
                                                                        fprintf(javaa, "{\n\n");
                                                                        fprintf(javaa, "%s", buffer);
                                                                        fprintf(javaa, "%s", ifstmt);
                                                                        ifstmt[0] = '\0';
                                                                        
                                                                        for (int i = 2; i >= 0; i--)
                                                                        {   
                                                                            if (out[i] != NULL)
                                                                            {
                                                                                fprintf(javaa, "%s", out[i]);
                                                                                out[i][0] = '\0';
                                                                            }
                                                                            else
                                                                            {
                                                                                break;
                                                                            }
                                                                        }
                                                                        buffer[0] = '\0';
                                                                        fprintf(javaa, "}\n");
                                                                    }
                                                                    else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                    }
                | FN ID fn_start formal_arguments R_BRACE ARROW INT fn_block{
                                                                            func = strdup($2);
                                                                            list_t* t_glob = lookup_scope($2, 0);

                                                                            if (t_glob == NULL)
                                                                            {
                                                                                insert($2, strlen($2), FUNCTION_TYPE, linenum, func);
                                                                                list_t* t = lookup($2);
                                                                                t->inf_type = INT_TYPE;
                                                                                t->parameters = $4;
                                                                                t->num_of_pars = 0;

                                                                                Param *p = $4;
                                                                                while (p != NULL)
                                                                                {
                                                                                    t->num_of_pars++;
                                                                                    p = p->next;
                                                                                }
                                                                                printf("Num of pars is %d\n", t->num_of_pars);

                                                                                fprintf(javaa, "\nmethod public static int %s(", $2);
                                                                                for(int i = 0; i < t->num_of_pars - 1; i++)
                                                                                {
                                                                                    fprintf(javaa, "int, ");
                                                                                }
                                                                                fprintf(javaa, "int)\n");
                                                                                fprintf(javaa, "max_stack 15\n");
                                                                                fprintf(javaa, "max_locals 15\n");
                                                                                fprintf(javaa, "{\n\n");
                                                                                fprintf(javaa, "%s", buffer);
                                                                                fprintf(javaa, "%s", ifstmt);
                                                                                ifstmt[0] = '\0';
                                                                                
                                                                                for (int i = 2; i >= 0; i--)
                                                                                {   
                                                                                    if (out[i] != NULL)
                                                                                    {
                                                                                        fprintf(javaa, "%s", out[i]);
                                                                                        out[i][0] = '\0';
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        break;
                                                                                    }
                                                                                }
                                                                                buffer[0] = '\0';
                                                                                fprintf(javaa, "}\n");

                                                                                //clear argument table after exit current func
                                                                                for(int i = 0; i < STRSIZE; i++) arg[i][0] = '\0';
                                                                            }
                                                                            else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                            }
                ;

formal_arguments:   formal_argument                                     {
                                                                            $1->next = NULL;
                                                                            $$ = $1;
                                                                        }
                    | formal_arguments COMMA formal_arguments           {
                                                                            $1->next = $3;
                                                                            $$ = $1;
                                                                        }                                                                                                           
                    ;

formal_argument:        ID COLON INT                                    {
                                                                        list_t* t = lookup($1);
                                                                        Param* p = malloc(sizeof(Param));
                                                         
                                                                        if (t == NULL)
                                                                        {
                                                                            insert($1, strlen($1), INT_TYPE, linenum, func);
                                                                            t = lookup($1);
                                                                            p->par_type = INT_TYPE;
                                                                            p->param_name = strdup($1);
                                                                            p->ival = 0; // initialize
                                                                            p->sval = strdup(""); // initialize
                                                                            p->passing = BY_VALUE;
                                                                            p->next = NULL;
                                                                            p->counter = counter;
                                                                            t->counter = counter;
                                                                            strncpy(arg[counter], t->st_name, strlen(t->st_name)); // put the name of a argument in the argument table
                                                                            counter += 1;
                                                                            $$ = p;
                                                                        }
                                                                        else if (t != NULL && strcmp(t->func, PROGRAM) == 0)
                                                                        {
                                                                            p->par_type = INT_TYPE;
                                                                            p->param_name = strdup($1);
                                                                            p->ival = 0; // initialize
                                                                            p->sval = strdup(""); // initialize
                                                                            p->passing = BY_VALUE;
                                                                            p->next = NULL;
                                                                            p->counter = counter;
                                                                            t->counter = counter;
                                                                            strncpy(arg[counter], t->st_name, strlen(t->st_name)); // put the name of a argument in the argument table
                                                                            counter += 1;
                                                                            $$ = p;
                                                                        }
                                                                        else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                        }
                        ;

statements:     statements statement
                | statement
                ;

statement:      ID ASSIGN integer_exp SEMICOLON                     {
                                                                    list_t* t_cur = lookup($1);
                                                                    if (t_cur != NULL && (t_cur->st_type == INT_TYPE || t_cur->st_type == UNDEF))
                                                                    {
                                                                        t_cur->st_type = INT_TYPE;
                                                                        t_cur->st_ival = stoi($3);
                                                                        t_cur->st_sval = strdup($3);

                                                                        if (t_cur->glob_flag == 1)
                                                                        {
                                                                            List("  putstatic int "); List(file); List("."); List(t_cur->st_name); List("\n\n");
                                                                        }
                                                                        else
                                                                        {
                                                                            List("  sipush "); List($3); List("\n");
                                                                            char a[STRSIZE];
                                                                            List("  istore_"); List(itos(t_cur->counter, a)); List("\n\n");
                                                                        }
                                                                    }
                                                                    else if (t_cur != NULL && (t_cur->st_type != INT_TYPE || t_cur->st_type != UNDEF))
                                                                    {
                                                                        Trace("line %d: The type does not match.\n", linenum);
                                                                    }
                                                                    else Trace("line %d: Identifier does not define.\n", linenum);
                                                                    }
                | PRINT integer_exp SEMICOLON   {
                                                char name[STRSIZE];
                                                int neg = 0;
                                                if ($2[0] == '-')
                                                {
                                                    neg = 1; // judge whether it is a negative number or not
                                                    for (int i = 1; i < strlen($2); i++) name[i - 1] = $2[i];
                                                    name[strlen($2) - 1] = '\0';
                                                    opbuf[opcount][0] = '\0';
                                                    opcount--;
                                                }else for (int i = 0; i < strlen($2); i++) name[i] = $2[i];
                                                name[strlen($2)] = '\0';
                                                
                                                strcat(out[cur_block], "  getstatic java.io.PrintStream java.lang.System.out\n");

                                                list_t* t = lookup(name);
                                                if (t->glob_flag == 1)
                                                {
                                                    strcat(out[cur_block], "  getstatic int "); strcat(out[cur_block], file); strcat(out[cur_block], "."); strcat(out[cur_block], t->st_name); strcat(out[cur_block], "\n");
                                                }
                                                else if (t->glob_flag == 0)
                                                {
                                                    char a[STRSIZE];
                                                    strcat(out[cur_block], "  iload_"); strcat(out[cur_block], itos(t->counter, a)); strcat(out[cur_block], "\n");
                                                }
                                                else
                                                {
                                                    strcat(out[cur_block], "  ldc "); strcat(out[cur_block], $2); strcat(out[cur_block], "\n");
                                                }
                                                if (neg == 1) strcat(out[cur_block], "  ineg\n");
                                                strcat(out[cur_block], "  invokevirtual void java.io.PrintStream.print(int)\n\n");
                                                cur_block += 1;
                                                }       
                | PRINT string_exp SEMICOLON    {
                                                strcat(out[cur_block], "  getstatic java.io.PrintStream java.lang.System.out\n");
                                                strcat(out[cur_block], "  ldc "); strcat(out[cur_block], $2); strcat(out[cur_block], "\n");
                                                strcat(out[cur_block], "  invokevirtual void java.io.PrintStream.print(java.lang.String)\n\n");
                                                cur_block += 1;
                                                }
                | PRINTLN integer_exp SEMICOLON {
                                                char name[STRSIZE];
                                                int neg = 0;
                                                if ($2[0] == '-')
                                                {
                                                    neg = 1; // judge whether it is a negative number or not
                                                    for (int i = 1; i < strlen($2); i++) name[i - 1] = $2[i];
                                                    name[strlen($2) - 1] = '\0';
                                                }else for (int i = 0; i < strlen($2); i++) name[i] = $2[i];
                                                name[strlen($2)] = '\0';
                                                
                                                strcat(out[cur_block], "  getstatic java.io.PrintStream java.lang.System.out\n");

                                                list_t* t = lookup(name);
                                                if (t->glob_flag == 1)
                                                {
                                                    strcat(out[cur_block], "  getstatic int "); strcat(out[cur_block], file); strcat(out[cur_block], "."); strcat(out[cur_block], t->st_name); strcat(out[cur_block], "\n");
                                                }
                                                else if (t->glob_flag == 0)
                                                {
                                                    char a[STRSIZE];
                                                    strcat(out[cur_block], "  iload_"); strcat(out[cur_block], itos(t->counter, a)); strcat(out[cur_block], "\n");
                                                }
                                                else 
                                                {
                                                    strcat(out[cur_block], "  ldc "); strcat(out[cur_block], $2); strcat(out[cur_block], "\n");
                                                }
                                                if (neg == 1) strcat(out[cur_block], "  ineg\n");
                                                strcat(out[cur_block], "  invokevirtual void java.io.PrintStream.println(int)\n\n");
                                                cur_block += 1;
                                                }
                | PRINTLN string_exp SEMICOLON  {
                                                strcat(out[cur_block], "  getstatic java.io.PrintStream java.lang.System.out\n");
                                                strcat(out[cur_block], "  ldc "); strcat(out[cur_block], $2); strcat(out[cur_block], "\n");
                                                strcat(out[cur_block], "  invokevirtual void java.io.PrintStream.println(java.lang.String)\n\n");
                                                cur_block += 1;
                                                }
                | RETURN SEMICOLON              {
                                                out[cur_block][0] = '\0';
                                                strcat(out[cur_block], "  return\n\n");
                                                cur_block += 1;
                                                }
                | RETURN integer_exp SEMICOLON  {
                                                out[cur_block][0] = '\0';
                                                strcat(out[cur_block], "  ireturn\n\n");
                                                cur_block += 1;
                                                }
                | conditional
                | loop
                ;

conditional:    IF L_BRACE bool_exp R_BRACE block ELSE block    {
                                                                char l[STRSIZE];
                                                                strcat(ifstmt, "L"); strcat(ifstmt, itos(L, l)); strcat(ifstmt, ":\n  ifeq L"); strcat(ifstmt, itos(L+1, l)); strcat(ifstmt, "\n");
                                                                strcat(out[1], "  goto L"); strcat(out[1], itos(L+2, l)); strcat(out[1], "\n\nL"); strcat(out[1], itos(L+1, l)); strcat(out[1], ":\n");
                                                                char b[MAX_LINE_SIZE];
                                                                b[0] = '\0';
                                                                strcat(b, "L"); strcat(b, itos(L+2, l)); strcat(b, ":\n");
                                                                strcat(b, out[0]);
                                                                strncpy(out[0], b, MAX_LINE_SIZE);
                                                                cur_block = 0;
                                                                ifFlag = 2;
                                                                L += 2;
                                                                }
                | IF L_BRACE bool_exp R_BRACE block             {
                                                                char l[STRSIZE];
                                                                strcat(ifstmt, "L"); strcat(ifstmt, itos(L, l)); strcat(ifstmt, ":\n  ifeq L"); strcat(ifstmt, itos(L+1, l)); strcat(ifstmt, "\n");
                                                                strcat(out[0], "L"); strcat(out[0], itos(L+1, l)); strcat(out[0], ":\n");
                                                                cur_block = 0;
                                                                ifFlag = 1;
                                                                L += 1;
                                                                }
                ;

loop:           WHILE L_BRACE bool_exp R_BRACE block    {
                                                        
                                                        }
                ;

bool_exp:       integer_exp                             {
                                                        int i = stoi($1);
                                                        if (i)
                                                        {
                                                            $$ = 1;
                                                        }
                                                        else
                                                        {
                                                            $$ = 0;
                                                        }
                                                        }
                | TRUE                                  {
                                                            $$ = $1;
                                                        }
                | FALSE                                 {
                                                            $$ = $1;
                                                        }
                ;

comma_separated_exps:   comma_separated_exp             {
                                                                $1->next = NULL;
                                                                $$ = $1;
                                                        }
                        | comma_separated_exps COMMA comma_separated_exps   {
                                                                                $1->next = $3;
                                                                                $$ = $1;
                                                                            }                                                                                                                              
                        ;

comma_separated_exp:    ID                                  {
                                                                Param *t = malloc(sizeof(Param));
                                                                list_t* t_cur = lookup($1);
                                                                list_t* t_glob = lookup_scope($1, 0);

                                                                if (t_glob != NULL)
                                                                {
                                                                    if (t_glob->st_type == INT_TYPE)
                                                                    {
                                                                        t->par_type = INT_TYPE;
                                                                        t->param_name = strdup($1);
                                                                        t->ival = t_glob->st_ival;
                                                                        t->sval = strdup(t_glob->st_sval);
                                                                    }
                                                                }
                                                                else if (t_cur != NULL && strcmp(t_cur->func, PROGRAM) == 1)
                                                                {
                                                                    if (t_cur->st_type == INT_TYPE)
                                                                    {
                                                                        t->par_type = INT_TYPE;
                                                                        t->param_name = strdup($1);
                                                                        t->ival = t_cur->st_ival;
                                                                        t->sval = strdup(t_cur->st_sval);
                                                                    }
                                                                }
                                                                else Trace("line %d: The type dose not match.\n", linenum);

                                                                t->next = NULL;
                                                                $$ = t;
                                                            }
                        | INTEGER                           {
                                                                Param *t = malloc(sizeof(Param));
                                                                t->param_name = strdup($1);
                                                                t->ival = stoi($1);
                                                                t->sval = strdup($1);
                                                                t->par_type = INT_TYPE;
                                                                t->next = NULL;
                                                                $$ = t;
                                                            }
                        ;

function_invocation:       ID L_BRACE R_BRACE   {
                                                list_t* t = lookup_scope($1, 0);
                                                $$ = t;
                                                if (t->st_type == FUNCTION_TYPE)
                                                {
                                                    switch(t->inf_type)
                                                    {
                                                        case INT_TYPE:
                                                        $$->inf_type = INT_TYPE;
                                                        $$->st_ival = 1; // temp
                                                        $$->st_sval = strdup("");
                                                        break;
                                                        default:
                                                        $$->inf_type = UNDEF;
                                                    }
                                                }
                                                else
                                                {
                                                    Trace("line %d: The type does not match.\n", linenum);
                                                }
                                                }
                           | ID L_BRACE comma_separated_exps R_BRACE{
                                                                    list_t* t = lookup_scope($1, 0);
                                                                    $$ = t;
                                                                    if (t->st_type == FUNCTION_TYPE)
                                                                    {
                                                                        switch(t->inf_type)
                                                                        {
                                                                            case INT_TYPE:
                                                                            $$->inf_type = INT_TYPE;
                                                                            $$->st_ival = 1; // temp
                                                                            $$->st_sval = strdup("");
                                                                            break;
                                                                            default:
                                                                            $$->inf_type = UNDEF;
                                                                        }

                                                                        Param *t1 = t->parameters;
                                                                        Param *t2 = $3;
                                                                        int count = 0;

                                                                        while (t1 != NULL)
                                                                        {
                                                                            if (t2 == NULL)
                                                                            {
                                                                                Trace("line %d: The numbers of parameters are different.\n", linenum);
                                                                                break;
                                                                            }
                                                                            else
                                                                            {
                                                                                list_t* temp = lookup(t2->param_name);
                                                                                if (temp != NULL && temp->glob_flag == 1)
                                                                                {
                                                                                    List("  getstatic int "); List(file); List("."); List(temp->st_name); List("\n");
                                                                                }
                                                                                else
                                                                                {
                                                                                    List("  sipush "); List(t2->sval); List("\n");
                                                                                }
                                                                            }

                                                                            if (t1->par_type != t2->par_type)
                                                                            {
                                                                                Trace("line %d: The types of parameters are different.\n", linenum);
                                                                                break;
                                                                            }

                                                                            count++;
                                                                            t1 = t1->next;
                                                                            t2 = t2->next;
                                                                        }

                                                                        if (t2 != NULL)
                                                                        {
                                                                            count++;
                                                                            Trace("line %d: The numbers of parameters are different.\n", linenum);
                                                                        }
                                                                        printf("Num of pars is %d\n", t->num_of_pars);
                                                                        printf("Num of that user give is %d\n", count);

                                                                        if (t->num_of_pars == count)
                                                                        {
                                                                            List("  invokestatic int "); List(file); List("."); List(t->st_name); List("(");
                                                                            for (int i = 0; i < t->num_of_pars - 1; i++)
                                                                            {
                                                                                List("int, ");
                                                                            }
                                                                            List("int)\n");
                                                                        }
                                                                        else yyerror("The numbers of parameters are different.");
                                                                    }
                                                                    else
                                                                    {
                                                                        Trace("line %d: The type does not match.\n", linenum);
                                                                    }
                                                                    }
                            ;

integer_exp:    integer_exp ADD integer_exp             {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        char a[STRSIZE];
                                                        
                                                        if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 1 && strcmp(t1->func, PROGRAM) == 0 && strcmp(t2->func, PROGRAM) == 0)
                                                        {
                                                            List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                            List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                        }
                                                        else if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 0 && strcmp(t1->func, PROGRAM) == 0 && arg[t1->counter] == NULL)
                                                        {
                                                            List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                            List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                        }
                                                        else if (t1 != NULL && t1->glob_flag == 0 && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0 && arg[t2->counter] == NULL)
                                                        {
                                                            List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                            List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                        }
                                                        else if (t1 != NULL && t1->glob_flag == 1 && t2 == NULL && strcmp(t1->func, PROGRAM) == 0)
                                                        {
                                                            List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                            List("  sipush "); List($3); List("\n");
                                                        }
                                                        else if (t1 == NULL && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0)
                                                        {
                                                            List("  sipush "); List($1); List("\n");
                                                            List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                        }
                                                        else if (t1 != NULL && t2 != NULL)
                                                        {
                                                            List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                            List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                        }
                                                        else if (t1 != NULL && t2 == NULL)
                                                        {
                                                            List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                            List("  sipush "); List($3); List("\n");
                                                        }
                                                        else if (t1 == NULL && t2 != NULL)
                                                        {
                                                            List("  sipush "); List($1); List("\n");
                                                            List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                        }
                                                        else
                                                        {
                                                            List("  sipush "); List($1); List("\n");
                                                            List("  sipush "); List($3); List("\n");
                                                        }
                                                        List("  iadd\n\n");

                                                        // return part
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi($1); j = stoi($3);
                                                        sum = i + j;
                                                        $$ = strdup(itos(sum, b));
                                                        }
                | integer_exp MINUS integer_exp         {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        char a[STRSIZE];
                                                        
                                                        if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 1 && strcmp(t1->func, PROGRAM) == 0 && strcmp(t2->func, PROGRAM) == 0)
                                                        {
                                                            List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                            List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                        }
                                                        else if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 0 && strcmp(t1->func, PROGRAM) == 0 && arg[t1->counter] == NULL)
                                                        {
                                                            List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                            List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                        }
                                                        else if (t1 != NULL && t1->glob_flag == 0 && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0 && arg[t2->counter] == NULL)
                                                        {
                                                            List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                            List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                        }
                                                        else if (t1 != NULL && t1->glob_flag == 1 && t2 == NULL && strcmp(t1->func, PROGRAM) == 0)
                                                        {
                                                            List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                            List("  sipush "); List($3); List("\n");
                                                        }
                                                        else if (t1 == NULL && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0)
                                                        {
                                                            List("  sipush "); List($1); List("\n");
                                                            List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                        }
                                                        else if (t1 != NULL && t2 != NULL)
                                                        {
                                                            List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                            List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                        }
                                                        else if (t1 != NULL && t2 == NULL)
                                                        {
                                                            List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                            List("  sipush "); List($3); List("\n");
                                                        }
                                                        else if (t1 == NULL && t2 != NULL)
                                                        {
                                                            List("  sipush "); List($1); List("\n");
                                                            List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                        }
                                                        else
                                                        {
                                                            List("  sipush "); List($1); List("\n");
                                                            List("  sipush "); List($3); List("\n");
                                                        }
                                                        List("  isub\n\n");

                                                        // return part
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi($1); j = stoi($3);
                                                        sum = i - j;
                                                        $$ = strdup(itos(sum, b));
                                                        }
                | integer_exp TIME integer_exp          {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        char a[STRSIZE];
                                                        
                                                        if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 1 && strcmp(t1->func, PROGRAM) == 0 && strcmp(t2->func, PROGRAM) == 0)
                                                        {
                                                            List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                            List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                        }
                                                        else if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 0 && strcmp(t1->func, PROGRAM) == 0 && arg[t1->counter] == NULL)
                                                        {
                                                            List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                            List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                        }
                                                        else if (t1 != NULL && t1->glob_flag == 0 && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0 && arg[t2->counter] == NULL)
                                                        {
                                                            List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                            List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                        }
                                                        else if (t1 != NULL && t1->glob_flag == 1 && t2 == NULL && strcmp(t1->func, PROGRAM) == 0)
                                                        {
                                                            List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                            List("  sipush "); List($3); List("\n");
                                                        }
                                                        else if (t1 == NULL && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0)
                                                        {
                                                            List("  sipush "); List($1); List("\n");
                                                            List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                        }
                                                        else if (t1 != NULL && t2 != NULL)
                                                        {
                                                            List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                            List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                        }
                                                        else if (t1 != NULL && t2 == NULL)
                                                        {
                                                            List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                            List("  sipush "); List($3); List("\n");
                                                        }
                                                        else if (t1 == NULL && t2 != NULL)
                                                        {
                                                            List("  sipush "); List($1); List("\n");
                                                            List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                        }
                                                        else
                                                        {
                                                            List("  sipush "); List($1); List("\n");
                                                            List("  sipush "); List($3); List("\n");
                                                        }
                                                        List("  imul\n\n");

                                                        // return part
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi($1); j = stoi($3);
                                                        sum = i * j;
                                                        $$ = strdup(itos(sum, b));
                                                        }
                | integer_exp DIVIDE integer_exp        {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        char a[STRSIZE];
                                                        
                                                        if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 1 && strcmp(t1->func, PROGRAM) == 0 && strcmp(t2->func, PROGRAM) == 0)
                                                        {
                                                            List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                            List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                        }
                                                        else if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 0 && strcmp(t1->func, PROGRAM) == 0 && arg[t1->counter] == NULL)
                                                        {
                                                            List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                            List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                        }
                                                        else if (t1 != NULL && t1->glob_flag == 0 && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0 && arg[t2->counter] == NULL)
                                                        {
                                                            List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                            List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                        }
                                                        else if (t1 != NULL && t1->glob_flag == 1 && t2 == NULL && strcmp(t1->func, PROGRAM) == 0)
                                                        {
                                                            List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                            List("  sipush "); List($3); List("\n");
                                                        }
                                                        else if (t1 == NULL && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0)
                                                        {
                                                            List("  sipush "); List($1); List("\n");
                                                            List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                        }
                                                        else if (t1 != NULL && t2 != NULL)
                                                        {
                                                            List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                            List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                        }
                                                        else if (t1 != NULL && t2 == NULL)
                                                        {
                                                            List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                            List("  sipush "); List($3); List("\n");
                                                        }
                                                        else if (t1 == NULL && t2 != NULL)
                                                        {
                                                            List("  sipush "); List($1); List("\n");
                                                            List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                        }
                                                        else
                                                        {
                                                            List("  sipush "); List($1); List("\n");
                                                            List("  sipush "); List($3); List("\n");
                                                        }
                                                        List("  idiv\n\n");

                                                        // return part
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi($1); j = stoi($3);
                                                        if (j == 0) yyerror("line %d: Divided by zero.");
                                                        else
                                                        {
                                                            sum = i / j;
                                                            $$ = strdup(itos(sum, b));
                                                        }
                                                        }
                | integer_exp MODULUS integer_exp       {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        char a[STRSIZE];
                                                        
                                                        if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 1 && strcmp(t1->func, PROGRAM) == 0 && strcmp(t2->func, PROGRAM) == 0)
                                                        {
                                                            List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                            List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                        }
                                                        else if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 0 && strcmp(t1->func, PROGRAM) == 0 && arg[t1->counter] == NULL)
                                                        {
                                                            List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                            List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                        }
                                                        else if (t1 != NULL && t1->glob_flag == 0 && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0 && arg[t2->counter] == NULL)
                                                        {
                                                            List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                            List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                        }
                                                        else if (t1 != NULL && t1->glob_flag == 1 && t2 == NULL && strcmp(t1->func, PROGRAM) == 0)
                                                        {
                                                            List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                            List("  sipush "); List($3); List("\n");
                                                        }
                                                        else if (t1 == NULL && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0)
                                                        {
                                                            List("  sipush "); List($1); List("\n");
                                                            List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                        }
                                                        else if (t1 != NULL && t2 != NULL)
                                                        {
                                                            List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                            List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                        }
                                                        else if (t1 != NULL && t2 == NULL)
                                                        {
                                                            List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                            List("  sipush "); List($3); List("\n");
                                                        }
                                                        else if (t1 == NULL && t2 != NULL)
                                                        {
                                                            List("  sipush "); List($1); List("\n");
                                                            List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                        }
                                                        else
                                                        {
                                                            List("  sipush "); List($1); List("\n");
                                                            List("  sipush "); List($3); List("\n");
                                                        }
                                                        List("  irem\n\n");

                                                        // return part
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi($1); j = stoi($3);
                                                        sum = i % j;
                                                        $$ = itos(sum, b);
                                                        }
                | MINUS integer_exp %prec UMINUS        {
                                                        list_t* t = lookup($2);
                                                        if (t != NULL && strcmp(t->func, PROGRAM) == 0 && arg[t->counter] == NULL)
                                                        {
                                                            strcat(opbuf[opcount], "  getstatic int "); strcat(opbuf[opcount], file); strcat(opbuf[opcount], "."); strcat(opbuf[opcount], t->st_name); strcat(opbuf[opcount], "\n");
                                                        }
                                                        else if (t != NULL)
                                                        {
                                                            char a[STRSIZE];
                                                            strcat(opbuf[opcount], "  iload_"); strcat(opbuf[opcount], itos(t->counter, a)); strcat(opbuf[opcount], "\n");
                                                        }
                                                        else
                                                        {
                                                            strcat(opbuf[opcount], "  sipush "); strcat(opbuf[opcount], $2); strcat(opbuf[opcount], "\n");
                                                        }
                                                        strcat(opbuf[opcount], "  ineg\n\n");
                                                        opcount += 1;

                                                        // return part
                                                        char b[STRSIZE];
                                                        b[0] = '-';
                                                        b[1] = '\0';
                                                        strcat(b, $2);
                                                        $$ = strdup(b);
                                                        }
                | L_BRACE integer_exp R_BRACE           {
                                                        $$ = strdup($2);
                                                        }
                | integer_exp LESS integer_exp          {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        char a[STRSIZE];
                                                        
                                                        if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 1 && strcmp(t1->func, PROGRAM) == 0 && strcmp(t2->func, PROGRAM) == 0)
                                                        {
                                                            List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                            List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                        }
                                                        else if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 0 && strcmp(t1->func, PROGRAM) == 0 && arg[t1->counter] == NULL)
                                                        {
                                                            List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                            List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                        }
                                                        else if (t1 != NULL && t1->glob_flag == 0 && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0 && arg[t2->counter] == NULL)
                                                        {
                                                            List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                            List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                        }
                                                        else if (t1 != NULL && t1->glob_flag == 1 && t2 == NULL && strcmp(t1->func, PROGRAM) == 0)
                                                        {
                                                            List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                            List("  sipush "); List($3); List("\n");
                                                        }
                                                        else if (t1 == NULL && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0)
                                                        {
                                                            List("  sipush "); List($1); List("\n");
                                                            List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                        }
                                                        else if (t1 != NULL && t2 != NULL)
                                                        {
                                                            List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                            List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                        }
                                                        else if (t1 != NULL && t2 == NULL)
                                                        {
                                                            List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                            List("  sipush "); List($3); List("\n");
                                                        }
                                                        else if (t1 == NULL && t2 != NULL)
                                                        {
                                                            List("  sipush "); List($1); List("\n");
                                                            List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                        }
                                                        else
                                                        {
                                                            List("  sipush "); List($1); List("\n");
                                                            List("  sipush "); List($3); List("\n");
                                                        }
                                                        List("  isub\n");
                                                        char l[STRSIZE];
                                                        List("  iflt L"); List(itos(L, l)); List("\n");
                                                        List("  iconst_0\n");
                                                        List("  goto L"); List(itos(L+1, l)); List("\n");
                                                        List("L"); List(itos(L, l)); List(":\n"); List("  iconst_1\n");
                                                        L++;
                                                                                       
                                                        // return part
                                                        int i, j;
                                                        i = stoi($1); j = stoi($3);
                                                        if (i < j)
                                                        {
                                                            $$ = strdup("1");
                                                        }
                                                        else
                                                        {
                                                            $$ = strdup("0");                                                        
                                                        }
                                                        }
                | integer_exp LE integer_exp    {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                char a[STRSIZE];
                                                        
                                                if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 1 && strcmp(t1->func, PROGRAM) == 0 && strcmp(t2->func, PROGRAM) == 0)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                    List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                }
                                                else if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 0 && strcmp(t1->func, PROGRAM) == 0 && arg[t1->counter] == NULL)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                    List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                }
                                                else if (t1 != NULL && t1->glob_flag == 0 && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0 && arg[t2->counter] == NULL)
                                                {
                                                    List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                    List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                }
                                                else if (t1 != NULL && t1->glob_flag == 1 && t2 == NULL && strcmp(t1->func, PROGRAM) == 0)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                    List("  sipush "); List($3); List("\n");
                                                }
                                                else if (t1 == NULL && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0)
                                                {
                                                    List("  sipush "); List($1); List("\n");
                                                    List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                }
                                                else if (t1 != NULL && t2 != NULL)
                                                {
                                                    List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                    List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                }
                                                else if (t1 != NULL && t2 == NULL)
                                                {
                                                    List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                    List("  sipush "); List($3); List("\n");
                                                }
                                                else if (t1 == NULL && t2 != NULL)
                                                {
                                                    List("  sipush "); List($1); List("\n");
                                                    List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                }
                                                else
                                                {
                                                    List("  sipush "); List($1); List("\n");
                                                    List("  sipush "); List($3); List("\n");
                                                }
                                                List("  isub\n");
                                                char l[STRSIZE];
                                                List("  ifle L"); List(itos(L, l)); List("\n");
                                                List("  iconst_0\n");
                                                List("  goto L"); List(itos(L+1, l)); List("\n");
                                                List("L"); List(itos(L, l)); List(":\n"); List("  iconst_1\n");
                                                L++;

                                                // return part
                                                int i, j;
                                                i = stoi($1); j = stoi($3);
                                                if (i <= j)
                                                {
                                                    $$ = strdup("1");
                                                }
                                                else
                                                {
                                                    $$ = strdup("0");                                                        
                                                }
                                                }
                | integer_exp E integer_exp     {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                char a[STRSIZE];
                                                
                                                if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 1 && strcmp(t1->func, PROGRAM) == 0 && strcmp(t2->func, PROGRAM) == 0)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                    List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                }
                                                else if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 0 && strcmp(t1->func, PROGRAM) == 0 && arg[t1->counter] == NULL)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                    List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                }
                                                else if (t1 != NULL && t1->glob_flag == 0 && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0 && arg[t2->counter] == NULL)
                                                {
                                                    List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                    List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                }
                                                else if (t1 != NULL && t1->glob_flag == 1 && t2 == NULL && strcmp(t1->func, PROGRAM) == 0)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                    List("  sipush "); List($3); List("\n");
                                                }
                                                else if (t1 == NULL && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0)
                                                {
                                                    List("  sipush "); List($1); List("\n");
                                                    List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                }
                                                else if (t1 != NULL && t2 != NULL)
                                                {
                                                    List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                    List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                }
                                                else if (t1 != NULL && t2 == NULL)
                                                {
                                                    List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                    List("  sipush "); List($3); List("\n");
                                                }
                                                else if (t1 == NULL && t2 != NULL)
                                                {
                                                    List("  sipush "); List($1); List("\n");
                                                    List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                }
                                                else
                                                {
                                                    List("  sipush "); List($1); List("\n");
                                                    List("  sipush "); List($3); List("\n");
                                                }
                                                List("  isub\n");
                                                char l[STRSIZE];
                                                List("  ifeq L"); List(itos(L, l)); List("\n");
                                                List("  iconst_0\n");
                                                List("  goto L"); List(itos(L+1, l)); List("\n");
                                                List("L"); List(itos(L, l)); List(":\n"); List("  iconst_1\n");
                                                L++;

                                                // return part
                                                int i, j;
                                                i = stoi($1); j = stoi($3);
                                                if (i == j)
                                                {
                                                    $$ = strdup("1");
                                                }
                                                else
                                                {
                                                    $$ = strdup("0");                                                        
                                                }
                                                }
                | integer_exp GE integer_exp    {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                char a[STRSIZE];
                                                
                                                if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 1 && strcmp(t1->func, PROGRAM) == 0 && strcmp(t2->func, PROGRAM) == 0)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                    List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                }
                                                else if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 0 && strcmp(t1->func, PROGRAM) == 0 && arg[t1->counter] == NULL)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                    List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                }
                                                else if (t1 != NULL && t1->glob_flag == 0 && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0 && arg[t2->counter] == NULL)
                                                {
                                                    List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                    List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                }
                                                else if (t1 != NULL && t1->glob_flag == 1 && t2 == NULL && strcmp(t1->func, PROGRAM) == 0)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                    List("  sipush "); List($3); List("\n");
                                                }
                                                else if (t1 == NULL && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0)
                                                {
                                                    List("  sipush "); List($1); List("\n");
                                                    List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                }
                                                else if (t1 != NULL && t2 != NULL)
                                                {
                                                    List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                    List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                }
                                                else if (t1 != NULL && t2 == NULL)
                                                {
                                                    List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                    List("  sipush "); List($3); List("\n");
                                                }
                                                else if (t1 == NULL && t2 != NULL)
                                                {
                                                    List("  sipush "); List($1); List("\n");
                                                    List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                }
                                                else
                                                {
                                                    List("  sipush "); List($1); List("\n");
                                                    List("  sipush "); List($3); List("\n");
                                                }
                                                List("  isub\n");
                                                char l[STRSIZE];
                                                List("  ifge L"); List(itos(L, l)); List("\n");
                                                List("  iconst_0\n");
                                                List("  goto L"); List(itos(L+1, l)); List("\n");
                                                List("L"); List(itos(L, l)); List(":\n"); List("  iconst_1\n");
                                                L++;

                                                // return part
                                                int i, j;
                                                i = stoi($1); j = stoi($3);
                                                if (i >= j)
                                                {
                                                    $$ = strdup("1");
                                                }
                                                else
                                                {
                                                    $$ = strdup("0");                                                        
                                                }
                                                }
                | integer_exp GREATER integer_exp   {
                                                    list_t* t1 = lookup($1);
                                                    list_t* t2 = lookup($3);
                                                    char a[STRSIZE];
                                                    
                                                    if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 1 && strcmp(t1->func, PROGRAM) == 0 && strcmp(t2->func, PROGRAM) == 0)
                                                    {
                                                        List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                        List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                    }
                                                    else if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 0 && strcmp(t1->func, PROGRAM) == 0 && arg[t1->counter] == NULL)
                                                    {
                                                        List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                        List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                    }
                                                    else if (t1 != NULL && t1->glob_flag == 0 && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0 && arg[t2->counter] == NULL)
                                                    {
                                                        List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                        List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                    }
                                                    else if (t1 != NULL && t1->glob_flag == 1 && t2 == NULL && strcmp(t1->func, PROGRAM) == 0)
                                                    {
                                                        List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                        List("  sipush "); List($3); List("\n");
                                                    }
                                                    else if (t1 == NULL && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0)
                                                    {
                                                        List("  sipush "); List($1); List("\n");
                                                        List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                    }
                                                    else if (t1 != NULL && t2 != NULL)
                                                    {
                                                        List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                        List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                    }
                                                    else if (t1 != NULL && t2 == NULL)
                                                    {
                                                        List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                        List("  sipush "); List($3); List("\n");
                                                    }
                                                    else if (t1 == NULL && t2 != NULL)
                                                    {
                                                        List("  sipush "); List($1); List("\n");
                                                        List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                    }
                                                    else
                                                    {
                                                        List("  sipush "); List($1); List("\n");
                                                        List("  sipush "); List($3); List("\n");
                                                    }
                                                    List("  isub\n");
                                                    char l[STRSIZE];
                                                    List("  ifgt L"); List(itos(L, l)); List("\n");
                                                    List("  iconst_0\n");
                                                    List("  goto L"); List(itos(L+1, l)); List("\n");
                                                    List("L"); List(itos(L, l)); List(":\n"); List("  iconst_1\n");
                                                    L++;

                                                    // return part
                                                    int i, j;
                                                    i = stoi($1); j = stoi($3);
                                                    if (i > j)
                                                    {
                                                        $$ = strdup("1");
                                                    }
                                                    else
                                                    {
                                                        $$ = strdup("0");                                                        
                                                    }
                                                    }
                | integer_exp NE integer_exp    {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                char a[STRSIZE];
                                                
                                                if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 1 && strcmp(t1->func, PROGRAM) == 0 && strcmp(t2->func, PROGRAM) == 0)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                    List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                }
                                                else if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 0 && strcmp(t1->func, PROGRAM) == 0 && arg[t1->counter] == NULL)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                    List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                }
                                                else if (t1 != NULL && t1->glob_flag == 0 && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0 && arg[t2->counter] == NULL)
                                                {
                                                    List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                    List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                }
                                                else if (t1 != NULL && t1->glob_flag == 1 && t2 == NULL && strcmp(t1->func, PROGRAM) == 0)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                    List("  sipush "); List($3); List("\n");
                                                }
                                                else if (t1 == NULL && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0)
                                                {
                                                    List("  sipush "); List($1); List("\n");
                                                    List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                }
                                                else if (t1 != NULL && t2 != NULL)
                                                {
                                                    List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                    List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                }
                                                else if (t1 != NULL && t2 == NULL)
                                                {
                                                    List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                    List("  sipush "); List($3); List("\n");
                                                }
                                                else if (t1 == NULL && t2 != NULL)
                                                {
                                                    List("  sipush "); List($1); List("\n");
                                                    List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                }
                                                else
                                                {
                                                    List("  sipush "); List($1); List("\n");
                                                    List("  sipush "); List($3); List("\n");
                                                }
                                                List("  isub\n");
                                                char l[STRSIZE];
                                                List("  ifne L"); List(itos(L, l)); List("\n");
                                                List("  iconst_0\n");
                                                List("  goto L"); List(itos(L+1, l)); List("\n");
                                                List("L"); List(itos(L, l)); List(":\n"); List("  iconst_1\n");
                                                L++;

                                                // return part
                                                int i, j;
                                                i = stoi($1); j = stoi($3);
                                                if (i != j)
                                                {
                                                    $$ = strdup("1");
                                                }
                                                else
                                                {
                                                    $$ = strdup("0");                                                        
                                                }
                                                }
                | EXCLAMATION integer_exp       {
                                                list_t* t = lookup($2);
                                                if (t != NULL && t->glob_flag == 1 && strcmp(t->func, PROGRAM) == 0 && arg[t->counter] == NULL)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t->st_name); List("\n");
                                                }
                                                else if (t != NULL)
                                                {
                                                    char a[STRSIZE];
                                                    List("  iload_"); List(itos(t->counter, a)); List("\n");
                                                }
                                                else
                                                {
                                                    List("  sipush "); List($2); List("\n");
                                                }
                                                List("  ixor\n\n");

                                                // return part
                                                int i;
                                                i = stoi($2);
                                                if (!i)
                                                {
                                                    $$ = strdup("1");
                                                }
                                                else
                                                {
                                                    $$ = strdup("0");                                                        
                                                }
                                                }
                | integer_exp AND integer_exp   {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                char a[STRSIZE];
                                                
                                                if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 1 && strcmp(t1->func, PROGRAM) == 0 && strcmp(t2->func, PROGRAM) == 0)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                    List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                }
                                                else if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 0 && strcmp(t1->func, PROGRAM) == 0 && arg[t1->counter] == NULL)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                    List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                }
                                                else if (t1 != NULL && t1->glob_flag == 0 && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0 && arg[t2->counter] == NULL)
                                                {
                                                    List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                    List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                }
                                                else if (t1 != NULL && t1->glob_flag == 1 && t2 == NULL && strcmp(t1->func, PROGRAM) == 0)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                    List("  sipush "); List($3); List("\n");
                                                }
                                                else if (t1 == NULL && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0)
                                                {
                                                    List("  sipush "); List($1); List("\n");
                                                    List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                }
                                                else if (t1 != NULL && t2 != NULL)
                                                {
                                                    List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                    List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                }
                                                else if (t1 != NULL && t2 == NULL)
                                                {
                                                    List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                    List("  sipush "); List($3); List("\n");
                                                }
                                                else if (t1 == NULL && t2 != NULL)
                                                {
                                                    List("  sipush "); List($1); List("\n");
                                                    List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                }
                                                else
                                                {
                                                    List("  sipush "); List($1); List("\n");
                                                    List("  sipush "); List($3); List("\n");
                                                }
                                                List("  iand\n\n");

                                                // return part
                                                int i, j;
                                                i = stoi($1); j = stoi($3);
                                                if (i && j)
                                                {
                                                    $$ = strdup("1");
                                                }
                                                else
                                                {
                                                    $$ = strdup("0");                                                        
                                                }
                                                }   
                | integer_exp OR integer_exp    {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                char a[STRSIZE];
                                                
                                                if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 1 && strcmp(t1->func, PROGRAM) == 0 && strcmp(t2->func, PROGRAM) == 0)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                    List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                }
                                                else if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 0 && strcmp(t1->func, PROGRAM) == 0 && arg[t1->counter] == NULL)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                    List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                }
                                                else if (t1 != NULL && t1->glob_flag == 0 && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0 && arg[t2->counter] == NULL)
                                                {
                                                    List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                    List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                }
                                                else if (t1 != NULL && t1->glob_flag == 1 && t2 == NULL && strcmp(t1->func, PROGRAM) == 0)
                                                {
                                                    List("  getstatic int "); List(file); List("."); List(t1->st_name); List("\n");
                                                    List("  sipush "); List($3); List("\n");
                                                }
                                                else if (t1 == NULL && t2 != NULL && t2->glob_flag == 1 && strcmp(t2->func, PROGRAM) == 0)
                                                {
                                                    List("  sipush "); List($1); List("\n");
                                                    List("  getstatic int "); List(file); List("."); List(t2->st_name); List("\n");
                                                }
                                                else if (t1 != NULL && t2 != NULL)
                                                {
                                                    List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                    List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                }
                                                else if (t1 != NULL && t2 == NULL)
                                                {
                                                    List("  iload_"); List(itos(t1->counter, a)); List("\n");
                                                    List("  sipush "); List($3); List("\n");
                                                }
                                                else if (t1 == NULL && t2 != NULL)
                                                {
                                                    List("  sipush "); List($1); List("\n");
                                                    List("  iload_"); List(itos(t2->counter, a)); List("\n");
                                                }
                                                else
                                                {
                                                    List("  sipush "); List($1); List("\n");
                                                    List("  sipush "); List($3); List("\n");
                                                }
                                                List("  ior\n\n");

                                                // return part
                                                int i, j;
                                                i = stoi($1); j = stoi($3);
                                                if (i || j)
                                                {
                                                    $$ = strdup("1");
                                                }
                                                else
                                                {
                                                    $$ = strdup("0");                                                        
                                                }
                                                }
                | INTEGER                       {
                                                    $$ = strdup($1);
                                                }
                | ID                            {
                                                list_t* t = lookup($1);
                                                if (t->st_type == INT_TYPE || t->st_type == CONST_INT_TYPE)
                                                {
                                                    char b[STRSIZE];
                                                    $$ = strdup(t->st_name);
                                                }
                                                else
                                                {
                                                    Trace("line %d: The type does not match.\n", linenum);
                                                }
                                                }
                | function_invocation           {
                                                if ($1->st_type == FUNCTION_TYPE && $1->inf_type == INT_TYPE)
                                                {
                                                    // throw a random num
                                                    $$ = strdup("1");
                                                }
                                                else
                                                {
                                                    Trace("line %d: The type does not match.\n", linenum);
                                                }
                                                }
                ;

string_exp:     L_BRACE string_exp R_BRACE      {
                                                    $$ = strdup($2);
                                                }
                | STRING                        {
                                                    $$ = strdup($1);
                                                }
                ;
%%
#include "lex.c"

void yyerror(char* msg)
{
    fprintf(stderr, "line %d: %s\n", linenum, msg);
}

int stoi(char *str)
{
  int result;
  int puiss;

  result = 0;
  puiss = 1;
  while (('-' == (*str)) || ((*str) == '+'))
    {
      if (*str == '-')
        puiss = puiss * -1;
      str++;
    }
  while ((*str >= '0') && (*str <= '9'))
    {
      result = (result * 10) + ((*str) - '0');
      str++;
    }
  return (result * puiss);
}

char* itos(int i, char b[]){
    char const digit[] = "0123456789";
    char* p = b;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return b;
}

int main(int argc, char** argv)
{
    /* create the hash table */
    create();

    /* open the source program file */
    if (argc != 2) {
        printf ("Usage: sc filename\n");
        exit(1);
    }
    yyin = fopen(argv[1], "r");         /* open input file */
    
    /* For the kingdom of fucking java */
    char* filename = malloc(sizeof(strlen(argv[1])));
    for (int i = 0; i < strlen(argv[1]) - 5; i++)
    {
        filename[i] = argv[1][i];
    }
    filename[strlen(argv[1]) - 5] = '\0';
    file = strdup(filename);
    char temp[] = ".jasm";
    strcat(filename, temp);
    javaa = fopen(filename, "w");           /* open a file for java bytecode */
    fprintf(javaa, "/*-------------------------------------------------*/\n");
    fprintf(javaa, "/*              Java Assembly Code                 */\n");
    fprintf(javaa, "/*-------------------------------------------------*/\n\n");
    fprintf(javaa, "class %s\n{\n", file);   /* make the file name as the class name */
    /*-----------------------------------------------------------------------------------*/

    int flag;
    flag = yyparse();

    /* perform parsing */
    if (flag == 1)                      /* parsing */
        yyerror("Parsing error !");     /* syntax error */

    fclose(yyin);                       /* close input file */
    fprintf(javaa, "\n}\n");              /* close the class */
    fclose(javaa);                      /* close the javaa */

    /* output symbol table */
    printf("\nSymbol table:\n");
    yyout = fopen("dump.out", "w");
    dump(yyout);
    fclose(yyout);

    return 0;
}
