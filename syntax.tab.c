/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y"

#include <stdio.h>
#include "listaSimbolos.h"
#include "listaCodigo.h"
#include <string.h>
#include <stdlib.h>

int nErrorSem = 0;
int nErrorSint =0;
Lista tablaSimb;
Tipo tipoActual;            /* Variable global para el tipo actual del simbolo */ 
int contCadenas=0;
int nEtiqueta = 0;
int registrosLibres[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
void yyerror();
extern int yylex();
extern int yylineno;
extern char * yytext;
int contieneTabla(char *str);
void insertaEntrada(char *str, Tipo t);
int esConstante(char *str);
void imprimeTabla(Lista tablaSimb);
Operacion creaInst(char *op, char *res, char *arg1, char *arg2);
char *registroLibre();
void imprimirCodigo(ListaC codigo);
void liberaReg(char *reg);
char *concatenaStr(char *a, char *b);
char *enteroACaracter(int numero);

#line 100 "syntax.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 31 "syntax.y"

#include "listaCodigo.h"

#line 147 "syntax.tab.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRLITERAL = 258,
    ID = 259,
    INTLITERAL = 260,
    VOID = 261,
    VAR = 262,
    CONST = 263,
    IF = 264,
    ELSE = 265,
    WHILE = 266,
    READ = 267,
    PRINT = 268,
    CLOSEBRA = 269,
    OPENBRA = 270,
    DO = 271,
    FOR = 272,
    LPAREN = 273,
    RPAREN = 274,
    SEMICOLON = 275,
    COMMA = 276,
    ASSIGNOP = 277,
    PLUSOP = 278,
    MINUSOP = 279,
    MULOP = 280,
    DIVOP = 281,
    UMINUS = 282
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "syntax.y"

    ListaC codigo; 
    char *str;

#line 191 "syntax.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */



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
typedef yytype_int8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYLAST   133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  40
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  96

#define YYUNDEFTOK  2
#define YYMAXUTOK   282


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    54,    54,    54,    75,    75,    80,    80,    85,    86,
      87,    90,    91,    98,   108,   124,   129,   132,   146,   149,
     173,   186,   208,   222,   251,   254,   257,   260,   263,   270,
     281,   301,   320,   339,   347,   355,   363,   371,   378,   379,
     390
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRLITERAL", "ID", "INTLITERAL", "VOID",
  "VAR", "CONST", "IF", "ELSE", "WHILE", "READ", "PRINT", "CLOSEBRA",
  "OPENBRA", "DO", "FOR", "LPAREN", "RPAREN", "SEMICOLON", "COMMA",
  "ASSIGNOP", "PLUSOP", "MINUSOP", "MULOP", "DIVOP", "UMINUS", "$accept",
  "program", "$@1", "declarations", "$@2", "$@3", "identifier_list",
  "asig", "statements_list", "statement", "print_list", "print_item",
  "read_list", "expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282
};
# endif

