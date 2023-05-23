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
#line 4 "compiler.y"

    #include "compiler_common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    int SCOPE = 0;
    int func_addr = -1;
    int array_count = 0;
    #define ENTRY 100


    typedef struct symbol symbol;
    struct symbol {
        char name[30];
        char type[8];
        int scope;
        int addr;
        int line;
        int mut;
        char func_re;
        char func_arg[10];
        struct symbol *next;
        struct symbol *arr_next;
    };

    symbol *sym_table_arr[10];
    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    // extern int yylineno;
    // extern int yylex();
    // extern FILE *yyin;

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol(int current_scope);
    static void insert_symbol(char name[], char type[], int current_scope, int line, int mut, char re_type);
    int lookup_symbol(char name[], int current_scope);
    char *symbol_type(int type);
    static void dump_symbol();
    bool Error_check(int ID1, int ID2);
    void Insert_arg_to_func(char name[], char arg[], char ret);
    char * Search_func_arg(char name[]);
    char Search_func_ret(char name[]);

    /* Global variables */
    bool HAS_ERROR = false;

#line 127 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    LET = 258,                     /* LET  */
    MUT = 259,                     /* MUT  */
    NEWLINE = 260,                 /* NEWLINE  */
    INT = 261,                     /* INT  */
    FLOAT = 262,                   /* FLOAT  */
    BOOL = 263,                    /* BOOL  */
    STR = 264,                     /* STR  */
    TRUE = 265,                    /* TRUE  */
    FALSE = 266,                   /* FALSE  */
    GEQ = 267,                     /* GEQ  */
    LEQ = 268,                     /* LEQ  */
    EQL = 269,                     /* EQL  */
    NEQ = 270,                     /* NEQ  */
    LOR = 271,                     /* LOR  */
    LAND = 272,                    /* LAND  */
    ADD_ASSIGN = 273,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 274,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 275,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 276,              /* DIV_ASSIGN  */
    REM_ASSIGN = 277,              /* REM_ASSIGN  */
    IF = 278,                      /* IF  */
    ELSE = 279,                    /* ELSE  */
    FOR = 280,                     /* FOR  */
    WHILE = 281,                   /* WHILE  */
    LOOP = 282,                    /* LOOP  */
    PRINT = 283,                   /* PRINT  */
    PRINTLN = 284,                 /* PRINTLN  */
    FUNC = 285,                    /* FUNC  */
    RETURN = 286,                  /* RETURN  */
    BREAK = 287,                   /* BREAK  */
    ARROW = 288,                   /* ARROW  */
    AS = 289,                      /* AS  */
    IN = 290,                      /* IN  */
    DOTDOT = 291,                  /* DOTDOT  */
    RSHIFT = 292,                  /* RSHIFT  */
    LSHIFT = 293,                  /* LSHIFT  */
    INT_LIT = 294,                 /* INT_LIT  */
    STRING_LIT = 295,              /* STRING_LIT  */
    FLOAT_LIT = 296,               /* FLOAT_LIT  */
    ID = 297,                      /* ID  */
    LOWER_THAN_ELSE = 298          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define LET 258
#define MUT 259
#define NEWLINE 260
#define INT 261
#define FLOAT 262
#define BOOL 263
#define STR 264
#define TRUE 265
#define FALSE 266
#define GEQ 267
#define LEQ 268
#define EQL 269
#define NEQ 270
#define LOR 271
#define LAND 272
#define ADD_ASSIGN 273
#define SUB_ASSIGN 274
#define MUL_ASSIGN 275
#define DIV_ASSIGN 276
#define REM_ASSIGN 277
#define IF 278
#define ELSE 279
#define FOR 280
#define WHILE 281
#define LOOP 282
#define PRINT 283
#define PRINTLN 284
#define FUNC 285
#define RETURN 286
#define BREAK 287
#define ARROW 288
#define AS 289
#define IN 290
#define DOTDOT 291
#define RSHIFT 292
#define LSHIFT 293
#define INT_LIT 294
#define STRING_LIT 295
#define FLOAT_LIT 296
#define ID 297
#define LOWER_THAN_ELSE 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 66 "compiler.y"

    int i_val;
    float f_val;
    bool b_val;
    char *s_val;
    /* ... */

