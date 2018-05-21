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
     LABEL = 258,
     IDENTIFIER = 259,
     INTCONSTANT = 260,
     LONGCONSTANT = 261,
     FLOATCONSTANT = 262,
     DOUBLECONSTANT = 263,
     CHARCONSTANT = 264,
     STRING_LITERAL = 265,
     CLASS = 266,
     EXTENDS = 267,
     ACCESS = 268,
     IMPLEMENTS = 269,
     FIELD = 270,
     METHOD = 271,
     MAX_STACK = 272,
     MAX_LOCALS = 273,
     CODE = 274,
     PUBLIC = 275,
     PRIVATE = 276,
     PROTECTED = 277,
     ABSTRACT = 278,
     FINAL = 279,
     INTERFACE = 280,
     STATIC = 281,
     NATIVE = 282,
     SYNCHRONIZED = 283,
     TRANSIENT = 284,
     VOLATILE = 285,
     BYTE = 286,
     CHAR = 287,
     DOUBLE = 288,
     FLOAT = 289,
     INT = 290,
     LONG = 291,
     SHORT = 292,
     BOOLEAN = 293,
     VOID = 294,
     DEFAULT = 295,
     TO = 296,
     EXCEPTIONS = 297,
     SOURCEFILE = 298,
     THROWS = 299,
     LINENUMBERTABLE = 300,
     LOCALVARIABLETABLE = 301,
     ACC_PUBLIC = 302,
     ACC_PRIVATE = 303,
     ACC_PROTECTED = 304,
     ACC_STATIC = 305,
     ACC_FINAL = 306,
     ACC_SYNCHRONIZED = 307,
     ACC_VOLATILE = 308,
     ACC_TRANSIENT = 309,
     ACC_NATIVE = 310,
     ACC_INTERFACE = 311,
     ACC_ABSTRACT = 312,
     AALOAD = 313,
     AASTORE = 314,
     ACONST_NULL = 315,
     ALOAD_0 = 316,
     ALOAD_1 = 317,
     ALOAD_2 = 318,
     ALOAD_3 = 319,
     ANEWARRAY = 320,
     ARETURN = 321,
     ARRAYLENGTH = 322,
     ASTORE_0 = 323,
     ASTORE_1 = 324,
     ASTORE_2 = 325,
     ASTORE_3 = 326,
     ATHROW = 327,
     BALOAD = 328,
     BASTORE = 329,
     BIPUSH = 330,
     CALOAD = 331,
     CASTORE = 332,
     CHECKCAST = 333,
     D2F = 334,
     D2I = 335,
     D2L = 336,
     DADD = 337,
     DALOAD = 338,
     DASTORE = 339,
     DCMPG = 340,
     DCMPL = 341,
     DCONST_0 = 342,
     DCONST_1 = 343,
     DDIV = 344,
     DLOAD_0 = 345,
     DLOAD_1 = 346,
     DLOAD_2 = 347,
     DLOAD_3 = 348,
     DMUL = 349,
     DNEG = 350,
     DREM = 351,
     DRETURN = 352,
     DSTORE_0 = 353,
     DSTORE_1 = 354,
     DSTORE_2 = 355,
     DSTORE_3 = 356,
     DSUB = 357,
     DUP = 358,
     DUP_X1 = 359,
     DUP_X2 = 360,
     DUP2 = 361,
     DUP2_X1 = 362,
     DUP2_X2 = 363,
     F2D = 364,
     F2I = 365,
     F2L = 366,
     FADD = 367,
     FALOAD = 368,
     FASTORE = 369,
     FCMPG = 370,
     FCMPL = 371,
     FCONST_0 = 372,
     FCONST_1 = 373,
     FCONST_2 = 374,
     FDIV = 375,
     FLOAD_0 = 376,
     FLOAD_1 = 377,
     FLOAD_2 = 378,
     FLOAD_3 = 379,
     FMUL = 380,
     FNEG = 381,
     FREM = 382,
     FRETURN = 383,
     FSTORE_0 = 384,
     FSTORE_1 = 385,
     FSTORE_2 = 386,
     FSTORE_3 = 387,
     FSUB = 388,
     GETFIELD = 389,
     GETSTATIC = 390,
     GOTO = 391,
     GOTO_W = 392,
     I2B = 393,
     I2C = 394,
     I2D = 395,
     I2F = 396,
     I2L = 397,
     I2S = 398,
     IADD = 399,
     IALOAD = 400,
     IAND = 401,
     IASTORE = 402,
     ICONST_0 = 403,
     ICONST_1 = 404,
     ICONST_2 = 405,
     ICONST_3 = 406,
     ICONST_4 = 407,
     ICONST_5 = 408,
     ICONST_M1 = 409,
     IDIV = 410,
     IF_ACMPEQ = 411,
     IF_ACMPNE = 412,
     IF_ICMPEQ = 413,
     IF_ICMPNE = 414,
     IF_ICMPLT = 415,
     IF_ICMPGE = 416,
     IF_ICMPGT = 417,
     IF_ICMPLE = 418,
     IFEQ = 419,
     IFNE = 420,
     IFLT = 421,
     IFGE = 422,
     IFGT = 423,
     IFLE = 424,
     IFNONNULL = 425,
     IFNULL = 426,
     ILOAD_0 = 427,
     ILOAD_1 = 428,
     ILOAD_2 = 429,
     ILOAD_3 = 430,
     IMUL = 431,
     INEG = 432,
     IOR = 433,
     IREM = 434,
     IRETURN = 435,
     ISHL = 436,
     ISHR = 437,
     ISTORE_0 = 438,
     ISTORE_1 = 439,
     ISTORE_2 = 440,
     ISTORE_3 = 441,
     ISUB = 442,
     IUSHR = 443,
     IXOR = 444,
     JSR = 445,
     JSR_W = 446,
     L2D = 447,
     L2F = 448,
     L2I = 449,
     LADD = 450,
     LALOAD = 451,
     LAND = 452,
     LASTORE = 453,
     LCMP = 454,
     LCONST_0 = 455,
     LCONST_1 = 456,
     LDIV = 457,
     LLOAD_0 = 458,
     LLOAD_1 = 459,
     LLOAD_2 = 460,
     LLOAD_3 = 461,
     LMUL = 462,
     LNEG = 463,
     LOR = 464,
     LREM = 465,
     LRETURN = 466,
     LSHL = 467,
     LSHR = 468,
     LSTORE_0 = 469,
     LSTORE_1 = 470,
     LSTORE_2 = 471,
     LSTORE_3 = 472,
     LSUB = 473,
     LUSHR = 474,
     LXOR = 475,
     MONITORENTER = 476,
     MONITOREXIT = 477,
     NOP = 478,
     POP = 479,
     POP2 = 480,
     RETURN = 481,
     SALOAD = 482,
     SASTORE = 483,
     SWAP = 484,
     IINC = 485,
     INSTANCEOF = 486,
     INVOKEINTERFACE = 487,
     INVOKENONVIRTUAL = 488,
     INVOKESTATIC = 489,
     INVOKEVIRTUAL = 490,
     LDC = 491,
     LDC_W = 492,
     LDC2_W = 493,
     MULTIANEWARRAY = 494,
     NEW = 495,
     NEWARRAY = 496,
     PUTFIELD = 497,
     PUTSTATIC = 498,
     SIPUSH = 499,
     ILOAD = 500,
     FLOAD = 501,
     ALOAD = 502,
     LLOAD = 503,
     DLOAD = 504,
     ISTORE = 505,
     FSTORE = 506,
     ASTORE = 507,
     LSTORE = 508,
     DSTORE = 509,
     RET = 510,
     WIDE = 511,
     LOAD = 512,
     STORE = 513,
     LOOKUPSWITCH = 514,
     TABLESWITCH = 515
   };
