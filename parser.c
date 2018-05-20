/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 30 "parser.y"

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

#define true 1
#define false 0

extern FILE* yyin;
extern FILE* yyout;
extern int linenum;
extern int yylex();
FILE* javaa;        //file for bytecode
char* file;         // filename without extension

void yyerror(char* msg);
int             stoi(char *str);
char*           itos(int i, char b[]);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 288 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 301 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   412

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNRULES -- Number of states.  */
#define YYNSTATES  181

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    16,    18,    21,
      24,    26,    28,    33,    37,    41,    44,    46,    48,    54,
      62,    67,    74,    81,    90,    92,    97,   101,   105,   108,
     111,   113,   119,   126,   134,   143,   145,   149,   153,   156,
     158,   163,   167,   171,   175,   179,   182,   186,   188,   190,
     198,   204,   210,   212,   214,   218,   222,   226,   230,   234,
     238,   241,   245,   249,   251,   253,   255,   259,   261,   263,
     267,   272,   276,   280,   284,   288,   291,   295,   299,   303,
     307,   311,   315,   319,   322,   326,   330,   332,   334,   336,
     340
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      72,     0,    -1,    82,    -1,    73,    82,    -1,    73,    78,
      -1,    73,    79,    -1,    78,    -1,    79,    -1,    74,    78,
      -1,    74,    79,    -1,    78,    -1,    79,    -1,    77,    74,
      86,    76,    -1,    77,    74,    76,    -1,    77,    86,    76,
      -1,    77,    76,    -1,    47,    -1,    46,    -1,    24,     4,
      50,    94,    41,    -1,    24,     4,    40,     9,    50,    94,
      41,    -1,    24,    27,     4,    41,    -1,    24,    27,     4,
      40,     9,    41,    -1,    24,    27,     4,    50,    94,    41,
      -1,    24,    27,     4,    40,     9,    50,    94,    41,    -1,
      42,    -1,    46,    74,    86,    76,    -1,    46,    74,    76,
      -1,    46,    86,    76,    -1,    46,    76,    -1,    82,    82,
      -1,    83,    -1,    21,     4,    80,    43,    81,    -1,    21,
       4,    80,    84,    43,    81,    -1,    21,     4,    80,    43,
      52,     9,    81,    -1,    21,     4,    80,    84,    43,    52,
       9,    81,    -1,    85,    -1,    84,    39,    84,    -1,     4,
      40,     9,    -1,    86,    87,    -1,    87,    -1,     4,    50,
      94,    41,    -1,    28,    94,    41,    -1,    28,    95,    41,
      -1,    29,    94,    41,    -1,    29,    95,    41,    -1,    30,
      41,    -1,    30,    94,    41,    -1,    88,    -1,    89,    -1,
      22,    42,    90,    43,    75,    17,    75,    -1,    22,    42,
      90,    43,    75,    -1,    36,    42,    90,    43,    75,    -1,
      94,    -1,    95,    -1,    95,    48,    95,    -1,    95,    53,
      95,    -1,    95,    55,    95,    -1,    95,    54,    95,    -1,
      95,    49,    95,    -1,    95,    56,    95,    -1,    51,    95,
      -1,    95,    57,    95,    -1,    95,    58,    95,    -1,     7,
      -1,     8,    -1,    92,    -1,    91,    39,    91,    -1,     4,
      -1,     6,    -1,     4,    42,    43,    -1,     4,    42,    91,
      43,    -1,    94,    65,    94,    -1,    94,    66,    94,    -1,
      94,    67,    94,    -1,    94,    68,    94,    -1,    66,    94,
      -1,    42,    94,    43,    -1,    94,    48,    94,    -1,    94,
      53,    94,    -1,    94,    55,    94,    -1,    94,    54,    94,
      -1,    94,    49,    94,    -1,    94,    56,    94,    -1,    51,
      94,    -1,    94,    57,    94,    -1,    94,    58,    94,    -1,
       6,    -1,     4,    -1,    93,    -1,    42,    95,    43,    -1,
       5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   121,   121,   121,   124,   125,   126,   127,   130,   131,
     132,   133,   136,   137,   138,   139,   142,   148,   153,   165,
     179,   197,   215,   250,   284,   289,   290,   291,   292,   295,
     296,   299,   326,   362,   385,   423,   427,   433,   464,   465,
     468,   493,   498,   503,   508,   513,   516,   519,   520,   523,
     524,   527,   530,   541,   556,   586,   620,   623,   653,   683,
     686,   689,   692,   695,   698,   703,   707,   713,   743,   753,
     774,   828,   835,   842,   849,   860,   867,   870,   882,   894,
     906,   918,   930,   942,   954,   966,   978,   981,   993,  1006,
    1009
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "REAL", "ID", "STRING", "INTEGER",
  "TRUE", "FALSE", "INT", "FLOAT", "STR", "BOOL", "BREAK", "CHAR",
  "CONTINUE", "DO", "ELSE", "ENUM", "EXTERN", "FOR", "FN", "IF", "IN",
  "LET", "LOOP", "MATCH", "MUT", "PRINT", "PRINTLN", "RETURN", "SELF",
  "STATIC", "STRUCT", "USE", "WHERE", "WHILE", "READ", "PUB", "COMMA",
  "COLON", "SEMICOLON", "L_BRACE", "R_BRACE", "L_SB", "R_SB", "L_B", "R_B",
  "LESS", "GREATER", "ASSIGN", "EXCLAMATION", "ARROW", "LE", "GE", "E",
  "NE", "AND", "OR", "AE", "ME", "TE", "DE", "AA", "MM", "ADD", "MINUS",
  "TIME", "DIVIDE", "MODULUS", "UMINUS", "$accept", "program",
  "global_declaration", "local_declaration", "block", "end", "start",
  "constant_declaration", "variable_declaration", "fn_start", "fn_block",
  "functions", "function", "formal_arguments", "formal_argument",
  "statements", "statement", "conditional", "loop", "bool_exp",
  "comma_separated_exps", "comma_separated_exp", "function_invocation",
  "integer_exp", "string_exp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    72,    73,    73,    73,    73,    74,    74,
      74,    74,    75,    75,    75,    75,    76,    77,    78,    78,
      79,    79,    79,    79,    80,    81,    81,    81,    81,    82,
      82,    83,    83,    83,    83,    84,    84,    85,    86,    86,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    88,
      88,    89,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    91,    91,    92,    92,    93,
      93,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    95,
      95
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     1,     1,     2,     2,
       1,     1,     4,     3,     3,     2,     1,     1,     5,     7,
       4,     6,     6,     8,     1,     4,     3,     3,     2,     2,
       1,     5,     6,     7,     8,     1,     3,     3,     2,     1,
       4,     3,     3,     3,     3,     2,     3,     1,     1,     7,
       5,     5,     1,     1,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     1,     1,     1,     3,     1,     1,     3,
       4,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     1,     1,     1,     3,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     6,     7,     2,    30,     0,
       0,     0,     1,     4,     5,     3,    29,    24,     0,     0,
       0,     0,     0,     0,     0,    35,     0,    87,    86,     0,
       0,     0,    88,     0,     0,    20,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,    83,    75,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
      16,     0,    28,    10,    11,     0,    39,    47,    48,     0,
      36,     0,    32,     0,    67,    68,    69,     0,    65,    76,
      77,    81,    78,    80,    79,    82,    84,    85,    71,    72,
      73,    74,    21,     0,    22,     0,     0,    90,     0,     0,
       0,     0,     0,    45,     0,     0,    26,     8,     9,     0,
      27,    38,    33,     0,    19,     0,    70,     0,     0,    63,
      64,     0,     0,    52,    53,     0,    41,    42,    43,    44,
      46,     0,    25,    34,    66,    23,    40,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,    17,
      50,     0,     0,    54,    58,    55,    57,    56,    59,    61,
      62,    51,     0,     0,    15,     0,    49,    13,     0,    14,
      12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    71,   160,    72,   161,    73,    74,    18,
      40,    16,     8,    24,    25,    75,    76,    77,    78,   132,
      87,    88,    32,    45,   134
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -104
static const yytype_int16 yypact[] =
{
     -10,     2,    43,    78,   -10,  -104,  -104,     9,  -104,    37,
      33,    87,  -104,  -104,  -104,     9,     9,  -104,    24,    94,
      50,    18,    75,    30,    56,  -104,    69,    79,  -104,    50,
      50,    50,  -104,   123,   117,  -104,    50,   127,   113,   130,
    -104,   143,    52,    50,    20,   291,   333,  -104,  -104,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    34,   144,  -104,    98,   111,    11,    11,    23,   112,
    -104,   113,  -104,  -104,  -104,   116,  -104,  -104,  -104,   115,
     126,   153,  -104,   165,  -104,  -104,  -104,    63,  -104,  -104,
      57,    57,    57,    57,    57,    57,   333,   102,    -7,    -7,
    -104,  -104,  -104,    50,  -104,    50,    15,  -104,    11,   186,
     125,   207,   134,  -104,   228,    15,  -104,  -104,  -104,   116,
    -104,  -104,  -104,   115,  -104,    90,  -104,   249,   270,  -104,
    -104,    11,   139,   312,   354,   140,  -104,  -104,  -104,  -104,
    -104,   141,  -104,  -104,   147,  -104,  -104,  -104,   148,    38,
      38,    38,    38,    38,    38,    38,    38,  -104,   148,  -104,
     170,   113,    38,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,   148,   113,  -104,   116,  -104,  -104,   116,  -104,
    -104
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,  -104,    35,  -103,   -68,  -104,     0,     1,  -104,
     -33,   114,  -104,   154,  -104,   -61,   -67,  -104,  -104,    88,
      80,  -104,  -104,   -18,   -22
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       5,     6,    33,   116,    13,    14,     9,   120,   121,    82,
     119,     1,    46,    47,     2,    27,   107,    28,    62,    27,
     107,    28,   129,   130,    84,    83,    85,    27,    22,    28,
       1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   107,   110,   112,   122,    10,   109,   111,
     114,   142,   121,   108,    27,   171,    28,   108,    34,    35,
      59,    60,    30,    86,   113,    29,   131,    23,    36,   176,
      11,   117,   118,    19,    30,   102,    38,    31,    12,    17,
     162,    31,    39,    20,   103,   127,   135,   128,   133,    31,
     143,    21,    29,   174,    84,    41,    85,   133,    38,    42,
     175,    30,   125,    26,    81,   177,   126,   179,   121,   147,
     180,   121,   178,    46,     7,    37,    31,    64,    15,    43,
      64,    44,    57,    58,    59,    60,    61,   163,   164,   165,
     166,   167,   168,   169,   170,    65,    63,     2,    65,    79,
     135,    66,    67,    68,    66,    67,    68,    22,   105,    69,
      49,    50,    69,   106,   115,    51,    52,    53,    54,    55,
      70,    38,   123,    70,    48,    41,   137,    57,    58,    59,
      60,    49,    50,   117,   118,   139,    51,    52,    53,    54,
      55,    56,   148,   157,   158,   104,   125,   172,    57,    58,
      59,    60,    49,    50,   159,    80,   173,    51,    52,    53,
      54,    55,    56,   141,     0,   144,   124,     0,     0,    57,
      58,    59,    60,    49,    50,     0,     0,     0,    51,    52,
      53,    54,    55,    56,     0,     0,     0,   136,     0,     0,
      57,    58,    59,    60,    49,    50,     0,     0,     0,    51,
      52,    53,    54,    55,    56,     0,     0,     0,   138,     0,
       0,    57,    58,    59,    60,    49,    50,     0,     0,     0,
      51,    52,    53,    54,    55,    56,     0,     0,     0,   140,
       0,     0,    57,    58,    59,    60,    49,    50,     0,     0,
       0,    51,    52,    53,    54,    55,    56,     0,     0,     0,
     145,     0,     0,    57,    58,    59,    60,    49,    50,     0,
       0,     0,    51,    52,    53,    54,    55,    56,     0,     0,
       0,   146,     0,     0,    57,    58,    59,    60,    49,    50,
       0,     0,     0,    51,    52,    53,    54,    55,    56,     0,
       0,     0,     0,     0,    89,    57,    58,    59,    60,    49,
      50,     0,     0,     0,    51,    52,    53,    54,    55,    56,
       0,     0,     0,     0,     0,     0,    57,    58,    59,    60,
      49,    50,     0,     0,     0,    51,    52,    53,    54,    55,
      56,     0,     0,     0,     0,     0,     0,    57,    58,    59,
      60,    49,    50,     0,     0,     0,    51,    52,    53,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    57,    58,
      59,    60,   149,   150,     0,     0,     0,   151,   152,   153,
     154,   155,   156
};

