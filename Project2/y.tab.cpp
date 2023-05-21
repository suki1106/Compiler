/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "y.y"

#include <stdio.h>
#include <string>
#include <iostream>

#include "symbols.hpp"
#include "lex.yy.cpp"


using namespace std;

void yyerror(string s);
#define Trace(t)        printf("%s\n",t);
Symboltable tb;
vector<arg_info> args_info;

#line 88 "y.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AS = 3,                         /* AS  */
  YYSYMBOL_VAR = 4,                        /* VAR  */
  YYSYMBOL_CONST = 5,                      /* CONST  */
  YYSYMBOL_FUNCTION = 6,                   /* FUNCTION  */
  YYSYMBOL_BOOL = 7,                       /* BOOL  */
  YYSYMBOL_REAL = 8,                       /* REAL  */
  YYSYMBOL_INT = 9,                        /* INT  */
  YYSYMBOL_STRING = 10,                    /* STRING  */
  YYSYMBOL_ARRAY = 11,                     /* ARRAY  */
  YYSYMBOL_OF = 12,                        /* OF  */
  YYSYMBOL_CHAR = 13,                      /* CHAR  */
  YYSYMBOL_MOD = 14,                       /* MOD  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_OR = 16,                        /* OR  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_DECREASING = 18,                /* DECREASING  */
  YYSYMBOL_DEFAULT = 19,                   /* DEFAULT  */
  YYSYMBOL_DO = 20,                        /* DO  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_END = 22,                       /* END  */
  YYSYMBOL_EXIT = 23,                      /* EXIT  */
  YYSYMBOL_FOR = 24,                       /* FOR  */
  YYSYMBOL_GET = 25,                       /* GET  */
  YYSYMBOL_IF = 26,                        /* IF  */
  YYSYMBOL_LOOP = 27,                      /* LOOP  */
  YYSYMBOL_PUT = 28,                       /* PUT  */
  YYSYMBOL_PROCEDURE = 29,                 /* PROCEDURE  */
  YYSYMBOL_RESULT = 30,                    /* RESULT  */
  YYSYMBOL_RETURN = 31,                    /* RETURN  */
  YYSYMBOL_SKIP = 32,                      /* SKIP  */
  YYSYMBOL_THEN = 33,                      /* THEN  */
  YYSYMBOL_WHEN = 34,                      /* WHEN  */
  YYSYMBOL_BEG = 35,                       /* BEG  */
  YYSYMBOL_LE = 36,                        /* LE  */
  YYSYMBOL_GE = 37,                        /* GE  */
  YYSYMBOL_NE = 38,                        /* NE  */
  YYSYMBOL_ID = 39,                        /* ID  */
  YYSYMBOL_val_STR = 40,                   /* val_STR  */
  YYSYMBOL_val_INTEGER = 41,               /* val_INTEGER  */
  YYSYMBOL_val_REAL = 42,                  /* val_REAL  */
  YYSYMBOL_val_BOOL = 43,                  /* val_BOOL  */
  YYSYMBOL_44_ = 44,                       /* '<'  */
  YYSYMBOL_45_ = 45,                       /* '='  */
  YYSYMBOL_46_ = 46,                       /* '>'  */
  YYSYMBOL_47_ = 47,                       /* '-'  */
  YYSYMBOL_48_ = 48,                       /* '+'  */
  YYSYMBOL_49_ = 49,                       /* '*'  */
  YYSYMBOL_50_ = 50,                       /* '/'  */
  YYSYMBOL_UMINUS = 51,                    /* UMINUS  */
  YYSYMBOL_52_ = 52,                       /* ':'  */
  YYSYMBOL_53_ = 53,                       /* '.'  */
  YYSYMBOL_54_ = 54,                       /* '('  */
  YYSYMBOL_55_ = 55,                       /* ')'  */
  YYSYMBOL_56_ = 56,                       /* ','  */
  YYSYMBOL_57_ = 57,                       /* '['  */
  YYSYMBOL_58_ = 58,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_program = 60,                   /* program  */
  YYSYMBOL_dec_stmts = 61,                 /* dec_stmts  */
  YYSYMBOL_stmts = 62,                     /* stmts  */
  YYSYMBOL_dec_stmt = 63,                  /* dec_stmt  */
  YYSYMBOL_const_dec = 64,                 /* const_dec  */
  YYSYMBOL_const_val = 65,                 /* const_val  */
  YYSYMBOL_TYPE = 66,                      /* TYPE  */
  YYSYMBOL_var_dec = 67,                   /* var_dec  */
  YYSYMBOL_func_dec = 68,                  /* func_dec  */
  YYSYMBOL_func_stmts = 69,                /* func_stmts  */
  YYSYMBOL_func_stmt = 70,                 /* func_stmt  */
  YYSYMBOL_args = 71,                      /* args  */
  YYSYMBOL_arg = 72,                       /* arg  */
  YYSYMBOL_stmt = 73,                      /* stmt  */
  YYSYMBOL_BLOCK_stmt = 74,                /* BLOCK_stmt  */
  YYSYMBOL_simple_stmt = 75,               /* simple_stmt  */
  YYSYMBOL_EXIT_STMT = 76,                 /* EXIT_STMT  */
  YYSYMBOL_EXPRESSION = 77,                /* EXPRESSION  */
  YYSYMBOL_proc_inv = 78,                  /* proc_inv  */
  YYSYMBOL_conditional_stmt = 79,          /* conditional_stmt  */
  YYSYMBOL_loop_stmt = 80,                 /* loop_stmt  */
  YYSYMBOL_opt_r = 81                      /* opt_r  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   245

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    57,    58,    61,    62,    66,    67,    68,
      71,    79,    89,    90,    91,    92,   102,   103,   104,   105,
     108,   113,   120,   126,   133,   145,   155,   156,   161,   162,
     163,   166,   167,   168,   171,   179,   180,   181,   182,   184,
     192,   196,   200,   204,   208,   212,   216,   222,   226,   232,
     236,   240,   244,   248,   252,   256,   260,   264,   268,   272,
     276,   280,   284,   288,   292,   296,   297,   298,   303,   309,
     311,   315,   325,   329,   335,   336
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AS", "VAR", "CONST",
  "FUNCTION", "BOOL", "REAL", "INT", "STRING", "ARRAY", "OF", "CHAR",
  "MOD", "AND", "OR", "NOT", "DECREASING", "DEFAULT", "DO", "ELSE", "END",
  "EXIT", "FOR", "GET", "IF", "LOOP", "PUT", "PROCEDURE", "RESULT",
  "RETURN", "SKIP", "THEN", "WHEN", "BEG", "LE", "GE", "NE", "ID",
  "val_STR", "val_INTEGER", "val_REAL", "val_BOOL", "'<'", "'='", "'>'",
  "'-'", "'+'", "'*'", "'/'", "UMINUS", "':'", "'.'", "'('", "')'", "','",
  "'['", "']'", "$accept", "program", "dec_stmts", "stmts", "dec_stmt",
  "const_dec", "const_val", "TYPE", "var_dec", "func_dec", "func_stmts",
  "func_stmt", "args", "arg", "stmt", "BLOCK_stmt", "simple_stmt",
  "EXIT_STMT", "EXPRESSION", "proc_inv", "conditional_stmt", "loop_stmt",
  "opt_r", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-38)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,   -31,   -18,   -12,    23,     4,   206,     9,   -38,   -38,
     -38,    -1,     0,   -19,     7,   -38,    32,    73,    53,   101,
     189,   101,   101,   -38,   -38,   189,    90,   -38,   206,   -38,
     -38,   -38,   -38,   -38,   -38,   101,    98,   101,    78,    55,
      55,   101,   -38,    57,   -38,   101,    40,   -38,   -38,   -38,
     -38,   101,   101,   -38,   121,   -38,   -38,   -38,    88,   189,
     -38,   136,   136,    89,   101,   -38,   136,   -38,   -38,   -38,
     -38,    75,   111,   136,   114,    67,    68,    69,    71,   136,
      72,   161,   101,   -38,    84,   101,   101,   101,   189,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   118,
     -38,   -38,   136,    85,   101,   101,    78,    94,    55,   189,
     106,    -5,   -38,   -38,   161,    10,    -4,    54,    54,    54,
      54,    54,    54,    15,    15,   -38,   -38,   -38,    96,   136,
     136,   -38,    78,   -38,   131,   103,   -38,   189,   134,   120,
     189,   123,   110,   142,   -38,   164,   155,   -38,   137,   153,
      78,   148,   189,   -38,   -38,   -38,   166,   165,   -38
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     0,     0,     0,     6,     4,     8,     7,
       9,     0,     0,     0,     0,     1,    47,    75,     0,    69,
      27,    69,    69,    44,    46,    27,     0,     2,     6,    35,
      36,    45,    37,    38,     3,    69,     0,    69,     0,    33,
      33,    69,    74,     0,    42,    69,    66,    14,    13,    12,
      15,    69,    69,    65,     0,    68,    29,    28,     0,    27,
      30,    41,    43,     0,    69,     5,    22,    17,    19,    16,
      18,     0,    20,    10,     0,     0,     0,    32,     0,    48,
       0,    63,    69,    53,     0,    69,    69,    69,    27,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,     0,
      26,    39,    40,     0,    69,    69,     0,     0,    33,    27,
       0,     0,    64,    54,    61,    62,     0,    59,    60,    58,
      56,    57,    55,    50,    49,    51,    52,    72,     0,    21,
      11,    34,     0,    31,     0,     0,    67,    27,     0,     0,
      27,     0,     0,     0,    71,     0,     0,    25,     0,     0,
       0,     0,    27,    70,    23,    24,     0,     0,    73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -38,   -38,   183,   163,   -38,    12,   -38,   -37,    16,   -38,
     -25,   -38,   -35,   -38,    22,   -38,   -38,   -38,   -15,   -38,
     -38,   -38,   -38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,    27,     7,    56,    53,    72,    57,    10,
      58,    59,    76,    77,    60,    29,    30,    31,    54,    55,
      32,    33,    43
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      63,    74,    35,    37,    15,    78,    61,    62,    11,    85,
      86,    87,     8,     1,     2,     3,     9,   137,   138,     8,
      66,    12,    73,     9,    85,    86,    79,    13,    28,    85,
      81,    89,    90,    91,   100,    39,    83,    84,     4,    92,
      93,    94,    95,    96,    97,    98,    89,    90,    91,   102,
      28,    36,    38,   136,    92,    93,    94,    95,    96,    97,
      98,    40,    14,   116,    97,    98,    41,   111,    85,   131,
     113,   114,   115,   133,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   134,    67,    68,    69,    70,   129,
     130,    42,    44,    64,    75,   140,    80,    82,    85,    86,
      87,    95,    96,    97,    98,    67,    68,    69,    70,    71,
      99,   101,   143,   154,   104,   146,   103,   105,    45,   106,
      89,    90,    91,   107,   110,   108,   109,   156,    92,    93,
      94,    95,    96,    97,    98,    85,    86,    87,   128,   112,
      46,    47,    48,    49,    50,   127,   132,   135,    51,   139,
      85,    86,    87,   141,    88,    52,   142,    89,    90,    91,
     144,   145,   147,   148,   149,    92,    93,    94,    95,    96,
      97,    98,    89,    90,    91,    85,   150,   151,   152,   153,
      92,    93,    94,    95,    96,    97,    98,   155,   157,   158,
      34,    65,     0,     1,     2,     0,     0,    89,    90,    91,
       0,     0,     0,     0,     0,    92,    93,    94,    95,    96,
      97,    98,    16,    17,    18,    19,    20,    21,     0,    22,
      23,    24,     0,     0,    25,     0,     0,     0,    26,    16,
      17,    18,    19,    20,    21,     0,    22,    23,    24,     0,
       0,    25,     0,     0,     0,    26
};

static const yytype_int16 yycheck[] =
{
      25,    38,     3,     3,     0,    40,    21,    22,    39,    14,
      15,    16,     0,     4,     5,     6,     0,    21,    22,     7,
      35,    39,    37,     7,    14,    15,    41,    39,     6,    14,
      45,    36,    37,    38,    59,    54,    51,    52,    29,    44,
      45,    46,    47,    48,    49,    50,    36,    37,    38,    64,
      28,    52,    52,    58,    44,    45,    46,    47,    48,    49,
      50,    54,    39,    88,    49,    50,    34,    82,    14,   106,
      85,    86,    87,   108,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,   109,     7,     8,     9,    10,   104,
     105,    18,    39,     3,    39,   132,    39,    57,    14,    15,
      16,    47,    48,    49,    50,     7,     8,     9,    10,    11,
      22,    22,   137,   150,     3,   140,    41,     3,    17,    52,
      36,    37,    38,    55,    52,    56,    55,   152,    44,    45,
      46,    47,    48,    49,    50,    14,    15,    16,    53,    55,
      39,    40,    41,    42,    43,    27,    52,    41,    47,    53,
      14,    15,    16,    22,    33,    54,    53,    36,    37,    38,
      26,    41,    39,    53,    22,    44,    45,    46,    47,    48,
      49,    50,    36,    37,    38,    14,    12,    22,    41,    26,
      44,    45,    46,    47,    48,    49,    50,    39,    22,    24,
       7,    28,    -1,     4,     5,    -1,    -1,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    32,    -1,    -1,    35,    -1,    -1,    -1,    39,    23,
      24,    25,    26,    27,    28,    -1,    30,    31,    32,    -1,
      -1,    35,    -1,    -1,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,    29,    60,    61,    63,    64,    67,
      68,    39,    39,    39,    39,     0,    23,    24,    25,    26,
      27,    28,    30,    31,    32,    35,    39,    62,    73,    74,
      75,    76,    79,    80,    61,     3,    52,     3,    52,    54,
      54,    34,    18,    81,    39,    17,    39,    40,    41,    42,
      43,    47,    54,    65,    77,    78,    64,    67,    69,    70,
      73,    77,    77,    69,     3,    62,    77,     7,     8,     9,
      10,    11,    66,    77,    66,    39,    71,    72,    71,    77,
      39,    77,    57,    77,    77,    14,    15,    16,    33,    36,
      37,    38,    44,    45,    46,    47,    48,    49,    50,    22,
      69,    22,    77,    41,     3,     3,    52,    55,    56,    55,
      52,    77,    55,    77,    77,    77,    69,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    27,    53,    77,
      77,    66,    52,    71,    69,    41,    58,    21,    22,    53,
      66,    22,    53,    69,    26,    41,    69,    39,    53,    22,
      12,    22,    41,    26,    66,    39,    69,    22,    24
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    62,    63,    63,    63,
      64,    64,    65,    65,    65,    65,    66,    66,    66,    66,
      67,    67,    67,    67,    68,    68,    69,    69,    70,    70,
      70,    71,    71,    71,    72,    73,    73,    73,    73,    74,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    78,
      79,    79,    80,    80,    81,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     0,     1,     1,     1,
       4,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     6,     4,    10,    10,     8,     2,     0,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     3,
       3,     2,     2,     2,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     1,     1,     4,     1,     0,
       8,     6,     4,    11,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 10: /* const_dec: CONST ID AS EXPRESSION  */
