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

May 24, 2018
Today, I add more blocks for judge whether it is a while_loop or if_els_stmt after some blocks or not.
Finally, I got a good way to produce java bytecode after I know the principle of bison since it is bottom-up parsing.
Try to ifstmt and whilestmt
Try while_loop
Now, I have to deal with local and global variables problem since it cannot define well.
Try to generate fib.jasm correctly. Now, the problem is when something equals something, it cannot write correclty since ID part does not write something in.

May 25, 2018
Try to solve !
Rewrite else statement, if statement, and while statement
Use Num(WHILE) Num(IF) Num(ELSE)
Mark statement as part of them
if-else statement is the problem.

June 07, 2018
Add integer_exp, else_integer_exp, and bool_exp

June 08, 2018
Delete integer_exp, else_integer_exp, and bool_exp
Deal with counter when a func is over

June 12, 2018
ixor in the bool_exp add more contents
bool_exp should be rewritten since the comparison should add in the if stmt, if-else stmt, and while stmt.
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
#define List(str);            fprintf(javaa, "%s", str)
#define Write(str)            strcat(buffer[bufIndex], str)
#define Num(number);          bufferMark[bufIndex] = number

/* standard size for string type in rust- programming language */
#ifndef STRSIZE
#define STRSIZE     40
#endif

/* standard size for struct Parameter type */
#ifndef PARAMSIZE
#define PARAMSIZE   40
#endif

#ifndef MAX_LINE_SIZE
#define MAX_LINE_SIZE 1024
#endif

#ifndef MAX_LINE_CODE
#define MAX_LINE_CODE 256
#endif

#define NORMAL 0
#define BOOLEXP 1
#define ELSEST 2

#define ORSIGN    1
#define ANDSIGN   2
#define EXCLASIGN 3

#define IFGT 1
#define IFLT 2
#define IFGE 3
#define IFLE 4
#define IFEQ 5
#define IFNE 6

extern FILE* yyin;
extern FILE* yyout;
extern int linenum;
extern int yylex();
extern char buf[256];
extern int counter;

FILE* javaa;        //file for bytecode
FILE* local_tab;    // local_var output file
char* file;         // filename without extension

char arg[STRSIZE][STRSIZE]; // record the names of arguments in the current function

char buffer[STRSIZE][MAX_LINE_SIZE]; // reserve the code generation in the func cause it is fucking reversed.
int bufIndex = 0;
int bufferMark[STRSIZE]; // remark what kind of handle about the match buffer blocks.

int L = 0; // stage counter

char local_var[STRSIZE][STRSIZE]; // record the local variables
int local_counter[STRSIZE]; // record the local values

int sign = 0; // OR = 1, AND = 2, EXCLAMATION = 3
short ifsign = 0; // for bool_exp sign

int operand = 0; // operand sign

void yyerror(char* msg);
void judge(list_t*, list_t*, char*, char arg[STRSIZE][STRSIZE], char*, char*); // judge should Write what king of sentences into file
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
%token <stringVal> TRUE FALSE
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
%type <stringVal> string_exp integer_exp else_integer_exp else_string_exp
%type <stringVal> bool_exp
%type <parptr> formal_argument formal_arguments comma_separated_exps comma_separated_exp
%type <symptr> function_invocation

%start program              /* the initial entry point */

%%
program:        functions
                | global_declaration functions
                ;
SEMI:           SEMICOLON   {
                                operand = 0; // reset to zero
                            }
                ;

global_declaration:     global_declaration constant_declaration
                        | global_declaration glob_variable_declaration
                        | constant_declaration
                        | glob_variable_declaration
                        ;

local_declaration:      local_declaration constant_declaration
                        | local_declaration local_variable_declaration
                        | constant_declaration
                        | local_variable_declaration
                        ;

block:          start local_declaration statements end               
                | start local_declaration end                         
                | start statements end                                
                | start end                                           
                ;
else_block:     start local_declaration else_statements end               
                | start local_declaration end                         
                | start else_statements end                                
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

constant_declaration:   LET ID ASSIGN integer_exp SEMI         {
                                                                    list_t* t = lookup($2);

                                                                    if (t == NULL)
                                                                    {
                                                                        insert($2, strlen($2), CONST_INT_TYPE, linenum);
                                                                        t = lookup($2);
                                                                        t->st_ival = stoi($4);
                                                                        t->st_sval = strdup($4);
                                                                        t->constant = 1;

                                                                        Write("    sipush "); Write($4); Write("\n");

                                                                        bufIndex++;
                                                                    }
                                                                    else Trace("line %d: Redeclaration of identifier.\n", linenum);

                                                                    }
                        | LET ID ASSIGN TRUE SEMI              {
                                                                    list_t* t = lookup($2);

                                                                    if (t == NULL)
                                                                    {
                                                                        insert($2, strlen($2), CONST_INT_TYPE, linenum);
                                                                        t = lookup($2);
                                                                        t->st_ival = stoi($4);
                                                                        t->st_sval = strdup($4);
                                                                        t->constant = 1;

                                                                        Write("   iconst_1\n");

                                                                        bufIndex++;
                                                                    }
                                                                    else Trace("line %d: Redeclaration of identifier.\n", linenum);

                                                                    }
                        | LET ID ASSIGN FALSE SEMI             {
                                                                    list_t* t = lookup($2);

                                                                    if (t == NULL)
                                                                    {
                                                                        insert($2, strlen($2), CONST_INT_TYPE, linenum);
                                                                        t = lookup($2);
                                                                        t->st_ival = stoi($4);
                                                                        t->st_sval = strdup($4);
                                                                        t->constant = 1;

                                                                        Write("   iconst_0\n");

                                                                        bufIndex++;
                                                                    }
                                                                    else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                    }
                        | LET ID ASSIGN string_exp SEMI        {
                                                                    list_t* t = lookup($2);

                                                                    if (t == NULL)
                                                                    {
                                                                        insert($2, strlen($2), CONST_STR_TYPE, linenum);
                                                                        t = lookup($2);
                                                                        t->st_sval = strdup($4);
                                                                        t->constant = 1;

                                                                        Write("   ldc "); Write($4); Write("\n");

                                                                        bufIndex++;
                                                                    }
                                                                    else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                    }   
                        | LET ID COLON INT ASSIGN integer_exp SEMI     {
                                                                            list_t* t = lookup($2);

                                                                            if (t == NULL)
                                                                            {
                                                                                insert($2, strlen($2), CONST_INT_TYPE, linenum);
                                                                                t = lookup($2);
                                                                                t->st_ival = stoi($6);
                                                                                t->st_sval = strdup($6);
                                                                                t->constant = 1;

                                                                                Write("   sipush "); Write($6); Write("\n");

                                                                                bufIndex++;
                                                                            }
                                                                            else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                            }
                        | LET ID COLON BOOL ASSIGN TRUE SEMI           {
                                                                            list_t* t = lookup($2);

                                                                            if (t == NULL)
                                                                            {
                                                                                insert($2, strlen($2), CONST_INT_TYPE, linenum);
                                                                                t = lookup($2);
                                                                                t->st_ival = stoi($6);
                                                                                t->st_sval = strdup($6);
                                                                                t->constant = 1;

                                                                                Write("    iconst_1\n");

                                                                                bufIndex++;
                                                                            }
                                                                            else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                            }
                        | LET ID COLON BOOL ASSIGN FALSE SEMI          {
                                                                            list_t* t = lookup($2);

                                                                            if (t == NULL)
                                                                            {
                                                                                insert($2, strlen($2), CONST_INT_TYPE, linenum);
                                                                                t = lookup($2);
                                                                                t->st_ival = stoi($6);
                                                                                t->st_sval = strdup($6);
                                                                                t->constant = 1;

                                                                                Write("    iconst_0\n");

                                                                                bufIndex++;
                                                                            }
                                                                            else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                            }
                        | LET ID COLON STR ASSIGN string_exp SEMI      {
                                                                            list_t* t = lookup($2);

                                                                            if (t == NULL)
                                                                            {
                                                                                insert($2, strlen($2), CONST_STR_TYPE, linenum);
                                                                                t = lookup($2);
                                                                                t->st_sval = strdup($6);
                                                                                t->constant = 1;
                                                                               
                                                                                Write("   ldc "); Write($6); Write("\n");

                                                                                bufIndex++;
                                                                            }
                                                                            else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                            }
                        ;

