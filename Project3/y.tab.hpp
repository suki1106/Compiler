/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    AS = 258,                      /* AS  */
    VAR = 259,                     /* VAR  */
    CONST = 260,                   /* CONST  */
    FUNCTION = 261,                /* FUNCTION  */
    BOOL = 262,                    /* BOOL  */
    REAL = 263,                    /* REAL  */
    INT = 264,                     /* INT  */
    STRING = 265,                  /* STRING  */
    ARRAY = 266,                   /* ARRAY  */
    OF = 267,                      /* OF  */
    CHAR = 268,                    /* CHAR  */
    MOD = 269,                     /* MOD  */
    AND = 270,                     /* AND  */
    OR = 271,                      /* OR  */
    NOT = 272,                     /* NOT  */
    DECREASING = 273,              /* DECREASING  */
    DEFAULT = 274,                 /* DEFAULT  */
    DO = 275,                      /* DO  */
    ELSE = 276,                    /* ELSE  */
    END = 277,                     /* END  */
    EXIT = 278,                    /* EXIT  */
    FOR = 279,                     /* FOR  */
    GET = 280,                     /* GET  */
    IF = 281,                      /* IF  */
    LOOP = 282,                    /* LOOP  */
    PUT = 283,                     /* PUT  */
    PROCEDURE = 284,               /* PROCEDURE  */
    RESULT = 285,                  /* RESULT  */
    RETURN = 286,                  /* RETURN  */
    SKIP = 287,                    /* SKIP  */
    THEN = 288,                    /* THEN  */
    WHEN = 289,                    /* WHEN  */
    BEG = 290,                     /* BEG  */
    LE = 291,                      /* LE  */
    GE = 292,                      /* GE  */
    NE = 293,                      /* NE  */
    ID = 294,                      /* ID  */
    val_STR = 295,                 /* val_STR  */
    val_INTEGER = 296,             /* val_INTEGER  */
    val_REAL = 297,                /* val_REAL  */
    val_BOOL = 298,                /* val_BOOL  */
    UMINUS = 299                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
#line 40 "y.y"

    int i_v;
    bool b_v;
    string* s_v;
    double r_v;
    data_type d_t;
    Info* Inf;

#line 164 "y.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