#endif
/* Tokens.  */
#define LABEL 258
#define IDENTIFIER 259
#define INTCONSTANT 260
#define LONGCONSTANT 261
#define FLOATCONSTANT 262
#define DOUBLECONSTANT 263
#define CHARCONSTANT 264
#define STRING_LITERAL 265
#define CLASS 266
#define EXTENDS 267
#define ACCESS 268
#define IMPLEMENTS 269
#define FIELD 270
#define METHOD 271
#define MAX_STACK 272
#define MAX_LOCALS 273
#define CODE 274
#define PUBLIC 275
#define PRIVATE 276
#define PROTECTED 277
#define ABSTRACT 278
#define FINAL 279
#define INTERFACE 280
#define STATIC 281
#define NATIVE 282
#define SYNCHRONIZED 283
#define TRANSIENT 284
#define VOLATILE 285
#define BYTE 286
#define CHAR 287
#define DOUBLE 288
#define FLOAT 289
#define INT 290
#define LONG 291
#define SHORT 292
#define BOOLEAN 293
#define VOID 294
#define DEFAULT 295
#define TO 296
#define EXCEPTIONS 297
#define SOURCEFILE 298
#define THROWS 299
#define LINENUMBERTABLE 300
#define LOCALVARIABLETABLE 301
#define ACC_PUBLIC 302
#define ACC_PRIVATE 303
#define ACC_PROTECTED 304
#define ACC_STATIC 305
#define ACC_FINAL 306
#define ACC_SYNCHRONIZED 307
#define ACC_VOLATILE 308
#define ACC_TRANSIENT 309
#define ACC_NATIVE 310
#define ACC_INTERFACE 311
#define ACC_ABSTRACT 312
#define AALOAD 313
#define AASTORE 314
#define ACONST_NULL 315
#define ALOAD_0 316
#define ALOAD_1 317
#define ALOAD_2 318
#define ALOAD_3 319
#define ANEWARRAY 320
#define ARETURN 321
#define ARRAYLENGTH 322
#define ASTORE_0 323
#define ASTORE_1 324
#define ASTORE_2 325
#define ASTORE_3 326
#define ATHROW 327
#define BALOAD 328
#define BASTORE 329
#define BIPUSH 330
#define CALOAD 331
#define CASTORE 332
#define CHECKCAST 333
#define D2F 334
#define D2I 335
#define D2L 336
#define DADD 337
#define DALOAD 338
#define DASTORE 339
#define DCMPG 340
#define DCMPL 341
#define DCONST_0 342
#define DCONST_1 343
#define DDIV 344
#define DLOAD_0 345
#define DLOAD_1 346
#define DLOAD_2 347
#define DLOAD_3 348
#define DMUL 349
#define DNEG 350
#define DREM 351
#define DRETURN 352
#define DSTORE_0 353
#define DSTORE_1 354
#define DSTORE_2 355
#define DSTORE_3 356
#define DSUB 357
#define DUP 358
#define DUP_X1 359
#define DUP_X2 360
#define DUP2 361
#define DUP2_X1 362
#define DUP2_X2 363
#define F2D 364
#define F2I 365
#define F2L 366
#define FADD 367
#define FALOAD 368
#define FASTORE 369
#define FCMPG 370
#define FCMPL 371
#define FCONST_0 372
#define FCONST_1 373
#define FCONST_2 374
#define FDIV 375
#define FLOAD_0 376
#define FLOAD_1 377
#define FLOAD_2 378
#define FLOAD_3 379
#define FMUL 380
#define FNEG 381
#define FREM 382
#define FRETURN 383
#define FSTORE_0 384
#define FSTORE_1 385
#define FSTORE_2 386
#define FSTORE_3 387
#define FSUB 388
#define GETFIELD 389
#define GETSTATIC 390
#define GOTO 391
#define GOTO_W 392
#define I2B 393
#define I2C 394
#define I2D 395
#define I2F 396
#define I2L 397
#define I2S 398
#define IADD 399
#define IALOAD 400
#define IAND 401
#define IASTORE 402
#define ICONST_0 403
#define ICONST_1 404
#define ICONST_2 405
#define ICONST_3 406
#define ICONST_4 407
#define ICONST_5 408
#define ICONST_M1 409
#define IDIV 410
#define IF_ACMPEQ 411
#define IF_ACMPNE 412
#define IF_ICMPEQ 413
#define IF_ICMPNE 414
#define IF_ICMPLT 415
#define IF_ICMPGE 416
#define IF_ICMPGT 417
#define IF_ICMPLE 418
#define IFEQ 419
#define IFNE 420
#define IFLT 421
#define IFGE 422
#define IFGT 423
#define IFLE 424
#define IFNONNULL 425
#define IFNULL 426
#define ILOAD_0 427
#define ILOAD_1 428
#define ILOAD_2 429
#define ILOAD_3 430
#define IMUL 431
#define INEG 432
#define IOR 433
#define IREM 434
#define IRETURN 435
#define ISHL 436
#define ISHR 437
#define ISTORE_0 438
#define ISTORE_1 439
#define ISTORE_2 440
#define ISTORE_3 441
#define ISUB 442
#define IUSHR 443
#define IXOR 444
#define JSR 445
#define JSR_W 446
#define L2D 447
#define L2F 448
#define L2I 449
#define LADD 450
#define LALOAD 451
#define LAND 452
#define LASTORE 453
#define LCMP 454
#define LCONST_0 455
#define LCONST_1 456
#define LDIV 457
#define LLOAD_0 458
#define LLOAD_1 459
#define LLOAD_2 460
#define LLOAD_3 461
#define LMUL 462
#define LNEG 463
#define LOR 464
#define LREM 465
#define LRETURN 466
#define LSHL 467
#define LSHR 468
#define LSTORE_0 469
#define LSTORE_1 470
#define LSTORE_2 471
#define LSTORE_3 472
#define LSUB 473
#define LUSHR 474
#define LXOR 475
#define MONITORENTER 476
#define MONITOREXIT 477
#define NOP 478
#define POP 479
#define POP2 480
#define RETURN 481
#define SALOAD 482
#define SASTORE 483
#define SWAP 484
#define IINC 485
#define INSTANCEOF 486
#define INVOKEINTERFACE 487
#define INVOKENONVIRTUAL 488
#define INVOKESTATIC 489
#define INVOKEVIRTUAL 490
#define LDC 491
#define LDC_W 492
#define LDC2_W 493
#define MULTIANEWARRAY 494
#define NEW 495
#define NEWARRAY 496
#define PUTFIELD 497
#define PUTSTATIC 498
#define SIPUSH 499
#define ILOAD 500
#define FLOAD 501
#define ALOAD 502
#define LLOAD 503
#define DLOAD 504
#define ISTORE 505
#define FSTORE 506
#define ASTORE 507
#define LSTORE 508
#define DSTORE 509
#define RET 510
#define WIDE 511
#define LOAD 512
#define STORE 513
#define LOOKUPSWITCH 514
#define TABLESWITCH 515




/* Copy the first part of user declarations.  */
#line 260 "javaa.y"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "utils.h"
#include "build.h"
#include "protos.h"
#include "listing.h"


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
#line 289 "javaa.y"
{
   Terminal        rk;
   Terminal        NT;
   Terminal        RK;
   Terminal        Rk;

   float           floatval;
   double          doubleval;
   char            charval;
   int             intval;
   long            longval;
   char           *string;

   BaseType        basetype;
   StorageClass    storageclass;
   TypeQualifier   typequalifier;
   ArgType	   argtype;
  
   lookupentry *   lookuplistptr;
   tableentry *    tablelistptr;

   struct {
	char* classname;
	char* fieldmethodname;
   }		classfieldmethodstruct;

   struct _declinfo {
      int   function;
      int   ptrcount;
      int   dimsize[7];
      int   numdims;
      char *name;
   }               declinfo;
   
   struct {
      TreeNode *formals;
      struct _declinfo D;
   }               funcstuff;

   struct {
      Type          T;
      StorageClass  C;
      TypeQualifier Q;
   } declspecs;

   struct {
      Type          T;
      StorageClass  C;
      TypeQualifier Q;
      TreeNode     *node;
   } declspecsnode;

   struct {
      Type          T;
      StorageClass  C;
      TypeQualifier Q;
      Symbol       *headsym;
      Symbol       *prevsym;
   } structdeclspecs;

   struct {
      Symbol   *headsym;
      Symbol   *prevsym;
   } headprevsym;

   struct {
      int       spec;
      int       val;
      char     *id;
   } idspecval;

   struct {
      Symbol   *sym;
      int       val;
   } symval;

   Type            typetype;

   Symbol         *sym;

   struct {
      TreeNode *decl;
      TreeNode *func;
   } declfunc;

   struct {
      TreeNode *decl;
      TreeNode *func;
      TreeNode *exprs;
      TreeNode *last;
   } declfuncexprs;

   struct {
      TreeNode *exprs;
      TreeNode *last;
   } exprslast;

   TreeNode       *node;
}
/* Line 193 of yacc.c.  */
#line 727 "javaa.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 389 "javaa.y"

   static void     CheckStructDcl(Type,int);
   static MimeType GenBlankMimeType();
   static Type     GenBlankType();
   static TreeNode *MakeBinOpSubTree(int, TreeNode *, TreeNode *);
   static TreeNode *MakeUnOpSubTree(int, TreeNode *);
   static TreeNode *MakeFuncSibs(TreeNode *, TreeNode *, TreeNode *,
              TreeNode *, TreeNode *);
   static TreeNode *GenEntryArgs(TreeNode *);