#line 274 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LET = 3,                        /* LET  */
  YYSYMBOL_MUT = 4,                        /* MUT  */
  YYSYMBOL_NEWLINE = 5,                    /* NEWLINE  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_BOOL = 8,                       /* BOOL  */
  YYSYMBOL_STR = 9,                        /* STR  */
  YYSYMBOL_TRUE = 10,                      /* TRUE  */
  YYSYMBOL_FALSE = 11,                     /* FALSE  */
  YYSYMBOL_GEQ = 12,                       /* GEQ  */
  YYSYMBOL_LEQ = 13,                       /* LEQ  */
  YYSYMBOL_EQL = 14,                       /* EQL  */
  YYSYMBOL_NEQ = 15,                       /* NEQ  */
  YYSYMBOL_LOR = 16,                       /* LOR  */
  YYSYMBOL_LAND = 17,                      /* LAND  */
  YYSYMBOL_ADD_ASSIGN = 18,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 19,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 20,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 21,                /* DIV_ASSIGN  */
  YYSYMBOL_REM_ASSIGN = 22,                /* REM_ASSIGN  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_FOR = 25,                       /* FOR  */
  YYSYMBOL_WHILE = 26,                     /* WHILE  */
  YYSYMBOL_LOOP = 27,                      /* LOOP  */
  YYSYMBOL_PRINT = 28,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 29,                   /* PRINTLN  */
  YYSYMBOL_FUNC = 30,                      /* FUNC  */
  YYSYMBOL_RETURN = 31,                    /* RETURN  */
  YYSYMBOL_BREAK = 32,                     /* BREAK  */
  YYSYMBOL_ARROW = 33,                     /* ARROW  */
  YYSYMBOL_AS = 34,                        /* AS  */
  YYSYMBOL_IN = 35,                        /* IN  */
  YYSYMBOL_DOTDOT = 36,                    /* DOTDOT  */
  YYSYMBOL_RSHIFT = 37,                    /* RSHIFT  */
  YYSYMBOL_LSHIFT = 38,                    /* LSHIFT  */
  YYSYMBOL_INT_LIT = 39,                   /* INT_LIT  */
  YYSYMBOL_STRING_LIT = 40,                /* STRING_LIT  */
  YYSYMBOL_FLOAT_LIT = 41,                 /* FLOAT_LIT  */
  YYSYMBOL_ID = 42,                        /* ID  */
  YYSYMBOL_43_ = 43,                       /* '('  */
  YYSYMBOL_44_ = 44,                       /* ')'  */
  YYSYMBOL_45_ = 45,                       /* '{'  */
  YYSYMBOL_46_ = 46,                       /* '}'  */
  YYSYMBOL_47_ = 47,                       /* ':'  */
  YYSYMBOL_48_ = 48,                       /* ','  */
  YYSYMBOL_49_ = 49,                       /* ';'  */
  YYSYMBOL_50_ = 50,                       /* '%'  */
  YYSYMBOL_51_ = 51,                       /* '='  */
  YYSYMBOL_52_ = 52,                       /* '['  */
  YYSYMBOL_53_ = 53,                       /* ']'  */
  YYSYMBOL_54_ = 54,                       /* '>'  */
  YYSYMBOL_55_ = 55,                       /* '<'  */
  YYSYMBOL_56_ = 56,                       /* '"'  */
  YYSYMBOL_57_ = 57,                       /* '&'  */
  YYSYMBOL_LOWER_THAN_ELSE = 58,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_59_ = 59,                       /* '!'  */
  YYSYMBOL_60_ = 60,                       /* '-'  */
  YYSYMBOL_61_ = 61,                       /* '+'  */
  YYSYMBOL_62_ = 62,                       /* '/'  */
  YYSYMBOL_63_ = 63,                       /* '*'  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_Program = 65,                   /* Program  */
  YYSYMBOL_66_1 = 66,                      /* $@1  */
  YYSYMBOL_GlobalStatementList = 67,       /* GlobalStatementList  */
  YYSYMBOL_GlobalStatement = 68,           /* GlobalStatement  */
  YYSYMBOL_PackageStmt = 69,               /* PackageStmt  */
  YYSYMBOL_FunctionDeclStmt = 70,          /* FunctionDeclStmt  */
  YYSYMBOL_Func = 71,                      /* Func  */
  YYSYMBOL_72_2 = 72,                      /* $@2  */
  YYSYMBOL_Funcname = 73,                  /* Funcname  */
  YYSYMBOL_Parameter = 74,                 /* Parameter  */
  YYSYMBOL_ReturnStmt = 75,                /* ReturnStmt  */
  YYSYMBOL_76_3 = 76,                      /* $@3  */
  YYSYMBOL_Callfunc = 77,                  /* Callfunc  */
  YYSYMBOL_argument_expr_list = 78,        /* argument_expr_list  */
  YYSYMBOL_DecStmt = 79,                   /* DecStmt  */
  YYSYMBOL_80_4 = 80,                      /* $@4  */
  YYSYMBOL_AssignStmt = 81,                /* AssignStmt  */
  YYSYMBOL_AssignmetExpr = 82,             /* AssignmetExpr  */
  YYSYMBOL_assign_op = 83,                 /* assign_op  */
  YYSYMBOL_Block = 84,                     /* Block  */
  YYSYMBOL_85_5 = 85,                      /* $@5  */
  YYSYMBOL_IfStmt = 86,                    /* IfStmt  */
  YYSYMBOL_Condition = 87,                 /* Condition  */
  YYSYMBOL_88_6 = 88,                      /* $@6  */
  YYSYMBOL_89_7 = 89,                      /* $@7  */
  YYSYMBOL_90_8 = 90,                      /* $@8  */
  YYSYMBOL_91_9 = 91,                      /* $@9  */
  YYSYMBOL_WhileStmt = 92,                 /* WhileStmt  */
  YYSYMBOL_ForStmt = 93,                   /* ForStmt  */
  YYSYMBOL_94_10 = 94,                     /* $@10  */
  YYSYMBOL_Lit = 95,                       /* Lit  */
  YYSYMBOL_96_11 = 96,                     /* $@11  */
  YYSYMBOL_97_12 = 97,                     /* $@12  */
  YYSYMBOL_LoopStmt = 98,                  /* LoopStmt  */
  YYSYMBOL_BreakStmt = 99,                 /* BreakStmt  */
  YYSYMBOL_PrintLNStmt = 100,              /* PrintLNStmt  */
  YYSYMBOL_PrintStmt = 101,                /* PrintStmt  */
  YYSYMBOL_new_non = 102,                  /* new_non  */
  YYSYMBOL_Expression = 103,               /* Expression  */
  YYSYMBOL_104_13 = 104,                   /* $@13  */
  YYSYMBOL_AsStmt = 105,                   /* AsStmt  */
  YYSYMBOL_Exp = 106,                      /* Exp  */
  YYSYMBOL_Exp1 = 107,                     /* Exp1  */
  YYSYMBOL_Exp2 = 108,                     /* Exp2  */
  YYSYMBOL_Exp3 = 109,                     /* Exp3  */
  YYSYMBOL_Exp4 = 110,                     /* Exp4  */
  YYSYMBOL_uexpr = 111,                    /* uexpr  */
  YYSYMBOL_unary_op = 112,                 /* unary_op  */
  YYSYMBOL_com_op = 113,                   /* com_op  */
  YYSYMBOL_add_op = 114,                   /* add_op  */
  YYSYMBOL_mul_op = 115,                   /* mul_op  */
  YYSYMBOL_ExpressionExpr = 116,           /* ExpressionExpr  */
  YYSYMBOL_TypeName = 117                  /* TypeName  */
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