static const yytype_int16 yycheck[] =
{
       0,     0,    20,    71,     4,     4,     4,    75,    75,    42,
      71,    21,    30,    31,    24,     4,     5,     6,    36,     4,
       5,     6,     7,     8,     4,    43,     6,     4,     4,     6,
      21,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,     5,    66,    67,    79,     4,    66,    67,
      68,   119,   119,    42,     4,   158,     6,    42,    40,    41,
      67,    68,    51,    43,    41,    42,    51,    43,    50,   172,
      27,    71,    71,    40,    51,    41,    46,    66,     0,    42,
      42,    66,    52,    50,    50,   103,   108,   105,   106,    66,
     123,     4,    42,   161,     4,    39,     6,   115,    46,    43,
     161,    51,    39,     9,    52,   173,    43,   175,   175,   131,
     178,   178,   173,   131,     0,    40,    66,     4,     4,    50,
       4,    42,    65,    66,    67,    68,     9,   149,   150,   151,
     152,   153,   154,   155,   156,    22,     9,    24,    22,     9,
     162,    28,    29,    30,    28,    29,    30,     4,    50,    36,
      48,    49,    36,    42,    42,    53,    54,    55,    56,    57,
      47,    46,     9,    47,    41,    39,    41,    65,    66,    67,
      68,    48,    49,   173,   173,    41,    53,    54,    55,    56,
      57,    58,    43,    43,    43,    41,    39,    17,    65,    66,
      67,    68,    48,    49,    46,    41,   161,    53,    54,    55,
      56,    57,    58,   115,    -1,   125,    41,    -1,    -1,    65,
      66,    67,    68,    48,    49,    -1,    -1,    -1,    53,    54,
      55,    56,    57,    58,    -1,    -1,    -1,    41,    -1,    -1,
      65,    66,    67,    68,    48,    49,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    58,    -1,    -1,    -1,    41,    -1,
      -1,    65,    66,    67,    68,    48,    49,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    58,    -1,    -1,    -1,    41,
      -1,    -1,    65,    66,    67,    68,    48,    49,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      41,    -1,    -1,    65,    66,    67,    68,    48,    49,    -1,
      -1,    -1,    53,    54,    55,    56,    57,    58,    -1,    -1,
      -1,    41,    -1,    -1,    65,    66,    67,    68,    48,    49,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    43,    65,    66,    67,    68,    48,
      49,    -1,    -1,    -1,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,
      48,    49,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    48,    49,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      67,    68,    48,    49,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    58
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    24,    72,    73,    78,    79,    82,    83,     4,
       4,    27,     0,    78,    79,    82,    82,    42,    80,    40,
      50,     4,     4,    43,    84,    85,     9,     4,     6,    42,
      51,    66,    93,    94,    40,    41,    50,    40,    46,    52,
      81,    39,    43,    50,    42,    94,    94,    94,    41,    48,
      49,    53,    54,    55,    56,    57,    58,    65,    66,    67,
      68,     9,    94,     9,     4,    22,    28,    29,    30,    36,
      47,    74,    76,    78,    79,    86,    87,    88,    89,     9,
      84,    52,    81,    94,     4,     6,    43,    91,    92,    43,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    41,    50,    41,    50,    42,     5,    42,    94,
      95,    94,    95,    41,    94,    42,    76,    78,    79,    86,
      76,    87,    81,     9,    41,    39,    43,    94,    94,     7,
       8,    51,    90,    94,    95,    95,    41,    41,    41,    41,
      41,    90,    76,    81,    91,    41,    41,    95,    43,    48,
      49,    53,    54,    55,    56,    57,    58,    43,    43,    46,
      75,    77,    42,    95,    95,    95,    95,    95,    95,    95,
      95,    75,    17,    74,    76,    86,    75,    76,    86,    76,
      76
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 16:
#line 142 "parser.y"
    {
                                                                    hide_scope();
                                                                    counter = 0;
                                                                    ;}
    break;

  case 17:
#line 148 "parser.y"
    {
                                                                    incr_scope();
                                                                    ;}
    break;

  case 18:
#line 153 "parser.y"
    {
                                                                    list_t* t_glob = lookup_scope((yyvsp[(2) - (5)].stringVal), 0);
                                                                    list_t* t_cur = lookup((yyvsp[(2) - (5)].stringVal));

                                                                    if (t_glob == NULL && t_cur == NULL)
                                                                    {
                                                                        insert((yyvsp[(2) - (5)].stringVal), strlen((yyvsp[(2) - (5)].stringVal)), CONST_INT_TYPE, linenum, func);
                                                                        list_t* t = lookup((yyvsp[(2) - (5)].stringVal));
                                                                        t->st_ival = stoi((yyvsp[(4) - (5)].stringVal));
                                                                    }
                                                                    else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                    ;}
    break;

  case 19:
#line 165 "parser.y"
    {
                                                                            list_t* t_glob = lookup_scope((yyvsp[(2) - (7)].stringVal), 0);
                                                                            list_t* t_cur = lookup((yyvsp[(2) - (7)].stringVal));

                                                                            if (t_glob == NULL && t_cur == NULL)
                                                                            {
                                                                                insert((yyvsp[(2) - (7)].stringVal), strlen((yyvsp[(2) - (7)].stringVal)), CONST_INT_TYPE, linenum, func);
                                                                                list_t* t = lookup((yyvsp[(2) - (7)].stringVal));
                                                                                t->st_ival = stoi((yyvsp[(6) - (7)].stringVal));
                                                                            }
                                                                            else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                            ;}
    break;

  case 20:
#line 179 "parser.y"
    {
                                                                        list_t* t_glob = lookup_scope((yyvsp[(3) - (4)].stringVal), 0);
                                                                        list_t* t_cur = lookup((yyvsp[(3) - (4)].stringVal));

                                                                        if (t_glob == NULL)
                                                                        {
                                                                            insert((yyvsp[(3) - (4)].stringVal), strlen((yyvsp[(3) - (4)].stringVal)), UNDEF, linenum, func);
                                                                            fprintf(javaa, "field static int %s\n\n", (yyvsp[(3) - (4)].stringVal));
                                                                        }
                                                                        else if (t_cur == NULL)
                                                                        {
                                                                            insert((yyvsp[(3) - (4)].stringVal), strlen((yyvsp[(3) - (4)].stringVal)), UNDEF, linenum, func);
                                                                            list_t* t = lookup((yyvsp[(3) - (4)].stringVal));
                                                                            t->counter = counter;
                                                                            counter++;
                                                                        }
                                                                        else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                        ;}
    break;

  case 21:
#line 197 "parser.y"
    {
                                                                        list_t* t_glob = lookup_scope((yyvsp[(3) - (6)].stringVal), 0);
                                                                        list_t* t_cur = lookup((yyvsp[(3) - (6)].stringVal));

                                                                        if (t_glob == NULL)
                                                                        {
                                                                            insert((yyvsp[(3) - (6)].stringVal), strlen((yyvsp[(3) - (6)].stringVal)), INT_TYPE, linenum, func);
                                                                            fprintf(javaa, "field static int %s\n\n", (yyvsp[(3) - (6)].stringVal));
                                                                        }
                                                                        else if (t_cur == NULL)
                                                                        {
                                                                            insert((yyvsp[(3) - (6)].stringVal), strlen((yyvsp[(3) - (6)].stringVal)), INT_TYPE, linenum, func);
                                                                            list_t* t = lookup((yyvsp[(3) - (6)].stringVal));
                                                                            t->counter = counter;
                                                                            counter++;
                                                                        }
                                                                        else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                        ;}
    break;

  case 22:
#line 215 "parser.y"
    {
                                                                        list_t* t_glob = lookup_scope((yyvsp[(3) - (6)].stringVal), 0);
                                                                        list_t* t_cur = lookup((yyvsp[(3) - (6)].stringVal));

                                                                        if (t_glob == NULL)
                                                                        {
                                                                            insert((yyvsp[(3) - (6)].stringVal), strlen((yyvsp[(3) - (6)].stringVal)), INT_TYPE, linenum, func);
                                                                            list_t* t = lookup((yyvsp[(3) - (6)].stringVal));
                                                                            t->st_ival = stoi((yyvsp[(5) - (6)].stringVal));
                                                                            t->st_sval = strdup((yyvsp[(5) - (6)].stringVal));
                                                                            fprintf(javaa, "field static int %s = %s\n\n", (yyvsp[(3) - (6)].stringVal), (yyvsp[(5) - (6)].stringVal));
                                                                        }
                                                                        else if (t_cur == NULL)
                                                                        {
                                                                            insert((yyvsp[(3) - (6)].stringVal), strlen((yyvsp[(3) - (6)].stringVal)), INT_TYPE, linenum, func);
                                                                            list_t* t = lookup((yyvsp[(3) - (6)].stringVal));
                                                                            t->counter = counter;
                                                                            t->st_ival = stoi((yyvsp[(5) - (6)].stringVal));
                                                                            t->st_sval = strdup((yyvsp[(5) - (6)].stringVal));
                                                                            counter++;
                                                                            List("sipush ");
                                                                            
                                                                            List((yyvsp[(5) - (6)].stringVal));
                                                                            
                                                                            List("\n");
                                                                            List("istore_");
                                                                            
                                                                            char n[STRSIZE];
                                                                            sprintf(n, "%d", t->counter);
                                                                            List(n);
                                                                            
                                                                            List("\n\n");
                                                                        }
                                                                        else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                        ;}
    break;

  case 23:
#line 250 "parser.y"
    {
                                                                                list_t* t_glob = lookup_scope((yyvsp[(3) - (8)].stringVal), 0);
                                                                                list_t* t_cur = lookup((yyvsp[(3) - (8)].stringVal));

                                                                                if (t_glob == NULL)
                                                                                {
                                                                                    insert((yyvsp[(3) - (8)].stringVal), strlen((yyvsp[(3) - (8)].stringVal)), INT_TYPE, linenum, func);
                                                                                    fprintf(javaa, "field static int %s = %s\n\n", (yyvsp[(3) - (8)].stringVal), (yyvsp[(7) - (8)].stringVal));
                                                                                }
                                                                                else if (t_cur == NULL)
                                                                                {
                                                                                    insert((yyvsp[(3) - (8)].stringVal), strlen((yyvsp[(3) - (8)].stringVal)), INT_TYPE, linenum, func);
                                                                                    list_t* t = lookup((yyvsp[(3) - (8)].stringVal));
                                                                                    t->counter = counter;
                                                                                    t->st_ival = stoi((yyvsp[(7) - (8)].stringVal));
                                                                                    t->st_sval = strdup((yyvsp[(7) - (8)].stringVal));
                                                                                    counter++;
                                                                                    List("sipush ");
                                                                                    
                                                                                    List((yyvsp[(7) - (8)].stringVal));
                                                                                    
                                                                                    List("\n");
                                                                                    List("istore_");

                                                                                    char n[STRSIZE];
                                                                                    sprintf(n, "%d", t->counter);
                                                                                    List(n);

                                                                                    List("\n\n");
                                                                                }
                                                                                else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                                ;}
    break;

  case 24:
#line 284 "parser.y"
    {
                                        incr_scope();
                                        ;}
    break;

  case 31:
#line 299 "parser.y"
    {
                                                                    func = strdup((yyvsp[(2) - (5)].stringVal));
                                                                    list_t* t_glob = lookup_scope((yyvsp[(2) - (5)].stringVal), 0);

                                                                    if (t_glob == NULL)
                                                                    {
                                                                        insert((yyvsp[(2) - (5)].stringVal), strlen((yyvsp[(2) - (5)].stringVal)), FUNCTION_TYPE, linenum, func);
                                                                        list_t* t = lookup((yyvsp[(2) - (5)].stringVal));
                                                                        t->inf_type = UNDEF;
                                                                        t->parameters = NULL;
                                                                        t->num_of_pars = 0;

                                                                        if (strcmp((yyvsp[(2) - (5)].stringVal), "main") == 0)
                                                                            fprintf(javaa, "method public static void main(java.lang.String[])\n");
                                                                        else
                                                                            fprintf(javaa, "method public static void %s()\n", (yyvsp[(2) - (5)].stringVal));
                                                                        
                                                                        fprintf(javaa, "max_stack 15\n");
                                                                        fprintf(javaa, "max_locals 15\n");
                                                                        fprintf(javaa, "{\n\n");
                                                                        fprintf(javaa, "%s", buffer);
                                                                        buffer = malloc(sizeof(char) * 1024);
                                                                        buffer = strdup("");
                                                                        fprintf(javaa, "}\n");
                                                                    }
                                                                    else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                    ;}
    break;

  case 32:
#line 326 "parser.y"
    {
                                                                    func = strdup((yyvsp[(2) - (6)].stringVal));
                                                                    list_t* t_glob = lookup_scope((yyvsp[(2) - (6)].stringVal), 0);

                                                                    if (t_glob == NULL)
                                                                    {
                                                                        insert((yyvsp[(2) - (6)].stringVal), strlen((yyvsp[(2) - (6)].stringVal)), FUNCTION_TYPE, linenum, func);
                                                                        list_t* t = lookup((yyvsp[(2) - (6)].stringVal));
                                                                        t->inf_type = UNDEF;
                                                                        t->parameters = (yyvsp[(4) - (6)].parptr);
                                                                        t->num_of_pars = 0;

                                                                        Param *p = (yyvsp[(4) - (6)].parptr);
                                                                        while (p != NULL)
                                                                        {
                                                                            t->num_of_pars++;
                                                                            p = p->next;
                                                                        }
                                                                        printf("Num of pars is %d\n", t->num_of_pars);

                                                                        fprintf(javaa, "method public static void %s(", (yyvsp[(2) - (6)].stringVal));
                                                                        for (int i = 0; i < t->num_of_pars - 1; i++)
                                                                        {
                                                                            fprintf(javaa, "int, ");
                                                                        }
                                                                        fprintf(javaa, "int)\n");
                                                                        fprintf(javaa, "max_stack 15\n");
                                                                        fprintf(javaa, "max_locals 15\n");
                                                                        fprintf(javaa, "{\n\n");
                                                                        fprintf(javaa, "%s", buffer);
                                                                        buffer = malloc(sizeof(char) * 1024);
                                                                        buffer = strdup("");
                                                                        fprintf(javaa, "}\n");
                                                                    }
                                                                    else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                    ;}
    break;

  case 33:
#line 362 "parser.y"
    {
                                                                    func = strdup((yyvsp[(2) - (7)].stringVal));
                                                                    list_t* t_glob = lookup_scope((yyvsp[(2) - (7)].stringVal), 0);

                                                                    if (t_glob == NULL)
                                                                    {
                                                                        insert((yyvsp[(2) - (7)].stringVal), strlen((yyvsp[(2) - (7)].stringVal)), FUNCTION_TYPE, linenum, func);
                                                                        list_t* t = lookup((yyvsp[(2) - (7)].stringVal));
                                                                        t->inf_type = INT_TYPE;
                                                                        t->parameters = NULL;
                                                                        t->num_of_pars = 0;

                                                                        fprintf(javaa, "method public static int %s()\n", (yyvsp[(2) - (7)].stringVal));
                                                                        fprintf(javaa, "max_stack 15\n");
                                                                        fprintf(javaa, "max_locals 15\n");
                                                                        fprintf(javaa, "{\n\n");
                                                                        fprintf(javaa, "%s", buffer);
                                                                        buffer = malloc(sizeof(char) * 1024);
                                                                        buffer = strdup("");
                                                                        fprintf(javaa, "}\n");
                                                                    }
                                                                    else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                    ;}
    break;

  case 34:
#line 385 "parser.y"
    {
                                                                            func = strdup((yyvsp[(2) - (8)].stringVal));
                                                                            list_t* t_glob = lookup_scope((yyvsp[(2) - (8)].stringVal), 0);

                                                                            if (t_glob == NULL)
                                                                            {
                                                                                insert((yyvsp[(2) - (8)].stringVal), strlen((yyvsp[(2) - (8)].stringVal)), FUNCTION_TYPE, linenum, func);
                                                                                list_t* t = lookup((yyvsp[(2) - (8)].stringVal));
                                                                                t->inf_type = INT_TYPE;
                                                                                t->parameters = (yyvsp[(4) - (8)].parptr);
                                                                                t->num_of_pars = 0;

                                                                                Param *p = (yyvsp[(4) - (8)].parptr);
                                                                                while (p != NULL)
                                                                                {
                                                                                    t->num_of_pars++;
                                                                                    p = p->next;
                                                                                }
                                                                                printf("Num of pars is %d\n", t->num_of_pars);

                                                                                fprintf(javaa, "method public static int %s(", (yyvsp[(2) - (8)].stringVal));
                                                                                for(int i = 0; i < t->num_of_pars - 1; i++)
                                                                                {
                                                                                    fprintf(javaa, "int, ");
                                                                                }
                                                                                fprintf(javaa, "int)\n");
                                                                                fprintf(javaa, "max_stack 15\n");
                                                                                fprintf(javaa, "max_locals 15\n");
                                                                                fprintf(javaa, "{\n\n");
                                                                                fprintf(javaa, "%s", buffer);
                                                                                buffer = malloc(sizeof(char) * 1024);
                                                                                buffer = strdup("");
                                                                                fprintf(javaa, "}\n");
                                                                            }
                                                                            else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                            ;}
    break;

  case 35:
#line 423 "parser.y"
    {
                                                                            (yyvsp[(1) - (1)].parptr)->next = NULL;
                                                                            (yyval.parptr) = (yyvsp[(1) - (1)].parptr);
                                                                        ;}
    break;

  case 36:
#line 427 "parser.y"
    {
                                                                            (yyvsp[(1) - (3)].parptr)->next = (yyvsp[(3) - (3)].parptr);
                                                                            (yyval.parptr) = (yyvsp[(1) - (3)].parptr);
                                                                        ;}
    break;

  case 37:
#line 433 "parser.y"
    {
                                                                        list_t* t = lookup((yyvsp[(1) - (3)].stringVal));
                                                                        Param* p = malloc(sizeof(Param));
                                                         
                                                                        if (t == NULL)
                                                                        {
                                                                            insert((yyvsp[(1) - (3)].stringVal), strlen((yyvsp[(1) - (3)].stringVal)), INT_TYPE, linenum, func);
                                                                            p->par_type = INT_TYPE;
                                                                            p->param_name = strdup((yyvsp[(1) - (3)].stringVal));
                                                                            p->ival = 0; // initialize
                                                                            p->sval = strdup(""); // initialize
                                                                            p->passing = BY_VALUE;
                                                                            p->next = NULL;
                                                                            p->counter = counter++;
                                                                            (yyval.parptr) = p;
                                                                        }
                                                                        else if (t != NULL && strcmp(t->func, PROGRAM) == 0)
                                                                        {
                                                                            p->par_type = INT_TYPE;
                                                                            p->param_name = strdup((yyvsp[(1) - (3)].stringVal));
                                                                            p->ival = 0; // initialize
                                                                            p->sval = strdup(""); // initialize
                                                                            p->passing = BY_VALUE;
                                                                            p->next = NULL;
                                                                            p->counter = counter++;
                                                                            (yyval.parptr) = p;
                                                                        }
                                                                        else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                        ;}
    break;

  case 40:
#line 468 "parser.y"
    {
                                                                    list_t* t_glob = lookup_scope((yyvsp[(1) - (4)].stringVal), 0);
                                                                    list_t* t_cur = lookup((yyvsp[(1) - (4)].stringVal));
                                                                    if (t_cur != NULL && (t_cur->st_type == INT_TYPE || t_cur->st_type == UNDEF))
                                                                    {
                                                                        t_cur->st_type = INT_TYPE;
                                                                        t_cur->st_ival = stoi((yyvsp[(3) - (4)].stringVal));
                                                                        t_cur->st_sval = strdup((yyvsp[(3) - (4)].stringVal));
                                                                    }
                                                                    else if (t_cur != NULL && (t_cur->st_type != INT_TYPE || t_cur->st_type != UNDEF))
                                                                    {
                                                                        Trace("line %d: The type does not match.\n", linenum);
                                                                    }
                                                                    else if (t_cur == NULL && t_glob != NULL && (t_glob->st_type == INT_TYPE || t_glob->st_type == UNDEF))
                                                                    {
                                                                        t_glob->st_type = INT_TYPE;
                                                                        t_glob->st_ival = stoi((yyvsp[(3) - (4)].stringVal));
                                                                        t_glob->st_sval = strdup((yyvsp[(3) - (4)].stringVal));
                                                                    }
                                                                    else if (t_cur == NULL && t_glob != NULL && (t_glob->st_type != INT_TYPE || t_glob->st_type != UNDEF))
                                                                    {
                                                                        Trace("line %d: The type does not match.\n", linenum);
                                                                    }
                                                                    else Trace("line %d: Redeclaration of identifier.\n", linenum);
                                                                    ;}
    break;

  case 41:
#line 493 "parser.y"
    {
                                                List("getstatic java.io.PrintStream java.lang.System.out\n");
                                                List("ldc "); List((yyvsp[(2) - (3)].stringVal)); List("\n");
                                                List("invokevirtual void java.io.PrintStream.print(int)\n\n");
                                                ;}
    break;

  case 42:
#line 498 "parser.y"
    {
                                                List("getstatic java.io.PrintStream java.lang.System.out\n");
                                                List("ldc "); List((yyvsp[(2) - (3)].stringVal)); List("\n");
                                                List("invokevirtual void java.io.PrintStream.print(int)\n\n");
                                                ;}
    break;

  case 43:
#line 503 "parser.y"
    {
                                                List("getstatic java.io.PrintStream java.lang.System.out\n");
                                                List("ldc "); List((yyvsp[(2) - (3)].stringVal)); List("\n");
                                                List("invokevirtual void java.io.PrintStream.println(int)\n\n");
                                                ;}
    break;

  case 44:
#line 508 "parser.y"
    {
                                                List("getstatic java.io.PrintStream java.lang.System.out\n");
                                                List("ldc "); List((yyvsp[(2) - (3)].stringVal)); List("\n");
                                                List("invokevirtual void java.io.PrintStream.println(int)\n\n");
                                                ;}
    break;

  case 45:
#line 513 "parser.y"
    {
                                                List("  return\n\n");
                                                ;}
    break;

  case 46:
#line 516 "parser.y"
    {
                                                List("  ireturn\n\n");
                                                ;}
    break;

  case 52:
#line 530 "parser.y"
    {
                                                        int i = stoi((yyvsp[(1) - (1)].stringVal));
                                                        if (i)
                                                        {
                                                            (yyval.boolVal) = 1;
                                                        }
                                                        else
                                                        {
                                                            (yyval.boolVal) = 0;
                                                        }
                                                        ;}
    break;

  case 53:
#line 541 "parser.y"
    {
                                                        for (int i = 0; i < STRSIZE; i++)
                                                        {
                                                            if ((yyvsp[(1) - (1)].stringVal)[i] == '\0')
                                                            {
                                                                (yyval.boolVal) = 0;
                                                                break;
                                                            }
                                                            if ((yyvsp[(1) - (1)].stringVal)[i])
                                                            {
                                                                (yyval.boolVal) = 1;
                                                                break;
                                                            }
                                                        }
                                                        ;}
    break;

  case 54:
#line 556 "parser.y"
    {
                                                        for (int i = 0; i < STRSIZE; i++)
                                                        {
                                                            if ((yyvsp[(1) - (3)].stringVal)[i] == '\0' && (yyvsp[(3) - (3)].stringVal)[i] == '\0')
                                                            {
                                                                (yyval.boolVal) = 0;
                                                                break;
                                                            }
                                                            else if ((yyvsp[(1) - (3)].stringVal)[i] == '\0' && (yyvsp[(3) - (3)].stringVal)[i] != '\0')
                                                            {
                                                                (yyval.boolVal) = 1;
                                                                break;
                                                            }
                                                            else if ((yyvsp[(1) - (3)].stringVal)[i] != '\0' && (yyvsp[(3) - (3)].stringVal)[i] == '\0')
                                                            {
                                                                (yyval.boolVal) = 0;
                                                                break;
                                                            }
                                                            else if ((yyvsp[(1) - (3)].stringVal)[i] < (yyvsp[(3) - (3)].stringVal)[i])
                                                            {
                                                                (yyval.boolVal) = 1;
                                                                break;
                                                            }
                                                            else if ((yyvsp[(1) - (3)].stringVal)[i] > (yyvsp[(3) - (3)].stringVal)[i])
                                                            {
                                                                (yyval.boolVal) = 0;
                                                                break;
                                                            }
                                                        }
                                                        ;}
    break;

  case 55:
#line 586 "parser.y"
    {
                                                        for (int i = 0; i < STRSIZE; i++)
                                                        {
                                                            if ((yyvsp[(1) - (3)].stringVal)[i] == '0' && (yyvsp[(3) - (3)].stringVal)[i] == '0')
                                                            {
                                                                (yyval.boolVal) = 1;
                                                            }
                                                            else if ((yyvsp[(1) - (3)].stringVal)[i] == '\0' && (yyvsp[(3) - (3)].stringVal)[i] != '\0')
                                                            {
                                                                (yyval.boolVal) = 1;
                                                                break;
                                                            }
                                                            else if ((yyvsp[(1) - (3)].stringVal)[i] != '\0' && (yyvsp[(3) - (3)].stringVal)[i] == '\0')
                                                            {
                                                                (yyval.boolVal) = 0;
                                                                break;
                                                            }
                                                            else if ((yyvsp[(1) - (3)].stringVal)[i] < (yyvsp[(3) - (3)].stringVal)[i])
                                                            {
                                                                (yyval.boolVal) = 1;
                                                                break;
                                                            }
                                                            else if ((yyvsp[(1) - (3)].stringVal)[i] > (yyvsp[(3) - (3)].stringVal)[i])
                                                            {
                                                                (yyval.boolVal) = 0;
                                                                break;
                                                            }
                                                            else if ((yyvsp[(1) - (3)].stringVal)[i] == (yyvsp[(3) - (3)].stringVal)[i])
                                                            {
                                                                (yyval.boolVal) = 1;
                                                                break;
                                                            }
                                                        }
                                                        ;}
    break;

  case 56:
#line 620 "parser.y"
    {
                                                            (yyval.boolVal) = !strcmp((yyvsp[(1) - (3)].stringVal), (yyvsp[(3) - (3)].stringVal));
                                                        ;}
    break;

  case 57:
#line 623 "parser.y"
    {
                                                        for (int i = 0; i < STRSIZE; i++)
                                                        {
                                                            if (!strcmp((yyvsp[(1) - (3)].stringVal), (yyvsp[(3) - (3)].stringVal)))
                                                            {
                                                                (yyval.boolVal) = 1;
                                                                break;
                                                            }
                                                            else if ((yyvsp[(1) - (3)].stringVal)[i] == '\0' && (yyvsp[(3) - (3)].stringVal)[i] != '\0')
                                                            {
                                                                (yyval.boolVal) = 0;
                                                                break;
                                                            }
                                                            else if ((yyvsp[(1) - (3)].stringVal)[i] != '\0' && (yyvsp[(3) - (3)].stringVal)[i] == '\0')
                                                            {
                                                                (yyval.boolVal) = 1;
                                                                break;
                                                            }
                                                            else if ((yyvsp[(1) - (3)].stringVal)[i] > (yyvsp[(3) - (3)].stringVal)[i])
                                                            {
                                                                (yyval.boolVal) = 1;
                                                                break;
                                                            }
                                                            else if ((yyvsp[(1) - (3)].stringVal)[i] < (yyvsp[(3) - (3)].stringVal)[i])
                                                            {
                                                                (yyval.boolVal) = 0;
                                                                break;
                                                            }
                                                        }
                                                        ;}
    break;

  case 58:
#line 653 "parser.y"
    {
                                                        for (int i = 0; i < STRSIZE; i++)
                                                        {
                                                            if (!strcmp((yyvsp[(1) - (3)].stringVal), (yyvsp[(3) - (3)].stringVal)))
                                                            {
                                                                (yyval.boolVal) = 0;
                                                                break;
                                                            }
                                                            else if ((yyvsp[(1) - (3)].stringVal)[i] == '\0' && (yyvsp[(3) - (3)].stringVal)[i] != '\0')
                                                            {
                                                                (yyval.boolVal) = 0;
                                                                break;
                                                            }
                                                            else if ((yyvsp[(1) - (3)].stringVal)[i] != '\0' && (yyvsp[(3) - (3)].stringVal)[i] == '\0')
                                                            {
                                                                (yyval.boolVal) = 1;
                                                                break;
                                                            }
                                                            else if ((yyvsp[(1) - (3)].stringVal)[i] > (yyvsp[(3) - (3)].stringVal)[i])
                                                            {
                                                                (yyval.boolVal) = 1;
                                                                break;
                                                            }
                                                            else if ((yyvsp[(1) - (3)].stringVal)[i] < (yyvsp[(3) - (3)].stringVal)[i])
                                                            {
                                                                (yyval.boolVal) = 0;
                                                                break;
                                                            }
                                                        }
                                                        ;}
    break;

  case 59:
#line 683 "parser.y"
    {
                                                            (yyval.boolVal) = strcmp((yyvsp[(1) - (3)].stringVal), (yyvsp[(3) - (3)].stringVal));
                                                        ;}
    break;

  case 60:
#line 686 "parser.y"
    {
                                                            (yyval.boolVal) = !(yyvsp[(2) - (2)].stringVal);
                                                        ;}
    break;

  case 61:
#line 689 "parser.y"
    {
                                                            (yyval.boolVal) = (yyvsp[(1) - (3)].stringVal) && (yyvsp[(3) - (3)].stringVal) ? 1 : 0;
                                                        ;}
    break;

  case 62:
#line 692 "parser.y"
    {
                                                            (yyval.boolVal) = (yyvsp[(1) - (3)].stringVal) || (yyvsp[(3) - (3)].stringVal) ? 1 : 0;
                                                        ;}
    break;

  case 63:
#line 695 "parser.y"
    {
                                                            (yyval.boolVal) = (yyvsp[(1) - (1)].boolVal);
                                                        ;}
    break;

  case 64:
#line 698 "parser.y"
    {
                                                            (yyval.boolVal) = (yyvsp[(1) - (1)].boolVal);
                                                        ;}
    break;

  case 65:
#line 703 "parser.y"
    {
                                                                (yyvsp[(1) - (1)].parptr)->next = NULL;
                                                                (yyval.parptr) = (yyvsp[(1) - (1)].parptr);
                                                        ;}
    break;

  case 66:
#line 707 "parser.y"
    {
                                                                                (yyvsp[(1) - (3)].parptr)->next = (yyvsp[(3) - (3)].parptr);
                                                                                (yyval.parptr) = (yyvsp[(1) - (3)].parptr);
                                                                            ;}
    break;

  case 67:
#line 713 "parser.y"
    {
                                                                Param *t = malloc(sizeof(Param));
                                                                list_t* t_cur = lookup((yyvsp[(1) - (1)].stringVal));
                                                                list_t* t_glob = lookup_scope((yyvsp[(1) - (1)].stringVal), 0);

                                                                if (t_glob != NULL)
                                                                {
                                                                    if (t_glob->st_type == INT_TYPE)
                                                                    {
                                                                        t->par_type = INT_TYPE;
                                                                        t->param_name = strdup((yyvsp[(1) - (1)].stringVal));
                                                                        t->ival = t_glob->st_ival;
                                                                        t->sval = strdup(t_glob->st_sval);
                                                                    }
                                                                }
                                                                else if (t_cur != NULL)
                                                                {
                                                                    if (t_cur->st_type == INT_TYPE)
                                                                    {
                                                                        t->par_type = INT_TYPE;
                                                                        t->param_name = strdup((yyvsp[(1) - (1)].stringVal));
                                                                        t->ival = t_cur->st_ival;
                                                                        t->sval = strdup(t_cur->st_sval);
                                                                    }
                                                                }
                                                                else Trace("line %d: The type dose not match.\n", linenum);

                                                                t->next = NULL;
                                                                (yyval.parptr) = t;
                                                            ;}
    break;

  case 68:
#line 743 "parser.y"
    {
                                                                Param *t = malloc(sizeof(Param));
                                                                t->ival = stoi((yyvsp[(1) - (1)].stringVal));
                                                                t->sval = strdup((yyvsp[(1) - (1)].stringVal));
                                                                t->par_type = INT_TYPE;
                                                                t->next = NULL;
                                                                (yyval.parptr) = t;
                                                            ;}
    break;

  case 69:
#line 753 "parser.y"
    {
                                                list_t* t = lookup_scope((yyvsp[(1) - (3)].stringVal), 0);
                                                (yyval.symptr) = t;
                                                if (t->st_type == FUNCTION_TYPE)
                                                {
                                                    switch(t->inf_type)
                                                    {
                                                        case INT_TYPE:
                                                        (yyval.symptr)->inf_type = INT_TYPE;
                                                        (yyval.symptr)->st_ival = 1; // temp
                                                        (yyval.symptr)->st_sval = strdup("1");
                                                        break;
                                                        default:
                                                        (yyval.symptr)->inf_type = UNDEF;
                                                    }
                                                }
                                                else
                                                {
                                                    Trace("line %d: The type does not match.\n", linenum);
                                                }
                                                ;}
    break;

  case 70:
#line 774 "parser.y"
    {
                                                                    list_t* t = lookup_scope((yyvsp[(1) - (4)].stringVal), 0);
                                                                    (yyval.symptr) = t;
                                                                    if (t->st_type == FUNCTION_TYPE)
                                                                    {
                                                                        switch(t->inf_type)
                                                                        {
                                                                            case INT_TYPE:
                                                                            (yyval.symptr)->inf_type = INT_TYPE;
                                                                            (yyval.symptr)->st_ival = 1; // temp
                                                                            break;
                                                                            case LOGIC_TYPE:
                                                                            (yyval.symptr)->inf_type = LOGIC_TYPE;
                                                                            (yyval.symptr)->st_bval = false; // temp
                                                                            default:
                                                                            (yyval.symptr)->inf_type = UNDEF;
                                                                        }

                                                                        Param *t1 = t->parameters;
                                                                        Param *t2 = (yyvsp[(3) - (4)].parptr);
                                                                        int count = 0;

                                                                        while (t1 != NULL)
                                                                        {
                                                                            if (t2 == NULL)
                                                                            {
                                                                                Trace("line %d: The numbers of parameters are different.\n", linenum);
                                                                                break;
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
                                                                    }
                                                                    else
                                                                    {
                                                                        Trace("line %d: The type does not match.\n", linenum);
                                                                    }
                                                                    ;}
    break;

  case 71:
#line 828 "parser.y"
    {
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi((yyvsp[(1) - (3)].stringVal)); j = stoi((yyvsp[(3) - (3)].stringVal));
                                                        sum = i + j;
                                                        (yyval.stringVal) = strdup(itos(sum, b));
                                                        ;}
    break;

  case 72:
#line 835 "parser.y"
    {
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi((yyvsp[(1) - (3)].stringVal)); j = stoi((yyvsp[(3) - (3)].stringVal));
                                                        sum = i - j;
                                                        (yyval.stringVal) = strdup(itos(sum, b));
                                                        ;}
    break;

  case 73:
#line 842 "parser.y"
    {
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi((yyvsp[(1) - (3)].stringVal)); j = stoi((yyvsp[(3) - (3)].stringVal));
                                                        sum = i * j;
                                                        (yyval.stringVal) = strdup(itos(sum, b));
                                                        ;}
    break;

  case 74:
#line 849 "parser.y"
    {
                                                        int i, j, sum;
                                                        char b[STRSIZE];
                                                        i = stoi((yyvsp[(1) - (3)].stringVal)); j = stoi((yyvsp[(3) - (3)].stringVal));
                                                        if (j == 0) Trace("line %d: Divided by zero.\n", linenum);
                                                        else
                                                        {
                                                            sum = i / j;
                                                            (yyval.stringVal) = strdup(itos(sum, b));
                                                        }
                                                        ;}
    break;

  case 75:
#line 860 "parser.y"
    {
                                                        int i;
                                                        char b[STRSIZE];
                                                        i = stoi((yyvsp[(2) - (2)].stringVal));
                                                        i = -i;
                                                        (yyval.stringVal) = strdup(itos(i, b));
                                                        ;}
    break;

  case 76:
#line 867 "parser.y"
    {
                                                        (yyval.stringVal) = strdup((yyvsp[(2) - (3)].stringVal));
                                                        ;}
    break;

  case 77:
#line 870 "parser.y"
    {
                                                        int i, j;
                                                        i = stoi((yyvsp[(1) - (3)].stringVal)); j = stoi((yyvsp[(3) - (3)].stringVal));
                                                        if (i < j)
                                                        {
                                                            (yyval.stringVal) = strdup("1");
                                                        }
                                                        else
                                                        {
                                                            (yyval.stringVal) = strdup("0");                                                        
                                                        }
                                                        ;}
    break;

  case 78:
#line 882 "parser.y"
    {
                                                int i, j;
                                                i = stoi((yyvsp[(1) - (3)].stringVal)); j = stoi((yyvsp[(3) - (3)].stringVal));
                                                if (i <= j)
                                                {
                                                    (yyval.stringVal) = strdup("1");
                                                }
                                                else
                                                {
                                                    (yyval.stringVal) = strdup("0");                                                        
                                                }
                                                ;}
    break;

  case 79:
#line 894 "parser.y"
    {
                                                int i, j;
                                                i = stoi((yyvsp[(1) - (3)].stringVal)); j = stoi((yyvsp[(3) - (3)].stringVal));
                                                if (i == j)
                                                {
                                                    (yyval.stringVal) = strdup("1");
                                                }
                                                else
                                                {
                                                    (yyval.stringVal) = strdup("0");                                                        
                                                }
                                                ;}
    break;

  case 80:
#line 906 "parser.y"
    {
                                                int i, j;
                                                i = stoi((yyvsp[(1) - (3)].stringVal)); j = stoi((yyvsp[(3) - (3)].stringVal));
                                                if (i >= j)
                                                {
                                                    (yyval.stringVal) = strdup("1");
                                                }
                                                else
                                                {
                                                    (yyval.stringVal) = strdup("0");                                                        
                                                }
                                                ;}
    break;

  case 81:
#line 918 "parser.y"
    {
                                                    int i, j;
                                                    i = stoi((yyvsp[(1) - (3)].stringVal)); j = stoi((yyvsp[(3) - (3)].stringVal));
                                                    if (i > j)
                                                    {
                                                        (yyval.stringVal) = strdup("1");
                                                    }
                                                    else
                                                    {
                                                        (yyval.stringVal) = strdup("0");                                                        
                                                    }
                                                    ;}
    break;

  case 82:
#line 930 "parser.y"
    {
                                                int i, j;
                                                i = stoi((yyvsp[(1) - (3)].stringVal)); j = stoi((yyvsp[(3) - (3)].stringVal));
                                                if (i != j)
                                                {
                                                    (yyval.stringVal) = strdup("1");
                                                }
                                                else
                                                {
                                                    (yyval.stringVal) = strdup("0");                                                        
                                                }
                                                ;}
    break;

  case 83:
#line 942 "parser.y"
    {
                                                int i;
                                                i = stoi((yyvsp[(2) - (2)].stringVal));
                                                if (!i)
                                                {
                                                    (yyval.stringVal) = strdup("1");
                                                }
                                                else
                                                {
                                                    (yyval.stringVal) = strdup("0");                                                        
                                                }
                                                ;}
    break;

  case 84:
#line 954 "parser.y"
    {
                                                int i, j;
                                                i = stoi((yyvsp[(1) - (3)].stringVal)); j = stoi((yyvsp[(3) - (3)].stringVal));
                                                if (i && j)
                                                {
                                                    (yyval.stringVal) = strdup("1");
                                                }
                                                else
                                                {
                                                    (yyval.stringVal) = strdup("0");                                                        
                                                }
                                                ;}
    break;

  case 85:
#line 966 "parser.y"
    {
                                                int i, j;
                                                i = stoi((yyvsp[(1) - (3)].stringVal)); j = stoi((yyvsp[(3) - (3)].stringVal));
                                                if (i || j)
                                                {
                                                    (yyval.stringVal) = strdup("1");
                                                }
                                                else
                                                {
                                                    (yyval.stringVal) = strdup("0");                                                        
                                                }
                                                ;}
    break;

  case 86:
#line 978 "parser.y"
    {
                                                    (yyval.stringVal) = strdup((yyvsp[(1) - (1)].stringVal));
                                                ;}
    break;

  case 87:
#line 981 "parser.y"
    {
                                                list_t* t = lookup((yyvsp[(1) - (1)].stringVal));
                                                if (t->st_type == INT_TYPE || t->st_type == CONST_INT_TYPE)
                                                {
                                                    char b[STRSIZE];
                                                    (yyval.stringVal) = strdup(itos(t->st_ival, b));
                                                }
                                                else
                                                {
                                                    Trace("line %d: The type does not match.\n", linenum);
                                                }
                                                ;}
    break;

  case 88:
#line 993 "parser.y"
    {
                                                if ((yyvsp[(1) - (1)].symptr)->st_type == FUNCTION_TYPE && (yyvsp[(1) - (1)].symptr)->inf_type == INT_TYPE)
                                                {
                                                    // throw a random num
                                                    (yyval.stringVal) = strdup("1");
                                                }
                                                else
                                                {
                                                    Trace("line %d: The type does not match.\n", linenum);
                                                }
                                                ;}
    break;

  case 89:
#line 1006 "parser.y"
    {
                                                    (yyval.stringVal) = strdup((yyvsp[(2) - (3)].stringVal));
                                                ;}
    break;

  case 90:
#line 1009 "parser.y"
    {
                                                    (yyval.stringVal) = strdup((yyvsp[(1) - (1)].stringVal));
                                                ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2784 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1013 "parser.y"

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
    /* initialize the buffer */
    buffer = malloc(sizeof(char) * 1024);
    buffer = strdup("");
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
    fprintf(javaa, "class %s\n{\n\n", file);   /* make the file name as the class name */
    /*-----------------------------------------------------------------------------------*/

    int flag;
    flag = yyparse();

    /* perform parsing */
    if (flag == 1)                      /* parsing */
        yyerror("Parsing error !");     /* syntax error */

    fclose(yyin);                       /* close input file */
    fprintf(javaa, "}\n");              /* close the class */
    free(buffer);
    fclose(javaa);                      /* close the javaa */

    /* output symbol table */
    printf("\nSymbol table:\n");
    yyout = fopen("dump.out", "w");
    dump(yyout);
    fclose(yyout);

    return 0;
}

