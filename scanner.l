/* 
我是在Mac上使用Homebrew下載flex，可能跟Unix的lex會有落差
所以如果助教要測試時，可能需要使用linux或Mac上的flex
這點請多包涵，因為我電腦容量已炸裂，無法使用虛擬機裝Unix的lex的組合

執行檔使用方法為./exe inputFile
我是用讀檔方式讀取文字

April 24, 2018
I increase a new token '->', READ for parser

April 27, 2018
I change the sign of '<', '>', '=', '!', '->' in order to recognize the tokens in bison.
Return every tokens for parser.

April 29, 2018
I changed the identifier part in order to recognize the type of the id, but it doesn't work.
Therefore, I recovery the part.

April 30, 2018
I increase the boolVal in yylval union

May 02, 2018
I discover a problem when I use "sscanf(yytext, "%s", yylval.stringVal);".
I cannot parse correctly since I will get a segmentation fault 11.
So I use another term "yylval.stringVal = strdup(yytext);" for parser, and it works.

May 05, 2018
'<=', '>=', '==', '!=', '&&', '||', '+=', '-=', '*=', '/=', '++', and '--' 
return
LE, GE, E, NE, AND, OR, AE, ME, TE, DE, AA, and MM

May 17, 2018
Make ID return yylval.stringVal, instead of yylval.symptr

May 18, 2018
Make integer return stringVal

May 24, 2018
Make true and false return stringVal
*/
%option noyywrap

%{
#include "symbols.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "parser.tab.h"

#define LIST     strcat(buf,yytext)
#define token(t) {LIST; printf("<%s>\n", t);}
#define tokenInteger(t, i) {LIST; printf("<%s: %d>\n", t, i);}
#define tokenReal(t, r) {LIST; printf("<%s: %lf>\n", t, r);}
#define tokenString(t, s) {LIST; printf("<%s: %s>\n", t, s);}

#define MAX_LINE_LENG 256
#define STRSIZE        40

extern int cur_scope;
extern FILE* yyin;
extern FILE* yyout;
extern FILE* javaa;
int linenum = 1;
char buf[MAX_LINE_LENG];
char code[MAX_LINE_LENG][MAX_LINE_LENG];
int codeCounter = 0;
char* tempStr;
int indexForStr = 1;
list_t* temp;
%}
%x Comment
%%
"//".*          	{LIST;}

"/*" 			{BEGIN(Comment); LIST;}
<Comment>"*/" 		{LIST; BEGIN(0);}
<Comment>\n             {LIST; printf("%d: %s\n", linenum++, buf); buf[0] = '\0';}
<Comment>. 		{LIST;}

"bool" 		{token("BOOL"); return BOOL;}
"break" 	{token("BREAK"); return BREAK;}
"char" 		{token("CHAR"); return CHAR;}
"continue" 	{token("CONTINUE"); return CONTINUE;}
"do" 		{token("DO"); return DO;}
"else" 		{token("ELSE"); return ELSE;}
"enum" 		{token("ENUM"); return ENUM;}
"extern" 	{token("EXTERN"); return EXTERN;}
"false" 	{token("FALSE"); yylval.stringVal = strdup("false"); return FALSE;}
"float" 	{token("FLOAT"); return FLOAT;}
"for" 		{token("FOR"); return FOR;}
"fn" 		{token("FN"); return FN;}
"if" 		{token("IF"); return IF;}
"in" 		{token("IN"); return IN;}
"int" 	 	{token("INT"); return INT;}
"let" 		{token("LET"); return LET;}
"loop" 		{token("LOOP"); return LOOP;}
"match" 	{token("MATCH"); return MATCH;}
"mut" 		{token("MUT"); return MUT;}
"print" 	{token("PRINT"); return PRINT;}
"println" 	{token("PRINTLN"); return PRINTLN;}
"pub" 		{token("PUB"); return PUB;}
"return" 	{token("RETURN"); return RETURN;}
"self" 		{token("SELF"); return SELF;}
"static" 	{token("STATIC"); return STATIC;}
"str" 		{token("STR"); return STR;}
"struct" 	{token("STRUCT"); return STRUCT;}
"true" 		{token("TRUE"); yylval.stringVal = strdup("true"); return TRUE;}
"use" 		{token("USE"); return USE;}
"where" 	{token("WHERE"); return WHERE;}
"while" 	{token("WHILE"); return WHILE;}