/* Line 216 of yacc.c.  */
#line 750 "javaa.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   850

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  271
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  346
/* YYNRULES -- Number of states.  */
#define YYNSTATES  434

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   515

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     265,   266,     2,     2,   267,     2,   263,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   270,     2,
       2,   264,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   268,     2,   269,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   261,     2,   262,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    12,    13,    25,    30,
      32,    33,    36,    37,    41,    43,    47,    49,    53,    55,
      57,    58,    60,    61,    63,    64,    66,    67,    69,    70,
      72,    73,    75,    76,    78,    79,    81,    82,    84,    87,
      89,    91,    92,    95,    96,    99,   101,   104,   105,   112,
     115,   118,   121,   124,   125,   130,   133,   134,   135,   136,
     157,   160,   161,   164,   166,   169,   170,   172,   174,   176,
     177,   181,   183,   185,   186,   190,   192,   194,   197,   200,
     202,   204,   206,   208,   210,   212,   214,   216,   218,   222,
     223,   229,   232,   234,   239,   241,   244,   245,   248,   250,
     252,   255,   257,   259,   262,   266,   273,   276,   279,   287,
     290,   293,   297,   304,   314,   318,   321,   323,   325,   327,
     329,   331,   333,   335,   337,   339,   341,   343,   345,   347,
     349,   351,   353,   355,   357,   359,   361,   363,   365,   367,
     369,   371,   373,   375,   377,   379,   381,   383,   385,   387,
     389,   391,   393,   395,   397,   399,   401,   403,   405,   407,
     409,   411,   413,   415,   417,   419,   421,   423,   425,   427,
     429,   431,   433,   435,   437,   439,   441,   443,   445,   447,
     449,   451,   453,   455,   457,   459,   461,   463,   465,   467,
     469,   471,   473,   475,   477,   479,   481,   483,   485,   487,
     489,   491,   493,   495,   497,   499,   501,   503,   505,   507,
     509,   511,   513,   515,   517,   519,   521,   523,   525,   527,
     529,   531,   533,   535,   537,   539,   541,   543,   545,   547,
     549,   551,   553,   555,   557,   559,   561,   563,   565,   567,
     569,   571,   573,   575,   577,   579,   581,   583,   585,   587,
     589,   591,   593,   595,   597,   599,   601,   603,   605,   607,
     609,   611,   613,   615,   617,   619,   621,   623,   625,   627,
     629,   631,   633,   635,   637,   639,   641,   643,   645,   647,
     649,   651,   653,   655,   657,   659,   661,   663,   665,   667,
     669,   671,   673,   675,   677,   679,   681,   683,   685,   687,
     689,   691,   693,   695,   697,   699,   701,   703,   705,   707,
     709,   711,   713,   715,   717,   722,   723,   726,   727,   729,
     731,   733,   735,   737,   739,   741,   743,   745,   747,   749,
     751,   753,   755,   760,   761,   767,   773,   774,   779,   780,
     784,   785,   790,   791,   798,   799,   802
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     272,     0,    -1,    -1,   273,   274,    -1,   275,   274,    -1,
     275,    -1,    -1,   277,   278,     4,   279,   293,   261,   295,
     276,   299,   341,   262,    -1,   283,   284,   285,   286,    -1,
      11,    -1,    -1,    12,   280,    -1,    -1,     4,   263,   280,
      -1,     4,    -1,     4,   263,   282,    -1,     4,    -1,     4,
     263,   282,    -1,     4,    -1,    23,    -1,    -1,    24,    -1,
      -1,    20,    -1,    -1,    25,    -1,    -1,    26,    -1,    -1,
      27,    -1,    -1,    28,    -1,    -1,    29,    -1,    -1,    30,
      -1,    -1,    21,    -1,    21,    22,    -1,    22,    -1,    20,
      -1,    -1,    14,   294,    -1,    -1,   294,   280,    -1,   280,
      -1,   295,   296,    -1,    -1,    15,   292,   298,   312,     4,
     297,    -1,   264,     5,    -1,   264,     7,    -1,   264,     6,
      -1,   264,     8,    -1,    -1,   287,   284,   290,   291,    -1,
     299,   300,    -1,    -1,    -1,    -1,    16,   292,   315,   301,
     306,     4,   265,   309,   266,   303,    17,     5,   305,   302,
     261,   318,   335,   337,   339,   262,    -1,    44,   304,    -1,
      -1,   304,   280,    -1,   280,    -1,    18,     5,    -1,    -1,
     312,    -1,    39,    -1,   308,    -1,    -1,   312,   267,   308,
      -1,   312,    -1,   310,    -1,    -1,   311,   267,   310,    -1,
     311,    -1,   312,    -1,   312,     4,    -1,   313,   314,    -1,
      31,    -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,
      36,    -1,    37,    -1,    38,    -1,   280,    -1,   268,   269,
     314,    -1,    -1,   287,   283,   284,   288,   289,    -1,   312,
       4,    -1,   280,    -1,   313,   268,   269,   314,    -1,   319,
      -1,   319,   320,    -1,    -1,   321,   322,    -1,   322,    -1,
     316,    -1,   321,   316,    -1,     3,    -1,   323,    -1,   324,
     334,    -1,   326,   312,   281,    -1,   325,   306,   281,   265,
     307,   266,    -1,   327,   280,    -1,    65,   317,    -1,   232,
     306,   281,   265,   307,   266,     5,    -1,   328,     4,    -1,
     329,   330,    -1,   230,   330,     5,    -1,   259,    40,     4,
     261,   331,   262,    -1,   260,     5,    41,     5,    40,     4,
     261,   332,   262,    -1,   239,   317,     5,    -1,   241,   333,
      -1,    58,    -1,    59,    -1,    60,    -1,    61,    -1,    62,
      -1,    63,    -1,    64,    -1,    66,    -1,    67,    -1,    68,
      -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,    73,
      -1,    74,    -1,    76,    -1,    77,    -1,    79,    -1,    80,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,
      -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,
      -1,    91,    -1,    92,    -1,    93,    -1,    94,    -1,    95,
      -1,    96,    -1,    97,    -1,    98,    -1,    99,    -1,   100,
      -1,   101,    -1,   102,    -1,   103,    -1,   104,    -1,   105,
      -1,   106,    -1,   107,    -1,   108,    -1,   109,    -1,   110,
      -1,   111,    -1,   112,    -1,   113,    -1,   114,    -1,   115,
      -1,   116,    -1,   117,    -1,   118,    -1,   119,    -1,   120,
      -1,   121,    -1,   122,    -1,   123,    -1,   124,    -1,   125,
      -1,   126,    -1,   127,    -1,   128,    -1,   129,    -1,   130,
      -1,   131,    -1,   132,    -1,   133,    -1,   138,    -1,   139,
      -1,   140,    -1,   141,    -1,   142,    -1,   143,    -1,   144,
      -1,   145,    -1,   146,    -1,   147,    -1,   148,    -1,   149,
      -1,   150,    -1,   151,    -1,   152,    -1,   153,    -1,   154,
      -1,   155,    -1,   172,    -1,   173,    -1,   174,    -1,   175,
      -1,   176,    -1,   177,    -1,   178,    -1,   179,    -1,   180,
      -1,   181,    -1,   182,    -1,   183,    -1,   184,    -1,   185,
      -1,   186,    -1,   187,    -1,   188,    -1,   189,    -1,   192,
      -1,   193,    -1,   194,    -1,   195,    -1,   196,    -1,   197,
      -1,   198,    -1,   199,    -1,   200,    -1,   201,    -1,   202,
      -1,   203,    -1,   204,    -1,   205,    -1,   206,    -1,   207,
      -1,   208,    -1,   209,    -1,   210,    -1,   211,    -1,   212,
      -1,   213,    -1,   214,    -1,   215,    -1,   216,    -1,   217,
      -1,   218,    -1,   219,    -1,   220,    -1,   221,    -1,   222,
      -1,   223,    -1,   224,    -1,   225,    -1,   226,    -1,   227,
      -1,   228,    -1,   229,    -1,   256,    -1,    75,    -1,   236,
      -1,   237,    -1,   238,    -1,   244,    -1,   234,    -1,   233,
      -1,   235,    -1,   134,    -1,   135,    -1,   242,    -1,   243,
      -1,    78,    -1,   231,    -1,   240,    -1,   136,    -1,   137,
      -1,   156,    -1,   157,    -1,   158,    -1,   159,    -1,   160,
      -1,   161,    -1,   162,    -1,   163,    -1,   164,    -1,   165,
      -1,   166,    -1,   167,    -1,   168,    -1,   169,    -1,   170,
      -1,   171,    -1,   190,    -1,   191,    -1,   245,    -1,   246,
      -1,   247,    -1,   248,    -1,   249,    -1,   250,    -1,   251,
      -1,   252,    -1,   253,    -1,   254,    -1,   255,    -1,   257,
      -1,   258,    -1,     5,    -1,     4,    -1,     5,   270,     4,
     331,    -1,    -1,     4,   332,    -1,    -1,    38,    -1,    32,
      -1,    34,    -1,    33,    -1,    31,    -1,    37,    -1,    35,
      -1,    36,    -1,     4,    -1,     5,    -1,     6,    -1,    10,
      -1,     7,    -1,     8,    -1,    42,   261,   336,   262,    -1,
      -1,   336,     4,     4,     4,   280,    -1,   336,     4,     4,
       4,     5,    -1,    -1,    45,   261,   338,   262,    -1,    -1,
     338,     4,     5,    -1,    -1,    46,   261,   340,   262,    -1,
      -1,   340,     4,     4,   312,     4,     5,    -1,    -1,    43,
      10,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   403,   403,   403,   408,   409,   414,   412,   421,   425,
     427,   432,   434,   442,   446,   453,   459,   467,   473,   481,
     483,   487,   489,   493,   495,   499,   501,   505,   507,   511,
     513,   517,   519,   523,   525,   529,   531,   535,   537,   539,
     541,   543,   547,   549,   553,   555,   560,   561,   564,   569,
     573,   577,   581,   586,   591,   596,   597,   601,   606,   601,
     622,   624,   628,   630,   635,   637,   641,   643,   652,   654,
     657,   662,   668,   670,   673,   678,   681,   685,   690,   697,
     699,   701,   703,   705,   707,   709,   711,   713,   721,   723,
     727,   732,   737,   739,   744,   748,   751,   754,   756,   758,
     760,   764,   768,   771,   774,   777,   783,   786,   789,   796,
     799,   802,   805,   808,   812,   815,   820,   822,   824,   826,
     828,   830,   832,   834,   836,   838,   840,   842,   844,   846,
     848,   850,   852,   854,   856,   858,   860,   862,   864,   866,
     868,   870,   872,   874,   876,   878,   880,   882,   884,   886,
     888,   890,   892,   894,   896,   898,   900,   902,   904,   906,
     908,   910,   912,   914,   916,   918,   920,   922,   924,   926,
     928,   930,   932,   934,   936,   938,   940,   942,   944,   946,
     948,   950,   952,   954,   956,   958,   960,   962,   964,   966,
     968,   970,   972,   974,   976,   978,   980,   982,   984,   986,
     988,   990,   992,   994,   996,   998,  1000,  1002,  1004,  1006,
    1008,  1010,  1012,  1014,  1016,  1018,  1020,  1022,  1024,  1026,
    1028,  1030,  1032,  1034,  1036,  1038,  1040,  1042,  1044,  1046,
    1048,  1050,  1052,  1054,  1056,  1058,  1060,  1062,  1064,  1066,
    1068,  1070,  1072,  1074,  1076,  1078,  1080,  1082,  1084,  1086,
    1088,  1090,  1092,  1094,  1096,  1098,  1100,  1102,  1104,  1106,
    1108,  1110,  1112,  1114,  1118,  1120,  1122,  1124,  1126,  1132,
    1134,  1136,  1141,  1143,  1145,  1147,  1152,  1154,  1156,  1160,
    1162,  1164,  1166,  1168,  1170,  1172,  1174,  1176,  1178,  1180,
    1182,  1184,  1186,  1188,  1190,  1192,  1194,  1196,  1198,  1203,
    1205,  1207,  1209,  1211,  1213,  1215,  1217,  1219,  1221,  1223,
    1225,  1227,  1231,  1233,  1237,  1239,  1242,  1244,  1248,  1250,
    1252,  1254,  1256,  1258,  1260,  1262,  1266,  1270,  1274,  1278,
    1282,  1287,  1295,  1297,  1300,  1302,  1307,  1311,  1313,  1316,
    1318,  1322,  1324,  1327,  1330,  1334,  1336
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LABEL", "IDENTIFIER", "INTCONSTANT",
  "LONGCONSTANT", "FLOATCONSTANT", "DOUBLECONSTANT", "CHARCONSTANT",
  "STRING_LITERAL", "CLASS", "EXTENDS", "ACCESS", "IMPLEMENTS", "FIELD",
  "METHOD", "MAX_STACK", "MAX_LOCALS", "CODE", "PUBLIC", "PRIVATE",
  "PROTECTED", "ABSTRACT", "FINAL", "INTERFACE", "STATIC", "NATIVE",
  "SYNCHRONIZED", "TRANSIENT", "VOLATILE", "BYTE", "CHAR", "DOUBLE",
  "FLOAT", "INT", "LONG", "SHORT", "BOOLEAN", "VOID", "DEFAULT", "TO",
  "EXCEPTIONS", "SOURCEFILE", "THROWS", "LINENUMBERTABLE",
  "LOCALVARIABLETABLE", "ACC_PUBLIC", "ACC_PRIVATE", "ACC_PROTECTED",
  "ACC_STATIC", "ACC_FINAL", "ACC_SYNCHRONIZED", "ACC_VOLATILE",
  "ACC_TRANSIENT", "ACC_NATIVE", "ACC_INTERFACE", "ACC_ABSTRACT", "AALOAD",
  "AASTORE", "ACONST_NULL", "ALOAD_0", "ALOAD_1", "ALOAD_2", "ALOAD_3",
  "ANEWARRAY", "ARETURN", "ARRAYLENGTH", "ASTORE_0", "ASTORE_1",
  "ASTORE_2", "ASTORE_3", "ATHROW", "BALOAD", "BASTORE", "BIPUSH",
  "CALOAD", "CASTORE", "CHECKCAST", "D2F", "D2I", "D2L", "DADD", "DALOAD",
  "DASTORE", "DCMPG", "DCMPL", "DCONST_0", "DCONST_1", "DDIV", "DLOAD_0",
  "DLOAD_1", "DLOAD_2", "DLOAD_3", "DMUL", "DNEG", "DREM", "DRETURN",
  "DSTORE_0", "DSTORE_1", "DSTORE_2", "DSTORE_3", "DSUB", "DUP", "DUP_X1",
  "DUP_X2", "DUP2", "DUP2_X1", "DUP2_X2", "F2D", "F2I", "F2L", "FADD",
  "FALOAD", "FASTORE", "FCMPG", "FCMPL", "FCONST_0", "FCONST_1",
  "FCONST_2", "FDIV", "FLOAD_0", "FLOAD_1", "FLOAD_2", "FLOAD_3", "FMUL",
  "FNEG", "FREM", "FRETURN", "FSTORE_0", "FSTORE_1", "FSTORE_2",
  "FSTORE_3", "FSUB", "GETFIELD", "GETSTATIC", "GOTO", "GOTO_W", "I2B",
  "I2C", "I2D", "I2F", "I2L", "I2S", "IADD", "IALOAD", "IAND", "IASTORE",
  "ICONST_0", "ICONST_1", "ICONST_2", "ICONST_3", "ICONST_4", "ICONST_5",
  "ICONST_M1", "IDIV", "IF_ACMPEQ", "IF_ACMPNE", "IF_ICMPEQ", "IF_ICMPNE",
  "IF_ICMPLT", "IF_ICMPGE", "IF_ICMPGT", "IF_ICMPLE", "IFEQ", "IFNE",
  "IFLT", "IFGE", "IFGT", "IFLE", "IFNONNULL", "IFNULL", "ILOAD_0",
  "ILOAD_1", "ILOAD_2", "ILOAD_3", "IMUL", "INEG", "IOR", "IREM",
  "IRETURN", "ISHL", "ISHR", "ISTORE_0", "ISTORE_1", "ISTORE_2",
  "ISTORE_3", "ISUB", "IUSHR", "IXOR", "JSR", "JSR_W", "L2D", "L2F", "L2I",
  "LADD", "LALOAD", "LAND", "LASTORE", "LCMP", "LCONST_0", "LCONST_1",
  "LDIV", "LLOAD_0", "LLOAD_1", "LLOAD_2", "LLOAD_3", "LMUL", "LNEG",
  "LOR", "LREM", "LRETURN", "LSHL", "LSHR", "LSTORE_0", "LSTORE_1",
  "LSTORE_2", "LSTORE_3", "LSUB", "LUSHR", "LXOR", "MONITORENTER",
  "MONITOREXIT", "NOP", "POP", "POP2", "RETURN", "SALOAD", "SASTORE",
  "SWAP", "IINC", "INSTANCEOF", "INVOKEINTERFACE", "INVOKENONVIRTUAL",
  "INVOKESTATIC", "INVOKEVIRTUAL", "LDC", "LDC_W", "LDC2_W",
  "MULTIANEWARRAY", "NEW", "NEWARRAY", "PUTFIELD", "PUTSTATIC", "SIPUSH",
  "ILOAD", "FLOAD", "ALOAD", "LLOAD", "DLOAD", "ISTORE", "FSTORE",
  "ASTORE", "LSTORE", "DSTORE", "RET", "WIDE", "LOAD", "STORE",
  "LOOKUPSWITCH", "TABLESWITCH", "'{'", "'}'", "'.'", "'='", "'('", "')'",
  "','", "'['", "']'", "':'", "$accept", "compilation_unit", "@1",
  "classlist", "class", "@2", "class_modifiers", "classword", "superclass",
  "classname", "classfieldmethodname", "endname", "abstract_entry",
  "final_entry", "public_entry", "interface_entry", "static_entry",
  "native_entry", "synchronized_entry", "transient_entry",
  "volatile_entry", "access_specifier", "interfaces", "interfacelist",
  "fieldlist", "field", "fieldconstant", "field_modifiers", "methodlist",
  "method", "@3", "@4", "throwslist", "throwsentries", "max_locals_decl",
  "returntype", "arguments", "argumentlist", "methodarguments",
  "methodargumentlist", "methodargument", "type", "basetype", "arrayadder",
  "method_modifiers", "localvar", "arrayorclassname", "code", "op_list",
  "op_line", "label", "op", "no_arg_op", "one_arg_op", "methodref_arg_op",
  "fieldref_arg_op", "class_arg_op", "label_arg_op", "localvar_arg_op",
  "localvar_arg", "lookuplist", "tablelist", "newarraytype", "argument",
  "exceptiontable", "exceptionslist", "linenumbertable", "linenumberlist",
  "localvariabletable", "localvariablelist", "sourcefilename", 0
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
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   123,   125,    46,    61,    40,    41,    44,    91,    93,
      58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   271,   273,   272,   274,   274,   276,   275,   277,   278,
     278,   279,   279,   280,   280,   281,   281,   282,   282,   283,
     283,   284,   284,   285,   285,   286,   286,   287,   287,   288,
     288,   289,   289,   290,   290,   291,   291,   292,   292,   292,
     292,   292,   293,   293,   294,   294,   295,   295,   296,   297,
     297,   297,   297,   297,   298,   299,   299,   301,   302,   300,
     303,   303,   304,   304,   305,   305,   306,   306,   307,   307,
     308,   308,   309,   309,   310,   310,   311,   311,   312,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   314,   314,
     315,   316,   317,   317,   318,   319,   319,   320,   320,   320,
     320,   321,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   324,   324,   324,   324,   324,   325,
     325,   325,   326,   326,   326,   326,   327,   327,   327,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   330,   330,   331,   331,   332,   332,   333,   333,
     333,   333,   333,   333,   333,   333,   334,   334,   334,   334,
     334,   334,   335,   335,   336,   336,   336,   337,   337,   338,
     338,   339,   339,   340,   340,   341,   341
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     0,    11,     4,     1,
       0,     2,     0,     3,     1,     3,     1,     3,     1,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     2,     1,
       1,     0,     2,     0,     2,     1,     2,     0,     6,     2,
       2,     2,     2,     0,     4,     2,     0,     0,     0,    20,
       2,     0,     2,     1,     2,     0,     1,     1,     1,     0,
       3,     1,     1,     0,     3,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     0,
       5,     2,     1,     4,     1,     2,     0,     2,     1,     1,
       2,     1,     1,     2,     3,     6,     2,     2,     7,     2,
       2,     3,     6,     9,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     0,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     0,     5,     5,     0,     4,     0,     3,
       0,     4,     0,     6,     0,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,    20,     1,    19,     3,    20,    10,    22,     4,
       9,     0,    21,    24,    12,    23,    26,     0,    43,    25,
       8,    14,    11,     0,     0,     0,    45,    42,    47,    13,
      44,     6,    41,    56,    46,    40,    37,    39,    28,   346,
      38,    27,    22,     0,    41,     0,    55,     0,    34,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,    89,
      28,   345,     7,    33,    36,    53,     0,    78,    20,    57,
      35,    54,     0,    48,    89,    22,     0,    49,    51,    50,
      52,    88,    30,    67,     0,    66,    29,    32,     0,    31,
      90,    73,     0,    72,    75,    76,    61,     0,    77,     0,
       0,    74,    63,    60,     0,    62,    65,     0,    58,    64,
       0,    96,   333,    94,     0,   338,   101,   116,   117,   118,
     119,   120,   121,   122,     0,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   264,   132,   133,   276,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   272,   273,   279,   280,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   297,
     298,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,     0,
     277,     0,   270,   269,   271,   265,   266,   267,     0,   278,
       0,   274,   275,   268,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   263,   310,   311,     0,     0,
       0,    99,    95,     0,    98,   102,     0,     0,     0,     0,
       0,     0,   336,     0,   342,    92,     0,   107,   313,   312,
       0,     0,     0,   322,   319,   321,   320,   324,   325,   323,
     318,   115,     0,     0,    91,   100,    97,   326,   327,   328,
     330,   331,   329,   103,     0,     0,   106,   109,   110,     0,
     340,     0,     0,     0,   111,    16,     0,   114,     0,     0,
       0,   104,     0,   332,     0,   344,    59,    89,     0,    69,
     315,     0,    69,     0,     0,   337,     0,    93,    18,    15,
       0,    68,    71,     0,     0,     0,     0,     0,   339,     0,
     341,     0,     0,     0,     0,   112,     0,   105,   335,   334,
       0,    17,   108,    70,   315,   317,     0,   314,   317,     0,
       0,   316,   113,   343
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     6,    33,     7,    11,    18,    57,
     376,   399,     8,    13,    16,    20,    42,    87,    90,    64,
      71,    38,    24,    27,    31,    34,    73,    43,    39,    46,
      76,   110,   100,   103,   108,    84,   400,   401,    92,    93,
      94,    85,    59,    67,    69,   321,   337,   112,   113,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   340,
     404,   429,   351,   363,   115,   369,   334,   384,   372,   396,
      47
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -314
static const yytype_int16 yypact[] =
{
    -314,    14,     5,  -314,  -314,  -314,    13,    32,     7,  -314,
    -314,    45,  -314,    34,    41,  -314,    30,    62,    53,  -314,
    -314,  -195,  -314,    62,  -192,    62,  -314,    62,  -314,  -314,
    -314,    55,    20,  -314,  -314,  -314,    49,  -314,    57,    -4,
    -314,  -314,     7,    42,    20,    71,  -314,  -178,    56,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,    83,  -180,
      57,  -314,  -314,  -314,    59,  -174,  -177,  -314,     5,  -314,
    -314,  -314,    27,  -314,  -180,     7,    26,  -314,  -314,  -314,
    -314,  -314,    64,  -314,    89,  -314,  -314,    66,  -170,  -314,
    -314,    42,  -169,  -314,  -171,    94,    58,    42,  -314,    62,
      82,  -314,  -314,    62,    95,  -314,    85,    96,  -314,  -314,
    -157,  -314,    63,   333,  -155,    65,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,    42,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,    33,
    -314,    26,  -314,  -314,  -314,  -314,  -314,  -314,    42,  -314,
     -16,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,    68,   104,
     107,  -314,  -314,   590,  -314,  -314,    19,    26,    42,    62,
     108,    33,  -314,  -148,    69,  -154,  -152,  -314,  -314,  -314,
     112,   114,   115,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,   117,    78,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,   114,   114,  -314,  -314,  -314,    -1,
    -314,  -139,  -138,  -146,  -314,  -137,  -140,  -314,  -134,   123,
    -136,  -314,   126,  -314,     0,  -314,  -314,  -180,   127,    42,
     128,    92,    42,   130,   131,  -314,     1,  -314,  -128,  -314,
    -129,  -314,  -127,  -132,  -123,   137,  -124,    43,  -314,   139,
    -314,   127,   140,    42,   142,  -314,  -114,  -314,  -314,  -314,
      42,  -314,  -314,  -314,   128,   144,   145,  -314,   144,  -118,
     146,  -314,  -314,  -314
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -314,  -314,  -314,   147,  -314,  -314,  -314,  -314,  -314,   -17,
    -313,  -261,    84,   -31,  -314,  -314,    97,  -314,  -314,  -314,
    -314,   110,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -282,  -237,  -257,  -314,    61,
    -314,   -41,  -117,   -73,  -314,  -164,  -135,  -314,  -314,  -314,
    -314,  -163,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -167,
    -263,  -266,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -88
static const yytype_int16 yytable[] =
{
      22,    81,    58,   382,   394,   409,    26,   336,    29,   341,
      30,    48,    44,    -5,     3,   343,   344,   345,   346,   347,
     348,   349,   350,   357,   358,   359,   360,   361,     4,   362,
      21,    12,    77,    78,    79,    80,     4,   338,   339,    45,
      35,    36,    37,    10,    82,   364,    21,    21,   418,    14,
      95,   380,   381,    17,    15,    19,    95,    49,    50,    51,
      52,    53,    54,    55,    56,    83,    21,    23,    25,    28,
      32,    40,   320,    49,    50,    51,    52,    53,    54,    55,
      56,    61,   102,    41,    62,    63,   105,    65,    66,    70,
      72,    86,    74,    88,    89,    91,    97,    96,    98,   104,
     106,   109,    99,   107,   111,   114,   332,   335,   352,   353,
     333,   354,   367,   370,   -87,   371,   373,   374,   375,   379,
     377,   378,   385,   387,   386,   389,   388,   390,   391,   392,
     393,   398,   405,   403,   407,   411,   408,   412,   414,   415,
     413,   416,   417,   420,   432,   422,   424,   425,   428,   430,
     421,   433,    75,     9,    60,   406,   423,    68,   101,   355,
     356,   427,   431,   342,   368,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   336,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   383,   395,   410,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   335,   320,     0,     0,     0,     0,   365,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   366,     0,   397,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   402,     0,
       0,   402,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,    50,    51,    52,    53,    54,
      55,    56,   402,     0,     0,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     419,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,    50,    51,    52,    53,    54,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319
};

static const yytype_int16 yycheck[] =
{
      17,    74,    43,     4,     4,     4,    23,   124,    25,   291,
      27,    42,    16,     0,     0,    31,    32,    33,    34,    35,
      36,    37,    38,     4,     5,     6,     7,     8,    23,    10,
       4,    24,     5,     6,     7,     8,    23,     4,     5,    43,
      20,    21,    22,    11,    75,   327,     4,     4,     5,     4,
      91,   364,   365,    12,    20,    25,    97,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     4,    14,   263,   261,
      15,    22,   113,    31,    32,    33,    34,    35,    36,    37,
      38,    10,    99,    26,   262,    29,   103,     4,   268,    30,
     264,    27,   269,     4,    28,   265,   267,   266,     4,    17,
       5,     5,    44,    18,   261,    42,   261,   124,    40,     5,
      45,     4,     4,   261,   268,    46,   268,     5,     4,    41,
       5,     4,   261,   269,   262,   265,   263,   261,     5,   265,
       4,     4,    40,     5,     4,   263,     5,   266,   270,   262,
     267,     4,   266,     4,   262,     5,     4,   261,     4,     4,
     411,     5,    68,     6,    44,   392,   413,    60,    97,   323,
     323,   424,   428,   298,   331,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   262,   262,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   298,   323,    -1,    -1,    -1,    -1,   328,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   329,    -1,   387,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   389,    -1,
      -1,   392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,   413,    -1,    -1,    -1,    -1,    -1,    -1,   420,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     407,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   272,   273,     0,    23,   274,   275,   277,   283,   274,
      11,   278,    24,   284,     4,    20,   285,    12,   279,    25,
     286,     4,   280,    14,   293,   263,   280,   294,   261,   280,
     280,   295,    15,   276,   296,    20,    21,    22,   292,   299,
      22,    26,   287,   298,    16,    43,   300,   341,   284,    31,
      32,    33,    34,    35,    36,    37,    38,   280,   312,   313,
     292,    10,   262,    29,   290,     4,   268,   314,   287,   315,
      30,   291,   264,   297,   269,   283,   301,     5,     6,     7,
       8,   314,   284,    39,   306,   312,    27,   288,     4,    28,
     289,   265,   309,   310,   311,   312,   266,   267,     4,    44,
     303,   310,   280,   304,    17,   280,     5,    18,   305,     5,
     302,   261,   318,   319,    42,   335,     3,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     312,   316,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   261,    45,   337,   280,   313,   317,     4,     5,
     330,   306,   317,    31,    32,    33,    34,    35,    36,    37,
      38,   333,    40,     5,     4,   316,   322,     4,     5,     6,
       7,     8,    10,   334,   306,   312,   280,     4,   330,   336,
     261,    46,   339,   268,     5,     4,   281,     5,     4,    41,
     281,   281,     4,   262,   338,   261,   262,   269,   263,   265,
     261,     5,   265,     4,     4,   262,   340,   314,     4,   282,
     307,   308,   312,     5,   331,    40,   307,     4,     5,     4,
     262,   263,   266,   267,   270,   262,     4,   266,     5,   280,
       4,   282,     5,   308,     4,   261,   312,   331,     4,   332,
       4,   332,   262,     5
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
        case 2:
#line 403 "javaa.y"
    { InitAssembler();;}
    break;

  case 3:
#line 404 "javaa.y"
    { EndAssembler();;}
    break;

  case 6:
#line 414 "javaa.y"
    {
		SetThisClass((yyvsp[(1) - (7)].intval), (yyvsp[(3) - (7)].string), (yyvsp[(4) - (7)].string));
		;}
    break;

  case 8:
#line 422 "javaa.y"
    {(yyval.intval) = (yyvsp[(1) - (4)].intval) | (yyvsp[(2) - (4)].intval) | (yyvsp[(3) - (4)].intval) | (yyvsp[(4) - (4)].intval);;}
    break;

  case 9:
#line 426 "javaa.y"
    {break;;}
    break;

  case 10:
#line 427 "javaa.y"
    {break;;}
    break;

  case 11:
#line 433 "javaa.y"
    { (yyval.string) = (yyvsp[(2) - (2)].string);;}
    break;

  case 12:
#line 434 "javaa.y"
    {
	    char* tempstring;
	    tempstring = (char *) malloc(strlen("java/lang/Object"));
	    strcpy(tempstring,"java/lang/Object");
	    (yyval.string) = tempstring;
	  ;}
    break;

  case 13:
#line 443 "javaa.y"
    {
		  (yyval.string) = ConsStrings((yyvsp[(1) - (3)].string),ConsStrings("/",(yyvsp[(3) - (3)].string)));
		;}
    break;

  case 14:
#line 447 "javaa.y"
    {
		  (yyval.string) = (yyvsp[(1) - (1)].string);
		;}
    break;

  case 15:
#line 454 "javaa.y"
    {
		  if ((yyvsp[(3) - (3)].classfieldmethodstruct).classname == NULL) (yyval.classfieldmethodstruct).classname = (yyvsp[(1) - (3)].string);
		  else (yyval.classfieldmethodstruct).classname = ConsStrings((yyvsp[(1) - (3)].string),ConsStrings("/",(yyvsp[(3) - (3)].classfieldmethodstruct).classname));
		  (yyval.classfieldmethodstruct).fieldmethodname = (yyvsp[(3) - (3)].classfieldmethodstruct).fieldmethodname;
		;}
    break;

  case 16:
#line 460 "javaa.y"
    {
		  (yyval.classfieldmethodstruct).classname = GetThisClass();
		  (yyval.classfieldmethodstruct).fieldmethodname = (yyvsp[(1) - (1)].string);
		;}
    break;

  case 17:
#line 468 "javaa.y"
    {
		  if ((yyvsp[(3) - (3)].classfieldmethodstruct).classname == NULL) (yyval.classfieldmethodstruct).classname = (yyvsp[(1) - (3)].string);
		  else (yyval.classfieldmethodstruct).classname = ConsStrings((yyvsp[(1) - (3)].string),ConsStrings("/",(yyvsp[(3) - (3)].classfieldmethodstruct).classname));
		  (yyval.classfieldmethodstruct).fieldmethodname = (yyvsp[(3) - (3)].classfieldmethodstruct).fieldmethodname;
		;}
    break;

  case 18:
#line 474 "javaa.y"
    {
		  (yyval.classfieldmethodstruct).classname = NULL;
		  (yyval.classfieldmethodstruct).fieldmethodname = (yyvsp[(1) - (1)].string);
		;}
    break;

  case 19:
#line 482 "javaa.y"
    {(yyval.intval) = 0x0400;;}
    break;

  case 20:
#line 483 "javaa.y"
    {(yyval.intval)=0;;}
    break;

  case 21:
#line 488 "javaa.y"
    {(yyval.intval) = 0x0010;;}
    break;

  case 22:
#line 489 "javaa.y"
    {(yyval.intval)=0;;}
    break;

  case 23:
#line 494 "javaa.y"
    {(yyval.intval) = 0x0001;;}
    break;

  case 24:
#line 495 "javaa.y"
    {(yyval.intval)=0;;}
    break;

  case 25:
#line 500 "javaa.y"
    {(yyval.intval) = 0x0200;;}
    break;

  case 26:
#line 501 "javaa.y"
    {(yyval.intval)=0;;}
    break;

  case 27:
#line 506 "javaa.y"
    {(yyval.intval) = 0x0008;;}
    break;

  case 28:
#line 507 "javaa.y"
    {(yyval.intval)=0;;}
    break;

  case 29:
#line 512 "javaa.y"
    {(yyval.intval) = 0x0100;;}
    break;

  case 30:
#line 513 "javaa.y"
    {(yyval.intval)=0;;}
    break;

  case 31:
#line 518 "javaa.y"
    {(yyval.intval) = 0x0020;;}
    break;

  case 32:
#line 519 "javaa.y"
    {(yyval.intval)=0;;}
    break;

  case 33:
#line 524 "javaa.y"
    {(yyval.intval) = 0x0080;;}
    break;

  case 34:
#line 525 "javaa.y"
    {(yyval.intval)=0;;}
    break;

  case 35:
#line 530 "javaa.y"
    {(yyval.intval) = 0x0040;;}
    break;

  case 36:
#line 531 "javaa.y"
    {(yyval.intval)=0;;}
    break;

  case 37:
#line 536 "javaa.y"
    {(yyval.intval) = 2;;}
    break;

  case 38:
#line 538 "javaa.y"
    {(yyval.intval) = 6;;}
    break;

  case 39:
#line 540 "javaa.y"
    {(yyval.intval) = 4;;}
    break;

  case 40:
#line 542 "javaa.y"
    {(yyval.intval) = 1;;}
    break;

  case 41:
#line 543 "javaa.y"
    {(yyval.intval)=0;;}
    break;

  case 42:
#line 548 "javaa.y"
    {break;;}
    break;

  case 43:
#line 549 "javaa.y"
    {break;;}
    break;

  case 44:
#line 554 "javaa.y"
    { AddToInterfaceList((yyvsp[(2) - (2)].string));;}
    break;

  case 45:
#line 556 "javaa.y"
    { AddToInterfaceList((yyvsp[(1) - (1)].string));;}
    break;

  case 47:
#line 561 "javaa.y"
    {break;;}
    break;

  case 48:
#line 565 "javaa.y"
    {NewField((yyvsp[(2) - (6)].intval)|(yyvsp[(3) - (6)].intval), (yyvsp[(5) - (6)].string), (yyvsp[(4) - (6)].string), (yyvsp[(6) - (6)].argtype));;}
    break;

  case 49:
#line 570 "javaa.y"
    {(yyval.argtype).type = INTCONSTANT;
              (yyval.argtype).intval = (yyvsp[(2) - (2)].intval);
             ;}
    break;

  case 50:
#line 574 "javaa.y"
    {(yyval.argtype).type = FLOATCONSTANT;
              (yyval.argtype).floatval = (yyvsp[(2) - (2)].floatval);
             ;}
    break;

  case 51:
#line 578 "javaa.y"
    {(yyval.argtype).type = LONGCONSTANT;
              (yyval.argtype).longval = (yyvsp[(2) - (2)].longval);
             ;}
    break;

  case 52:
#line 582 "javaa.y"
    {(yyval.argtype).type = DOUBLECONSTANT;
              (yyval.argtype).doubleval = (yyvsp[(2) - (2)].doubleval);
             ;}
    break;

  case 53:
#line 586 "javaa.y"
    {(yyval.argtype).type = 0;
             ;}
    break;

  case 54:
#line 592 "javaa.y"
    { (yyval.intval) = (yyvsp[(1) - (4)].intval) | (yyvsp[(2) - (4)].intval) | (yyvsp[(3) - (4)].intval) | (yyvsp[(4) - (4)].intval) ;;}
    break;

  case 56:
#line 597 "javaa.y"
    {break;;}
    break;

  case 57:
#line 601 "javaa.y"
    {NewNewMethod((yyvsp[(2) - (3)].intval)|(yyvsp[(3) - (3)].intval));;}
    break;

  case 58:
#line 606 "javaa.y"
    { 
	    char* tmpstr; 
	    /*message("Calling NewMethod.");*/
	    tmpstr = ConsStrings("(",ConsStrings((yyvsp[(8) - (13)].string),ConsStrings(")",(yyvsp[(5) - (13)].string))));
	    /*message(tmpstr);*/
	    NewMethod((yyvsp[(6) - (13)].string), tmpstr, (yyvsp[(12) - (13)].intval), (yyvsp[(13) - (13)].intval)); ;}
    break;

  case 59:
#line 618 "javaa.y"
    {EndMethod();;}
    break;

  case 60:
#line 623 "javaa.y"
    {break;;}
    break;

  case 61:
#line 624 "javaa.y"
    {break;;}
    break;

  case 62:
#line 629 "javaa.y"
    {AddToThrowsList((yyvsp[(2) - (2)].string));;}
    break;

  case 63:
#line 631 "javaa.y"
    {AddToThrowsList((yyvsp[(1) - (1)].string));;}
    break;

  case 64:
#line 636 "javaa.y"
    {(yyval.intval) = (yyvsp[(2) - (2)].intval);;}
    break;

  case 65:
#line 637 "javaa.y"
    {(yyval.intval) = -1;;}
    break;

  case 66:
#line 642 "javaa.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); ;}
    break;

  case 67:
#line 644 "javaa.y"
    { char* tempstring;
	     	  tempstring = (char *) malloc(strlen("B"));
	     	  strcpy(tempstring,"V");
	     	  (yyval.string) = tempstring;
	  	;}
    break;

  case 68:
#line 653 "javaa.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string);;}
    break;

  case 69:
#line 654 "javaa.y"
    {(yyval.string) = NULL;;}
    break;

  case 70:
#line 658 "javaa.y"
    {
		  /*message("in arguments with comma.");*/
		  (yyval.string) = ConsStrings((yyvsp[(1) - (3)].string),(yyvsp[(3) - (3)].string));
		;}
    break;

  case 71:
#line 663 "javaa.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); /*message("in arguments");*/;}
    break;

  case 72:
#line 669 "javaa.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string);;}
    break;

  case 73:
#line 670 "javaa.y"
    {(yyval.string) = NULL;;}
    break;

  case 74:
#line 674 "javaa.y"
    {
		  /*message("in arguments with comma.");*/
		  (yyval.string) = ConsStrings((yyvsp[(1) - (3)].string),(yyvsp[(3) - (3)].string));
		;}
    break;

  case 75:
#line 679 "javaa.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); /*message("in arguments");*/;}
    break;

  case 76:
#line 682 "javaa.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); 
		  /*message("calling IncrementLocalVarSlot");*/
		  IncrementLocalVarSlot((yyvsp[(1) - (1)].string)); /*message("in methodargument");*/;}
    break;

  case 77:
#line 686 "javaa.y"
    { (yyval.string) = (yyvsp[(1) - (2)].string); NewLocalVar((yyvsp[(2) - (2)].string), (yyvsp[(1) - (2)].string));/*message("in methodargument");*/;}
    break;

  case 78:
#line 691 "javaa.y"
    {
		  /*message("In type.");*/
		  (yyval.string) = ConsStrings((yyvsp[(2) - (2)].string),(yyvsp[(1) - (2)].string));
		;}
    break;

  case 79:
#line 698 "javaa.y"
    { (yyval.string) = ConsStrings("B",""); ;}
    break;

  case 80:
#line 700 "javaa.y"
    { (yyval.string) = ConsStrings("C",""); ;}
    break;

  case 81:
#line 702 "javaa.y"
    { (yyval.string) = ConsStrings("D",""); ;}
    break;

  case 82:
#line 704 "javaa.y"
    { (yyval.string) = ConsStrings("F",""); ;}
    break;

  case 83:
#line 706 "javaa.y"
    { (yyval.string) = ConsStrings("I",""); ;}
    break;

  case 84:
#line 708 "javaa.y"
    { (yyval.string) = ConsStrings("J",""); ;}
    break;

  case 85:
#line 710 "javaa.y"
    { (yyval.string) = ConsStrings("S",""); ;}
    break;

  case 86:
#line 712 "javaa.y"
    { (yyval.string) = ConsStrings("Z",""); ;}
    break;

  case 87:
#line 714 "javaa.y"
    {
		 (yyval.string) = ConsStrings("L", ConsStrings((yyvsp[(1) - (1)].string),";"));
	   	 /*message($$);*/
		 /*message("Got classname.");*/;}
    break;

  case 88:
#line 722 "javaa.y"
    {(yyval.string) = ConsStrings("[",(yyvsp[(3) - (3)].string));;}
    break;

  case 89:
#line 723 "javaa.y"
    {(yyval.string)=NULL;;}
    break;

  case 90:
#line 729 "javaa.y"
    { (yyval.intval) = (yyvsp[(1) - (5)].intval) | (yyvsp[(2) - (5)].intval) | (yyvsp[(3) - (5)].intval) | (yyvsp[(4) - (5)].intval) | (yyvsp[(5) - (5)].intval);;}
    break;

  case 91:
#line 733 "javaa.y"
    {NewLocalVar((yyvsp[(2) - (2)].string), (yyvsp[(1) - (2)].string));;}
    break;

  case 92:
#line 738 "javaa.y"
    {(yyval.string) = (yyvsp[(1) - (1)].string);;}
    break;

  case 93:
#line 740 "javaa.y"
    {(yyval.string) = ConsStrings("[",ConsStrings((yyvsp[(4) - (4)].string),(yyvsp[(1) - (4)].string)));;}
    break;

  case 94:
#line 745 "javaa.y"
    {break;;}
    break;

  case 95:
#line 749 "javaa.y"
    {break;;}
    break;

  case 96:
#line 751 "javaa.y"
    {break;;}
    break;

  case 97:
#line 755 "javaa.y"
    {break;;}
    break;

  case 98:
#line 757 "javaa.y"
    {break;;}
    break;

  case 99:
#line 759 "javaa.y"
    {break;;}
    break;

  case 100:
#line 761 "javaa.y"
    {break;;}
    break;

  case 101:
#line 765 "javaa.y"
    {DefineLabel((yyvsp[(1) - (1)].string));;}
    break;

  case 102:
#line 769 "javaa.y"
    {GenNoArgCode((yyvsp[(1) - (1)].intval));
		;}
    break;

  case 103:
#line 772 "javaa.y"
    {GenOneArgCode((yyvsp[(1) - (2)].intval), (yyvsp[(2) - (2)].argtype));
		;}
    break;

  case 104:
#line 775 "javaa.y"
    {GenFieldArgCode((yyvsp[(1) - (3)].intval), (yyvsp[(3) - (3)].classfieldmethodstruct).classname, (yyvsp[(3) - (3)].classfieldmethodstruct).fieldmethodname, (yyvsp[(2) - (3)].string));
		;}
    break;

  case 105:
#line 779 "javaa.y"
    {GenMethodArgCode((yyvsp[(1) - (6)].intval), (yyvsp[(3) - (6)].classfieldmethodstruct).classname, (yyvsp[(3) - (6)].classfieldmethodstruct).fieldmethodname,
		         	 ConsStrings("(",ConsStrings((yyvsp[(5) - (6)].string),
				   ConsStrings(")",(yyvsp[(2) - (6)].string))))); 
		;}
    break;

  case 106:
#line 784 "javaa.y"
    {GenClassArgCode((yyvsp[(1) - (2)].intval), (yyvsp[(2) - (2)].string));
		;}
    break;

  case 107:
#line 787 "javaa.y"
    {GenClassArgCode((yyvsp[(1) - (2)].Rk).terminal, (yyvsp[(2) - (2)].string));
		;}
    break;

  case 108:
#line 791 "javaa.y"
    {GenINVOKEINTERFACECode((yyvsp[(1) - (7)].Rk).terminal, (yyvsp[(3) - (7)].classfieldmethodstruct).classname,
				 (yyvsp[(3) - (7)].classfieldmethodstruct).fieldmethodname,
		         	 ConsStrings("(",ConsStrings((yyvsp[(5) - (7)].string),
				   ConsStrings(")",(yyvsp[(2) - (7)].string)))), (yyvsp[(7) - (7)].intval)); 
		;}
    break;

  case 109:
#line 797 "javaa.y"
    {GenLabelArgCode((yyvsp[(1) - (2)].intval), (yyvsp[(2) - (2)].string));
		;}
    break;

  case 110:
#line 800 "javaa.y"
    {GenLocalVarArgCode((yyvsp[(1) - (2)].intval),(yyvsp[(2) - (2)].intval));
		;}
    break;

  case 111:
#line 803 "javaa.y"
    {GenIINCCode((yyvsp[(1) - (3)].Rk).terminal,(yyvsp[(2) - (3)].intval),(yyvsp[(3) - (3)].intval));
		;}
    break;

  case 112:
#line 806 "javaa.y"
    {GenLOOKUPSWITCHCode((yyvsp[(1) - (6)].Rk).terminal,(yyvsp[(3) - (6)].string),(yyvsp[(5) - (6)].lookuplistptr));
		;}
    break;

  case 113:
#line 810 "javaa.y"
    {GenTABLESWITCHCode((yyvsp[(1) - (9)].Rk).terminal,(yyvsp[(2) - (9)].intval),(yyvsp[(4) - (9)].intval),(yyvsp[(6) - (9)].string),(yyvsp[(8) - (9)].tablelistptr));
		;}
    break;

  case 114:
#line 813 "javaa.y"
    {GenMULTIANEWARRAYCode((yyvsp[(1) - (3)].Rk).terminal,(yyvsp[(2) - (3)].string),(yyvsp[(3) - (3)].intval));
		;}
    break;

  case 115:
#line 816 "javaa.y"
    {GenNEWARRAYCode((yyvsp[(1) - (2)].Rk).terminal,(yyvsp[(2) - (2)].intval));
		;}
    break;

  case 116:
#line 821 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 117:
#line 823 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 118:
#line 825 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 119:
#line 827 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 120:
#line 829 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 121:
#line 831 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 122:
#line 833 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 123:
#line 835 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 124:
#line 837 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 125:
#line 839 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 126:
#line 841 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 127:
#line 843 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 128:
#line 845 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 129:
#line 847 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 130:
#line 849 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 131:
#line 851 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 132:
#line 853 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 133:
#line 855 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 134:
#line 857 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 135:
#line 859 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 136:
#line 861 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 137:
#line 863 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 138:
#line 865 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 139:
#line 867 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 140:
#line 869 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 141:
#line 871 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 142:
#line 873 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 143:
#line 875 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 144:
#line 877 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 145:
#line 879 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 146:
#line 881 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 147:
#line 883 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 148:
#line 885 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 149:
#line 887 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 150:
#line 889 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 151:
#line 891 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 152:
#line 893 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 153:
#line 895 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 154:
#line 897 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 155:
#line 899 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 156:
#line 901 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 157:
#line 903 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 158:
#line 905 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 159:
#line 907 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 160:
#line 909 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 161:
#line 911 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 162:
#line 913 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 163:
#line 915 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 164:
#line 917 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 165:
#line 919 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 166:
#line 921 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 167:
#line 923 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 168:
#line 925 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 169:
#line 927 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 170:
#line 929 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 171:
#line 931 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 172:
#line 933 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 173:
#line 935 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 174:
#line 937 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 175:
#line 939 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 176:
#line 941 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 177:
#line 943 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 178:
#line 945 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 179:
#line 947 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 180:
#line 949 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 181:
#line 951 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 182:
#line 953 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 183:
#line 955 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 184:
#line 957 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 185:
#line 959 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 186:
#line 961 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 187:
#line 963 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 188:
#line 965 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 189:
#line 967 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 190:
#line 969 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 191:
#line 971 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 192:
#line 973 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 193:
#line 975 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 194:
#line 977 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 195:
#line 979 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 196:
#line 981 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 197:
#line 983 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 198:
#line 985 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 199:
#line 987 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 200:
#line 989 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 201:
#line 991 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 202:
#line 993 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 203:
#line 995 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 204:
#line 997 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 205:
#line 999 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 206:
#line 1001 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 207:
#line 1003 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 208:
#line 1005 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 209:
#line 1007 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 210:
#line 1009 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 211:
#line 1011 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 212:
#line 1013 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 213:
#line 1015 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 214:
#line 1017 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 215:
#line 1019 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 216:
#line 1021 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 217:
#line 1023 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 218:
#line 1025 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 219:
#line 1027 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 220:
#line 1029 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 221:
#line 1031 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 222:
#line 1033 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 223:
#line 1035 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 224:
#line 1037 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 225:
#line 1039 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 226:
#line 1041 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 227:
#line 1043 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 228:
#line 1045 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 229:
#line 1047 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 230:
#line 1049 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 231:
#line 1051 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 232:
#line 1053 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 233:
#line 1055 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 234:
#line 1057 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 235:
#line 1059 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 236:
#line 1061 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 237:
#line 1063 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 238:
#line 1065 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 239:
#line 1067 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 240:
#line 1069 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 241:
#line 1071 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 242:
#line 1073 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 243:
#line 1075 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 244:
#line 1077 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 245:
#line 1079 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 246:
#line 1081 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 247:
#line 1083 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 248:
#line 1085 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 249:
#line 1087 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 250:
#line 1089 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 251:
#line 1091 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 252:
#line 1093 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 253:
#line 1095 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 254:
#line 1097 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 255:
#line 1099 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 256:
#line 1101 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 257:
#line 1103 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 258:
#line 1105 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 259:
#line 1107 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 260:
#line 1109 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 261:
#line 1111 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 262:
#line 1113 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 263:
#line 1115 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 264:
#line 1119 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 265:
#line 1121 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 266:
#line 1123 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 267:
#line 1125 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 268:
#line 1127 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 269:
#line 1133 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 270:
#line 1135 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 271:
#line 1137 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 272:
#line 1142 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 273:
#line 1144 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 274:
#line 1146 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 275:
#line 1148 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 276:
#line 1153 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 277:
#line 1155 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 278:
#line 1157 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 279:
#line 1161 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 280:
#line 1163 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 281:
#line 1165 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 282:
#line 1167 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 283:
#line 1169 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 284:
#line 1171 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 285:
#line 1173 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 286:
#line 1175 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 287:
#line 1177 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 288:
#line 1179 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 289:
#line 1181 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 290:
#line 1183 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 291:
#line 1185 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 292:
#line 1187 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 293:
#line 1189 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 294:
#line 1191 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 295:
#line 1193 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 296:
#line 1195 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 297:
#line 1197 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 298:
#line 1199 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 299:
#line 1204 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 300:
#line 1206 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 301:
#line 1208 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 302:
#line 1210 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 303:
#line 1212 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 304:
#line 1214 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 305:
#line 1216 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 306:
#line 1218 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 307:
#line 1220 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 308:
#line 1222 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 309:
#line 1224 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 310:
#line 1226 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 311:
#line 1228 "javaa.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].Rk).terminal;;}
    break;

  case 312:
#line 1232 "javaa.y"
    { (yyval.intval) = (yyvsp[(1) - (1)].intval);;}
    break;

  case 313:
#line 1234 "javaa.y"
    { (yyval.intval) = GetLocalVar((yyvsp[(1) - (1)].string));;}
    break;

  case 314:
#line 1238 "javaa.y"
    { (yyval.lookuplistptr) = AddToLookupList((yyvsp[(4) - (4)].lookuplistptr),(yyvsp[(1) - (4)].intval),(yyvsp[(3) - (4)].string)); ;}
    break;

  case 315:
#line 1239 "javaa.y"
    {(yyval.lookuplistptr) = NULL;;}
    break;

  case 316:
#line 1243 "javaa.y"
    { (yyval.tablelistptr) = AddToTableList((yyvsp[(2) - (2)].tablelistptr),(yyvsp[(1) - (2)].string)); ;}
    break;

  case 317:
#line 1244 "javaa.y"
    {(yyval.tablelistptr) = NULL;;}
    break;

  case 318:
#line 1249 "javaa.y"
    { (yyval.intval) = 4;;}
    break;

  case 319:
#line 1251 "javaa.y"
    { (yyval.intval) = 5;;}
    break;

  case 320:
#line 1253 "javaa.y"
    { (yyval.intval) = 6;;}
    break;

  case 321:
#line 1255 "javaa.y"
    { (yyval.intval) = 7;;}
    break;

  case 322:
#line 1257 "javaa.y"
    { (yyval.intval) = 8;;}
    break;

  case 323:
#line 1259 "javaa.y"
    { (yyval.intval) = 9;;}
    break;

  case 324:
#line 1261 "javaa.y"
    { (yyval.intval) = 10;;}
    break;

  case 325:
#line 1263 "javaa.y"
    { (yyval.intval) = 11;;}
    break;

  case 326:
#line 1267 "javaa.y"
    {(yyval.argtype).type = IDENTIFIER;
              (yyval.argtype).stringval = (yyvsp[(1) - (1)].string);
             ;}
    break;

  case 327:
#line 1271 "javaa.y"
    {(yyval.argtype).type = INTCONSTANT;
              (yyval.argtype).intval = (yyvsp[(1) - (1)].intval);
             ;}
    break;

  case 328:
#line 1275 "javaa.y"
    {(yyval.argtype).type = LONGCONSTANT;
              (yyval.argtype).longval = (yyvsp[(1) - (1)].longval);
             ;}
    break;

  case 329:
#line 1279 "javaa.y"
    {(yyval.argtype).type = STRING_LITERAL;
              (yyval.argtype).stringval = (yyvsp[(1) - (1)].string);
             ;}
    break;

  case 330:
#line 1283 "javaa.y"
    {(yyval.argtype).type = FLOATCONSTANT;
              (yyval.argtype).floatval = (yyvsp[(1) - (1)].floatval);
	      /*message("got a float constant.");*/
             ;}
    break;

  case 331:
#line 1288 "javaa.y"
    {(yyval.argtype).type = DOUBLECONSTANT;
              (yyval.argtype).doubleval = (yyvsp[(1) - (1)].doubleval);
	      /*message("got a double constant.");*/
             ;}
    break;

  case 332:
#line 1296 "javaa.y"
    { break; ;}
    break;

  case 333:
#line 1297 "javaa.y"
    {break;;}
    break;

  case 334:
#line 1301 "javaa.y"
    { AddToExceptionList((yyvsp[(2) - (5)].string),(yyvsp[(3) - (5)].string),(yyvsp[(4) - (5)].string),(yyvsp[(5) - (5)].string)); ;}
    break;

  case 335:
#line 1303 "javaa.y"
    { 
		  if ((yyvsp[(5) - (5)].intval) != 0) oops("Must have a class name or 0 here.");
	          AddToExceptionList((yyvsp[(2) - (5)].string),(yyvsp[(3) - (5)].string),(yyvsp[(4) - (5)].string),NULL); 
		;}
    break;

  case 336:
#line 1307 "javaa.y"
    {break;;}
    break;

  case 337:
#line 1312 "javaa.y"
    { break; ;}
    break;

  case 338:
#line 1313 "javaa.y"
    {break;;}
    break;

  case 339:
#line 1317 "javaa.y"
    { AddToLineNumberList((yyvsp[(2) - (3)].string),(yyvsp[(3) - (3)].intval)); ;}
    break;

  case 340:
#line 1318 "javaa.y"
    {break;;}
    break;

  case 341:
#line 1323 "javaa.y"
    { break; ;}
    break;

  case 342:
#line 1324 "javaa.y"
    {break;;}
    break;

  case 343:
#line 1329 "javaa.y"
    { AddToUserLocalVarList((yyvsp[(2) - (6)].string),(yyvsp[(3) - (6)].string),(yyvsp[(4) - (6)].string),(yyvsp[(5) - (6)].string),(yyvsp[(6) - (6)].intval)); ;}
    break;

  case 344:
#line 1330 "javaa.y"
    {break;;}
    break;

  case 345:
#line 1335 "javaa.y"
    { SetSourceFile((yyvsp[(2) - (2)].string)); ;}
    break;

  case 346:
#line 1336 "javaa.y"
    {break;;}
    break;


/* Line 1267 of yacc.c.  */
#line 4360 "javaa.tab.c"
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


#line 1338 "javaa.y"


