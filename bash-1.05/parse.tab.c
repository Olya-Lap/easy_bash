/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 21 "parse.y" /* yacc.c:339  */

#include <stdio.h>
#include <signal.h>
#include "shell.h"
#include "flags.h"

#ifdef READLINE
//#include <readline/readline.h>
//#include <readline/history.h>
#endif

#define YYDEBUG 1
extern int eof_encountered;
extern int no_line_editing;
extern int interactive;

#line 83 "parse.tab.c" /* yacc.c:339  */

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
    IF = 258,
    THEN = 259,
    ELSE = 260,
    ELIF = 261,
    FI = 262,
    CASE = 263,
    ESAC = 264,
    FOR = 265,
    WHILE = 266,
    UNTIL = 267,
    DO = 268,
    DONE = 269,
    FUNCTION = 270,
    IN = 271,
    WORD = 272,
    NUMBER = 273,
    AND_AND = 274,
    OR_OR = 275,
    GREATER_GREATER = 276,
    LESS_LESS = 277,
    LESS_AND = 278,
    GREATER_AND = 279,
    SEMI_SEMI = 280,
    LESS_LESS_MINUS = 281,
    AND_GREATER = 282,
    DOUBLE_OPEN = 283,
    DOUBLE_CLOSE = 284,
    yacc_EOF = 285
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 38 "parse.y" /* yacc.c:355  */

  WORD_DESC *word;		/* the word that we read. */
  int number;			/* the number that we read. */
  WORD_LIST *word_list;
  COMMAND *command;
  REDIRECT *redirect;
  ELEMENT element;
  PATTERN_LIST *pattern;

#line 161 "parse.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 176 "parse.tab.c" /* yacc.c:358  */

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
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   274

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    30,     2,
      40,    41,     2,     2,     2,    37,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
      36,     2,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,    34,    39,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    86,    94,   106,   117,   118,   122,   124,
     126,   128,   130,   132,   134,   136,   138,   140,   142,   144,
     146,   148,   150,   153,   155,   157,   159,   161,   165,   167,
     171,   172,   176,   178,   182,   184,   187,   191,   193,   195,
     197,   199,   202,   204,   206,   210,   212,   214,   217,   219,
     222,   225,   228,   231,   234,   237,   241,   245,   247,   249,
     254,   255,   259,   261,   265,   267,   271,   273,   277,   279,
     288,   292,   293,   294,   296,   300,   302,   304,   306,   308,
     310,   312,   316,   317,   318,   321,   322,   331,   332,   334,
     337,   339,   341,   343,   345,   347
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "THEN", "ELSE", "ELIF", "FI",
  "CASE", "ESAC", "FOR", "WHILE", "UNTIL", "DO", "DONE", "FUNCTION", "IN",
  "WORD", "NUMBER", "AND_AND", "OR_OR", "GREATER_GREATER", "LESS_LESS",
  "LESS_AND", "GREATER_AND", "SEMI_SEMI", "LESS_LESS_MINUS", "AND_GREATER",
  "DOUBLE_OPEN", "DOUBLE_CLOSE", "'&'", "';'", "'\\n'", "yacc_EOF", "'|'",
  "'>'", "'<'", "'-'", "'{'", "'}'", "'('", "')'", "$accept", "inputunit",
  "words", "redirection", "simple_command_element", "redirections",
  "simple_command", "command", "shell_command", "group_command",
  "elif_clause", "case_clause_1", "pattern_list_1", "case_clause_sequence",
  "pattern_list", "pattern", "list", "list0", "list1", "list_terminator",
  "newlines", "simple_list", "simple_list1", YY_NULLPTR
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
      38,    59,    10,   285,   124,    62,    60,    45,   123,   125,
      40,    41
};
# endif

#define YYPACT_NINF -46

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-46)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,   -28,   -46,     0,     9,   -46,   -46,    72,    -1,   104,
      80,    81,    12,    51,    85,   101,   -46,   -46,   107,   112,
     -46,   -46,   121,   -46,   -46,    87,   -46,   211,   -46,   109,
     234,   -46,   140,   173,   -46,   118,   141,   142,    27,   122,
     147,   148,    78,    83,   151,   155,   157,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   143,   139,
     -46,   -46,   -46,   -46,   211,   -46,   -46,   -46,   204,   204,
     -46,   -46,   -46,   -46,   -46,   229,   -13,   -46,    60,   -46,
     -46,   -46,   152,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   173,   173,   117,
     117,   173,    88,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
      22,   -46,   -46,   175,   178,    53,   -46,    53,   164,   164,
     -46,   -46,   -46,   -46,   195,   173,   173,   173,   173,   173,
     173,   194,   -46,   -46,   -46,    -3,   -46,   -46,   190,   102,
     -46,   -46,   -46,    53,   -46,   199,   206,   -46,   183,   183,
     167,   167,   167,   -46,   -46,   -46,   -46,    55,   -46,   -46,
     -29,   209,   179,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   203,   -46,   -46,   -46,    25,    56,   -46,
     216,   135,   -46,   -46,   -46,   -46,   -46,   -46,   210,   197,
     -46,   -46,   -46
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    85,     0,     0,    85,    85,     0,    28,     0,
       0,     0,     0,     0,     0,     0,     3,     5,     0,     0,
      85,    85,     0,    29,    32,    34,    95,    35,    51,     0,
      87,     4,     0,     0,    85,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,    14,    16,
      24,    27,    18,    22,    20,    26,     8,     9,     0,     0,
       1,    28,    33,    30,    36,     2,    85,    85,    88,    89,
      85,    85,    86,    81,    70,    71,     0,    85,     0,    85,
      85,    85,     0,    55,    85,    13,    15,    17,    25,    19,
      23,    21,    10,    11,    56,    50,    31,     0,     0,    92,
      93,     0,     0,    85,    85,    85,    85,    85,    85,    85,
       0,    85,     6,     0,     0,     0,    85,     0,    90,    91,
      94,    85,    85,    45,     0,     0,     0,    73,    74,    72,
       0,     0,    60,    85,    64,     0,    85,    85,     0,     0,
      48,    49,    54,     0,    52,     0,     0,    47,    75,    76,
      77,    78,    79,    80,    44,    61,    65,     0,    42,    68,
       0,     0,     0,    37,     7,    83,    82,    84,    85,    53,
      46,    85,    43,     0,    85,    38,    39,     0,    57,    69,
      62,    63,    85,    85,    85,    59,    66,    67,     0,     0,
      58,    40,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,   -46,   -17,   218,   -46,   -46,     2,   -46,   -31,
      67,   -46,   119,   -46,   123,   -46,    -5,   -46,   144,   -46,
     -26,   -46,   -45
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,   139,    23,    24,    64,    25,    73,    27,    28,
     124,   131,   132,   133,   134,   160,    32,    74,    75,   168,
      33,    29,    30
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      36,    37,    26,   109,    31,   173,   158,    83,    76,    78,
      63,     1,   174,     2,   159,    58,    59,    34,     3,    72,
       4,     5,     6,    99,   100,     7,    35,     8,     9,    72,
      49,    10,    11,    12,    13,   136,    14,    15,   182,    39,
      97,    98,    16,    17,   101,    18,    19,    96,    20,    50,
      21,   110,   118,   119,    72,   115,   120,    72,   117,    81,
     137,   184,   122,   183,   172,    20,   102,    82,    51,    52,
      26,    26,   159,   111,   113,   114,   112,   125,   126,   127,
     128,   129,   130,   135,   142,    72,   144,    72,    53,    38,
     143,    20,    72,   121,   122,   123,    87,    47,    48,    26,
      26,    89,    54,    26,    61,     9,   138,   157,    10,    11,
      12,    13,   169,    14,    15,    88,   145,   146,    55,   164,
      90,    60,    18,    19,    56,    40,    41,    42,    43,    57,
      44,   161,   162,   165,   166,   167,    66,    67,     2,    45,
      46,    65,   177,     3,    71,     4,     5,     6,   181,    77,
       7,    70,     8,     9,    79,    80,    10,    11,    12,    13,
     187,    14,    15,    84,    85,    86,   178,    72,    91,   180,
      18,    19,    92,    20,    93,    21,     2,   188,   189,   190,
      95,     3,    94,     4,     5,     6,   103,   104,     7,   140,
       8,     9,   141,   116,    10,    11,    12,    13,    70,    14,
      15,   108,   147,   154,   163,    72,   170,     2,    18,    19,
     171,    20,     3,    21,     4,     5,     6,   108,   176,     7,
     179,     8,     9,   175,   191,    10,    11,    12,    13,     9,
      14,    15,    10,    11,    12,    13,   192,    14,    15,    18,
      19,   186,    20,    62,    21,   185,    18,    19,   103,   104,
       0,     0,   155,    66,    67,     0,   156,     0,     0,   105,
     106,   107,     0,   108,    68,    69,     0,     0,    70,   148,
     149,   150,   151,   152,   153
};