#if 1

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
#endif /* 1 */

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
#define YYLAST   336

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  249

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
       2,     2,     2,    59,    56,     2,     2,    50,    57,     2,
      43,    44,    63,    61,    48,    60,     2,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    49,
      55,    51,    54,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   109,   109,   109,   113,   114,   118,   119,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     138,   142,   142,   146,   150,   163,   170,   177,   178,   178,
     186,   189,   195,   196,   200,   211,   222,   233,   244,   245,
     248,   248,   254,   258,   267,   268,   269,   270,   271,   272,
     276,   276,   280,   281,   282,   286,   286,   297,   297,   298,
     298,   299,   299,   300,   304,   308,   308,   315,   319,   323,
     327,   331,   332,   333,   334,   335,   335,   335,   336,   340,
     344,   348,   354,   360,   361,   365,   366,   367,   368,   369,
     370,   371,   375,   375,   379,   399,   404,   407,   408,   409,
     413,   417,   423,   427,   433,   437,   443,   446,   452,   456,
     462,   465,   475,   478,   481,   487,   490,   493,   496,   499,
     502,   508,   511,   517,   520,   523,   530,   531,   537,   543,
     549,   555,   566,   567,   568,   569,   570
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LET", "MUT",
  "NEWLINE", "INT", "FLOAT", "BOOL", "STR", "TRUE", "FALSE", "GEQ", "LEQ",
  "EQL", "NEQ", "LOR", "LAND", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "REM_ASSIGN", "IF", "ELSE", "FOR", "WHILE", "LOOP",
  "PRINT", "PRINTLN", "FUNC", "RETURN", "BREAK", "ARROW", "AS", "IN",
  "DOTDOT", "RSHIFT", "LSHIFT", "INT_LIT", "STRING_LIT", "FLOAT_LIT", "ID",
  "'('", "')'", "'{'", "'}'", "':'", "','", "';'", "'%'", "'='", "'['",
  "']'", "'>'", "'<'", "'\"'", "'&'", "LOWER_THAN_ELSE", "'!'", "'-'",
  "'+'", "'/'", "'*'", "$accept", "Program", "$@1", "GlobalStatementList",
  "GlobalStatement", "PackageStmt", "FunctionDeclStmt", "Func", "$@2",
  "Funcname", "Parameter", "ReturnStmt", "$@3", "Callfunc",
  "argument_expr_list", "DecStmt", "$@4", "AssignStmt", "AssignmetExpr",
  "assign_op", "Block", "$@5", "IfStmt", "Condition", "$@6", "$@7", "$@8",
  "$@9", "WhileStmt", "ForStmt", "$@10", "Lit", "$@11", "$@12", "LoopStmt",
  "BreakStmt", "PrintLNStmt", "PrintStmt", "new_non", "Expression", "$@13",
  "AsStmt", "Exp", "Exp1", "Exp2", "Exp3", "Exp4", "uexpr", "unary_op",
  "com_op", "add_op", "mul_op", "ExpressionExpr", "TypeName", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-107)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-93)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -107,    99,   291,  -107,     4,  -107,    30,    89,    30,    71,
     103,   112,    66,    66,   198,  -107,   291,  -107,  -107,  -107,
    -107,   115,  -107,  -107,  -107,  -107,   106,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,   117,   -23,   133,  -107,   118,   131,
     118,   163,    76,  -107,  -107,  -107,   118,  -107,  -107,   -17,
     128,    -5,  -107,    16,  -107,  -107,  -107,  -107,  -107,    47,
     132,  -107,    76,   291,  -107,   134,  -107,    45,   154,    66,
     121,   164,   166,   129,    10,   141,  -107,  -107,    76,    76,
      11,   130,  -107,  -107,  -107,    90,   152,     9,   169,   180,
     225,    18,   -28,  -107,   130,  -107,  -107,   142,  -107,  -107,
      66,  -107,  -107,  -107,   151,    58,   187,  -107,   200,   118,
     160,    12,    66,  -107,  -107,  -107,    12,     0,    72,   153,
      94,    66,    66,    66,    66,   183,  -107,   184,   167,   163,
    -107,    12,   172,   173,   179,   193,   201,   157,   188,    -8,
    -107,    -3,    12,   195,    41,   130,   130,  -107,  -107,  -107,
    -107,  -107,  -107,   130,  -107,  -107,   130,  -107,  -107,  -107,
      41,  -107,  -107,   199,   202,  -107,  -107,   205,  -107,  -107,
    -107,   206,    60,   243,    79,    96,   209,  -107,  -107,    66,
    -107,   202,   202,   202,   202,   118,  -107,   211,  -107,  -107,
    -107,  -107,  -107,  -107,    66,  -107,  -107,  -107,  -107,   180,
     225,    18,   -28,  -107,    66,  -107,    66,    12,   232,   226,
    -107,    66,  -107,   228,   101,  -107,   291,   220,   -21,   -19,
     202,  -107,    12,   223,   104,  -107,  -107,   231,  -107,  -107,
    -107,   227,    12,  -107,   218,  -107,    66,   291,  -107,   224,
       6,   261,   222,  -107,  -107,    66,    37,   229,  -107
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     7,     0,     0,     0,     0,
       0,     0,    78,    78,     0,    50,     3,     5,     6,    17,
      20,     0,    18,    19,    10,    12,     0,    11,    13,    14,
      15,    16,     8,     9,     0,     0,    55,    63,     0,     0,
       0,    83,    78,    24,    71,    72,     0,    67,    68,     0,
       0,     0,    74,     0,    45,    46,    47,    48,    49,     0,
       0,    44,    78,     0,     4,    21,    42,     0,    78,    78,
       0,     0,     0,     0,    83,     0,    64,    84,    78,    78,
      98,    78,   114,   113,   112,    99,     0,   110,    86,   101,
     103,   105,   107,   109,    78,    94,    79,     0,    69,    75,
      78,    27,    80,    33,     0,     0,     0,    43,     0,     0,
       0,     0,    78,   132,   133,   136,     0,   134,     0,     0,
       0,    78,    78,    78,    78,    54,    52,     0,     0,    83,
      87,     0,     0,     0,     0,     0,     0,     0,    98,    99,
     110,     0,     0,     0,    78,    78,    78,   117,   118,   119,
     120,   115,   116,    78,   122,   121,    78,   125,   124,   123,
      78,   111,    70,     0,    73,    30,    31,     0,    28,    51,
      23,     0,     0,   134,     0,     0,     0,   135,    38,    78,
      39,    56,    58,    60,    62,     0,    65,     0,    95,   131,
     130,   127,   129,   128,    78,    97,    96,    81,   126,   100,
     102,   104,   106,   108,    78,    32,    78,     0,     0,     0,
      37,    78,    36,     0,     0,    53,     0,     0,     0,     0,
      29,    25,     0,     0,     0,    40,    34,     0,    82,    93,
      76,     0,     0,    35,     0,    66,    78,     0,    26,     0,
       0,     0,     0,    77,    22,    78,     0,     0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,  -107,   -60,   -14,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,   119,  -107,  -107,  -107,  -107,  -107,  -107,
     -34,  -107,   207,   274,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,   -12,  -107,  -107,  -107,  -107,  -107,  -107,   -67,   -41,
    -107,   -31,   204,   138,   149,   135,   143,   203,  -107,  -107,
    -107,  -107,  -107,  -106
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    16,    17,    18,    19,    20,   110,    21,
     172,    22,   206,    23,   105,    24,   234,    25,    26,    62,
      27,    63,    28,    38,    70,    71,    72,    73,    29,    30,
     216,   139,   163,   236,    52,    31,    32,    33,    78,    86,
     137,   140,    88,    89,    90,    91,    92,    93,    94,   153,
     156,   160,    95,   119
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    53,    64,   108,    74,   174,    76,   127,    34,   177,
     176,    87,    96,   145,   -85,   125,   -91,   230,   113,   114,
     115,   107,   157,    97,    68,   188,   142,   100,    69,   100,
      85,    87,   229,     6,   158,   159,   196,   129,   130,    98,
     100,   195,    99,   100,   101,   131,    35,    87,    87,   132,
      85,    44,    45,   -85,   100,   -91,   118,   120,   -85,   243,
     -91,   133,   187,   -92,   100,   102,    85,    85,    46,   173,
     144,   134,    36,   135,   136,   170,    44,    45,   154,   155,
      47,    79,    48,   138,    81,   100,    44,    45,   164,   103,
     247,   104,   111,    46,    64,   -90,   112,    49,    50,     3,
     175,   221,   166,    46,   208,    47,   167,    48,   209,   181,
     182,   183,   184,   198,    41,    47,   231,    48,    80,    81,
     100,   178,    49,    50,   142,    37,   238,    37,   210,   203,
     211,    39,    49,    50,   -90,    82,    83,    84,   100,   -90,
      44,    45,   100,   180,   100,   212,    42,   -59,   -57,   100,
     226,   215,   100,   233,    43,    66,   227,    46,    65,    67,
     113,   114,   115,    15,    44,    45,    75,   214,    77,    47,
      99,    48,   138,    81,   106,   121,    59,   241,   109,   122,
     123,    46,   218,   128,   124,   145,    49,    50,   -61,    82,
      83,    84,   219,    47,   220,    48,   143,   146,   162,   224,
     165,   168,   171,     4,   179,     5,   116,   -84,   185,   194,
      49,   117,   186,    64,   189,   190,    54,    55,    56,    57,
      58,   191,   131,     6,   240,     7,     8,    64,     9,    10,
      11,    12,    13,   246,     4,   192,     5,   147,   148,   149,
     150,    59,    14,   193,   197,    15,   169,   205,    60,    61,
     100,   204,   177,   207,     6,   217,     7,     8,   213,     9,
      10,    11,    12,    13,     4,   222,     5,   225,   223,   228,
     232,   239,   237,    14,   245,   242,    15,   235,   248,   151,
     152,   126,    40,   199,     6,   141,     7,     8,   201,     9,
      10,    11,    12,    13,     4,   200,     5,   161,     0,   202,
       0,     0,     0,    14,     0,     0,    15,   244,     0,     0,
       0,     0,     0,     0,     6,     0,     7,     8,     0,     9,
      10,    11,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     0,    15
};