#line 72 "y.y"
        {
            Trace("constant declaration without type declaration");
            if((yyvsp[0].Inf)->f_type != CONST_f) yyerror("<ERROR> expression should be constant");
            (yyvsp[0].Inf)->name = *(yyvsp[-2].s_v);
            if(tb.Insert(*((yyvsp[0].Inf))) ==-1)yyerror("<ERROR> identifier already exists");
            //tb.dump();
        }
#line 1280 "y.tab.cpp"
    break;

  case 11: /* const_dec: CONST ID ':' TYPE AS EXPRESSION  */
#line 80 "y.y"
        {
            Trace("constant declaration with type declaration");
            if((yyvsp[0].Inf)->f_type != CONST_f) yyerror("<ERROR> expression should be constant");
            (yyvsp[0].Inf)->name = *(yyvsp[-4].s_v);
            if(tb.Insert(*((yyvsp[0].Inf))) ==-1)yyerror("<ERROR> identifier already exists");
            //tb.dump();
        }
#line 1292 "y.tab.cpp"
    break;

  case 12: /* const_val: val_REAL  */
#line 89 "y.y"
                    {(yyval.Inf) = new Info("",REAL_TYPE,CONST_f,(yyvsp[0].r_v));}
#line 1298 "y.tab.cpp"
    break;

  case 13: /* const_val: val_INTEGER  */
