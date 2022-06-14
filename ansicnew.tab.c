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
#line 1 "ansicnew.y"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <list>
using namespace std;


extern int yylex();
void yyerror(const char *);
extern FILE *yyin;

#include "symfuncs.h"
#include "genlibnew.h"



enum OP_TYPES{
		PLUS_OP = 1,
		ADDR_OP,
		MINUS_OP,
		DEREF_OP,
		TWOCOMP_OP,
		NOT_OP
};

enum ASSIGN_TYPES{
	EQ_ASSIGN_OP = 1,
	MUL_ASSIGN_OP,
	DIV_ASSIGN_OP,
	MOD_ASSIGN_OP,
	ADD_ASSIGN_OP,
	SUB_ASSIGN_OP,
	LEFT_ASSIGN_OP,
	RIGHT_ASSIGN_OP,
	AND_ASSIGN_OP,
	XOR_ASSIGN_OP,
	OR_ASSIGN_OP,
};


#line 116 "ansicnew.tab.c"

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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IDENTIFIER = 258,
    CONSTANT = 259,
    STRING_LITERAL = 260,
    SIZEOF = 261,
    PTR_OP = 262,
    INC_OP = 263,
    DEC_OP = 264,
    LEFT_OP = 265,
    RIGHT_OP = 266,
    LE_OP = 267,
    GE_OP = 268,
    EQ_OP = 269,
    NE_OP = 270,
    AND_OP = 271,
    OR_OP = 272,
    MUL_ASSIGN = 273,
    DIV_ASSIGN = 274,
    MOD_ASSIGN = 275,
    ADD_ASSIGN = 276,
    SUB_ASSIGN = 277,
    LEFT_ASSIGN = 278,
    RIGHT_ASSIGN = 279,
    AND_ASSIGN = 280,
    XOR_ASSIGN = 281,
    OR_ASSIGN = 282,
    TYPE_NAME = 283,
    TYPEDEF = 284,
    EXTERN = 285,
    STATIC = 286,
    AUTO = 287,
    REGISTER = 288,
    CHAR = 289,
    SHORT = 290,
    INT = 291,
    LONG = 292,
    SIGNED = 293,
    UNSIGNED = 294,
    FLOAT = 295,
    DOUBLE = 296,
    CONST = 297,
    VOLATILE = 298,
    VOID = 299,
    STRUCT = 300,
    UNION = 301,
    ENUM = 302,
    ELLIPSIS = 303,
    CASE = 304,
    DEFAULT = 305,
    IF = 306,
    ELSE = 307,
    SWITCH = 308,
    WHILE = 309,
    DO = 310,
    FOR = 311,
    GOTO = 312,
    CONTINUE = 313,
    BREAK = 314,
    RETURN = 315,
    NOELSE = 316
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 47 "ansicnew.y"

	struct{
		union{
			int ival;
			double dval;
			char *name;
			char *sval;
			char cval;
		};
		int valtype;
	};
	VAR_DATA *id_data;
	std::list<VAR_DATA *> *idlist;
	int scsp;
	std::list<int> *sqlist;
	int typsp;
	int qual;
	VAR_DATA sym;
	struct{
		int typq;
		int level;
	} pstruc;
	std::list<int> *splist;
	int op;
	int typ;
	int assop;
	int instr;
	struct {
		std::list<int> *breaklist;
		std::list<int> *nextlist;
		std::list<int> *continuelist;
		std::list<GOTO_DATA *> *gotolist;
		std::list<CASE_DATA *> *caselist;
	} lists;

#line 266 "ansicnew.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1289

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  221
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  378