static const yytype_int16 yycheck[] =
{
      12,    13,    16,    63,    38,   111,    40,    74,     4,     9,
     116,    42,    46,    16,     5,     5,     5,    36,     6,     7,
       8,    62,    50,    40,    47,   131,    34,    48,    51,    48,
      42,    62,    53,    23,    62,    63,   142,    78,    79,    56,
      48,    44,    42,    48,    49,    34,    42,    78,    79,    38,
      62,    10,    11,    44,    48,    44,    68,    69,    49,    53,
      49,    50,   129,    52,    48,    49,    78,    79,    27,    57,
      61,    60,    42,    62,    63,   109,    10,    11,    60,    61,
      39,     5,    41,    42,    43,    48,    10,    11,   100,    42,
      53,    44,    47,    27,   108,     5,    51,    56,    57,     0,
     112,   207,    44,    27,    44,    39,    48,    41,    48,   121,
     122,   123,   124,   144,    43,    39,   222,    41,    42,    43,
      48,    49,    56,    57,    34,     6,   232,     8,    49,   160,
      51,    42,    56,    57,    44,    59,    60,    61,    48,    49,
      10,    11,    48,    49,    48,    49,    43,    14,    15,    48,
      49,   185,    48,    49,    42,    49,   216,    27,    43,    42,
       6,     7,     8,    45,    10,    11,    35,   179,     5,    39,
      42,    41,    42,    43,    42,    54,    43,   237,    44,    15,
      14,    27,   194,    42,    55,    16,    56,    57,    55,    59,
      60,    61,   204,    39,   206,    41,    44,    17,    56,   211,
      49,    14,    42,     3,    51,     5,    52,    24,    24,    52,
      56,    57,    45,   227,    42,    42,    18,    19,    20,    21,
      22,    42,    34,    23,   236,    25,    26,   241,    28,    29,
      30,    31,    32,   245,     3,    42,     5,    12,    13,    14,
      15,    43,    42,    42,    49,    45,    46,    42,    50,    51,
      48,    52,     9,    47,    23,    44,    25,    26,    49,    28,
      29,    30,    31,    32,     3,    33,     5,    39,    42,    49,
      47,    53,    45,    42,    52,    51,    45,    46,    49,    54,
      55,    74,     8,   145,    23,    81,    25,    26,   153,    28,
      29,    30,    31,    32,     3,   146,     5,    94,    -1,   156,
      -1,    -1,    -1,    42,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    65,    66,     0,     3,     5,    23,    25,    26,    28,
      29,    30,    31,    32,    42,    45,    67,    68,    69,    70,
      71,    73,    75,    77,    79,    81,    82,    84,    86,    92,
      93,    99,   100,   101,     4,    42,    42,    77,    87,    42,
      87,    43,    43,    42,    10,    11,    27,    39,    41,    56,
      57,    95,    98,    95,    18,    19,    20,    21,    22,    43,
      50,    51,    83,    85,    68,    43,    49,    42,    47,    51,
      88,    89,    90,    91,    84,    35,    84,     5,   102,     5,
      42,    43,    59,    60,    61,    95,   103,   105,   106,   107,
     108,   109,   110,   111,   112,   116,    84,    40,    56,    42,
      48,    49,    49,    42,    44,    78,    42,   103,    67,    44,
      72,    47,    51,     6,     7,     8,    52,    57,    95,   117,
      95,    54,    15,    14,    55,     5,    86,   102,    42,   103,
     103,    34,    38,    50,    60,    62,    63,   104,    42,    95,
     105,   106,    34,    44,    61,    16,    17,    12,    13,    14,
      15,    54,    55,   113,    60,    61,   114,    50,    62,    63,
     115,   111,    56,    96,    95,    49,    44,    48,    14,    46,
      84,    42,    74,    57,   117,    95,   117,     9,    49,    51,
      49,    95,    95,    95,    95,    24,    45,   102,   117,    42,
      42,    42,    42,    42,    52,    44,   117,    49,   105,   107,
     108,   109,   110,   105,    52,    42,    76,    47,    44,    48,
      49,    51,    49,    49,    95,    84,    94,    44,    95,    95,
      95,   117,    33,    42,    95,    39,    49,    67,    49,    53,
      36,   117,    47,    49,    80,    46,    97,    45,   117,    53,
      95,    67,    51,    53,    46,    52,    95,    53,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    66,    65,    67,    67,    68,    68,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      70,    72,    71,    71,    73,    74,    74,    75,    76,    75,
      77,    77,    78,    78,    79,    79,    79,    79,    79,    79,
      80,    79,    81,    82,    83,    83,    83,    83,    83,    83,
      85,    84,    86,    86,    86,    88,    87,    89,    87,    90,
      87,    91,    87,    87,    92,    94,    93,    95,    95,    95,
      95,    95,    95,    95,    95,    96,    97,    95,    95,    98,
      99,   100,   101,   102,   102,   103,   103,   103,   103,   103,
     103,   103,   104,   103,   103,   105,   105,   105,   105,   105,
     106,   106,   107,   107,   108,   108,   109,   109,   110,   110,
     111,   111,   112,   112,   112,   113,   113,   113,   113,   113,
     113,   114,   114,   115,   115,   115,   116,   116,   116,   116,
     116,   116,   117,   117,   117,   117,   117
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,    10,     4,     2,     3,     5,     3,     0,     6,
       4,     4,     3,     1,     7,     8,     6,     6,     5,     5,
       0,    14,     2,     3,     1,     1,     1,     1,     1,     1,
       0,     4,     4,     6,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     1,     3,     0,     8,     1,     1,     2,
       3,     1,     1,     3,     1,     0,     0,     9,     0,     2,
       3,     5,     7,     0,     1,     1,     1,     2,     1,     0,
       1,     1,     0,     5,     1,     3,     3,     3,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     2,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
#line 109 "compiler.y"
      {create_symbol(SCOPE);}
#line 1832 "y.tab.c"
    break;

  case 3: /* Program: $@1 GlobalStatementList  */
#line 109 "compiler.y"
                                                  {while(SCOPE >= 0){dump_symbol(SCOPE);}}
#line 1838 "y.tab.c"
    break;

  case 20: /* FunctionDeclStmt: Func  */
#line 138 "compiler.y"
           {func_addr = -1;}
#line 1844 "y.tab.c"
    break;

  case 21: /* $@2: %empty  */
#line 142 "compiler.y"
                   {create_symbol(SCOPE + 1); SCOPE++;}
#line 1850 "y.tab.c"
    break;

  case 22: /* Func: Funcname '(' $@2 Parameter ')' ARROW TypeName '{' GlobalStatementList '}'  */
#line 142 "compiler.y"
                                                                                                                 { 
        Insert_arg_to_func((yyvsp[-9].s_val), (yyvsp[-6].s_val), (yyvsp[-3].s_val)[0] - 32);
        dump_symbol(SCOPE);
    }
#line 1859 "y.tab.c"
    break;

  case 24: /* Funcname: FUNC ID  */
#line 150 "compiler.y"
              { 
        if (!strcmp((yyvsp[0].s_val), "main"))
        {
            while (SCOPE > 0)
                dump_symbol(SCOPE--);
        }
        printf("func: %s\n", (yyvsp[0].s_val));
        insert_symbol((yyvsp[0].s_val), "func", SCOPE, yylineno, -1, 'V');
        Insert_arg_to_func((yyvsp[0].s_val), "v", 'V');
        (yyval.s_val) = (yyvsp[0].s_val);
    }
#line 1875 "y.tab.c"
    break;

  case 25: /* Parameter: ID ':' TypeName  */
#line 163 "compiler.y"
                     {
        insert_symbol((yyvsp[-2].s_val), (yyvsp[0].s_val), SCOPE, yylineno, 0, '-'); 
        int length = strlen((yyval.s_val));
        for (int i = 0; i < length ; i++)
            (yyval.s_val)[i] = '\0';
        strncpy( (yyval.s_val), (yyvsp[0].s_val), 1);
    }
#line 1887 "y.tab.c"
    break;

  case 26: /* Parameter: Parameter ',' ID ':' TypeName  */
#line 170 "compiler.y"
                                   { 
        insert_symbol((yyvsp[-2].s_val), (yyvsp[0].s_val), SCOPE, yylineno, 0, '-');
        strncat( (yyval.s_val), (yyvsp[0].s_val), 1);
    }
#line 1896 "y.tab.c"
    break;

  case 27: /* ReturnStmt: RETURN Lit ';'  */
#line 177 "compiler.y"
                    {printf("%creturn\n", (yyvsp[-1].s_val)[0]);}
#line 1902 "y.tab.c"
    break;

  case 28: /* $@3: %empty  */
#line 178 "compiler.y"
                  {
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-3].s_val), lookup_symbol((yyvsp[-3].s_val), SCOPE) % 10);
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-1].s_val), lookup_symbol((yyvsp[-1].s_val), SCOPE) % 10);
        printf("REM\n");
    }