#line 90 "y.y"
                      {(yyval.Inf)= new Info("",INT_TYPE,CONST_f,(yyvsp[0].i_v));}
#line 1304 "y.tab.cpp"
    break;

  case 14: /* const_val: val_STR  */
#line 91 "y.y"
                  {(yyval.Inf)=new Info("",STR_TYPE,CONST_f,(yyvsp[0].s_v));}
#line 1310 "y.tab.cpp"
    break;

  case 15: /* const_val: val_BOOL  */
#line 92 "y.y"
                   {(yyval.Inf)=new Info("",BOOL_TYPE,CONST_f,(yyvsp[0].b_v));}
#line 1316 "y.tab.cpp"
    break;

  case 16: /* TYPE: INT  */
#line 102 "y.y"
          {(yyval.d_t) = INT_TYPE;}
#line 1322 "y.tab.cpp"
    break;

  case 17: /* TYPE: BOOL  */
#line 103 "y.y"
            {(yyval.d_t) = BOOL_TYPE;}
#line 1328 "y.tab.cpp"
    break;

  case 18: /* TYPE: STRING  */
#line 104 "y.y"
             {(yyval.d_t)=STR_TYPE;}
#line 1334 "y.tab.cpp"
    break;

  case 19: /* TYPE: REAL  */
