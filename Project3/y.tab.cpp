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

//int label_used=0;




bool isConst_Exp = 0;



#line 110 "y.tab.cpp"

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
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_62_2 = 62,                      /* $@2  */
  YYSYMBOL_dec_stmts = 63,                 /* dec_stmts  */
  YYSYMBOL_stmts = 64,                     /* stmts  */
  YYSYMBOL_dec_stmt = 65,                  /* dec_stmt  */
  YYSYMBOL_const_dec = 66,                 /* const_dec  */
  YYSYMBOL_67_3 = 67,                      /* $@3  */
  YYSYMBOL_68_4 = 68,                      /* $@4  */
  YYSYMBOL_const_val = 69,                 /* const_val  */
  YYSYMBOL_TYPE = 70,                      /* TYPE  */
  YYSYMBOL_var_dec = 71,                   /* var_dec  */
  YYSYMBOL_72_5 = 72,                      /* $@5  */
  YYSYMBOL_73_6 = 73,                      /* $@6  */
  YYSYMBOL_func_dec = 74,                  /* func_dec  */
  YYSYMBOL_75_7 = 75,                      /* $@7  */
  YYSYMBOL_76_8 = 76,                      /* $@8  */
  YYSYMBOL_func_stmts = 77,                /* func_stmts  */
  YYSYMBOL_func_stmt = 78,                 /* func_stmt  */
  YYSYMBOL_args = 79,                      /* args  */
  YYSYMBOL_arg = 80,                       /* arg  */
  YYSYMBOL_stmt = 81,                      /* stmt  */
  YYSYMBOL_BLOCK_stmt = 82,                /* BLOCK_stmt  */
  YYSYMBOL_83_9 = 83,                      /* $@9  */
  YYSYMBOL_simple_stmt = 84,               /* simple_stmt  */
  YYSYMBOL_85_10 = 85,                     /* $@10  */
  YYSYMBOL_EXIT_STMT = 86,                 /* EXIT_STMT  */
  YYSYMBOL_EXPRESSION = 87,                /* EXPRESSION  */
  YYSYMBOL_func_inv = 88,                  /* func_inv  */
  YYSYMBOL_proc_inv = 89,                  /* proc_inv  */
  YYSYMBOL_actual_params = 90,             /* actual_params  */
  YYSYMBOL_actual_param = 91,              /* actual_param  */
  YYSYMBOL_conditional_stmt = 92,          /* conditional_stmt  */
  YYSYMBOL_93_11 = 93,                     /* $@11  */
  YYSYMBOL_ELSE_stmt = 94,                 /* ELSE_stmt  */
  YYSYMBOL_95_12 = 95,                     /* $@12  */
  YYSYMBOL_loop_stmt = 96,                 /* loop_stmt  */
  YYSYMBOL_97_13 = 97,                     /* $@13  */
  YYSYMBOL_98_14 = 98,                     /* $@14  */
  YYSYMBOL_99_15 = 99,                     /* $@15  */
  YYSYMBOL_100_16 = 100,                   /* $@16  */
  YYSYMBOL_opt_r = 101                     /* opt_r  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   287

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

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
       0,    79,    79,    83,    79,   101,   102,   105,   106,   110,
     111,   112,   115,   115,   127,   127,   144,   145,   146,   147,
     157,   158,   159,   160,   163,   175,   175,   196,   196,   219,
     230,   229,   258,   257,   280,   281,   286,   287,   288,   291,
     292,   293,   296,   304,   305,   306,   307,   310,   309,   321,
     335,   334,   346,   356,   365,   369,   370,   376,   379,   383,
     395,   414,   433,   452,   470,   479,   493,   521,   546,   573,
     598,   623,   648,   663,   676,   688,   692,   713,   748,   758,
     761,   788,   811,   812,   813,   816,   824,   823,   846,   845,
     869,   889,   895,   888,   908,   929,   907,   949,   950
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
  "'['", "']'", "$accept", "program", "$@1", "$@2", "dec_stmts", "stmts",
  "dec_stmt", "const_dec", "$@3", "$@4", "const_val", "TYPE", "var_dec",
  "$@5", "$@6", "func_dec", "$@7", "$@8", "func_stmts", "func_stmt",
  "args", "arg", "stmt", "BLOCK_stmt", "$@9", "simple_stmt", "$@10",
  "EXIT_STMT", "EXPRESSION", "func_inv", "proc_inv", "actual_params",
  "actual_param", "conditional_stmt", "$@11", "ELSE_stmt", "$@12",
  "loop_stmt", "$@13", "$@14", "$@15", "$@16", "opt_r", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-90)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -90,    10,    15,   -90,   -25,   -23,   -14,    -8,   -90,    15,
     -90,   -90,   -90,     3,     5,   -21,    -9,   248,   -90,   -90,
     132,   -90,   115,    -7,    -7,    17,    35,    19,    -4,   -90,
     -90,    -4,   -90,   -90,   -90,     0,   -90,   248,   -90,   -90,
     -90,   -90,   -90,   -90,    -4,   -90,   -90,   -90,   -90,    18,
      58,    -4,    60,    14,    12,    33,    36,    -4,   -90,    51,
     -90,    -4,   -31,   -90,   -90,   -90,   -90,    -4,    -4,   -90,
     138,   -90,   231,    -4,   163,   231,    -4,    -4,   -90,   163,
      40,   -90,   163,   -90,   115,    44,    -7,   -90,   163,    49,
     203,    -4,    -4,   -90,    83,    -4,    -4,    -4,   -90,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,   -90,
     -90,   -90,   231,   -90,   163,    85,   163,   163,    53,    55,
      56,    -4,    -4,   -90,   115,   -90,   231,    -4,    82,    68,
     -90,   -90,   203,   178,   231,    38,    38,    38,    38,    38,
      38,    -2,    -2,   -90,   -90,   122,   -90,   -90,   -90,    -4,
     105,   163,   163,   -90,   126,   120,   -90,   -90,     7,   123,
     -90,   137,   231,   112,   102,   -90,   133,   -90,   -90,   115,
     139,   -90,    -4,   231,   -90,   -90,   121,   163,   140,   -90,
     231,   146,   -90,   -90,   141,   156,   -90
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     6,     1,     0,     0,     0,     0,     3,     6,
      10,     9,    11,     0,     0,     0,     0,     8,     5,    27,
       0,    12,     0,    41,    41,    58,    98,     0,     0,    91,
      50,     0,    54,    56,    47,     0,     4,     8,    43,    44,
      55,    57,    45,    46,     0,    21,    23,    20,    22,     0,
      24,     0,     0,     0,     0,    40,     0,     0,    97,     0,
      52,     0,    77,    18,    17,    16,    19,     0,     0,    76,
       0,    79,    35,     0,    53,    35,     0,    84,     7,    28,
       0,    25,    13,    14,     0,     0,    41,    32,    59,     0,
      74,    84,     0,    64,     0,     0,     0,     0,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      36,    92,    35,    38,    51,     0,    49,    85,     0,    83,
       0,     0,     0,    42,     0,    39,    35,     0,     0,     0,
      75,    65,    72,    73,    35,    70,    71,    69,    67,    68,
      66,    61,    60,    62,    63,     0,    34,    48,    81,    84,
       0,    26,    15,    30,     0,     0,    80,    78,     0,     0,
      82,     0,    35,     0,     0,    88,     0,    87,    93,     0,
       0,    33,     0,    35,    90,    29,     0,    94,     0,    31,
      35,     0,    95,    89,     0,     0,    96
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   -90,   -90,   -90,   172,   152,   -90,     9,   -90,   -90,
     -90,   -22,    13,   -90,   -90,   -90,   -90,   -90,   -70,   -90,
     -15,   -90,   -10,   -90,   -90,   -90,   -90,   -90,   -27,   -90,
     -90,   -89,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   -90,   -90
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    17,     8,    36,     9,   109,    51,   122,
      69,    50,   110,   121,    44,    12,   162,   126,   111,   112,
      54,    55,   113,    38,    75,    39,    73,    40,   117,    71,
      41,   118,   119,    42,   134,   167,   173,    43,    72,   145,
     180,   184,    59
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      52,    70,   128,    76,    74,   115,    19,    37,    21,    56,
       3,    10,    95,    61,    13,    11,    14,    79,    10,     4,
       5,     6,    11,    91,    82,    15,    92,    37,   165,   166,
      88,    16,    53,    23,    90,    62,    63,    64,    65,    66,
      93,    94,   146,    67,     7,    24,   114,   107,   108,   116,
      68,    57,    95,    58,    77,    20,   154,    22,    60,    80,
     160,    81,   123,    83,   158,   129,    84,    85,   131,   132,
     133,   125,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    95,    96,    97,   105,   106,   107,   108,    86,
      89,    87,   170,   120,   151,   152,   124,    95,    96,    97,
     155,   127,   153,   178,    99,   100,   101,   147,   148,   150,
     182,   149,   102,   103,   104,   105,   106,   107,   108,    99,
     100,   101,    45,    46,    47,    48,   157,   102,   103,   104,
     105,   106,   107,   108,    95,    96,    97,   156,   130,    45,
      46,    47,    48,    49,   159,   177,   161,   175,   163,   169,
     168,   171,    95,    96,    97,   172,    99,   100,   101,   174,
     179,   176,   181,   185,   102,   103,   104,   105,   106,   107,
     108,    98,   183,   164,    99,   100,   101,    95,    96,    97,
     186,    18,   102,   103,   104,   105,   106,   107,   108,    78,
       0,     0,    95,    96,     0,     0,     0,     0,     0,    99,
     100,   101,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,    99,   100,   101,    95,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,     0,     0,     0,     4,     5,     0,     0,    99,
     100,   101,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,    25,    26,    27,    28,    29,    30,
       0,    31,    32,    33,     0,     0,    34,     0,     0,     0,
      35,    25,    26,    27,    28,    29,    30,     0,    31,    32,
      33,     0,     0,    34,     0,     0,     0,    35
};

static const yytype_int16 yycheck[] =
{
      22,    28,    91,     3,    31,    75,     3,    17,     3,    24,
       0,     2,    14,    17,    39,     2,    39,    44,     9,     4,
       5,     6,     9,    54,    51,    39,    57,    37,    21,    22,
      57,    39,    39,    54,    61,    39,    40,    41,    42,    43,
      67,    68,   112,    47,    29,    54,    73,    49,    50,    76,
      54,    34,    14,    18,    54,    52,   126,    52,    39,    41,
     149,     3,    84,     3,   134,    92,    52,    55,    95,    96,
      97,    86,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    14,    15,    16,    47,    48,    49,    50,    56,
      39,    55,   162,    53,   121,   122,    52,    14,    15,    16,
     127,    52,   124,   173,    36,    37,    38,    22,    55,    53,
     180,    56,    44,    45,    46,    47,    48,    49,    50,    36,
      37,    38,     7,     8,     9,    10,    58,    44,    45,    46,
      47,    48,    49,    50,    14,    15,    16,    55,    55,     7,
       8,     9,    10,    11,    22,   172,    41,   169,    22,    12,
      27,    39,    14,    15,    16,    53,    36,    37,    38,    26,
      39,    22,    22,    22,    44,    45,    46,    47,    48,    49,
      50,    33,    26,    53,    36,    37,    38,    14,    15,    16,
      24,     9,    44,    45,    46,    47,    48,    49,    50,    37,
      -1,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    36,    37,    38,    14,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    23,    24,    25,    26,    27,    28,
      -1,    30,    31,    32,    -1,    -1,    35,    -1,    -1,    -1,
      39,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
      32,    -1,    -1,    35,    -1,    -1,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    60,    61,     0,     4,     5,     6,    29,    63,    65,
      66,    71,    74,    39,    39,    39,    39,    62,    63,     3,
      52,     3,    52,    54,    54,    23,    24,    25,    26,    27,
      28,    30,    31,    32,    35,    39,    64,    81,    82,    84,
      86,    89,    92,    96,    73,     7,     8,     9,    10,    11,
      70,    67,    70,    39,    79,    80,    79,    34,    18,   101,
      39,    17,    39,    40,    41,    42,    43,    47,    54,    69,
      87,    88,    97,    85,    87,    83,     3,    54,    64,    87,
      41,     3,    87,     3,    52,    55,    56,    55,    87,    39,
      87,    54,    57,    87,    87,    14,    15,    16,    33,    36,
      37,    38,    44,    45,    46,    47,    48,    49,    50,    66,
      71,    77,    78,    81,    87,    77,    87,    87,    90,    91,
      53,    72,    68,    70,    52,    79,    76,    52,    90,    87,
      55,    87,    87,    87,    93,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    98,    77,    22,    55,    56,
      53,    87,    87,    70,    77,    87,    55,    58,    77,    22,
      90,    41,    75,    22,    53,    21,    22,    94,    27,    12,
      77,    39,    53,    95,    26,    70,    22,    87,    77,    39,
      99,    22,    77,    26,   100,    22,    24
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
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
      94,    97,    98,    96,    99,   100,    96,   101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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
       2,     0,     0,     6,     0,     0,    13,     1,     0
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
  case 2: /* $@1: %empty  */