#line 1912 "y.tab.c"
    break;

  case 29: /* ReturnStmt: ID '%' ID EQL $@3 Lit  */
#line 182 "compiler.y"
          {printf("EQL\n"); printf("breturn\n");}
#line 1918 "y.tab.c"
    break;

  case 30: /* Callfunc: ID '(' ')' ';'  */
#line 186 "compiler.y"
                    {
        printf("call: %s(%s)%c\n", (yyvsp[-3].s_val), Search_func_arg((yyvsp[-3].s_val)), Search_func_ret((yyvsp[-3].s_val)));
    }
#line 1926 "y.tab.c"
    break;

  case 31: /* Callfunc: ID '(' argument_expr_list ')'  */
#line 189 "compiler.y"
                                  {
        printf("call: %s(%s)%c\n", (yyvsp[-3].s_val), Search_func_arg((yyvsp[-3].s_val)), Search_func_ret((yyvsp[-3].s_val)));
    }
#line 1934 "y.tab.c"
    break;

  case 32: /* argument_expr_list: argument_expr_list ',' ID  */
#line 195 "compiler.y"
                               {printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), lookup_symbol((yyvsp[0].s_val), SCOPE) % 10);}
#line 1940 "y.tab.c"
    break;

  case 33: /* argument_expr_list: ID  */
#line 196 "compiler.y"
        {printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), lookup_symbol((yyvsp[0].s_val), SCOPE) % 10);}
#line 1946 "y.tab.c"
    break;

  case 34: /* DecStmt: LET ID ':' TypeName '=' Lit ';'  */
#line 201 "compiler.y"
    {
        if ((yyvsp[-3].s_val)[0] == 'i')
            insert_symbol((yyvsp[-5].s_val), "i32", SCOPE, yylineno, 0, '-');
        else if ((yyvsp[-3].s_val)[0] == 'f')
            insert_symbol((yyvsp[-5].s_val), "f32", SCOPE, yylineno, 0, '-');
        else if ((yyvsp[-3].s_val)[0] == 'b')
            insert_symbol((yyvsp[-5].s_val), "bool", SCOPE, yylineno, 0, '-');
        else if ((yyvsp[-3].s_val)[0] == 's')
            insert_symbol((yyvsp[-5].s_val), "str", SCOPE, yylineno, 0, '-');
    }
#line 1961 "y.tab.c"
    break;

  case 35: /* DecStmt: LET MUT ID ':' TypeName '=' Lit ';'  */
#line 212 "compiler.y"
    {
        if ((yyvsp[-3].s_val)[0] == 'i')
            insert_symbol((yyvsp[-5].s_val), "i32", SCOPE, yylineno, 1, '-');
        else if ((yyvsp[-3].s_val)[0] == 'f')
            insert_symbol((yyvsp[-5].s_val), "f32", SCOPE, yylineno, 1, '-');
        else if ((yyvsp[-3].s_val)[0] == 'b')
            insert_symbol((yyvsp[-5].s_val), "bool", SCOPE, yylineno, 1, '-');
        else if ((yyvsp[-3].s_val)[0] == 's')
            insert_symbol((yyvsp[-5].s_val), "str", SCOPE, yylineno, 1, '-');
    }
#line 1976 "y.tab.c"
    break;

  case 36: /* DecStmt: LET MUT ID '=' Lit ';'  */
#line 223 "compiler.y"
    {
        if ((yyvsp[-1].s_val)[0] == 'i')
            insert_symbol((yyvsp[-3].s_val), "i32", SCOPE, yylineno, 1, '-');
        else if ((yyvsp[-1].s_val)[0] == 'f')
            insert_symbol((yyvsp[-3].s_val), "f32", SCOPE, yylineno, 1, '-');
        else if ((yyvsp[-1].s_val)[0] == 'b')
            insert_symbol((yyvsp[-3].s_val), "bool", SCOPE, yylineno, 1, '-');
        else if ((yyvsp[-1].s_val)[0] == 's')
            insert_symbol((yyvsp[-3].s_val), "str", SCOPE, yylineno, 1, '-');
    }
#line 1991 "y.tab.c"
    break;

  case 37: /* DecStmt: LET MUT ID ':' TypeName ';'  */
#line 234 "compiler.y"
    {
        if ((yyvsp[-1].s_val)[0] == 'i')
            insert_symbol((yyvsp[-3].s_val), "i32", SCOPE, yylineno, 1, '-');
        else if ((yyvsp[-1].s_val)[0] == 'f')
            insert_symbol((yyvsp[-3].s_val), "f32", SCOPE, yylineno, 1, '-');
        else if ((yyvsp[-1].s_val)[0] == 'b')
            insert_symbol((yyvsp[-3].s_val), "bool", SCOPE, yylineno, 1, '-');
        else if ((yyvsp[-1].s_val)[0] == 's')
            insert_symbol((yyvsp[-3].s_val), "str", SCOPE, yylineno, 1, '-');
    }
#line 2006 "y.tab.c"
    break;

  case 39: /* DecStmt: LET ID '=' Lit ';'  */
#line 245 "compiler.y"
                       {
        insert_symbol((yyvsp[-3].s_val), (yyvsp[-1].s_val), SCOPE, yylineno, 0, '-');
    }
#line 2014 "y.tab.c"
    break;

  case 40: /* $@4: %empty  */
#line 248 "compiler.y"
                                         {printf("INT_LIT %d\n", (yyvsp[0].i_val));}
#line 2020 "y.tab.c"
    break;

  case 41: /* DecStmt: LET ID ':' '[' TypeName ';' INT_LIT $@4 ']' '=' '[' Lit ']' ';'  */
#line 248 "compiler.y"
                                                                                              {
        insert_symbol((yyvsp[-12].s_val), "array", SCOPE, yylineno, 0, '-');
    }
#line 2028 "y.tab.c"
    break;

  case 43: /* AssignmetExpr: ID assign_op Expression  */
#line 258 "compiler.y"
                              {
            if (!Error_check(lookup_symbol((yyvsp[-2].s_val), SCOPE), lookup_symbol((yyvsp[-2].s_val), SCOPE)))
                printf("error:%d: undefined: %s\n", yylineno + 1, (yyvsp[-2].s_val));
            else
                printf("%s\n",(yyvsp[-1].s_val)); 
        }
#line 2039 "y.tab.c"
    break;

  case 44: /* assign_op: '='  */
#line 267 "compiler.y"
          { (yyval.s_val) = "ASSIGN";}
#line 2045 "y.tab.c"
    break;

  case 45: /* assign_op: ADD_ASSIGN  */
#line 268 "compiler.y"
                 { (yyval.s_val) = "ADD_ASSIGN";}
#line 2051 "y.tab.c"
    break;

  case 46: /* assign_op: SUB_ASSIGN  */
#line 269 "compiler.y"
                 { (yyval.s_val) = "SUB_ASSIGN";}
#line 2057 "y.tab.c"
    break;

  case 47: /* assign_op: MUL_ASSIGN  */
#line 270 "compiler.y"
                 { (yyval.s_val) = "MUL_ASSIGN";}
#line 2063 "y.tab.c"
    break;

  case 48: /* assign_op: DIV_ASSIGN  */
#line 271 "compiler.y"
                 { (yyval.s_val) = "DIV_ASSIGN";}
#line 2069 "y.tab.c"
    break;

  case 49: /* assign_op: REM_ASSIGN  */