#line 105 "y.y"
            {(yyval.d_t)=REAL_TYPE;}
#line 1340 "y.tab.cpp"
    break;

  case 20: /* var_dec: VAR ID ':' TYPE  */
#line 109 "y.y"
        {
            Trace("variable declaration without value initialization");
            if(tb.Insert(Info(*((yyvsp[-2].s_v)),(yyvsp[0].d_t),VAR_f))  == -1) yyerror("<ERROR> identifier already exists"); 
        }
#line 1349 "y.tab.cpp"
    break;

  case 21: /* var_dec: VAR ID ':' TYPE AS EXPRESSION  */
#line 114 "y.y"
        {
            Trace("variable declaration with value initialization and type");
            (yyvsp[0].Inf)->name = *(yyvsp[-4].s_v);
            if((yyvsp[0].Inf)->d_type != (yyvsp[-2].d_t))  yyerror("<ERROR> Type not compatible");
            if(tb.Insert(*((yyvsp[0].Inf)))  == -1) yyerror("<ERROR> identifier already exists");
        }
#line 1360 "y.tab.cpp"
    break;

  case 22: /* var_dec: VAR ID AS EXPRESSION  */
#line 121 "y.y"
        {
            Trace("variable declaration iwth value initialization but not type");
            (yyvsp[0].Inf)->name = *(yyvsp[-2].s_v);
            if(tb.Insert(*(yyvsp[0].Inf)) == -1)yyerror("<ERROR> identifier already exists");
        }