#line 79 "y.y"
        {
            out_f << "class " << out_name.substr(0,out_name.find(".")) << "\n{\n";
        }
#line 1347 "y.tab.cpp"
    break;

  case 3: /* $@2: %empty  */
#line 83 "y.y"
        {
            // enter main block
            out_f << "\tmethod public static void main(java.lang.String[])\n";
            out_f << "\tmax_stack 15\n";
            out_f << "\tmax_locals 15\n";
            out_f << "\t{\n";

        }
#line 1360 "y.tab.cpp"
    break;

  case 4: /* program: $@1 dec_stmts $@2 stmts  */
#line 92 "y.y"
        {
            out_f << "\t\treturn\n";
            out_f << "\t}\n";
            out_f << "}";
            out_f.close();
        }
#line 1371 "y.tab.cpp"
    break;

  case 12: /* $@3: %empty  */
#line 115 "y.y"
                       {isConst_Exp=1;}
#line 1377 "y.tab.cpp"
    break;

  case 13: /* const_dec: CONST ID AS $@3 EXPRESSION  */
#line 116 "y.y"
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
#line 1393 "y.tab.cpp"
    break;

  case 14: /* $@4: %empty  */
#line 127 "y.y"
                             {isConst_Exp=1;}
#line 1399 "y.tab.cpp"
    break;

  case 15: /* const_dec: CONST ID ':' TYPE AS $@4 EXPRESSION  */