#line 272 "compiler.y"
                 { (yyval.s_val) = "REM_ASSIGN";}
#line 2075 "y.tab.c"
    break;

  case 50: /* $@5: %empty  */
#line 276 "compiler.y"
          { create_symbol(SCOPE + 1); SCOPE++;}
#line 2081 "y.tab.c"
    break;

  case 51: /* Block: '{' $@5 GlobalStatementList '}'  */
#line 276 "compiler.y"
                                                                        { dump_symbol(SCOPE);}
#line 2087 "y.tab.c"
    break;

  case 55: /* $@6: %empty  */
#line 286 "compiler.y"
        { 
        if (lookup_symbol((yyvsp[0].s_val), SCOPE) == -1)
            printf("error:%d: undefined: %s\n", yylineno + 1, (yyvsp[0].s_val));
        else
            printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), lookup_symbol((yyvsp[0].s_val), SCOPE) % 10);
    }
#line 2098 "y.tab.c"
    break;

  case 56: /* Condition: ID $@6 '>' Lit  */
#line 292 "compiler.y"
                {
            if (lookup_symbol((yyvsp[-3].s_val), SCOPE) == -1)
                printf("error:%d: invalid operation: GTR (mismatched types undefined and %s)\n", yylineno + 1, (yyvsp[0].s_val));
            printf("GTR\n");
        }
#line 2108 "y.tab.c"
    break;

  case 57: /* $@7: %empty  */
#line 297 "compiler.y"
        {printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), lookup_symbol((yyvsp[0].s_val), SCOPE) % 10);}
#line 2114 "y.tab.c"
    break;

  case 58: /* Condition: ID $@7 NEQ Lit  */
#line 297 "compiler.y"
                                                                                              {printf("NEQ\n");}
#line 2120 "y.tab.c"
    break;

  case 59: /* $@8: %empty  */
#line 298 "compiler.y"
        {printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), lookup_symbol((yyvsp[0].s_val), SCOPE) % 10);}
#line 2126 "y.tab.c"
    break;

  case 60: /* Condition: ID $@8 EQL Lit  */
#line 298 "compiler.y"
                                                                                              {printf("EQL\n");}
#line 2132 "y.tab.c"
    break;

  case 61: /* $@9: %empty  */
#line 299 "compiler.y"
        {printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), lookup_symbol((yyvsp[0].s_val), SCOPE) % 10);}
#line 2138 "y.tab.c"
    break;

  case 62: /* Condition: ID $@9 '<' Lit  */
#line 299 "compiler.y"
                                                                                              {printf("LSS\n");}
#line 2144 "y.tab.c"
    break;

  case 65: /* $@10: %empty  */
#line 308 "compiler.y"
                      {
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-1].s_val), lookup_symbol((yyvsp[-1].s_val), SCOPE) % 10);
        create_symbol(SCOPE + 1); SCOPE++;
        insert_symbol((yyvsp[-3].s_val), "i32", SCOPE, yylineno, 0, '-');
        }
#line 2154 "y.tab.c"
    break;

  case 67: /* Lit: INT_LIT  */
#line 315 "compiler.y"
              {
        printf("INT_LIT %d\n", (yyvsp[0].i_val));
        (yyval.s_val) = "i32";
    }
#line 2163 "y.tab.c"
    break;

  case 68: /* Lit: FLOAT_LIT  */
#line 319 "compiler.y"
                {
        printf("FLOAT_LIT %f\n", (yyvsp[0].f_val));
        (yyval.s_val) = "f32";
    }
#line 2172 "y.tab.c"
    break;

  case 69: /* Lit: '"' '"'  */
#line 323 "compiler.y"
              {
        printf("STRING_LIT \"\"\n");
        (yyval.s_val) = "str";
    }
#line 2181 "y.tab.c"
    break;

  case 70: /* Lit: '"' STRING_LIT '"'  */
#line 327 "compiler.y"
                         {
        printf("STRING_LIT \"%s\"\n", (yyvsp[-1].s_val));
        (yyval.s_val) = "str";
    }
#line 2190 "y.tab.c"
    break;

  case 71: /* Lit: TRUE  */
#line 331 "compiler.y"
          {printf("bool TRUE\n"); (yyval.s_val) = "bool";}
#line 2196 "y.tab.c"
    break;

  case 72: /* Lit: FALSE  */
#line 332 "compiler.y"
           {printf("bool FALSE\n"); (yyval.s_val) = "bool";}
#line 2202 "y.tab.c"
    break;

  case 75: /* $@11: %empty  */
#line 335 "compiler.y"
            {printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), lookup_symbol((yyvsp[0].s_val), SCOPE) % 10);}
#line 2208 "y.tab.c"
    break;

  case 76: /* $@12: %empty  */
#line 335 "compiler.y"
                                                                                                         {printf("DOTDOT\n");}
#line 2214 "y.tab.c"
    break;

  case 81: /* PrintLNStmt: PRINTLN '(' Expression ')' ';'  */
#line 348 "compiler.y"
                                     {
        printf("PRINTLN %s\n", (yyvsp[-2].s_val));
    }
#line 2222 "y.tab.c"
    break;

  case 82: /* PrintStmt: PRINT '(' new_non Expression new_non ')' ';'  */
#line 354 "compiler.y"
                                                   {
        printf("PRINT %s\n", (yyvsp[-3].s_val));
    }
#line 2230 "y.tab.c"
    break;

  case 91: /* Expression: ID  */
#line 371 "compiler.y"
        {
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), lookup_symbol((yyvsp[0].s_val), SCOPE) % 10);
        strcpy((yyval.s_val), symbol_type(lookup_symbol((yyvsp[0].s_val), SCOPE) / 10));
    }
#line 2239 "y.tab.c"
    break;

  case 92: /* $@13: %empty  */
#line 375 "compiler.y"
        {printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), lookup_symbol((yyvsp[0].s_val), SCOPE) % 10);}
#line 2245 "y.tab.c"
    break;

  case 93: /* Expression: ID $@13 '[' Lit ']'  */
#line 375 "compiler.y"
                                                                                                  {
        strcpy((yyval.s_val), symbol_type(lookup_symbol((yyvsp[-4].s_val), SCOPE) / 10));
    }
#line 2253 "y.tab.c"
    break;

  case 95: /* AsStmt: ID AS TypeName  */
#line 399 "compiler.y"
                    {
            printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].s_val), lookup_symbol((yyvsp[-2].s_val), SCOPE) % 10);
            printf("%c2%c\n", symbol_type(lookup_symbol((yyvsp[-2].s_val), SCOPE) / 10)[0], (yyvsp[0].s_val)[0]);
            strcpy((yyval.s_val), (yyvsp[0].s_val));
    }
#line 2263 "y.tab.c"
    break;

  case 96: /* AsStmt: Lit AS TypeName  */
#line 404 "compiler.y"
                     {printf("%c2%c\n", (yyvsp[-2].s_val)[0], (yyvsp[0].s_val)[0]); 
        (yyval.s_val) = (yyvsp[0].s_val);
    }
#line 2271 "y.tab.c"
    break;

  case 97: /* AsStmt: '(' Exp ')'  */
#line 407 "compiler.y"
                 {(yyval.s_val) = (yyvsp[-1].s_val);}
#line 2277 "y.tab.c"
    break;

  case 98: /* AsStmt: ID  */
#line 408 "compiler.y"
        {printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), lookup_symbol((yyvsp[0].s_val), SCOPE) % 10); strcpy((yyval.s_val), symbol_type(lookup_symbol((yyvsp[0].s_val), SCOPE) / 10));}
#line 2283 "y.tab.c"
    break;

  case 100: /* Exp: Exp LOR Exp1  */