#define YYUNDEFTOK  2
#define YYMAXUTOK   316


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
       2,     2,     2,    73,     2,     2,     2,    75,    68,     2,
      62,    63,    69,    70,    67,    71,    66,    74,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    81,    83,
      76,    82,    77,    80,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,    78,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    84,    79,    85,    72,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   162,   162,   176,   209,   223,   227,   228,   264,   272,
     287,   288,   289,   303,   320,   329,   338,   339,   349,   359,
     407,   416,   428,   429,   430,   431,   432,   433,   437,   448,
     458,   459,   480,   501,   525,   526,   547,   571,   572,   593,
     617,   618,   635,   652,   669,   689,   690,   707,   726,   727,
     751,   752,   776,   777,   800,   806,   812,   813,   823,   824,
     834,   835,   835,   854,   855,   932,   933,   934,   935,   936,
     937,   938,   939,   940,   941,   942,   946,   947,   951,   955,
     956,   985,   990,   994,   999,  1003,  1008,  1015,  1021,  1028,
    1031,  1039,  1040,  1041,  1042,  1043,  1047,  1048,  1049,  1050,
    1051,  1052,  1053,  1054,  1055,  1056,  1057,  1058,  1062,  1063,
    1064,  1068,  1069,  1073,  1074,  1078,  1082,  1086,  1091,  1095,
    1103,  1104,  1108,  1109,  1110,  1114,  1115,  1116,  1120,  1121,
    1125,  1126,  1130,  1131,  1135,  1141,  1159,  1168,  1171,  1183,
    1191,  1198,  1201,  1210,  1214,  1218,  1222,  1230,  1235,  1243,
    1246,  1250,  1257,  1266,  1273,  1274,  1278,  1281,  1285,  1288,
    1292,  1293,  1294,  1298,  1299,  1300,  1301,  1302,  1303,  1304,
    1305,  1306,  1310,  1311,  1312,  1316,  1317,  1320,  1324,  1329,
    1329,  1337,  1345,  1350,  1355,  1363,  1372,  1383,  1393,  1400,
    1404,  1411,  1418,  1419,  1423,  1427,  1440,  1445,  1451,  1466,
    1482,  1489,  1497,  1534,  1546,  1557,  1569,  1584,  1593,  1602,
    1611,  1620,  1631,  1632,  1636,  1637,  1641,  1642,  1642,  1661,
    1662,  1662
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "NOELSE", "'('", "')'", "'['", "']'",
  "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'",
  "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'",
  "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "M", "N", "logical_and_expression", "logical_or_expression",
  "conditional_expression", "$@1", "assignment_expression",
  "assignment_operator", "expression", "constant_expression",
  "declaration", "declaration_specifiers", "init_declarator_list",
  "init_declarator", "storage_class_specifier", "type_specifier",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "P", "statement", "$@2", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "logic_expression", "logic_expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition", "$@3",
  "$@4", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    40,    41,    91,    93,    46,    44,    38,    42,
      43,    45,   126,    33,    47,    37,    60,    62,    94,   124,
      63,    58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF (-301)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-218)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     913,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,    14,    11,   117,  -301,    31,  1242,  1242,  -301,    22,
    -301,  1242,  1242,   108,    23,   823,  -301,  -301,   -62,    32,
     -13,  -301,  -301,   117,  -301,    52,  -301,  1066,  -301,  -301,
     -23,  1040,  -301,  -301,    31,  1086,    -8,   958,   607,   108,
    -301,  -301,    32,    75,   -25,  -301,  -301,  -301,  -301,    11,
    -301,   465,  1086,    -8,  1040,  1040,   988,  -301,    53,  1040,
      80,   321,  -301,  -301,  -301,  -301,  -301,    15,   112,   121,
    -301,   -34,  -301,  -301,  -301,   728,   749,   749,   586,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,   226,  -301,   773,
    -301,   126,    56,   155,    40,   189,   144,   116,   118,   203,
       6,  -301,   158,   -22,   773,    32,  -301,  -301,   465,   317,
    -301,  -301,  -301,  -301,  -301,  1008,  -301,  -301,  -301,   773,
      88,  -301,   149,  -301,   151,   773,   159,   174,  -301,  -301,
    -301,   187,   248,   177,   179,   513,  -301,  -301,  -301,    96,
    -301,  -301,  -301,   392,   172,  -301,  -301,  -301,  -301,   868,
     631,  -301,    61,  -301,   123,  -301,  1221,  -301,   260,   586,
    -301,   773,  -301,  -301,   -19,   129,   201,   263,  -301,  -301,
     657,   773,   265,  -301,   773,   773,   773,   773,   773,   773,
     773,   773,   773,   773,   773,   773,   773,   773,   773,   773,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,    -2,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
     773,  -301,  -301,    53,  -301,   773,  -301,   188,  -301,   773,
     213,   215,   497,   536,   195,  -301,  -301,  -301,   100,   773,
    -301,    -8,  -301,   194,  -301,   497,  -301,   218,   219,  -301,
     220,   123,  1185,   678,  -301,  -301,  -301,   221,  -301,  1143,
     145,  -301,   773,  -301,  -301,    38,  -301,   146,  -301,  -301,
    -301,  -301,   126,   126,    56,    56,   155,   155,   155,   155,
      40,    40,   189,   144,   116,   773,   773,   773,   410,  -301,
    -301,  -301,  -301,   497,  -301,   497,   222,   223,   773,   773,
     237,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,   230,  -301,   232,  -301,  -301,  -301,   773,  -301,
     118,   203,   -26,  -301,  -301,  -301,   497,  -301,  -301,    57,
     235,  -301,   536,  -301,  -301,  -301,  -301,  -301,   497,   497,
    -301,   238,  -301,  -301,  -301,   247,  -301,   497,   773,   702,
    -301,  -301,  -301,   240,   497,    66,   773,  -301,   224,  -301,
    -301,  -301,   497,  -301,  -301,  -301,   497,  -301
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   136,   107,    91,    92,    93,    94,    95,    97,    98,
      99,   100,   103,   104,   101,   102,   132,   133,    96,   111,
     112,     0,     0,   143,   215,     0,    81,    83,   105,     0,
     106,    85,   220,   135,     0,     0,   212,   214,   127,     0,
       0,   147,   145,   144,    79,     0,    87,    89,    82,    84,
     110,     0,    86,   192,     0,     0,     0,     0,     0,   134,
       1,   213,     0,   130,     0,   128,   137,   148,   146,     0,
      80,     0,     0,     0,     0,   117,     0,   113,     0,   119,
      89,   177,   193,   219,   221,   156,   142,   155,     0,   149,
     151,     0,     2,     3,     4,     0,     0,     0,     0,   139,
      22,    23,    24,    25,    26,    27,     6,    16,    28,     0,
      30,    34,    37,    40,    45,    48,    50,    52,    56,    58,
      60,    78,     0,     0,     0,     0,   125,    88,     0,    28,
      63,   172,    90,   216,   218,     0,   116,   109,   114,     0,
       0,   120,   122,   118,     2,     0,     0,     0,    54,    55,
      55,     0,     0,     0,     0,     0,   196,   188,    76,     0,
     179,   194,   178,   177,    55,   181,   182,   183,   184,     0,
       0,   153,   160,   154,   161,   140,     0,   141,     0,     0,
      20,     0,    17,    18,     0,   158,     0,     0,    12,    13,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    55,    55,   138,   126,   131,   129,   175,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    65,
       0,   108,   123,     0,   115,     0,    55,     0,    55,     0,
       0,     0,   177,     0,     0,   208,   209,   210,     0,     0,
     197,     0,   190,    55,   189,   177,   168,     0,     0,   164,
       0,   162,     0,     0,   150,   152,   157,     0,     5,     0,
     160,   159,     0,    11,     8,     0,    14,     0,    10,    31,
      32,    33,    35,    36,    38,    39,    43,    44,    41,    42,
      46,    47,    49,    51,    53,     0,     0,     0,     0,   173,
      64,   121,   124,   177,    55,   177,   198,     0,     0,     0,
       0,    55,   207,   211,    77,   180,   191,   195,   169,   163,
     165,   170,     0,   166,     0,    21,    29,     9,     0,     7,
      57,    59,     0,   174,   176,   185,   177,   187,    55,     0,
       0,    55,     0,   171,   167,    15,    61,   186,   177,   177,
      55,     0,   199,    55,    54,   200,   202,   177,     0,     0,
      55,    54,   203,     0,   177,     0,     0,    55,     0,   205,
      54,    62,   177,   204,    55,   201,   177,   206
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -301,  -301,  -301,  -301,   -58,  -301,   -99,    47,    48,    24,
      50,    94,    97,   101,    17,  -252,   -80,    10,  -301,   -57,
    -301,   -69,  -301,   -87,   -67,    19,     5,  -301,   244,  -301,
     167,  -301,  -301,   241,   -46,   -51,  -301,    81,  -301,   254,
     192,   141,    21,   -18,   -16,  -301,   -54,  -301,   142,  -301,
     143,   -75,  -159,  -122,  -301,  -301,   -53,  -301,  -301,   -52,
     -32,   165,  -235,  -300,  -301,  -301,  -301,  -301,  -301,   286,
    -301,  -301,  -301
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   106,   107,   275,   129,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   240,   255,   119,   120,   130,
     354,   158,   230,   159,   122,    53,    54,    45,    46,    26,
      27,    28,    29,    76,    77,    78,   140,   141,    30,    64,
      65,    31,    32,    33,    34,    43,   257,    89,    90,    91,
     186,   258,   174,   132,   218,   160,   161,   251,   162,    83,
      55,   164,   165,   307,   353,   166,   167,   168,    35,    36,
      37,    73,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,   121,   131,    88,    84,    25,   217,    42,   311,   340,
     193,   184,   173,   261,     1,    72,    59,    38,     1,    24,
     133,   134,    62,   211,   136,    50,     1,    68,   143,   177,
     138,    48,    49,   178,     1,    63,    52,   180,   182,   183,
      25,   249,   125,    40,   268,   125,    47,   185,   249,   163,
      66,   108,   201,   202,    24,   346,     1,   215,   363,   131,
     126,    74,    87,   214,     1,   298,   108,   121,   248,   241,
     242,   172,   232,    22,    82,    80,    81,   169,   237,   170,
      23,   108,   121,   299,    23,    22,   212,   108,   121,   138,
      80,    82,   184,    22,   184,   279,   280,   281,    39,   142,
      23,   327,   360,   260,   277,   328,    51,   352,   171,   367,
     271,   261,   108,   121,    44,    22,   203,   204,   374,    69,
     349,   276,    23,   169,   249,   170,   197,   198,   185,   370,
     295,   296,   297,   249,   139,    70,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   306,   172,    59,   233,   303,   124,   305,    16,
      17,   300,    71,   249,    41,   199,   200,   249,   302,   270,
      57,   234,    58,   326,    87,   175,   334,   108,   121,   250,
     314,    87,    82,   313,    67,   262,    23,   263,   176,   310,
      40,   269,    79,   170,   208,   194,   324,   209,    23,   315,
     195,   196,   317,   205,   206,   108,   121,   269,   322,   170,
     332,   329,   207,   249,   108,    79,    79,    79,    75,   210,
      79,   339,   306,   213,   336,   286,   287,   288,   289,   131,
     235,   342,   236,   187,   188,   189,   239,   108,   108,    79,
     238,    75,    75,    75,   282,   283,    75,   284,   285,   243,
     335,   244,   337,   270,   142,   290,   291,   254,   348,   345,
     245,   351,   246,   266,   272,    75,   273,    87,   278,   304,
     357,   306,   365,   359,    87,   308,    79,   309,   312,   316,
     366,   318,   319,   347,   325,   320,   338,   372,   190,   249,
     191,   341,   192,   343,   376,   355,   356,   344,   350,   361,
     358,   292,    75,   368,   362,   293,   331,   373,   108,   371,
     294,   369,   330,   127,   301,   135,   123,   216,   265,   375,
      79,    61,   267,   377,   144,    93,    94,    95,   253,    96,
      97,     0,     0,     0,     0,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,     0,    75,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
     145,   146,   147,     0,   148,   149,   150,   151,   152,   153,
     154,   155,     0,    98,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   144,    93,    94,    95,   229,
      96,    97,     0,     0,   156,     0,   157,     0,     0,     0,
       0,     0,     0,    92,    93,    94,    95,     0,    96,    97,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,   145,   146,   147,     0,   148,   149,   150,   151,   152,
     153,   154,   155,     0,    98,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,     0,     0,    92,    93,
      94,    95,    98,    96,    97,   156,     0,   252,   100,   101,
     102,   103,   104,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,   333,     0,     0,     0,     0,
     144,    93,    94,    95,     0,    96,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,    93,    94,    95,
       0,    96,    97,     0,     0,     0,     0,    98,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,    92,
      93,    94,    95,     0,    96,    97,   145,   146,   147,   128,
     148,   149,   150,   151,   152,   153,   154,   155,     0,    98,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,     0,     0,     0,     0,    98,     0,     0,     0,     0,
     156,   100,   101,   102,   103,   104,   105,     0,     0,    92,
      93,    94,    95,     0,    96,    97,   247,     0,    98,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
      92,    93,    94,    95,     2,    96,    97,     0,     0,   156,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    92,    93,    94,    95,     0,    96,
      97,     0,     0,     0,     0,     0,     0,     0,    98,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
      92,    93,    94,    95,     0,    96,    97,     0,     0,    98,
       0,     0,    99,     0,     0,   100,   101,   102,   103,   104,
     105,    92,    93,    94,    95,     0,    96,    97,     0,     0,
       0,     0,     0,    98,     0,     0,   259,     0,     0,   100,
     101,   102,   103,   104,   105,    92,    93,    94,    95,     0,
      96,    97,     0,     0,     0,     0,     0,     0,     0,    98,
     274,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,    92,    93,    94,    95,     0,    96,    97,     0,     0,
      98,     0,     0,   323,     0,     0,   100,   101,   102,   103,
     104,   105,    92,    93,    94,    95,     0,    96,    97,     0,
       0,     0,     0,     0,    98,   364,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,    92,    93,    94,    95,
       0,    96,    97,     0,     0,     0,     0,     0,     0,     0,
     179,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,    60,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,    98,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     169,   256,   170,     0,     0,     0,     0,    23,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,    86,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     2,     0,     0,     0,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,   137,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,     0,
       0,     0,     0,   231,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    71,     0,
    -217,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   269,   256,   170,     0,     0,
       0,     0,    23,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   321,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   264,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
      58,    58,    71,    57,    56,     0,   128,    23,   243,   309,
     109,    98,    87,   172,     3,    47,    34,     3,     3,     0,
      72,    73,    84,    17,    75,     3,     3,    43,    79,    63,
      76,    26,    27,    67,     3,     3,    31,    95,    96,    97,
      35,    67,    67,    22,    63,    67,    25,    98,    67,    81,
      63,   109,    12,    13,    35,    81,     3,   124,   358,   128,
      85,    84,    57,    85,     3,    67,   124,   124,   155,   149,
     150,    87,   139,    62,    55,    54,    84,    62,   145,    64,
      69,   139,   139,    85,    69,    62,    80,   145,   145,   135,
      69,    72,   179,    62,   181,   194,   195,   196,    84,    78,
      69,    63,   354,   170,   191,    67,    84,   342,    87,   361,
     185,   270,   170,   170,    83,    62,    76,    77,   370,    67,
      63,   190,    69,    62,    67,    64,    70,    71,   179,    63,
     210,   211,   212,    67,    81,    83,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   239,   169,   172,    67,   236,    82,   238,    42,
      43,   230,    82,    67,    23,    10,    11,    67,   235,   185,
      62,    83,    64,   272,   169,    63,   298,   235,   235,    83,
     249,   176,   163,    83,    43,    62,    69,    64,    67,   242,
     169,    62,    51,    64,    78,    69,   263,    79,    69,   251,
      74,    75,   255,    14,    15,   263,   263,    62,   262,    64,
     297,    65,    68,    67,   272,    74,    75,    76,    51,    16,
      79,   308,   309,    65,   304,   201,   202,   203,   204,   298,
      81,   311,    81,     7,     8,     9,    62,   295,   296,    98,
      81,    74,    75,    76,   197,   198,    79,   199,   200,    62,
     303,     3,   305,   269,   233,   205,   206,    85,   338,   328,
      83,   341,    83,     3,    63,    98,     3,   262,     3,    81,
     350,   358,   359,   353,   269,    62,   135,    62,    83,    85,
     360,    63,    63,   336,    63,    65,    63,   367,    62,    67,
      64,    54,    66,    63,   374,   348,   349,    65,    63,    52,
      62,   207,   135,    63,   357,   208,   296,    83,   366,   366,
     209,   364,   295,    69,   233,    74,    62,   125,   176,   372,
     179,    35,   179,   376,     3,     4,     5,     6,   163,     8,
       9,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,   179,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    50,    51,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,     3,     4,     5,     6,    82,
       8,     9,    -1,    -1,    83,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,    -1,    -1,     3,     4,
       5,     6,    62,     8,     9,    83,    -1,    85,    68,    69,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    73,     3,
       4,     5,     6,    -1,     8,     9,    49,    50,    51,    84,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      83,    68,    69,    70,    71,    72,    73,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    83,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    73,
       3,     4,     5,     6,    28,     8,     9,    -1,    -1,    83,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    73,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    62,
      -1,    -1,    65,    -1,    -1,    68,    69,    70,    71,    72,
      73,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    65,    -1,    -1,    68,
      69,    70,    71,    72,    73,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      73,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      62,    -1,    -1,    65,    -1,    -1,    68,    69,    70,    71,
      72,    73,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    73,     0,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    63,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    28,    -1,    -1,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    85,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    85,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,    -1,
      -1,    -1,    69,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    62,    69,   111,   112,   115,   116,   117,   118,
     124,   127,   128,   129,   130,   154,   155,   156,     3,    84,
     128,   127,   130,   131,    83,   113,   114,   128,   112,   112,
       3,    84,   112,   111,   112,   146,   158,    62,    64,   129,
       0,   155,    84,     3,   125,   126,    63,   127,   130,    67,
      83,    82,   146,   157,    84,   116,   119,   120,   121,   127,
     128,    84,   111,   145,   145,     3,    63,   112,   132,   133,
     134,   135,     3,     4,     5,     6,     8,     9,    62,    65,
      68,    69,    70,    71,    72,    73,    87,    88,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   103,
     104,   105,   110,   125,    82,    67,    85,   114,    84,    90,
     105,   107,   139,   145,   145,   119,   121,    85,   120,    81,
     122,   123,   128,   121,     3,    49,    50,    51,    53,    54,
      55,    56,    57,    58,    59,    60,    83,    85,   107,   109,
     141,   142,   144,   146,   147,   148,   151,   152,   153,    62,
      64,   128,   130,   137,   138,    63,    67,    63,    67,    62,
      90,    62,    90,    90,   109,   121,   136,     7,     8,     9,
      62,    64,    66,    92,    69,    74,    75,    70,    71,    10,
      11,    12,    13,    76,    77,    14,    15,    68,    78,    79,
      16,    17,    80,    65,    85,   110,   126,   139,   140,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    82,
     108,    85,   110,    67,    83,    81,    81,   110,    81,    62,
     101,   102,   102,    62,     3,    83,    83,    83,   109,    67,
      83,   143,    85,   147,    85,   102,    63,   132,   137,    65,
     110,   138,    62,    64,    48,   134,     3,   136,    63,    62,
     130,   137,    63,     3,    63,    89,   107,   109,     3,    92,
      92,    92,    93,    93,    94,    94,    95,    95,    95,    95,
      96,    96,    97,    98,    99,   102,   102,   102,    67,    85,
     107,   123,   110,   102,    81,   102,   109,   149,    62,    62,
     142,   148,    83,    83,   107,   145,    85,   142,    63,    63,
      65,    63,   132,    65,   110,    63,    92,    63,    67,    65,
     100,   103,   109,    85,   139,   142,   102,   142,    63,   109,
     149,    54,   102,    63,    65,   107,    81,   142,   102,    63,
      63,   102,   148,   150,   106,   142,   142,   102,    62,   102,
     101,    52,   142,   149,    63,   109,   102,   101,    63,   142,
      63,   105,   102,    83,   101,   142,   102,   142
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    91,    91,    91,    92,    92,
      93,    93,    93,    93,    94,    94,    94,    95,    95,    95,
      96,    96,    96,    96,    96,    97,    97,    97,    98,    98,
      99,    99,   100,   100,   101,   102,   103,   103,   104,   104,
     105,   106,   105,   107,   107,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   109,   109,   110,   111,
     111,   112,   112,   112,   112,   112,   112,   113,   113,   114,
     114,   115,   115,   115,   115,   115,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   117,   117,
     117,   118,   118,   119,   119,   120,   121,   121,   121,   121,
     122,   122,   123,   123,   123,   124,   124,   124,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   129,   129,
     129,   129,   129,   130,   130,   130,   130,   131,   131,   132,
     132,   133,   133,   134,   134,   134,   135,   135,   136,   136,
     137,   137,   137,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   139,   139,   139,   140,   140,   141,   142,   143,
     142,   142,   142,   142,   142,   144,   144,   144,   145,   145,
     145,   145,   146,   146,   147,   147,   148,   148,   149,   150,
     151,   151,   151,   152,   152,   152,   152,   153,   153,   153,
     153,   153,   154,   154,   155,   155,   156,   157,   156,   156,
     158,   156
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     0,     0,     1,     4,     1,     4,
       1,     0,     9,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       3,     1,     2,     1,     2,     1,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     4,
       2,     1,     1,     1,     2,     3,     2,     1,     2,     1,
       1,     3,     1,     2,     3,     4,     5,     2,     1,     3,
       1,     3,     1,     1,     2,     1,     1,     3,     4,     3,
       4,     4,     3,     1,     2,     2,     3,     1,     2,     1,
       3,     1,     3,     2,     2,     1,     1,     3,     1,     2,
       1,     1,     2,     3,     2,     3,     3,     4,     2,     3,
       3,     4,     1,     3,     4,     1,     3,     0,     1,     0,
       3,     1,     1,     1,     1,     4,     5,     4,     2,     3,
       3,     4,     1,     2,     1,     3,     1,     2,     1,     1,
       6,    10,     6,     7,     9,     8,    11,     3,     2,     2,
       2,     3,     1,     2,     1,     1,     4,     0,     4,     3,
       0,     3
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
#line 162 "ansicnew.y"
                                        { printf("primary_expression : IDENTIFIER\n");
							  string *name = new string((yyvsp[0].name));
							  symrec *s = getsym(name);
							  if(s == NULL)
							  {
									printf("Variable %s \n", (yyvsp[0].name));
									yyerror("Variable not declared! ");
							  }
							  cout<< "<" << *name << ">\n";
							  (yyval.sym).var = s;
							  (yyval.sym).typ = s->typ;
							  (yyval.sym).dimlist = s->dimlist;
							  (yyval.sym).plevel = 0;
							}
#line 1936 "ansicnew.tab.c"
    break;

  case 3:
#line 176 "ansicnew.y"
                                                { printf("primary_expression : CONSTANT\n");
							  symrec *s;
							  std::string *name;
							  switch((yyvsp[0].valtype))
							  {
									case DOUBLEVAL:
									cout << "<(double)" << (yyvsp[0].dval) << ">\n";
									name = newtemp();
									s = putsym(name, DOUBLEVAL | CONST_SPEC);
									(yyval.sym).val.doubleval = (yyvsp[0].dval);
									*(double *)(datablock+s->offset) = (yyvsp[0].dval);
									(yyval.sym).typ = s->typ;
									(yyval.sym).var = s;
									break;
									case INTVAL:
									cout<< "<(int)" << (yyvsp[0].ival) << ">\n";
									name = newtemp();
									s = putsym(name, INTVAL |CONST_SPEC);
									(yyval.sym).val.intval = (yyvsp[0].ival);
									*(int *)(datablock+s->offset) = (yyvsp[0].ival);
									(yyval.sym).typ = s->typ;
									(yyval.sym).var = s;
									break;
									case CHARVAL:
									cout<<"<(char)" << (yyvsp[0].cval) <<">\n";
									s = putsym(name, CHARVAL | CONST_SPEC);
									(yyval.sym).val.charval = (yyvsp[0].cval);
									*(char *)(datablock+s->offset) = (yyvsp[0].cval);
									(yyval.sym).typ = s->typ;
									(yyval.sym).var = s;
									break;
							  }
							}
#line 1974 "ansicnew.tab.c"
    break;

  case 4:
#line 209 "ansicnew.y"
                                        { printf("primary_expression : STRING_LITERAL\n");
							  symrec *s;
							  std::string *name;
							  string *str = new string((yyvsp[0].sval));
							  cout << "<\"" << *str << "\">\n";
							  name = newtemp();
							  s = putsym(name, STRVAL | CONST_SPEC);
							  s->size = strlen((yyvsp[0].sval))+1;
							  memcpy(datablock+s->offset, (yyvsp[0].sval), s->size);
							  data_location(s->size);
							  (yyval.sym).name = name;
							  (yyval.sym).typ = s->typ;
							  (yyval.sym).var = s;
							}
#line 1993 "ansicnew.tab.c"
    break;

  case 5:
#line 223 "ansicnew.y"
                                {printf("primary_expression : '(' expression ')'\n"); (yyval.sym)=(yyvsp[-1].sym);}
#line 1999 "ansicnew.tab.c"
    break;

  case 6:
#line 227 "ansicnew.y"
                                        { printf("postfix_expression : primary_expression\n"); (yyval.sym) =(yyvsp[0].sym); }
#line 2005 "ansicnew.tab.c"
    break;

  case 7:
#line 228 "ansicnew.y"
                                                        { printf("postfix_expression : postfix_expression '[' expression ']'\n"); 
												  (yyval.sym) = (yyvsp[-3].sym);
												  if((yyvsp[-3].sym).var == NULL)
												  	yyerror("Error: Array name must be specified");
												  if(!isintegral((yyvsp[-1].sym).typ))
												  	yyerror("Array subscript must be integral!\n");
												  if((yyvsp[-3].sym).plevel>0){
													string *name = newtemp();
													symrec *s0 = putsym(name, INTVAL | CONST_SPEC);
													*(int *)(datablock+s0->offset) = getsizeof((yyval.sym).typ);
													name = newtemp();
													symrec *s1 = putsym(name, INTVAL | CONST_SPEC);
													*(int *)(datablock+s1->offset) = getrdim((yyval.sym).dimlist,(yyvsp[-3].sym).plevel-1);
													name = newtemp();
													symrec *s2 = putsym(name, INTVAL | VAR_SPEC);
													gencode(MULT_IR, (yyvsp[-1].sym).var, s0, s2);
													name = newtemp();
													symrec *s3 = putsym(name, INTVAL | VAR_SPEC);
													gencode(MULT_IR, (yyval.sym).var2, s1,s3);
													name = newtemp();
													symrec *s4 = putsym(name, INTVAL | VAR_SPEC);
													gencode(MULT_IR, s3, s2,s4);
													(yyval.sym).var2 = s4;
												  }
												  else{
													string *name = newtemp();
													symrec *s1 = putsym(name, INTVAL | VAR_SPEC);
													*(int *)(datablock+s1->offset) = getsizeof((yyval.sym).typ);
													name = newtemp();
													symrec *s2 = putsym(name, INTVAL | VAR_SPEC);
													gencode(MULT_IR, (yyvsp[-1].sym).var, s1,s2);
													(yyval.sym).var2 = s2;
												  }
												  (yyval.sym).typ |= ARRAY_SPEC;
												  (yyval.sym).plevel++;
												}
#line 2046 "ansicnew.tab.c"
    break;

  case 8:
#line 264 "ansicnew.y"
                                                { printf("postfix_expression : postfix_expression '(' ')'\n"); 
										  symrec *s;
										  std::string *name = newtemp();
										  s = putsym(name, (yyvsp[-2].sym).typ & 0x1F);
										  (yyval.sym).typ = s->typ;
										  gencode(CALL_IR, (yyvsp[-2].sym).var, nullptr, s);
										  (yyval.sym).var = s;
										}
#line 2059 "ansicnew.tab.c"
    break;

  case 9:
#line 272 "ansicnew.y"
                                                                        { printf("postfix_expression : postfix_expression '(' argument_expression_list ')'\n"); 
																  symrec *s, *s2, *s3;
																  std::list<VAR_DATA *>::reverse_iterator it;
																  std::string *name = newtemp();
																  s = putsym(name, (yyvsp[-3].sym).typ & 0x1F);
																  (yyval.sym).typ = s->typ;
																  for(it = (yyvsp[-1].sym).arglist->rbegin(); it != (yyvsp[-1].sym).arglist->rend(); it++){
																	gencode(PARAM_IR, (*it)->var, nullptr, nullptr);
																  }
																  s3 = new symrec();
																  s3->name = "";
																  s3->offset = (yyvsp[-1].sym).arglist->size();
																  gencode(CALL_IR, (yyvsp[-3].sym).var, s3, s);
																  (yyval.sym).var = s;
																}
#line 2079 "ansicnew.tab.c"
    break;

  case 10:
#line 287 "ansicnew.y"
                                                        { printf("postfix_expression : postfix_expression '.' IDENTIFIER\n"); }
#line 2085 "ansicnew.tab.c"
    break;

  case 11:
#line 288 "ansicnew.y"
                                                        { printf("postfix_expression : postfix_expression PTR_OP IDENTIFIER\n"); }
#line 2091 "ansicnew.tab.c"
    break;

  case 12:
#line 289 "ansicnew.y"
                                                { printf("postfix_expression : postfix_expression INC_OP\n"); 
									  if((yyvsp[-1].sym).typ & VAR_SPEC){
									  std::string *name = newtemp();
									  symrec *s;
									  s = putsym(name, (yyvsp[-1].sym).typ);
									  gencode(STORE_IR, (yyvsp[-1].sym).var, nullptr, s);
									  gencode(INC_IR, (yyvsp[-1].sym).var, nullptr, (yyvsp[-1].sym).var);
									  (yyval.sym).name = name;
									  (yyval.sym).typ = (yyvsp[-1].sym).typ;
									  (yyval.sym).var =s;
									  }
									  else
									  	yyerror("ERROR Operand of decrement operator must be an variable");	
									}
#line 2110 "ansicnew.tab.c"
    break;

  case 13:
#line 303 "ansicnew.y"
                                                { printf("postfix_expression : postfix_expression DEC_OP\n"); 
									  if((yyvsp[-1].sym).typ & VAR_SPEC){
										std::string *name = newtemp();
										symrec *s;
										s = putsym(name, (yyvsp[-1].sym).typ);
										gencode(STORE_IR, (yyvsp[-1].sym).var, nullptr, s);
										gencode(DEC_IR, (yyvsp[-1].sym).var, nullptr, (yyvsp[-1].sym).var);
										(yyval.sym).name = name;
										(yyval.sym).typ = (yyvsp[-1].sym).typ;
										(yyval.sym).var = s;
									  }
									  else
									  	yyerror("ERROR Operand of decrement operator must be an variable");	
									}
#line 2129 "ansicnew.tab.c"
    break;

  case 14:
#line 320 "ansicnew.y"
                                        { printf("argument_expression_list : assignment_expression\n"); 
								  std::list<VAR_DATA *> *newlist = new std::list<VAR_DATA *>();
								  VAR_DATA *newstruc = new VAR_DATA();
								  *newstruc = (yyvsp[0].sym);
								  newlist->push_back(newstruc);
								  (yyval.sym).name = new std::string();
								  (yyval.sym).typ = 0;
								  (yyval.sym).arglist = newlist;
								}
#line 2143 "ansicnew.tab.c"
    break;

  case 15:
#line 329 "ansicnew.y"
                                                                        { printf("argument_expression_list : argument_expression_list ',' assignment_expression\n"); 
																  VAR_DATA *newstruc = new VAR_DATA();
																  *newstruc = (yyvsp[0].sym);
																  (yyval.sym) = (yyvsp[-2].sym);
																  (yyval.sym).arglist->push_back(newstruc);
																}
#line 2154 "ansicnew.tab.c"
    break;

  case 16:
#line 338 "ansicnew.y"
                                        { printf("unary_expression : postfix_expression\n"); (yyval.sym) = (yyvsp[0].sym);}
#line 2160 "ansicnew.tab.c"
    break;

  case 17:
#line 339 "ansicnew.y"
                                                { printf("unary_expression : INC_OP unary_expression\n"); 
									  if((yyvsp[0].sym).typ & VAR_SPEC){
										gencode(INC_IR, (yyvsp[0].sym).var, nullptr, (yyvsp[0].sym).var);
										(yyval.sym).name = (yyvsp[0].sym).name;
										(yyval.sym).typ = (yyvsp[0].sym).typ;
										(yyval.sym).var = (yyvsp[0].sym).var;
									  }
									  else
									  	yyerror("ERROR Operand of increment operator must be a variable name\n");
									}
#line 2175 "ansicnew.tab.c"
    break;

  case 18:
#line 349 "ansicnew.y"
                                                { printf("unary_expression : DEC_OP unary_expression\n"); 
									  if((yyvsp[0].sym).typ & VAR_SPEC){
										gencode(DEC_IR, (yyvsp[0].sym).var, nullptr, (yyvsp[0].sym).var);
										(yyval.sym).name = (yyvsp[0].sym).name;
										(yyval.sym).typ = (yyvsp[0].sym).typ;
										(yyval.sym).var = (yyvsp[0].sym).var;
									  }
									  else
									  	yyerror("ERROR Operand of decrement operator must be a variable name\n");
									}
#line 2190 "ansicnew.tab.c"
    break;

  case 19:
#line 359 "ansicnew.y"
                                                        { printf("unary_expression : unary_operator cast_expression\n"); 
											  std::string *name;
											  symrec *s = nullptr;
											  name = newtemp();
											  switch((yyvsp[-1].op)){
												case PLUS_OP:
													name = (yyvsp[0].sym).name;
													s=(yyvsp[0].sym).var;
													(yyval.sym).typ = (yyvsp[0].sym).typ;
													break;
												case ADDR_OP:
													name= newtemp();
													s = putsym(name, INTVAL);
													gencode(ADDRESS_IR, (yyvsp[0].sym).var, nullptr, s);
													(yyval.sym).typ = INTVAL;
													break;
												case DEREF_OP:
													name = newtemp();
													if(!ispointer((yyvsp[0].sym).typ))
														yyerror("ERROR: OPERAND MUST BE A POINTER\n");
													s = putsym(name, (yyvsp[0].sym).typ & ~POINTER_SPEC);
													gencode(DEREF_IR, (yyvsp[0].sym).var, nullptr, s);
													(yyval.sym).typ = (yyvsp[0].sym).typ;
													break;
												case MINUS_OP:
													name = newtemp();
													s = putsym(name, (yyvsp[0].sym).typ);
													gencode(MINUS_IR, (yyvsp[0].sym).var, nullptr, s);
													(yyval.sym).typ = (yyvsp[0].sym).typ;
													break;
												case TWOCOMP_OP:
													name = newtemp();
													s = putsym(name, INTVAL);
													gencode(TWOCOMP_IR, (yyvsp[0].sym).var, nullptr, s);
													(yyval.sym).typ = INTVAL;
													break;
												case NOT_OP:
													name = newtemp();
													/*s = putsym(name, INTVAL);
													gencode(NOT_IR, $2.var, nullptr, s); */
													(yyval.sym).truelist = (yyvsp[0].sym).falselist;
													(yyval.sym).falselist = (yyvsp[0].sym).truelist;
													(yyval.sym).typ = INTVAL;
													break;
											  }
											  (yyval.sym).name = name;
											  (yyval.sym).var = s;
											}
#line 2243 "ansicnew.tab.c"
    break;

  case 20:
#line 407 "ansicnew.y"
                                                { printf("unary_expression : SIZEOF unary_expression\n"); 
									  std::string *name = newtemp();
									  symrec *s;
									  s = putsym(name, INTVAL | CONST_SPEC);
									  *(int *) (datablock+s->offset) = getsizeof((yyvsp[0].sym).typ);
									  (yyval.sym).name = name;
									  (yyval.sym).typ = INTVAL | CONST_SPEC;
									  (yyval.sym).var = s;
									}
#line 2257 "ansicnew.tab.c"
    break;

  case 21:
#line 416 "ansicnew.y"
                                                { printf("unary_expression : SIZEOF '(' type_name ')'\n"); 
									  std::string *name = newtemp();
									  symrec *s;
									  s = putsym(name, INTVAL | CONST_SPEC);
									  *(int *) (datablock+s->offset) = getsizeof((yyvsp[-1].typ));
									  (yyval.sym).name = name;
									  (yyval.sym).typ = INTVAL | CONST_SPEC;
									  (yyval.sym).var = s;
									}
#line 2271 "ansicnew.tab.c"
    break;

  case 22:
#line 428 "ansicnew.y"
                        { printf("unary_operator : '&'\n");  (yyval.op) = ADDR_OP; }
#line 2277 "ansicnew.tab.c"
    break;

  case 23:
#line 429 "ansicnew.y"
                        { printf("unary_operator : '*'\n"); (yyval.op) = DEREF_OP; }
#line 2283 "ansicnew.tab.c"
    break;

  case 24:
#line 430 "ansicnew.y"
                        { printf("unary_operator : '+'\n"); (yyval.op) = PLUS_OP; }
#line 2289 "ansicnew.tab.c"
    break;

  case 25:
#line 431 "ansicnew.y"
                        { printf("unary_operator : '-'\n"); (yyval.op) = MINUS_OP; }
#line 2295 "ansicnew.tab.c"
    break;

  case 26:
#line 432 "ansicnew.y"
                        { printf("unary_operator : '~'\n"); (yyval.op) = TWOCOMP_OP; }
#line 2301 "ansicnew.tab.c"
    break;

  case 27:
#line 433 "ansicnew.y"
                        { printf("unary_operator : '!'\n"); (yyval.op) = NOT_OP; }
#line 2307 "ansicnew.tab.c"
    break;

  case 28:
#line 437 "ansicnew.y"
                                        { printf("cast_expression : unary_expression\n"); 
							  (yyval.sym) = (yyvsp[0].sym);
							  if(isarray((yyvsp[0].sym).typ)){
								string *name = newtemp();
								symrec *s = putsym(name, (yyvsp[0].sym).typ & ~ARRAY_SPEC);
								gencode(LOADA_IR, (yyvsp[0].sym).var, (yyvsp[0].sym).var2, s);
								(yyval.sym).name = name;
								(yyval.sym).typ = s->typ;
								(yyval.sym).var = s;
							  }
							}
#line 2323 "ansicnew.tab.c"
    break;

  case 29:
#line 448 "ansicnew.y"
                                                        { printf("cast_expression : '(' type_name ')' cast_expression\n"); 
											  int typ = (yyvsp[-2].typ) & 0x1f;
											  symrec *s = genconv(typ, (yyvsp[0].sym).var);
											  (yyval.sym).var = s;
											  (yyval.sym).typ = s->typ;
											  (yyval.sym).name = new string(s->name);
											}
#line 2335 "ansicnew.tab.c"
    break;

  case 30:
#line 458 "ansicnew.y"
                                        { printf("multiplicative_expression : cast_expression\n"); (yyval.sym)=(yyvsp[0].sym);}
#line 2341 "ansicnew.tab.c"
    break;

  case 31:
#line 459 "ansicnew.y"
                                                                { printf("multiplicative_expression : multiplicative_expression '*' cast_expression\n"); 
														  int typ = gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & 0x1f;
														  string *name = newtemp();
														  symrec *s = putsym(name, typ);
														  if(((yyvsp[-2].sym).typ & 0x1f) == ((yyvsp[0].sym).typ & 0x1f))
														  		gencode(MULT_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s );
														  else{
															symrec *s2;
															if(((yyvsp[-2].sym).typ & 0x1f) == typ){
																s2 = genconv(typ, (yyvsp[0].sym).var);
																gencode(MULT_IR, (yyvsp[-2].sym).var, s2, s);
															}
															else{
																s2 = genconv(typ, (yyvsp[-2].sym).var);
																gencode(MULT_IR, s2, (yyvsp[0].sym).var, s);
															}
														  }
														  (yyval.sym).var = s;
														  (yyval.sym).typ = s->typ;
														  (yyval.sym).name = name;
														}
#line 2367 "ansicnew.tab.c"
    break;

  case 32:
#line 480 "ansicnew.y"
                                                                { printf("multiplicative_expression : multiplicative_expression '/' cast_expression\n"); 
														  int typ = gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & 0x1f;
														  string *name = newtemp();
														  symrec *s = putsym(name, typ);
														  if(((yyvsp[-2].sym).typ & 0x1f) == ((yyvsp[0].sym).typ & 0x1f))
														  		gencode(DIV_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s );
														  else{
															symrec *s2;
															if(((yyvsp[-2].sym).typ & 0x1f) == typ){
																s2 = genconv(typ, (yyvsp[0].sym).var);
																gencode(DIV_IR, (yyvsp[-2].sym).var, s2, s);
															}
															else{
																s2 = genconv(typ, (yyvsp[-2].sym).var);
																gencode(DIV_IR, s2, (yyvsp[0].sym).var, s);
															}
														  }
														  (yyval.sym).var = s;
														  (yyval.sym).typ = s->typ;
														  (yyval.sym).name = name;
														}