glob_variable_declaration:   LET MUT ID SEMI                       {
                                                                        list_t* t = lookup($3);

                                                                        if (t == NULL && cur_scope == 0)
                                                                        {
                                                                            insert($3, strlen($3), UNDEF, linenum);
                                                                            t = lookup($3);
                                                                            t->glob_flag = 1;
                                                                            t->constant = 0;
                                                                            List("  field static int "); List($3); List("\n");
                                                                        }
                                                                        else Trace("line %d: Redeclaration of identifier.\n", linenum);

                                                                        
                                                                        }
                        | LET MUT ID COLON INT SEMI                {
                                                                        list_t* t = lookup($3);

                                                                        if (t == NULL && cur_scope == 0)
                                                                        {
                                                                            insert($3, strlen($3), INT_TYPE, linenum);
                                                                            t = lookup($3);
                                                                            t->glob_flag = 1;
                                                                            t->constant = 0;
                                                                            List("  field static int "); List($3); List("\n");
                                                                        }
                                                                        else Trace("line %d: Redeclaration of identifier.\n", linenum);

                                                                        
                                                                        }
                        | LET MUT ID ASSIGN integer_exp SEMI       {
                                                                        list_t* t = lookup($3);

                                                                        if (t == NULL && cur_scope == 0)
                                                                        {
                                                                            insert($3, strlen($3), INT_TYPE, linenum);
                                                                            t = lookup($3);
                                                                            t->glob_flag = 1;
                                                                            t->st_ival = stoi($5);
                                                                            t->st_sval = strdup($5);
                                                                            t->constant = 0;
                                                                            List("  field static int "); List($3); List(" = "); List($5); List("\n");
                                                                        }
                                                                        else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                        }        
                        | LET MUT ID COLON INT ASSIGN integer_exp SEMI     {
                                                                                list_t* t = lookup($3);

                                                                                if (t == NULL && cur_scope == 0)
                                                                                {
                                                                                    insert($3, strlen($3), INT_TYPE, linenum);
                                                                                    t = lookup($3);
                                                                                    t->glob_flag = 1;
                                                                                    t->constant = 0;
                                                                                    List("  field static int "); List($3); List(" = "); List("\n");
                                                                                }
                                                                                else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                                }
                        ;
local_variable_declaration:   LET MUT ID SEMI                      {
                                                                        list_t* t = lookup($3);

                                                                        if (t == NULL)
                                                                        {
                                                                            insert($3, strlen($3), UNDEF, linenum);
                                                                            t = lookup($3);
                                                                            t->glob_flag = 0;
                                                                            t->counter = counter;
                                                                            t->st_ival = stoi("0");
                                                                            t->st_sval = strdup("0");
                                                                            t->constant = 0;

                                                                            strcat(local_var[counter], $3);
                                                                            local_counter[counter] = counter;
                                                                            
                                                                            char l[STRSIZE];
                                                                            fprintf(local_tab, "%s", $3); fprintf(local_tab, " = "); fprintf(local_tab, "%s", itos(counter, l)); fprintf(local_tab, ", next number " ); fprintf(local_tab, "%s", itos(counter+1, l));
                                                                            fprintf(local_tab, "\n");

                                                                            counter++;
                                                                        }
                                                                        else Trace("line %d: Redeclaration of identifier.\n", linenum);

                                                                        
                                                                        }
                        | LET MUT ID COLON INT SEMI                {
                                                                        list_t* t = lookup($3);

                                                                        if (t == NULL)
                                                                        {
                                                                            insert($3, strlen($3), INT_TYPE, linenum);
                                                                            t = lookup($3);
                                                                            t->glob_flag = 0;
                                                                            t->counter = counter;
                                                                            t->st_ival = stoi("0");
                                                                            t->st_sval = strdup("0");
                                                                            t->constant = 0;

                                                                            strcat(local_var[counter], $3);
                                                                            local_counter[counter] = counter;

                                                                            char l[STRSIZE];
                                                                            fprintf(local_tab, "%s", $3); fprintf(local_tab, " = "); fprintf(local_tab, "%s", itos(counter, l)); fprintf(local_tab, ", next number " ); fprintf(local_tab, "%s", itos(counter+1, l));
                                                                            fprintf(local_tab, "\n");

                                                                            counter++;
                                                                        }
                                                                        else Trace("line %d: Redeclaration of identifier.\n", linenum);

                                                                        
                                                                        }
                        | LET MUT ID ASSIGN integer_exp SEMI       {
                                                                        list_t* t = lookup($3);

                                                                        if (t == NULL)
                                                                        {
                                                                            insert($3, strlen($3), INT_TYPE, linenum);
                                                                            t = lookup($3);
                                                                            t->glob_flag = 0;
                                                                            t->counter = counter;
                                                                            t->st_ival = stoi($5);
                                                                            t->st_sval = strdup($5);
                                                                            t->constant = 0;

                                                                            strcat(local_var[counter], $3);
                                                                            local_counter[counter] = counter;
                                                                            char l[STRSIZE];
                                                                            fprintf(local_tab, "%s", $3); fprintf(local_tab, " = "); fprintf(local_tab, "%s", itos(counter, l)); fprintf(local_tab, ", next number " ); fprintf(local_tab, "%s", itos(counter+1, l));
                                                                            fprintf(local_tab, "\n");

                                                                            counter++;
                                                                            Write("    sipush "); Write($5); Write("\n");
                                                                            
                                                                            char n[STRSIZE];
                                                                            sprintf(n, "%d", t->counter);
                                                                            Write("    istore "); Write(n); Write("\n");

                                                                            // put mark for buffer
                                                                            Num(NORMAL);

                                                                            bufIndex++;
                                                                        }
                                                                        else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                        }        
                        | LET MUT ID COLON INT ASSIGN integer_exp SEMI     {
                                                                                list_t* t = lookup($3);

                                                                                if (t == NULL)
                                                                                {
                                                                                    insert($3, strlen($3), INT_TYPE, linenum);
                                                                                    t = lookup($3);
                                                                                    t->glob_flag = 0;
                                                                                    t->counter = counter;
                                                                                    t->st_ival = stoi($7);
                                                                                    t->st_sval = strdup($7);
                                                                                    t->constant = 0;

                                                                                    strcat(local_var[counter], $3);
                                                                                    local_counter[counter] = counter;
                                                                                    char l[STRSIZE];
                                                                                    fprintf(local_tab, "%s", t->st_name); fprintf(local_tab, " = "); fprintf(local_tab, "%s", itos(counter, l)); fprintf(local_tab, ", next number "); fprintf(local_tab, "%s", itos(counter+1, l));
                                                                                    fprintf(local_tab, "\n");

                                                                                    counter++;
                                                                                    Write("    sipush "); Write($7); Write("\n");

                                                                                    char n[STRSIZE];
                                                                                    sprintf(n, "%d", t->counter);
                                                                                    Write("    istore "); Write(n); Write("\n");

                                                                                    // put mark for buffer
                                                                                    Num(NORMAL);

                                                                                    bufIndex++;
                                                                                }
                                                                                else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                                }
                        ;