#line 413 "compiler.y"
                   { 
        printf("LOR\n"); 
        (yyval.s_val) = "bool"; 
    }
#line 2292 "y.tab.c"
    break;

  case 101: /* Exp: Exp1  */
#line 417 "compiler.y"
           {
        (yyval.s_val) = (yyvsp[0].s_val);
    }
#line 2300 "y.tab.c"
    break;

  case 102: /* Exp1: Exp1 LAND Exp2  */
#line 423 "compiler.y"
                     {  
        (yyval.s_val) = "bool";            
        printf("LAND\n"); 
    }
#line 2309 "y.tab.c"
    break;

  case 103: /* Exp1: Exp2  */
#line 427 "compiler.y"
           { 
        (yyval.s_val) = (yyvsp[0].s_val);
    }
#line 2317 "y.tab.c"
    break;

  case 104: /* Exp2: Exp2 com_op Exp3  */
#line 433 "compiler.y"
                       { 
        (yyval.s_val) = "bool";
        printf("%s\n", (yyvsp[-1].s_val)); 
    }
#line 2326 "y.tab.c"
    break;

  case 105: /* Exp2: Exp3  */
#line 437 "compiler.y"
           { 
        (yyval.s_val) = (yyvsp[0].s_val); 
    }
#line 2334 "y.tab.c"
    break;

  case 106: /* Exp3: Exp3 add_op Exp4  */
#line 443 "compiler.y"
                       { 
        printf("%s\n", (yyvsp[-1].s_val));
    }
#line 2342 "y.tab.c"
    break;

  case 107: /* Exp3: Exp4  */
#line 446 "compiler.y"
           { 
        (yyval.s_val) = (yyvsp[0].s_val);
    }
#line 2350 "y.tab.c"
    break;

  case 108: /* Exp4: Exp4 mul_op AsStmt  */
#line 452 "compiler.y"
                         { 
            (yyval.s_val) = (yyvsp[-2].s_val);
        printf("%s\n", (yyvsp[-1].s_val)); 
    }
#line 2359 "y.tab.c"
    break;

  case 109: /* Exp4: uexpr  */
#line 456 "compiler.y"
            { 
        (yyval.s_val) = (yyvsp[0].s_val);
    }
#line 2367 "y.tab.c"
    break;

  case 110: /* uexpr: AsStmt  */
#line 462 "compiler.y"
             { 
        (yyval.s_val) = (yyvsp[0].s_val);
    }
#line 2375 "y.tab.c"
    break;

  case 111: /* uexpr: unary_op uexpr  */
#line 465 "compiler.y"
                     { 
        printf("%s\n", (yyvsp[-1].s_val)); 
        (yyval.s_val) = (yyvsp[0].s_val); 
    }
#line 2384 "y.tab.c"
    break;

  case 112: /* unary_op: '+'  */
#line 475 "compiler.y"
          { 
        (yyval.s_val) = "POS"; 
    }
#line 2392 "y.tab.c"
    break;

  case 113: /* unary_op: '-'  */
#line 478 "compiler.y"
          { 
        (yyval.s_val) = "NEG"; 
    }
#line 2400 "y.tab.c"
    break;

  case 114: /* unary_op: '!'  */
#line 481 "compiler.y"
          { 
        (yyval.s_val) = "NOT";
    }
#line 2408 "y.tab.c"
    break;

  case 115: /* com_op: '>'  */
#line 487 "compiler.y"
          {
        (yyval.s_val) = "GTR"; 
    }
#line 2416 "y.tab.c"
    break;

  case 116: /* com_op: '<'  */
#line 490 "compiler.y"
          { 
        (yyval.s_val) = "LSS"; 
    }
#line 2424 "y.tab.c"
    break;

  case 117: /* com_op: GEQ  */
#line 493 "compiler.y"
          { 
        (yyval.s_val) = "GEQ";
    }
#line 2432 "y.tab.c"
    break;

  case 118: /* com_op: LEQ  */
#line 496 "compiler.y"
          { 
        (yyval.s_val) = "LEQ"; 
    }
#line 2440 "y.tab.c"
    break;

  case 119: /* com_op: EQL  */
#line 499 "compiler.y"
          { 
        (yyval.s_val) = "EQL"; 
    }
#line 2448 "y.tab.c"
    break;

  case 120: /* com_op: NEQ  */
#line 502 "compiler.y"
          { 
        (yyval.s_val) = "NEQ"; 
    }
#line 2456 "y.tab.c"
    break;

  case 121: /* add_op: '+'  */
#line 508 "compiler.y"
          { 
        (yyval.s_val) = "ADD"; 
    }
#line 2464 "y.tab.c"
    break;

  case 122: /* add_op: '-'  */
#line 511 "compiler.y"
          { 
        (yyval.s_val) = "SUB"; 
    }
#line 2472 "y.tab.c"
    break;

  case 123: /* mul_op: '*'  */
#line 517 "compiler.y"
          { 
        (yyval.s_val) = "MUL"; 
    }
#line 2480 "y.tab.c"
    break;

  case 124: /* mul_op: '/'  */
#line 520 "compiler.y"
          { 
        (yyval.s_val) = "DIV"; 
    }
#line 2488 "y.tab.c"
    break;

  case 125: /* mul_op: '%'  */
#line 523 "compiler.y"
          { 
        (yyval.s_val) = "REM"; 
    }
#line 2496 "y.tab.c"
    break;

  case 126: /* ExpressionExpr: AsStmt '+' AsStmt  */
#line 530 "compiler.y"
                        {printf("ADD\n");}
#line 2502 "y.tab.c"
    break;

  case 127: /* ExpressionExpr: ID '-' ID  */
#line 531 "compiler.y"
                {
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].s_val), lookup_symbol((yyvsp[-2].s_val), SCOPE) % 10);
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), lookup_symbol((yyvsp[0].s_val), SCOPE) % 10);
        printf("SUB\n");
        strcpy((yyval.s_val), symbol_type(lookup_symbol((yyvsp[-2].s_val), SCOPE) / 10));
    }
#line 2513 "y.tab.c"
    break;

  case 128: /* ExpressionExpr: ID '*' ID  */
#line 537 "compiler.y"
                {
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].s_val), lookup_symbol((yyvsp[-2].s_val), SCOPE) % 10);
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), lookup_symbol((yyvsp[0].s_val), SCOPE) % 10);
        printf("MUL\n");
        strcpy((yyval.s_val), symbol_type(lookup_symbol((yyvsp[-2].s_val), SCOPE) / 10));
    }
#line 2524 "y.tab.c"
    break;

  case 129: /* ExpressionExpr: ID '/' ID  */
#line 543 "compiler.y"
                {
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].s_val), lookup_symbol((yyvsp[-2].s_val), SCOPE) % 10);
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), lookup_symbol((yyvsp[0].s_val), SCOPE) % 10);
        printf("DIV\n");
        strcpy((yyval.s_val), symbol_type(lookup_symbol((yyvsp[-2].s_val), SCOPE) / 10));
    }
#line 2535 "y.tab.c"
    break;

  case 130: /* ExpressionExpr: ID '%' ID  */
#line 549 "compiler.y"
                {
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].s_val), lookup_symbol((yyvsp[-2].s_val), SCOPE) % 10);
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), lookup_symbol((yyvsp[0].s_val), SCOPE) % 10);
        printf("REM\n");
        strcpy((yyval.s_val), symbol_type(lookup_symbol((yyvsp[-2].s_val), SCOPE) / 10));
    }
#line 2546 "y.tab.c"
    break;

  case 131: /* ExpressionExpr: ID LSHIFT ID  */