#line 1370 "y.tab.cpp"
    break;

  case 23: /* var_dec: VAR ID ':' ARRAY val_INTEGER '.' '.' val_INTEGER OF TYPE  */
#line 127 "y.y"
        {
            Trace("Array declaration");
            if(tb.Insert(Info(*((yyvsp[-8].s_v)), (yyvsp[0].d_t),ARRAY_f)) == -1)yyerror("<ERROR> identifier already exists");
        }
#line 1379 "y.tab.cpp"
    break;

  case 24: /* func_dec: FUNCTION ID '(' args ')' ':' TYPE func_stmts END ID  */
#line 134 "y.y"
        {
            Trace("Func declaration");
            

            if(tb.Insert(Info(*(yyvsp[-8].s_v),(yyvsp[-3].d_t),FUNC_f,args_info) ) ==-1)yyerror("<ERROR> identifier already exists");
            args_info.clear();
            
            // new symbol table


        }
#line 1395 "y.tab.cpp"
    break;

  case 25: /* func_dec: PROCEDURE ID '(' args ')' func_stmts END ID  */
#line 146 "y.y"
        {
            Trace("procedure declaration");
            // new symbol table

        }
#line 1405 "y.tab.cpp"
    break;

  case 34: /* arg: ID ':' TYPE  */