static const yytype_int16 yycheck[] =
{
       5,     6,     0,    16,    32,    34,     9,    38,    34,    35,
      27,     1,    41,     3,    17,    20,    21,    17,     8,    32,
      10,    11,    12,    68,    69,    15,    17,    17,    18,    32,
      18,    21,    22,    23,    24,    13,    26,    27,    13,    40,
      66,    67,    32,    33,    70,    35,    36,    64,    38,    37,
      40,    77,    97,    98,    32,    81,   101,    32,    84,    32,
      38,     5,     6,    38,     9,    38,    71,    40,    17,    18,
      68,    69,    17,    13,    79,    80,    16,   103,   104,   105,
     106,   107,   108,   109,   115,    32,   117,    32,    37,    17,
     116,    38,    32,     5,     6,     7,    18,    17,    17,    97,
      98,    18,    17,   101,    17,    18,   111,   133,    21,    22,
      23,    24,   143,    26,    27,    37,   121,   122,    17,    17,
      37,     0,    35,    36,    17,    21,    22,    23,    24,    17,
      26,   136,   137,    31,    32,    33,    19,    20,     3,    35,
      36,    32,   168,     8,     4,    10,    11,    12,   174,    31,
      15,    34,    17,    18,    13,    13,    21,    22,    23,    24,
      25,    26,    27,    41,    17,    17,   171,    32,    17,   174,
      35,    36,    17,    38,    17,    40,     3,   182,   183,   184,
      41,     8,    39,    10,    11,    12,    19,    20,    15,    14,
      17,    18,    14,    41,    21,    22,    23,    24,    34,    26,
      27,    34,     7,     9,    14,    32,     7,     3,    35,    36,
       4,    38,     8,    40,    10,    11,    12,    34,    39,    15,
      17,    17,    18,    14,    14,    21,    22,    23,    24,    18,
      26,    27,    21,    22,    23,    24,    39,    26,    27,    35,
      36,    25,    38,    25,    40,   178,    35,    36,    19,    20,
      -1,    -1,   133,    19,    20,    -1,   133,    -1,    -1,    30,
      31,    32,    -1,    34,    30,    31,    -1,    -1,    34,   125,
     126,   127,   128,   129,   130
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     8,    10,    11,    12,    15,    17,    18,
      21,    22,    23,    24,    26,    27,    32,    33,    35,    36,
      38,    40,    43,    45,    46,    48,    49,    50,    51,    63,
      64,    32,    58,    62,    17,    17,    58,    58,    17,    40,
      21,    22,    23,    24,    26,    35,    36,    17,    17,    18,
      37,    17,    18,    37,    17,    17,    17,    17,    58,    58,
       0,    17,    46,    45,    47,    32,    19,    20,    30,    31,
      34,     4,    32,    49,    59,    60,    62,    31,    62,    13,
      13,    32,    40,    51,    41,    17,    17,    18,    37,    18,
      37,    17,    17,    17,    39,    41,    45,    62,    62,    64,
      64,    62,    58,    19,    20,    30,    31,    32,    34,    16,
      62,    13,    16,    58,    58,    62,    41,    62,    64,    64,
      64,     5,     6,     7,    52,    62,    62,    62,    62,    62,
      62,    53,    54,    55,    56,    62,    13,    38,    58,    44,
      14,    14,    51,    62,    51,    58,    58,     7,    60,    60,
      60,    60,    60,    60,     9,    54,    56,    62,     9,    17,
      57,    58,    58,    14,    17,    31,    32,    33,    61,    51,
       7,     4,     9,    34,    41,    14,    39,    62,    58,    17,
      58,    62,    13,    38,     5,    52,    25,    25,    58,    58,
      58,    14,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    43,    43,    44,    44,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    46,    46,
      47,    47,    48,    48,    49,    49,    49,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    51,    52,    52,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    57,    57,
      58,    59,    59,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    61,    62,    62,    63,    63,    63,
      64,    64,    64,    64,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     0,     2,     2,     2,
       3,     3,     2,     3,     2,     3,     2,     3,     2,     3,
       2,     3,     2,     3,     2,     3,     2,     2,     1,     1,
       1,     2,     1,     2,     1,     1,     2,     6,     7,     7,
      10,    10,     6,     7,     6,     5,     7,     6,     5,     5,
       3,     1,     5,     6,     5,     3,     3,     4,     6,     5,
       1,     2,     4,     4,     1,     2,     5,     5,     1,     3,
       2,     1,     3,     3,     3,     4,     4,     4,     4,     4,
       4,     1,     1,     1,     1,     0,     2,     1,     2,     2,
       4,     4,     3,     3,     4,     1
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
#line 78 "parse.y" /* yacc.c:1646  */
    {
			  /* Case of regular command.  Discard the error
			     safety net,and return the command just parsed. */
			  global_command = (yyvsp[-1].command);
			  eof_encountered = 0;
			  discard_parser_constructs (0);
			  YYACCEPT;
			}
#line 1406 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 87 "parse.y" /* yacc.c:1646  */
    {
			  /* Case of regular command, but not a very
			     interesting one.  Return a NULL command. */
			  global_command = (COMMAND *)NULL;
			  YYACCEPT;
			}
#line 1417 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 95 "parse.y" /* yacc.c:1646  */
    {
			  /* Error during parsing.  Return NULL command. */
			  global_command = (COMMAND *)NULL;
			  eof_encountered = 0;
			  discard_parser_constructs (1);
			  if (interactive)
			    YYACCEPT;
			  else
			    YYABORT;
			}
#line 1432 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 107 "parse.y" /* yacc.c:1646  */
    {
			  /* Case of EOF seen by itself.  Do ignoreeof or 
			     not. */
			  global_command = (COMMAND *)NULL;
			  handle_eof_input_unit ();
			  YYACCEPT;
			}
#line 1444 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 117 "parse.y" /* yacc.c:1646  */
    { (yyval.word_list) = NULL; }
#line 1450 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 119 "parse.y" /* yacc.c:1646  */
    { (yyval.word_list) = make_word_list ((yyvsp[0].word), (yyvsp[-1].word_list)); }
#line 1456 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 123 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ( 1, r_output_direction, (yyvsp[0].word)); }
#line 1462 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 125 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ( 0, r_input_direction, (yyvsp[0].word)); }
#line 1468 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 127 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ((yyvsp[-2].number), r_output_direction, (yyvsp[0].word)); }
#line 1474 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 129 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ((yyvsp[-2].number), r_input_direction, (yyvsp[0].word)); }
#line 1480 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 131 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ( 1, r_appending_to, (yyvsp[0].word)); }
#line 1486 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 133 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ((yyvsp[-2].number), r_appending_to, (yyvsp[0].word)); }
#line 1492 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 135 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ( 0, r_reading_until, (yyvsp[0].word)); }
#line 1498 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 137 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ((yyvsp[-2].number), r_reading_until, (yyvsp[0].word)); }
#line 1504 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 139 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ( 0, r_duplicating, (yyvsp[0].number)); }
#line 1510 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 141 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ((yyvsp[-2].number), r_duplicating, (yyvsp[0].number)); }
#line 1516 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 143 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ( 1, r_duplicating, (yyvsp[0].number)); }
#line 1522 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 145 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ((yyvsp[-2].number), r_duplicating, (yyvsp[0].number)); }
#line 1528 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 147 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ( 0, r_deblank_reading_until, (yyvsp[0].word)); }
#line 1534 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 149 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ((yyvsp[-2].number), r_deblank_reading_until, (yyvsp[0].word)); }
#line 1540 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 151 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ( 1, r_close_this, 0); }
#line 1546 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 154 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ((yyvsp[-2].number), r_close_this, 0); }
#line 1552 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 156 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ( 0, r_close_this, 0); }
#line 1558 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 158 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ((yyvsp[-2].number), r_close_this, 0); }
#line 1564 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 160 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ( 1, r_err_and_out, (yyvsp[0].word)); }
#line 1570 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 162 "parse.y" /* yacc.c:1646  */
    { (yyval.redirect) = make_redirection ( 1, r_err_and_out, (yyvsp[0].word)); }
#line 1576 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 166 "parse.y" /* yacc.c:1646  */
    { (yyval.element).word = (yyvsp[0].word); (yyval.element).redirect = 0; }
#line 1582 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 168 "parse.y" /* yacc.c:1646  */
    { (yyval.element).redirect = (yyvsp[0].redirect); (yyval.element).word = 0; }
#line 1588 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 173 "parse.y" /* yacc.c:1646  */
    { (yyvsp[-1].redirect)->next = (yyvsp[0].redirect); (yyval.redirect) = (yyvsp[-1].redirect); }
#line 1594 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 177 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_simple_command ((yyvsp[0].element), NULL); }
#line 1600 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 179 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_simple_command ((yyvsp[0].element), (yyvsp[-1].command)); }
#line 1606 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 183 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = clean_simple_command ((yyvsp[0].command)); }
#line 1612 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 185 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = (yyvsp[0].command); }
#line 1618 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 188 "parse.y" /* yacc.c:1646  */
    { (yyval.command)->redirects = (yyvsp[0].redirect); (yyval.command) = (yyvsp[-1].command); }
#line 1624 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 192 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_for_command ((yyvsp[-4].word), (WORD_LIST *)add_string_to_list ("$@", NULL), (yyvsp[-1].command)); }
#line 1630 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 194 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_for_command ((yyvsp[-5].word), (WORD_LIST *)add_string_to_list ("$@", NULL), (yyvsp[-1].command)); }
#line 1636 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 196 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_for_command ((yyvsp[-5].word), (WORD_LIST *)add_string_to_list ("$@", NULL), (yyvsp[-1].command)); }
#line 1642 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 198 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_for_command ((yyvsp[-8].word), (WORD_LIST *)reverse_list ((yyvsp[-5].word_list)), (yyvsp[-1].command)); }
#line 1648 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 200 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_for_command ((yyvsp[-8].word), (WORD_LIST *)reverse_list ((yyvsp[-5].word_list)), (yyvsp[-1].command)); }
#line 1654 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 203 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_case_command ((yyvsp[-4].word), NULL); }
#line 1660 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 205 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_case_command ((yyvsp[-5].word), (yyvsp[-2].pattern)); }
#line 1666 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 207 "parse.y" /* yacc.c:1646  */
    { report_syntax_error ("Inserted `;;'");
			  (yyval.command) = make_case_command ((yyvsp[-4].word), (yyvsp[-1].pattern)); }
#line 1673 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 211 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_if_command ((yyvsp[-3].command), (yyvsp[-1].command), NULL); }
#line 1679 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 213 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_if_command ((yyvsp[-5].command), (yyvsp[-3].command), (yyvsp[-1].command)); }
#line 1685 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 215 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_if_command ((yyvsp[-4].command), (yyvsp[-2].command), (yyvsp[-1].command)); }
#line 1691 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 218 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_while_command ((yyvsp[-3].command), (yyvsp[-1].command)); }
#line 1697 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 220 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_until_command ((yyvsp[-3].command), (yyvsp[-1].command)); }
#line 1703 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 223 "parse.y" /* yacc.c:1646  */
    { (yyvsp[-1].command)->subshell = 1; (yyval.command) = (yyvsp[-1].command); }
#line 1709 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 226 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = (yyvsp[0].command); }
#line 1715 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 229 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_function_def ((yyvsp[-4].word), (yyvsp[0].command)); }
#line 1721 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 232 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_function_def ((yyvsp[-4].word), (yyvsp[0].command)); }
#line 1727 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 235 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_function_def ((yyvsp[-3].word), (yyvsp[0].command)); }
#line 1733 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 238 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_function_def ((yyvsp[-1].word), (yyvsp[0].command)); }
#line 1739 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 242 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_group_command ((yyvsp[-1].command)); }
#line 1745 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 246 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_if_command ((yyvsp[-2].command), (yyvsp[0].command), NULL); }
#line 1751 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 248 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_if_command ((yyvsp[-4].command), (yyvsp[-2].command), (yyvsp[0].command)); }
#line 1757 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 250 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = make_if_command ((yyvsp[-3].command), (yyvsp[-1].command), (yyvsp[0].command)); }
#line 1763 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 256 "parse.y" /* yacc.c:1646  */
    { (yyvsp[0].pattern)->next = (yyvsp[-1].pattern); (yyval.pattern) = (yyvsp[0].pattern); }
#line 1769 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 260 "parse.y" /* yacc.c:1646  */
    { (yyval.pattern) = make_pattern_list ((yyvsp[-2].word_list), (yyvsp[0].command)); }
#line 1775 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 262 "parse.y" /* yacc.c:1646  */
    { (yyval.pattern) = make_pattern_list ((yyvsp[-2].word_list), NULL); }
#line 1781 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 268 "parse.y" /* yacc.c:1646  */
    { (yyvsp[0].pattern)->next = (yyvsp[-1].pattern); (yyval.pattern) = (yyvsp[0].pattern); }
#line 1787 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 272 "parse.y" /* yacc.c:1646  */
    { (yyval.pattern) = make_pattern_list ((yyvsp[-3].word_list), (yyvsp[-1].command)); }
#line 1793 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 274 "parse.y" /* yacc.c:1646  */
    { (yyval.pattern) = make_pattern_list ((yyvsp[-3].word_list), NULL); }
#line 1799 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 278 "parse.y" /* yacc.c:1646  */
    { (yyval.word_list) = make_word_list ((yyvsp[0].word), NULL); }
#line 1805 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 280 "parse.y" /* yacc.c:1646  */
    { (yyval.word_list) = make_word_list ((yyvsp[0].word), (yyvsp[-2].word_list)); }
#line 1811 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 289 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = (yyvsp[0].command); }
#line 1817 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 295 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = command_connect ((yyvsp[-2].command), 0, '&'); }
#line 1823 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 301 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = command_connect ((yyvsp[-3].command), (yyvsp[0].command), AND_AND); }
#line 1829 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 303 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = command_connect ((yyvsp[-3].command), (yyvsp[0].command), OR_OR); }
#line 1835 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 305 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = command_connect ((yyvsp[-3].command), (yyvsp[0].command), '&'); }
#line 1841 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 307 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = command_connect ((yyvsp[-3].command), (yyvsp[0].command), ';'); }
#line 1847 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 309 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = command_connect ((yyvsp[-3].command), (yyvsp[0].command), ';'); }
#line 1853 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 311 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = command_connect ((yyvsp[-3].command), (yyvsp[0].command), '|'); }
#line 1859 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 333 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = command_connect ((yyvsp[-1].command), (COMMAND *)NULL, '&'); }
#line 1865 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 338 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = command_connect ((yyvsp[-3].command), (yyvsp[0].command), AND_AND); }
#line 1871 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 340 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = command_connect ((yyvsp[-3].command), (yyvsp[0].command), OR_OR); }
#line 1877 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 342 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = command_connect ((yyvsp[-2].command), (yyvsp[0].command), '&'); }
#line 1883 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 344 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = command_connect ((yyvsp[-2].command), (yyvsp[0].command), ';'); }
#line 1889 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 346 "parse.y" /* yacc.c:1646  */
    { (yyval.command) = command_connect ((yyvsp[-3].command), (yyvsp[0].command), '|'); }
#line 1895 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 1899 "parse.tab.c" /* yacc.c:1646  */
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
#line 349 "parse.y" /* yacc.c:1906  */


/* Initial size to allocate for tokens, and the
   amount to grow them by. */
#define TOKEN_DEFAULT_GROW_SIZE 512

/* The token currently being read. */
int current_token = 0;

/* The last read token, or NULL.  read_token () uses this for context
   checking. */
int last_read_token = 0;

/* The token read prior to last_read_token. */
int token_before_that = 0;

/* Global var is non-zero when end of file has been reached. */
int EOF_Reached = 0;

/* yy_getc () returns the next available character from input or EOF.
   yy_ungetc (c) makes `c' the next character to read.
   init_yy_io (get, unget), makes the function `get' the installed function
   for getting the next character, and makes `unget' the installed function
   for un-getting a character. */
return_EOF ()			/* does nothing good. */
{
  return (EOF);
}

/* Variables containing the current get and unget functions. */

/* Some stream `types'. */
#define st_stream 0
#define st_string 1

Function *get_yy_char = return_EOF;
Function *unget_yy_char = return_EOF;
int yy_input_type = st_stream;
FILE *yy_input_dev = (FILE *)NULL;

/* The current stream name.  In the case of a file, this is a filename. */
char *stream_name = (char *)NULL;

/* Function to set get_yy_char and unget_yy_char. */
init_yy_io (get_function, unget_function, type, location)
     Function *get_function, *unget_function;
     int type;
     FILE *location;
{
  get_yy_char = get_function;
  unget_yy_char = unget_function;
  yy_input_type = type;
  yy_input_dev = location;
}

/* Call this to get the next character of input. */
yy_getc ()
{
  return (*get_yy_char) ();
}

/* Call this to unget C.  That is, to make C the next character
   to be read. */
yy_ungetc (c)
{
  return (*unget_yy_char) (c);
}

/* **************************************************************** */
/*								    */
/*		  Let input be read from readline ().		    */
/*								    */
/* **************************************************************** */

#ifdef READLINE
char *current_readline_prompt = (char *)NULL;
char *current_readline_line = (char *)NULL;
int current_readline_line_index = 0;

static int readline_initialized_yet = 0;
yy_readline_get ()
{
  if (!current_readline_line)
    {
      char *readline ();
      SigHandler *old_sigint;
      extern sighandler throw_to_top_level ();
      
      if (!readline_initialized_yet)
	{
	  initialize_readline ();
	  readline_initialized_yet = 1;
	}

      old_sigint = (SigHandler *)signal (SIGINT, throw_to_top_level);
	  if (!current_readline_prompt)
	    current_readline_line = readline ("");
	  else
	    current_readline_line = readline (current_readline_prompt);
      signal (SIGINT, old_sigint);

      current_readline_line_index = 0;

      if (!current_readline_line)
	{
	  current_readline_line_index = 0;
	  return (EOF);
	}

      current_readline_line =
	(char *)xrealloc (current_readline_line,
			  2 + strlen (current_readline_line));
      strcat (current_readline_line, "\n");
    }

  if (!current_readline_line[current_readline_line_index])
    {
      free (current_readline_line);
      current_readline_line = (char *)NULL;
      return (yy_readline_get ());
    }
  else
    {
      int c = current_readline_line[current_readline_line_index++];
      return (c);
    }
}

yy_readline_unget (c)
{
  if (current_readline_line_index && current_readline_line)
    current_readline_line[--current_readline_line_index] = c;
}
  
with_input_from_stdin ()
{
  init_yy_io (yy_readline_get, yy_readline_unget,
	      st_string, current_readline_line);
  stream_name = savestring ("readline stdin");
}

#else  /* READLINE */

with_input_from_stdin ()
{
  with_input_from_stream (stdin, "stdin");
}
#endif  /* READLINE */

/* **************************************************************** */
/*								    */
/*   Let input come from STRING.  STRING is zero terminated.	    */
/*								    */
/* **************************************************************** */

yy_string_get ()
{
  /* If the string doesn't exist, or is empty, EOF found. */
  if (!(char *)yy_input_dev || !*(char *)yy_input_dev)
    return (EOF);
  else {
    register char *temp = (char *)yy_input_dev;
    int c = *temp++;
    yy_input_dev = (FILE *)temp;
    return (c);
  }
}

yy_string_unget (c)
     int c;
{
  register char *temp = (char *)yy_input_dev;
  *(--temp) = c;
  yy_input_dev = (FILE *)temp;
  return (c);
}

with_input_from_string (string, name)
     char *string;
     char *name;
{
  init_yy_io (yy_string_get, yy_string_unget, st_string, string);
  stream_name = savestring (name);
}

/* **************************************************************** */
/*								    */
/*		     Let input come from STREAM.		    */
/*								    */
/* **************************************************************** */

yy_stream_get ()
{
  if (yy_input_dev)
#ifdef SYSV
    return (sysv_getc (yy_input_dev));
#else
    return (getc (yy_input_dev));
#endif  /* SYSV */
  else return (EOF);
}

yy_stream_unget (c)
     int c;
{
  ungetc (c, yy_input_dev);
}

with_input_from_stream (stream, name)
     FILE *stream;
     char *name;
{
  init_yy_io (yy_stream_get, yy_stream_unget, st_stream, stream);
  stream_name = savestring (name);
}

typedef struct stream_saver {
  struct stream_saver *next;
  Function *getter, *putter;
  int type, line;
  char *location, *name;
} STREAM_SAVER;

/* The globally known line number. */
int line_number = 0;

STREAM_SAVER *stream_list = (STREAM_SAVER *)NULL;

push_stream ()
{
  STREAM_SAVER *temp = (STREAM_SAVER *)xmalloc (sizeof (STREAM_SAVER));
  temp->type = yy_input_type;
  temp->location = (char *)yy_input_dev;
  temp->getter = get_yy_char;
  temp->putter = unget_yy_char;
  temp->line = line_number;
  temp->name = stream_name; stream_name = (char *)NULL;
  temp->next = stream_list;
  stream_list = temp;
  EOF_Reached = line_number = 0;
}

pop_stream ()
{
  if (!stream_list)
    {
      EOF_Reached = 1;
    }
  else
    {
      STREAM_SAVER *temp = stream_list;
    
      EOF_Reached = 0;
      stream_list = stream_list->next;

      if (stream_name)
	free (stream_name);
      stream_name = temp->name;

      init_yy_io (temp->getter, temp->putter, temp->type, temp->location);
      line_number = temp->line;
      free (temp);
    }
}


/* Return a line of text, taken from wherever yylex () reads input.
   If there is no more input, then we return NULL. */
char *
read_a_line ()
{
  char *line_buffer = (char *)NULL;
  int index = 0, buffer_size = 0;
  int c;

  while (c = yy_getc ())
    {
      /* If there is no more input, then we return NULL. */
      if (c == EOF)
	{
	  c = '\n';
	  if (!line_buffer)
	    return ((char *)NULL);
	}

      if (index + 1 > buffer_size)
	if (!buffer_size)
	  line_buffer = (char *)xmalloc (buffer_size = 200);
	else
	  line_buffer = (char *)xrealloc (line_buffer, buffer_size += 200);

      line_buffer[index++] = c;
      if (c == '\n')
	{
	  line_buffer[index] = '\0';
	  return (line_buffer);
	}
    }
}


/* Return a line as in read_a_line (), but insure that the prompt is
   the secondary prompt. */
char *
read_secondary_line ()
{
  char *decode_prompt_string ();
  char *temp_prompt = get_string_value ("PS2");

#ifdef READLINE
  if (!no_line_editing)
    {
      extern char *current_readline_prompt;

      if (current_readline_prompt)
	{
	  free (current_readline_prompt);
	  current_readline_prompt = (char *)NULL;
	}

      if (temp_prompt)
	current_readline_prompt = decode_prompt_string (temp_prompt);
      else
	current_readline_prompt = (savestring (""));
    }
  else
#endif  /* READLINE */
    {
      printf ("%s", temp_prompt ? temp_prompt : "");
      fflush (stdout);
    }

  return (read_a_line ());
}

/* **************************************************************** */
/*								    */
/*				YYLEX ()			    */
/*								    */
/* **************************************************************** */

/* Reserved words.  These are only recognized as the first word of a
   command.  TOKEN_WORD_ALIST. */
struct {
  char *word;
  int token;
} token_word_alist[] = {
  {"if", IF},
  {"then", THEN},
  {"else", ELSE},
  {"elif", ELIF},
  {"fi", FI},
  {"case", CASE},
  {"esac", ESAC},
  {"for", FOR},
  {"while", WHILE},
  {"until", UNTIL},
  {"do", DO},
  {"done", DONE},
  {"in", IN},
  {"function", FUNCTION},
  {"{", '{'},
  {"}", '}'},
  {(char *)NULL, 0}
};

/* Where shell input comes from.  For each line that we read, alias
   and history expansion are done. */
char *shell_input_line = (char *)NULL;
int shell_input_line_index = 0;
int shell_input_line_size = 0;

/* Either zero, or EOF. */
int shell_input_line_terminator = 0;

/* Return the next shell input character.  This always reads characters
   from shell_input_line; when that line is exhausted, it is time to
   read the next line. */
int
shell_getc (remove_quoted_newline)
     int remove_quoted_newline;
{
  extern int login_shell;
  int c;

  if (!shell_input_line || !shell_input_line[shell_input_line_index])
    {
      register int i, l;
      char *pre_process_line (), *expansions;

      restart_read_next_line:

      line_number++;

    restart_read:

      i = 0;
      shell_input_line_terminator = 0;

#ifdef JOB_CONTROL
      notify_and_cleanup ();
#endif

      clearerr (stdin);
      while (c = yy_getc ())
	{
	  if (i + 2 > shell_input_line_size)
	    if (!shell_input_line)
	      shell_input_line = (char *)xmalloc (shell_input_line_size = 256);
	    else
	      shell_input_line =
		(char *)xrealloc (shell_input_line, shell_input_line_size += 256);

	  if (c == EOF)
	    {
	      clearerr (stdin);

	      if (!i)
		shell_input_line_terminator = EOF;

	      shell_input_line[i] = '\0';
	      break;
	    }

	  shell_input_line[i++] = c;

	  if (c == '\n')
	    {
	      shell_input_line[--i] = '\0';
	      break;
	    }
	}
      shell_input_line_index = 0;

      if (!shell_input_line[0] || shell_input_line[0] == '#')
	goto after_pre_process;

      expansions = pre_process_line (shell_input_line, 1, 1);

      free (shell_input_line);
      shell_input_line = expansions;

      if (shell_input_line)
	{
	  if (echo_input_at_read)
	    fprintf (stderr, "%s\n", shell_input_line);

	  shell_input_line_size = strlen (expansions);

	}
      else
	{
	  shell_input_line_size = 0;
	  prompt_again ();
	  goto restart_read;
	}

    after_pre_process:
      /* Add the newline to the end of this string, iff the string does
	 not already end in an EOF character.  */
      if (shell_input_line_terminator != EOF)
	{
	  l = strlen (shell_input_line);

	  if (l + 3 > shell_input_line_size)
	    shell_input_line =
	      (char *)xrealloc (shell_input_line,
				1 + (shell_input_line_size += 2));
	  strcpy (shell_input_line + l, "\n");
	}
    }
  
  c = shell_input_line[shell_input_line_index];

  if (c)
    shell_input_line_index++;

  if (c == '\\' && remove_quoted_newline &&
      shell_input_line[shell_input_line_index] == '\n')
    {
      prompt_again ();
      goto restart_read_next_line;
    }

  if (!c && shell_input_line_terminator == EOF)
    {
      if (shell_input_line_index != 0)
	return ('\n');
      else
	return (EOF);
    }

  return (c);
}

/* Put C back into the input for the shell. */
shell_ungetc (c)
     int c;
{
  if (shell_input_line && shell_input_line_index)
    shell_input_line[--shell_input_line_index] = c;
}

/* Discard input until CHARACTER is seen. */
discard_until (character)
     int character;
{
  int c;
  while ((c = shell_getc (0)) != EOF && c != character)
    ;
  if (c != EOF )
    shell_ungetc (c);
}

/* Tell readline () that we have some text for it to edit. */
re_edit (text)
     char *text;
{
#ifdef READLINE
  if (strcmp (stream_name, "readline stdin") == 0)
    bash_re_edit (text);
#endif
}

/* Non-zero means do no history expansion on this line, regardless
   of what history_expansion says. */
int history_expansion_inhibited = 0;

/* Do pre-processing on LINE.  If PRINT_CHANGES is non-zero, then
   print the results of expanding the line if there were any changes.
   If there is an error, return NULL, otherwise the expanded line is
   returned.  If ADDIT is non-zero the line is added to the history
   list after history expansion, but before alias expansion.  ADDIT
   is just a suggestion; REMEMBER_ON_HISTORY can veto, and does.
   Right now this does history and alias expansion. */
char *
pre_process_line (line, print_changes, addit)
     char *line;
     int print_changes, addit;
{
  extern int history_expansion;
  extern int remember_on_history;
  int history_expand ();
  char *history_value;
  char *return_value = line;
  int expanded = 0;

#ifdef ALIAS
  char *alias_expand (), *alias_value;
#endif

  /* History expand the line.  If this results in no errors, then
     add that line to the history if ADDIT is non-zero. */
  if (!history_expansion_inhibited && history_expansion)
    {
      expanded = history_expand (line, &history_value);

      if (expanded)
	{
	  if (print_changes)
	    fprintf (stderr, "%s\n", history_value);

	  /* If there was an error, return NULL. */
	  if (expanded < 0)
	    {
	      free (history_value);

	      /* New hack.  We can allow the user to edit the
		 failed history expansion. */
	      re_edit (line);

	      return ((char *)NULL);
	    }
	}

      /* Let other expansions know that return_value can be free'ed,
	 and that a line has been added to the history list. */
      expanded = 1;
      return_value = history_value;
    }

  if (addit && remember_on_history)
    {
      extern int history_control;

      switch (history_control)
	{
	case 0:
	  add_history (return_value);
	  break;
	case 1:
	  if (*return_value != ' ')
	    add_history (return_value);
	  break;
	case 2:
	  {
	    HIST_ENTRY *temp = previous_history ();
	    if (!temp || (strcmp (temp->line, return_value) != 0))
	      add_history (return_value);
	    using_history ();
	  }
	  break;
	}
    }

#ifdef ALIAS
  alias_value = alias_expand (return_value);

  if (expanded)
    {
      expanded = 0;
      free (return_value);
    }

  return_value = alias_value;

#else
  return_value = savestring (line);
#endif /* ALIAS */

#ifdef ALIAS
#ifdef NEVER  /* Expanding history-wise here is sematically incorrect
		 for this shell, and should never be done.  I figured
		 it out, so just trust me, okay? */
  /* History expand the alias.  This is a special hack.  Don't you
     just hate this? */

  if (!history_expansion_inhibited && history_expansion)
    {
      expanded = history_expand (return_value, &history_value);

      if (expanded < 0)
	{
	  free (history_value);
	  free (return_value);
	  return ((char *)NULL);
	}

      if (expanded)
	{
	  free (return_value);
	  return_value = history_value;
	}
    }
#endif  /* NEVER */
#endif  /* ALIAS */
  return (return_value);
}


/* Place to remember the token.  We try to keep the buffer
   at a reasonable size, but it can grow. */
char *token = NULL;

/* Current size of the token buffer. */
int token_buffer_size = 0;

/* Command to read_token () explaining what we want it to do. */
#define READ 0
#define RESET 1

/* prompt_string_pointer points to one of these,
   never to an actual string. */
char *ps1_prompt, *ps2_prompt;

/* Handle on the current prompt string.  Indirectly points through
   ps1_ or ps2_prompt. */
char **prompt_string_pointer;

/* Function for yyparse to call.  yylex keeps track of
   the last two tokens read, and calls read_token.  */
yylex ()
{
  if (interactive && (!current_token || current_token == '\n'))
    {
      /* Before we print a prompt, we might have to check mailboxes.
	 We do this only if it is time to do so. Notice that only here
	 is the mail alarm reset; nothing takes place in check_mail ()
	 except the checking of mail.  Please don't change this. */
      if (time_to_check_mail ())
	{
	  check_mail ();
	  reset_mail_timer ();
	}

      /* Allow the execution of a random command just before the printing
	 of each prompt.  If the shell variable PROMPT_COMMAND
	 is set then the value of it is the command to execute. */
      {
	char *command_to_execute = get_string_value ("PROMPT_COMMAND");

	if (command_to_execute)
	  {
	    extern Function *last_shell_builtin, *this_shell_builtin;
	    Function *temp_last, *temp_this;

	    temp_last = last_shell_builtin;
	    temp_this = this_shell_builtin;

	    parse_and_execute (savestring (command_to_execute),
			       "PROMPT_COMMAND");
	    last_shell_builtin = temp_last;
	    this_shell_builtin = temp_this;
	  }
      }

      prompt_again ();
      prompt_string_pointer = &ps2_prompt;
    }

  token_before_that = last_read_token;
  last_read_token = current_token;
  current_token = read_token (READ);
  return (current_token);
}

/* Called from shell.c when Control-C is typed at top level.  Or
   by the error rule at top level. */
reset_parser ()
{
  read_token (RESET);
}
  
/* When non-zero, we have read the required tokens
   which allow ESAC to be the next one read. */
static int allow_esac_as_next = 0;

/* When non-zero, accept single '{' as a token itself. */
static int allow_open_brace = 0;

/* DELIMITER is the value of the delimiter that is currently
   enclosing, or zero for none. */
static int delimiter = 0;

/* When non-zero, an open-brace used to create a group is awaiting a close
   brace partner. */
static int open_brace_awaiting_satisfaction = 0;

/* If non-zero, it is the token that we want read_token to return regardless
   of what text is (or isn't) present to be read.  read_token resets this. */
int token_to_read = 0;

/* Read the next token.  Command can be READ (normal operation) or 
   RESET (to normalize state. */
read_token (command)
     int command;
{
  int character;		/* Current character. */
  int peek_char;		/* Temporary look-ahead character. */
  int result;			/* The thing to return. */
  WORD_DESC *the_word;		/* The value for YYLVAL when a WORD is read. */

  if (token_buffer_size < TOKEN_DEFAULT_GROW_SIZE)
    {
      if (token)
	free (token);
      token = (char *)xmalloc (token_buffer_size = TOKEN_DEFAULT_GROW_SIZE);
    }

  if (command == RESET)
    {
      delimiter = 0;
      open_brace_awaiting_satisfaction = 0;
      if (shell_input_line)
	{
	  free (shell_input_line);
	  shell_input_line = (char *)NULL;
	  shell_input_line_size = 0;
	}
      last_read_token = '\n';
      token_to_read = '\n';
      return;
    }

  if (token_to_read)
    {
      int rt = token_to_read;
      token_to_read = 0;
      return (rt);
    }

  /* Read a single word from input.  Start by skipping blanks. */
  while ((character = shell_getc (1)) != EOF && whitespace (character));

  if (character == EOF)
    return (yacc_EOF);

  if (character == '#' && !interactive)
    {
      /* A comment.  Discard until EOL or EOF, and then return a newline. */
      discard_until ('\n');
      shell_getc (0);
      return ('\n');
    }

  if (character == '\n')
    return (character);

  if (member (character, "()<>;&|"))
    {
      /* Please note that the shell does not allow whitespace to
	 appear in between tokens which are character pairs, such as
	 "<<" or ">>".  I believe this is the correct behaviour. */

      if (character == (peek_char = shell_getc (1)))
	{
	  switch (character)
	    {
	      /* If '<' then we could be at "<<" or at "<<-".  We have to
		 look ahead one more character. */
	    case '<':
	      peek_char = shell_getc (1);
	      if (peek_char == '-')
		return (LESS_LESS_MINUS);
	      else
		{
		  shell_ungetc (peek_char);
		  return (LESS_LESS);
		}

	    case '(': return (DOUBLE_OPEN);
	    case ')': return (DOUBLE_CLOSE);
	    case '>': return (GREATER_GREATER);
	    case ';':	return (SEMI_SEMI);
	    case '&': return (AND_AND);
	    case '|': return (OR_OR);
	    }
	}
      else
	{
	  if (peek_char == '&')
	    {
	      switch (character)
		{
		case '<': return (LESS_AND);
		case '>': return (GREATER_AND);
		}
	    }
	  if (peek_char == '>' && character == '&')
	    return (AND_GREATER);
	}
      shell_ungetc (peek_char);

      /* If we look like we are reading the start of a function
	 definition, then let the reader know about it so that
	 we will do the right thing with `{'. */
      if (character == ')' &&
	  last_read_token == '(' && token_before_that == WORD)
	allow_open_brace = 1;

      return (character);
    }

  /* Hack <&- (close stdin) case. */
  if (character == '-')
    {
      switch (last_read_token)
	{
	case LESS_AND:
	case GREATER_AND:
	  return (character);
	}
    }
  
  /* Okay, if we got this far, we have to read a word.  Read one,
     and then check it against the known ones. */
  {
    /* Index into the token that we are building. */
    int token_index = 0;

    /* ALL_DIGITS becomes zero when we see a non-digit. */
    int all_digits = digit (character);

    /* DOLLAR_PRESENT becomes non-zero if we see a `$'. */
    int dollar_present = 0;

    /* QUOTED becomes non-zero if we see one of ("), ('), (`), or (\). */
    int quoted = 0;

    /* Non-zero means to ignore the value of the next character, and just
       to add it no matter what. */
    int pass_next_character = 0;

    /* Non-zero means parsing a dollar-paren construct.  It is the count of
       un-quoted closes we need to see. */
    int dollar_paren_level = 0;

    /* Another level variable.  This one is for dollar_parens inside of
       double-quotes. */
    int delimited_paren_level = 0;

    for (;;)
      {
	if (character == EOF)
	  goto got_token;

	if (pass_next_character)
	  {
	    pass_next_character = 0;
	    goto got_character;
	  }

	/* Handle double backslash.  These are always magic.  The
	   second backslash does not cause a trailing newline to be
	   eaten. */

	if (character == '\\')
	  {
	    peek_char = shell_getc (0);
	    if (peek_char != '\\')
	      shell_ungetc (peek_char);
	    else
	      {
		token[token_index++] = character;
		goto got_character;
	      }
	  }

	/* Handle backslashes.  Quote lots of things when not inside of
	   double-quotes, quote some things inside of double-quotes. */

	if (character == '\\' && delimiter != '\'')
	  {
	    peek_char = shell_getc (0);

	    /* Backslash-newline is ignored in all other cases. */
	    if (peek_char == '\n')
	      {
		character = '\n';
		goto next_character;
	      }
	    else
	      {
		shell_ungetc (peek_char);

		/* If the next character is to be quoted, do it now. */
		if (!delimiter || delimiter == '`' ||
		    ((delimiter == '"' ) &&
		     (member (peek_char, slashify_in_quotes))))
		  {
		    pass_next_character++;
		    quoted = 1;
		    goto got_character;
		  }
	      }
	  }

	if (delimiter)
	  {
	    if (character == delimiter)
	      {
		delimiter = 0;
		if (delimited_paren_level)
		  {
		    report_error ("Expected ')' before %c", character);
		    return ('\n');
		  }
		goto got_character;
	      }
	  }

	if (!delimiter || delimiter == '`' || delimiter == '"')
	  {
	    if (character == '$')
	      {
		peek_char = shell_getc (1);
		shell_ungetc (peek_char);
		if (peek_char == '(')
		  {
		    if (!delimiter)
		      dollar_paren_level++;
		    else
		      delimited_paren_level++;

		    pass_next_character++;
		    goto got_character;
		  }
	      }
		
	    if (character == ')')
	      {
		if (delimiter && delimited_paren_level)
		  delimited_paren_level--;

		if (!delimiter && dollar_paren_level)
		  {
		    dollar_paren_level--;
		    goto got_character;
		  }
	      }
	  }

	if (!dollar_paren_level && !delimiter &&
	    member (character, " \t\n;&()|<>"))
	  {
	    shell_ungetc (character);
	    goto got_token;
	  }
    
	if (!delimiter)
	  {
	    if (character == '"' || character == '`' || character == '\'')
	      {
		quoted = 1;
		delimiter = character;
		goto got_character;
	      }
	  }

	if (all_digits) all_digits = digit (character);
	if (character == '$') dollar_present = 1;

      got_character:

	token[token_index++] = character;

	if (token_index == (token_buffer_size - 1))
	  token = (char *)xrealloc (token, (token_buffer_size
					    += TOKEN_DEFAULT_GROW_SIZE));
	{
	  char *decode_prompt_string ();

	next_character:
	  if (character == '\n' && interactive)
	    prompt_again ();
	}
	character = shell_getc ((delimiter != '\''));
      }

got_token:

    token[token_index] = '\0';
	
    if ((delimiter || dollar_paren_level) && character == EOF)
      {
	if (dollar_paren_level && !delimiter)
	  delimiter = ')';

	report_error ("Unexpected EOF.  Looking for `%c'.", delimiter);
	return (-1);
      }

    if (all_digits)
      {
	/* Check to see what thing we should return.  If the last_read_token
	   is a `<', or a `&', or the character which ended this token is
	   a '>' or '<', then, and ONLY then, is this input token a NUMBER.
	   Otherwise, it is just a word, and should be returned as such. */

	if ((character == '<' || character == '>') ||
	    (last_read_token == LESS_AND ||
	     last_read_token == GREATER_AND))
	  {
	    sscanf (token, "%d", &(yylval.number));
	    return (NUMBER);
	  }
      }

    /* Handle special case.  IN is recognized if the last token
       was WORD and the token before that was FOR or CASE. */
    if ((strcmp (token, "in") == 0) &&
	(last_read_token == WORD) &&
	((token_before_that == FOR) ||
	 (token_before_that == CASE)))
      {
	if (token_before_that == CASE) allow_esac_as_next++;
	return (IN);
      }

    /* Ditto for DO in the FOR case. */
    if ((strcmp (token, "do") == 0) &&
	(last_read_token == WORD) &&
	(token_before_that == FOR))
      return (DO);

    /* Ditto for ESAC in the CASE case. 
       Specifically, this handles "case word in esac", which is a legal
       construct, certainly because someone will pass an empty arg to the
       case construct, and we don't want it to barf.  Of course, we should
       insist that the case construct has at least one pattern in it, but
       the designers disagree. */
    if (allow_esac_as_next)
      {
	allow_esac_as_next--;
	if (strcmp (token, "esac") == 0)
	  return (ESAC);
      }

    /* Ditto for `{' in the FUNCTION case. */
    if (allow_open_brace)
      {
	allow_open_brace = 0;
	if (strcmp (token, "{") == 0)
	  {
	    open_brace_awaiting_satisfaction++;
	    return ('{');
	  }
      }

    /* Check to see if it is a reserved word. */
    if (!dollar_present && !quoted &&
	reserved_word_acceptable (last_read_token))
      {
	int i;
	for (i = 0; token_word_alist[i].word != (char *)NULL; i++)
	  if (strcmp (token, token_word_alist[i].word) == 0)
	    {
	      if (token_word_alist[i].token == '{')
		open_brace_awaiting_satisfaction++;

	      return (token_word_alist[i].token);
	    }
      }

    /* What if we are attempting to satisfy an open-brace grouper? */
    if (open_brace_awaiting_satisfaction && strcmp (token, "}") == 0)
      {
	open_brace_awaiting_satisfaction--;
	return ('}');
      }
      
    the_word = (WORD_DESC *)xmalloc (sizeof (WORD_DESC));
    the_word->word = (char *)xmalloc (1 + strlen (token));
    strcpy (the_word->word, token);
    the_word->dollar_present = dollar_present;
    the_word->quoted = quoted;
    the_word->assignment = assignment (token);

    yylval.word = the_word;
    result = WORD;
    if (last_read_token == FUNCTION)
      allow_open_brace = 1;
  }
  return (result);
}

/* Return 1 if TOKEN is a token that after being read would allow
   a reserved word to be seen, else 0. */
reserved_word_acceptable (token)
     int token;
{
  if (member (token, "\n;()|&{") ||
      token == AND_AND ||
      token == OR_OR ||
      token == SEMI_SEMI ||
      token == DO ||
      token == IF ||
      token == THEN ||
      token == ELSE ||
      token == ELIF ||
      token == 0)
    return (1);
  else
    return (0);
}

/* Issue a prompt, or prepare to issue a prompt when the next character
   is read. */
prompt_again ()
{
  char *decode_prompt_string ();
  char *temp_prompt;

  ps1_prompt = get_string_value ("PS1");
  ps2_prompt = get_string_value ("PS2");

  if (!prompt_string_pointer)
    prompt_string_pointer = &ps1_prompt;

  if (*prompt_string_pointer)
    temp_prompt = decode_prompt_string (*prompt_string_pointer);
  else
    temp_prompt = savestring ("");

#ifdef READLINE
  if (!no_line_editing)
    {
      if (current_readline_prompt)
	free (current_readline_prompt);
      
      current_readline_prompt = temp_prompt;
    }
  else
#endif  /* READLINE */
    {
      if (interactive)
	{
	  fprintf (stderr, "%s", temp_prompt);
	  fflush (stderr);
	}
      free (temp_prompt);
    }
}

/* This sucks. but it is just a crock for SYSV.  The whole idea of MAXPATHLEN
   is a crock if you ask me.  Why can't we just have dynamically defined
   sizes?  (UCSB crashes every 20 minutes on me.) */
#ifndef MAXPATHLEN
#define MAXPATHLEN 1024
#endif  /* MAXPATHLEN */

/* Return a string which will be printed as a prompt.  The string
   may contain special characters which are decoded as follows:
   
	\t	the time
	\d	the date
	\n	CRLF
	\s	the name of the shell
	\w	the current working directory
	\W	the last element of PWD
	\u	your username
	\h	the hostname
	\#	the command number of this command
	\!	the history number of this command
	\$	a $ or a # if you are root
	\<octal> character code in octal
	\\	a backslash
*/
#include <sys/param.h>
#include <time.h>

#define PROMPT_GROWTH 50
char *
decode_prompt_string (string)
     char *string;
{
  int result_size = PROMPT_GROWTH;
  int result_index = 0;
  char *result = (char *)xmalloc (PROMPT_GROWTH);
  int c;
  char *temp = (char *)NULL;

  result[0] = 0;
  while (c = *string++)
    {
      if (c == '\\')
	{
	  c = *string;

	  switch (c)
	    {

	    case '0':
	    case '1':
	    case '2':
	    case '3':
	    case '4':
	    case '5':
	    case '6':
	    case '7':
	      {
		char octal_string[4];
		int n;

		strncpy (octal_string, string, 3);
		octal_string[3] = '\0';

		n = read_octal (octal_string);

		temp = savestring ("\\");
		if (n != -1)
		  {
		    string += 3;
		    temp[0] = n;
		  }

		c = 0;
		goto add_string;
	      }
	  
	    case 't':
	    case 'd':

	      /* Make the current time/date into a string. */
	      {
		long the_time = time (0);
		char *ttemp = ctime (&the_time);
		temp = savestring (ttemp);

		if (c == 't')
		  {
		    strcpy (temp, temp + 11);
		    temp[8] = '\0';
		  }
		else
		  temp[10] = '\0';

		goto add_string;
	      }

	    case 'n':
	      temp = savestring ("\r\n");
	      goto add_string;

	    case 's':
	      {
		extern char *shell_name;
		temp = savestring (shell_name);
		goto add_string;
	      }
	
	    case 'w':
	    case 'W':
	      {
		/* Use the value of PWD because it is much more effecient. */
#define EFFICIENT
#ifdef EFFICIENT
		char *polite_directory_format (), t_string[MAXPATHLEN];

		temp = get_string_value ("PWD");

		if (!temp)
		  getwd (t_string);
		else
		  strcpy (t_string, temp);
#else
		getwd (t_string);
#endif  /* EFFICIENT */

		if (c == 'W')
		  {
		    char *rindex (), *dir = rindex (t_string, '/');
		    if (dir)
		      strcpy (t_string, dir + 1);
		    temp = savestring (t_string);
		  }
		else
		  temp = savestring (polite_directory_format (t_string));
		goto add_string;
	      }
      
	    case 'u':
	      {
		extern char *current_user_name;
		temp = savestring (current_user_name);

		goto add_string;
	      }

	    case 'h':
	      {
		extern char *current_host_name;
		char *t_string, *index ();

		temp = savestring (current_host_name);
		if (t_string = index (temp, '.'))
		  *t_string = '\0';
		
		goto add_string;
	      }

	    case '#':
	      {
		extern int current_command_number;
		char number_buffer[20];
		sprintf (number_buffer, "%d", current_command_number);
		temp = savestring (number_buffer);
		goto add_string;
	      }

	    case '!':
	      {
		extern int history_base, where_history ();
		char number_buffer[20];

		using_history ();
		if (get_string_value ("HISTSIZE"))
		  sprintf (number_buffer, "%d",
			   history_base + where_history ());
		else
		  strcpy (number_buffer, "!");
		temp = savestring (number_buffer);
		goto add_string;
	      }

	    case '$':
	      temp = savestring (geteuid () == 0 ? "#" : "$");
	      goto add_string;

	    case '\\':
	      temp = savestring ("\\");
	      goto add_string;

	    default:
	      temp = savestring ("\\ ");
	      temp[1] = c;

	    add_string:
	      if (c)
		string++;
	      result =
		(char *)sub_append_string (temp, result,
					   &result_index, &result_size);
	      temp = (char *)NULL; /* Free ()'ed in sub_append_string (). */
	      result[result_index] = '\0';
	      break;
	    }
	}
      else
	{
	  while (3 + result_index > result_size)
	    result = (char *)xrealloc (result, result_size += PROMPT_GROWTH);

	  result[result_index++] = c;
	  result[result_index] = '\0';
	}
    }

  /* I don't really think that this is a good idea.  Do you? */
  if (!find_variable ("NO_PROMPT_VARS"))
    {
      WORD_LIST *expand_string (), *list;
      char *string_list ();

      list = expand_string (result, 1);
      free (result);
      result = string_list (list);
      dispose_words (list);
    }

  return (result);
}

/* Report a syntax error, and restart the parser.  Call here for fatal
   errors. */
yyerror ()
{
  report_syntax_error ((char *)NULL);
  reset_parser ();
}

/* Report a syntax error with line numbers, etc.
   Call here for recoverable errors.  If you have a message to print,
   then place it in MESSAGE, otherwise pass NULL and this will figure
   out an appropriate message for you. */
report_syntax_error (message)
     char *message;
{
  if (message)
    {
      if (!interactive)
	{
	  char *name = stream_name ? stream_name : "stdin";
	  report_error ("%s:%d: `%s'", name, line_number, message);
	}
      else
	report_error ("%s", message);

      return;
    }

  if (shell_input_line && *shell_input_line)
    {
      char *error_token, *t = shell_input_line;
      register int i = shell_input_line_index;
      int token_end = 0;

      if (!t[i] && i)
	i--;

      while (i && t[i] == ' ' || t[i] == '\t' || t[i] == '\n')
	i--;

      if (i)
	token_end = i + 1;

      while (i && !member (t[i], " \n\t;|&"))
	i--;

      while (i != token_end && member (t[i], " \n\t"))
	i++;

      if (token_end)
	{
	  error_token = (char *)alloca (1 + (token_end - i));
	  strncpy (error_token, t + i, token_end - i);
	  error_token[token_end - i] = '\0';

	  report_error ("syntax error near `%s'", error_token);
	}
      else if ((i == 0) && (token_end == 0))    /* a 1-character token */
	{
	  error_token = (char *) alloca (2);
	  strncpy(error_token, t + i, 1);
	  error_token[1] = '\0';

	  report_error ("syntax error near `%s'", error_token);
	}

      if (!interactive)
	{
	  char *temp = savestring (shell_input_line);
	  char *name = stream_name ? stream_name : "stdin";
	  int l = strlen (temp);

	  while (l && temp[l - 1] == '\n')
	    temp[--l] = '\0';

	  report_error ("%s:%d: `%s'", name, line_number, temp);
	  free (temp);
	}
    }
  else
    report_error ("Syntax error");
}

/* ??? Needed function. ??? We have to be able to discard the constructs
   created during parsing.  In the case of error, we want to return
   allocated objects to the memory pool.  In the case of no error, we want
   to throw away the information about where the allocated objects live.
   (dispose_command () will actually free the command. */
discard_parser_constructs (error_p)
     int error_p;
{
/*   if (error_p) {
     fprintf (stderr, "*");
  } */
}
   
/* Do that silly `type "bye" to exit' stuff.  You know, "ignoreeof". */

/* The number of times that we have encountered an EOF character without
   another character intervening.  When this gets above the limit, the
   shell terminates. */
int eof_encountered = 0;

/* The limit for eof_encountered. */
int eof_encountered_limit = 10;

/* If we have EOF as the only input unit, this user wants to leave
   the shell.  If the shell is not interactive, then just leave.
   Otherwise, if ignoreeof is set, and we haven't done this the
   required number of times in a row, print a message. */
handle_eof_input_unit ()
{
  extern int login_shell, EOF_Reached;

  if (interactive)
    {
      /* If the user wants to "ignore" eof, then let her do so, kind of. */
      if (find_variable ("ignoreeof") || find_variable ("IGNOREEOF"))
	{
	  if (eof_encountered < eof_encountered_limit)
	    {
	      fprintf (stderr, "Use \"%s\" to leave the shell.\n",
		       login_shell ? "logout" : "exit");
	      eof_encountered++;
	      return;
	    } 
	}

      /* In this case EOF should exit the shell.  Do it now. */
      reset_parser ();
      exit_builtin ((WORD_LIST *)NULL);
    }
  else
    {
      /* We don't write history files, etc., for non-interactive shells. */
      EOF_Reached = 1;
    }
}