#line 555 "compiler.y"
                   {
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].s_val), lookup_symbol((yyvsp[-2].s_val), SCOPE) % 10);
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), lookup_symbol((yyvsp[0].s_val), SCOPE) % 10);
        if (lookup_symbol((yyvsp[-2].s_val), SCOPE) / 10 != lookup_symbol((yyvsp[0].s_val), SCOPE) / 10)
            printf("error:%d: invalid operation: LSHIFT (mismatched types %s and %s)\n", yylineno + 1, symbol_type(lookup_symbol((yyvsp[-2].s_val), SCOPE) / 10), symbol_type(lookup_symbol((yyvsp[0].s_val), SCOPE) / 10));
        printf("LSHIFT\n");
        strcpy((yyval.s_val), symbol_type(lookup_symbol((yyvsp[-2].s_val), SCOPE) / 10));
    }
#line 2559 "y.tab.c"
    break;

  case 132: /* TypeName: INT  */
#line 566 "compiler.y"
          { (yyval.s_val) = "i32";}
#line 2565 "y.tab.c"
    break;

  case 133: /* TypeName: FLOAT  */
#line 567 "compiler.y"
            { (yyval.s_val) ="f32";}
#line 2571 "y.tab.c"
    break;

  case 134: /* TypeName: '&'  */
#line 568 "compiler.y"
          { (yyval.s_val) = "str";}
#line 2577 "y.tab.c"
    break;

  case 135: /* TypeName: '&' STR  */
#line 569 "compiler.y"
              { (yyval.s_val) = "str";}
#line 2583 "y.tab.c"
    break;

  case 136: /* TypeName: BOOL  */
#line 570 "compiler.y"
           { (yyval.s_val) = "bool";}
#line 2589 "y.tab.c"
    break;


#line 2593 "y.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 573 "compiler.y"


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yylineno = 0;
    yyparse();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

static void create_symbol(int current_scope) {
    printf("> Create symbol table (scope level %d)\n", current_scope);
}

static void insert_symbol(char name[], char type[], int current_scope, int line, int mut, char re_type) {
    symbol *new_symbol = malloc(sizeof(symbol));
    strcpy(new_symbol->name, name);
    strcpy(new_symbol->type, type);
    new_symbol->scope = current_scope;
    new_symbol->line = line + 1;
    new_symbol->mut = mut;
    new_symbol->func_re = re_type;
    new_symbol->next = NULL;
    int addr = 0;
    if (sym_table_arr[0] == NULL)
        sym_table_arr[0] = new_symbol;
    else   
    {
        symbol *tmp;
        for (int i = 0; i <= SCOPE; i++)
        {
            if (!sym_table_arr[i])
                break;
            tmp = sym_table_arr[i];
            while (tmp->next != NULL)
                tmp = tmp->next;
        }
        if (sym_table_arr[SCOPE])
            tmp->next = new_symbol;
        else
            sym_table_arr[SCOPE] = new_symbol;
        addr = tmp->addr + 1;
    }
    // function
    if (type[1] == 'u')
    {
        new_symbol->addr = -1;
        printf("> Insert `%s` (addr: %d) to scope level %d\n", name, new_symbol->addr, current_scope);
    }
    else
    {
        func_addr++;
        new_symbol->addr = func_addr;
        printf("> Insert `%s` (addr: %d) to scope level %d\n", name, new_symbol->addr, current_scope);
    }
}

int lookup_symbol(char name[], int current_scope) {
    symbol *search_pointer;
    while (current_scope >= 0)
    {
        if (sym_table_arr[current_scope])
            search_pointer = sym_table_arr[current_scope];
        else
        {
            current_scope--;
            continue;
        }

        while (search_pointer->next != NULL && strcmp(name, search_pointer->name))
            search_pointer = search_pointer->next;

        if (!strcmp(name, search_pointer->name))
            break;
        else
            current_scope--;
    }

    // doesn't find the target
    if (strcmp(name, search_pointer->name))
        return -1;

    int type = 1;// 1:int, 2:float, 3:bool, 4:str, 5:array
    switch (search_pointer->type[0])
    {
        case 'i':
            type = 1;
            break;
        case 'f':
            type = 2;
            break;
        case 'b':
            type = 3;
            break;
        case 's':
            type = 4;
            break;
        case 'a':
            type = 5;
            break;
    }
    return type*10 + (search_pointer->addr);
}

static void dump_symbol(int current_scope) {
    printf("\n> Dump symbol table (scope level: %d)\n", current_scope);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
        "Index", "Name", "Mut","Type", "Addr", "Lineno", "Func_sig");

    int index = 0;
    symbol *current_symbol = sym_table_arr[current_scope];
    while (current_symbol)
    {
        symbol *current_symbol_next = current_symbol->next;
        if (!strcmp(current_symbol->type, "func"))
        {
            printf("%-10d%-10s%-10d%-10s%-10d%-10d(%s)%c",
                    index, current_symbol->name, current_symbol->mut, current_symbol->type, current_symbol->addr, current_symbol->line, current_symbol->func_arg, current_symbol->func_re);
            for (int i = 0; i < 7 - strlen(current_symbol->func_arg); i++)
                printf(" ");
            printf("\n");
        }
        else
            printf("%-10d%-10s%-10d%-10s%-10d%-10d%-10c\n",
                    index, current_symbol->name, current_symbol->mut, current_symbol->type, current_symbol->addr, current_symbol->line, current_symbol->func_re);
        index++;
        free(current_symbol);
        current_symbol = current_symbol_next;
    }
    sym_table_arr[current_scope] = NULL;
    SCOPE--;
}

char * symbol_type(int type)
{
    switch (type)
    {
        case 1:
            return "i32";
        case 2:
            return "f32";
        case 3:
            return "bool";
        case 4:
            return "str";
        case 5:
            return "array";
    }
    return "x";
}

bool Error_check(int ID1, int ID2)
{
    if (ID1 == -1 || ID2 == -1)
        return false;
    if (ID1 / 10 != ID2 / 10)
        return false;
    return true;
}

void Insert_arg_to_func(char name[], char arg[], char ret)
{
    symbol *search_pointer;
    int current_scope = SCOPE;
    while (current_scope >= 0)
    {
        if (sym_table_arr[current_scope])
            search_pointer = sym_table_arr[current_scope];
        else
        {
            current_scope--;
            continue;
        }

        while (search_pointer->next != NULL && strcmp(name, search_pointer->name))
            search_pointer = search_pointer->next;

        if (!strcmp(name, search_pointer->name))
            break;
        else
            current_scope--;
    }
    search_pointer->func_re = ret;
    strcpy(search_pointer->func_arg, arg);
    for (int i = 0; i < strlen(search_pointer->func_arg); i++)
        search_pointer->func_arg[i] -= 32;
}

char * Search_func_arg(char name[])
{
    symbol *search_pointer;
    int current_scope = SCOPE;
    while (current_scope >= 0)
    {
        if (sym_table_arr[current_scope])
            search_pointer = sym_table_arr[current_scope];
        else
        {
            current_scope--;
            continue;
        }

        while (search_pointer->next != NULL && strcmp(name, search_pointer->name))
            search_pointer = search_pointer->next;

        if (!strcmp(name, search_pointer->name))
            break;
        else
            current_scope--;
    }

    return search_pointer->func_arg;
}

char Search_func_ret(char name[])
{
    symbol *search_pointer;
    int current_scope = SCOPE;
    while (current_scope >= 0)
    {
        if (sym_table_arr[current_scope])
            search_pointer = sym_table_arr[current_scope];
        else
        {
            current_scope--;
            continue;
        }

        while (search_pointer->next != NULL && strcmp(name, search_pointer->name))
            search_pointer = search_pointer->next;

        if (!strcmp(name, search_pointer->name))
            break;
        else
            current_scope--;
    }

    return search_pointer->func_re;
}