#line 128 "y.y"
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
#line 1418 "y.tab.cpp"
    break;

  case 16: /* const_val: val_REAL  */
#line 144 "y.y"
                    {(yyval.Inf) = new Info("",REAL_TYPE,CONST_f,(yyvsp[0].r_v));}
#line 1424 "y.tab.cpp"
    break;

  case 17: /* const_val: val_INTEGER  */
#line 145 "y.y"
                      {(yyval.Inf)= new Info("",INT_TYPE,CONST_f,(yyvsp[0].i_v));}
#line 1430 "y.tab.cpp"
    break;

  case 18: /* const_val: val_STR  */
#line 146 "y.y"
                  {(yyval.Inf)=new Info("",STR_TYPE,CONST_f,(yyvsp[0].s_v));}
#line 1436 "y.tab.cpp"
    break;

  case 19: /* const_val: val_BOOL  */
#line 147 "y.y"
                   {(yyval.Inf)=new Info("",BOOL_TYPE,CONST_f,(yyvsp[0].b_v));}
#line 1442 "y.tab.cpp"
    break;

  case 20: /* TYPE: INT  */
#line 157 "y.y"
          {(yyval.d_t) = INT_TYPE;}
#line 1448 "y.tab.cpp"
    break;

  case 21: /* TYPE: BOOL  */