#define YYPACT_NINF (-33)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-7)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -33,    18,    20,   -33,    26,     4,    29,     9,   -33,    -6,
      16,    27,    43,    19,    33,    41,    33,    48,    31,    53,
      63,    84,     3,   -33,   -33,    78,    83,   -33,   -33,    87,
      25,   -33,   -33,    46,   -33,     5,     5,     5,   -33,    82,
     -33,   -33,   -33,     5,     5,    90,   -33,   -10,    61,   112,
      78,     5,   -33,    33,   -33,    60,    17,    73,   -33,   120,
      81,   -33,   -33,     3,     5,     5,     5,     5,   -33,   107,
       5,   -10,   -33,   -33,    78,    78,   -33,   -33,   -33,    92,
      92,   -33,   -33,     5,    96,   116,   -33,    89,    78,    78,
     108,   110,   -33,   -33,    78,   -33
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     0,    10,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,    16,     0,     0,    15,     8,    13,
       0,    11,     9,     0,    26,     0,     0,     0,    31,     0,
      30,    39,    40,     0,     0,     0,    27,    29,     0,     0,
       0,     0,     5,     0,     7,     0,     0,     0,    25,     0,
       0,    37,    24,     0,     0,     0,     0,     0,    18,     0,
       0,    14,    12,    17,     0,     0,    32,    38,    28,    33,
      34,    35,    36,     0,     0,    20,    21,     0,     0,     0,
       0,     0,    19,    22,     0,    23
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -33,   -33,   -33,   -33,   -33,   -33,   111,    77,   109,   -25,
     -33,    68,   -33,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     9,    14,    16,    30,    31,    12,    27,
      45,    46,    39,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      49,    10,    11,    55,    56,    57,    40,    41,    42,    41,
      42,    60,    61,    64,    65,    66,    67,    13,     3,    71,
      -4,    43,     6,    43,     8,    70,     4,    44,    15,    44,
       5,    -6,    79,    80,    81,    82,    74,    29,    84,    28,
      64,    65,    66,    67,    17,    52,    53,    18,     7,    85,
      86,    87,    19,    35,    20,    21,    22,    23,    24,    25,
      26,    32,    17,    91,    92,    18,    54,    53,    34,    95,
      19,    36,    20,    21,    22,    68,    24,    25,    26,    17,
      73,    37,    18,    64,    65,    66,    67,    19,    38,    20,
      21,    22,    75,    24,    25,    26,    64,    65,    66,    67,
      77,    50,    58,    59,    64,    65,    66,    67,    90,    51,
      62,    63,    64,    65,    66,    67,    88,    66,    67,    64,
      65,    66,    67,    69,    76,    83,    89,    33,    93,    94,
      72,    78,     0,    48
};