"," 		{token("','"); return COMMA;}
":" 		{token("':'"); return COLON;}
";" 		{token("';'"); return SEMICOLON;}
"(" 		{token("'('"); return L_BRACE;}
")" 		{token("')'"); return R_BRACE;}
"[" 		{token("'['"); return L_SB;}
"]" 		{token("']'"); return R_SB;}
"{" 		{token("'{'"); return L_B;}
"}" 		{token("'}'"); return R_B;}

"+" 		{token("'+'"); return ADD;}
"-" 		{token("'-'"); return MINUS;}
"*" 		{token("'*'"); return TIME;}
"/" 		{token("'/'"); return DIVIDE;}
"++" 		{token("'++'"); return AA;}
"--" 		{token("'--'"); return MM;}
"%"		{token("'%'"); return MODULUS;}

"<" 		{token("'<'"); return LESS;}
"<="		{token("'<='"); return LE;}
">=" 		{token("'>='"); return GE;}
">" 		{token("'>'"); return GREATER;}
"==" 		{token("'=='"); return E;}
"!="		{token("'!='"); return NE;}

"&&" 		{token("'&&'"); return AND;}
"||" 		{token("'||'"); return OR;}
"!" 		{token("'!'"); return EXCLAMATION;}

"=" 		{token("'='"); return ASSIGN;}

"+=" 		{token("'+='"); return AE;}
"-=" 		{token("'-='"); return ME;}
"*=" 		{token("'*='"); return TE;}
"/=" 		{token("'/='"); return DE;}

"->"            {token("'->'"); return ARROW;}
"read"          {token("'READ'"); return READ;}

[A-Z_a-z]([A-Z_a-z]|[0-9])*             {
                                        yylval.stringVal = strdup(yytext);
                                        tokenString("id", yytext);
                                        return ID;
                                        }               

"0"|[0-9][0-9]*                         {
                                        yylval.stringVal = strdup(yytext);
                                        tokenString("integer", yylval.stringVal);
	                                return INTEGER;
                                        }

[0-9_]+"."[0-9]+                        {
                                        yylval.floatVal = atof(yytext);
                                        tokenReal("real", yylval.floatVal);
	                                return REAL;
                                        }

\"([\\.]|[^\\"])*\"                     {
                                        tempStr = malloc((strlen(yytext) - 1) * sizeof(char));
                                        for (int i = 0; i < strlen(yytext) - 2; i++)
                                        {
                                                tempStr[i] = yytext[indexForStr];
                                                indexForStr++;
                                        }
                                        tempStr[strlen(yytext) - 1] = '\0';

                                        yylval.stringVal = strdup(yytext);
                                        tokenString("string", tempStr);
                                        free(tempStr);
                                        indexForStr = 1;

	                                return STRING;
                                        }

\n      {
        char line[STRSIZE];

        // store code for writing into javaa file
        // strcat(code[codeCounter], "/*"); strcat(code[codeCounter], itos(linenum, line)); strcat(code[codeCounter], ": "); strcat(code[codeCounter], buf); strcat(code[codeCounter++], "*/\n");

        // write every code line into javaa
        // fprintf(javaa, "%s", code[codeCounter-1]);

        LIST;
        printf("%d: %s", linenum++, buf);
        buf[0] = '\0';
        }

[ \t]*  {LIST;}

.       {
        LIST;
        printf("%d:%s\n", linenum+1, buf);
        printf("bad character:'%s'\n",yytext);
        exit(-1);
        }
%%
