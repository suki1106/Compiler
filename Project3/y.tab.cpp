/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "y.y" /* yacc.c:339  */

#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>
#include <fstream>

#include "symbols.hpp"
#include "lex.yy.cpp"


using namespace std;

void yyerror(string s);
#define Trace(t)        printf("%s\n",t);

string out_name;
ofstream out_f;

vector<arg_info> args_info;
vector<Info> params; // deal with function invocation
Symboltable_List stb_list;

int result_stmt = 0;

int counter_local_var = 0; // for project3
int label_index=0;
stack<int> st_label;
stack<Info*> st_id; // used in for loop

//int label_used=0;




bool isConst_Exp = 0;



#line 106 "y.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.hpp".  */
#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AS = 258,
    VAR = 259,
    CONST = 260,
    FUNCTION = 261,
    BOOL = 262,
    REAL = 263,
    INT = 264,
    STRING = 265,
    ARRAY = 266,
    OF = 267,
    CHAR = 268,
    MOD = 269,
    AND = 270,
    OR = 271,
    NOT = 272,
    DECREASING = 273,
    DEFAULT = 274,
    DO = 275,
    ELSE = 276,
    END = 277,
    EXIT = 278,
    FOR = 279,
    GET = 280,
    IF = 281,
    LOOP = 282,
    PUT = 283,
    PROCEDURE = 284,
    RESULT = 285,
    RETURN = 286,
    SKIP = 287,
    THEN = 288,
    WHEN = 289,
    BEG = 290,
    LE = 291,
    GE = 292,
    NE = 293,
    ID = 294,
    val_STR = 295,
    val_INTEGER = 296,
    val_REAL = 297,
    val_BOOL = 298,
    UMINUS = 299
  };
#endif
/* Tokens.  */
#define AS 258
#define VAR 259
#define CONST 260
#define FUNCTION 261
#define BOOL 262
#define REAL 263
#define INT 264
#define STRING 265
#define ARRAY 266
#define OF 267
#define CHAR 268
#define MOD 269
#define AND 270
#define OR 271
#define NOT 272
#define DECREASING 273
#define DEFAULT 274
#define DO 275
#define ELSE 276
#define END 277
#define EXIT 278
#define FOR 279
#define GET 280
#define IF 281
#define LOOP 282
#define PUT 283
#define PROCEDURE 284
#define RESULT 285
#define RETURN 286
#define SKIP 287
#define THEN 288
#define WHEN 289
#define BEG 290
#define LE 291
#define GE 292
#define NE 293
#define ID 294
#define val_STR 295
#define val_INTEGER 296
#define val_REAL 297
#define val_BOOL 298
#define UMINUS 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 41 "y.y" /* yacc.c:355  */

    int i_v;
    bool b_v;
    string* s_v;
    double r_v;
    data_type d_t;
    Info* Inf;

#line 243 "y.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 260 "y.tab.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   308

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      54,    55,    49,    48,    56,    47,    53,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,     2,
      44,    45,    46,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    81,    81,    85,    81,   105,   106,   109,   110,   114,
     115,   116,   119,   119,   131,   131,   148,   149,   150,   151,
     161,   162,   163,   164,   167,   183,   183,   204,   204,   227,
     238,   237,   291,   290,   335,   336,   341,   342,   343,   346,
     347,   348,   351,   359,   360,   361,   362,   365,   364,   376,
     390,   389,   401,   411,   422,   427,   428,   434,   437,   444,
     456,   475,   494,   513,   531,   540,   554,   582,   607,   634,
     659,   684,   709,   724,   737,   752,   756,   777,   812,   822,
     825,   859,   889,   890,   891,   894,   902,   901,   924,   923,
     947,   967,   973,   966,   986,   987,  1052,   986,  1096,  1097
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AS", "VAR", "CONST", "FUNCTION", "BOOL",
  "REAL", "INT", "STRING", "ARRAY", "OF", "CHAR", "MOD", "AND", "OR",
  "NOT", "DECREASING", "DEFAULT", "DO", "ELSE", "END", "EXIT", "FOR",
  "GET", "IF", "LOOP", "PUT", "PROCEDURE", "RESULT", "RETURN", "SKIP",
  "THEN", "WHEN", "BEG", "LE", "GE", "NE", "ID", "val_STR", "val_INTEGER",
  "val_REAL", "val_BOOL", "'<'", "'='", "'>'", "'-'", "'+'", "'*'", "'/'",
  "UMINUS", "':'", "'.'", "'('", "')'", "','", "'['", "']'", "$accept",
  "program", "$@1", "$@2", "dec_stmts", "stmts", "dec_stmt", "const_dec",
  "$@3", "$@4", "const_val", "TYPE", "var_dec", "$@5", "$@6", "func_dec",
  "$@7", "$@8", "func_stmts", "func_stmt", "args", "arg", "stmt",
  "BLOCK_stmt", "$@9", "simple_stmt", "$@10", "EXIT_STMT", "EXPRESSION",
  "func_inv", "proc_inv", "actual_params", "actual_param",
  "conditional_stmt", "$@11", "ELSE_stmt", "$@12", "loop_stmt", "$@13",
  "$@14", "$@15", "$@16", "$@17", "opt_r", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    60,    61,    62,    45,    43,    42,
      47,   299,    58,    46,    40,    41,    44,    91,    93
};
# endif