#line 158 "y.y"
            {(yyval.d_t) = BOOL_TYPE;}
#line 1454 "y.tab.cpp"
    break;

  case 22: /* TYPE: STRING  */
#line 159 "y.y"
             {(yyval.d_t)=STR_TYPE;}
#line 1460 "y.tab.cpp"
    break;

  case 23: /* TYPE: REAL  */
#line 160 "y.y"
            {(yyval.d_t)=REAL_TYPE;}
#line 1466 "y.tab.cpp"
    break;

  case 24: /* var_dec: VAR ID ':' TYPE  */
#line 164 "y.y"
        {
            Trace("variable declaration without value initialization");
            Symboltable* tb = stb_list.getCurrentTable();
            if(tb->Insert(Info(*((yyvsp[-2].s_v)),(yyvsp[0].d_t),VAR_f))  == -1) yyerror("<ERROR> identifier already exists"); 
            if(stb_list.isGlobal()){
                out_f << "\t" << "field static " << getType((yyvsp[0].d_t)) << " " << *(yyvsp[-2].s_v) << "\n"; // global
            }else{
                Info* data = tb->getInfo(tb->lookup(*(yyvsp[-2].s_v)));
                data->index_local = counter_local_var++;
            }
        }
#line 1482 "y.tab.cpp"
    break;

  case 25: /* $@5: %empty  */
#line 175 "y.y"
                           {isConst_Exp=1;}
#line 1488 "y.tab.cpp"
    break;

  case 26: /* var_dec: VAR ID ':' TYPE AS $@5 EXPRESSION  */
#line 176 "y.y"
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
#line 1513 "y.tab.cpp"
    break;

  case 27: /* $@6: %empty  */
#line 196 "y.y"
                   {isConst_Exp=1;}
#line 1519 "y.tab.cpp"
    break;

  case 28: /* var_dec: VAR ID AS $@6 EXPRESSION  */