static const yytype_int8 yycheck[] =
{
      25,     7,     8,    35,    36,    37,     3,     4,     5,     4,
       5,    43,    44,    23,    24,    25,    26,     1,     0,    51,
       4,    18,    18,    18,    15,    50,     6,    24,     1,    24,
       4,     4,    64,    65,    66,    67,    19,     4,    70,    20,
      23,    24,    25,    26,     1,    20,    21,     4,    19,    74,
      75,    83,     9,    22,    11,    12,    13,    14,    15,    16,
      17,    20,     1,    88,    89,     4,    20,    21,    20,    94,
       9,    18,    11,    12,    13,    14,    15,    16,    17,     1,
      20,    18,     4,    23,    24,    25,    26,     9,     4,    11,
      12,    13,    19,    15,    16,    17,    23,    24,    25,    26,
      19,    18,    20,    21,    23,    24,    25,    26,    19,    22,
      20,    21,    23,    24,    25,    26,    20,    25,    26,    23,
      24,    25,    26,    11,     4,    18,    10,    16,    20,    19,
      53,    63,    -1,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,    30,     0,     6,     4,    18,    19,    15,    31,
       7,     8,    36,     1,    32,     1,    33,     1,     4,     9,
      11,    12,    13,    14,    15,    16,    17,    37,    20,     4,
      34,    35,    20,    34,    20,    22,    18,    18,     4,    40,
       3,     4,     5,    18,    24,    38,    39,    41,    36,    37,
      18,    22,    20,    21,    20,    41,    41,    41,    20,    21,
      41,    41,    20,    21,    23,    24,    25,    26,    14,    11,
      37,    41,    35,    20,    19,    19,     4,    19,    39,    41,
      41,    41,    41,    18,    41,    37,    37,    41,    20,    10,
      19,    37,    37,    20,    19,    37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    28,    30,    29,    32,    31,    33,    31,    31,    31,
      31,    34,    34,    35,    35,    36,    36,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    38,    38,    39,
      39,    40,    40,    41,    41,    41,    41,    41,    41,    41,
      41
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     9,     0,     5,     0,     5,     4,     4,
       0,     1,     3,     1,     3,     2,     0,     4,     3,     7,
       5,     5,     7,     8,     3,     3,     2,     1,     3,     1,
       1,     1,     3,     3,     3,     3,     3,     2,     3,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 54 "syntax.y"
                                {tablaSimb = creaLS();}
#line 1430 "syntax.tab.c"
    break;

  case 3:
#line 54 "syntax.y"
                                                                                                                            {   
                                    (yyval.codigo) = (yyvsp[-2].codigo);
                                    concatenaLC((yyvsp[-2].codigo), (yyvsp[-1].codigo));
                                    liberaLC((yyvsp[-1].codigo));
                                    
                                    //gestion tabla de simbolos
                                    imprimeTabla(tablaSimb);
                                    liberaLS(tablaSimb);

                                    //inserta inst fin de programa
                                    Operacion inst = creaInst("li", "$v0", "10", NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    inst = creaInst("syscall", NULL, NULL, NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);

                                    //gestion impresion de codigo
                                    imprimirCodigo((yyval.codigo));
                                    liberaLC((yyval.codigo));
                                }
#line 1454 "syntax.tab.c"
    break;

  case 4:
#line 75 "syntax.y"
                                                 {tipoActual = VARIABLE;}
#line 1460 "syntax.tab.c"
    break;

  case 5:
#line 75 "syntax.y"
                                                                                                     {
                                    (yyval.codigo) = (yyvsp[-4].codigo);
                                    concatenaLC((yyvsp[-4].codigo), (yyvsp[-1].codigo));
                                    liberaLC((yyvsp[-1].codigo));
                                }
#line 1470 "syntax.tab.c"
    break;

  case 6:
#line 80 "syntax.y"
                                                     {tipoActual = CONSTANTE;}
#line 1476 "syntax.tab.c"
    break;

  case 7:
#line 80 "syntax.y"
                                                                                                         {
                                    (yyval.codigo) = (yyvsp[-4].codigo);
                                    concatenaLC((yyvsp[-4].codigo), (yyvsp[-1].codigo));
                                    liberaLC((yyvsp[-1].codigo));
                                }
#line 1486 "syntax.tab.c"
    break;

  case 8:
#line 85 "syntax.y"
                                                                   {(yyval.codigo) = creaLC();}
#line 1492 "syntax.tab.c"
    break;

  case 9:
#line 86 "syntax.y"
                                                                     {(yyval.codigo) = creaLC();}
#line 1498 "syntax.tab.c"
    break;

  case 10:
#line 87 "syntax.y"
                                               {(yyval.codigo) = creaLC();}
#line 1504 "syntax.tab.c"
    break;

  case 11:
#line 90 "syntax.y"
                                      {(yyval.codigo) = (yyvsp[0].codigo);}
#line 1510 "syntax.tab.c"
    break;

  case 12:
#line 91 "syntax.y"
                                                             {
                                    (yyval.codigo) = (yyvsp[-2].codigo);
                                    concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                                    liberaLC((yyvsp[0].codigo));
                                }
#line 1520 "syntax.tab.c"
    break;

  case 13:
#line 98 "syntax.y"
                                   {
                                    if(!contieneTabla((yyvsp[0].str)))
                                        insertaEntrada((yyvsp[0].str), tipoActual);
                                    else{
                                        printf("Error linea %d: Variable <%s> ya declarada.\n", yylineno, (yyvsp[0].str));
                                        nErrorSem++;
                                    }

                                    (yyval.codigo) = creaLC();
                                }
#line 1535 "syntax.tab.c"
    break;

  case 14:
#line 108 "syntax.y"
                                                          {
                                    if(!contieneTabla((yyvsp[-2].str)))
                                        insertaEntrada((yyvsp[-2].str), tipoActual);
                                    else{
                                        printf("Error linea %d: Variable <%s> ya declarada.\n", yylineno, (yyvsp[-2].str));
                                        nErrorSem++;
                                    }

                                    (yyval.codigo) = (yyvsp[0].codigo);
                                    Operacion inst = creaInst("sw", recuperaResLC((yyvsp[0].codigo)), concatenaStr("_", (yyvsp[-2].str)), NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    liberaReg(inst.res);
                                    //imprimirCodigo($$);
                                }
#line 1554 "syntax.tab.c"
    break;

  case 15:
#line 124 "syntax.y"
                                                          {
                                    (yyval.codigo) = (yyvsp[-1].codigo); 
                                    concatenaLC((yyvsp[-1].codigo), (yyvsp[0].codigo)); 
                                    liberaLC((yyvsp[0].codigo));
                                }
#line 1564 "syntax.tab.c"
    break;

  case 16:
#line 129 "syntax.y"
                                               { (yyval.codigo) = creaLC();}
#line 1570 "syntax.tab.c"
    break;

  case 17:
#line 132 "syntax.y"
                                                                 {
                                    if(!contieneTabla((yyvsp[-3].str))){
                                        printf("Error linea %d: Error semantico <%s> no declarado.\n", yylineno, (yyvsp[-3].str));
                                        nErrorSem++;
                                    }else if(esConstante((yyvsp[-3].str))){
                                        printf("Error linea %d: Error semantico, asignacion a constante <%s>\n", yylineno, (yyvsp[-3].str));
                                        nErrorSem++;
                                    }
                                    (yyval.codigo) = (yyvsp[-1].codigo);
                                    Operacion inst = creaInst("sw", recuperaResLC((yyvsp[-1].codigo)), concatenaStr("_", (yyvsp[-3].str)), NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    liberaReg(inst.res);
                                    //imprimirCodigo($$);
                                }
#line 1589 "syntax.tab.c"
    break;

  case 18:
#line 146 "syntax.y"
                                                                   { 
                                    (yyval.codigo) = (yyvsp[-1].codigo);
                                }
#line 1597 "syntax.tab.c"
    break;

  case 19:
#line 149 "syntax.y"
                                                                                       {
                                    
                                    (yyval.codigo) = (yyvsp[-4].codigo);
                                    nEtiqueta++;    //else
                                    char *etiq1 = concatenaStr("$l", enteroACaracter(nEtiqueta));
                                    nEtiqueta++;    //finif
                                    char *etiq2 = concatenaStr("$l", enteroACaracter(nEtiqueta));
                                    
                                    Operacion inst = creaInst("beqz", recuperaResLC((yyvsp[-4].codigo)), etiq1, NULL); //no cumple if y salta a else
                                    liberaReg(recuperaResLC((yyvsp[-4].codigo)));
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    concatenaLC((yyval.codigo), (yyvsp[-2].codigo));                        

                                    inst = creaInst("b", etiq2, NULL, NULL);    //Cumple if y salta a fin-if
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    inst = creaInst(etiq1, NULL, NULL, NULL); //etiq: else
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    concatenaLC((yyval.codigo), (yyvsp[0].codigo));

                                    inst = creaInst(etiq2, NULL, NULL, NULL); //etiq: finif
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    liberaLC((yyvsp[-2].codigo));
                                    liberaLC((yyvsp[0].codigo));
                                }
#line 1626 "syntax.tab.c"
    break;

  case 20:
#line 173 "syntax.y"
                                                                        {
                                    (yyval.codigo) = (yyvsp[-2].codigo);
                                    nEtiqueta++;
                                    char *etiq = concatenaStr("$l", enteroACaracter(nEtiqueta));
                                    Operacion inst = creaInst("beqz", recuperaResLC((yyvsp[-2].codigo)), etiq, NULL); //No cumple if y salta finif
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                                    inst = creaInst(etiq, NULL, NULL, NULL);                          //finif
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);

                                    liberaReg(recuperaResLC((yyvsp[-2].codigo)));
                                    liberaLC((yyvsp[0].codigo));
                                }
#line 1644 "syntax.tab.c"
    break;

  case 21:
#line 186 "syntax.y"
                                                                           {
                                    nEtiqueta++;
                                    char *etiq1 = concatenaStr("$l", enteroACaracter(nEtiqueta));       //etiq1: inicio while
                                    nEtiqueta++;    
                                    char *etiq2 = concatenaStr("$l", enteroACaracter(nEtiqueta));       //etiq2: fin While

                                    Operacion inst = creaInst(etiq1, NULL, NULL, NULL);                 //etiq: inicio while
                                    insertaLC((yyvsp[-2].codigo), inicioLC((yyvsp[-2].codigo)), inst);                                  
                                    (yyval.codigo) = (yyvsp[-2].codigo);                                                            //expression

                                    inst = creaInst("beqz", recuperaResLC((yyvsp[-2].codigo)), etiq2, NULL);            // Expresion == 0, finwhile
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);                                   //statement
                                    concatenaLC((yyval.codigo), (yyvsp[0].codigo));                                                
                                    inst = creaInst("b", etiq1, NULL, NULL);                            //salta a inicio
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);

                                    inst = creaInst(etiq2, NULL, NULL, NULL);                           //etiq: fin-while
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                                                                                        //otros statement
                                    liberaReg(recuperaResLC((yyvsp[-2].codigo)));
                                    liberaLC((yyvsp[0].codigo));
                                }
#line 1671 "syntax.tab.c"
    break;

  case 22:
#line 208 "syntax.y"
                                                                                         {
                                    nEtiqueta++;
                                    char *etiq1 = concatenaStr("$l", enteroACaracter(nEtiqueta));       //etiq1: do

                                    Operacion inst = creaInst(etiq1, NULL, NULL, NULL);                 //do
                                    insertaLC((yyvsp[-5].codigo), inicioLC((yyvsp[-5].codigo)), inst);                                  
                                    (yyval.codigo) = (yyvsp[-5].codigo);                                                            //statement

                                    concatenaLC((yyval.codigo), (yyvsp[-2].codigo));                                                //expression
                                    inst = creaInst("bnez", recuperaResLC((yyvsp[-2].codigo)), etiq1, NULL);            //Expresion != 0, vuelve al do
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    liberaReg(recuperaResLC((yyvsp[-2].codigo)));
                                    liberaLC((yyvsp[-2].codigo));
                                }
#line 1690 "syntax.tab.c"
    break;

  case 23:
#line 224 "syntax.y"
                                {
                                    nEtiqueta++;
                                    char *etiq1 = concatenaStr("$l", enteroACaracter(nEtiqueta));       //etiq1: inicio for
                                    nEtiqueta++;    
                                    char *etiq2 = concatenaStr("$l", enteroACaracter(nEtiqueta));       //etiq2: fin for
                                    

                                    Operacion inst = creaInst(etiq1, NULL, NULL, NULL);                 //etiq: inicio FOR
                                    insertaLC((yyvsp[-4].codigo), inicioLC((yyvsp[-4].codigo)), inst);                                  
                                    concatenaLC((yyvsp[-5].codigo), (yyvsp[-4].codigo));
                                    (yyval.codigo) = (yyvsp[-5].codigo);                                                            //expression

                                    inst = creaInst("beqz", recuperaResLC((yyvsp[-4].codigo)), etiq2, NULL);            // Expresion == 0, finfor
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);                                   //statement
                                    concatenaLC((yyval.codigo), (yyvsp[0].codigo)); 
                                    concatenaLC((yyval.codigo), (yyvsp[-2].codigo));
                                    inst = creaInst("b", etiq1, NULL, NULL);                            //salta a inicio
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);

                                    inst = creaInst(etiq2, NULL, NULL, NULL);                           //etiq: fin-for
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                                                                                        //otros statement
                                    liberaReg(recuperaResLC((yyvsp[-5].codigo)));
                                    liberaLC((yyvsp[-4].codigo));
                                    liberaLC((yyvsp[-2].codigo));
                                    liberaLC((yyvsp[0].codigo));
                                }