#line 172 "y.y"
    {
        args_info.push_back(arg_info(*(yyvsp[-2].s_v),(yyvsp[0].d_t)));
    }
#line 1413 "y.tab.cpp"
    break;

  case 39: /* BLOCK_stmt: BEG func_stmts END  */
#line 185 "y.y"
        {
            // new symbol table
            Trace("find block");
        }
#line 1422 "y.tab.cpp"
    break;

  case 40: /* simple_stmt: ID AS EXPRESSION  */
#line 193 "y.y"
            {
                Trace("Assign value to ID");
            }
#line 1430 "y.tab.cpp"
    break;

  case 41: /* simple_stmt: PUT EXPRESSION  */
#line 197 "y.y"
            {
                Trace("Find PUT");
            }
#line 1438 "y.tab.cpp"
    break;

  case 42: /* simple_stmt: GET ID  */
#line 201 "y.y"
            {
                Trace("Find GET");
            }
#line 1446 "y.tab.cpp"
    break;

  case 43: /* simple_stmt: RESULT EXPRESSION  */
#line 205 "y.y"
            {
                Trace("Find result");
            }
#line 1454 "y.tab.cpp"
    break;

  case 44: /* simple_stmt: RETURN  */
#line 209 "y.y"
            {
                Trace("Find RETURN");
            }
#line 1462 "y.tab.cpp"
    break;

  case 45: /* simple_stmt: EXIT_STMT  */
#line 213 "y.y"
            {
                
            }
#line 1470 "y.tab.cpp"
    break;

  case 46: /* simple_stmt: SKIP  */
#line 217 "y.y"
            {
                Trace("Find skip");
            }
#line 1478 "y.tab.cpp"
    break;

  case 47: /* EXIT_STMT: EXIT  */
#line 223 "y.y"
            {
                Trace("Find EXIT");
            }
#line 1486 "y.tab.cpp"
    break;

  case 48: /* EXIT_STMT: EXIT WHEN EXPRESSION  */
#line 227 "y.y"
            {
                Trace("Find EXIT with boolean expression");
            }
#line 1494 "y.tab.cpp"
    break;

  case 49: /* EXPRESSION: EXPRESSION '+' EXPRESSION  */
#line 233 "y.y"
            {
                Trace("expression + expression");
            }
#line 1502 "y.tab.cpp"
    break;

  case 50: /* EXPRESSION: EXPRESSION '-' EXPRESSION  */
#line 237 "y.y"
            {
                Trace("expression - expression");
            }
#line 1510 "y.tab.cpp"
    break;

  case 51: /* EXPRESSION: EXPRESSION '*' EXPRESSION  */
#line 241 "y.y"
            {
                 Trace("expression * expression");
            }
#line 1518 "y.tab.cpp"
    break;

  case 52: /* EXPRESSION: EXPRESSION '/' EXPRESSION  */
#line 245 "y.y"
            {
                Trace("expression / expression");
            }
#line 1526 "y.tab.cpp"
    break;

  case 53: /* EXPRESSION: '-' EXPRESSION  */
#line 249 "y.y"
            {
                Trace("- expression");
            }
#line 1534 "y.tab.cpp"
    break;

  case 54: /* EXPRESSION: EXPRESSION MOD EXPRESSION  */
#line 253 "y.y"
            {
                Trace("expression mod expression");
            }
#line 1542 "y.tab.cpp"
    break;

  case 55: /* EXPRESSION: EXPRESSION '>' EXPRESSION  */