#line 197 "y.y"
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
#line 1546 "y.tab.cpp"
    break;

  case 29: /* var_dec: VAR ID ':' ARRAY val_INTEGER '.' '.' val_INTEGER OF TYPE  */
#line 220 "y.y"
        {
            Trace("Array declaration");
            Symboltable* tb = stb_list.getCurrentTable();
            Info tmp = Info(*((yyvsp[-8].s_v)), (yyvsp[0].d_t),ARRAY_f);
            tmp.size = (yyvsp[-2].i_v) - (yyvsp[-5].i_v) +1; // store array size
            if(tb->Insert(tmp) == -1)yyerror("<ERROR> identifier already exists");
        }
#line 1558 "y.tab.cpp"
    break;

  case 30: /* $@7: %empty  */
#line 230 "y.y"
        {
            //if(*$2 != *$11) yyerror("<ERROR> Func declaration error");

            Trace("Func declaration");

            Symboltable* tb = stb_list.getCurrentTable();
            if(tb->Insert(Info(*(yyvsp[-5].s_v),(yyvsp[0].d_t),FUNC_f,args_info) ) ==-1)yyerror("<ERROR> identifier already exists");
            
            // create new symbol table and switch
            stb_list.create_table();
            tb = stb_list.getCurrentTable(); // copy constructor?
            for(auto& arg:args_info)
                tb->Insert(Info(arg.name,arg.d_type,VAR_f)); // insert arg into table
            
            //tb->printTableSize();
            args_info.clear();
        }
#line 1580 "y.tab.cpp"
    break;

  case 31: /* func_dec: FUNCTION ID '(' args ')' ':' TYPE $@7 func_stmts END ID  */
#line 248 "y.y"
        {
            if(*(yyvsp[-9].s_v) != *(yyvsp[0].s_v)) yyerror("<ERROR> Func declaration error");
            //check result expression ?
            if(result_stmt == 0) yyerror("<ERROR> Function should return value");
            
            result_stmt=0;
            stb_list.dumpCurrentTable();
            stb_list.popTable();
        }
#line 1594 "y.tab.cpp"
    break;

  case 32: /* $@8: %empty  */
#line 258 "y.y"
        {
            Trace("procedure declaration");
            // new symbol table
            Symboltable* tb = stb_list.getCurrentTable();
            if( tb->Insert(Info(*(yyvsp[-3].s_v),VOID_TYPE,FUNC_f,args_info)) ==-1) yyerror("<ERROR> identifier already exists");
            
            //create new table and switch, store args info in new table
            stb_list.create_table();
            tb = stb_list.getCurrentTable();
            for(auto& arg:args_info)
                tb->Insert(Info(arg.name,arg.d_type,VAR_f)); // store parameter info     
            //tb->printTableSize();
            args_info.clear();
        }
#line 1613 "y.tab.cpp"
    break;

  case 33: /* func_dec: PROCEDURE ID '(' args ')' $@8 func_stmts END ID  */
#line 272 "y.y"
        {
            if(*(yyvsp[-7].s_v) != *(yyvsp[0].s_v)) yyerror("<ERROR> Procedure declaration error");
            stb_list.dumpCurrentTable();
            stb_list.popTable();
        }
#line 1623 "y.tab.cpp"
    break;

  case 42: /* arg: ID ':' TYPE  */
#line 297 "y.y"
    {
        args_info.push_back(arg_info(*(yyvsp[-2].s_v),(yyvsp[0].d_t)));
    }
#line 1631 "y.tab.cpp"
    break;

  case 47: /* $@9: %empty  */
#line 310 "y.y"
        {
            stb_list.create_table();
        }
#line 1639 "y.tab.cpp"
    break;

  case 48: /* BLOCK_stmt: BEG $@9 func_stmts END  */
#line 312 "y.y"
                        {
            Trace("find block stmt");
            // BLOCK ends, call popTable
            stb_list.dumpCurrentTable();
            stb_list.popTable();
        }
#line 1650 "y.tab.cpp"
    break;

  case 49: /* simple_stmt: ID AS EXPRESSION  */
#line 322 "y.y"
            {
                Trace("Assign value to ID");
                Info* id = stb_list.lookup(*(yyvsp[-2].s_v));
                if(id == NULL) yyerror("<ERROR> identifier not exists");
                if(id->f_type == CONST_f) yyerror("const variable can not be assigned");
                if(sameType(*id,*(yyvsp[0].Inf)) == 0) yyerror("type is not compatible"); // array?
                if(id->isGlobalVar == 1){
                    out_f << "putstatic " << getType(id->d_type) << " " << out_name.substr(0,out_name.find(".")) + "." + id->name << "\n";
                }else{
                    out_f << "istore " << id->index_local << "\n";
                }
            }