#define YYPACT_NINF -90

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-90)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -90,    24,    15,   -90,   -30,   -26,   -14,   -11,   -90,    15,
     -90,   -90,   -90,     3,     5,   -22,   -13,   269,   -90,   -90,
      80,   -90,    91,    11,    11,    25,    29,    19,    -5,   -90,
     -90,    -5,   -90,   -90,   -90,     2,   -90,   269,   -90,   -90,
     -90,   -90,   -90,   -90,    -5,   -90,   -90,   -90,   -90,    40,
      62,    -5,    67,    -9,    27,    36,    41,    -5,   -90,    56,
     -90,    -5,   -43,   -90,   -90,   -90,   -90,    -5,    -5,   -90,
     162,   -90,   252,    -5,   177,   252,    -5,    -5,   -90,   177,
      49,   -90,   177,   -90,    91,    52,    11,   -90,   177,    57,
     217,    -5,    -5,   -90,   120,    -5,    -5,    -5,   -90,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,   -90,
     -90,   -90,   252,   -90,   177,    88,   177,   177,    58,    55,
      59,    -5,    -5,   -90,    91,   -90,   252,   -90,    66,    70,
     -90,   -90,   217,   202,   252,     4,     4,     4,     4,     4,
       4,    12,    12,   -90,   -90,   100,   -90,   -90,   -90,    -5,
      82,   177,   177,   -90,   102,    -5,   -90,   -90,     9,    98,
     -90,   114,   252,    90,   136,   -90,   104,   -90,   -90,    91,
     109,   -90,    79,   252,   -90,   -90,    99,    -5,   115,   -90,
     177,   113,   252,   -90,   -90,   118,   117,   -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     6,     1,     0,     0,     0,     0,     3,     6,
      10,     9,    11,     0,     0,     0,     0,     8,     5,    27,
       0,    12,     0,    41,    41,    58,    99,     0,     0,    91,
      50,     0,    54,    56,    47,     0,     4,     8,    43,    44,
      55,    57,    45,    46,     0,    21,    23,    20,    22,     0,
      24,     0,     0,     0,     0,    40,     0,     0,    98,     0,
      52,     0,    77,    18,    17,    16,    19,     0,     0,    76,
       0,    79,    35,     0,    53,    35,     0,    84,     7,    28,
       0,    25,    13,    14,     0,     0,    41,    32,    59,     0,
      74,    84,     0,    64,     0,     0,     0,     0,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      36,    92,    35,    38,    51,     0,    49,    85,     0,    83,
       0,     0,     0,    42,     0,    39,    35,    94,     0,     0,
      75,    65,    72,    73,    35,    70,    71,    69,    67,    68,
      66,    61,    60,    62,    63,     0,    34,    48,    81,    84,
       0,    26,    15,    30,     0,     0,    80,    78,     0,     0,
      82,     0,    35,     0,     0,    88,     0,    87,    93,     0,
       0,    33,     0,    35,    90,    29,     0,     0,     0,    31,
      95,     0,    35,    89,    96,     0,     0,    97
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   -90,   -90,   -90,   133,   106,   -90,     8,   -90,   -90,
     -90,   -21,    13,   -90,   -90,   -90,   -90,   -90,   -29,   -90,
     -20,   -90,   -10,   -90,   -90,   -90,   -90,   -90,   -28,   -90,
     -90,   -89,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   -90,   -90,   -90
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    17,     8,    36,     9,   109,    51,   122,
      69,    50,   110,   121,    44,    12,   162,   126,   111,   112,
      54,    55,   113,    38,    75,    39,    73,    40,   117,    71,
      41,   118,   119,    42,   134,   167,   173,    43,    72,   145,
     155,   182,   185,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      70,    52,   128,    74,    56,    76,    19,    37,    21,    13,
      10,    91,    61,    14,    92,    11,    79,    10,    95,     4,
       5,     6,    11,    82,     3,    15,    95,    37,    16,    88,
     165,   166,    23,    90,    62,    63,    64,    65,    66,    93,
      94,    24,    67,    84,     7,   114,   115,    58,   116,    68,
      53,   105,   106,   107,   108,    20,    77,    22,    60,    57,
     160,   107,   108,   123,   129,    81,   125,   131,   132,   133,
      83,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    80,    85,   146,    95,    96,    97,    45,    46,    47,
      48,    49,    86,   151,   152,    89,    87,   154,    45,    46,
      47,    48,   120,   153,   124,   158,    99,   100,   101,   127,
     147,   149,   150,   148,   102,   103,   104,   105,   106,   107,
     108,   156,   159,   161,   163,   168,   169,   164,   157,   171,
     174,   176,   177,   170,    95,    96,    97,   181,   179,   183,
     186,   187,    18,    78,   178,     0,     0,     0,   175,   180,
      95,    96,    97,   184,     0,     0,    99,   100,   101,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     108,     0,    99,   100,   101,   130,    95,    96,    97,     0,
     102,   103,   104,   105,   106,   107,   108,     0,     0,   172,
       0,    95,    96,    97,     0,    98,     0,     0,    99,   100,
     101,     0,     0,     0,     0,     0,   102,   103,   104,   105,
     106,   107,   108,    99,   100,   101,    95,    96,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,    95,     0,     0,     0,     0,     0,     0,    99,   100,
     101,     0,     0,     0,     0,     0,   102,   103,   104,   105,
     106,   107,   108,    99,   100,   101,     4,     5,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,     0,     0,     0,     0,    25,    26,    27,    28,    29,
      30,     0,    31,    32,    33,     0,     0,    34,     0,     0,
       0,    35,    25,    26,    27,    28,    29,    30,     0,    31,
      32,    33,     0,     0,    34,     0,     0,     0,    35
};