fn_start:       L_BRACE                 {
                                        hide_scope();
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
                                                                    list_t* t = lookup($2);

                                                                    if (t == NULL)
                                                                    {
                                                                        insert($2, strlen($2), FUNCTION_TYPE, linenum);
                                                                        t = lookup($2);
                                                                        t->inf_type = UNDEF;
                                                                        t->parameters = NULL;
                                                                        t->num_of_pars = 0;

                                                                        if (strcmp($2, "main") == 0)
                                                                        {
                                                                            List("\n  method public static void main (java.lang.String[])\n");
                                                                        }
                                                                        else
                                                                        {
                                                                            List("\n  method public static void "); List($2); List("()\n");
                                                                        }
                                                                        
                                                                        List("  max_stack 15\n  max_locals 15\n  {\n");
                                                                        
                                                                        for (int i = 0; i < bufIndex; i++)
                                                                        {
                                                                            List(buffer[i]);
                                                                            buffer[i][0] = '\0';
                                                                        }

                                                                        List("    return\n");
                                                                        List("  }");

                                                                        counter = 0; // reset counter when a func is over
                                                                    }
                                                                    else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                    }
                | FN ID fn_start formal_arguments R_BRACE fn_block  {
                                                                    list_t* t = lookup($2);

                                                                    if (t == NULL)
                                                                    {
                                                                        insert($2, strlen($2), FUNCTION_TYPE, linenum);
                                                                        t = lookup($2);
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

                                                                        List("\n  method public static void "); List($2); List("(");
                                                                        for (int i = 0; i < t->num_of_pars - 1; i++)
                                                                        {
                                                                            List("int, ");
                                                                        }
                                                                        List("int)\n");
                                                                        List("  max_stack 15\n  max_locals 15\n  {\n");
                                                                       
                                                                        for (int i = 0; i < bufIndex; i++)
                                                                        {
                                                                            List(buffer[i]);
                                                                            buffer[i][0] = '\0';
                                                                        }

                                                                        List("    return\n");
                                                                        List("  }");

                                                                        //clear argument table after exit current func
                                                                        for(int i = 0; i < STRSIZE; i++) arg[i][0] = '\0';

                                                                        counter = 0; // reset counter when a func is over
                                                                    }
                                                                    else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                    }
                | FN ID fn_start R_BRACE ARROW INT fn_block         {
                                                                    list_t* t = lookup($2);

                                                                    if (t == NULL)
                                                                    {
                                                                        insert($2, strlen($2), FUNCTION_TYPE, linenum);
                                                                        t = lookup($2);
                                                                        t->inf_type = INT_TYPE;
                                                                        t->parameters = NULL;
                                                                        t->num_of_pars = 0;

                                                                        List("\n  method public static int "); List($2); List("()\n");
                                                                        List("  max_stack 15\n");
                                                                        List("  max_locals 15\n");
                                                                        List("  {\n");

                                                                        for (int i = 0; i < bufIndex; i++)
                                                                        {
                                                                            List(buffer[i]);
                                                                            buffer[i][0] = '\0';
                                                                        }
                                                                        
                                                                        List("  }");

                                                                        counter = 0; // reset counter when a func is over
                                                                    }
                                                                    else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                    }
                | FN ID fn_start formal_arguments R_BRACE ARROW INT fn_block{
                                                                            list_t* t = lookup($2);

                                                                            if (t == NULL)
                                                                            {
                                                                                insert($2, strlen($2), FUNCTION_TYPE, linenum);
                                                                                t = lookup($2);
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

                                                                                List("\n  method public static int "); List($2); List("(");
                                                                                for(int i = 0; i < t->num_of_pars - 1; i++)
                                                                                {
                                                                                    List("int, ");
                                                                                }
                                                                                List("int)\n");
                                                                                List("  max_stack 15\n");
                                                                                List("  max_locals 15\n");
                                                                                List("  {\n");
                                                                                
                                                                                for (int i = 0; i < bufIndex; i++)
                                                                                {
                                                                                    List(buffer[i]);
                                                                                    buffer[i][0] = '\0';
                                                                                }

                                                                                List("  }");

                                                                                //clear argument table after exit current func
                                                                                for(int i = 0; i < STRSIZE; i++) arg[i][0] = '\0';

                                                                                counter = 0; // reset counter when a func is over
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
                                                                            insert($1, strlen($1), INT_TYPE, linenum);
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
                                                                        else if (t != NULL && t->scope == 0)
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
else_statements:    else_statements else_statement
                    | else_statement
                    ;

statement:      ID ASSIGN integer_exp SEMI                     {
                                                                    list_t* t = lookup($1);
                                                                    if (t != NULL && (t->st_type == INT_TYPE || t->st_type == UNDEF))
                                                                    {
                                                                        t->st_type = INT_TYPE;
                                                                        t->st_ival = stoi($3);
                                                                        t->st_sval = strdup($3);

                                                                        if (t->glob_flag == 1)
                                                                        {
                                                                            if (t->neg == 1)
                                                                            {
                                                                                t->neg = 0;
                                                                                Write("    ineg\n");
                                                                            }
                                                                            Write("    putstatic int "); Write(file); Write("."); Write(t->st_name); Write("\n");
                                                                        }
                                                                        else
                                                                        {
                                                                            list_t* temp = lookup($3);
                                                                            char a[STRSIZE];

                                                                            if (temp != NULL && temp->constant == 0)
                                                                            {
                                                                                Write("    iload "); Write(itos(temp->counter, a)); Write("\n");
                                                                            }
                                                                            else if (temp != NULL && temp->constant == 1)
                                                                            {
                                                                                Write("    sipush "); Write(t->st_sval); Write("\n");
                                                                            }
                                                                            if (temp != NULL && temp->neg == 1)
                                                                            {
                                                                                temp->neg = 0;
                                                                                Write("    ineg\n");
                                                                            }
                                                                            
                                                                            Write("    istore "); Write(itos(t->counter, a)); Write("\n");
                                                                        }

                                                                        // put mark for buffer
                                                                        Num(NORMAL);

                                                                        bufIndex++;
                                                                    }
                                                                    else if (t != NULL && (t->st_type != INT_TYPE || t->st_type != UNDEF))
                                                                    {
                                                                        Trace("line %d: The type does not match.\n", linenum);
                                                                    }
                                                                    else Trace("line %d: Identifier does not define.\n", linenum);
                                                                    }
                | PRINT integer_exp SEMI   {
                                                Write("    getstatic java.io.PrintStream java.lang.System.out\n");

                                                list_t* t = lookup($2);
                                                if (t != NULL && t->glob_flag == 1)
                                                {
                                                    Write("    getstatic int "); Write(file); Write("."); Write(t->st_name); Write("\n");
                                                }
                                                else if (t != NULL && t->glob_flag == 0)
                                                {
                                                    char a[STRSIZE];
                                                    Write("    iload "); Write(itos(t->counter, a)); Write("\n");
                                                }
                                                else
                                                {
                                                    Write("    ldc "); Write($2); Write("\n");
                                                }

                                                if (t != NULL && t->neg == 1)
                                                {
                                                    t->neg = 0;
                                                    Write("    ineg\n");
                                                }
                                                Write("    invokevirtual void java.io.PrintStream.print(int)\n");
                                                
                                                // put mark for buffer
                                                Num(NORMAL);

                                                bufIndex++;
                                                }       
                | PRINT string_exp SEMI    {
                                                Write("    getstatic java.io.PrintStream java.lang.System.out\n");
                                                Write("    ldc "); Write($2); Write("\n");
                                                Write("    invokevirtual void java.io.PrintStream.print(java.lang.String)\n");

                                                // put mark for buffer
                                                Num(NORMAL);
                                                
                                                bufIndex++;
                                                }
                | PRINTLN integer_exp SEMI {
                                                Write("    getstatic java.io.PrintStream java.lang.System.out\n");

                                                list_t* t = lookup($2);
                                                if (t != NULL && t->glob_flag == 1)
                                                {
                                                    Write("    getstatic int "); Write(file); Write("."); Write(t->st_name); Write("\n");
                                                }
                                                else if (t != NULL && t->glob_flag == 0)
                                                {
                                                    char a[STRSIZE];
                                                    Write("    iload "); Write(itos(t->counter, a)); Write("\n");
                                                }
                                                else 
                                                {
                                                    Write("    ldc "); Write($2); Write("\n");
                                                }

                                                if (t != NULL && t->neg == 1)
                                                {
                                                    t->neg = 0;
                                                    Write("    ineg\n");
                                                }

                                                Write("    invokevirtual void java.io.PrintStream.println(int)\n");

                                                // put mark for buffer
                                                Num(NORMAL);
                                                
                                                bufIndex++;
                                                }
                | PRINTLN string_exp SEMI  {
                                                Write("    getstatic java.io.PrintStream java.lang.System.out\n");
                                                Write("    ldc "); Write($2); Write("\n");
                                                Write("    invokevirtual void java.io.PrintStream.println(java.lang.String)\n");

                                                // put mark for buffer
                                                Num(NORMAL);
                                                
                                                bufIndex++;
                                                }
                | RETURN SEMI              {
                                                Write("    return\n");

                                                // put mark for buffer
                                                Num(NORMAL);
                                                
                                                bufIndex++;
                                                }
                | RETURN integer_exp SEMI  {
                                                Write("    ireturn\n");

                                                // put mark for buffer
                                                Num(NORMAL);
                                                
                                                bufIndex++;
                                                }
                | conditional
                | loop
                ;
else_statement: ID ASSIGN else_integer_exp SEMI                {
                                                                    list_t* t = lookup($1);
                                                                    if (t != NULL && (t->st_type == INT_TYPE || t->st_type == UNDEF))
                                                                    {
                                                                        t->st_type = INT_TYPE;
                                                                        t->st_ival = stoi($3);
                                                                        t->st_sval = strdup($3);

                                                                        if (t->glob_flag == 1)
                                                                        {
                                                                            if (t->neg == 1)
                                                                            {
                                                                                t->neg = 0;
                                                                                Write("    ineg\n");
                                                                            }
                                                                            Write("    putstatic int "); Write(file); Write("."); Write(t->st_name); Write("\n");
                                                                        }
                                                                        else
                                                                        {
                                                                            list_t* temp = lookup($3);
                                                                            char a[STRSIZE];

                                                                            if (temp != NULL && temp->constant == 0)
                                                                            {
                                                                                Write("    iload "); Write(itos(temp->counter, a)); Write("\n");
                                                                            }
                                                                            else if (temp != NULL && temp->constant == 1)
                                                                            {
                                                                                Write("    sipush "); Write(t->st_sval); Write("\n");
                                                                            }
                                                                            if (temp != NULL && temp->neg == 1)
                                                                            {
                                                                                temp->neg = 0;
                                                                                Write("    ineg\n");
                                                                            }
                                                                            
                                                                            Write("    istore "); Write(itos(t->counter, a)); Write("\n");
                                                                        }

                                                                        // put mark for buffer
                                                                        Num(ELSEST);

                                                                        bufIndex++;
                                                                    }
                                                                    else if (t != NULL && (t->st_type != INT_TYPE || t->st_type != UNDEF))
                                                                    {
                                                                        Trace("line %d: The type does not match.\n", linenum);
                                                                    }
                                                                    else Trace("line %d: Identifier does not define.\n", linenum);
                                                                    }
                | PRINT else_integer_exp SEMI   {
                                                Write("    getstatic java.io.PrintStream java.lang.System.out\n");

                                                list_t* t = lookup($2);
                                                if (t != NULL && t->glob_flag == 1)
                                                {
                                                    Write("    getstatic int "); Write(file); Write("."); Write(t->st_name); Write("\n");
                                                }
                                                else if (t != NULL && t->glob_flag == 0)
                                                {
                                                    char a[STRSIZE];
                                                    Write("    iload "); Write(itos(t->counter, a)); Write("\n");
                                                }
                                                else
                                                {
                                                    Write("    ldc "); Write($2); Write("\n");
                                                }

                                                if (t != NULL && t->neg == 1)
                                                {
                                                    t->neg = 0;
                                                    Write("    ineg\n");
                                                }
                                                Write("    invokevirtual void java.io.PrintStream.print(int)\n");
                                                
                                                // put mark for buffer
                                                Num(ELSEST);

                                                bufIndex++;
                                                }       
                | PRINT else_string_exp SEMI    {
                                                Write("    getstatic java.io.PrintStream java.lang.System.out\n");
                                                Write("    ldc "); Write($2); Write("\n");
                                                Write("    invokevirtual void java.io.PrintStream.print(java.lang.String)\n");

                                                // put mark for buffer
                                                Num(ELSEST);
                                                
                                                bufIndex++;
                                                }
                | PRINTLN else_integer_exp SEMI {
                                                Write("    getstatic java.io.PrintStream java.lang.System.out\n");

                                                list_t* t = lookup($2);
                                                if (t != NULL && t->glob_flag == 1)
                                                {
                                                    Write("    getstatic int "); Write(file); Write("."); Write(t->st_name); Write("\n");
                                                }
                                                else if (t != NULL && t->glob_flag == 0)
                                                {
                                                    char a[STRSIZE];
                                                    Write("    iload "); Write(itos(t->counter, a)); Write("\n");
                                                }
                                                else 
                                                {
                                                    Write("    ldc "); Write($2); Write("\n");
                                                }

                                                if (t != NULL && t->neg == 1)
                                                {
                                                    t->neg = 0;
                                                    Write("    ineg\n");
                                                }

                                                Write("    invokevirtual void java.io.PrintStream.println(int)\n");

                                                // put mark for buffer
                                                Num(ELSEST);
                                                
                                                bufIndex++;
                                                }
                | PRINTLN else_string_exp SEMI  {
                                                Write("    getstatic java.io.PrintStream java.lang.System.out\n");
                                                Write("    ldc "); Write($2); Write("\n");
                                                Write("    invokevirtual void java.io.PrintStream.println(java.lang.String)\n");

                                                // put mark for buffer
                                                Num(ELSEST);
                                                
                                                bufIndex++;
                                                }
                ;

conditional:    IF L_BRACE bool_exp R_BRACE block ELSE else_block    {
                                                                char str[MAX_LINE_SIZE];
                                                                char l[STRSIZE];
                                                                str[0] = '\0';

                                                                // judge I should pop back how many blocks
                                                                int i, j, k = 0, m;
                                                                for (i = bufIndex - 1; i >= 0; i--)
                                                                {
                                                                    if (bufferMark[i] == ELSEST)
                                                                    {
                                                                        j = i;
                                                                    }
                                                                    if (bufferMark[i] == BOOLEXP)
                                                                    {
                                                                        for (k = i; k >= 0; k--)
                                                                        {
                                                                            if (bufferMark[k] != BOOLEXP)
                                                                            {
                                                                                break;
                                                                            }
                                                                        }
                                                                        break;
                                                                    }
                                                                }

                                                                if (strcmp($3, "true") == 0 || strcmp($3, "false") == 0)
                                                                {
                                                                    for (m = i; m < j; m++) strcat(str, buffer[m]);
                                                                    strcat(str, "    goto L"); strcat(str, itos(L+1, l)); strcat(str, "\n");
                                                                    strcat(str, "  L"); strcat(str, itos(L++, l)); strcat(str, ":\n");
                                                                    for (m = j; m < bufIndex; m++) strcat(str, buffer[m]);
                                                                    strcat(str, "  L"); strcat(str, itos(L++, l)); strcat(str, ":\n");
                                                                }
                                                                else {
                                                                    for (m = k + 1; m <= i; m++) strcat(str, buffer[m]);

                                                                    if (sign != NORMAL)
                                                                    {
                                                                        if (sign == 1)
                                                                        {
                                                                            strcat(str, "    ior\n");
                                                                            strcat(str, "    ifne L"); strcat(str, itos(L, l)); strcat(str, "\n");
                                                                        }
                                                                        else if (sign == 2)
                                                                        {
                                                                            strcat(str, "    iand\n");
                                                                            strcat(str, "    ifne L"); strcat(str, itos(L, l)); strcat(str, "\n");
                                                                        }
                                                                        else if (sign == EXCLASIGN)
                                                                        {
                                                                            strcat(str, "    iconst_0\n");
                                                                            strcat(str, "    ixor\n");
                                                                            strcat(str, "    ifeq L"); strcat(str, itos(L, l)); strcat(str, "\n");
                                                                        }
                                                                        
                                                                        sign = 0; // reset sign flag
                                                                    }

                                                                    strcat(str, "    iconst_0\n");
                                                                    strcat(str, "    goto L"); strcat(str, itos(L+1, l)); strcat(str, "\n");
                                                                    strcat(str, "  L"); strcat(str, itos(L++, l)); strcat(str, ":\n");
                                                                    strcat(str, "    iconst_1\n");
                                                                    strcat(str, "  L"); strcat(str, itos(L, l)); strcat(str, ":\n");
                                                                    strcat(str, "    ifeq L"); strcat(str, itos(L+1, l)); strcat(str, "\n");
                                                                    L++;

                                                                    for (m = i + 1; m < j; m++) strcat(str, buffer[m]);
                                                                    strcat(str, "    goto L"); strcat(str, itos(L+1, l)); strcat(str, "\n");

                                                                    strcat(str, "  L"); strcat(str, itos(L++, l)); strcat(str, ":\n");

                                                                    for (m = j; m < bufIndex; m++) strcat(str, buffer[m]);
                                                                    strcat(str, "  L"); strcat(str, itos(L++, l)); strcat(str, ":\n");
                                                                }

                                                                for (m = k + 1; m < bufIndex; m++) buffer[m][0] = '\0';

                                                                bufIndex -= k + 1;
                                                                Write(str);
                                                                }
                | IF L_BRACE bool_exp R_BRACE block             {
                                                                char str[MAX_LINE_SIZE];
                                                                char l[STRSIZE];
                                                                str[0] = '\0';

                                                                // judge I should pop back how many blocks
                                                                int i, j, k;
                                                                for (i = bufIndex - 1; i >= 0; i--)
                                                                {
                                                                    if (bufferMark[i] == BOOLEXP)
                                                                    {
                                                                        for (j = i; j >= 0; j--)
                                                                        {
                                                                            if (bufferMark[j] != BOOLEXP)
                                                                            {
                                                                                break;
                                                                            }
                                                                        }
                                                                        break;
                                                                    }
                                                                }
                                                                
                                                                if (strcmp($3, "true") == 0 || strcmp($3, "false") == 0)
                                                                {
                                                                    for (k = i; k < bufIndex; k++) strcat(str, buffer[k]);
                                                                          
                                                                    strcat(str, "  L"); strcat(str, itos(L++, l)); strcat(str, ":\n");
                                                                }
                                                                else
                                                                {
                                                                    for (k = j + 1; k <= i; k++) strcat(str, buffer[k]);

                                                                    if (sign != NORMAL)
                                                                    {
                                                                        if (sign == 1)
                                                                        {
                                                                            strcat(str, "    ior\n");
                                                                            strcat(str, "    ifne L"); strcat(str, itos(L, l)); strcat(str, "\n");
                                                                        }
                                                                        else if (sign == 2)
                                                                        {
                                                                            strcat(str, "    iand\n");
                                                                            strcat(str, "    ifne L"); strcat(str, itos(L, l)); strcat(str, "\n");
                                                                        }
                                                                        else if (sign == EXCLASIGN)
                                                                        {
                                                                            strcat(str, "    iconst_0\n");
                                                                            strcat(str, "    ixor\n");
                                                                            strcat(str, "    ifeq L"); strcat(str, itos(L, l)); strcat(str, "\n");
                                                                        }
                                                                        
                                                                        
                                                                        sign = 0; // reset sign flag
                                                                    }

                                                                    strcat(str, "    iconst_0\n");
                                                                    strcat(str, "    goto L"); strcat(str, itos(L+1, l)); strcat(str, "\n");
                                                                    strcat(str, "  L"); strcat(str, itos(L++, l)); strcat(str, ":\n");
                                                                    strcat(str, "    iconst_1\n");
                                                                    for (k = i + 1; k < bufIndex; k++) strcat(str, buffer[k]);
                                                                    strcat(str, "  L"); strcat(str, itos(L++, l)); strcat(str, ":\n");
                                                                }

                                                                for (k = j + 1; k < bufIndex; k++) buffer[k][0] = '\0';
                                                                
                                                                bufIndex -= j + 1;
                                                                Write(str);
                                                                }
                ;

loop:           WHILE L_BRACE bool_exp R_BRACE block    {
                                                        char str[MAX_LINE_SIZE];
                                                        str[0] = '\0';
                                                        char l[STRSIZE];

                                                        // judge I should pop back how many blocks
                                                        int i, j, k;
                                                        for (i = bufIndex - 1; i >= 0; i--)
                                                        {
                                                            if (bufferMark[i] == BOOLEXP)
                                                            {
                                                                for (j = i; j >= 0; j--)
                                                                {
                                                                    if (bufferMark[j] != BOOLEXP)
                                                                    {
                                                                        break;
                                                                    }
                                                                }
                                                                break;
                                                            }
                                                        }

                                                        int Lbegin = L + 1;
                                                        int Ltrue = L;
                                                        int Lfalse = L + 2;
                                                        int Lexit = L + 3;
                                                        strcat(str, "  L"); strcat(str, itos(Lbegin, l)); strcat(str, ":\n");
                                                        for (k = j + 1; k <= i; k++) strcat(str, buffer[k]);

                                                        if (sign != NORMAL)
                                                        {
                                                            if (sign == 1)
                                                            {
                                                                strcat(str, "    ior\n");
                                                                strcat(str, "    ifne L"); strcat(str, itos(L, l)); strcat(str, "\n");
                                                            }
                                                            else if (sign == 2)
                                                            {
                                                                strcat(str, "    iand\n");
                                                                strcat(str, "    ifne L"); strcat(str, itos(L, l)); strcat(str, "\n");
                                                            }
                                                            else if (sign == EXCLASIGN)
                                                            {
                                                                strcat(str, "    iconst_0\n");
                                                                strcat(str, "    ixor\n");
                                                                strcat(str, "    ifeq L"); strcat(str, itos(L, l)); strcat(str, "\n");
                                                            }
                                                            
                                                            
                                                            sign = 0; // reset sign flag
                                                        }

                                                        strcat(str, "    iconst_0\n");
                                                        strcat(str, "    goto L"); strcat(str, itos(Lfalse, l)); strcat(str, "\n");
                                                        strcat(str, "  L"); strcat(str, itos(Ltrue, l)); strcat(str, ":\n");
                                                        strcat(str, "    iconst_1\n");
                                                        strcat(str, "  L"); strcat(str, itos(Lfalse, l)); strcat(str, ":\n");
                                                        strcat(str, "    ifeq L"); strcat(str, itos(Lexit, l)); strcat(str, "\n");
                                                        for (k = i + 1; k < bufIndex; k++)
                                                            strcat(str, buffer[k]);
                                                        strcat(str, "    goto L"); strcat(str, itos(Lbegin, l)); strcat(str, "\n");
                                                        strcat(str, "  L"); strcat(str, itos(Lexit, l)); strcat(str, ":\n");

                                                        L += 4;

                                                        for (k = j + 1; k < bufIndex; k++) buffer[k][0] = '\0';
                                                        bufIndex -= j + 1;
                                                        Write(str);
                                                        }
                ;

bool_exp:       bool_exp ADD bool_exp             {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        
                                                        if (operand == 0)
                                                        {
                                                            judge(t1, t2, file, arg, $1, $3);
                                                            operand = 1;
                                                        }
                                                        Write("    iadd\n");

                                                        // return part
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi($1); j = stoi($3);
                                                        sum = i + j;
                                                        $$ = strdup(itos(sum, b));

                                                        // put mark for buffer
                                                        Num(BOOLEXP);

                                                        bufIndex++;
                                                        }
                | bool_exp MINUS bool_exp         {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        
                                                        if (operand == 0)
                                                        {
                                                            judge(t1, t2, file, arg, $1, $3);
                                                            operand = 1;
                                                        }

                                                        Write("    isub\n");

                                                        // return part
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi($1); j = stoi($3);
                                                        sum = i - j;
                                                        $$ = strdup(itos(sum, b));

                                                        // put mark for buffer
                                                        Num(BOOLEXP);

                                                        bufIndex++;
                                                        }
                | bool_exp TIME bool_exp          {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        
                                                        if (operand == 0)
                                                        {
                                                            judge(t1, t2, file, arg, $1, $3);
                                                            operand = 1;
                                                        }

                                                        Write("    imul\n");

                                                        // return part
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi($1); j = stoi($3);
                                                        sum = i * j;
                                                        $$ = strdup(itos(sum, b));

                                                        // put mark for buffer
                                                        Num(BOOLEXP);

                                                        bufIndex++;
                                                        }
                | bool_exp DIVIDE bool_exp        {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        
                                                        if (operand == 0)
                                                        {
                                                            judge(t1, t2, file, arg, $1, $3);
                                                            operand = 1;
                                                        }

                                                        Write("    idiv\n");

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

                                                        // put mark for buffer
                                                        Num(BOOLEXP);

                                                        bufIndex++;
                                                        }
                | bool_exp MODULUS bool_exp       {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        
                                                        if (operand == 0)
                                                        {
                                                            judge(t1, t2, file, arg, $1, $3);
                                                            operand = 1;
                                                        }
                                                        Write("    irem\n");

                                                        // return part
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi($1); j = stoi($3);
                                                        sum = i % j;
                                                        $$ = itos(sum, b);

                                                        // put mark for buffer
                                                        Num(BOOLEXP);

                                                        bufIndex++;
                                                        }
                | MINUS bool_exp %prec UMINUS        {
                                                        list_t* t = lookup($2);
                                                        
                                                        // return part
                                                        if (t != NULL && t->neg == 0)
                                                        {
                                                            t->neg = 1;
                                                            $$ = strdup($2);
                                                        }
                                                        else if (t != NULL && t->neg == 1)
                                                        {
                                                            t->neg = 0;
                                                            $$ = strdup($2);
                                                        }
                                                        else
                                                        {
                                                            int i = stoi($2);
                                                            i = -i;
                                                            char a[STRSIZE];
                                                            $$ = strdup(itos(i, a));
                                                        }
                                                        }
                | L_BRACE bool_exp R_BRACE           {
                                                        $$ = strdup($2);
                                                        }
                | EXCLAMATION bool_exp       {
                                                list_t* t = lookup($2);
                                                if (t != NULL && t->glob_flag == 1 && arg[t->counter] != NULL)
                                                {
                                                    Write("    getstatic int "); Write(file); Write("."); Write(t->st_name); Write("\n");
                                                }
                                                else if (t != NULL && t->glob_flag == 0)
                                                {
                                                    char a[STRSIZE];
                                                    Write("    iload "); Write(itos(t->counter, a)); Write("\n");
                                                }
                                                else
                                                {
                                                    Write("    sipush "); Write($2); Write("\n");
                                                }
                                                sign = EXCLASIGN;
                                                // Write("    ixor\n");
                                                // char l[STRSIZE];
                                                // Write("    ifeq L"); Write(itos(L, l)); Write("\n");

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

                                                // put mark for buffer
                                                Num(BOOLEXP);

                                                bufIndex++;
                                                }
                | bool_exp AND bool_exp   {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                if (operand == 0)
                                                {
                                                    judge(t1, t2, file, arg, $1, $3);
                                                    operand = 1;
                                                }

                                                sign = ANDSIGN;

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

                                                // put mark for buffer
                                                Num(BOOLEXP);

                                                bufIndex++;
                                                }   
                | bool_exp OR bool_exp          {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                if (operand == 0)
                                                {
                                                    judge(t1, t2, file, arg, $1, $3);
                                                    operand = 1;
                                                }
 
                                                sign = ORSIGN;

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

                                                // put mark for buffer
                                                Num(BOOLEXP);

                                                bufIndex++;
                                                }
                | bool_exp LESS bool_exp    {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                if (operand == 0)
                                                {
                                                    judge(t1, t2, file, arg, $1, $3);
                                                    operand = 1;
                                                }

                                                Write("    isub\n");
                                                char l[STRSIZE];
                                                Write("    iflt L"); Write(itos(L, l)); Write("\n");
                                                // Write("    iconst_0\n");
                                                
                                                                                
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

                                                // put mark for buffer
                                                Num(BOOLEXP);

                                                bufIndex++;
                                                }
                | bool_exp LE bool_exp    {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                if (operand == 0)
                                                {
                                                    judge(t1, t2, file, arg, $1, $3);
                                                    operand = 1;
                                                }

                                                Write("    isub\n");
                                                char l[STRSIZE];
                                                Write("    ifle L"); Write(itos(L, l)); Write("\n");
                                                // Write("    iconst_0\n");


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

                                                // put mark for buffer
                                                Num(BOOLEXP);

                                                bufIndex++;
                                                }
                | bool_exp E bool_exp     {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                if (operand == 0)
                                                {
                                                    judge(t1, t2, file, arg, $1, $3);
                                                    operand = 1;
                                                }
                                                Write("    isub\n");
                                                char l[STRSIZE];
                                                Write("    ifeq L"); Write(itos(L, l)); Write("\n");
                                                // Write("    iconst_0\n");
                                                

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

                                                // put mark for buffer
                                                Num(BOOLEXP);

                                                bufIndex++;
                                                }
                | bool_exp GE bool_exp    {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                if (operand == 0)
                                                {
                                                    judge(t1, t2, file, arg, $1, $3);
                                                    operand = 1;
                                                }

                                                Write("    isub\n");
                                                char l[STRSIZE];
                                                Write("    ifge L"); Write(itos(L, l)); Write("\n");
                                                // Write("    iconst_0\n");
                                                

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

                                                // put mark for buffer
                                                Num(BOOLEXP);

                                                bufIndex++;
                                                }
                | bool_exp GREATER bool_exp   {
                                                    list_t* t1 = lookup($1);
                                                    list_t* t2 = lookup($3);
                                                    
                                                    if (operand == 0)
                                                    {
                                                        judge(t1, t2, file, arg, $1, $3);
                                                        operand = 1;
                                                    }

                                                    Write("    isub\n");
                                                    char l[STRSIZE];
                                                    Write("    ifgt L"); Write(itos(L, l)); Write("\n");
                                                    // Write("    iconst_0\n");
                                                    

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

                                                    // put mark for buffer
                                                    Num(BOOLEXP);

                                                    bufIndex++;
                                                    }
                | bool_exp NE bool_exp    {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                if (operand == 0)
                                                {
                                                    judge(t1, t2, file, arg, $1, $3);
                                                    operand = 1;
                                                }
                                                
                                                Write("    isub\n");
                                                char l[STRSIZE];
                                                Write("    ifne L"); Write(itos(L, l)); Write("\n");
                                                // Write("    iconst_0\n");
                                                

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

                                                // put mark for buffer
                                                Num(BOOLEXP);

                                                bufIndex++;
                                                }
                | ID                            {
                                                list_t* t = lookup($1);
                                                if (t->st_type == INT_TYPE || t->st_type == CONST_INT_TYPE)
                                                {
                                                    char b[STRSIZE];

                                                    $$ = strdup(t->st_name);

                                                    /*
                                                    if (operand != 0)
                                                    {
                                                        if (t != NULL && t->glob_flag == 1 && arg[t->counter] != NULL)
                                                        {
                                                            Write("    getstatic int "); Write(file); Write("."); Write(t->st_name); Write("\n");
                                                        }
                                                        else if (t != NULL && t->glob_flag == 0)
                                                        {
                                                            char a[STRSIZE];
                                                            Write("    iload "); Write(itos(t->counter, a)); Write("\n");
                                                        }
                                                        bufIndex++;
                                                    }
                                                    */
                                                
                                                }
                                                else
                                                {
                                                    Trace("line %d: The type does not match.\n", linenum);
                                                }
                                                }
                | INTEGER                       {
                                                    $$ = strdup($1);

                                                    /*
                                                    if (operand != 0)
                                                    {
                                                        Write("    sipush "); Write($1); Write("\n");
                                                        bufIndex++;
                                                    }
                                                    */
                                                }
                | TRUE                          {
                                                char l[STRSIZE];
                                                Write("    iconst_1\n");
                                                Write("    ifeq L"); Write(itos(L, l)); Write("\n");
                                                $$ = strdup($1);

                                                Num(BOOLEXP);

                                                bufIndex++;
                                                }
                | FALSE                         {
                                                char l[STRSIZE];
                                                Write("    iconst_0\n");
                                                Write("    ifeq L"); Write(itos(L, l)); Write("\n");
                                                $$ = strdup($1);

                                                Num(BOOLEXP);

                                                bufIndex++;
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

                                                                if (t_cur != NULL)
                                                                {
                                                                    if (t_cur->st_type == INT_TYPE)
                                                                    {
                                                                        t->par_type = INT_TYPE;
                                                                        t->param_name = strdup($1);
                                                                        t->ival = t_cur->st_ival;
                                                                        t->sval = strdup(t_cur->st_sval);
                                                                    }
                                                                }
                                                                else if (t_cur != NULL && cur_scope != 0)
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
                                                list_t* t = lookup($1);
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
                                                                    list_t* t = lookup($1);
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
                                                                                    Write("    getstatic int "); Write(file); Write("."); Write(temp->st_name); Write("\n");
                                                                                }
                                                                                else
                                                                                {
                                                                                    Write("    sipush "); Write(t2->sval); Write("\n");
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
                                                                            Write("    invokestatic int "); Write(file); Write("."); Write(t->st_name); Write("(");
                                                                            for (int i = 0; i < t->num_of_pars - 1; i++)
                                                                            {
                                                                                Write("int, ");
                                                                            }
                                                                            Write("int)\n");

                                                                        }
                                                                        else yyerror("The numbers of parameters are different.");

                                                                        bufIndex++;
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
                                                        
                                                        judge(t1, t2, file, arg, $1, $3);
                                                        Write("    iadd\n");

                                                        // return part
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi($1); j = stoi($3);
                                                        sum = i + j;
                                                        $$ = strdup(itos(sum, b));

                                                        // put mark for buffer
                                                        Num(NORMAL);

                                                        bufIndex++;
                                                        }
                | integer_exp MINUS integer_exp         {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        
                                                        judge(t1, t2, file, arg, $1, $3);

                                                        Write("    isub\n");

                                                        // return part
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi($1); j = stoi($3);
                                                        sum = i - j;
                                                        $$ = strdup(itos(sum, b));

                                                        // put mark for buffer
                                                        Num(NORMAL);

                                                        bufIndex++;
                                                        }
                | integer_exp TIME integer_exp          {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        
                                                        judge(t1, t2, file, arg, $1, $3);

                                                        Write("    imul\n");

                                                        // return part
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi($1); j = stoi($3);
                                                        sum = i * j;
                                                        $$ = strdup(itos(sum, b));

                                                        // put mark for buffer
                                                        Num(NORMAL);

                                                        bufIndex++;
                                                        }
                | integer_exp DIVIDE integer_exp        {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        
                                                        judge(t1, t2, file, arg, $1, $3);

                                                        Write("    idiv\n");

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

                                                        // put mark for buffer
                                                        Num(NORMAL);

                                                        bufIndex++;
                                                        }
                | integer_exp MODULUS integer_exp       {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        
                                                        judge(t1, t2, file, arg, $1, $3);

                                                        Write("    irem\n");

                                                        // return part
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi($1); j = stoi($3);
                                                        sum = i % j;
                                                        $$ = itos(sum, b);

                                                        // put mark for buffer
                                                        Num(NORMAL);

                                                        bufIndex++;
                                                        }
                | MINUS integer_exp %prec UMINUS        {
                                                        list_t* t = lookup($2);
                                                        
                                                        // return part
                                                        if (t != NULL && t->neg == 0)
                                                        {
                                                            t->neg = 1;
                                                            $$ = strdup($2);
                                                        }
                                                        else if (t != NULL && t->neg == 1)
                                                        {
                                                            t->neg = 0;
                                                            $$ = strdup($2);
                                                        }
                                                        else
                                                        {
                                                            int i = stoi($2);
                                                            i = -i;
                                                            char a[STRSIZE];
                                                            $$ = strdup(itos(i, a));
                                                        }
                                                        }
                | L_BRACE integer_exp R_BRACE           {
                                                        $$ = strdup($2);
                                                        }
                | EXCLAMATION integer_exp       {
                                                list_t* t = lookup($2);
                                                if (t != NULL && t->glob_flag == 1 && arg[t->counter] != NULL)
                                                {
                                                    Write("    getstatic int "); Write(file); Write("."); Write(t->st_name); Write("\n");
                                                }
                                                else if (t != NULL && t->glob_flag == 0)
                                                {
                                                    char a[STRSIZE];
                                                    Write("    iload "); Write(itos(t->counter, a)); Write("\n");
                                                }
                                                else
                                                {
                                                    Write("    sipush "); Write($2); Write("\n");
                                                }
                                                Write("    iconst_0\n");
                                                Write("    ixor\n");

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

                                                // put mark for buffer
                                                Num(NORMAL);

                                                bufIndex++;
                                                }
                | integer_exp AND integer_exp   {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                judge(t1, t2, file, arg, $1, $3);

                                                Write("    iand\n");

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

                                                // put mark for buffer
                                                Num(NORMAL);

                                                bufIndex++;
                                                }   
                | integer_exp OR integer_exp    {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                judge(t1, t2, file, arg, $1, $3);
 
                                                Write("    ior\n");

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

                                                // put mark for buffer
                                                Num(NORMAL);

                                                bufIndex++;
                                                }
                | integer_exp LESS integer_exp  {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                judge(t1, t2, file, arg, $1, $3);

                                                Write("    isub\n");
                                                char l[STRSIZE];
                                                Write("    iflt L"); Write(itos(L, l)); Write("\n");
                                                // Write("    iconst_0\n");
                                                
                                                                                
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

                                                // put mark for buffer
                                                Num(NORMAL);

                                                bufIndex++;
                                                }
                | integer_exp LE integer_exp    {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                judge(t1, t2, file, arg, $1, $3);

                                                Write("    isub\n");
                                                char l[STRSIZE];
                                                Write("    ifle L"); Write(itos(L, l)); Write("\n");
                                                // Write("    iconst_0\n");


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

                                                // put mark for buffer
                                                Num(NORMAL);

                                                bufIndex++;
                                                }
                | integer_exp E integer_exp     {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                judge(t1, t2, file, arg, $1, $3);

                                                Write("    isub\n");
                                                char l[STRSIZE];
                                                Write("    ifeq L"); Write(itos(L, l)); Write("\n");
                                                // rite("    iconst_0\n");
                                                

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

                                                // put mark for buffer
                                                Num(NORMAL);

                                                bufIndex++;
                                                }
                | integer_exp GE integer_exp    {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                judge(t1, t2, file, arg, $1, $3);

                                                Write("    isub\n");
                                                char l[STRSIZE];
                                                Write("    ifge L"); Write(itos(L, l)); Write("\n");
                                                // Write("    iconst_0\n");
                                                

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

                                                // put mark for buffer
                                                Num(NORMAL);

                                                bufIndex++;
                                                }
                | integer_exp GREATER integer_exp   {
                                                    list_t* t1 = lookup($1);
                                                    list_t* t2 = lookup($3);
                                                    
                                                    judge(t1, t2, file, arg, $1, $3);

                                                    Write("    isub\n");
                                                    char l[STRSIZE];
                                                    Write("    ifgt L"); Write(itos(L, l)); Write("\n");
                                                    // Write("    iconst_0\n");
                                                    

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

                                                    // put mark for buffer
                                                    Num(NORMAL);

                                                    bufIndex++;
                                                    }
                | integer_exp NE integer_exp    {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                judge(t1, t2, file, arg, $1, $3);
                                                
                                                Write("    isub\n");
                                                char l[STRSIZE];
                                                Write("    ifne L"); Write(itos(L, l)); Write("\n");
                                                // Write("    iconst_0\n");
                                                

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

                                                // put mark for buffer
                                                Num(NORMAL);

                                                bufIndex++;
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
else_integer_exp:   else_integer_exp ADD else_integer_exp             {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        
                                                        judge(t1, t2, file, arg, $1, $3);
                                                        Write("    iadd\n");

                                                        // return part
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi($1); j = stoi($3);
                                                        sum = i + j;
                                                        $$ = strdup(itos(sum, b));

                                                        // put mark for buffer
                                                        Num(ELSEST);

                                                        bufIndex++;
                                                        }
                | else_integer_exp MINUS else_integer_exp   {
                                                            list_t* t1 = lookup($1);
                                                            list_t* t2 = lookup($3);
                                                            
                                                            judge(t1, t2, file, arg, $1, $3);

                                                            Write("    isub\n");

                                                            // return part
                                                            int i, j, sum;
                                                            char b[STRSIZE];
                                                            i = stoi($1); j = stoi($3);
                                                            sum = i - j;
                                                            $$ = strdup(itos(sum, b));

                                                            // put mark for buffer
                                                            Num(ELSEST);

                                                            bufIndex++;
                                                            }
                | else_integer_exp TIME else_integer_exp          {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        
                                                        judge(t1, t2, file, arg, $1, $3);

                                                        Write("    imul\n");

                                                        // return part
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi($1); j = stoi($3);
                                                        sum = i * j;
                                                        $$ = strdup(itos(sum, b));

                                                        // put mark for buffer
                                                        Num(ELSEST);

                                                        bufIndex++;
                                                        }
                | else_integer_exp DIVIDE else_integer_exp  {
                                                            list_t* t1 = lookup($1);
                                                            list_t* t2 = lookup($3);
                                                            
                                                            judge(t1, t2, file, arg, $1, $3);

                                                            Write("    idiv\n");

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

                                                            // put mark for buffer
                                                            Num(ELSEST);

                                                            bufIndex++;
                                                            }
                | else_integer_exp MODULUS else_integer_exp       {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        
                                                        judge(t1, t2, file, arg, $1, $3);

                                                        Write("    irem\n");

                                                        // return part
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi($1); j = stoi($3);
                                                        sum = i % j;
                                                        $$ = itos(sum, b);

                                                        // put mark for buffer
                                                        Num(ELSEST);

                                                        bufIndex++;
                                                        }
                | MINUS else_integer_exp %prec UMINUS        {
                                                        list_t* t = lookup($2);
                                                        
                                                        // return part
                                                        if (t != NULL && t->neg == 0)
                                                        {
                                                            t->neg = 1;
                                                            $$ = strdup($2);
                                                        }
                                                        else if (t != NULL && t->neg == 1)
                                                        {
                                                            t->neg = 0;
                                                            $$ = strdup($2);
                                                        }
                                                        else
                                                        {
                                                            int i = stoi($2);
                                                            i = -i;
                                                            char a[STRSIZE];
                                                            $$ = strdup(itos(i, a));
                                                        }
                                                        }
                | L_BRACE else_integer_exp R_BRACE      {
                                                        $$ = strdup($2);
                                                        }
                | EXCLAMATION else_integer_exp  {
                                                list_t* t = lookup($2);
                                                if (t != NULL && t->glob_flag == 1 && arg[t->counter] != NULL)
                                                {
                                                    Write("    getstatic int "); Write(file); Write("."); Write(t->st_name); Write("\n");
                                                }
                                                else if (t != NULL && t->glob_flag == 0)
                                                {
                                                    char a[STRSIZE];
                                                    Write("    iload "); Write(itos(t->counter, a)); Write("\n");
                                                }
                                                else
                                                {
                                                    Write("    sipush "); Write($2); Write("\n");
                                                }
                                                Write("    iconst_0\n");
                                                Write("    ixor\n");

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

                                                // put mark for buffer
                                                Num(ELSEST);

                                                bufIndex++;
                                                }
                | else_integer_exp AND else_integer_exp   {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                judge(t1, t2, file, arg, $1, $3);

                                                Write("    iand\n");

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

                                                // put mark for buffer
                                                Num(ELSEST);

                                                bufIndex++;
                                                }   
                | else_integer_exp OR else_integer_exp  {
                                                        list_t* t1 = lookup($1);
                                                        list_t* t2 = lookup($3);
                                                        
                                                        judge(t1, t2, file, arg, $1, $3);

                                                        Write("    ior\n");

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

                                                        // put mark for buffer
                                                        Num(ELSEST);

                                                        bufIndex++;
                                                        }
                | else_integer_exp LESS else_integer_exp  {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                judge(t1, t2, file, arg, $1, $3);

                                                Write("    isub\n");
                                                char l[STRSIZE];
                                                Write("    iflt L"); Write(itos(L, l)); Write("\n");
                                                // Write("    iconst_0\n");
                                                
                                                                                
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

                                                // put mark for buffer
                                                Num(ELSEST);

                                                bufIndex++;
                                                }
                | else_integer_exp LE else_integer_exp    {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                judge(t1, t2, file, arg, $1, $3);

                                                Write("    isub\n");
                                                char l[STRSIZE];
                                                Write("    ifle L"); Write(itos(L, l)); Write("\n");
                                                // Write("    iconst_0\n");


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

                                                // put mark for buffer
                                                Num(ELSEST);

                                                bufIndex++;
                                                }
                | else_integer_exp E else_integer_exp     {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                judge(t1, t2, file, arg, $1, $3);

                                                Write("    isub\n");
                                                char l[STRSIZE];
                                                Write("    ifeq L"); Write(itos(L, l)); Write("\n");
                                                // Write("    iconst_0\n");
                                                

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

                                                // put mark for buffer
                                                Num(ELSEST);

                                                bufIndex++;
                                                }
                | else_integer_exp GE else_integer_exp    {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                judge(t1, t2, file, arg, $1, $3);

                                                Write("    isub\n");
                                                char l[STRSIZE];
                                                Write("    ifge L"); Write(itos(L, l)); Write("\n");
                                                // Write("    iconst_0\n");
                                                

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

                                                // put mark for buffer
                                                Num(ELSEST);

                                                bufIndex++;
                                                }
                | else_integer_exp GREATER else_integer_exp   {
                                                    list_t* t1 = lookup($1);
                                                    list_t* t2 = lookup($3);
                                                    
                                                    judge(t1, t2, file, arg, $1, $3);

                                                    Write("    isub\n");
                                                    char l[STRSIZE];
                                                    Write("    ifgt L"); Write(itos(L, l)); Write("\n");
                                                    // Write("    iconst_0\n");
                                                    

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

                                                    // put mark for buffer
                                                    Num(ELSEST);

                                                    bufIndex++;
                                                    }
                | else_integer_exp NE else_integer_exp    {
                                                list_t* t1 = lookup($1);
                                                list_t* t2 = lookup($3);
                                                
                                                judge(t1, t2, file, arg, $1, $3);
                                                
                                                Write("    isub\n");
                                                char l[STRSIZE];
                                                Write("    ifne L"); Write(itos(L, l)); Write("\n");
                                                // Write("    iconst_0\n");
                                                

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

                                                // put mark for buffer
                                                Num(ELSEST);

                                                bufIndex++;
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
else_string_exp:    L_BRACE else_string_exp R_BRACE {
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

int main(int argc, char** argv)
{
    /* create the hash table */
    create();

    /* open the local_var.out */
    local_tab = fopen("local.out", "w");
    fprintf(local_tab, "entering block, next number 0\n");

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
    javaa = fopen(filename, "w");                   /* open a file for java bytecode */
    List("/*-------------------------------------------------------------------------------*/\n");
    List("/*                              Java Assembly Code                               */\n");
    List("/*-------------------------------------------------------------------------------*/\n\n");
    List("class "); List(file); List(" {\n");      /* make the file name as the class name */
    /*------------------------------------------------------------------------------------------------------------*/

    int flag;
    flag = yyparse();

    /* perform parsing */
    if (flag == 1)                      /* parsing */
        yyerror("Parsing error !");     /* syntax error */

    fclose(yyin);                       /* close input file */
    char line[STRSIZE];
    // List("\n/* "); fprintf(javaa, "%s", itos(linenum-1, line)); List(": } */"); // end of rust file
    List("\n}\n");                      /* close the class */

    fclose(javaa);                      /* close the javaa */

    /* output symbol table */
    printf("\nSymbol table:\n");
    yyout = fopen("dump.out", "w");
    dump(yyout);
    fclose(yyout);
    fclose(local_tab);

    printf("\n");

    /* execute javaa */
    
    char exe[STRSIZE] = "./javaa ";
    strcat(exe, filename);
    system(exe);

    printf("\n");
    

    /* cat the file *.jasm */
    /*
    char cat[STRSIZE] = "cat ";
    strcat(cat, filename);
    system(cat);
    */
    /*
    printf("\n");
    */

    /* execute java */
    
    printf("*\tResult of %s.class: \n\n", file);
    char class[STRSIZE] = "java ";
    strcat(class, file);
    system(class);
    

    return 0;
}

// judge that I should take a global variable or a local variable
void judge(list_t* t1, list_t* t2, char* file, char arg[STRSIZE][STRSIZE], char* $1, char* $3)
{
	char cat[MAX_LINE_SIZE];
    cat[0] = '\0';
	char a[SIZE];

    short flag1 = 1, flag3 = 1;
    int i = 0;
    while ($1[i] != '\0')
    {
        if (!isdigit($1[i]))
        {
            flag1 = 0;
            break;
        }
        i++;
    }
    i = 0;
    while ($3[i] != '\0')
    {
        if (!isdigit($3[i]))
        {
            flag3 = 0;
            break;
        }
        i++;
    }

	if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 1)
	{
		strcat(cat, "    getstatic int "); strcat(cat, file); strcat(cat, "."); strcat(cat, t1->st_name); strcat(cat, "\n");
		strcat(cat, "    getstatic int "); strcat(cat, file); strcat(cat, "."); strcat(cat, t2->st_name); strcat(cat, "\n");
	}
	else if (t1 != NULL && t1->glob_flag == 1 && t2 != NULL && t2->glob_flag == 0 && arg[t1->counter] == NULL)
	{
		strcat(cat, "    getstatic int "); strcat(cat, file); strcat(cat, "."); strcat(cat, t1->st_name); strcat(cat, "\n");
		strcat(cat, "    iload "); strcat(cat, itos(t2->counter, a)); strcat(cat, "\n");
	}
	else if (t1 != NULL && t1->glob_flag == 0 && t2 != NULL && t2->glob_flag == 1 && arg[t2->counter] == NULL)
	{
		strcat(cat, "    iload "); strcat(cat, itos(t1->counter, a)); strcat(cat, "\n");
		strcat(cat, "    getstatic int "); strcat(cat, file); strcat(cat, "."); strcat(cat, t2->st_name); strcat(cat, "\n");
	}
	else if (t1 != NULL && t1->glob_flag == 1 && t2 == NULL && flag3 == 1 ) 
	{
		strcat(cat, "    getstatic int "); strcat(cat, file); strcat(cat, "."); strcat(cat, t1->st_name); strcat(cat, "\n");
		strcat(cat, "    sipush "); strcat(cat, $3); strcat(cat, "\n");
	}
	else if (t1 == NULL && flag1 == 1 && t2 != NULL && t2->glob_flag == 1 && t2->scope == 0)
	{
		strcat(cat, "    sipush "); strcat(cat, $1); strcat(cat, "\n");
		strcat(cat, "    getstatic int "); strcat(cat, file); strcat(cat, "."); strcat(cat, t2->st_name); strcat(cat, "\n");
	}
	else if (t1 != NULL && t2 != NULL && t1->constant == 0 && t2->constant == 0)
	{
		strcat(cat, "    iload "); strcat(cat, itos(t1->counter, a)); strcat(cat, "\n");
		strcat(cat, "    iload "); strcat(cat, itos(t2->counter, a)); strcat(cat, "\n");
	}
    else if (t1 != NULL && t2 != NULL && t1->constant == 1 && t2->constant == 0)
    {
        strcat(cat, "    sipush "); strcat(cat, t1->st_sval); strcat(cat, "\n");
		strcat(cat, "    iload "); strcat(cat, itos(t2->counter, a)); strcat(cat, "\n");
    }
    else if (t1 != NULL && t2 != NULL && t1->constant == 0 && t2->constant == 1)
    {
		strcat(cat, "    iload "); strcat(cat, itos(t1->counter, a)); strcat(cat, "\n");
        strcat(cat, "    sipush "); strcat(cat, t2->st_sval); strcat(cat, "\n");
    }
	else if (t1 != NULL && t2 == NULL && flag3 == 1 )
	{
		strcat(cat, "    iload "); strcat(cat, itos(t1->counter, a)); strcat(cat, "\n");
		strcat(cat, "    sipush "); strcat(cat, $3); strcat(cat, "\n");
	}
	else if (t1 == NULL && flag1 == 1 && t2 != NULL)
	{
		strcat(cat, "    sipush "); strcat(cat, $1); strcat(cat, "\n");
		strcat(cat, "    iload "); strcat(cat, itos(t2->counter, a)); strcat(cat, "\n");
	}
	else if (t1 == NULL && flag1 == 1 && t2 == NULL && flag3 == 1 )
	{
		strcat(cat, "    sipush "); strcat(cat, t1->st_sval); strcat(cat, "\n");
		strcat(cat, "    sipush "); strcat(cat, t2->st_sval); strcat(cat, "\n");
	}

	Write(cat);
}