#line 257 "y.y"
            {
                Trace("EXPRESSION > EXPRESSION");
            }
#line 1550 "y.tab.cpp"
    break;

  case 56: /* EXPRESSION: EXPRESSION '<' EXPRESSION  */
#line 261 "y.y"
            {
                Trace("EXPRESSION < EXPRESSION");
            }
#line 1558 "y.tab.cpp"
    break;

  case 57: /* EXPRESSION: EXPRESSION '=' EXPRESSION  */
#line 265 "y.y"
            {
                Trace("EXPRESSION = EXPRESSION");
            }
#line 1566 "y.tab.cpp"
    break;

  case 58: /* EXPRESSION: EXPRESSION NE EXPRESSION  */
#line 269 "y.y"
            {
                Trace("EXPRESSION != EXPRESSION");
            }
#line 1574 "y.tab.cpp"
    break;

  case 59: /* EXPRESSION: EXPRESSION LE EXPRESSION  */
#line 273 "y.y"
            {
                Trace("EXPRESSION <= EXPRESSION");
            }
#line 1582 "y.tab.cpp"
    break;

  case 60: /* EXPRESSION: EXPRESSION GE EXPRESSION  */
#line 277 "y.y"
            {
                Trace("EXPRESSION >= EXPRESSION");
            }
#line 1590 "y.tab.cpp"
    break;

  case 61: /* EXPRESSION: EXPRESSION AND EXPRESSION  */
#line 281 "y.y"
            {
                Trace("EXPRESSION and EXPRESSION");
            }
#line 1598 "y.tab.cpp"
    break;

  case 62: /* EXPRESSION: EXPRESSION OR EXPRESSION  */
#line 285 "y.y"
            {
                Trace("EXPRESSION or EXPRESSION");
            }
#line 1606 "y.tab.cpp"
    break;

  case 63: /* EXPRESSION: NOT EXPRESSION  */
#line 289 "y.y"
            {
                Trace("Negation operator");
            }
#line 1614 "y.tab.cpp"
    break;

  case 64: /* EXPRESSION: '(' EXPRESSION ')'  */
#line 293 "y.y"
            {
                (yyval.Inf) = (yyvsp[-1].Inf);
            }
#line 1622 "y.tab.cpp"
    break;

  case 65: /* EXPRESSION: const_val  */
#line 296 "y.y"
                      {Trace("const_value");}
#line 1628 "y.tab.cpp"
    break;

  case 67: /* EXPRESSION: ID '[' EXPRESSION ']'  */
#line 299 "y.y"
            {
                Trace("Array reference");
                //check expression type
            }
#line 1637 "y.tab.cpp"
    break;

  case 68: /* EXPRESSION: proc_inv  */
#line 304 "y.y"
            {

            }
#line 1645 "y.tab.cpp"
    break;

  case 70: /* conditional_stmt: IF EXPRESSION THEN func_stmts ELSE func_stmts END IF  */
#line 312 "y.y"
                    {
                        Trace("if-ELSE stmt");
                    }
#line 1653 "y.tab.cpp"
    break;

  case 71: /* conditional_stmt: IF EXPRESSION THEN func_stmts END IF  */
#line 316 "y.y"
                    {
                        Trace("if stmt");
                    }
#line 1661 "y.tab.cpp"
    break;

  case 72: /* loop_stmt: LOOP func_stmts END LOOP  */
#line 326 "y.y"
            {
                Trace("loop");
            }
#line 1669 "y.tab.cpp"
    break;

  case 73: /* loop_stmt: FOR opt_r ID ':' val_INTEGER '.' '.' val_INTEGER func_stmts END FOR  */
#line 330 "y.y"
            {
                Trace("For loop");
            }
#line 1677 "y.tab.cpp"
    break;


#line 1681 "y.tab.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 342 "y.y"



void yyerror(string msg)
{
    cerr << msg << endl;
    exit(1);
}

int main()
{
    yyparse();
    tb.dump();
    return 0;
}


int yywrap()
{
    return 1;
}