#line 1667 "y.tab.cpp"
    break;

  case 50: /* $@10: %empty  */
#line 335 "y.y"
            {
                out_f << "getstatic java.io.PrintStream java.lang.System.out\n";
            }
#line 1675 "y.tab.cpp"
    break;

  case 51: /* simple_stmt: PUT $@10 EXPRESSION  */
#line 338 "y.y"
            {
                Trace("Find PUT");
                if((yyvsp[0].Inf)->d_type ==INT_TYPE || (yyvsp[0].Inf)->d_type == BOOL_TYPE){
                    out_f << "invokevirtual void java.io.PrintStream.print(int)\n";
                }else{ // string
                    out_f << "invokevirtual void java.io.PrintStream.print(java.lang.String)\n";
                }
            }
#line 1688 "y.tab.cpp"
    break;

  case 52: /* simple_stmt: GET ID  */
#line 347 "y.y"
            {
                Trace("Find GET");
                //Symboltable* tb = stb_list.getCurrentTable();
                //int idx=tb->lookup(*$2);
                //if(idx == -1) yyerror("<ERROR> identifier not exists");
                Info* id = stb_list.lookup(*(yyvsp[0].s_v));
                if(id == NULL) yyerror("<ERROR> identifier not exists");
                //Info* id = tb->getInfo(idx);
            }
#line 1702 "y.tab.cpp"
    break;

  case 53: /* simple_stmt: RESULT EXPRESSION  */
#line 357 "y.y"
            {
                Trace("Find result");
                result_stmt = 1;
                Info* func_info = stb_list.getFunc();
                if(func_info== NULL || func_info->f_type != FUNC_f) yyerror("could't find function declaration");
                if((yyvsp[0].Inf)->d_type != func_info->d_type)yyerror("function return type is not compatible");
                // check function type
            }
#line 1715 "y.tab.cpp"
    break;

  case 54: /* simple_stmt: RETURN  */
#line 366 "y.y"
            {
                Trace("Find RETURN");
            }
#line 1723 "y.tab.cpp"
    break;

  case 56: /* simple_stmt: SKIP  */
#line 371 "y.y"
            {
                Trace("Find skip");
                out_f << "getstatic java.io.PrintStream java.lang.System.out\n";
                out_f << "invokevirtual void java.io.PrintStream.println()\n";
            }
#line 1733 "y.tab.cpp"
    break;

  case 58: /* EXIT_STMT: EXIT  */
#line 380 "y.y"
            {
                Trace("Find EXIT");
            }
#line 1741 "y.tab.cpp"
    break;

  case 59: /* EXIT_STMT: EXIT WHEN EXPRESSION  */
#line 384 "y.y"
            {
                Trace("Find EXIT with expression");
                if((yyvsp[0].Inf)->d_type != BOOL_TYPE)yyerror("<ERROR> EXIT WHEN EXPRESSION, EXPRESSION SHOULD BE BOOL_EXPR");

                int index=st_label.top();
                out_f << "ifne L" << index+1 << "\n";


            }
#line 1755 "y.tab.cpp"
    break;

  case 60: /* EXPRESSION: EXPRESSION '+' EXPRESSION  */
#line 396 "y.y"
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
#line 1778 "y.tab.cpp"
    break;

  case 61: /* EXPRESSION: EXPRESSION '-' EXPRESSION  */
#line 415 "y.y"
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
#line 1801 "y.tab.cpp"
    break;

  case 62: /* EXPRESSION: EXPRESSION '*' EXPRESSION  */
#line 434 "y.y"
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
#line 1824 "y.tab.cpp"
    break;

  case 63: /* EXPRESSION: EXPRESSION '/' EXPRESSION  */
#line 453 "y.y"
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
#line 1846 "y.tab.cpp"
    break;

  case 64: /* EXPRESSION: '-' EXPRESSION  */