static const yytype_int16 yycheck[] =
{
      28,    22,    91,    31,    24,     3,     3,    17,     3,    39,
       2,    54,    17,    39,    57,     2,    44,     9,    14,     4,
       5,     6,     9,    51,     0,    39,    14,    37,    39,    57,
      21,    22,    54,    61,    39,    40,    41,    42,    43,    67,
      68,    54,    47,    52,    29,    73,    75,    18,    76,    54,
      39,    47,    48,    49,    50,    52,    54,    52,    39,    34,
     149,    49,    50,    84,    92,     3,    86,    95,    96,    97,
       3,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    41,    55,   112,    14,    15,    16,     7,     8,     9,
      10,    11,    56,   121,   122,    39,    55,   126,     7,     8,
       9,    10,    53,   124,    52,   134,    36,    37,    38,    52,
      22,    56,    53,    55,    44,    45,    46,    47,    48,    49,
      50,    55,    22,    41,    22,    27,    12,   155,    58,    39,
      26,    22,    53,   162,    14,    15,    16,    22,    39,    26,
      22,    24,     9,    37,   173,    -1,    -1,    -1,   169,   177,
      14,    15,    16,   182,    -1,    -1,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    -1,    36,    37,    38,    55,    14,    15,    16,    -1,
      44,    45,    46,    47,    48,    49,    50,    -1,    -1,    53,
      -1,    14,    15,    16,    -1,    33,    -1,    -1,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    36,    37,    38,    14,    15,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    36,    37,    38,     4,     5,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    -1,    30,    31,    32,    -1,    -1,    35,    -1,    -1,
      -1,    39,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    32,    -1,    -1,    35,    -1,    -1,    -1,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    60,    61,     0,     4,     5,     6,    29,    63,    65,
      66,    71,    74,    39,    39,    39,    39,    62,    63,     3,
      52,     3,    52,    54,    54,    23,    24,    25,    26,    27,
      28,    30,    31,    32,    35,    39,    64,    81,    82,    84,
      86,    89,    92,    96,    73,     7,     8,     9,    10,    11,
      70,    67,    70,    39,    79,    80,    79,    34,    18,   102,
      39,    17,    39,    40,    41,    42,    43,    47,    54,    69,
      87,    88,    97,    85,    87,    83,     3,    54,    64,    87,
      41,     3,    87,     3,    52,    55,    56,    55,    87,    39,
      87,    54,    57,    87,    87,    14,    15,    16,    33,    36,
      37,    38,    44,    45,    46,    47,    48,    49,    50,    66,
      71,    77,    78,    81,    87,    77,    87,    87,    90,    91,
      53,    72,    68,    70,    52,    79,    76,    52,    90,    87,
      55,    87,    87,    87,    93,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    98,    77,    22,    55,    56,
      53,    87,    87,    70,    77,    99,    55,    58,    77,    22,
      90,    41,    75,    22,    87,    21,    22,    94,    27,    12,
      77,    39,    53,    95,    26,    70,    22,    53,    77,    39,
      87,    22,   100,    26,    77,   101,    22,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    61,    62,    60,    63,    63,    64,    64,    65,
      65,    65,    67,    66,    68,    66,    69,    69,    69,    69,
      70,    70,    70,    70,    71,    72,    71,    73,    71,    71,
      75,    74,    76,    74,    77,    77,    78,    78,    78,    79,
      79,    79,    80,    81,    81,    81,    81,    83,    82,    84,
      85,    84,    84,    84,    84,    84,    84,    84,    86,    86,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      88,    89,    90,    90,    90,    91,    93,    92,    95,    94,
      94,    97,    98,    96,    99,   100,   101,    96,   102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     4,     2,     0,     2,     0,     1,
       1,     1,     0,     5,     0,     7,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     0,     7,     0,     5,    10,
       0,    11,     0,     9,     2,     0,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     0,     4,     3,
       0,     3,     2,     2,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     1,     1,     4,     1,
       4,     4,     3,     1,     0,     1,     0,     6,     0,     5,
       2,     0,     0,     6,     0,     0,     0,    14,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 81 "y.y" /* yacc.c:1646  */
    {
            out_f << "class " << out_name.substr(0,out_name.find(".")) << "\n{\n";
        }
#line 1497 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 85 "y.y" /* yacc.c:1646  */
    {
            // enter main block
            counter_local_var=0;

            out_f << "\tmethod public static void main(java.lang.String[])\n";
            out_f << "\tmax_stack 30\n";
            out_f << "\tmax_locals 30\n";
            out_f << "\t{\n";

        }
#line 1512 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 96 "y.y" /* yacc.c:1646  */
    {
            out_f << "\t\treturn\n";
            out_f << "\t}\n";
            out_f << "}";
            out_f.close();
        }
#line 1523 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 119 "y.y" /* yacc.c:1646  */
    {isConst_Exp=1;}
#line 1529 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 120 "y.y" /* yacc.c:1646  */
    {
            Trace("constant declaration without type declaration");
            if((yyvsp[0].Inf)->f_type != CONST_f) yyerror("<ERROR> expression should be constant");
            //$4->name = *$2;
            Info tmp = *(yyvsp[0].Inf);
            tmp.name = *(yyvsp[-3].s_v);
            Symboltable* tb = stb_list.getCurrentTable();
            if(tb->Insert(tmp) ==-1)yyerror("<ERROR> identifier already exists");
            isConst_Exp=0;
            //tb.dump();
        }
#line 1545 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 131 "y.y" /* yacc.c:1646  */
    {isConst_Exp=1;}
#line 1551 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 132 "y.y" /* yacc.c:1646  */
    {
            Trace("constant declaration with type declaration");
            if((yyvsp[0].Inf)->f_type != CONST_f) yyerror("<ERROR> expression should be constant");
            // check expression type
            if((yyvsp[0].Inf)->d_type != (yyvsp[-3].d_t)) yyerror("type is not compatible");
            //$6->name = *$2;
            Info tmp = *(yyvsp[0].Inf);
            tmp.name = *(yyvsp[-5].s_v);
            tmp.d_type = (yyvsp[-3].d_t);
            Symboltable* tb = stb_list.getCurrentTable();
            if(tb->Insert(tmp) ==-1)yyerror("<ERROR> identifier already exists");
            isConst_Exp=0;
            //tb.dump();
        }
#line 1570 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 148 "y.y" /* yacc.c:1646  */
    {(yyval.Inf) = new Info("",REAL_TYPE,CONST_f,(yyvsp[0].r_v));}
#line 1576 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 149 "y.y" /* yacc.c:1646  */
    {(yyval.Inf)= new Info("",INT_TYPE,CONST_f,(yyvsp[0].i_v));}
#line 1582 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 150 "y.y" /* yacc.c:1646  */
    {(yyval.Inf)=new Info("",STR_TYPE,CONST_f,(yyvsp[0].s_v));}
#line 1588 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 151 "y.y" /* yacc.c:1646  */
    {(yyval.Inf)=new Info("",BOOL_TYPE,CONST_f,(yyvsp[0].b_v));}
#line 1594 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 161 "y.y" /* yacc.c:1646  */
    {(yyval.d_t) = INT_TYPE;}
#line 1600 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 162 "y.y" /* yacc.c:1646  */
    {(yyval.d_t) = BOOL_TYPE;}
#line 1606 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 163 "y.y" /* yacc.c:1646  */
    {(yyval.d_t)=STR_TYPE;}
#line 1612 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 164 "y.y" /* yacc.c:1646  */
    {(yyval.d_t)=REAL_TYPE;}
#line 1618 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 168 "y.y" /* yacc.c:1646  */
    {
            Trace("variable declaration without value initialization");
            Symboltable* tb = stb_list.getCurrentTable();
            //cout << "this is S2:" << *($2) << endl;
            //tb->dump();
            if(tb->Insert(Info(*((yyvsp[-2].s_v)),(yyvsp[0].d_t),VAR_f))  == -1) yyerror("<ERROR> identifier already exists"); 
            if(stb_list.isGlobal()){
                cout << "\t" << "field static " << getType((yyvsp[0].d_t)) << " " << *(yyvsp[-2].s_v) << "\n";
                out_f << "\t" << "field static " << getType((yyvsp[0].d_t)) << " " << *(yyvsp[-2].s_v) << "\n"; // global
            }else{
                Info* data = tb->getInfo(tb->lookup(*(yyvsp[-2].s_v)));
                data->index_local = counter_local_var++;
            }
            tb->dump();
        }
#line 1638 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 183 "y.y" /* yacc.c:1646  */
    {isConst_Exp=1;}
#line 1644 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 184 "y.y" /* yacc.c:1646  */
    {
            Trace("variable declaration with value initialization and type");
            isConst_Exp=0;
            Info tmp = *(yyvsp[0].Inf);
            if(tmp.d_type != (yyvsp[-3].d_t))  yyerror("<ERROR> Type not compatible");
            if(tmp.f_type != CONST_f) yyerror("<ERROR> expression should be constant_expr");
            Symboltable* tb = stb_list.getCurrentTable();
            tmp.name = *(yyvsp[-5].s_v);
            tmp.f_type = VAR_f;
            if(tb->Insert(tmp)  == -1) yyerror("<ERROR> identifier already exists");
            if(stb_list.isGlobal()){
                out_f << "\t" << "field static " << getType((yyvsp[-3].d_t)) << " " << *(yyvsp[-5].s_v) << " = " << getValue_IntBool(tmp) <<"\n";
            }else{
                Info* data = tb->getInfo(tb->lookup(*(yyvsp[-5].s_v)));
                data->index_local = counter_local_var;
                out_f << "\t\t" << "sipush " << getValue_IntBool(*data) <<"\n";
                out_f << "\t\t" << "istore " << counter_local_var << "\n";
                ++counter_local_var;
            }
        }
#line 1669 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 204 "y.y" /* yacc.c:1646  */
    {isConst_Exp=1;}
#line 1675 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 205 "y.y" /* yacc.c:1646  */
    {
            Trace("variable declaration iwth value initialization but not type");
            isConst_Exp=0;
            //$4->name = *$2;
            //$4->f_type = VAR_f;
            Info tmp = *(yyvsp[0].Inf);
            if(tmp.f_type != CONST_f) yyerror("<ERROR> expression should be constant_expr");
            tmp.name = *(yyvsp[-3].s_v);
            tmp.f_type = VAR_f;
            
            Symboltable* tb = stb_list.getCurrentTable();
            if(tb->Insert(tmp) == -1)yyerror("<ERROR> identifier already exists");
            if(stb_list.isGlobal()){
                out_f << "\t" << "field static " << getType(tmp.d_type) << " " << *(yyvsp[-3].s_v) << " = " << getValue_IntBool(tmp) <<"\n";
            }else{
                Info* data = tb->getInfo(tb->lookup(*(yyvsp[-3].s_v)));
                data->index_local = counter_local_var;
                out_f << "\t\t" << "sipush " << getValue_IntBool(*data) <<"\n";
                out_f << "\t\t" << "istore " << counter_local_var << "\n";
                ++counter_local_var;
            }
        }
#line 1702 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 228 "y.y" /* yacc.c:1646  */
    {
            Trace("Array declaration");
            Symboltable* tb = stb_list.getCurrentTable();
            Info tmp = Info(*((yyvsp[-8].s_v)), (yyvsp[0].d_t),ARRAY_f);
            tmp.size = (yyvsp[-2].i_v) - (yyvsp[-5].i_v) +1; // store array size
            if(tb->Insert(tmp) == -1)yyerror("<ERROR> identifier already exists");
        }
#line 1714 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 238 "y.y" /* yacc.c:1646  */
    {
            //if(*$2 != *$11) yyerror("<ERROR> Func declaration error");
            Trace("Func declaration");

            Symboltable* tb = stb_list.getCurrentTable();
            if(tb->Insert(Info(*(yyvsp[-5].s_v),(yyvsp[0].d_t),FUNC_f,args_info) ) ==-1)yyerror("<ERROR> identifier already exists");
            
            // create new symbol table and switch

            stb_list.create_table();
            tb = stb_list.getCurrentTable(); 

            for(auto& arg:args_info){
                Info data = Info(arg.name,arg.d_type,VAR_f);
                cout << "local_var:" <<counter_local_var << "\n";
                data.index_local = counter_local_var++;
                //cout << data.index_local;
                tb->Insert(data); // insert arg into table
            }
            //tb->printTableSize();
            tb->dump();

            out_f << "method public static int " << *(yyvsp[-5].s_v) << "(";

            for(int i = 0 ; i != args_info.size();i++){
                out_f << getType(args_info[i].d_type);
                if(i != args_info.size()-1)out_f << ",";
            }
            out_f << ")\n";

            
            out_f << "\tmax_stack 30\n";
            out_f << "\tmax_locals 30\n";
            out_f << "\t{\n";


            args_info.clear();
        }
#line 1757 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 277 "y.y" /* yacc.c:1646  */
    {
            if(*(yyvsp[-9].s_v) != *(yyvsp[0].s_v)) yyerror("<ERROR> Func declaration error");
            //check result expression ?
            if(result_stmt == 0) yyerror("<ERROR> Function should return value");
            
            result_stmt=0;
            counter_local_var=0;
            //stb_list.dumpCurrentTable();

            out_f << "\t}\n";
            
            stb_list.popTable();
        }
#line 1775 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 291 "y.y" /* yacc.c:1646  */
    {
            Trace("procedure declaration");
            // new symbol table
            Symboltable* tb = stb_list.getCurrentTable();
            if( tb->Insert(Info(*(yyvsp[-3].s_v),VOID_TYPE,FUNC_f,args_info)) ==-1) yyerror("<ERROR> identifier already exists");
            
            //create new table and switch, store args info in new table
            stb_list.create_table();
            tb = stb_list.getCurrentTable();

            for(auto& arg:args_info){
                Info data = Info(arg.name,arg.d_type,VAR_f);
                data.index_local = counter_local_var++;
                tb->Insert(data); // insert arg into table
            }

            out_f << "method public static void " << *(yyvsp[-3].s_v) << "(";

            for(int i = 0 ; i != args_info.size();i++){
                out_f << getType(args_info[i].d_type);
                if(i != args_info.size()-1)out_f << ",";
            }


            out_f << ")\n";

            
            out_f << "\tmax_stack 30\n";
            out_f << "\tmax_locals 30\n";
            out_f << "\t{\n";
            args_info.clear();
            
        }
#line 1813 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 324 "y.y" /* yacc.c:1646  */
    {
            if(*(yyvsp[-7].s_v) != *(yyvsp[0].s_v)) yyerror("<ERROR> Procedure declaration error");

            counter_local_var=0;
            //stb_list.dumpCurrentTable();
            out_f << "\t}\n";
            stb_list.popTable();
        }
#line 1826 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 352 "y.y" /* yacc.c:1646  */
    {
        args_info.push_back(arg_info(*(yyvsp[-2].s_v),(yyvsp[0].d_t)));
    }
#line 1834 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 365 "y.y" /* yacc.c:1646  */
    {
            stb_list.create_table();
        }
#line 1842 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 367 "y.y" /* yacc.c:1646  */
    {
            Trace("find block stmt");
            // BLOCK ends, call popTable
            stb_list.dumpCurrentTable();
            stb_list.popTable();
        }
#line 1853 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 377 "y.y" /* yacc.c:1646  */
    {
                Trace("Assign value to ID");
                Info* id = stb_list.lookup(*(yyvsp[-2].s_v));
                if(id == NULL) yyerror("<ERROR> identifier not exists");
                if(id->f_type == CONST_f) yyerror("const variable can not be assigned");
                if(sameType(*id,*(yyvsp[0].Inf)) == 0) yyerror("type is not compatible"); // array?
                if(id->isGlobalVar == 1){
                    out_f << "putstatic " << getType(id->d_type) << " " << out_name.substr(0,out_name.find(".")) + "." + *(yyvsp[-2].s_v) << "\n";
                }else{
                    out_f << "istore " << id->index_local << "\n";
                }
            }
#line 1870 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 390 "y.y" /* yacc.c:1646  */
    {
                out_f << "getstatic java.io.PrintStream java.lang.System.out\n";
            }
#line 1878 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 393 "y.y" /* yacc.c:1646  */
    {
                Trace("Find PUT");
                if((yyvsp[0].Inf)->d_type ==INT_TYPE || (yyvsp[0].Inf)->d_type == BOOL_TYPE){
                    out_f << "invokevirtual void java.io.PrintStream.print(int)\n";
                }else{ // string
                    out_f << "invokevirtual void java.io.PrintStream.print(java.lang.String)\n";
                }
            }
#line 1891 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 402 "y.y" /* yacc.c:1646  */
    {
                Trace("Find GET");
                //Symboltable* tb = stb_list.getCurrentTable();
                //int idx=tb->lookup(*$2);
                //if(idx == -1) yyerror("<ERROR> identifier not exists");
                Info* id = stb_list.lookup(*(yyvsp[0].s_v));
                if(id == NULL) yyerror("<ERROR> identifier not exists");
                //Info* id = tb->getInfo(idx);
            }
#line 1905 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 412 "y.y" /* yacc.c:1646  */
    {
                Trace("Find result");
                result_stmt = 1;
                Info* func_info = stb_list.getFunc();
                if(func_info== NULL || func_info->f_type != FUNC_f) yyerror("could't find function declaration");
                if((yyvsp[0].Inf)->d_type != func_info->d_type)yyerror("function return type is not compatible");
                // check function type

                out_f << "ireturn\n";
            }
#line 1920 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 423 "y.y" /* yacc.c:1646  */
    {
                Trace("Find RETURN");
                out_f << "return\n";
            }
#line 1929 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 429 "y.y" /* yacc.c:1646  */
    {
                Trace("Find skip");
                out_f << "getstatic java.io.PrintStream java.lang.System.out\n";
                out_f << "invokevirtual void java.io.PrintStream.println()\n";
            }
#line 1939 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 438 "y.y" /* yacc.c:1646  */
    {
                Trace("Find EXIT");

                int index=st_label.top();
                out_f << "goto L" << index+1 << "\n";
            }
#line 1950 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 445 "y.y" /* yacc.c:1646  */
    {
                Trace("Find EXIT with expression");
                if((yyvsp[0].Inf)->d_type != BOOL_TYPE)yyerror("<ERROR> EXIT WHEN EXPRESSION, EXPRESSION SHOULD BE BOOL_EXPR");

                int index=st_label.top();
                out_f << "ifne L" << index+1 << "\n";


            }
#line 1964 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 457 "y.y" /* yacc.c:1646  */
    {
                Trace("expression + expression");
                if((yyvsp[-2].Inf)->d_type != (yyvsp[0].Inf)->d_type) yyerror("Type not compatible");
                //stb_list.dumpCurrentTable();
                if((yyvsp[-2].Inf)->d_type != REAL_TYPE && (yyvsp[-2].Inf)->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if((yyvsp[-2].Inf)->f_type == ARRAY_f || (yyvsp[0].Inf)->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if((yyvsp[-2].Inf)->f_type == CONST_f && (yyvsp[0].Inf)->f_type == CONST_f){
                    if((yyvsp[-2].Inf)->d_type == INT_TYPE){
                        (yyval.Inf) = new Info("",INT_TYPE,CONST_f,((yyvsp[-2].Inf)->i_v+(yyvsp[0].Inf)->i_v));
                    }else{ 
                        //real type
                        (yyval.Inf) = new Info("",REAL_TYPE,CONST_f,((yyvsp[-2].Inf)->r_v+(yyvsp[0].Inf)->r_v));
                    }
                }else{
                    (yyval.Inf) = new Info("",(yyvsp[-2].Inf)->d_type,VAR_f);
                }
                if(!isConst_Exp)out_f << "iadd\n";
            }
#line 1987 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 476 "y.y" /* yacc.c:1646  */
    {
                Trace("expression - expression");
                if((yyvsp[-2].Inf)->d_type != (yyvsp[0].Inf)->d_type) yyerror("Type not compatible");
                if((yyvsp[-2].Inf)->d_type != REAL_TYPE && (yyvsp[-2].Inf)->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if((yyvsp[-2].Inf)->f_type == ARRAY_f || (yyvsp[0].Inf)->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                
                if((yyvsp[-2].Inf)->f_type == CONST_f && (yyvsp[0].Inf)->f_type == CONST_f){
                    if((yyvsp[-2].Inf)->d_type == INT_TYPE){
                        (yyval.Inf) = new Info("",INT_TYPE,CONST_f,((yyvsp[-2].Inf)->i_v-(yyvsp[0].Inf)->i_v));
                    }else{ 
                        //real type
                        (yyval.Inf) = new Info("",REAL_TYPE,CONST_f,((yyvsp[-2].Inf)->r_v-(yyvsp[0].Inf)->r_v));
                    }
                }else{
                    (yyval.Inf) = new Info("",(yyvsp[-2].Inf)->d_type,VAR_f);
                }
                if(!isConst_Exp)out_f << "isub\n";
            }
#line 2010 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 495 "y.y" /* yacc.c:1646  */
    {
                Trace("expression * expression");
                if((yyvsp[-2].Inf)->d_type != (yyvsp[0].Inf)->d_type) yyerror("Type not compatible");
                if((yyvsp[-2].Inf)->d_type != REAL_TYPE && (yyvsp[-2].Inf)->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if((yyvsp[-2].Inf)->f_type == ARRAY_f || (yyvsp[0].Inf)->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                
                if((yyvsp[-2].Inf)->f_type == CONST_f && (yyvsp[0].Inf)->f_type == CONST_f){
                    if((yyvsp[-2].Inf)->d_type == INT_TYPE){
                        (yyval.Inf) = new Info("",INT_TYPE,CONST_f,((yyvsp[-2].Inf)->i_v*(yyvsp[0].Inf)->i_v));
                    }else{ 
                        //real type
                        (yyval.Inf) = new Info("",REAL_TYPE,CONST_f,((yyvsp[-2].Inf)->r_v*(yyvsp[0].Inf)->r_v));
                    }
                }else{
                    (yyval.Inf) = new Info("",(yyvsp[-2].Inf)->d_type,VAR_f);
                }
                if(!isConst_Exp)out_f << "imul\n";
            }
#line 2033 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 514 "y.y" /* yacc.c:1646  */
    {
                Trace("expression / expression");
                if((yyvsp[-2].Inf)->d_type != (yyvsp[0].Inf)->d_type) yyerror("Type not compatible");
                if((yyvsp[-2].Inf)->d_type != REAL_TYPE && (yyvsp[-2].Inf)->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if((yyvsp[-2].Inf)->f_type == ARRAY_f || (yyvsp[0].Inf)->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if((yyvsp[-2].Inf)->f_type == CONST_f && (yyvsp[0].Inf)->f_type == CONST_f){
                    if((yyvsp[-2].Inf)->d_type == INT_TYPE){
                        (yyval.Inf) = new Info("",INT_TYPE,CONST_f,((yyvsp[-2].Inf)->i_v/(yyvsp[0].Inf)->i_v));
                    }else{ 
                        //real type
                        (yyval.Inf) = new Info("",REAL_TYPE,CONST_f,((yyvsp[-2].Inf)->r_v/(yyvsp[0].Inf)->r_v));
                    }
                }else{
                    (yyval.Inf) = new Info("",(yyvsp[-2].Inf)->d_type,VAR_f);
                }
                if(!isConst_Exp)out_f << "idiv\n";
            }
#line 2055 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 532 "y.y" /* yacc.c:1646  */
    {
                Trace("- expression");
                if((yyvsp[0].Inf)->d_type != REAL_TYPE && (yyvsp[0].Inf)->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if((yyvsp[0].Inf)->f_type == ARRAY_f) yyerror("unary minus is not support array");

                (yyval.Inf) = ((yyvsp[0].Inf)->d_type == INT_TYPE) ? new Info("",INT_TYPE,(yyvsp[0].Inf)->f_type,-(yyvsp[0].Inf)->i_v): new Info("",REAL_TYPE,(yyvsp[0].Inf)->f_type,-(yyvsp[0].Inf)->r_v);
                if(!isConst_Exp)out_f << "ineg\n";
            }
#line 2068 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 541 "y.y" /* yacc.c:1646  */
    {
                Trace("expression mod expression");
                if((yyvsp[-2].Inf)->d_type != (yyvsp[0].Inf)->d_type) yyerror("Type not compatible");
                if((yyvsp[-2].Inf)->d_type != INT_TYPE) yyerror("Type should be INT");
                if((yyvsp[-2].Inf)->f_type == ARRAY_f || (yyvsp[0].Inf)->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if((yyvsp[-2].Inf)->f_type == CONST_f && (yyvsp[0].Inf)->f_type == CONST_f){
                    (yyval.Inf) = new Info("",INT_TYPE,CONST_f,((yyvsp[-2].Inf)->i_v%(yyvsp[0].Inf)->i_v));
                }else{
                    (yyval.Inf) = new Info("",INT_TYPE,VAR_f);
                }

                if(!isConst_Exp)out_f << "irem\n";
            }
#line 2086 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 555 "y.y" /* yacc.c:1646  */
    {
                Trace("EXPRESSION > EXPRESSION");
                if((yyvsp[-2].Inf)->d_type != (yyvsp[0].Inf)->d_type) yyerror("Type not compatible");
                if((yyvsp[-2].Inf)->d_type != REAL_TYPE && (yyvsp[-2].Inf)->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if((yyvsp[-2].Inf)->f_type == ARRAY_f || (yyvsp[0].Inf)->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if((yyvsp[-2].Inf)->f_type == CONST_f && (yyvsp[0].Inf)->f_type == CONST_f){
                    if((yyvsp[-2].Inf)->d_type== INT_TYPE){
                        (yyval.Inf) = new Info("",BOOL_TYPE,CONST_f,((yyvsp[-2].Inf)->i_v > (yyvsp[0].Inf)->i_v));
                    }else{
                        (yyval.Inf) = new Info("",BOOL_TYPE,CONST_f,((yyvsp[-2].Inf)->r_v > (yyvsp[0].Inf)->r_v));
                    }
                }else{
                    (yyval.Inf) = new Info("",BOOL_TYPE,VAR_f);
                }


                if(!isConst_Exp){
                    out_f << "isub\n";
                    out_f << "ifgt L" << label_index << "\n";
                    out_f << "iconst_0" << "\n";
                    out_f << "goto L" << label_index+1 << "\n";
                    out_f << "L" << label_index << ": iconst_1\n";
                    out_f << "L" << label_index+1 << ":\n";
                    label_index+=2;
                }

            }
#line 2118 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 583 "y.y" /* yacc.c:1646  */
    {
                Trace("EXPRESSION < EXPRESSION");
                if((yyvsp[-2].Inf)->d_type != (yyvsp[0].Inf)->d_type) yyerror("Type not compatible");
                if((yyvsp[-2].Inf)->d_type != REAL_TYPE && (yyvsp[-2].Inf)->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if((yyvsp[-2].Inf)->f_type == ARRAY_f || (yyvsp[0].Inf)->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if((yyvsp[-2].Inf)->f_type == CONST_f && (yyvsp[0].Inf)->f_type == CONST_f){
                    if((yyvsp[-2].Inf)->d_type== INT_TYPE){
                        (yyval.Inf) = new Info("",BOOL_TYPE,CONST_f,((yyvsp[-2].Inf)->i_v < (yyvsp[0].Inf)->i_v));
                    }else{
                        (yyval.Inf) = new Info("",BOOL_TYPE,CONST_f,((yyvsp[-2].Inf)->r_v < (yyvsp[0].Inf)->r_v));
                    }
                }else{
                    (yyval.Inf) = new Info("",BOOL_TYPE,VAR_f);
                }
                if(!isConst_Exp){
                    out_f << "isub\n";
                    out_f << "iflt L" << label_index << "\n";
                    out_f << "iconst_0" << "\n";
                    out_f << "goto L" << label_index+1 << "\n";
                    out_f << "L" << label_index << ": iconst_1\n";
                    out_f << "L" << label_index+1 << ":\n";
                    label_index+=2;
                }
            }
#line 2147 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 608 "y.y" /* yacc.c:1646  */
    {
                Trace("EXPRESSION = EXPRESSION");
                if((yyvsp[-2].Inf)->d_type != (yyvsp[0].Inf)->d_type) yyerror("Type not compatible");
                if((yyvsp[-2].Inf)->d_type != REAL_TYPE && (yyvsp[-2].Inf)->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if((yyvsp[-2].Inf)->f_type == ARRAY_f || (yyvsp[0].Inf)->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if((yyvsp[-2].Inf)->f_type == CONST_f && (yyvsp[0].Inf)->f_type == CONST_f){
                    if((yyvsp[-2].Inf)->d_type== INT_TYPE){
                        (yyval.Inf) = new Info("",BOOL_TYPE,CONST_f,((yyvsp[-2].Inf)->i_v == (yyvsp[0].Inf)->i_v));
                    }else{
                        (yyval.Inf) = new Info("",BOOL_TYPE,CONST_f,((yyvsp[-2].Inf)->r_v == (yyvsp[0].Inf)->r_v));
                    }
                }else{
                    (yyval.Inf) = new Info("",BOOL_TYPE,VAR_f);
                }
                
                if(!isConst_Exp){
                    out_f << "isub\n";
                    out_f << "ifeq L" << label_index << "\n";
                    out_f << "iconst_0" << "\n";
                    out_f << "goto L" << label_index+1 << "\n";
                    out_f << "L" << label_index << ": iconst_1\n";
                    out_f << "L" << label_index+1 << ":\n";
                    label_index+=2;
                }

            }
#line 2178 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 635 "y.y" /* yacc.c:1646  */
    {
                Trace("EXPRESSION != EXPRESSION");
                if((yyvsp[-2].Inf)->d_type != (yyvsp[0].Inf)->d_type) yyerror("Type not compatible");
                if((yyvsp[-2].Inf)->d_type != REAL_TYPE && (yyvsp[-2].Inf)->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if((yyvsp[-2].Inf)->f_type == ARRAY_f || (yyvsp[0].Inf)->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if((yyvsp[-2].Inf)->f_type == CONST_f && (yyvsp[0].Inf)->f_type == CONST_f){
                    if((yyvsp[-2].Inf)->d_type== INT_TYPE){
                        (yyval.Inf) = new Info("",BOOL_TYPE,CONST_f,((yyvsp[-2].Inf)->i_v != (yyvsp[0].Inf)->i_v));
                    }else{
                        (yyval.Inf) = new Info("",BOOL_TYPE,CONST_f,((yyvsp[-2].Inf)->r_v != (yyvsp[0].Inf)->r_v));
                    }
                }else{
                    (yyval.Inf) = new Info("",BOOL_TYPE,VAR_f);
                }
                if(!isConst_Exp){
                    out_f << "isub\n";
                    out_f << "ifne L" << label_index << "\n";
                    out_f << "iconst_0" << "\n";
                    out_f << "goto L" << label_index+1 << "\n";
                    out_f << "L" << label_index << ": iconst_1\n";
                    out_f << "L" << label_index+1 << ":\n";
                    label_index+=2;
                }
            }
#line 2207 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 660 "y.y" /* yacc.c:1646  */
    {
                Trace("EXPRESSION <= EXPRESSION");
                if((yyvsp[-2].Inf)->d_type != (yyvsp[0].Inf)->d_type) yyerror("Type not compatible");
                if((yyvsp[-2].Inf)->d_type != REAL_TYPE && (yyvsp[-2].Inf)->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if((yyvsp[-2].Inf)->f_type == ARRAY_f || (yyvsp[0].Inf)->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if((yyvsp[-2].Inf)->f_type == CONST_f && (yyvsp[0].Inf)->f_type == CONST_f){
                    if((yyvsp[-2].Inf)->d_type== INT_TYPE){
                        (yyval.Inf) = new Info("",BOOL_TYPE,CONST_f,((yyvsp[-2].Inf)->i_v <= (yyvsp[0].Inf)->i_v));
                    }else{
                        (yyval.Inf) = new Info("",BOOL_TYPE,CONST_f,((yyvsp[-2].Inf)->r_v <= (yyvsp[0].Inf)->r_v));
                    }
                }else{
                    (yyval.Inf) = new Info("",BOOL_TYPE,VAR_f);
                }
                if(!isConst_Exp){
                    out_f << "isub\n";
                    out_f << "ifle L" << label_index << "\n";
                    out_f << "iconst_0" << "\n";
                    out_f << "goto L" << label_index+1 << "\n";
                    out_f << "L" << label_index << ": iconst_1\n";
                    out_f << "L" << label_index+1 << ":\n";
                    label_index+=2;
                }
            }
#line 2236 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 685 "y.y" /* yacc.c:1646  */
    {
                Trace("EXPRESSION >= EXPRESSION");
                if((yyvsp[-2].Inf)->d_type != (yyvsp[0].Inf)->d_type) yyerror("Type not compatible");
                if((yyvsp[-2].Inf)->d_type != REAL_TYPE && (yyvsp[-2].Inf)->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if((yyvsp[-2].Inf)->f_type == ARRAY_f || (yyvsp[0].Inf)->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if((yyvsp[-2].Inf)->f_type == CONST_f && (yyvsp[0].Inf)->f_type == CONST_f){
                    if((yyvsp[-2].Inf)->d_type== INT_TYPE){
                        (yyval.Inf) = new Info("",BOOL_TYPE,CONST_f,((yyvsp[-2].Inf)->i_v >= (yyvsp[0].Inf)->i_v));
                    }else{
                        (yyval.Inf) = new Info("",BOOL_TYPE,CONST_f,((yyvsp[-2].Inf)->r_v >= (yyvsp[0].Inf)->r_v));
                    }
                }else{
                    (yyval.Inf) = new Info("",BOOL_TYPE,VAR_f);
                }
                if(!isConst_Exp){
                    out_f << "isub\n";
                    out_f << "ifge L" << label_index << "\n";
                    out_f << "iconst_0" << "\n";
                    out_f << "goto L" << label_index+1 << "\n";
                    out_f << "L" << label_index << ": iconst_1\n";
                    out_f << "L" << label_index+1 << ":\n";
                    label_index+=2;
                }
            }
#line 2265 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 710 "y.y" /* yacc.c:1646  */
    {
                Trace("EXPRESSION and EXPRESSION");
                if((yyvsp[-2].Inf)->d_type != (yyvsp[0].Inf)->d_type) yyerror("Type not compatible");
                if((yyvsp[-2].Inf)->d_type != BOOL_TYPE) yyerror("Type should be BOOLEAN");
                if((yyvsp[-2].Inf)->f_type == ARRAY_f || (yyvsp[0].Inf)->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if((yyvsp[-2].Inf)->f_type == CONST_f && (yyvsp[0].Inf)->f_type == CONST_f){
                    (yyval.Inf) = new Info("",BOOL_TYPE,CONST_f,(yyvsp[-2].Inf)->b_v && (yyvsp[0].Inf)->b_v);
                }else{
                    (yyval.Inf) = new Info("",BOOL_TYPE,VAR_f);
                }
                
                if(!isConst_Exp)out_f << "iand\n";

            }
#line 2284 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 725 "y.y" /* yacc.c:1646  */
    {
                Trace("EXPRESSION or EXPRESSION");
                if((yyvsp[-2].Inf)->d_type != (yyvsp[0].Inf)->d_type) yyerror("Type not compatible");
                if((yyvsp[-2].Inf)->d_type != BOOL_TYPE) yyerror("Type should be BOOLEAN");
                if((yyvsp[-2].Inf)->f_type == ARRAY_f || (yyvsp[0].Inf)->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if((yyvsp[-2].Inf)->f_type == CONST_f && (yyvsp[0].Inf)->f_type == CONST_f){
                    (yyval.Inf) = new Info("",BOOL_TYPE,CONST_f,(yyvsp[-2].Inf)->b_v || (yyvsp[0].Inf)->b_v);
                }else{
                    (yyval.Inf) = new Info("",BOOL_TYPE,VAR_f);
                }
                if(!isConst_Exp)out_f << "ior\n";
            }
#line 2301 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 738 "y.y" /* yacc.c:1646  */
    {
                Trace("Negation operator");
                if((yyvsp[0].Inf)->d_type != BOOL_TYPE) yyerror("Type should be BOOLEAN");
                if((yyvsp[0].Inf)->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                 if((yyvsp[0].Inf)->f_type == CONST_f){
                    (yyval.Inf) = new Info("",BOOL_TYPE,CONST_f,!(yyvsp[0].Inf)->b_v);
                }else{
                    (yyval.Inf) = new Info("",BOOL_TYPE,VAR_f);
                }
                if(!isConst_Exp){
                    out_f << "iconst_1\n";
                    out_f << "ixor\n";
                }
            }
#line 2320 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 753 "y.y" /* yacc.c:1646  */
    {
                (yyval.Inf) = (yyvsp[-1].Inf);
            }
#line 2328 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 757 "y.y" /* yacc.c:1646  */
    {
                Trace("const_value");
                // what if const variable declaration?
                if(!isConst_Exp){
                    switch((yyvsp[0].Inf)->d_type){
                        case INT_TYPE:
                            out_f << "\t\t" << "sipush " << getValue_IntBool(*(yyvsp[0].Inf)) << "\n";
                            break;
                        case STR_TYPE:
                            out_f << "\t\t" << "ldc " <<"\"" +*((yyvsp[0].Inf)->s_v)+"\"" << "\n";
                            break;
                        case BOOL_TYPE:
                            out_f << "\t\t" << "iconst_" << getValue_IntBool(*(yyvsp[0].Inf)) << "\n";
                            break;
                        default:
                            cout << "Not support for real type" << endl;
                            exit(1);
                    }
                }
            }
#line 2353 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 778 "y.y" /* yacc.c:1646  */
    {
                Info* id = stb_list.lookup(*(yyvsp[0].s_v));
                if(id == NULL) yyerror("ID not exists");
                if(id->f_type == FUNC_f) yyerror("func invocation error");
                (yyval.Inf) = id;           
                
                if(id->f_type == CONST_f){
                    // iconst_value for bool
                    // sipush for int
                    // ldc for string
                    switch(id->d_type){
                        case INT_TYPE:
                            out_f << "\t\t" << "sipush " << getValue_IntBool(*id) << "\n";
                            break;
                        case STR_TYPE:
                            out_f << "\t\t" << "ldc " <<"\"" +*(id->s_v)+"\"" << "\n";
                            break;
                        case BOOL_TYPE:
                            out_f << "\t\t" << "iconst_" << getValue_IntBool(*id) << "\n";
                            break;
                        default:
                            cout << "Not support for real type" << endl;
                            exit(1);
                    }
                }else{
                    if(id->isGlobalVar == 1){
                        string tmp = out_name.substr(0,out_name.find(".")) + "." + id->name; // example.a
                        out_f << "\t\t" << "getstatic " << getType(id->d_type) << " " << tmp << "\n";
                    }else{
                        int local_var_number = id->index_local;
                        out_f << "\t\t" << "iload " << local_var_number << "\n";
                    }
                }
            }
#line 2392 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 813 "y.y" /* yacc.c:1646  */
    {
                Trace("Array reference");
                //check expression type
                Info* id = stb_list.lookup(*(yyvsp[-3].s_v));
                if(id == NULL) yyerror("ID not exists");
                if((yyvsp[-1].Inf)->d_type != INT_TYPE)yyerror("expression should be INT_EXPR");
                if((yyvsp[-1].Inf)->f_type == FUNC_f || (yyvsp[-1].Inf)->f_type== ARRAY_f)yyerror("can not pass Array or Function id");
                (yyval.Inf) = new Info("",id->d_type,VAR_f);
            }
#line 2406 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 826 "y.y" /* yacc.c:1646  */
    {
            Trace("function invocation");
            //Symboltable* tb =stb_list.getCurrentTable();
            //int idx= tb->lookup(*$1);
            //if(idx==-1)yyerror("identifier not exists");
            //Info* func_info = tb->getInfo(idx);
            
            Info* func_info = stb_list.lookup(*(yyvsp[-3].s_v));
            if(func_info == NULL)yyerror("function not exists");
            // can not be procedure

            if(func_info->d_type == VOID_TYPE) yyerror("<ERROR> expression is not available for procedure");

            if(params.size() != func_info->params.size())yyerror("number of parameters are not the same");
            
            // compare type

            for(int i = 0 ;i <params.size();i++){
                if(params[i].d_type != func_info->params[i].d_type) yyerror("<ERROR>type is different");
            }
            params.clear();
            (yyval.Inf) = new Info("",func_info->d_type,VAR_f);

            out_f << "invokestatic " << getType(func_info->d_type) << " " << out_name.substr(0,out_name.find(".")) + "." + func_info->name + "(";
            for(int i =0 ; i<func_info->params.size();i++){
                out_f << getType(func_info->params[i].d_type);
                if(i!=func_info->params.size()-1)out_f << ", ";
            }
            out_f << ")\n";
        }
#line 2441 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 860 "y.y" /* yacc.c:1646  */
    {
            Trace("procedure invocation");

            
            Info* func_info = stb_list.lookup(*(yyvsp[-3].s_v));
            if(func_info == NULL)yyerror("procedure not exists");

            if(func_info->d_type != VOID_TYPE) yyerror("<ERROR> simple statments is not support for function ");

            if(params.size() != func_info->params.size())yyerror("number of parameters are not the same");
            
            // compare type

            for(int i = 0 ;i <params.size();i++){
                if(params[i].d_type != func_info->params[i].d_type) yyerror("<ERROR>type is different");
            }
            params.clear();
            //$$ = new Info("",func_info->d_type,VAR_f);

            out_f << "invokestatic " << getType(func_info->d_type) << " " << out_name.substr(0,out_name.find(".")) + "." + func_info->name + "(";
            for(int i =0 ; i<func_info->params.size();i++){
                out_f << getType(func_info->params[i].d_type);
                if(i!=func_info->params.size()-1)out_f << ", ";
            }
            out_f << ")\n";
        }
#line 2472 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 895 "y.y" /* yacc.c:1646  */
    {
                params.push_back(*(yyvsp[0].Inf));
            }
#line 2480 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 902 "y.y" /* yacc.c:1646  */
    {                    
                        stb_list.create_table();
                        // jump to L0
                        //label_temp = label_index;

                        st_label.push(label_index);
                        out_f << "ifeq L" << label_index << "\n";
                        label_index+=2;


                        //label_max_tmp = max(label_index,label_max_tmp);
                    }
#line 2497 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 915 "y.y" /* yacc.c:1646  */
    {
                        // jump to L1 ? (Lexit)
                        // if stmt (Lexit = L0)
                        // if-else (Lexit != L0)
                        if((yyvsp[-4].Inf)->d_type != BOOL_TYPE) yyerror("condition should be bool_expr");
                    }
#line 2508 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 924 "y.y" /* yacc.c:1646  */
    {
            stb_list.popTable();
            stb_list.create_table();
            //jump to lexit
            
            int index = st_label.top();
            //int base = label_index - (label_used);
            out_f << "goto L" << index+1 << "\n";
            out_f << "L" << index <<":\n";
        
        }
#line 2524 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 935 "y.y" /* yacc.c:1646  */
    {
            Trace("if-ELSE stmt");
            stb_list.popTable();
            
            //int base = label_index - (label_used);
            
            int index = st_label.top();
            out_f << "L" << index+1 << ":\n";
            
            st_label.pop();
         
        }
#line 2541 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 948 "y.y" /* yacc.c:1646  */
    {
            Trace("if stmt");
            stb_list.popTable();

            //int base = label_index - (label_used);

            int index = st_label.top();
            out_f << "L" << index << ":\n";

            st_label.pop();

            //label_index += 1; // should be modified (due to Nested if)
            
            //label_index-=2;
           
        }
#line 2562 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 967 "y.y" /* yacc.c:1646  */
    {
                stb_list.create_table();
                st_label.push(label_index);
                out_f << "L" << label_index <<":" << "\n"; // begin
                label_index+=2;
            }
#line 2573 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 973 "y.y" /* yacc.c:1646  */
    {
                int index= st_label.top();
                out_f << "goto L" << index  << "\n";
            }
#line 2582 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 978 "y.y" /* yacc.c:1646  */
    {
                Trace("loop");
                stb_list.popTable();
                int index= st_label.top();
                out_f << "L" << index+1 << ":" << "\n";
                st_label.pop();
            }
#line 2594 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 986 "y.y" /* yacc.c:1646  */
    {isConst_Exp=1;}
#line 2600 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 987 "y.y" /* yacc.c:1646  */
    {
                //cout << *$3 << endl;
                //stb_list.dumpAllTable();
                
                Info* id = stb_list.lookup(*(yyvsp[-6].s_v));
                st_id.push(id);
                
                //cout << "name:" <<(*id).name << endl;
                //cout << "name2:" << id->name << endl;

                if(id==NULL)yyerror("<ERROR> can't find identifier definition");

                
                if((yyvsp[-3].Inf)->f_type != CONST_f || (yyvsp[0].Inf)->f_type != CONST_f) yyerror("form should be <for identifier : const_expr .. const_expr>");
                
                stb_list.create_table();
                
                // decreasing index check?

                if((yyvsp[-7].b_v) == 1 && getValue_IntBool(*(yyvsp[-3].Inf)) < getValue_IntBool(*(yyvsp[0].Inf)) ){
                    // decreasing
                    yyerror("<ERROR>First expression should greater than second one");
                }
                //cout << "sipush " << getValue_IntBool(*$6) << "\n";

                out_f << "sipush " << getValue_IntBool(*(yyvsp[-3].Inf)) << "\n";
                // need to check id is global or local

                //cout << id->name << endl;

                if(id->isGlobalVar == 0){
                    // local var
                    out_f << "istore " << id->index_local << "\n";
                }else{
                    // global
                    //out_f << "putstatic " <<getType(id->d_type) << " " << out_name.substr(0,out_name.find(".")+1) + id->name << "\n"; //(id->name would cause error, i don't know why)
                    out_f << "putstatic " <<getType(id->d_type) << " " << out_name.substr(0,out_name.find(".")+1) + *(yyvsp[-6].s_v) << "\n";
                }


                st_label.push(label_index);

                out_f << "L" << label_index << ":\n";

                if(id->isGlobalVar==0){
                    out_f << "iload " << id->index_local << "\n";
                }else{
                    out_f << "getstatic " << getType(id->d_type) << " " << out_name.substr(0,out_name.find(".")) + "." + *(yyvsp[-6].s_v) << "\n";
                }

                out_f << "sipush " << getValue_IntBool(*(yyvsp[0].Inf)) << "\n";
                out_f << "isub\n";

                //cout << "test" << endl;
                if((yyvsp[-7].b_v)!=0){
                    // decreasing goto lexit
                    out_f << "iflt L" << label_index+1 << "\n"; 
                }else{
                    out_f << "ifgt L" << label_index+1 << "\n"; 
                }
                
                isConst_Exp=0;// correct?

                label_index+=2;
            }
#line 2670 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1052 "y.y" /* yacc.c:1646  */
    {
                //Info* id = stb_list.lookup(*$3);
                Info*id=st_id.top();
                int index= st_label.top();

                // need to check global or local
                if(id->isGlobalVar==0){
                    out_f << "iload " << id->index_local << "\n";
                }else{
                    //cout << "getstatic " << getType(id->d_type) << " " << out_name.substr(0,out_name.find(".")) + "." + *$3 << "\n";
                    out_f << "getstatic " << getType(id->d_type) << " " << out_name.substr(0,out_name.find(".")) + "." + *(yyvsp[-8].s_v) << "\n";
                }

                out_f << "sipush 1" << "\n";
                if((yyvsp[-9].b_v)==0){
                    out_f << "iadd\n";
                }else{
                    // decreasing
                    out_f << "isub\n";
                }

                // need to check global or local
                if(id->isGlobalVar == 0){
                    out_f << "istore " << id->index_local << "\n";
                }else{
                    out_f << "putstatic " << getType(id->d_type) << " " << out_name.substr(0,out_name.find(".")) + "." + *(yyvsp[-8].s_v) << "\n";
                }

                out_f << "goto L" << index << "\n";
            }
#line 2705 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1083 "y.y" /* yacc.c:1646  */
    {
                Trace("For loop");
                stb_list.popTable();

                int index= st_label.top();

                st_label.pop();
                st_id.pop();
                out_f << "L" << index+1 << ":\n";
                
            }
#line 2721 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1096 "y.y" /* yacc.c:1646  */
    {(yyval.b_v)=1;}
#line 2727 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1097 "y.y" /* yacc.c:1646  */
    {(yyval.b_v)=0;}
#line 2733 "y.tab.cpp" /* yacc.c:1646  */
    break;


#line 2737 "y.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 1103 "y.y" /* yacc.c:1906  */



void yyerror(string msg)
{
    cerr << "line: " << linenum << " " <<msg << endl;
    //exit(1);
}

int main(int argc , char*argv[])
{
    if(argc!=2){
        cout << "<ERROR> Usage: ./parser your_st_program.st" << endl;
        exit(1);
    }

    yyin = fopen(argv[1],"r");

    if(yyin == NULL){
        cout << "file \"" << argv[1] << "\" not exist" << endl;
        exit(1);
    }


    out_name = string(argv[1]);

    std::size_t dot_pos = out_name.find('.');

    if(dot_pos != string::npos && out_name.substr(dot_pos) == ".st"){
        out_name = out_name.replace(dot_pos+1,2,"jasm");
        
        out_f.open(out_name);
        if(!out_f.is_open()){
            cout << "unable to write file";
            exit(1);
        }
    }else{
        cout << "this is only support for simple turing Programming Language" << endl;
        exit(1);
    }



    yyparse();
    stb_list.dumpAllTable();

    return 0;
}


int yywrap()
{
    return 1;
}
