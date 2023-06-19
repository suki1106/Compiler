/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 41 "y.y" /* yacc.c:1909  */

    int i_v;
    bool b_v;
    string* s_v;
    double r_v;
    data_type d_t;
    Info* Inf;

#line 151 "y.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