#line 471 "y.y"
            {
                Trace("- expression");
                if((yyvsp[0].Inf)->d_type != REAL_TYPE && (yyvsp[0].Inf)->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if((yyvsp[0].Inf)->f_type == ARRAY_f) yyerror("unary minus is not support array");

                (yyval.Inf) = ((yyvsp[0].Inf)->d_type == INT_TYPE) ? new Info("",INT_TYPE,(yyvsp[0].Inf)->f_type,-(yyvsp[0].Inf)->i_v): new Info("",REAL_TYPE,(yyvsp[0].Inf)->f_type,-(yyvsp[0].Inf)->r_v);
                if(!isConst_Exp)out_f << "ineg\n";
            }
#line 1859 "y.tab.cpp"
    break;

  case 65: /* EXPRESSION: EXPRESSION MOD EXPRESSION  */
#line 480 "y.y"
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
#line 1877 "y.tab.cpp"
    break;

  case 66: /* EXPRESSION: EXPRESSION '>' EXPRESSION  */
#line 494 "y.y"
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
#line 1909 "y.tab.cpp"
    break;

  case 67: /* EXPRESSION: EXPRESSION '<' EXPRESSION  */
#line 522 "y.y"
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
#line 1938 "y.tab.cpp"
    break;

  case 68: /* EXPRESSION: EXPRESSION '=' EXPRESSION  */
#line 547 "y.y"
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
#line 1969 "y.tab.cpp"
    break;

  case 69: /* EXPRESSION: EXPRESSION NE EXPRESSION  */
#line 574 "y.y"
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
#line 1998 "y.tab.cpp"
    break;

  case 70: /* EXPRESSION: EXPRESSION LE EXPRESSION  */
#line 599 "y.y"
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
#line 2027 "y.tab.cpp"
    break;

  case 71: /* EXPRESSION: EXPRESSION GE EXPRESSION  */
#line 624 "y.y"
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
#line 2056 "y.tab.cpp"
    break;

  case 72: /* EXPRESSION: EXPRESSION AND EXPRESSION  */
#line 649 "y.y"
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
#line 2075 "y.tab.cpp"
    break;

  case 73: /* EXPRESSION: EXPRESSION OR EXPRESSION  */
#line 664 "y.y"
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
#line 2092 "y.tab.cpp"
    break;

  case 74: /* EXPRESSION: NOT EXPRESSION  */
#line 677 "y.y"
            {
                Trace("Negation operator");
                if((yyvsp[0].Inf)->d_type != BOOL_TYPE) yyerror("Type should be BOOLEAN");
                if((yyvsp[0].Inf)->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                 if((yyvsp[0].Inf)->f_type == CONST_f){
                    (yyval.Inf) = new Info("",BOOL_TYPE,CONST_f,!(yyvsp[0].Inf)->b_v);
                }else{
                    (yyval.Inf) = new Info("",BOOL_TYPE,VAR_f);
                }
                if(!isConst_Exp)out_f << "ixor\n";
            }
#line 2108 "y.tab.cpp"
    break;

  case 75: /* EXPRESSION: '(' EXPRESSION ')'  */
#line 689 "y.y"
            {
                (yyval.Inf) = (yyvsp[-1].Inf);
            }
#line 2116 "y.tab.cpp"
    break;

  case 76: /* EXPRESSION: const_val  */
#line 693 "y.y"
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
#line 2141 "y.tab.cpp"
    break;

  case 77: /* EXPRESSION: ID  */
#line 714 "y.y"
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
#line 2180 "y.tab.cpp"
    break;

  case 78: /* EXPRESSION: ID '[' EXPRESSION ']'  */
#line 749 "y.y"
            {
                Trace("Array reference");
                //check expression type
                Info* id = stb_list.lookup(*(yyvsp[-3].s_v));
                if(id == NULL) yyerror("ID not exists");
                if((yyvsp[-1].Inf)->d_type != INT_TYPE)yyerror("expression should be INT_EXPR");
                if((yyvsp[-1].Inf)->f_type == FUNC_f || (yyvsp[-1].Inf)->f_type== ARRAY_f)yyerror("can not pass Array or Function id");
                (yyval.Inf) = new Info("",id->d_type,VAR_f);
            }
#line 2194 "y.tab.cpp"
    break;

  case 80: /* func_inv: ID '(' actual_params ')'  */
#line 762 "y.y"
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
        }
#line 2222 "y.tab.cpp"
    break;

  case 81: /* proc_inv: ID '(' actual_params ')'  */
#line 789 "y.y"
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
        }
#line 2246 "y.tab.cpp"
    break;

  case 85: /* actual_param: EXPRESSION  */
#line 817 "y.y"
            {
                params.push_back(*(yyvsp[0].Inf));
            }
#line 2254 "y.tab.cpp"
    break;

  case 86: /* $@11: %empty  */