#line 2393 "ansicnew.tab.c"
    break;

  case 33:
#line 501 "ansicnew.y"
                                                                { printf("multiplicative_expression : multiplicative_expression '%%' cast_expression\n"); 
														  int typ = gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & 0x1f;
														  string *name = newtemp();
														  symrec *s = putsym(name, typ);
														  if(((yyvsp[-2].sym).typ & 0x1f) == ((yyvsp[0].sym).typ & 0x1f))
														  		gencode(MOD_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s );
														  else{
															symrec *s2;
															if(((yyvsp[-2].sym).typ & 0x1f) == typ){
																s2 = genconv(typ, (yyvsp[0].sym).var);
																gencode(MOD_IR, (yyvsp[-2].sym).var, s2, s);
															}
															else{
																s2 = genconv(typ, (yyvsp[-2].sym).var);
																gencode(MOD_IR, s2, (yyvsp[0].sym).var, s);
															}
														  }
														  (yyval.sym).var = s;
														  (yyval.sym).typ = s->typ;
														  (yyval.sym).name = name;
														}
#line 2419 "ansicnew.tab.c"
    break;

  case 34:
#line 525 "ansicnew.y"
                                                { printf("additive_expression : multiplicative_expression\n"); (yyval.sym)=(yyvsp[0].sym);}
#line 2425 "ansicnew.tab.c"
    break;

  case 35:
#line 526 "ansicnew.y"
                                                                        { printf("additive_expression : additive_expression '+' multiplicative_expression\n"); 
															  int typ = gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & 0x1f;
															  string *name = newtemp();
															  symrec *s = putsym(name, typ);
															  if(((yyvsp[-2].sym).typ & 0x1f) == ((yyvsp[0].sym).typ & 0x1f))
																	gencode(ADD_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s );
															  else{
															  	symrec *s2;
																if(((yyvsp[-2].sym).typ & 0x1f) == typ){
																	s2 = genconv(typ, (yyvsp[0].sym).var);
																	gencode(ADD_IR, (yyvsp[-2].sym).var, s2, s);
																}
																else{
																	s2 = genconv(typ, (yyvsp[-2].sym).var);
																	gencode(ADD_IR, s2, (yyvsp[0].sym).var, s);
																}
															  }
															(yyval.sym).var = s;
															(yyval.sym).typ = s->typ;
															(yyval.sym).name = name;
															}
#line 2451 "ansicnew.tab.c"
    break;

  case 36:
#line 547 "ansicnew.y"
                                                                        { printf("additive_expression : additive_expression '-' multiplicative_expression\n"); 
															  int typ = gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & 0x1f;
														  	  string *name = newtemp();
														     symrec *s = putsym(name, typ);
														     if(((yyvsp[-2].sym).typ & 0x1f) == ((yyvsp[0].sym).typ & 0x1f))
														  		gencode(SUB_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s );
														     else{
															 	symrec *s2;
																if(((yyvsp[-2].sym).typ & 0x1f) == typ){
																	s2 = genconv(typ, (yyvsp[0].sym).var);
																		gencode(SUB_IR, (yyvsp[-2].sym).var, s2, s);
																}
															 else{
															 	s2 = genconv(typ, (yyvsp[-2].sym).var);
																gencode(SUB_IR, s2, (yyvsp[0].sym).var, s);
																 }
														 	 }
														  	 (yyval.sym).var = s;
														  	 (yyval.sym).typ = s->typ;
														  	 (yyval.sym).name = name;
															}
#line 2477 "ansicnew.tab.c"
    break;

  case 37:
#line 571 "ansicnew.y"
                                        { printf("shift_expression : additive_expression\n"); (yyval.sym)=(yyvsp[0].sym);}
#line 2483 "ansicnew.tab.c"
    break;

  case 38:
#line 572 "ansicnew.y"
                                                                { printf("shift_expression : shift_expression LEFT_OP additive_expression\n"); 
														  int typ = gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & 0x1f;
														  string *name = newtemp();
														  symrec *s = putsym(name, typ);
														  if(((yyvsp[-2].sym).typ & 0x1f) == ((yyvsp[0].sym).typ & 0x1f))
														  		gencode(LSHIFT_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s );
														  else{
															symrec *s2;
															if(((yyvsp[-2].sym).typ & 0x1f) == typ){
																s2 = genconv(typ, (yyvsp[0].sym).var);
																gencode(LSHIFT_IR, (yyvsp[-2].sym).var, s2, s);
															}
															else{
																s2 = genconv(typ, (yyvsp[-2].sym).var);
																gencode(LSHIFT_IR, s2, (yyvsp[0].sym).var, s);
															}
														  }
														  (yyval.sym).var = s;
														  (yyval.sym).typ = s->typ;
														  (yyval.sym).name = name;
														}
#line 2509 "ansicnew.tab.c"
    break;

  case 39:
#line 593 "ansicnew.y"
                                                                { printf("shift_expression : shift_expression RIGHT_OP additive_expression\n"); 
														  int typ = gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & 0x1f;
														  string *name = newtemp();
														  symrec *s = putsym(name, typ);
														  if(((yyvsp[-2].sym).typ & 0x1f) == ((yyvsp[0].sym).typ & 0x1f))
														  		gencode(RSHIFT_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s );
														  else{
															symrec *s2;
															if(((yyvsp[-2].sym).typ & 0x1f) == typ){
																s2 = genconv(typ, (yyvsp[0].sym).var);
																gencode(RSHIFT_IR, (yyvsp[-2].sym).var, s2, s);
															}
															else{
																s2 = genconv(typ, (yyvsp[-2].sym).var);
																gencode(RSHIFT_IR, s2, (yyvsp[0].sym).var, s);
															}
														  }
														  (yyval.sym).var = s;
														  (yyval.sym).typ = s->typ;
														  (yyval.sym).name = name;
														}
#line 2535 "ansicnew.tab.c"
    break;

  case 40:
#line 617 "ansicnew.y"
                                        { printf("relational_expression : shift_expression\n"); (yyval.sym)=(yyvsp[0].sym); }
#line 2541 "ansicnew.tab.c"
    break;

  case 41:
#line 618 "ansicnew.y"
                                                                { printf("relational_expression : relational_expression '<' shift_expression\n"); 
														  int typ = gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & 0x1f;
														  symrec *s1 = (yyvsp[-2].sym).var, *s2 = (yyvsp[0].sym).var;
														  if(((yyvsp[-2].sym).typ & 0x1f) != ((yyvsp[0].sym).typ & 0x1f)){
															if(((yyvsp[-2].sym).typ & 0x1f) == typ){
																s2 = genconv(typ, (yyvsp[0].sym).var);
															}
															else{
																s1 = genconv(typ, (yyvsp[-2].sym).var);
															}
														  }
															(yyval.sym).truelist = makelist(nextinstr);
															gencode(IF_LT_IR, s1, s2, nullptr);
															(yyval.sym).falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														  
														}
#line 2563 "ansicnew.tab.c"
    break;

  case 42:
#line 635 "ansicnew.y"
                                                                { printf("relational_expression : relational_expression '>' shift_expression\n"); 
														   int typ = gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & 0x1f;
														  symrec *s1 = (yyvsp[-2].sym).var, *s2 = (yyvsp[0].sym).var;
														  if(((yyvsp[-2].sym).typ & 0x1f) != ((yyvsp[0].sym).typ & 0x1f)){
															if(((yyvsp[-2].sym).typ & 0x1f) == typ){
																s2 = genconv(typ, (yyvsp[0].sym).var);
															}
															else{
																s1 = genconv(typ, (yyvsp[-2].sym).var);
															}
														  }
															(yyval.sym).truelist = makelist(nextinstr);
															gencode(IF_GT_IR, s1, s2, nullptr);
															(yyval.sym).falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														  
														}
#line 2585 "ansicnew.tab.c"
    break;

  case 43:
#line 652 "ansicnew.y"
                                                                { printf("relational_expression : relational_expression LE_OP shift_expression\n"); 
														   int typ = gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & 0x1f;
														  symrec *s1 = (yyvsp[-2].sym).var, *s2 = (yyvsp[0].sym).var;
														  if(((yyvsp[-2].sym).typ & 0x1f) != ((yyvsp[0].sym).typ & 0x1f)){
															if(((yyvsp[-2].sym).typ & 0x1f) == typ){
																s2 = genconv(typ, (yyvsp[0].sym).var);
															}
															else{
																s1 = genconv(typ, (yyvsp[-2].sym).var);
															}
														  }
															(yyval.sym).truelist = makelist(nextinstr);
															gencode(IF_LE_IR, s1, s2, nullptr);
															(yyval.sym).falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														  
														}
#line 2607 "ansicnew.tab.c"
    break;

  case 44:
#line 669 "ansicnew.y"
                                                                { printf("relational_expression : relational_expression GE_OP shift_expression\n"); 
														   int typ = gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & 0x1f;
														  symrec *s1 = (yyvsp[-2].sym).var, *s2 = (yyvsp[0].sym).var;
														  if(((yyvsp[-2].sym).typ & 0x1f) != ((yyvsp[0].sym).typ & 0x1f)){
															if(((yyvsp[-2].sym).typ & 0x1f) == typ){
																s2 = genconv(typ, (yyvsp[0].sym).var);
															}
															else{
																s1 = genconv(typ, (yyvsp[-2].sym).var);
															}
														  }
															(yyval.sym).truelist = makelist(nextinstr);
															gencode(IF_GE_IR, s1, s2, nullptr);
															(yyval.sym).falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														  
														}
#line 2629 "ansicnew.tab.c"
    break;

  case 45:
#line 689 "ansicnew.y"
                                        { printf("equality_expression : relational_expression\n"); (yyval.sym) = (yyvsp[0].sym);}
#line 2635 "ansicnew.tab.c"
    break;

  case 46:
#line 690 "ansicnew.y"
                                                                        { printf("equality_expression : equality_expression EQ_OP relational_expression\n"); 
															  int typ = gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & 0x1f;
														  	  symrec *s1 = (yyvsp[-2].sym).var, *s2 = (yyvsp[0].sym).var;
														      if(((yyvsp[-2].sym).typ & 0x1f) != ((yyvsp[0].sym).typ & 0x1f)){
															  	if(((yyvsp[-2].sym).typ & 0x1f) == typ){
																	s2 = genconv(typ, (yyvsp[0].sym).var);
																}
															  else{
															  	s1 = genconv(typ, (yyvsp[-2].sym).var);
															      }
														  	  }
															  (yyval.sym).truelist = makelist(nextinstr);
															  gencode(IF_EQ_IR, s1, s2, nullptr);
															  (yyval.sym).falselist = makelist(nextinstr);
															  gencode(GOTO_IR);
														  
															}
#line 2657 "ansicnew.tab.c"
    break;

  case 47:
#line 707 "ansicnew.y"
                                                                        { printf("equality_expression : equality_expression NE_OP relational_expression\n"); 
														      int typ = gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & 0x1f;
														  	  symrec *s1 = (yyvsp[-2].sym).var, *s2 = (yyvsp[0].sym).var;
														      if(((yyvsp[-2].sym).typ & 0x1f) != ((yyvsp[0].sym).typ & 0x1f)){
															  	if(((yyvsp[-2].sym).typ & 0x1f) == typ){
																	s2 = genconv(typ, (yyvsp[0].sym).var);
																}
															  else{
															  	s1 = genconv(typ, (yyvsp[-2].sym).var);
															      }
														  	  }
															  (yyval.sym).truelist = makelist(nextinstr);
															  gencode(IF_NE_IR, s1, s2, nullptr);
															  (yyval.sym).falselist = makelist(nextinstr);
															  gencode(GOTO_IR);
															}
#line 2678 "ansicnew.tab.c"
    break;

  case 48:
#line 726 "ansicnew.y"
                                        { printf("and_expression : equality_expression\n"); (yyval.sym) = (yyvsp[0].sym); }
#line 2684 "ansicnew.tab.c"
    break;

  case 49:
#line 727 "ansicnew.y"
                                                                { printf("and_expression : and_expression '&' equality_expression\n"); 
														  int typ = gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & 0x1f;
														  string *name = newtemp();
														  symrec *s = putsym(name, typ);
														  if(((yyvsp[-2].sym).typ & 0x1f) == ((yyvsp[0].sym).typ & 0x1f))
														  		gencode(AND_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s );
														  else{
															symrec *s2;
															if(((yyvsp[-2].sym).typ & 0x1f) == typ){
																s2 = genconv(typ, (yyvsp[0].sym).var);
																gencode(AND_IR, (yyvsp[-2].sym).var, s2, s);
															}
															else{
																s2 = genconv(typ, (yyvsp[-2].sym).var);
																gencode(AND_IR, s2, (yyvsp[0].sym).var, s);
															}
														  }
														  (yyval.sym).var = s;
														  (yyval.sym).typ = s->typ;
														  (yyval.sym).name = name;
													}
#line 2710 "ansicnew.tab.c"
    break;

  case 50:
#line 751 "ansicnew.y"
                                        { printf("exclusive_or_expression : and_expression\n"); (yyval.sym) = (yyvsp[0].sym);}
#line 2716 "ansicnew.tab.c"
    break;

  case 51:
#line 752 "ansicnew.y"
                                                                { printf("exclusive_or_expression : exclusive_or_expression '^' and_expression\n"); 
														  int typ = gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & 0x1f;
														  string *name = newtemp();
														  symrec *s = putsym(name, typ);
														  if(((yyvsp[-2].sym).typ & 0x1f) == ((yyvsp[0].sym).typ & 0x1f))
														  		gencode(XOR_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s );
														  else{
															symrec *s2;
															if(((yyvsp[-2].sym).typ & 0x1f) == typ){
																s2 = genconv(typ, (yyvsp[0].sym).var);
																gencode(XOR_IR, (yyvsp[-2].sym).var, s2, s);
															}
															else{
																s2 = genconv(typ, (yyvsp[-2].sym).var);
																gencode(XOR_IR, s2, (yyvsp[0].sym).var, s);
															}
														  }
														  (yyval.sym).var = s;
														  (yyval.sym).typ = s->typ;
														  (yyval.sym).name = name;
														}
#line 2742 "ansicnew.tab.c"
    break;

  case 52:
#line 776 "ansicnew.y"
                                                { printf("inclusive_or_expression : exclusive_or_expression\n"); (yyval.sym) = (yyvsp[0].sym);}
#line 2748 "ansicnew.tab.c"
    break;

  case 53:
#line 777 "ansicnew.y"
                                                                        { printf("inclusive_or_expression : inclusive_or_expression '|' exclusive_or_expression\n"); 
																  int typ = gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & 0x1f;
														  		  string *name = newtemp();
														  		  symrec *s = putsym(name, typ);
														  		  if(((yyvsp[-2].sym).typ & 0x1f) == ((yyvsp[0].sym).typ & 0x1f))
														  		  gencode(OR_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s );
														  		  else{
																  symrec *s2;
																  if(((yyvsp[-2].sym).typ & 0x1f) == typ){
																  	s2 = genconv(typ, (yyvsp[0].sym).var);
																  	gencode(OR_IR, (yyvsp[-2].sym).var, s2, s);
															      }
																  else{
																  	s2 = genconv(typ, (yyvsp[-2].sym).var);
																  	gencode(OR_IR, s2, (yyvsp[0].sym).var, s);
																  }
														  		}
														  		  (yyval.sym).var = s;
														  		  (yyval.sym).typ = s->typ;
														  		  (yyval.sym).name = name;
																}
#line 2774 "ansicnew.tab.c"
    break;

  case 54:
#line 800 "ansicnew.y"
                {
			(yyval.lists).nextlist = makelist(nextinstr);
			gencode(GOTO_IR);
		}
#line 2783 "ansicnew.tab.c"
    break;

  case 55:
#line 806 "ansicnew.y"
                {
			(yyval.instr) = nextinstr;
		}
#line 2791 "ansicnew.tab.c"
    break;

  case 56:
#line 812 "ansicnew.y"
                                                                                                        { printf("logical_and_expression : inclusive_or_expression\n"); (yyval.sym) = (yyvsp[0].sym);}
#line 2797 "ansicnew.tab.c"
    break;

  case 57:
#line 813 "ansicnew.y"
                                                                                {	printf("logical_and_expression : logical_and_expression AND_OP inclusive_or_expression\n"); 
																	backpatch((yyvsp[-3].sym).truelist, (yyvsp[-1].instr));
																	(yyval.sym).truelist = (yyvsp[0].sym).truelist;
																	(yyval.sym).falselist = (yyvsp[-3].sym).falselist;
																	(yyval.sym).falselist->merge(*((yyvsp[0].sym).falselist));
																	(yyval.sym).typ = INTVAL;
																}
#line 2809 "ansicnew.tab.c"
    break;

  case 58:
#line 823 "ansicnew.y"
                                                                                                        { printf("logical_or_expression : logical_and_expression\n"); (yyval.sym) = (yyvsp[0].sym); }
#line 2815 "ansicnew.tab.c"
    break;

  case 59:
#line 824 "ansicnew.y"
                                                                        { printf("logical_or_expression : logical_or_expression OR_OP logical_and_expression\n"); 
																	backpatch((yyvsp[-3].sym).falselist, (yyvsp[-1].instr));
																	(yyval.sym).falselist = (yyvsp[0].sym).falselist;
																	(yyval.sym).truelist = (yyvsp[-3].sym).truelist;
																	(yyval.sym).truelist->merge(*((yyvsp[0].sym).truelist));
																	(yyval.sym).typ = INTVAL;
																}
#line 2827 "ansicnew.tab.c"
    break;

  case 60:
#line 834 "ansicnew.y"
                                                                                {(yyval.sym) = (yyvsp[0].sym);}
#line 2833 "ansicnew.tab.c"
    break;

  case 61:
#line 835 "ansicnew.y"
                                                        {

														string *name = newtemp();
														symrec *s = putsym(name, (yyvsp[-1].sym).typ & ~CONST_SPEC | VAR_SPEC);
														gencode(STORE_IR, (yyvsp[-1].sym).var, NULL, s);
														(yyvsp[-1].sym).var = s;
													}
#line 2845 "ansicnew.tab.c"
    break;

  case 62:
#line 842 "ansicnew.y"
                                                                        {
														gencode(STORE_IR, (yyvsp[0].sym).var, NULL, (yyvsp[-5].sym).var);
														(yyval.sym).var = (yyvsp[-5].sym).var;
														backpatch((yyvsp[-8].sym).truelist, (yyvsp[-6].instr));
														backpatch((yyvsp[-8].sym).falselist, (yyvsp[-1].instr));
														backpatch((yyvsp[-2].lists).nextlist, nextinstr);
														(yyval.sym).truelist = nullptr;
														(yyval.sym).falselist = nullptr;
													}
#line 2859 "ansicnew.tab.c"
    break;

  case 63:
#line 854 "ansicnew.y"
                                                                                                                        { printf("assignment_expression : conditional_expression\n"); (yyval.sym) = (yyvsp[0].sym); }
#line 2865 "ansicnew.tab.c"
    break;

  case 64:
#line 855 "ansicnew.y"
                                                                                { printf("assignment_expression : unary_expression assignment_operator assignment_expression\n"); 
																		  string *name;
																		  symrec *s, *s2, *s3;

																		  if((yyvsp[0].sym).truelist || (yyvsp[0].sym).falselist){
																			  std::string *name = newtemp();
																			  symrec *s1, *s0;
																			  s0 = putsym(name, INTVAL | CONST_SPEC);
																			  *(int *)(datablock+s0->offset)=0;
																			  name = newtemp();
																			  s1 = putsym(name, INTVAL | CONST_SPEC);
																			  *(int *)(datablock+s1->offset)=1;
																			  name = newtemp();
																			  (yyvsp[0].sym).var = putsym(name, INTVAL | VAR_SPEC);
																			  (yyvsp[0].sym).typ = INTVAL | VAR_SPEC;
																			  (yyvsp[0].sym).name	 = name;
																			  backpatch((yyvsp[0].sym).truelist, nextinstr);
																			  gencode(STORE_IR, s1, nullptr, (yyvsp[0].sym).var);
																			  gencode(GOTO_IR, nullptr, nullptr, nextinstr+2);
																			  backpatch((yyvsp[0].sym).falselist, nextinstr);
																			  gencode(STORE_IR, s0, nullptr, (yyvsp[0].sym).var);
																		  }
																		  switch((yyvsp[-1].assop)){
																			case EQ_ASSIGN_OP:
																				if(!isarray((yyvsp[-2].sym).typ)){
																					if(((yyvsp[0].sym).typ & 0x1f) == ((yyvsp[-2].sym).typ & 0x1f))
																						gencode(STORE_IR, (yyvsp[0].sym).var, nullptr, (yyvsp[-2].sym).var);
																				
																				else{
																					s3 = genconv((yyvsp[-2].sym).typ, (yyvsp[0].sym).var);
																					gencode(STORE_IR, s3, nullptr, (yyvsp[-2].sym).var);
																					}
																				}
																				else{
																					if(((yyvsp[0].sym).typ & 0x1f) == ((yyvsp[-2].sym).typ & 0x1f))
																						gencode(STOREA_IR, (yyvsp[0].sym).var, (yyvsp[-2].sym).var2, (yyvsp[-2].sym).var);
																					else{
																						s3 = genconv((yyvsp[-2].sym).typ, (yyvsp[0].sym).var);
																						gencode(STOREA_IR, s3, (yyvsp[-2].sym).var2, (yyvsp[-2].sym).var);
																						}
																				}
																				break;
																			case MUL_ASSIGN_OP:
																				genassign(MULT_IR, &(yyvsp[-2].sym), &(yyvsp[0].sym));
																				break;
																			case DIV_ASSIGN_OP:
																				genassign(DIV_IR, &(yyvsp[-2].sym), &(yyvsp[0].sym));
																				break;
																			case MOD_ASSIGN_OP:
																				genassign(MOD_IR, &(yyvsp[-2].sym), &(yyvsp[0].sym));
																				break;
																			case ADD_ASSIGN_OP:
																				genassign(ADD_IR, &(yyvsp[-2].sym), &(yyvsp[0].sym));
																				break;
																			case SUB_ASSIGN_OP:
																				genassign(SUB_IR, &(yyvsp[-2].sym), &(yyvsp[0].sym));
																				break;
																			case LEFT_ASSIGN_OP:
																				genassign(LSHIFT_IR, &(yyvsp[-2].sym), &(yyvsp[0].sym));
																				break;
																			case RIGHT_ASSIGN_OP:
																				genassign(RSHIFT_IR, &(yyvsp[-2].sym), &(yyvsp[0].sym));
																				break;
																			case AND_ASSIGN_OP:
																				genassign(AND_IR, &(yyvsp[-2].sym), &(yyvsp[0].sym));
																				break;
																			case XOR_ASSIGN_OP:
																				genassign(XOR_IR, &(yyvsp[-2].sym), &(yyvsp[0].sym));
																				break;	
																			case OR_ASSIGN_OP:
																				genassign(OR_IR, &(yyvsp[-2].sym), &(yyvsp[0].sym));
																				break;
																		    } 
																		}
#line 2944 "ansicnew.tab.c"
    break;

  case 65:
#line 932 "ansicnew.y"
                                        { printf("assignment_operator : '='\n"); (yyval.assop) = EQ_ASSIGN_OP; }
#line 2950 "ansicnew.tab.c"
    break;

  case 66:
#line 933 "ansicnew.y"
                                { printf("assignment_operator : MUL_ASSIGN\n"); (yyval.assop) = MUL_ASSIGN_OP;}
#line 2956 "ansicnew.tab.c"
    break;

  case 67:
#line 934 "ansicnew.y"
                                { printf("assignment_operator : DIV_ASSIGN\n"); (yyval.assop) = DIV_ASSIGN_OP;}
#line 2962 "ansicnew.tab.c"
    break;

  case 68:
#line 935 "ansicnew.y"
                                { printf("assignment_operator : MOD_ASSIGN\n"); (yyval.assop) = MOD_ASSIGN_OP;}
#line 2968 "ansicnew.tab.c"
    break;

  case 69:
#line 936 "ansicnew.y"
                                { printf("assignment_operator : ADD_ASSIGN\n"); (yyval.assop) = ADD_ASSIGN_OP;}
#line 2974 "ansicnew.tab.c"
    break;

  case 70:
#line 937 "ansicnew.y"
                                { printf("assignment_operator : SUB_ASSIGN\n"); (yyval.assop) = SUB_ASSIGN_OP;}
#line 2980 "ansicnew.tab.c"
    break;

  case 71:
#line 938 "ansicnew.y"
                                { printf("assignment_operator : LEFT_ASSIGN\n"); (yyval.assop) = LEFT_ASSIGN_OP;}
#line 2986 "ansicnew.tab.c"
    break;

  case 72:
#line 939 "ansicnew.y"
                                { printf("assignment_operator : RIGHT_ASSIGN\n"); (yyval.assop) = RIGHT_ASSIGN_OP;}
#line 2992 "ansicnew.tab.c"
    break;

  case 73:
#line 940 "ansicnew.y"
                                { printf("assignment_operator : AND_ASSIGN\n"); (yyval.assop) = AND_ASSIGN_OP;}
#line 2998 "ansicnew.tab.c"
    break;

  case 74:
#line 941 "ansicnew.y"
                                { printf("assignment_operator : XOR_ASSIGN\n"); (yyval.assop) = XOR_ASSIGN_OP;}
#line 3004 "ansicnew.tab.c"
    break;

  case 75:
#line 942 "ansicnew.y"
                                        { printf("assignment_operator : OR_ASSIGN\n"); (yyval.assop) = OR_ASSIGN_OP;}
#line 3010 "ansicnew.tab.c"
    break;

  case 76:
#line 946 "ansicnew.y"
                                        { printf("expression : assignment_expression\n"); (yyval.sym) = (yyvsp[0].sym); }
#line 3016 "ansicnew.tab.c"
    break;

  case 77:
#line 947 "ansicnew.y"
                                                        { printf("expression : expression ',' assignment_expression\n"); (yyval.sym) = (yyvsp[-2].sym); }
#line 3022 "ansicnew.tab.c"
    break;

  case 78:
#line 951 "ansicnew.y"
                                                { printf("constant_expression : conditional_expression\n"); (yyval.sym) = (yyvsp[0].sym); }
#line 3028 "ansicnew.tab.c"
    break;

  case 79:
#line 955 "ansicnew.y"
                                                { printf("declaration : declaration_specifiers ';'\n"); }
#line 3034 "ansicnew.tab.c"
    break;

  case 80:
#line 956 "ansicnew.y"
                                                                        { printf("declaration : declaration_specifiers init_declarator_list ';'\n"); 
															  int typ;
															  std::list<VAR_DATA *>::iterator it;
															  typ = get_type((yyvsp[-2].sqlist));
															  cout<<"Declaring variables: "<<endl;
															  for(it = (yyvsp[-1].idlist)->begin(); it != (yyvsp[-1].idlist)->end(); it++)
															  {
																symrec *s;
																cout<< *(*it)->name << endl;
																if(isarray((*it)->typ))
																	installarray((*it)->name, typ | VAR_SPEC | ((*it)->typ & ~0x1F),(*it)->dimlist);
																else
																	if(isfunction((*it)->typ))
																		s=install((*it)->name, typ | FUNC_SPEC | ((*it)->typ & ~0xF1));
																else{
																	s = install((*it)->name, typ | VAR_SPEC | ((*it)->typ & ~0x1F));
																	if((*it)->init){
																		if(currscope>0)
																			gencode(STORE_IR, (*it)->var, nullptr, s);
																		else{
																			initvar(s,(*it)->var);
																		}
																	}
																}	
															  }
															}
#line 3065 "ansicnew.tab.c"
    break;

  case 81:
#line 985 "ansicnew.y"
                                                { printf("declaration_specifiers : storage_class_specifier\n"); 
									  list<int> *newlist = new list<int>;
									  newlist->push_back((yyvsp[0].scsp));
									  (yyval.sqlist) = newlist;
									}
#line 3075 "ansicnew.tab.c"
    break;

  case 82:
#line 990 "ansicnew.y"
                                                                        { printf("declaration_specifiers : storage_class_specifier declaration_specifiers\n"); 
															  (yyval.sqlist) = (yyvsp[0].sqlist);
															  (yyval.sqlist)->push_back((yyvsp[-1].scsp));
															}
#line 3084 "ansicnew.tab.c"
    break;

  case 83:
#line 994 "ansicnew.y"
                                        { printf("declaration_specifiers : type_specifier\n"); 
							  list<int> *newlist = new list<int>;
							  newlist->push_back((yyvsp[0].typsp));
							  (yyval.sqlist)=newlist;
							}
#line 3094 "ansicnew.tab.c"
    break;

  case 84:
#line 999 "ansicnew.y"
                                                        { printf("declaration_specifiers : type_specifier declaration_specifiers\n"); 
												  (yyval.sqlist)=(yyvsp[0].sqlist);
												  (yyval.sqlist)->push_back((yyvsp[-1].typsp));
												}
#line 3103 "ansicnew.tab.c"
    break;

  case 85:
#line 1003 "ansicnew.y"
                                        { printf("declaration_specifiers : type_qualifier\n"); 
							  list<int> *newlist = new list<int>;
							  newlist->push_back((yyvsp[0].qual));
							  (yyval.sqlist)=newlist;
							}
#line 3113 "ansicnew.tab.c"
    break;

  case 86:
#line 1008 "ansicnew.y"
                                                        { printf("declaration_specifiers : type_qualifier declaration_specifiers\n"); 
												  (yyval.sqlist)=(yyvsp[0].sqlist);
												  (yyval.sqlist)->push_back((yyvsp[-1].qual));
												}
#line 3122 "ansicnew.tab.c"
    break;

  case 87:
#line 1015 "ansicnew.y"
                                        { std::list<VAR_DATA *> *newlist = new std::list<VAR_DATA *>;
							  VAR_DATA *newstruc = (yyvsp[0].id_data);
							  printf("init_declarator_list : init_declarator\n");
							  newlist->push_back(newstruc);
							  (yyval.idlist) = newlist;
							}
#line 3133 "ansicnew.tab.c"
    break;

  case 88:
#line 1021 "ansicnew.y"
                                                                { printf("init_declarator_list : init_declarator_list ',' init_declarator\n"); 
													  (yyval.idlist) = (yyvsp[-2].idlist);
													  (yyval.idlist)->push_back((yyvsp[0].id_data));
													}
#line 3142 "ansicnew.tab.c"
    break;

  case 89:
#line 1028 "ansicnew.y"
                                { printf("init_declarator : declarator\n"); 
						  (yyval.id_data) = (yyvsp[0].id_data);
						}
#line 3150 "ansicnew.tab.c"
    break;

  case 90:
#line 1031 "ansicnew.y"
                                                { printf("init_declarator : declarator '=' initializer\n"); 
										  (yyval.id_data) = (yyvsp[-2].id_data);
										  (yyval.id_data)->init = 1;
										  (yyval.id_data)->var = (yyvsp[0].sym).var;
										}
#line 3160 "ansicnew.tab.c"
    break;

  case 91:
#line 1039 "ansicnew.y"
                                { printf("storage_class_specifier : TYPEDEF\n");  (yyval.scsp) = TYPENAME_SPEC; }
#line 3166 "ansicnew.tab.c"
    break;

  case 92:
#line 1040 "ansicnew.y"
                                { printf("storage_class_specifier : EXTERN\n"); (yyval.scsp) = EXTERN_SPEC; }
#line 3172 "ansicnew.tab.c"
    break;

  case 93:
#line 1041 "ansicnew.y"
                                { printf("storage_class_specifier : STATIC\n"); (yyval.scsp) = STATIC_SPEC; }
#line 3178 "ansicnew.tab.c"
    break;

  case 94:
#line 1042 "ansicnew.y"
                        { printf("storage_class_specifier : AUTO\n"); (yyval.scsp) = AUTO_SPEC; }
#line 3184 "ansicnew.tab.c"
    break;

  case 95:
#line 1043 "ansicnew.y"
                                { printf("storage_class_specifier : REGISTER\n"); (yyval.scsp) = REGISTER_SPEC; }
#line 3190 "ansicnew.tab.c"
    break;

  case 96:
#line 1047 "ansicnew.y"
                        { printf("type_specifier : VOID\n"); (yyval.typsp) = VOID_SPEC; }
#line 3196 "ansicnew.tab.c"
    break;

  case 97:
#line 1048 "ansicnew.y"
                        { printf("type_specifier : CHAR\n"); (yyval.typsp) = CHAR_SPEC; }
#line 3202 "ansicnew.tab.c"
    break;

  case 98:
#line 1049 "ansicnew.y"
                        { printf("type_specifier : SHORT\n"); (yyval.typsp) = SHORT_SPEC; }
#line 3208 "ansicnew.tab.c"
    break;

  case 99:
#line 1050 "ansicnew.y"
                        { printf("type_specifier : INT\n"); (yyval.typsp) = INT_SPEC;}
#line 3214 "ansicnew.tab.c"
    break;

  case 100:
#line 1051 "ansicnew.y"
                        { printf("type_specifier : LONG\n"); (yyval.typsp) = LONG_SPEC; }
#line 3220 "ansicnew.tab.c"
    break;

  case 101:
#line 1052 "ansicnew.y"
                        { printf("type_specifier : FLOAT\n"); (yyval.typsp) = FLOAT_SPEC; }
#line 3226 "ansicnew.tab.c"
    break;

  case 102:
#line 1053 "ansicnew.y"
                                { printf("type_specifier : DOUBLE\n"); (yyval.typsp) = DOUBLE_SPEC; }
#line 3232 "ansicnew.tab.c"
    break;

  case 103:
#line 1054 "ansicnew.y"
                                { printf("type_specifier : SIGNED\n"); (yyval.typsp) = SIGNED_SPEC; }
#line 3238 "ansicnew.tab.c"
    break;

  case 104:
#line 1055 "ansicnew.y"
                                { printf("type_specifier : UNSIGNED\n"); (yyval.typsp) = UNSIGNED_SPEC; }
#line 3244 "ansicnew.tab.c"
    break;

  case 105:
#line 1056 "ansicnew.y"
                                                { printf("type_specifier : struct_or_union_specifier\n"); }
#line 3250 "ansicnew.tab.c"
    break;

  case 106:
#line 1057 "ansicnew.y"
                                        { printf("type_specifier : enum_specifier\n"); (yyval.typsp) = ENUM_SPEC; }
#line 3256 "ansicnew.tab.c"
    break;

  case 107:
#line 1058 "ansicnew.y"
                                { printf("type_specifier : TYPE_NAME\n"); (yyval.typsp) = TYPENAME_SPEC; }
#line 3262 "ansicnew.tab.c"
    break;

  case 108:
#line 1062 "ansicnew.y"
                                                                                { printf("struct_or_union_specifier : struct_or_union IDENTIFIER '{' struct_declaration_list '}'\n"); }
#line 3268 "ansicnew.tab.c"
    break;

  case 109:
#line 1063 "ansicnew.y"
                                                                        { printf("struct_or_union_specifier : struct_or_union '{' struct_declaration_list '}'\n"); }
#line 3274 "ansicnew.tab.c"
    break;

  case 110:
#line 1064 "ansicnew.y"
                                                { printf("struct_or_union_specifier : struct_or_union IDENTIFIER\n"); }
#line 3280 "ansicnew.tab.c"
    break;

  case 111:
#line 1068 "ansicnew.y"
                                { printf("struct_or_union : STRUCT\n"); }
#line 3286 "ansicnew.tab.c"
    break;

  case 112:
#line 1069 "ansicnew.y"
                        { printf("struct_or_union : UNION\n"); }
#line 3292 "ansicnew.tab.c"
    break;

  case 113:
#line 1073 "ansicnew.y"
                                        { printf("struct_declaration_list : struct_declaration\n"); }
#line 3298 "ansicnew.tab.c"
    break;

  case 114:
#line 1074 "ansicnew.y"
                                                                { printf("struct_declaration_list : struct_declaration_list struct_declaration\n"); }
#line 3304 "ansicnew.tab.c"
    break;

  case 115:
#line 1078 "ansicnew.y"
                                                                        { printf("struct_declaration : specifier_qualifier_list struct_declarator_list ';'\n"); }
#line 3310 "ansicnew.tab.c"
    break;

  case 116:
#line 1082 "ansicnew.y"
                                                                { printf("specifier_qualifier_list : type_specifier specifier_qualifier_list\n"); 
													  (yyval.sqlist) = (yyvsp[0].sqlist);
													  (yyval.sqlist)->push_back((yyvsp[-1].typsp));
													}
#line 3319 "ansicnew.tab.c"
    break;

  case 117:
#line 1086 "ansicnew.y"
                                        { printf("specifier_qualifier_list : type_specifier\n"); 
							  std::list<int> *newlist = new std::list<int>;
							  newlist->push_back((yyvsp[0].typsp));
							  (yyval.sqlist) = newlist;
							}
#line 3329 "ansicnew.tab.c"
    break;

  case 118:
#line 1091 "ansicnew.y"
                                                                { printf("specifier_qualifier_list : type_qualifier specifier_qualifier_list\n"); 
													  (yyval.sqlist) = (yyvsp[0].sqlist);
													  (yyval.sqlist)->push_back((yyvsp[-1].qual));
													}
#line 3338 "ansicnew.tab.c"
    break;

  case 119:
#line 1095 "ansicnew.y"
                                        { printf("specifier_qualifier_list : type_qualifier\n"); 
							  std::list<int> *newlist = new std::list<int>;
							  newlist->push_back((yyvsp[0].qual));
							  (yyval.sqlist) = newlist;
							}
#line 3348 "ansicnew.tab.c"
    break;

  case 120:
#line 1103 "ansicnew.y"
                                        { printf("struct_declarator_list : struct_declarator\n"); }
#line 3354 "ansicnew.tab.c"
    break;

  case 121:
#line 1104 "ansicnew.y"
                                                                { printf("struct_declarator_list : struct_declarator_list ',' struct_declarator\n"); }
#line 3360 "ansicnew.tab.c"
    break;

  case 122:
#line 1108 "ansicnew.y"
                                { printf("struct_declarator : declarator\n"); }
#line 3366 "ansicnew.tab.c"
    break;

  case 123:
#line 1109 "ansicnew.y"
                                                { printf("struct_declarator : ':' constant_expression\n"); }
#line 3372 "ansicnew.tab.c"
    break;

  case 124:
#line 1110 "ansicnew.y"
                                                        { printf("struct_declarator : declarator ':' constant_expression\n"); }
#line 3378 "ansicnew.tab.c"
    break;

  case 125:
#line 1114 "ansicnew.y"
                                                { printf("enum_specifier : ENUM '{' enumerator_list '}'\n"); }
#line 3384 "ansicnew.tab.c"
    break;

  case 126:
#line 1115 "ansicnew.y"
                                                                { printf("enum_specifier : ENUM IDENTIFIER '{' enumerator_list '}'\n"); }
#line 3390 "ansicnew.tab.c"
    break;

  case 127:
#line 1116 "ansicnew.y"
                                        { printf("enum_specifier : ENUM IDENTIFIER\n"); }
#line 3396 "ansicnew.tab.c"
    break;

  case 128:
#line 1120 "ansicnew.y"
                                { printf("enumerator_list : enumerator\n"); }
#line 3402 "ansicnew.tab.c"
    break;

  case 129:
#line 1121 "ansicnew.y"
                                                        { printf("enumerator_list : enumerator_list ',' enumerator\n"); }
#line 3408 "ansicnew.tab.c"
    break;

  case 130:
#line 1125 "ansicnew.y"
                                { printf("enumerator : IDENTIFIER\n"); }
#line 3414 "ansicnew.tab.c"
    break;

  case 131:
#line 1126 "ansicnew.y"
                                                        { printf("enumerator : IDENTIFIER '=' constant_expression\n"); }
#line 3420 "ansicnew.tab.c"
    break;

  case 132:
#line 1130 "ansicnew.y"
                        { printf("type_qualifier : CONST\n"); (yyval.qual) = CONST_SPEC; }
#line 3426 "ansicnew.tab.c"
    break;

  case 133:
#line 1131 "ansicnew.y"
                                { printf("type_qualifier : VOLATILE\n"); (yyval.qual) = VOLATILE_SPEC; }
#line 3432 "ansicnew.tab.c"
    break;

  case 134:
#line 1135 "ansicnew.y"
                                                { 
										printf("declarator: pointer direct_declarator\n");
										(yyval.id_data) = (yyvsp[0].id_data);
										(yyval.id_data)->plevel = (yyvsp[-1].pstruc).level;
										(yyval.id_data)->typ |= POINTER_SPEC | (yyvsp[-1].pstruc).typq;
									}
#line 3443 "ansicnew.tab.c"
    break;

  case 135:
#line 1141 "ansicnew.y"
                                        { printf("declarator : direct_declarator\n"); 
							  (yyval.id_data) = (yyvsp[0].id_data);
							  if(isarray((yyval.id_data)->typ))
							  {
								  if(allzero((yyval.id_data)->dimlist))
								  {
									  (yyval.id_data)->typ &= ~ARRAY_SPEC;
									  (yyval.id_data)->typ |= POINTER_SPEC;
								  }
								  else{
									  if(product((yyval.id_data)->dimlist) == 0)
									  	yyerror("Array dimensions must be specified!");
								  }
							  }
							}
#line 3463 "ansicnew.tab.c"
    break;

  case 136:
#line 1159 "ansicnew.y"
                                {
							printf("direct_declarator: IDENTIFIER");
							string *name = new string((yyvsp[0].name));
							cout<<"<"<< *name << ">\n";
							VAR_DATA *newsym = new VAR_DATA();
							newsym->name = name;
							newsym->dimlist = nullptr;
							(yyval.id_data) = newsym;
						}
#line 3477 "ansicnew.tab.c"
    break;

  case 137:
#line 1168 "ansicnew.y"
                                {
						   	printf("direct_declarator: '(' declarator ')'    \n");
						 	}
#line 3485 "ansicnew.tab.c"
    break;

  case 138:
#line 1171 "ansicnew.y"
                                                                 {
													   		printf("direct_declarator: direct_declarator '[' constant_expression ']'    \n");
															if(!isintegral((yyvsp[-1].sym).typ))
																yyerror("Array dimensions must be integral!");
															if(!isconstant((yyvsp[-1].sym).typ))
																yyerror("Array dimensions must be constant!");
															(yyval.id_data) = (yyvsp[-3].id_data);
															if((yyval.id_data)->dimlist == nullptr)
																(yyval.id_data)->dimlist = new list<int>;
															(yyval.id_data)->dimlist->push_back((yyvsp[-1].sym).val.intval);
															(yyval.id_data)->typ |= ARRAY_SPEC;
													   	}
#line 3502 "ansicnew.tab.c"
    break;

  case 139:
#line 1183 "ansicnew.y"
                                                {
										printf("direct_declarator: direct_declarator '[' ']'\n");
										(yyval.id_data) = (yyvsp[-2].id_data);
										if((yyval.id_data)->dimlist == nullptr)
											(yyval.id_data)->dimlist = new list<int>;
										(yyval.id_data)->dimlist->push_back(0);
										(yyval.id_data)->typ |= ARRAY_SPEC;
									}
#line 3515 "ansicnew.tab.c"
    break;

  case 140:
#line 1191 "ansicnew.y"
                                                                {
														printf("direct_declarator: direct_declarator '(' parameter_type_list ')'\n");	
														(yyval.id_data) = (yyvsp[-3].id_data);
														(yyval.id_data)->typ |= FUNC_SPEC;
														(yyval.id_data)->arglist = (yyvsp[-1].idlist);
														(yyval.id_data)->init = 0;																			
														}
#line 3527 "ansicnew.tab.c"
    break;

  case 141:
#line 1198 "ansicnew.y"
                                                                {
													printf("direct_declarator:  direct_declarator '(' identifier_list ')'\n ");
													}
#line 3535 "ansicnew.tab.c"
    break;

  case 142:
#line 1201 "ansicnew.y"
                                                {
									printf("direct_declarator: direct_declarator '(' ')'\n");
									(yyval.id_data) = (yyvsp[-2].id_data);
									(yyval.id_data)->typ |= FUNC_SPEC;
									(yyval.id_data)->init = 0;
									}
#line 3546 "ansicnew.tab.c"
    break;

  case 143:
#line 1210 "ansicnew.y"
                        { printf("pointer : '*'\n"); 
				  (yyval.pstruc).typq = POINTER_SPEC;
				  (yyval.pstruc).level = 1;
				}
#line 3555 "ansicnew.tab.c"
    break;

  case 144:
#line 1214 "ansicnew.y"
                                                { printf("pointer : '*' type_qualifier_list\n"); 
									  (yyval.pstruc).typq = get_type((yyvsp[0].splist)) | POINTER_SPEC;
									  (yyval.pstruc).level = 1;
									}
#line 3564 "ansicnew.tab.c"
    break;

  case 145:
#line 1218 "ansicnew.y"
                                { printf("pointer : '*' pointer\n"); 
						  (yyval.pstruc) = (yyvsp[0].pstruc);
						  (yyval.pstruc).level++;
						}
#line 3573 "ansicnew.tab.c"
    break;

  case 146:
#line 1222 "ansicnew.y"
                                                        { printf("pointer : '*' type_qualifier_list pointer\n"); 
											  (yyval.pstruc) = (yyvsp[0].pstruc);
											  (yyval.pstruc).typq = get_type((yyvsp[-1].splist));
											  (yyval.pstruc).level++;
											}
#line 3583 "ansicnew.tab.c"
    break;

  case 147:
#line 1230 "ansicnew.y"
                                        { printf("type_qualifier_list : type_qualifier\n"); 
							  list<int> *newlist = new list<int>();
							  newlist->push_back((yyvsp[0].qual));
							  (yyval.splist) = newlist;
							}
#line 3593 "ansicnew.tab.c"
    break;

  case 148:
#line 1235 "ansicnew.y"
                                                        { printf("type_qualifier_list : type_qualifier_list type_qualifier\n"); 
												  (yyval.splist) = (yyvsp[-1].splist);
												  (yyval.splist)->push_back((yyvsp[0].qual));
												}
#line 3602 "ansicnew.tab.c"
    break;

  case 149:
#line 1243 "ansicnew.y"
                                        {  printf("parameter_type_list: parameter_list\n"); 
							   (yyval.idlist) = (yyvsp[0].idlist); 
							}
#line 3610 "ansicnew.tab.c"
    break;

  case 150:
#line 1246 "ansicnew.y"
                                                { printf("parameter_type_list: parameter_list ',' ELLIPSIS\n");}
#line 3616 "ansicnew.tab.c"
    break;

  case 151:
#line 1250 "ansicnew.y"
                                        { printf("parameter_list : parameter_declaration\n");
								  std::list<VAR_DATA *> *newlist = new std::list<VAR_DATA *>;
								  VAR_DATA *newstruc = new VAR_DATA();
								  *newstruc = (yyvsp[0].sym);
								  newlist->push_back(newstruc);
								  (yyval.idlist) = newlist;
								}
#line 3628 "ansicnew.tab.c"
    break;

  case 152:
#line 1257 "ansicnew.y"
                                                                { printf("parameter_list : parameter_list ',' parameter_declaration\n");
													  (yyval.idlist) = (yyvsp[-2].idlist);
													  VAR_DATA *newstruc = new VAR_DATA();
													  *newstruc = (yyvsp[0].sym);
													  (yyval.idlist)->push_back(newstruc);
													}
#line 3639 "ansicnew.tab.c"
    break;

  case 153:
#line 1266 "ansicnew.y"
                                                        { printf("parameter_declaration : declaration_specifiers declarator\n");
											  (yyval.sym).name =(yyvsp[0].id_data)->name;
											  if(!isarray((yyvsp[0].id_data)->typ))
											  	(yyval.sym).typ = get_type((yyvsp[-1].sqlist));
											  else
											  	(yyval.sym).typ = (yyval.sym).typ = get_type((yyvsp[-1].sqlist)) | ARRAY_SPEC;
											}
#line 3651 "ansicnew.tab.c"
    break;

  case 154:
#line 1273 "ansicnew.y"
                                                                { printf("parameter_declaration : declaration_specifiers abstract_declarator\n"); }
#line 3657 "ansicnew.tab.c"
    break;

  case 155:
#line 1274 "ansicnew.y"
                                                { printf("parameter_declaration : declaration_specifiers\n"); }
#line 3663 "ansicnew.tab.c"
    break;

  case 156:
#line 1278 "ansicnew.y"
                                { printf("identifier_list : IDENTIFIER\n"); 
						  	
						}
#line 3671 "ansicnew.tab.c"
    break;

  case 157:
#line 1281 "ansicnew.y"
                                                        { printf("identifier_list : identifier_list ',' IDENTIFIER\n"); }
#line 3677 "ansicnew.tab.c"
    break;

  case 158:
#line 1285 "ansicnew.y"
                                                { printf("type_name : specifier_qualifier_list\n"); 
									  (yyval.typ) = get_type((yyvsp[0].sqlist));
									}
#line 3685 "ansicnew.tab.c"
    break;

  case 159:
#line 1288 "ansicnew.y"
                                                                { printf("type_name : specifier_qualifier_list abstract_declarator\n"); }
#line 3691 "ansicnew.tab.c"
    break;

  case 160:
#line 1292 "ansicnew.y"
                                { printf("abstract_declarator : pointer\n"); }
#line 3697 "ansicnew.tab.c"
    break;

  case 161:
#line 1293 "ansicnew.y"
                                                { printf("abstract_declarator : direct_abstract_declarator\n"); }
#line 3703 "ansicnew.tab.c"
    break;

  case 162:
#line 1294 "ansicnew.y"
                                                        { printf("abstract_declarator : pointer direct_abstract_declarator\n"); }
#line 3709 "ansicnew.tab.c"
    break;

  case 163:
#line 1298 "ansicnew.y"
                                                { printf("direct_abstract_declarator : '(' abstract_declarator ')'\n"); }
#line 3715 "ansicnew.tab.c"
    break;

  case 164:
#line 1299 "ansicnew.y"
                                { printf("direct_abstract_declarator : '[' ']'\n"); }
#line 3721 "ansicnew.tab.c"
    break;

  case 165:
#line 1300 "ansicnew.y"
                                                { printf("direct_abstract_declarator : '[' constant_expression ']'\n"); }
#line 3727 "ansicnew.tab.c"
    break;

  case 166:
#line 1301 "ansicnew.y"
                                                        { printf("direct_abstract_declarator : direct_abstract_declarator '[' ']'\n"); }
#line 3733 "ansicnew.tab.c"
    break;

  case 167:
#line 1302 "ansicnew.y"
                                                                                { printf("direct_abstract_declarator : direct_abstract_declarator '[' constant_expression ']'\n"); }
#line 3739 "ansicnew.tab.c"
    break;

  case 168:
#line 1303 "ansicnew.y"
                                { printf("direct_abstract_declarator : '(' ')'\n"); }
#line 3745 "ansicnew.tab.c"
    break;

  case 169:
#line 1304 "ansicnew.y"
                                                { printf("direct_abstract_declarator : '(' parameter_type_list ')'\n"); }
#line 3751 "ansicnew.tab.c"
    break;

  case 170:
#line 1305 "ansicnew.y"
                                                        { printf("direct_abstract_declarator : direct_abstract_declarator '(' ')'\n"); }
#line 3757 "ansicnew.tab.c"
    break;

  case 171:
#line 1306 "ansicnew.y"
                                                                                { printf("direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list ')'\n"); }
#line 3763 "ansicnew.tab.c"
    break;

  case 172:
#line 1310 "ansicnew.y"
                                        { printf("initializer : assignment_expression\n"); (yyval.sym) = (yyvsp[0].sym); }
#line 3769 "ansicnew.tab.c"
    break;

  case 173:
#line 1311 "ansicnew.y"
                                                { printf("initializer : '{' initializer_list '}'\n"); }
#line 3775 "ansicnew.tab.c"
    break;

  case 174:
#line 1312 "ansicnew.y"
                                                { printf("initializer : '{' initializer_list ',' '}'\n"); }
#line 3781 "ansicnew.tab.c"
    break;

  case 175:
#line 1316 "ansicnew.y"
                                { printf("initializer_list : initializer\n"); }
#line 3787 "ansicnew.tab.c"
    break;

  case 176:
#line 1317 "ansicnew.y"
                                                        { printf("initializer_list : initializer_list ',' initializer\n"); }
#line 3793 "ansicnew.tab.c"
    break;

  case 178:
#line 1324 "ansicnew.y"
                                                { 
									printf("statement : labeled_statement\n"); 
									(yyval.lists) = (yyvsp[0].lists);
									(yyval.lists).nextlist = NULL;
								}
#line 3803 "ansicnew.tab.c"
    break;

  case 179:
#line 1329 "ansicnew.y"
                                                        {
									enter_scope();
								}
#line 3811 "ansicnew.tab.c"
    break;

  case 180:
#line 1332 "ansicnew.y"
                                        { 
									printf("statement : compound_statement\n"); 
	  								//printlocalvars();
									(yyval.lists) = (yyvsp[0].lists);
	  							}
#line 3821 "ansicnew.tab.c"
    break;

  case 181:
#line 1337 "ansicnew.y"
                                        { 
									printf("statement : expression_statement\n"); 
									(yyval.lists).nextlist = NULL;
									(yyval.lists).breaklist = NULL;
									(yyval.lists).continuelist = NULL;
									(yyval.lists).gotolist = NULL;
									(yyval.lists).caselist = NULL;
								}
#line 3834 "ansicnew.tab.c"
    break;

  case 182:
#line 1345 "ansicnew.y"
                                        { 
									printf("statement : selection_statement\n"); 
									(yyval.lists) = (yyvsp[0].lists);
									(yyval.lists).caselist = NULL;
								}
#line 3844 "ansicnew.tab.c"
    break;

  case 183:
#line 1350 "ansicnew.y"
                                        { 
									printf("statement : iteration_statement\n"); 
									(yyval.lists) = (yyvsp[0].lists);
									(yyval.lists).caselist = NULL;
								}
#line 3854 "ansicnew.tab.c"
    break;

  case 184:
#line 1355 "ansicnew.y"
                                                { 
									printf("statement : jump_statement\n"); 
									(yyval.lists) = (yyvsp[0].lists);
									(yyval.lists).caselist = NULL;
								}
#line 3864 "ansicnew.tab.c"
    break;

  case 185:
#line 1363 "ansicnew.y"
                                                { 
											printf("labeled_statement : IDENTIFIER ':' statement\n"); 
											putlab(new string((yyvsp[-3].name)), (yyvsp[-1].instr));
											(yyval.lists).nextlist = NULL;
											(yyval.lists).breaklist = NULL;
											(yyval.lists).continuelist = NULL;
											(yyval.lists).gotolist = NULL;
											(yyval.lists).caselist = NULL;
										}
#line 3878 "ansicnew.tab.c"
    break;

  case 186:
#line 1372 "ansicnew.y"
                                                                {
														printf("labeled_statement : CASE constant_expression ':' statement\n"); 
														(yyval.lists).breaklist = (yyvsp[0].lists).breaklist;
														(yyval.lists).continuelist = (yyvsp[0].lists).continuelist;
														(yyval.lists).gotolist = (yyvsp[0].lists).gotolist;
														if(!isconstant((yyvsp[-3].sym).typ))
															yyerror("ERROR: CASE expression must be constant\n");
														if(!isintegral((yyvsp[-3].sym).typ))
															yyerror("ERROR: CASE expression must be integral constant\n");
														(yyval.lists).caselist = makecaselist((yyvsp[-3].sym).val, (yyvsp[-3].sym).typ, (yyvsp[-1].instr));
													}
#line 3894 "ansicnew.tab.c"
    break;

  case 187:
#line 1383 "ansicnew.y"
                                                                                { 
														printf("labeled_statement : DEFAULT ':' N statement\n"); 
														(yyval.lists).breaklist = (yyvsp[0].lists).breaklist;
														(yyval.lists).continuelist = (yyvsp[0].lists).continuelist;
														(yyval.lists).gotolist = (yyvsp[0].lists).gotolist;
														(yyval.lists).caselist = makecaselist((yyvsp[-1].instr));
													}
#line 3906 "ansicnew.tab.c"
    break;

  case 188:
#line 1393 "ansicnew.y"
                                                                                                {
														printf("compound_statement : '{' '}'\n");
														(yyval.lists).breaklist = NULL;
														(yyval.lists).continuelist = NULL;
														(yyval.lists).gotolist = NULL;
														(yyval.lists).nextlist = NULL;
													}
#line 3918 "ansicnew.tab.c"
    break;

  case 189:
#line 1400 "ansicnew.y"
                                                                                {
														printf("compound_statement : '{' statement_list '}'\n"); 
														(yyval.lists) = (yyvsp[-1].lists);
													}
#line 3927 "ansicnew.tab.c"
    break;

  case 190:
#line 1404 "ansicnew.y"
                                                                                {
														printf("compound_statement : '{' declaration_list '}'\n"); 
														(yyval.lists).breaklist = NULL;
														(yyval.lists).continuelist = NULL;
														(yyval.lists).gotolist = NULL;
														(yyval.lists).nextlist = NULL;
													}
#line 3939 "ansicnew.tab.c"
    break;

  case 191:
#line 1411 "ansicnew.y"
                                                                {
														printf("compound_statement : '{' declaration_list statement_list '}'\n"); 
														(yyval.lists) = (yyvsp[-1].lists);
													}
#line 3948 "ansicnew.tab.c"
    break;

  case 192:
#line 1418 "ansicnew.y"
                                { printf("declaration_list : declaration\n"); }
#line 3954 "ansicnew.tab.c"
    break;

  case 193:
#line 1419 "ansicnew.y"
                                                { printf("declaration_list : declaration_list declaration\n"); }
#line 3960 "ansicnew.tab.c"
    break;

  case 194:
#line 1423 "ansicnew.y"
                                                                { 
										printf("statement_list : statement\n"); 
										(yyval.lists) = (yyvsp[0].lists);
									}
#line 3969 "ansicnew.tab.c"
    break;

  case 195:
#line 1427 "ansicnew.y"
                                        {
										printf("statement_list : statement_list statement\n"); 
										backpatch((yyvsp[-2].lists).nextlist, (yyvsp[-1].instr));
										(yyval.lists) = (yyvsp[-2].lists);
										(yyval.lists).nextlist = (yyvsp[0].lists).nextlist;
										(yyval.lists).breaklist = merge((yyvsp[-2].lists).breaklist, (yyvsp[0].lists).breaklist);
										(yyval.lists).continuelist = merge((yyvsp[-2].lists).continuelist, (yyvsp[0].lists).continuelist);
										(yyval.lists).gotolist = merge((yyvsp[-2].lists).gotolist, (yyvsp[0].lists).gotolist);
										(yyval.lists).caselist = merge((yyvsp[-2].lists).caselist, (yyvsp[0].lists).caselist);
									}
#line 3984 "ansicnew.tab.c"
    break;

  case 196:
#line 1440 "ansicnew.y"
                                                { 
								printf("expression_statement : ';'\n"); 
								(yyval.sym).truelist = nullptr;
								(yyval.sym).falselist = nullptr;
							}
#line 3994 "ansicnew.tab.c"
    break;

  case 197:
#line 1445 "ansicnew.y"
                                        { 
								printf("expression_statement : expression ';'\n"); 
								(yyval.sym) = (yyvsp[-1].sym);
							}
#line 4003 "ansicnew.tab.c"
    break;

  case 198:
#line 1451 "ansicnew.y"
                                                                {	
													(yyval.sym) = (yyvsp[0].sym);
													if((yyvsp[0].sym).truelist == nullptr || (yyvsp[0].sym).falselist == nullptr){
														std::string *name = newtemp();
														symrec *s0;
														s0 = putsym(name, INTVAL | CONST_SPEC);
														*(int *)(datablock+s0->offset) = 0;
														(yyval.sym).truelist = makelist(nextinstr);
														gencode(IF_NE_IR, (yyvsp[0].sym).var, s0, nullptr);
														(yyval.sym).falselist = makelist(nextinstr);
														gencode(GOTO_IR);
													}
												}
#line 4021 "ansicnew.tab.c"
    break;

  case 199:
#line 1466 "ansicnew.y"
                                                        {
														(yyval.sym) = (yyvsp[0].sym);
														if((yyvsp[0].sym).truelist == nullptr || (yyvsp[0].sym).falselist == nullptr){
															std::string *name = newtemp();
															symrec *s0;
															s0 = putsym(name, INTVAL | CONST_SPEC);
															*(int *)(datablock+s0->offset) = 0;
															(yyval.sym).truelist = makelist(nextinstr);
															gencode(IF_NE_IR, (yyvsp[0].sym).var, s0, nullptr);
															(yyval.sym).falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														}
													}
#line 4039 "ansicnew.tab.c"
    break;

  case 200:
#line 1482 "ansicnew.y"
                                                                        { 	printf("expression_statement : IF '(' expression ')' N statement ");
																		backpatch((yyvsp[-3].sym).truelist, (yyvsp[-1].instr));
																		(yyval.lists).nextlist = merge((yyvsp[-3].sym).falselist, (yyvsp[0].lists).nextlist);
																		(yyval.lists).breaklist = (yyvsp[0].lists).breaklist;
																		(yyval.lists).continuelist = (yyvsp[0].lists).continuelist;
																		(yyval.lists).gotolist = (yyvsp[0].lists).gotolist;
																	}
#line 4051 "ansicnew.tab.c"
    break;

  case 201:
#line 1489 "ansicnew.y"
                                                                                { 	printf("selection_statement : IF '(' expression ')' statement ELSE statement\n"); 
																		backpatch((yyvsp[-7].sym).truelist, (yyvsp[-5].instr));
																		backpatch((yyvsp[-7].sym).falselist, (yyvsp[-1].instr));
																		(yyval.lists).nextlist = merge((yyvsp[-4].lists).nextlist, (yyvsp[-2].lists).nextlist, (yyvsp[0].lists).nextlist);
																		(yyval.lists).breaklist = merge((yyvsp[-4].lists).breaklist, (yyvsp[0].lists).breaklist);
																		(yyval.lists).continuelist = merge((yyvsp[-4].lists).continuelist, (yyvsp[0].lists).continuelist);
																		(yyval.lists).gotolist = merge((yyvsp[-4].lists).gotolist, (yyvsp[0].lists).gotolist);
																	}
#line 4064 "ansicnew.tab.c"
    break;

  case 202:
#line 1497 "ansicnew.y"
                                                        { 
													printf("selection_statement : SWITCH '(' expression ')' statement\n"); 
													if(!isintegral((yyvsp[-2].sym).typ))
														yyerror("ERROR: swtich expression must be integral");
													(yyvsp[0].lists).breaklist = merge((yyvsp[0].lists).breaklist, makelist(nextinstr));
													gencode(GOTO_IR);
													backpatch((yyvsp[-4].lists).nextlist, nextinstr);
													std::list<CASE_DATA *>::iterator it;
													if((yyvsp[0].lists).caselist != NULL){
														for(it = (yyvsp[0].lists).caselist->begin(); it != (yyvsp[0].lists).caselist->end(); it++){
															int addr = (*it)->addr;
															int typ = (*it)->typ;
															if(typ == VOIDVAL)
																gencode(GOTO_IR, addr);
															else{
																std::string *name = newtemp();
																symrec *s = putsym(name, INTVAL | CONST_SPEC);
																symrec*s1 = (yyvsp[-2].sym).var;
																*(int *)((char *)datablock+s->offset) = (*it)->val.intval;
																if(isconstant((yyvsp[-2].sym).typ)){
																	name = newtemp();
																	s1 = putsym(name, INTVAL | CONST_SPEC);
																	*(int *)((char *)datablock+s1->offset) = (yyvsp[-2].sym).val.intval;
																}
																gencode(IF_EQ_IR, s, s1, addr);
															}
														}
														backpatch((yyvsp[0].lists).breaklist, nextinstr);
														(yyval.lists).breaklist = NULL;
														(yyval.lists).continuelist = (yyvsp[0].lists).continuelist;
														(yyval.lists).gotolist = (yyvsp[0].lists).gotolist;
														(yyval.lists).nextlist = NULL;
													}
												}
#line 4103 "ansicnew.tab.c"
    break;

  case 203:
#line 1534 "ansicnew.y"
                                                                                                                        { 
																						printf("iteration_statement : WHILE '(' expression ')' statement\n"); 
																						backpatch((yyvsp[0].lists).nextlist, (yyvsp[-5].instr));
																						backpatch((yyvsp[0].lists).continuelist, (yyvsp[-5].instr));
																						backpatch((yyvsp[-3].sym).truelist, (yyvsp[-1].instr));
																						(yyval.lists).nextlist = (yyvsp[-3].sym).falselist;
																						gencode(GOTO_IR, (yyvsp[-5].instr));
																						backpatch((yyvsp[0].lists).breaklist, nextinstr);
																						(yyval.lists).breaklist = NULL;
																						(yyval.lists).continuelist = NULL;
																						(yyval.lists).gotolist = (yyvsp[0].lists).gotolist;
																					}
#line 4120 "ansicnew.tab.c"
    break;

  case 204:
#line 1546 "ansicnew.y"
                                                                                                                                        { 
																									printf("iteration_statement : DO statement WHILE '(' expression ')' ';'\n"); 
																									backpatch((yyvsp[-2].sym).truelist, (yyvsp[-7].instr));
																									backpatch((yyvsp[-6].lists).nextlist, (yyvsp[-4].instr));
																									backpatch((yyvsp[-6].lists).continuelist, (yyvsp[-4].instr));
																									backpatch((yyvsp[-6].lists).breaklist, nextinstr);
																									(yyval.lists).breaklist = NULL;
																									(yyval.lists).continuelist = NULL;
																									(yyval.lists).nextlist  = (yyvsp[-2].sym).falselist;
																									(yyval.lists).gotolist = (yyvsp[-6].lists).gotolist;
																								}
#line 4136 "ansicnew.tab.c"
    break;

  case 205:
#line 1557 "ansicnew.y"
                                                                                                                        { 
																									printf("iteration_statement : FOR '(' expression_statement expression_statement ')' statement\n"); 
																									backpatch((yyvsp[-3].sym).truelist, (yyvsp[-2].instr));
																									backpatch((yyvsp[0].lists).nextlist, (yyvsp[-4].instr));
																									backpatch((yyvsp[0].lists).continuelist, (yyvsp[-4].instr));
																									(yyval.lists).nextlist = (yyvsp[-3].sym).falselist;
																									gencode(GOTO_IR, (yyvsp[-4].instr));
																									backpatch((yyvsp[0].lists).breaklist, nextinstr);
																									(yyval.lists).breaklist = NULL;
																									(yyval.lists).continuelist = NULL;
																									(yyval.lists).gotolist = (yyvsp[0].lists).gotolist;
																								}
#line 4153 "ansicnew.tab.c"
    break;

  case 206:
#line 1569 "ansicnew.y"
                                                                                                        { 
																									printf("iteration_statement : FOR '(' expression_statement expression_statement expression ')' statement\n");
																									backpatch((yyvsp[-6].sym).truelist, (yyvsp[-1].instr));
																									backpatch((yyvsp[0].lists).nextlist, (yyvsp[-5].instr));
																									backpatch((yyvsp[-2].lists).nextlist, (yyvsp[-7].instr));
																									(yyval.lists).nextlist = (yyvsp[-6].sym).falselist;
																									gencode(GOTO_IR, (yyvsp[-5].instr));
																									backpatch((yyvsp[0].lists).breaklist, nextinstr);
																									(yyval.lists).breaklist = NULL;
																									(yyval.lists).continuelist = NULL;
																									(yyval.lists).gotolist = (yyvsp[0].lists).gotolist;
																								}
#line 4170 "ansicnew.tab.c"
    break;

  case 207:
#line 1584 "ansicnew.y"
                                        { 
									printf("jump_statement : GOTO IDENTIFIER ';'\n"); 
									(yyval.lists).continuelist = NULL;
									(yyval.lists).breaklist = NULL;
									(yyval.lists).nextlist = NULL;
									(yyval.lists).caselist = NULL;
									(yyval.lists).gotolist = makelist(new string((yyvsp[-1].name)), nextinstr);
									gencode(GOTO_IR);
								}
#line 4184 "ansicnew.tab.c"
    break;

  case 208:
#line 1593 "ansicnew.y"
                                                { 
									printf("jump_statement : CONTINUE ';'\n"); 
									(yyval.lists).breaklist = NULL;
									(yyval.lists).nextlist = NULL;
									(yyval.lists).caselist = NULL;
									(yyval.lists).gotolist = NULL;
									(yyval.lists).continuelist = makelist(nextinstr);
									gencode(GOTO_IR);
								}
#line 4198 "ansicnew.tab.c"
    break;

  case 209:
#line 1602 "ansicnew.y"
                                                        { 
									printf("jump_statement : BREAK ';'\n"); 
									(yyval.lists).nextlist = NULL;
									(yyval.lists).continuelist = NULL;
									(yyval.lists).caselist = NULL;
									(yyval.lists).gotolist = NULL;
									(yyval.lists).breaklist = makelist(nextinstr);
									gencode(GOTO_IR);	
								}
#line 4212 "ansicnew.tab.c"
    break;

  case 210:
#line 1611 "ansicnew.y"
                                                { 
									printf("jump_statement : RETURN ';'\n"); 
						  			gencode(RET_IR);
									(yyval.lists).breaklist = NULL;
									(yyval.lists).nextlist = NULL;
									(yyval.lists).continuelist = NULL;
									(yyval.lists).caselist = NULL;
									(yyval.lists).gotolist = NULL;
								}
#line 4226 "ansicnew.tab.c"
    break;

  case 211:
#line 1620 "ansicnew.y"
                                        { printf("jump_statement : RETURN expression ';'\n"); 
								  	gencode(RET_IR, (yyvsp[-1].sym).var, nullptr, nullptr);
								  	(yyval.lists).breaklist = NULL;
								  	(yyval.lists).nextlist = NULL;
								  	(yyval.lists).continuelist = NULL;
									(yyval.lists).caselist = NULL;
									(yyval.lists).gotolist = NULL;
								}
#line 4239 "ansicnew.tab.c"
    break;

  case 212:
#line 1631 "ansicnew.y"
                                        { printf("translation_unit : external_declaration\n"); }
#line 4245 "ansicnew.tab.c"
    break;

  case 213:
#line 1632 "ansicnew.y"
                                                        { printf("translation_unit : translation_unit external_declaration\n"); }
#line 4251 "ansicnew.tab.c"
    break;

  case 214:
#line 1636 "ansicnew.y"
                                        { printf("external_declaration : function_definition\n"); }
#line 4257 "ansicnew.tab.c"
    break;

  case 215:
#line 1637 "ansicnew.y"
                                { printf("external_declaration : declaration\n"); }
#line 4263 "ansicnew.tab.c"
    break;

  case 216:
#line 1641 "ansicnew.y"
                                                                                        { printf("function_definition : declaration_specifiers declarator declaration_list compound_statement\n"); }
#line 4269 "ansicnew.tab.c"
    break;

  case 217:
#line 1642 "ansicnew.y"
                                                        { 
													
													int typ = get_type((yyvsp[-1].sqlist)) | (yyvsp[0].id_data)->typ;
													curr_func = install((yyvsp[0].id_data)->name, typ);
													gencode(PROC_IR, curr_func);
													localsyms = new symboltable();
													enter_scope();
													installarg((yyvsp[0].id_data)->arglist);
													lab_table.clear();
													setargs();	
												}
#line 4285 "ansicnew.tab.c"
    break;

  case 218:
#line 1653 "ansicnew.y"
                                                                                { 
													printf("function_definition :  declaration_specifiers declarator compound_statement\n"); 
													printlocalvars();
													exit_scope();
													curr_func->func_desc.sym_table = localsyms;
													gencode(ENDPROC_IR, curr_func);
													patch_gotos((yyvsp[0].lists).gotolist);
												}
#line 4298 "ansicnew.tab.c"
    break;

  case 219:
#line 1661 "ansicnew.y"
                                                         {printf("function_definition : declarator declaration_list compound_statement\n"); }
#line 4304 "ansicnew.tab.c"
    break;

  case 220:
#line 1662 "ansicnew.y"
                                                                                { 
													int typ = (yyvsp[0].id_data)->typ;
													
													curr_func = install((yyvsp[0].id_data)->name, typ);
													gencode(PROC_IR, curr_func);
													localsyms = new symboltable();
													enter_scope();
													installarg((yyvsp[0].id_data)->arglist);
													lab_table.clear();
													setargs();
													}
#line 4320 "ansicnew.tab.c"
    break;

  case 221:
#line 1673 "ansicnew.y"
                                                {
									printf("function_definition : declarator compound_statement\n"); 
								  	printlocalvars();
								  	exit_scope();
								  	curr_func->func_desc.sym_table = localsyms;
								  	gencode(ENDPROC_IR, curr_func);
									patch_gotos((yyvsp[0].lists).gotolist);
								}
#line 4333 "ansicnew.tab.c"
    break;


#line 4337 "ansicnew.tab.c"

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
#line 1684 "ansicnew.y"

#include <stdio.h>

extern char yytext[];
extern int column;

void yyerror(const char *s)
{ 
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

int main(int argc, char*argv[])
{
	//Tabla de simbolos globales
	string fname;
	sym_table = new symboltable();
	printf("Compilador de ANSI C 1985 version 0.9\n\n");
	//Abrir el archivo para el analisis lexico
	if(argc > 1){
		yyin = fopen(argv[1], "rt");
		fname = argv[1];
	}
	else{
		printf("Uso: %s archivo\n\n", argv[0]);
		exit(1);
	}
	yyparse();
	printvars();
	cout << "\nCodigo Intermedio:\n";
	print_icode();
	print_code(fname);
	return 0;
}
