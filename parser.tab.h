/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     REAL = 258,
     ID = 259,
     STRING = 260,
     INTEGER = 261,
     TRUE = 262,
     FALSE = 263,
     INT = 264,
     FLOAT = 265,
     STR = 266,
     BOOL = 267,
     BREAK = 268,
     CHAR = 269,
     CONTINUE = 270,
     DO = 271,
     ELSE = 272,
     ENUM = 273,
     EXTERN = 274,
     FOR = 275,
     FN = 276,
     IF = 277,
     IN = 278,
     LET = 279,
     LOOP = 280,
     MATCH = 281,
     MUT = 282,
     PRINT = 283,
     PRINTLN = 284,
     RETURN = 285,
     SELF = 286,
     STATIC = 287,
     STRUCT = 288,
     USE = 289,
     WHERE = 290,
     WHILE = 291,
     READ = 292,
     PUB = 293,
     COMMA = 294,
     COLON = 295,
     SEMICOLON = 296,
     L_BRACE = 297,
     R_BRACE = 298,
     L_SB = 299,
     R_SB = 300,
     L_B = 301,
     R_B = 302,
     LESS = 303,
     GREATER = 304,
     ASSIGN = 305,
     EXCLAMATION = 306,
     ARROW = 307,
     LE = 308,
     GE = 309,
     E = 310,
     NE = 311,
     AND = 312,
     OR = 313,
     AE = 314,
     ME = 315,
     TE = 316,
     DE = 317,
     AA = 318,
     MM = 319,
     ADD = 320,
     MINUS = 321,
     TIME = 322,
     DIVIDE = 323,
     MODULUS = 324,
     UMINUS = 325
   };
#endif
/* Tokens.  */
#define REAL 258
#define ID 259
#define STRING 260
#define INTEGER 261
#define TRUE 262
#define FALSE 263
#define INT 264
#define FLOAT 265
#define STR 266
#define BOOL 267
#define BREAK 268
#define CHAR 269
#define CONTINUE 270
#define DO 271
#define ELSE 272
#define ENUM 273
#define EXTERN 274
#define FOR 275
#define FN 276
#define IF 277
#define IN 278
#define LET 279
#define LOOP 280
#define MATCH 281
#define MUT 282
#define PRINT 283
#define PRINTLN 284
#define RETURN 285
#define SELF 286
#define STATIC 287
#define STRUCT 288
#define USE 289
#define WHERE 290
#define WHILE 291
#define READ 292
#define PUB 293
#define COMMA 294
#define COLON 295
#define SEMICOLON 296
#define L_BRACE 297
#define R_BRACE 298
#define L_SB 299
#define R_SB 300
#define L_B 301
#define R_B 302
#define LESS 303
#define GREATER 304
#define ASSIGN 305
#define EXCLAMATION 306
#define ARROW 307
#define LE 308
#define GE 309
#define E 310
#define NE 311
#define AND 312
#define OR 313
#define AE 314
#define ME 315
#define TE 316
#define DE 317
#define AA 318
#define MM 319
#define ADD 320
#define MINUS 321
#define TIME 322
#define DIVIDE 323
#define MODULUS 324
#define UMINUS 325




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 73 "parser.y"
{
    char* stringVal;
    double floatVal;
    int intVal;
    bool boolVal;
    list_t* symptr;
    Param* parptr; // struct Parameter type
}
/* Line 1529 of yacc.c.  */
#line 198 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