#line 824 "y.y"
                    {                    
                        stb_list.create_table();
                        // jump to L0
                        //label_temp = label_index;

                        st_label.push(label_index);
                        out_f << "ifeq L" << label_index << "\n";
                        label_index+=2;


                        //label_max_tmp = max(label_index,label_max_tmp);
                    }
#line 2271 "y.tab.cpp"
    break;

  case 87: /* conditional_stmt: IF EXPRESSION THEN $@11 func_stmts ELSE_stmt  */
#line 837 "y.y"
                    {
                        // jump to L1 ? (Lexit)
                        // if stmt (Lexit = L0)
                        // if-else (Lexit != L0)
                        if((yyvsp[-4].Inf)->d_type != BOOL_TYPE) yyerror("condition should be bool_expr");
                    }
#line 2282 "y.tab.cpp"
    break;

  case 88: /* $@12: %empty  */
#line 846 "y.y"
        {
            stb_list.popTable();
            stb_list.create_table();
            //jump to lexit
            
            int index = st_label.top();
            //int base = label_index - (label_used);
            out_f << "goto L" << index+1 << "\n";
            out_f << "L" << index <<":\n";
        
        }
#line 2298 "y.tab.cpp"
    break;

  case 89: /* ELSE_stmt: ELSE $@12 func_stmts END IF  */
#line 857 "y.y"
        {
            Trace("if-ELSE stmt");
            stb_list.popTable();
            
            //int base = label_index - (label_used);
            
            int index = st_label.top();
            out_f << "L" << index+1 << ":\n";
            
            st_label.pop();
         
        }
#line 2315 "y.tab.cpp"
    break;

  case 90: /* ELSE_stmt: END IF  */
#line 870 "y.y"
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
#line 2336 "y.tab.cpp"
    break;

  case 91: /* $@13: %empty  */
#line 889 "y.y"
            {
                stb_list.create_table();
                st_label.push(label_index);
                out_f << "L" << label_index <<":" << "\n"; // begin
                label_index+=2;
            }
#line 2347 "y.tab.cpp"
    break;

  case 92: /* $@14: %empty  */
#line 895 "y.y"
            {
                int index= st_label.top();
                out_f << "goto L" << index  << "\n";
            }
#line 2356 "y.tab.cpp"
    break;

  case 93: /* loop_stmt: LOOP $@13 func_stmts $@14 END LOOP  */
#line 900 "y.y"
            {
                Trace("loop");
                stb_list.popTable();
                int index= st_label.top();
                out_f << "L" << index+1 << ":" << "\n";
                st_label.pop();
            }
#line 2368 "y.tab.cpp"
    break;

  case 94: /* $@15: %empty  */
#line 908 "y.y"
            {
                Info* id = stb_list.lookup(*(yyvsp[-5].s_v));
                if(id==NULL)yyerror("<ERROR> can't find identifier definition");
                if((yyvsp[-3].Inf)->f_type != CONST_f || (yyvsp[0].Inf)->f_type != CONST_f) yyerror("form should be <for identifier : const_expr .. const_expr>");
                stb_list.create_table();
                
                // decreasing index check?

                out_f << "sipush " << getValue_IntBool(*(yyvsp[-3].Inf)) << "\n";
                out_f << "istore " << id->index_local << "\n";

                st_label.push(label_index);

                out_f << "L" << label_index << ":\n";
                out_f << "iload " << id->index_local << "\n";
                out_f << "sipush " << getValue_IntBool(*(yyvsp[0].Inf)) << "\n";
                out_f << "isub\n";
                out_f << "ifgt L" << label_index+1 << "\n";

                label_index+=2;
            }
#line 2394 "y.tab.cpp"
    break;

  case 95: /* $@16: %empty  */
#line 929 "y.y"
            {
                Info* id = stb_list.lookup(*(yyvsp[-7].s_v));
                int index= st_label.top();
                out_f << "iload " << id->index_local << "\n";
                out_f << "sipush 1" << "\n"; // increase 1
                out_f << "iadd\n";
                out_f << "istore " << id->index_local << "\n";
                out_f << "goto L" << index << "\n";
            }
#line 2408 "y.tab.cpp"
    break;

  case 96: /* loop_stmt: FOR opt_r ID ':' EXPRESSION '.' '.' EXPRESSION $@15 func_stmts $@16 END FOR  */
#line 939 "y.y"
            {
                Trace("For loop");
                stb_list.popTable();
                int index= st_label.top();
                
                st_label.pop();
                out_f << "L" << index+1 << ":\n";
            }
#line 2421 "y.tab.cpp"
    break;


#line 2425 "y.tab.cpp"

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

#line 956 "y.y"



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