#line 1722 "syntax.tab.c"
    break;

  case 24:
#line 251 "syntax.y"
                                                             {
                                    (yyval.codigo) = (yyvsp[-1].codigo);
                                }
#line 1730 "syntax.tab.c"
    break;

  case 25:
#line 254 "syntax.y"
                                                           {
                                    (yyval.codigo) = (yyvsp[-1].codigo);
                                }
#line 1738 "syntax.tab.c"
    break;

  case 26:
#line 257 "syntax.y"
                                                   { (yyval.codigo) = creaLC();}
#line 1744 "syntax.tab.c"
    break;

  case 27:
#line 260 "syntax.y"
                                           { 
                                    (yyval.codigo) = (yyvsp[0].codigo);
                                }
#line 1752 "syntax.tab.c"
    break;

  case 28:
#line 263 "syntax.y"
                                                              {
                                    (yyval.codigo) = (yyvsp[-2].codigo);
                                    concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                                    liberaLC((yyvsp[0].codigo));
                                }
#line 1762 "syntax.tab.c"
    break;

  case 29:
#line 270 "syntax.y"
                                           {
                                    (yyval.codigo) = (yyvsp[0].codigo);
                                    Operacion inst = creaInst("move", "$a0", recuperaResLC((yyvsp[0].codigo)), NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    inst = creaInst("li", "$v0", "1", NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    inst = creaInst("syscall", NULL, NULL, NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);

                                    liberaReg(recuperaResLC((yyvsp[0].codigo)));
                                }
#line 1778 "syntax.tab.c"
    break;

  case 30:
#line 281 "syntax.y"
                                             {      /* Es necesario comprobar si una cadena esta ya en la seccion de datos? */
                                    if(!contieneTabla((yyvsp[0].str))){
                                        insertaEntrada((yyvsp[0].str), CADENA);
                                        contCadenas++;
                                    }
                                    PosicionLista pos = buscaLS(tablaSimb, (yyvsp[0].str));    //Buscar idCadena, no todas las veces se introduce nueva cadena. contCadenas no actualizado 
                                    Simbolo tmp = recuperaLS(tablaSimb, pos);
                                    int id = tmp.valor;
                                    char *idStr = concatenaStr("$str", enteroACaracter(id));

                                    (yyval.codigo) = creaLC();
                                    Operacion inst = creaInst("la", "$a0", idStr, NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    inst = creaInst("li", "$v0", "4", NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    inst = creaInst("syscall", NULL, NULL, NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                }
#line 1801 "syntax.tab.c"
    break;

  case 31:
#line 301 "syntax.y"
                                  {
                                    if(!contieneTabla((yyvsp[0].str))){
                                        printf("Error linea %d: Error semantico <%s> no declarado.\n", yylineno, (yyvsp[0].str));
                                        nErrorSem++;
                                    }else if(esConstante((yyvsp[0].str))){
                                        printf("Error linea %d: Error semantico, asignacion a constante <%s>\n", yylineno, (yyvsp[0].str));
                                        nErrorSem++;
                                    }
                                    (yyval.codigo) = creaLC();
                                    char *id = concatenaStr("_", (yyvsp[0].str));

                                    Operacion inst = creaInst("li", "$v0", "5", NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    inst = creaInst("syscall", NULL, NULL, NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    inst = creaInst("sw", "$v0", id, NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);

                                }
#line 1825 "syntax.tab.c"
    break;

  case 32:
#line 320 "syntax.y"
                                                     {
                                    if(!contieneTabla((yyvsp[0].str))){
                                        printf("Error linea %d: Error semantico <%s> no declarado.\n", yylineno, (yyvsp[0].str));
                                    }else if(esConstante((yyvsp[0].str))){
                                        printf("Error linea %d: Error semantico, asignacion a constante <%s>\n", yylineno, (yyvsp[0].str));
                                    }
                                    (yyval.codigo) = (yyvsp[-2].codigo);
                                    char *id = concatenaStr("_", (yyvsp[0].str));

                                    Operacion inst = creaInst("li", "$v0", "5", NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    inst = creaInst("syscall", NULL, NULL, NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    inst = creaInst("sw", "$v0", id, NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                }
#line 1846 "syntax.tab.c"
    break;

  case 33:
#line 339 "syntax.y"
                                                                        { /*$$=$1+$3*/ 
                                    (yyval.codigo) = (yyvsp[-2].codigo);
                                    concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                                    Operacion inst = creaInst("add", recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[0].codigo)));
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    liberaLC((yyvsp[0].codigo));
                                    liberaReg(inst.arg2);
                                }
#line 1859 "syntax.tab.c"
    break;

  case 34:
#line 347 "syntax.y"
                                                                        { /*$$=$1-$3*/
                                    (yyval.codigo) = (yyvsp[-2].codigo);
                                    concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                                    Operacion inst = creaInst("sub", recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[0].codigo)));
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    liberaLC((yyvsp[0].codigo));
                                    liberaReg(inst.arg2);
                                }
#line 1872 "syntax.tab.c"
    break;

  case 35:
#line 355 "syntax.y"
                                                                        { /*$$=$1*$3*/ 
                                    (yyval.codigo) = (yyvsp[-2].codigo);
                                    concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                                    Operacion inst = creaInst("mul", recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[0].codigo)));
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    liberaLC((yyvsp[0].codigo));
                                    liberaReg(inst.arg2);
                                }
#line 1885 "syntax.tab.c"
    break;

  case 36:
#line 363 "syntax.y"
                                                                        { /*$$=$1/$3*/
                                    (yyval.codigo) = (yyvsp[-2].codigo);
                                    concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                                    Operacion inst = creaInst("div", recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[0].codigo)));
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    liberaLC((yyvsp[0].codigo));
                                    liberaReg(inst.arg2);
                                }
#line 1898 "syntax.tab.c"
    break;

  case 37:
#line 371 "syntax.y"
                                                                        { /*$$=-$2*/ 
                                    (yyval.codigo) = (yyvsp[0].codigo);
                                    char *res = recuperaResLC((yyvsp[0].codigo));
                                    Operacion inst = creaInst("neg", res, res, NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    guardaResLC((yyval.codigo), inst.res);
                                }
#line 1910 "syntax.tab.c"
    break;

  case 38:
#line 378 "syntax.y"
                                                                        { (yyval.codigo)=(yyvsp[-1].codigo); }
#line 1916 "syntax.tab.c"
    break;

  case 39:
#line 379 "syntax.y"
                                     {
                                    if(!contieneTabla((yyvsp[0].str))){
                                        printf("Error linea %d: Error semantico, <%s> no declarado.\n", yylineno, (yyvsp[0].str));
                                        nErrorSem++;
                                    }
                                    (yyval.codigo) = creaLC();
                                    Operacion inst = creaInst("lw", registroLibre(), concatenaStr("_", (yyvsp[0].str)), NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    guardaResLC((yyval.codigo), inst.res);
                                    
                                }
#line 1932 "syntax.tab.c"
    break;

  case 40:
#line 390 "syntax.y"
                                             {
                                    (yyval.codigo) = creaLC();
                                    Operacion inst = creaInst("li", registroLibre(), (yyvsp[0].str), NULL);
                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), inst);
                                    guardaResLC((yyval.codigo), inst.res);
                                }
#line 1943 "syntax.tab.c"
    break;


#line 1947 "syntax.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 397 "syntax.y"

void yyerror(){
    nErrorSint++;
    printf("Error sintactico en linea %d \n", yylineno);
}

int contieneTabla(char *str){
    if(buscaLS(tablaSimb, str) != NULL)
        return 1;
    else 
        return 0;
}

void insertaEntrada(char *str, Tipo t){
    Simbolo s;
    s.nombre = str;
    s.tipo = t;
    if(t == CADENA)
        s.valor = contCadenas;                      /* Identificador de cadena */
    insertaFinalLS(tablaSimb, s);
}

int esConstante(char *str){
    PosicionLista pos = buscaLS(tablaSimb, str);
    if(pos != NULL){
        Simbolo aux = recuperaLS(tablaSimb, pos);
        if(aux.tipo == CONSTANTE)
            return 1;
    }
    return 0;
}

/*Usa las funciones abstractas/genericas, se podria definir en listaSimbolos.c para realizar directamente un recorrido con punteros, 
pero creo que así queda mas entendible y en el mismo archivo que el analizador lexico*/
void imprimeTabla(Lista tablaSimb){
    printf("\t.data\n");
    /* Imprime las cadenas */
    PosicionLista aux = inicioLS(tablaSimb);    /* Cabecera */
    while(aux != finalLS(tablaSimb)) {
        Simbolo simb = recuperaLS(tablaSimb, aux);
        if(simb.tipo == CADENA){
            printf("$str%d:\n", simb.valor);
            printf("\t.asciiz %s\n", simb.nombre);
        }
        aux = siguienteLS(tablaSimb, aux);
    }

    /* Imprime las variables */
    aux = inicioLS(tablaSimb);                  /* Cabecera */
    while(aux != finalLS(tablaSimb)) {
        Simbolo simb = recuperaLS(tablaSimb, aux);
        if(simb.tipo != CADENA){
            printf("_%s:\n", simb.nombre);
            printf("\t.word 0\n");
        }
        aux = siguienteLS(tablaSimb, aux);
    }
}

Operacion creaInst(char *op, char *res, char *arg1, char *arg2){
    Operacion inst;
    inst.op = op;
    inst.res = res;
    inst.arg1 = arg1;
    inst.arg2 = arg2;
    return inst;
}

char *registroLibre(){
    for(int i = 0; i<10; i++){
        if(registrosLibres[i] == 1){
            registrosLibres[i] = 0;            /*Marcamos como no libre */
            char *tmp = malloc(4 * sizeof(char));
            sprintf(tmp, "$t%d", i);
            return tmp;
        }
    }
    printf("ERROR. No hay registros disponibles.\n");
    return NULL;
}
void imprimirCodigo(ListaC codigo)
{
  PosicionListaC p = inicioLC(codigo);
  printf("\t.text\n\t.globl main\n");
  printf("main:\n");
  while (p != finalLC(codigo))
  {
    Operacion oper = recuperaLC(codigo, p);
    if(oper.op[0] != '$')                                /* imprime tab si no es una etiqueta, no inicia en '$' */
        printf("\t");
    printf("%s", oper.op);
    if (oper.res)
        printf(" %s", oper.res);
    if(oper.op[0] == '$')                               /* Solo imprime ':' si es etiqueta, no inicia en '$'*/
        printf(":\n");
    if (oper.arg1)
        printf(", %s", oper.arg1);
    if (oper.arg2)
        printf(", %s", oper.arg2);
    if( oper.op[0] != '$')                               /* Solo imprime '\n' si no es etiqueta, no inicia en '$'*/
        printf("\n");
    p = siguienteLC(codigo, p);
  }
}

char *concatenaStr(char *a, char *b){
    int tam = strlen(a) + strlen(b);
    char * tmp = malloc( (tam + 1) * sizeof(char));
    strcat(strcpy(tmp, a), b);
    return tmp;
}

void liberaReg(char *reg){ /* $tx */
    int i = ((int) reg[2]) - ((int)'0');            /* conversion mediante  codigo ascii */ 
    registrosLibres[i] = 1;
}

char *enteroACaracter(int numero){
    char *aux = malloc(sizeof(char));
    sprintf(aux, "%d", numero);
    return aux;
}
