/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 77 "cfg.y"


#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include "route_struct.h"
#include "globals.h"
#include "route.h"
#include "dprint.h"
#include "sr_module.h"
#include "modparam.h"
#include "ip_addr.h"
#include "resolve.h"
#include "socket_info.h"
#include "name_alias.h"
#include "ut.h"
#include "dset.h"
#include "pvar.h"
#include "blacklists.h"
#include "xlog.h"
#include "tcp_server.h"
#include "tcp_conn.h"
#include "db/db_insertq.h"
#include "bin_interface.h"


#include "config.h"
#ifdef USE_TLS
#include "tls/tls_config.h"
#include "tls/tls_domain.h"
#endif

#ifdef DEBUG_DMALLOC
#include <dmalloc.h>
#endif

/* hack to avoid alloca usage in the generated C file (needed for compiler
 with no built in alloca, like icc*/
#undef _ALLOCA_H


extern int yylex();
static void yyerror(char* s);
static void yyerrorf(char* fmt, ...);
static char* tmp;
static int i_tmp;
static void* cmd_tmp;
static struct socket_id* lst_tmp;
static int rt;  /* Type of route block for find_export */
static str* str_tmp;
static str s_tmp;
static str tstr;
static struct ip_addr* ip_tmp;
static pv_spec_t *spec;
static pv_elem_t *pvmodel;
static struct bl_rule *bl_head = 0;
static struct bl_rule *bl_tail = 0;
static struct stat statf;

action_elem_t elems[MAX_ACTION_ELEMS];
static action_elem_t route_elems[MAX_ACTION_ELEMS];
action_elem_t *a_tmp;

static inline void warn(char* s);
static struct socket_id* mk_listen_id(char*, int, int);
static struct socket_id* set_listen_id_adv(struct socket_id *, char *, int);

static char *mpath=NULL;
static char mpath_buf[256];
static int  mpath_len = 0;

extern int line;

#define mk_action0(_res, _type, _p1_type, _p2_type, _p1, _p2) \
	do { \
		_res = mk_action(_type, 0, 0, line); \
	} while(0)
#define mk_action1(_res, _type, _p1_type, _p1) \
	do { \
		elems[0].type = _p1_type; \
		elems[0].u.data = _p1; \
		_res = mk_action(_type, 1, elems, line); \
	} while(0)
#define	mk_action2(_res, _type, _p1_type, _p2_type, _p1, _p2) \
	do { \
		elems[0].type = _p1_type; \
		elems[0].u.data = _p1; \
		elems[1].type = _p2_type; \
		elems[1].u.data = _p2; \
		_res = mk_action(_type, 2, elems, line); \
	} while(0)
#define mk_action3(_res, _type, _p1_type, _p2_type, _p3_type, _p1, _p2, _p3) \
	do { \
		elems[0].type = _p1_type; \
		elems[0].u.data = _p1; \
		elems[1].type = _p2_type; \
		elems[1].u.data = _p2; \
		elems[2].type = _p3_type; \
		elems[2].u.data = _p3; \
		_res = mk_action(_type, 3, elems, line); \
	} while(0)



/* Line 268 of yacc.c  */
#line 185 "cfg.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FORWARD = 258,
     SEND = 259,
     DROP = 260,
     EXIT = 261,
     RETURN = 262,
     LOG_TOK = 263,
     ERROR = 264,
     ROUTE = 265,
     ROUTE_FAILURE = 266,
     ROUTE_ONREPLY = 267,
     ROUTE_BRANCH = 268,
     ROUTE_ERROR = 269,
     ROUTE_LOCAL = 270,
     ROUTE_STARTUP = 271,
     ROUTE_TIMER = 272,
     ROUTE_EVENT = 273,
     SET_HOST = 274,
     SET_HOSTPORT = 275,
     PREFIX = 276,
     STRIP = 277,
     STRIP_TAIL = 278,
     APPEND_BRANCH = 279,
     REMOVE_BRANCH = 280,
     PV_PRINTF = 281,
     SET_USER = 282,
     SET_USERPASS = 283,
     SET_PORT = 284,
     SET_URI = 285,
     REVERT_URI = 286,
     SET_DSTURI = 287,
     RESET_DSTURI = 288,
     ISDSTURISET = 289,
     FORCE_RPORT = 290,
     FORCE_LOCAL_RPORT = 291,
     FORCE_TCP_ALIAS = 292,
     IF = 293,
     ELSE = 294,
     SWITCH = 295,
     CASE = 296,
     DEFAULT = 297,
     SBREAK = 298,
     WHILE = 299,
     SET_ADV_ADDRESS = 300,
     SET_ADV_PORT = 301,
     FORCE_SEND_SOCKET = 302,
     SERIALIZE_BRANCHES = 303,
     NEXT_BRANCHES = 304,
     USE_BLACKLIST = 305,
     UNUSE_BLACKLIST = 306,
     MAX_LEN = 307,
     SETDEBUG = 308,
     SETFLAG = 309,
     RESETFLAG = 310,
     ISFLAGSET = 311,
     SETBFLAG = 312,
     RESETBFLAG = 313,
     ISBFLAGSET = 314,
     SETSFLAG = 315,
     RESETSFLAG = 316,
     ISSFLAGSET = 317,
     METHOD = 318,
     URI = 319,
     FROM_URI = 320,
     TO_URI = 321,
     SRCIP = 322,
     SRCPORT = 323,
     DSTIP = 324,
     DSTPORT = 325,
     PROTO = 326,
     AF = 327,
     MYSELF = 328,
     MSGLEN = 329,
     UDP = 330,
     TCP = 331,
     TLS = 332,
     SCTP = 333,
     NULLV = 334,
     CACHE_STORE = 335,
     CACHE_FETCH = 336,
     CACHE_COUNTER_FETCH = 337,
     CACHE_REMOVE = 338,
     CACHE_ADD = 339,
     CACHE_SUB = 340,
     CACHE_RAW_QUERY = 341,
     XDBG = 342,
     XLOG = 343,
     XLOG_BUF_SIZE = 344,
     XLOG_FORCE_COLOR = 345,
     RAISE_EVENT = 346,
     SUBSCRIBE_EVENT = 347,
     CONSTRUCT_URI = 348,
     GET_TIMESTAMP = 349,
     SCRIPT_TRACE = 350,
     DEBUG = 351,
     FORK = 352,
     LOGSTDERROR = 353,
     LOGFACILITY = 354,
     LOGNAME = 355,
     AVP_ALIASES = 356,
     LISTEN = 357,
     BIN_LISTEN = 358,
     BIN_CHILDREN = 359,
     ALIAS = 360,
     AUTO_ALIASES = 361,
     DNS = 362,
     REV_DNS = 363,
     DNS_TRY_IPV6 = 364,
     DNS_RETR_TIME = 365,
     DNS_RETR_NO = 366,
     DNS_SERVERS_NO = 367,
     DNS_USE_SEARCH = 368,
     MAX_WHILE_LOOPS = 369,
     PORT = 370,
     CHILDREN = 371,
     CHECK_VIA = 372,
     MEMLOG = 373,
     MEMDUMP = 374,
     EXECMSGTHRESHOLD = 375,
     EXECDNSTHRESHOLD = 376,
     TCPTHRESHOLD = 377,
     EVENT_SHM_THRESHOLD = 378,
     EVENT_PKG_THRESHOLD = 379,
     QUERYBUFFERSIZE = 380,
     QUERYFLUSHTIME = 381,
     SIP_WARNING = 382,
     SOCK_MODE = 383,
     SOCK_USER = 384,
     SOCK_GROUP = 385,
     UNIX_SOCK = 386,
     UNIX_SOCK_CHILDREN = 387,
     UNIX_TX_TIMEOUT = 388,
     SERVER_SIGNATURE = 389,
     SERVER_HEADER = 390,
     USER_AGENT_HEADER = 391,
     LOADMODULE = 392,
     MPATH = 393,
     MODPARAM = 394,
     MAXBUFFER = 395,
     USER = 396,
     GROUP = 397,
     CHROOT = 398,
     WDIR = 399,
     MHOMED = 400,
     DISABLE_TCP = 401,
     ASYNC_TCP = 402,
     ASYNC_TCP_LOCAL_CON_TIMEOUT = 403,
     ASYNC_TCP_LOCAL_WRITE_TIMEOUT = 404,
     ASYNC_TCP_MAX_POSTPONED_CHUNKS = 405,
     TCP_ACCEPT_ALIASES = 406,
     TCP_CHILDREN = 407,
     TCP_CONNECT_TIMEOUT = 408,
     TCP_SEND_TIMEOUT = 409,
     TCP_CON_LIFETIME = 410,
     TCP_LISTEN_BACKLOG = 411,
     TCP_POLL_METHOD = 412,
     TCP_MAX_CONNECTIONS = 413,
     TCP_OPT_CRLF_PINGPONG = 414,
     TCP_NO_NEW_CONN_BFLAG = 415,
     TCP_KEEPALIVE = 416,
     TCP_KEEPCOUNT = 417,
     TCP_KEEPIDLE = 418,
     TCP_KEEPINTERVAL = 419,
     TCP_MAX_MSG_CHUNKS = 420,
     TCP_MAX_MSG_TIME = 421,
     DISABLE_TLS = 422,
     TLSLOG = 423,
     TLS_PORT_NO = 424,
     TLS_METHOD = 425,
     TLS_HANDSHAKE_TIMEOUT = 426,
     TLS_SEND_TIMEOUT = 427,
     TLS_SERVER_DOMAIN = 428,
     TLS_CLIENT_DOMAIN = 429,
     TLS_CLIENT_DOMAIN_AVP = 430,
     SSLv23 = 431,
     SSLv2 = 432,
     SSLv3 = 433,
     TLSv1 = 434,
     TLS_VERIFY_CLIENT = 435,
     TLS_VERIFY_SERVER = 436,
     TLS_REQUIRE_CLIENT_CERTIFICATE = 437,
     TLS_CERTIFICATE = 438,
     TLS_PRIVATE_KEY = 439,
     TLS_CA_LIST = 440,
     TLS_CIPHERS_LIST = 441,
     ADVERTISED_ADDRESS = 442,
     ADVERTISED_PORT = 443,
     DISABLE_CORE = 444,
     OPEN_FD_LIMIT = 445,
     MCAST_LOOPBACK = 446,
     MCAST_TTL = 447,
     TOS = 448,
     DISABLE_DNS_FAILOVER = 449,
     DISABLE_DNS_BLACKLIST = 450,
     DST_BLACKLIST = 451,
     DISABLE_STATELESS_FWD = 452,
     DB_VERSION_TABLE = 453,
     DB_DEFAULT_URL = 454,
     DISABLE_503_TRANSLATION = 455,
     EQUAL = 456,
     EQUAL_T = 457,
     GT = 458,
     LT = 459,
     GTE = 460,
     LTE = 461,
     DIFF = 462,
     MATCH = 463,
     NOTMATCH = 464,
     COLONEQ = 465,
     PLUSEQ = 466,
     MINUSEQ = 467,
     SLASHEQ = 468,
     MULTEQ = 469,
     MODULOEQ = 470,
     BANDEQ = 471,
     BOREQ = 472,
     BXOREQ = 473,
     AND = 474,
     OR = 475,
     BRSHIFT = 476,
     BLSHIFT = 477,
     BXOR = 478,
     BAND = 479,
     BOR = 480,
     MODULO = 481,
     MULT = 482,
     SLASH = 483,
     MINUS = 484,
     PLUS = 485,
     BNOT = 486,
     NOT = 487,
     NUMBER = 488,
     ZERO = 489,
     ID = 490,
     STRING = 491,
     SCRIPTVAR = 492,
     IPV6ADDR = 493,
     COMMA = 494,
     SEMICOLON = 495,
     RPAREN = 496,
     LPAREN = 497,
     LBRACE = 498,
     RBRACE = 499,
     LBRACK = 500,
     RBRACK = 501,
     AS = 502,
     USE_CHILDREN = 503,
     DOT = 504,
     CR = 505,
     COLON = 506,
     ANY = 507,
     SCRIPTVARERR = 508
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 190 "cfg.y"

	long intval;
	unsigned long uval;
	char* strval;
	struct expr* expr;
	struct action* action;
	struct net* ipnet;
	struct ip_addr* ipaddr;
	struct socket_id* sockid;
	struct _pv_spec *specval;



/* Line 293 of yacc.c  */
#line 488 "cfg.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 500 "cfg.tab.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  223
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5423

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  254
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  659
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1367

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   508

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
     245,   246,   247,   248,   249,   250,   251,   252,   253
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    15,    17,    18,
      21,    22,    25,    26,    29,    30,    33,    34,    37,    38,
      41,    42,    45,    46,    49,    50,    53,    55,    57,    59,
      61,    63,    65,    67,    69,    71,    73,    75,    77,    80,
      83,    85,    89,    93,    99,   103,   105,   108,   110,   114,
     118,   124,   130,   138,   140,   143,   153,   164,   168,   170,
     173,   177,   181,   185,   189,   193,   197,   201,   205,   209,
     213,   217,   221,   225,   229,   233,   237,   241,   244,   248,
     251,   255,   258,   262,   265,   269,   272,   276,   280,   284,
     288,   292,   296,   300,   304,   308,   312,   316,   320,   324,
     328,   332,   336,   340,   344,   348,   352,   356,   360,   364,
     368,   372,   376,   380,   384,   388,   392,   396,   400,   404,
     408,   412,   416,   420,   424,   428,   432,   436,   440,   444,
     448,   452,   456,   460,   464,   468,   472,   476,   480,   484,
     488,   492,   496,   500,   504,   508,   512,   516,   520,   524,
     528,   532,   536,   540,   544,   548,   552,   556,   560,   564,
     568,   572,   576,   580,   584,   588,   592,   596,   600,   604,
     608,   612,   616,   620,   624,   628,   632,   636,   640,   644,
     648,   652,   656,   660,   664,   668,   672,   676,   680,   684,
     688,   692,   696,   700,   704,   708,   712,   716,   720,   724,
     728,   732,   736,   740,   744,   748,   750,   752,   756,   760,
     764,   768,   772,   776,   780,   784,   788,   792,   796,   800,
     806,   810,   814,   818,   822,   826,   830,   834,   838,   842,
     846,   850,   854,   858,   862,   866,   870,   874,   878,   882,
     886,   890,   894,   898,   902,   906,   909,   913,   916,   924,
     928,   932,   936,   940,   944,   948,   952,   955,   958,   961,
     970,   979,   982,   984,   986,   994,   996,   998,  1002,  1003,
    1014,  1015,  1026,  1027,  1036,  1038,  1041,  1043,  1046,  1050,
    1054,  1058,  1062,  1066,  1070,  1074,  1078,  1082,  1086,  1090,
    1094,  1098,  1102,  1106,  1110,  1114,  1118,  1122,  1126,  1130,
    1134,  1138,  1142,  1146,  1150,  1154,  1158,  1162,  1166,  1170,
    1174,  1176,  1178,  1180,  1185,  1193,  1196,  1204,  1207,  1212,
    1220,  1223,  1231,  1234,  1239,  1242,  1247,  1250,  1255,  1258,
    1268,  1271,  1279,  1282,  1286,  1290,  1293,  1297,  1301,  1303,
    1305,  1307,  1309,  1311,  1313,  1315,  1317,  1319,  1321,  1323,
    1325,  1327,  1329,  1331,  1333,  1335,  1337,  1339,  1341,  1343,
    1345,  1347,  1351,  1355,  1359,  1363,  1367,  1371,  1375,  1379,
    1382,  1386,  1390,  1394,  1398,  1402,  1406,  1410,  1414,  1418,
    1421,  1425,  1429,  1432,  1436,  1440,  1443,  1447,  1451,  1454,
    1458,  1462,  1465,  1469,  1473,  1477,  1480,  1484,  1488,  1492,
    1495,  1499,  1503,  1507,  1510,  1514,  1518,  1522,  1526,  1529,
    1533,  1537,  1539,  1543,  1545,  1547,  1549,  1553,  1557,  1559,
    1561,  1563,  1565,  1567,  1569,  1571,  1573,  1575,  1577,  1579,
    1581,  1583,  1585,  1587,  1589,  1593,  1597,  1601,  1605,  1609,
    1613,  1617,  1621,  1625,  1629,  1632,  1636,  1640,  1644,  1648,
    1650,  1652,  1654,  1658,  1661,  1663,  1667,  1670,  1673,  1675,
    1678,  1681,  1683,  1685,  1687,  1690,  1692,  1695,  1699,  1705,
    1709,  1717,  1720,  1722,  1725,  1727,  1734,  1740,  1745,  1749,
    1756,  1762,  1767,  1771,  1775,  1778,  1780,  1784,  1786,  1790,
    1792,  1794,  1796,  1800,  1804,  1808,  1813,  1817,  1820,  1825,
    1830,  1837,  1840,  1845,  1849,  1851,  1855,  1857,  1862,  1867,
    1871,  1873,  1878,  1885,  1888,  1893,  1898,  1902,  1905,  1910,
    1915,  1918,  1923,  1928,  1931,  1936,  1941,  1944,  1949,  1954,
    1957,  1962,  1967,  1970,  1975,  1980,  1983,  1990,  1997,  2002,
    2007,  2010,  2017,  2024,  2029,  2034,  2037,  2044,  2051,  2056,
    2061,  2064,  2071,  2074,  2079,  2084,  2091,  2094,  2099,  2104,
    2107,  2112,  2117,  2120,  2125,  2130,  2133,  2138,  2143,  2146,
    2151,  2158,  2163,  2167,  2169,  2174,  2179,  2186,  2193,  2198,
    2201,  2206,  2211,  2214,  2219,  2224,  2227,  2232,  2237,  2240,
    2245,  2250,  2253,  2258,  2262,  2264,  2269,  2272,  2277,  2281,
    2283,  2287,  2289,  2293,  2295,  2299,  2301,  2306,  2310,  2312,
    2317,  2322,  2327,  2330,  2335,  2340,  2343,  2348,  2353,  2356,
    2361,  2366,  2369,  2373,  2378,  2381,  2386,  2391,  2394,  2399,
    2404,  2407,  2416,  2427,  2438,  2445,  2454,  2463,  2474,  2485,
    2496,  2507,  2516,  2523,  2527,  2532,  2537,  2540,  2545,  2550,
    2557,  2562,  2569,  2578,  2585,  2594,  2609,  2616,  2620,  2627
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     255,     0,    -1,   256,    -1,   256,   257,    -1,   257,    -1,
     256,     1,    -1,   277,    -1,   278,    -1,    -1,   258,   293,
      -1,    -1,   259,   294,    -1,    -1,   260,   295,    -1,    -1,
     261,   296,    -1,    -1,   262,   297,    -1,    -1,   263,   298,
      -1,    -1,   264,   299,    -1,    -1,   265,   300,    -1,    -1,
     266,   301,    -1,   250,    -1,   279,    -1,   236,    -1,   314,
      -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,   252,
      -1,   233,    -1,   252,    -1,   233,    -1,   230,   233,    -1,
     229,   233,    -1,   267,    -1,   267,   251,   269,    -1,   268,
     251,   267,    -1,   268,   251,   267,   251,   269,    -1,   267,
     251,     1,    -1,   271,    -1,   271,   272,    -1,   271,    -1,
     271,   248,   233,    -1,   271,   247,   267,    -1,   271,   247,
     267,   248,   233,    -1,   271,   247,   267,   251,   269,    -1,
     271,   247,   267,   251,   269,   248,   233,    -1,   273,    -1,
     273,   274,    -1,   242,   268,   239,   312,   239,   269,   239,
     236,   241,    -1,   232,   242,   268,   239,   312,   239,   269,
     239,   236,   241,    -1,   276,   239,   275,    -1,   275,    -1,
     276,     1,    -1,    96,   201,   270,    -1,    96,   201,     1,
      -1,    97,   201,   233,    -1,    97,   201,     1,    -1,    98,
     201,   233,    -1,    98,   201,     1,    -1,    99,   201,   235,
      -1,    99,   201,     1,    -1,   100,   201,   236,    -1,   100,
     201,     1,    -1,   101,   201,   236,    -1,   101,   201,     1,
      -1,   107,   201,   233,    -1,   107,   201,     1,    -1,   108,
     201,   233,    -1,   108,   201,     1,    -1,   109,   201,   233,
      -1,   109,     1,    -1,   110,   201,   233,    -1,   110,     1,
      -1,   111,   201,   233,    -1,   111,     1,    -1,   112,   201,
     233,    -1,   112,     1,    -1,   113,   201,   233,    -1,   113,
       1,    -1,   115,   201,   233,    -1,   115,   201,     1,    -1,
     114,   201,   233,    -1,   114,   201,     1,    -1,   140,   201,
     233,    -1,   140,   201,     1,    -1,   116,   201,   233,    -1,
     116,   201,     1,    -1,   117,   201,   233,    -1,   117,   201,
       1,    -1,   118,   201,   233,    -1,   118,   201,     1,    -1,
     119,   201,   233,    -1,   119,   201,     1,    -1,   120,   201,
     233,    -1,   120,   201,     1,    -1,   121,   201,   233,    -1,
     121,   201,     1,    -1,   122,   201,   233,    -1,   122,   201,
       1,    -1,   123,   201,   233,    -1,   123,   201,     1,    -1,
     124,   201,   233,    -1,   124,   201,     1,    -1,   125,   201,
     233,    -1,   125,   201,     1,    -1,   126,   201,   233,    -1,
     126,   201,     1,    -1,   127,   201,   233,    -1,   127,   201,
       1,    -1,   141,   201,   236,    -1,   141,   201,   235,    -1,
     141,   201,     1,    -1,   142,   201,   236,    -1,   142,   201,
     235,    -1,   142,   201,     1,    -1,   143,   201,   236,    -1,
     143,   201,   235,    -1,   143,   201,     1,    -1,   144,   201,
     236,    -1,   144,   201,   235,    -1,   144,   201,     1,    -1,
     145,   201,   233,    -1,   145,   201,     1,    -1,   146,   201,
     233,    -1,   146,   201,     1,    -1,   147,   201,   233,    -1,
     147,   201,     1,    -1,   148,   201,   233,    -1,   148,   201,
       1,    -1,   149,   201,   233,    -1,   149,   201,     1,    -1,
     150,   201,   233,    -1,   150,   201,     1,    -1,   151,   201,
     233,    -1,   151,   201,     1,    -1,   152,   201,   233,    -1,
     152,   201,     1,    -1,   153,   201,   233,    -1,   153,   201,
       1,    -1,   154,   201,   233,    -1,   154,   201,     1,    -1,
     155,   201,   233,    -1,   155,   201,     1,    -1,   156,   201,
     233,    -1,   156,   201,     1,    -1,   157,   201,   235,    -1,
     157,   201,   236,    -1,   157,   201,     1,    -1,   158,   201,
     233,    -1,   158,   201,     1,    -1,   159,   201,   233,    -1,
     159,   201,     1,    -1,   160,   201,   233,    -1,   160,   201,
     235,    -1,   160,   201,     1,    -1,   161,   201,   233,    -1,
     161,   201,     1,    -1,   165,   201,   233,    -1,   165,   201,
       1,    -1,   166,   201,   233,    -1,   166,   201,     1,    -1,
     162,   201,   233,    -1,   162,   201,     1,    -1,   163,   201,
     233,    -1,   163,   201,     1,    -1,   164,   201,   233,    -1,
     164,   201,     1,    -1,   167,   201,   233,    -1,   167,   201,
       1,    -1,   168,   201,   233,    -1,   168,   201,     1,    -1,
     169,   201,   233,    -1,   169,   201,     1,    -1,   170,   201,
     176,    -1,   170,   201,   177,    -1,   170,   201,   178,    -1,
     170,   201,   179,    -1,   170,   201,     1,    -1,   180,   201,
     233,    -1,   180,   201,     1,    -1,   181,   201,   233,    -1,
     181,   201,     1,    -1,   182,   201,   233,    -1,   182,   201,
       1,    -1,   183,   201,   236,    -1,   183,   201,     1,    -1,
     184,   201,   236,    -1,   184,   201,     1,    -1,   185,   201,
     236,    -1,   185,   201,     1,    -1,   186,   201,   236,    -1,
     186,   201,     1,    -1,   171,   201,   233,    -1,   171,   201,
       1,    -1,   172,   201,   233,    -1,   172,   201,     1,    -1,
     175,   201,   236,    -1,   175,   201,     1,    -1,   283,    -1,
     285,    -1,   134,   201,   233,    -1,   134,   201,     1,    -1,
     135,   201,   236,    -1,   135,   201,     1,    -1,   136,   201,
     236,    -1,   136,   201,     1,    -1,    89,   201,   233,    -1,
      90,   201,   233,    -1,    89,   201,     1,    -1,    90,   201,
       1,    -1,   102,   201,   274,    -1,   102,   201,     1,    -1,
     103,   201,   267,   251,   269,    -1,   103,   201,     1,    -1,
     104,   201,   233,    -1,   104,   201,     1,    -1,   105,   201,
     272,    -1,   105,   201,     1,    -1,   106,   201,   233,    -1,
     106,   201,     1,    -1,   187,   201,   267,    -1,   187,   201,
       1,    -1,   188,   201,   233,    -1,   188,   201,     1,    -1,
     189,   201,   233,    -1,   189,   201,     1,    -1,   190,   201,
     233,    -1,   190,   201,     1,    -1,   191,   201,   233,    -1,
     191,   201,     1,    -1,   192,   201,   233,    -1,   192,   201,
       1,    -1,   193,   201,   233,    -1,   193,   201,   235,    -1,
     193,   201,     1,    -1,   138,   201,   236,    -1,   138,   201,
       1,    -1,   194,   201,   233,    -1,   194,     1,    -1,   195,
     201,   233,    -1,   195,     1,    -1,   196,   201,   235,   251,
     243,   276,   244,    -1,   197,   201,   233,    -1,   198,   201,
     236,    -1,   198,   201,     1,    -1,   199,   201,   236,    -1,
     199,   201,     1,    -1,   200,   201,   233,    -1,   200,   201,
       1,    -1,     1,   201,    -1,   137,   236,    -1,   137,     1,
      -1,   139,   242,   236,   239,   236,   239,   236,   241,    -1,
     139,   242,   236,   239,   236,   239,   270,   241,    -1,   139,
       1,    -1,   280,    -1,   282,    -1,   233,   249,   233,   249,
     233,   249,   233,    -1,   238,    -1,   281,    -1,   245,   281,
     246,    -1,    -1,   173,   245,   279,   251,   269,   246,   284,
     243,   288,   244,    -1,    -1,   174,   245,   279,   251,   269,
     246,   286,   243,   289,   244,    -1,    -1,   174,   245,   236,
     246,   287,   243,   289,   244,    -1,   290,    -1,   288,   290,
      -1,   291,    -1,   289,   291,    -1,   170,   201,   176,    -1,
     170,   201,   177,    -1,   170,   201,   178,    -1,   170,   201,
     179,    -1,   170,   201,     1,    -1,   183,   201,   236,    -1,
     183,   201,     1,    -1,   184,   201,   236,    -1,   184,   201,
       1,    -1,   185,   201,   236,    -1,   185,   201,     1,    -1,
     186,   201,   236,    -1,   186,   201,     1,    -1,   180,   201,
     233,    -1,   180,   201,     1,    -1,   182,   201,   233,    -1,
     182,   201,     1,    -1,   170,   201,   176,    -1,   170,   201,
     177,    -1,   170,   201,   178,    -1,   170,   201,   179,    -1,
     170,   201,     1,    -1,   183,   201,   236,    -1,   183,   201,
       1,    -1,   184,   201,   236,    -1,   184,   201,     1,    -1,
     185,   201,   236,    -1,   185,   201,     1,    -1,   186,   201,
     236,    -1,   186,   201,     1,    -1,   181,   201,   233,    -1,
     181,   201,     1,    -1,   235,    -1,   233,    -1,   236,    -1,
      10,   243,   320,   244,    -1,    10,   245,   292,   246,   243,
     320,   244,    -1,    10,     1,    -1,    11,   245,   292,   246,
     243,   320,   244,    -1,    11,     1,    -1,    12,   243,   320,
     244,    -1,    12,   245,   292,   246,   243,   320,   244,    -1,
      12,     1,    -1,    13,   245,   292,   246,   243,   320,   244,
      -1,    13,     1,    -1,    14,   243,   320,   244,    -1,    14,
       1,    -1,    15,   243,   320,   244,    -1,    15,     1,    -1,
      16,   243,   320,   244,    -1,    16,     1,    -1,    17,   245,
     292,   239,   233,   246,   243,   320,   244,    -1,    17,     1,
      -1,    18,   245,   292,   246,   243,   320,   244,    -1,    18,
       1,    -1,   302,   219,   302,    -1,   302,   220,   302,    -1,
     232,   302,    -1,   242,   302,   241,    -1,   245,   316,   246,
      -1,   310,    -1,   202,    -1,   207,    -1,   203,    -1,   204,
      -1,   205,    -1,   206,    -1,   208,    -1,   209,    -1,   303,
      -1,   304,    -1,   303,    -1,   304,    -1,   305,    -1,    64,
      -1,    65,    -1,    66,    -1,   237,    -1,   253,    -1,   311,
      -1,   318,    -1,   270,    -1,   309,    -1,   308,   307,   314,
      -1,    69,   303,   312,    -1,    69,   307,   314,    -1,    67,
     303,   312,    -1,    67,   307,   314,    -1,    63,   307,   236,
      -1,    63,   307,   235,    -1,    63,   307,     1,    -1,    63,
       1,    -1,   309,   307,   309,    -1,   309,   307,   236,    -1,
     309,   307,   235,    -1,   309,   306,   270,    -1,   309,   303,
      73,    -1,   309,   303,    79,    -1,   308,   307,   236,    -1,
     308,   303,    73,    -1,   308,   307,     1,    -1,   308,     1,
      -1,    68,   306,   233,    -1,    68,   306,     1,    -1,    68,
       1,    -1,    70,   306,   233,    -1,    70,   306,     1,    -1,
      70,     1,    -1,    71,   306,   268,    -1,    71,   306,     1,
      -1,    71,     1,    -1,    72,   306,   233,    -1,    72,   306,
       1,    -1,    72,     1,    -1,    74,   306,   233,    -1,    74,
     306,    52,    -1,    74,   306,     1,    -1,    74,     1,    -1,
      67,   307,   236,    -1,    67,   303,    73,    -1,    67,   307,
       1,    -1,    67,     1,    -1,    69,   307,   236,    -1,    69,
     303,    73,    -1,    69,   307,     1,    -1,    69,     1,    -1,
      73,   303,   308,    -1,    73,   303,    67,    -1,    73,   303,
      69,    -1,    73,   303,     1,    -1,    73,     1,    -1,   279,
     228,   279,    -1,   279,   228,   233,    -1,   279,    -1,   279,
     228,     1,    -1,   249,    -1,   229,    -1,   235,    -1,   314,
     313,   235,    -1,   314,   249,     1,    -1,   201,    -1,   210,
      -1,   211,    -1,   212,    -1,   213,    -1,   214,    -1,   215,
      -1,   216,    -1,   217,    -1,   218,    -1,   270,    -1,   236,
      -1,   235,    -1,   309,    -1,   311,    -1,   331,    -1,   316,
     230,   316,    -1,   316,   229,   316,    -1,   316,   227,   316,
      -1,   316,   228,   316,    -1,   316,   226,   316,    -1,   316,
     224,   316,    -1,   316,   225,   316,    -1,   316,   223,   316,
      -1,   316,   222,   316,    -1,   316,   221,   316,    -1,   231,
     316,    -1,   242,   316,   241,    -1,   309,   315,   316,    -1,
     309,   201,    79,    -1,   309,   210,    79,    -1,   331,    -1,
     322,    -1,   317,    -1,   243,   320,   244,    -1,   243,   244,
      -1,   321,    -1,   243,   320,   244,    -1,   243,   244,    -1,
     320,   321,    -1,   321,    -1,   320,     1,    -1,   331,   240,
      -1,   322,    -1,   323,    -1,   324,    -1,   317,   240,    -1,
     240,    -1,   331,     1,    -1,    38,   302,   319,    -1,    38,
     302,   319,    39,   319,    -1,    44,   302,   319,    -1,    40,
     242,   309,   241,   243,   325,   244,    -1,   326,   328,    -1,
     326,    -1,   326,   327,    -1,   327,    -1,    41,   270,   251,
     320,    43,   240,    -1,    41,   270,   251,    43,   240,    -1,
      41,   270,   251,   320,    -1,    41,   270,   251,    -1,    41,
     236,   251,   320,    43,   240,    -1,    41,   236,   251,    43,
     240,    -1,    41,   236,   251,   320,    -1,    41,   236,   251,
      -1,    42,   251,   320,    -1,    42,   251,    -1,   236,    -1,
     329,   239,   236,    -1,   233,    -1,   329,   239,   233,    -1,
     236,    -1,   233,    -1,   309,    -1,   330,   239,   236,    -1,
     330,   239,   233,    -1,   330,   239,   309,    -1,     3,   242,
     236,   241,    -1,     3,   242,   241,    -1,     3,     1,    -1,
       3,   242,     1,   241,    -1,     4,   242,   236,   241,    -1,
       4,   242,   236,   239,   236,   241,    -1,     4,     1,    -1,
       4,   242,     1,   241,    -1,     5,   242,   241,    -1,     5,
      -1,     6,   242,   241,    -1,     6,    -1,     7,   242,   270,
     241,    -1,     7,   242,   309,   241,    -1,     7,   242,   241,
      -1,     7,    -1,     8,   242,   236,   241,    -1,     8,   242,
     270,   239,   236,   241,    -1,     8,     1,    -1,     8,   242,
       1,   241,    -1,    53,   242,   270,   241,    -1,    53,   242,
     241,    -1,    53,     1,    -1,    54,   242,   233,   241,    -1,
      54,   242,   235,   241,    -1,    54,     1,    -1,    55,   242,
     233,   241,    -1,    55,   242,   235,   241,    -1,    55,     1,
      -1,    56,   242,   233,   241,    -1,    56,   242,   235,   241,
      -1,    56,     1,    -1,    60,   242,   233,   241,    -1,    60,
     242,   235,   241,    -1,    60,     1,    -1,    61,   242,   233,
     241,    -1,    61,   242,   235,   241,    -1,    61,     1,    -1,
      62,   242,   233,   241,    -1,    62,   242,   235,   241,    -1,
      62,     1,    -1,    57,   242,   233,   239,   233,   241,    -1,
      57,   242,   233,   239,   235,   241,    -1,    57,   242,   233,
     241,    -1,    57,   242,   235,   241,    -1,    57,     1,    -1,
      58,   242,   233,   239,   233,   241,    -1,    58,   242,   233,
     239,   235,   241,    -1,    58,   242,   233,   241,    -1,    58,
     242,   235,   241,    -1,    58,     1,    -1,    59,   242,   233,
     239,   233,   241,    -1,    59,   242,   233,   239,   235,   241,
      -1,    59,   242,   233,   241,    -1,    59,   242,   235,   241,
      -1,    59,     1,    -1,     9,   242,   236,   239,   236,   241,
      -1,     9,     1,    -1,     9,   242,     1,   241,    -1,    10,
     242,   292,   241,    -1,    10,   242,   292,   239,   330,   241,
      -1,    10,     1,    -1,    10,   242,     1,   241,    -1,    19,
     242,   236,   241,    -1,    19,     1,    -1,    19,   242,     1,
     241,    -1,    21,   242,   236,   241,    -1,    21,     1,    -1,
      21,   242,     1,   241,    -1,    23,   242,   233,   241,    -1,
      23,     1,    -1,    23,   242,     1,   241,    -1,    22,   242,
     233,   241,    -1,    22,     1,    -1,    22,   242,     1,   241,
      -1,    24,   242,   236,   239,   236,   241,    -1,    24,   242,
     236,   241,    -1,    24,   242,   241,    -1,    24,    -1,    25,
     242,   233,   241,    -1,    25,   242,   309,   241,    -1,    26,
     242,   236,   239,   236,   241,    -1,    26,   242,   309,   239,
     236,   241,    -1,    20,   242,   236,   241,    -1,    20,     1,
      -1,    20,   242,     1,   241,    -1,    29,   242,   236,   241,
      -1,    29,     1,    -1,    29,   242,     1,   241,    -1,    27,
     242,   236,   241,    -1,    27,     1,    -1,    27,   242,     1,
     241,    -1,    28,   242,   236,   241,    -1,    28,     1,    -1,
      28,   242,     1,   241,    -1,    30,   242,   236,   241,    -1,
      30,     1,    -1,    30,   242,     1,   241,    -1,    31,   242,
     241,    -1,    31,    -1,    32,   242,   236,   241,    -1,    32,
       1,    -1,    32,   242,     1,   241,    -1,    33,   242,   241,
      -1,    33,    -1,    34,   242,   241,    -1,    34,    -1,    35,
     242,   241,    -1,    35,    -1,    36,   242,   241,    -1,    36,
      -1,    37,   242,   233,   241,    -1,    37,   242,   241,    -1,
      37,    -1,    37,   242,     1,   241,    -1,    45,   242,   267,
     241,    -1,    45,   242,     1,   241,    -1,    45,     1,    -1,
      46,   242,   233,   241,    -1,    46,   242,     1,   241,    -1,
      46,     1,    -1,    47,   242,   271,   241,    -1,    47,   242,
       1,   241,    -1,    47,     1,    -1,    48,   242,   233,   241,
      -1,    48,   242,     1,   241,    -1,    48,     1,    -1,    49,
     242,   241,    -1,    49,   242,     1,   241,    -1,    49,     1,
      -1,    50,   242,   236,   241,    -1,    50,   242,     1,   241,
      -1,    50,     1,    -1,    51,   242,   236,   241,    -1,    51,
     242,     1,   241,    -1,    51,     1,    -1,    80,   242,   236,
     239,   236,   239,   236,   241,    -1,    80,   242,   236,   239,
     236,   239,   236,   239,   233,   241,    -1,    80,   242,   236,
     239,   236,   239,   236,   239,   309,   241,    -1,    83,   242,
     236,   239,   236,   241,    -1,    81,   242,   236,   239,   236,
     239,   309,   241,    -1,    82,   242,   236,   239,   236,   239,
     309,   241,    -1,    84,   242,   236,   239,   236,   239,   233,
     239,   233,   241,    -1,    84,   242,   236,   239,   236,   239,
     309,   239,   233,   241,    -1,    85,   242,   236,   239,   236,
     239,   233,   239,   233,   241,    -1,    85,   242,   236,   239,
     236,   239,   309,   239,   233,   241,    -1,    86,   242,   236,
     239,   236,   239,   236,   241,    -1,    86,   242,   236,   239,
     236,   241,    -1,   235,   242,   241,    -1,   235,   242,   329,
     241,    -1,   235,   242,     1,   241,    -1,   235,     1,    -1,
      87,   242,   236,   241,    -1,    88,   242,   236,   241,    -1,
      88,   242,   236,   239,   236,   241,    -1,    91,   242,   236,
     241,    -1,    91,   242,   236,   239,   309,   241,    -1,    91,
     242,   236,   239,   309,   239,   309,   241,    -1,    92,   242,
     236,   239,   236,   241,    -1,    92,   242,   236,   239,   236,
     239,   233,   241,    -1,    93,   242,   236,   239,   236,   239,
     236,   239,   236,   239,   236,   239,   309,   241,    -1,    94,
     242,   309,   239,   309,   241,    -1,    95,   242,   241,    -1,
      95,   242,   233,   239,   236,   241,    -1,    95,   242,   233,
     239,   236,   239,   236,   241,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   490,   490,   493,   494,   495,   498,   499,   500,   500,
     501,   501,   502,   502,   503,   503,   504,   504,   505,   505,
     506,   506,   507,   507,   508,   508,   510,   513,   526,   533,
     546,   547,   548,   556,   563,   566,   567,   570,   571,   572,
     576,   577,   578,   579,   580,   583,   584,   588,   589,   590,
     591,   592,   593,   596,   597,   601,   608,   618,   619,   620,
     624,   631,   632,   633,   634,   635,   636,   642,   643,   644,
     645,   648,   649,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   668,   669,   670,   671,   672,   673,   674,   675,   676,
     677,   678,   679,   680,   681,   682,   683,   696,   697,   710,
     711,   712,   713,   714,   715,   716,   717,   718,   719,   720,
     721,   722,   723,   724,   725,   726,   727,   728,   729,   730,
     731,   738,   739,   746,   747,   754,   755,   762,   763,   770,
     771,   778,   779,   786,   787,   794,   795,   802,   803,   810,
     811,   818,   819,   833,   847,   848,   855,   856,   863,   864,
     875,   885,   886,   893,   894,   901,   902,   909,   910,   921,
     922,   933,   934,   945,   946,   953,   954,   961,   962,   969,
     970,   980,   990,  1000,  1010,  1019,  1027,  1028,  1036,  1037,
    1044,  1045,  1055,  1056,  1066,  1067,  1077,  1078,  1088,  1089,
    1096,  1097,  1104,  1105,  1116,  1117,  1118,  1119,  1120,  1121,
    1124,  1125,  1128,  1129,  1130,  1131,  1132,  1133,  1149,  1152,
    1171,  1174,  1175,  1176,  1181,  1183,  1184,  1185,  1191,  1193,
    1205,  1207,  1210,  1211,  1214,  1215,  1222,  1223,  1230,  1231,
    1235,  1262,  1263,  1271,  1272,  1275,  1276,  1279,  1280,  1290,
    1293,  1294,  1295,  1296,  1297,  1298,  1301,  1304,  1343,  1344,
    1350,  1356,  1360,  1361,  1364,  1398,  1418,  1419,  1422,  1422,
    1433,  1433,  1444,  1444,  1455,  1456,  1459,  1460,  1463,  1470,
    1477,  1484,  1491,  1492,  1499,  1501,  1508,  1510,  1517,  1518,
    1525,  1526,  1533,  1534,  1541,  1545,  1552,  1559,  1566,  1573,
    1575,  1582,  1584,  1591,  1593,  1600,  1601,  1608,  1609,  1616,
    1619,  1622,  1629,  1634,  1642,  1657,  1660,  1666,  1669,  1677,
    1683,  1686,  1692,  1695,  1703,  1706,  1714,  1717,  1725,  1728,
    1740,  1743,  1749,  1754,  1755,  1756,  1757,  1758,  1759,  1762,
    1763,  1766,  1767,  1768,  1769,  1771,  1772,  1775,  1776,  1779,
    1780,  1781,  1784,  1785,  1786,  1789,  1803,  1808,  1809,  1810,
    1812,  1815,  1817,  1819,  1821,  1823,  1827,  1829,  1831,  1832,
    1835,  1838,  1841,  1844,  1847,  1850,  1853,  1855,  1857,  1858,
    1861,  1863,  1864,  1865,  1867,  1868,  1869,  1871,  1874,  1875,
    1877,  1878,  1879,  1881,  1883,  1884,  1885,  1899,  1901,  1903,
    1905,  1919,  1921,  1923,  1925,  1927,  1929,  1931,  1933,  1938,
    1939,  1950,  1951,  1958,  1959,  1962,  1963,  1975,  1979,  1980,
    1981,  1982,  1983,  1984,  1985,  1986,  1987,  1988,  1992,  1993,
    1994,  1995,  1996,  1997,  1998,  2001,  2004,  2007,  2010,  2013,
    2016,  2019,  2022,  2025,  2028,  2031,  2034,  2047,  2060,  2082,
    2083,  2084,  2085,  2086,  2089,  2090,  2091,  2094,  2095,  2096,
    2099,  2100,  2101,  2102,  2103,  2104,  2105,  2108,  2116,  2126,
    2134,  2143,  2144,  2146,  2147,  2150,  2159,  2168,  2176,  2184,
    2193,  2202,  2210,  2221,  2227,  2235,  2240,  2249,  2253,  2259,
    2264,  2269,  2274,  2284,  2294,  2306,  2312,  2319,  2320,  2323,
    2329,  2335,  2336,  2338,  2339,  2340,  2341,  2342,  2348,  2354,
    2360,  2366,  2369,  2375,  2376,  2378,  2380,  2381,  2382,  2384,
    2386,  2387,  2389,  2391,  2392,  2394,  2396,  2397,  2399,  2401,
    2402,  2404,  2406,  2407,  2409,  2411,  2412,  2416,  2420,  2423,
    2426,  2427,  2431,  2435,  2439,  2443,  2444,  2448,  2452,  2456,
    2460,  2461,  2467,  2468,  2470,  2477,  2495,  2496,  2498,  2500,
    2501,  2504,  2506,  2507,  2509,  2511,  2512,  2515,  2517,  2518,
    2520,  2528,  2530,  2532,  2534,  2536,  2539,  2562,  2577,  2579,
    2580,  2582,  2584,  2585,  2587,  2589,  2590,  2592,  2594,  2595,
    2597,  2599,  2600,  2602,  2603,  2604,  2606,  2607,  2609,  2611,
    2612,  2613,  2614,  2616,  2617,  2619,  2621,  2629,  2636,  2643,
    2646,  2650,  2652,  2653,  2669,  2671,  2672,  2676,  2679,  2680,
    2684,  2687,  2688,  2691,  2694,  2695,  2699,  2702,  2703,  2707,
    2710,  2711,  2720,  2732,  2745,  2752,  2761,  2770,  2781,  2792,
    2803,  2814,  2823,  2830,  2847,  2864,  2866,  2868,  2870,  2872,
    2874,  2876,  2878,  2880,  2882,  2884,  2898,  2904,  2906,  2914
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FORWARD", "SEND", "DROP", "EXIT",
  "RETURN", "LOG_TOK", "ERROR", "ROUTE", "ROUTE_FAILURE", "ROUTE_ONREPLY",
  "ROUTE_BRANCH", "ROUTE_ERROR", "ROUTE_LOCAL", "ROUTE_STARTUP",
  "ROUTE_TIMER", "ROUTE_EVENT", "SET_HOST", "SET_HOSTPORT", "PREFIX",
  "STRIP", "STRIP_TAIL", "APPEND_BRANCH", "REMOVE_BRANCH", "PV_PRINTF",
  "SET_USER", "SET_USERPASS", "SET_PORT", "SET_URI", "REVERT_URI",
  "SET_DSTURI", "RESET_DSTURI", "ISDSTURISET", "FORCE_RPORT",
  "FORCE_LOCAL_RPORT", "FORCE_TCP_ALIAS", "IF", "ELSE", "SWITCH", "CASE",
  "DEFAULT", "SBREAK", "WHILE", "SET_ADV_ADDRESS", "SET_ADV_PORT",
  "FORCE_SEND_SOCKET", "SERIALIZE_BRANCHES", "NEXT_BRANCHES",
  "USE_BLACKLIST", "UNUSE_BLACKLIST", "MAX_LEN", "SETDEBUG", "SETFLAG",
  "RESETFLAG", "ISFLAGSET", "SETBFLAG", "RESETBFLAG", "ISBFLAGSET",
  "SETSFLAG", "RESETSFLAG", "ISSFLAGSET", "METHOD", "URI", "FROM_URI",
  "TO_URI", "SRCIP", "SRCPORT", "DSTIP", "DSTPORT", "PROTO", "AF",
  "MYSELF", "MSGLEN", "UDP", "TCP", "TLS", "SCTP", "NULLV", "CACHE_STORE",
  "CACHE_FETCH", "CACHE_COUNTER_FETCH", "CACHE_REMOVE", "CACHE_ADD",
  "CACHE_SUB", "CACHE_RAW_QUERY", "XDBG", "XLOG", "XLOG_BUF_SIZE",
  "XLOG_FORCE_COLOR", "RAISE_EVENT", "SUBSCRIBE_EVENT", "CONSTRUCT_URI",
  "GET_TIMESTAMP", "SCRIPT_TRACE", "DEBUG", "FORK", "LOGSTDERROR",
  "LOGFACILITY", "LOGNAME", "AVP_ALIASES", "LISTEN", "BIN_LISTEN",
  "BIN_CHILDREN", "ALIAS", "AUTO_ALIASES", "DNS", "REV_DNS",
  "DNS_TRY_IPV6", "DNS_RETR_TIME", "DNS_RETR_NO", "DNS_SERVERS_NO",
  "DNS_USE_SEARCH", "MAX_WHILE_LOOPS", "PORT", "CHILDREN", "CHECK_VIA",
  "MEMLOG", "MEMDUMP", "EXECMSGTHRESHOLD", "EXECDNSTHRESHOLD",
  "TCPTHRESHOLD", "EVENT_SHM_THRESHOLD", "EVENT_PKG_THRESHOLD",
  "QUERYBUFFERSIZE", "QUERYFLUSHTIME", "SIP_WARNING", "SOCK_MODE",
  "SOCK_USER", "SOCK_GROUP", "UNIX_SOCK", "UNIX_SOCK_CHILDREN",
  "UNIX_TX_TIMEOUT", "SERVER_SIGNATURE", "SERVER_HEADER",
  "USER_AGENT_HEADER", "LOADMODULE", "MPATH", "MODPARAM", "MAXBUFFER",
  "USER", "GROUP", "CHROOT", "WDIR", "MHOMED", "DISABLE_TCP", "ASYNC_TCP",
  "ASYNC_TCP_LOCAL_CON_TIMEOUT", "ASYNC_TCP_LOCAL_WRITE_TIMEOUT",
  "ASYNC_TCP_MAX_POSTPONED_CHUNKS", "TCP_ACCEPT_ALIASES", "TCP_CHILDREN",
  "TCP_CONNECT_TIMEOUT", "TCP_SEND_TIMEOUT", "TCP_CON_LIFETIME",
  "TCP_LISTEN_BACKLOG", "TCP_POLL_METHOD", "TCP_MAX_CONNECTIONS",
  "TCP_OPT_CRLF_PINGPONG", "TCP_NO_NEW_CONN_BFLAG", "TCP_KEEPALIVE",
  "TCP_KEEPCOUNT", "TCP_KEEPIDLE", "TCP_KEEPINTERVAL",
  "TCP_MAX_MSG_CHUNKS", "TCP_MAX_MSG_TIME", "DISABLE_TLS", "TLSLOG",
  "TLS_PORT_NO", "TLS_METHOD", "TLS_HANDSHAKE_TIMEOUT", "TLS_SEND_TIMEOUT",
  "TLS_SERVER_DOMAIN", "TLS_CLIENT_DOMAIN", "TLS_CLIENT_DOMAIN_AVP",
  "SSLv23", "SSLv2", "SSLv3", "TLSv1", "TLS_VERIFY_CLIENT",
  "TLS_VERIFY_SERVER", "TLS_REQUIRE_CLIENT_CERTIFICATE", "TLS_CERTIFICATE",
  "TLS_PRIVATE_KEY", "TLS_CA_LIST", "TLS_CIPHERS_LIST",
  "ADVERTISED_ADDRESS", "ADVERTISED_PORT", "DISABLE_CORE", "OPEN_FD_LIMIT",
  "MCAST_LOOPBACK", "MCAST_TTL", "TOS", "DISABLE_DNS_FAILOVER",
  "DISABLE_DNS_BLACKLIST", "DST_BLACKLIST", "DISABLE_STATELESS_FWD",
  "DB_VERSION_TABLE", "DB_DEFAULT_URL", "DISABLE_503_TRANSLATION", "EQUAL",
  "EQUAL_T", "GT", "LT", "GTE", "LTE", "DIFF", "MATCH", "NOTMATCH",
  "COLONEQ", "PLUSEQ", "MINUSEQ", "SLASHEQ", "MULTEQ", "MODULOEQ",
  "BANDEQ", "BOREQ", "BXOREQ", "AND", "OR", "BRSHIFT", "BLSHIFT", "BXOR",
  "BAND", "BOR", "MODULO", "MULT", "SLASH", "MINUS", "PLUS", "BNOT", "NOT",
  "NUMBER", "ZERO", "ID", "STRING", "SCRIPTVAR", "IPV6ADDR", "COMMA",
  "SEMICOLON", "RPAREN", "LPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK",
  "AS", "USE_CHILDREN", "DOT", "CR", "COLON", "ANY", "SCRIPTVARERR",
  "$accept", "cfg", "statements", "statement", "$@1", "$@2", "$@3", "$@4",
  "$@5", "$@6", "$@7", "$@8", "$@9", "listen_id", "proto", "port",
  "snumber", "phostport", "id_lst", "listen_def", "listen_lst",
  "blst_elem", "blst_elem_list", "assign_stm", "module_stm", "ip", "ipv4",
  "ipv6addr", "ipv6", "tls_server_domain_stm", "$@10",
  "tls_client_domain_stm", "$@11", "$@12", "tls_server_decls",
  "tls_client_decls", "tls_server_var", "tls_client_var", "route_name",
  "route_stm", "failure_route_stm", "onreply_route_stm",
  "branch_route_stm", "error_route_stm", "local_route_stm",
  "startup_route_stm", "timer_route_stm", "event_route_stm", "exp",
  "equalop", "compop", "matchop", "intop", "strop", "uri_type",
  "script_var", "exp_elem", "exp_cond", "ipnet", "host_sep", "host",
  "assignop", "assignexp", "assign_cmd", "exp_stm", "stm", "actions",
  "action", "if_cmd", "while_cmd", "switch_cmd", "switch_stm", "case_stms",
  "case_stm", "default_stm", "module_func_param", "route_param", "cmd", 0
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
     505,   506,   507,   508
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   254,   255,   256,   256,   256,   257,   257,   258,   257,
     259,   257,   260,   257,   261,   257,   262,   257,   263,   257,
     264,   257,   265,   257,   266,   257,   257,   267,   267,   267,
     268,   268,   268,   268,   268,   269,   269,   270,   270,   270,
     271,   271,   271,   271,   271,   272,   272,   273,   273,   273,
     273,   273,   273,   274,   274,   275,   275,   276,   276,   276,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   278,   278,   278,
     278,   278,   279,   279,   280,   281,   282,   282,   284,   283,
     286,   285,   287,   285,   288,   288,   289,   289,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     292,   292,   292,   293,   293,   293,   294,   294,   295,   295,
     295,   296,   296,   297,   297,   298,   298,   299,   299,   300,
     300,   301,   301,   302,   302,   302,   302,   302,   302,   303,
     303,   304,   304,   304,   304,   305,   305,   306,   306,   307,
     307,   307,   308,   308,   308,   309,   309,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   312,
     312,   312,   312,   313,   313,   314,   314,   314,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   317,   317,   317,   318,
     318,   318,   318,   318,   319,   319,   319,   320,   320,   320,
     321,   321,   321,   321,   321,   321,   321,   322,   322,   323,
     324,   325,   325,   326,   326,   327,   327,   327,   327,   327,
     327,   327,   327,   328,   328,   329,   329,   329,   329,   330,
     330,   330,   330,   330,   330,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     0,     2,
       0,     2,     0,     2,     0,     2,     0,     2,     0,     2,
       0,     2,     0,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     3,     3,     5,     3,     1,     2,     1,     3,     3,
       5,     5,     7,     1,     2,     9,    10,     3,     1,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     2,     7,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     8,
       8,     2,     1,     1,     7,     1,     1,     3,     0,    10,
       0,    10,     0,     8,     1,     2,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     4,     7,     2,     7,     2,     4,     7,
       2,     7,     2,     4,     2,     4,     2,     4,     2,     9,
       2,     7,     2,     3,     3,     2,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     2,     3,     3,     2,     3,     3,     2,     3,
       3,     2,     3,     3,     3,     2,     3,     3,     3,     2,
       3,     3,     3,     2,     3,     3,     3,     3,     2,     3,
       3,     1,     3,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     1,
       1,     1,     3,     2,     1,     3,     2,     2,     1,     2,
       2,     1,     1,     1,     2,     1,     2,     3,     5,     3,
       7,     2,     1,     2,     1,     6,     5,     4,     3,     6,
       5,     4,     3,     3,     2,     1,     3,     1,     3,     1,
       1,     1,     3,     3,     3,     4,     3,     2,     4,     4,
       6,     2,     4,     3,     1,     3,     1,     4,     4,     3,
       1,     4,     6,     2,     4,     4,     3,     2,     4,     4,
       2,     4,     4,     2,     4,     4,     2,     4,     4,     2,
       4,     4,     2,     4,     4,     2,     6,     6,     4,     4,
       2,     6,     6,     4,     4,     2,     6,     6,     4,     4,
       2,     6,     2,     4,     4,     6,     2,     4,     4,     2,
       4,     4,     2,     4,     4,     2,     4,     4,     2,     4,
       6,     4,     3,     1,     4,     4,     6,     6,     4,     2,
       4,     4,     2,     4,     4,     2,     4,     4,     2,     4,
       4,     2,     4,     3,     1,     4,     2,     4,     3,     1,
       3,     1,     3,     1,     3,     1,     4,     3,     1,     4,
       4,     4,     2,     4,     4,     2,     4,     4,     2,     4,
       4,     2,     3,     4,     2,     4,     4,     2,     4,     4,
       2,     8,    10,    10,     6,     8,     8,    10,    10,    10,
      10,     8,     6,     3,     4,     4,     2,     4,     4,     6,
       4,     6,     8,     6,     8,    14,     6,     3,     6,     8
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     7,   205,   206,   256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,    79,     0,    81,     0,    83,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   258,
     257,     0,   261,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,     0,   247,     0,     0,     0,
       0,     0,     0,     1,     5,     3,     0,     9,     0,    11,
       0,    13,     0,    15,     0,    17,     0,    19,     0,    21,
       0,    23,     0,    25,   215,   213,   216,   214,    61,     0,
       0,    37,    60,    63,    62,    65,    64,    67,    66,    69,
      68,    71,    70,   218,    30,    31,    32,    33,     0,   415,
      28,   265,     0,    34,    40,     0,    47,    53,   217,    27,
     262,   266,   263,    29,   220,     0,   222,   221,   224,    45,
     223,   226,   225,    73,    72,    75,    74,    76,    78,    80,
      82,    84,    89,    88,    87,    86,    93,    92,    95,    94,
      97,    96,    99,    98,   101,   100,   103,   102,   105,   104,
     107,   106,   109,   108,   111,   110,   113,   112,   115,   114,
     208,   207,   210,   209,   212,   211,   243,   242,     0,    91,
      90,   118,   117,   116,   121,   120,   119,   124,   123,   122,
     127,   126,   125,   129,   128,   131,   130,   133,   132,   135,
     134,   137,   136,   139,   138,   141,   140,   143,   142,   145,
     144,   147,   146,   149,   148,   151,   150,   154,   152,   153,
     156,   155,   158,   157,   161,   159,   160,   163,   162,   169,
     168,   171,   170,   173,   172,   165,   164,   167,   166,   175,
     174,   177,   176,   179,   178,   184,   180,   181,   182,   183,
     200,   199,   202,   201,     0,     0,     0,   204,   203,   186,
     185,   188,   187,   190,   189,   192,   191,   194,   193,   196,
     195,   198,   197,   228,   227,   230,   229,   232,   231,   234,
     233,   236,   235,   238,   237,   241,   239,   240,   244,   246,
       0,   249,   251,   250,   253,   252,   255,   254,   315,     0,
       0,   317,     0,   320,     0,     0,   322,     0,   324,     0,
     326,     0,   328,     0,   330,     0,   332,     0,    39,    38,
       0,     0,     0,     0,     0,     0,    54,   414,     0,     0,
       0,    46,     0,     0,   272,     0,     0,     0,     0,   504,
     506,   510,     0,     0,     0,     0,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,     0,   594,     0,   599,
     601,   603,   605,   608,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   355,
     465,   356,     0,     0,     0,   458,   461,   462,   463,     0,
     311,   310,   312,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,    44,    35,    36,    41,    42,
      49,    48,   417,   416,   219,     0,     0,     0,     0,     0,
     497,     0,   501,     0,     0,     0,     0,   513,     0,   552,
       0,   556,     0,   559,     0,   579,     0,   562,     0,   568,
       0,   565,     0,     0,     0,     0,   585,     0,   588,     0,
     582,     0,   591,     0,     0,   596,     0,     0,     0,     0,
       0,     0,     0,   352,   353,   354,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   359,     0,
       0,   360,   338,   357,   451,   358,   450,   449,     0,     0,
     612,     0,   615,     0,   618,     0,   621,     0,   624,     0,
     627,     0,   630,     0,   517,     0,   520,     0,   523,     0,
     526,     0,   540,     0,   545,     0,   550,     0,   529,     0,
     532,     0,   535,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   646,     0,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
       0,   464,   459,   313,   457,   466,   460,     0,     0,   318,
       0,     0,   323,   325,   327,     0,     0,     0,     0,     0,
       0,     0,   268,     0,   270,     0,     0,    58,     0,     0,
       0,   496,     0,     0,   503,   505,   509,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   572,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     593,     0,     0,   598,   600,   602,   604,     0,     0,   607,
     369,   339,   341,   342,   343,   344,   340,   345,   346,   349,
     350,   351,     0,   399,   349,     0,   382,   347,   348,     0,
     403,   349,     0,   385,     0,   388,     0,   391,     0,   408,
       0,   395,     0,   335,     0,   453,     0,     0,     0,     0,
       0,   429,     0,   428,     0,   431,   432,     0,   433,     0,
       0,     0,   467,   454,   379,   349,     0,   349,   350,     0,
       0,     0,   469,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   622,     0,     0,     0,     0,   516,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   657,     0,   487,   485,   643,     0,   447,   448,   446,
       0,     0,     0,     0,     0,     0,     0,    43,    50,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     276,     0,     0,     0,    59,     0,   248,   498,   495,   502,
       0,   499,   507,   508,   514,   511,     0,   553,     0,   557,
       0,   554,   560,   558,   580,   578,   563,   561,   569,   567,
     566,   564,     0,   571,   574,   575,     0,     0,   586,   584,
     589,   587,   583,   581,   592,   590,   597,   595,   609,   606,
     368,   367,   366,   397,   411,   364,   398,   396,   365,   381,
     380,   401,   362,   402,   400,   363,   384,   383,   387,   386,
     390,   389,   407,   405,   406,   404,   394,   393,   392,   336,
     452,   349,     0,   349,     0,   444,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   337,   333,
     334,   456,     0,     0,   377,   378,   376,   361,   374,   375,
     373,   372,   371,   370,     0,   611,   610,   614,   613,   617,
     616,   620,   619,   623,   626,   625,   629,   628,   515,   518,
     519,   521,   522,   524,   525,     0,   538,   539,     0,   543,
     544,     0,   548,   549,   527,   528,   530,   531,   533,   534,
       0,     0,     0,     0,     0,     0,     0,   647,     0,   648,
       0,   650,     0,     0,     0,     0,   645,     0,   644,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   260,     0,
       0,     0,     0,     0,     0,     0,   273,   277,     0,     0,
       0,    57,     0,     0,     0,   490,   489,   491,     0,     0,
       0,     0,     0,   445,   443,   442,   441,   439,   440,   438,
     436,   437,   435,   434,   455,   468,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   488,   486,   314,   316,
     319,   321,     0,   331,   264,    52,     0,     0,     0,     0,
       0,     0,     0,     0,   274,   299,   295,   296,   297,   298,
     309,   308,   301,   300,   303,   302,   305,   304,   307,   306,
       0,     0,     0,   500,   512,   551,     0,   555,   570,   576,
     577,   412,   410,   409,     0,     0,   472,   474,   536,   537,
     541,   542,   546,   547,     0,     0,     0,   634,     0,     0,
       0,   642,   649,     0,   651,     0,   653,     0,   656,     0,
     658,     0,     0,     0,     0,     0,     0,     0,     0,   269,
     275,   271,     0,     0,   493,   492,   494,     0,     0,   470,
       0,   473,   471,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   329,   282,   278,   279,   280,
     281,   292,   291,   294,   293,   284,   283,   286,   285,   288,
     287,   290,   289,     0,     0,   482,   478,   484,     0,   631,
     635,   636,     0,     0,     0,     0,   641,   652,   654,     0,
     659,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   480,     0,   476,
       0,   632,   633,   637,   638,   639,   640,     0,     0,    55,
     479,   475,     0,    56,     0,     0,   655
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   274,   275,   588,   853,   276,   290,   277,
     278,   757,   758,   112,   113,   279,   280,   281,   282,   114,
     942,   115,   951,   597,  1203,   949,  1204,   950,   573,   227,
     229,   231,   233,   235,   237,   239,   241,   243,   659,   827,
     820,   821,   869,   870,   854,   562,   662,   856,  1005,   489,
     283,   730,   857,   563,   665,   862,   564,   565,   566,   567,
     568,  1235,  1236,  1237,  1282,   926,  1148,   569
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -933
static const yytype_int16 yypact[] =
{
    5173,  -163,  -134,  -120,   -69,   -65,   -54,   -26,   -19,    -1,
       3,    14,    34,    38,   404,   422,   449,    35,    47,   492,
     507,   585,   457,   468,   526,   566,   598,   599,   627,   631,
     632,   683,   684,   693,   705,   706,   712,   718,   749,    98,
     792,    26,   823,   827,   843,   859,   872,   875,   879,   885,
     896,   899,   903,   948,   953,   957,   965,   968,   982,   992,
     995,  1011,  1012,  1013,  1034,  1047,  1058,  1059,  1060,  1061,
    1062,  1063,  1074,  1085,  1092,     2,   303,  1102,  1103,  1104,
    1105,  1106,  1107,  1108,  1129,  1131,  1132,  1142,  1163,  1164,
    1165,  1166,   628,   630,  1167,  1168,  1169,  1179,  1180,  -933,
     645,  3713,  -933,   678,   699,   744,   746,   761,   698,   765,
     767,  1025,  -933,  -933,  -933,  -933,  -933,   124,   125,   273,
     258,   261,   118,   126,   182,    18,    61,   316,    40,   335,
     336,   346,  -933,  1101,  -933,  1173,  -933,  1174,  -933,  1175,
    -933,  1176,   347,   355,   388,   394,   397,   403,   408,   424,
     427,   444,   464,   482,   484,   485,   487,   188,   191,  -933,
    -933,   207,  -933,   869,   497,    30,   110,   178,   186,   499,
     503,   504,   506,   509,   510,   511,   512,   513,   514,   515,
     516,   198,   527,   528,   249,   529,   530,   531,   532,   533,
     536,   549,   550,   552,   508,   554,   555,   375,   923,   208,
     556,   557,   558,   210,   211,   212,   213,    67,   559,   560,
     569,   570,   571,   257,  -933,  1177,  -933,  1178,  1188,  1191,
     215,   216,   572,  -933,  -163,  -933,    50,  -933,    42,  -933,
      64,  -933,    45,  -933,    24,  -933,    71,  -933,    72,  -933,
      56,  -933,    59,  -933,  -933,  -933,  -933,  -933,  -933,  1192,
    1193,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  1181,  -933,
    -933,  -933,  1189,  -933,  1161,  1162,   390,   943,  -933,  -933,
    -933,  -933,  -933,  -179,  -933,  1183,  -933,  -933,  -933,   943,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  1190,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  1184,  1182,  1187,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    1194,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  5015,
     432,  -933,   432,  -933,  5015,   432,  -933,   432,  -933,  5015,
    -933,  5015,  -933,  5015,  -933,   432,  -933,   432,  -933,  -933,
    1199,  1195,    28,   915,   915,  1206,  -933,  -933,   130,  1202,
    -154,  -933,  1207,  -154,  -933,  -154,  1201,    44,    74,  1200,
    1205,  1208,    76,    77,    79,    81,    82,    83,    84,    86,
    1209,  1210,  1211,    88,    91,    96,    99,  1212,   100,  1213,
    1214,  1215,  1216,  1217,  3911,  1218,  3911,   109,   112,   113,
     119,   128,   129,   132,   148,   149,   150,   151,   152,   155,
     159,   160,   164,   168,  1219,  1220,  1221,  1222,  1223,  1224,
    1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,   173,  -933,
    -933,  -933,  1204,  1235,  1291,  -933,  -933,  -933,  -933,    87,
    -933,  -933,  -933,  1233,  1234,  1533,  1236,  1237,  1628,  1870,
    1965,  1238,  1239,  1197,  -933,  -933,  -933,  -933,  -933,  1240,
     -14,  -933,  -933,  -933,  -933,  1242,  1241,  1243,  1244,  -168,
    -933,   176,  -933,   217,  1247,  1248,   861,  -933,   190,  -933,
     218,  -933,   196,  -933,   219,  -933,   220,  -933,   221,  -933,
     573,  -933,   574,   -55,  -184,   -91,  -933,   222,  -933,   223,
    -933,   224,  -933,   225,  1251,  -933,   226,  1252,  1253,  1254,
    1255,   102,   395,  -933,  -933,  -933,   618,   496,   633,   852,
     914,   920,   594,   930,  3911,  3911,  4260,  4004,  -933,  4167,
     904,  1186,  -933,  -933,  -933,  -933,  -933,  -933,   -59,  4167,
    -933,    75,  -933,   575,  -933,    46,  -933,   576,  -933,    90,
    -933,   227,  -933,   228,  -933,   410,  -933,  -172,  -933,   456,
    -933,   481,  -933,   486,  -933,   489,  -933,   535,  -933,   543,
    -933,   562,  -933,   648,  1261,  1262,  1263,  1264,  1265,  1266,
    1267,  1268,  1269,  1270,  1271,  1272,   -59,   -53,  -933,   175,
    1369,  1397,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    4004,  -933,  -933,  -933,  -933,  -933,  -933,  1273,  1274,  -933,
    1275,  1276,  -933,  -933,  -933,  1245,  1277,  1278,  -154,  1279,
    -154,   845,  -933,   768,  -933,  1280,   578,  -933,    33,  1282,
    1283,  -933,  1284,   675,  -933,  -933,  -933,  1286,  1288,  1289,
    1292,  1293,  1304,  1307,  1306,   700,  1308,  1309,  1310,  1331,
    1333,  1334,  1335,  1344,  1355,  1356,   701,  -933,  1357,  1358,
    1361,  1362,  1363,  1364,  1365,  1366,  1367,  1368,  1370,  1371,
    -933,  1381,  1382,  -933,  -933,  -933,  -933,  1389,  1398,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,   200,  -933,   426,   202,  -933,  -933,  -933,   577,
    -933,   428,   204,  -933,   580,  -933,    31,  -933,   581,  -933,
     614,  -933,   197,  -933,   -35,  -933,  2207,   618,   633,  4004,
     842,  -933,  4004,  -933,   904,   763,  -933,   917,  -933,  3911,
    3911,  4502,  1445,  -933,  -933,  1436,   206,   679,   505,   793,
     459,  1399,  -933,  1400,  1401,  1402,  1403,  1404,  1405,  1426,
    1428,  1429,  -933,  1430,  1439,  1450,  1451,  -933,  1452,  1453,
    1454,  1455,  1456,  1457,  1458,   811,  1459,   812,  1460,   848,
    1461,  1462,  1463,  1464,  1465,  1466,  1476,  1479,  1485,  1486,
    1487,  1488,  1489,  1490,  1491,   862,   889,  1492,  1494,  1495,
    1496,  -933,  1497,  -933,  -933,  -933,   890,  -933,  -933,  1133,
    5015,  5015,  5015,  5015,  1302,  5015,  1353,  -933,  -933,  1482,
    1498,  1499,  1360,  1312,  1313,  1314,  1320,  1409,  1535,   463,
    -933,  1500,   578,  1502,  -933,  -168,  -933,  -933,  -933,  -933,
    1501,  -933,  -933,  -933,  -933,  -933,  1506,  -933,  1508,  -933,
     356,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  1509,  -933,  -933,  -933,  1510,  1511,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  1520,  -933,  -933,  -933,  -179,  -933,
    -933,  -933,  -933,  -933,  -933,  -179,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  1437,   230,  1676,   231,  -933,  1044,   232,  4004,  4004,
    4004,  4004,  4004,  4004,  4004,  4004,  4004,  4004,  -933,  -933,
    -933,  -933,  2302,  4595,  -933,  -933,  -933,  -179,  -933,  -933,
    -933,  -933,  -933,  -933,  1507,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,   685,  -933,  -933,   929,  -933,
    -933,   942,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    1515,  1516,  1517,  1518,  1519,  1521,  1522,  -933,  1523,  -933,
     -59,  -933,  1524,  1525,   -59,  1526,  -933,   381,  -933,  2544,
    2639,  2881,  2976,  1513,  3218,  1530,  1531,  -933,  -933,   847,
     595,   582,   237,   239,   240,   241,  -933,  -933,   768,  1527,
     375,  -933,  1528,  1534,  1537,  -933,  -933,  -933,   941,  1538,
    1539,  1540,    19,  -933,   944,   944,   944,   944,   944,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  1724,  1541,  1542,  1543,
    1544,  1546,  1547,  1532,  1550,  1551,  1552,  1553,  1555,   945,
    1554,   946,   951,  1557,  1556,   969,  -933,  -933,  -933,  -933,
    -933,  -933,  5015,  -933,  -933,  -933,  1566,  1571,  1573,  1575,
    1590,  1597,  1598,   -42,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
     762,   375,  1561,  -933,  -933,  -933,   439,  -933,  -933,  -933,
    -933,  -933,  1181,  -933,   863,  1558,   621,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  1565,   -59,   -59,  -933,   354,   389,
    1567,  -933,  -933,   -59,  -933,  1572,  -933,  1568,  -933,  1570,
    -933,  3313,   681,   583,   584,   242,   243,   244,   245,  -933,
    -933,  -933,  1569,  -154,  -933,  -933,  -933,  1559,  1560,  -933,
    1562,  -933,  -933,   970,  1574,  1576,  1577,  1579,  1580,  1581,
    1582,  1583,  1584,  1587,  1586,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -154,  1589,  4759,  4852,  5015,   437,  -933,
    -933,  -933,  1588,  1596,  1599,  1600,  -933,  -933,  -933,  1578,
    -933,  1591,  1595,  1594,   954,  1601,  1196,  3555,  1602,  1603,
    1604,  1605,  1606,  1607,  1610,  1614,  1611,  -933,  1613,  -933,
    1615,  -933,  -933,  -933,  -933,  -933,  -933,  1618,  1616,  -933,
    -933,  -933,  1612,  -933,   -59,  1617,  -933
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -933,  -933,  -933,  1706,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -117,  -697,  -479,  -119,  -123,  1548,  -933,
    1545,   854,  -933,  -933,  -933,  -196,  -933,  1563,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,   674,   635,  -932,   690,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -482,   -36,
    -595,  -933,   104,    63,  -496,  -520,  -933,  -491,  -818,  -933,
    -214,  -933,  -659,  -487,  -933,  -654,  -461,  -557,  -484,  -933,
    -933,  -933,  -933,   600,  -933,  -933,  -933,  -500
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -484
static const yytype_int16 yytable[] =
{
     252,   414,   416,   575,   661,   289,   661,   734,   578,   285,
     579,   594,   580,  1012,   596,   872,   598,  1137,   734,   263,
    1231,   734,   734,   734,   667,   468,   667,   162,   660,   585,
     660,   341,  1018,   663,   954,   663,   132,   664,   116,   664,
     666,   288,   666,   461,   669,   600,   466,   877,   134,   788,
     487,   458,   828,   559,   828,   828,   828,   474,   828,   953,
     476,   889,   284,   890,   755,   463,   868,   117,   433,   561,
     488,   929,   470,   472,   756,   602,   873,   607,   609,   586,
     611,   118,   613,   615,   617,   619,   768,   621,   735,   626,
     434,   881,   628,   264,   265,   266,   267,   630,   587,   159,
     632,   635,   863,   807,   789,   791,   264,   265,   266,   267,
     670,   344,   863,   672,   674,   264,   265,   266,   267,   257,
     676,   264,   265,   266,   267,   244,   246,   259,  1196,   678,
     680,   592,   119,   682,   661,   661,   120,   855,  1197,  1019,
    1198,  1199,  1200,  1201,  1202,   790,   559,   121,   871,   684,
     686,   688,   690,   692,   667,   667,   694,   858,   660,   660,
     696,   698,   561,   663,   663,   700,   289,   664,   664,   702,
     666,   666,   843,   844,   718,   122,   922,   759,   559,   347,
     920,   786,   123,   261,   859,   860,   787,   350,   921,   332,
    1035,   769,   334,  1036,   561,   846,   919,   774,  1026,   377,
     124,  1000,  1269,  1006,   125,  1013,  1029,  1055,   336,   417,
     855,   425,   427,   429,   431,   126,   452,   454,   762,   772,
     776,   778,   780,   792,   794,   796,   798,   801,   883,   885,
     858,  1006,  1013,  1055,   749,   127,   133,   750,  1212,   128,
    1214,  1216,  1218,  1305,  1307,  1309,  1311,   197,   135,  1027,
     384,   268,  1232,   269,   270,  1139,   271,   271,   445,   253,
     868,   586,   255,   272,   272,   342,   343,   469,   163,   937,
     273,   939,   955,   268,   248,   269,   270,   956,   271,   268,
     587,   269,   270,   273,   271,   272,   601,   462,  1137,   734,
     467,   272,   273,   459,   268,   460,   269,   270,   273,   271,
     268,   475,   269,   270,   477,   271,   272,   464,   268,   465,
     269,   270,   272,   271,   471,   473,   603,   286,   608,   610,
     272,   612,  1222,   614,   616,   618,   620,   736,   622,   855,
     627,   882,   855,   629,   160,   808,   291,   293,   631,   661,
     661,   633,   636,   809,  1025,   345,   346,   295,   302,   858,
    1063,   671,   858,   258,   673,   675,   304,   245,   247,   667,
     667,   677,   260,   660,   660,  -413,   589,   590,   663,   663,
     679,   681,   664,   664,   683,   666,   666,  1049,  1050,  1154,
    1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,   306,
     685,   687,   689,   691,   693,   308,   810,   695,   310,  1165,
    1052,   697,   699,  1272,   312,   658,   701,   658,   923,   314,
     703,   924,   760,   348,   349,   719,   925,   761,   262,   249,
     250,   351,   352,   251,   333,   316,   770,   335,   318,   570,
    1028,   571,   572,   378,   379,  1001,  1002,   269,  1007,   269,
    1014,   269,  1056,   337,   418,   320,   426,   428,   430,   432,
    1147,   453,   455,   763,   773,   777,   779,   781,   793,   795,
     797,   799,   802,   884,   886,   322,  1007,  1014,  1056,  1119,
    1120,  1121,  1122,  1213,  1124,  1215,  1217,  1219,  1306,  1308,
    1310,  1312,   385,   324,   386,   326,   328,   767,   330,   771,
     446,   254,   447,   136,   256,   734,   863,   826,   339,  1003,
     353,  1011,   249,   250,   355,   357,   251,   359,   138,   405,
     361,   363,   365,   367,   369,   371,   373,   375,   855,   855,
     855,   855,   855,   855,   855,   855,   855,   855,   380,   382,
     387,   389,   391,   393,   395,   658,   658,   397,   858,   858,
     858,   858,   858,   858,   858,   858,   858,   858,   198,   287,
     399,   401,   878,   403,   874,   410,   412,   419,   421,   423,
     435,   437,   734,   734,   734,   734,   888,   734,   292,   294,
     439,   441,   443,   456,   782,   784,   875,   879,  1009,   296,
     303,  1016,  1020,  1210,  1301,  1303,   140,  1286,   305,  1145,
    1181,   559,  1146,   559,  1184,   839,  1205,   811,   812,   813,
     814,   815,   816,   817,   818,   129,   819,   561,   268,   561,
     824,  1008,   831,   271,  1186,  1022,   840,  1187,  1015,   823,
     272,   307,  1288,   130,   865,   867,   559,   309,  1004,   214,
     311,   216,   941,   943,   830,  1004,   313,   484,   485,   249,
     250,   315,   561,   251,   944,   223,   945,   946,   947,   948,
     131,   887,  1057,   264,   265,   266,   267,   317,   142,   268,
     319,   268,  1234,  1280,   271,   570,   271,   571,   572,   143,
    1338,   272,  1274,   272,   559,  1275,   559,   321,   643,   644,
     645,  1023,  1296,  1024,   406,   407,   408,   409,   226,   891,
     561,   892,   561,   137,  1061,  1062,   559,   323,   811,   812,
     813,   814,   815,   816,   734,   822,  1276,  1136,   139,   825,
     228,   832,   561,   236,   893,   325,   894,   327,   329,   895,
     331,   896,   897,   866,   898,  1284,  1285,   144,  1287,  1289,
     340,  1261,   354,  1291,  -348,  -348,   356,   358,  -348,   360,
     658,   658,   362,   364,   366,   368,   370,   372,   374,   376,
    1060,   829,  1058,   834,   836,   838,   230,   842,  1059,   232,
     381,   383,   388,   390,   392,   394,   396,   145,   899,   398,
     900,  1206,  1207,  1208,  1209,   234,   901,   734,   902,   734,
     734,   238,   400,   402,   240,   404,   141,   411,   413,   420,
     422,   424,   436,   438,  1314,   903,   811,   904,  1339,   146,
     147,   816,   440,   442,   444,   457,   783,   785,   876,   880,
    1010,  1031,  1033,  1017,  1021,  1211,  1302,  1304,   865,   867,
     811,   812,   813,   814,   815,   816,   817,   818,   148,   215,
     273,   217,   149,   150,  1331,   811,   812,   813,   814,   815,
     816,   817,   818,   718,  1365,  -430,  -430,  -430,  -430,  -430,
    -430,  -430,  -430,   833,  1334,  1336,  1337,  1297,  1298,  1299,
    1300,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,
    -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,
    -430,   905,  -430,   906,   151,   152,  -430,  -430,  -430,  -430,
    -430,  -430,  -430,  -430,   153,  -430,  -430,  -430,  -430,  -430,
    -430,  -430,  -430,  -430,  -430,   864,   154,   155,  -347,  -347,
    1032,  1034,  -347,   156,   960,   835,   961,  1037,  1167,   157,
    1168,   837,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,
    -430,   841,   943,  -430,  -430,  -430,  -430,  -430,   943,   970,
     982,   971,   983,   944,  1004,   945,   946,   947,   948,   944,
     158,   945,   946,   947,   948,   732,  1233,   497,   498,   499,
     500,   501,   502,   503,   504,   811,   812,   813,   814,   815,
     816,   817,   818,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   161,   525,  -481,  -481,  1348,   526,   527,
     528,   529,   530,   531,   532,   533,  1271,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,  1196,   264,   265,
     266,   267,   249,   250,   164,  1004,   251,  1197,   165,  1198,
    1199,  1200,  1201,  1202,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   242,   166,   553,   554,   555,   556,   557,
    1085,  1088,  1086,  1089,   811,   812,   813,   814,   815,   816,
     167,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,
    -430,  -430,  -430,   168,   249,   250,   169,  -430,   251,  -430,
     170,   940,  -430,  -430,   719,  -430,   171,  1091,  -430,  1092,
     249,   250,   249,   250,   251,  -430,   251,   172,   559,  1277,
     173,  1108,   766,  1109,   174,   338,   811,   812,   813,   814,
     815,   816,   817,   818,   561,  1278,   811,   812,   813,   814,
     815,   816,   811,   812,   813,   814,   815,   816,  1110,  1117,
    1111,  1118,   811,   812,   813,   814,   815,   816,  1038,  1039,
    1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,   268,   175,
     269,   270,   574,   271,   176,   576,   268,   577,   177,   415,
     272,   271,  1169,  1048,  1170,   581,   178,   582,   272,   179,
    1043,  1044,  1045,  1046,  1047,  1171,   268,  1172,   269,   270,
    1226,   271,  1227,   180,  1250,  1253,  1251,  1254,   272,   558,
    1255,   559,  1256,   181,   560,   273,   182,   732,  -481,   497,
     498,   499,   500,   501,   502,   503,   504,   561,  1259,  1318,
    1260,  1319,   183,   184,   185,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   186,   525,  -477,  -477,  1350,
     526,   527,   528,   529,   530,   531,   532,   533,   187,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   188,
     189,   190,   191,   192,   193,  1038,  1039,  1040,  1041,  1042,
    1043,  1044,  1045,  1046,  1047,   194,   544,   545,   546,   547,
     548,   549,   550,   551,   552,  1153,   195,   553,   554,   555,
     556,   557,   732,   196,   497,   498,   499,   500,   501,   502,
     503,   504,   775,   199,   200,   201,   202,   203,   204,   205,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     206,   525,   207,   208,   297,   526,   527,   528,   529,   530,
     531,   532,   533,   209,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,  1038,  1039,  1040,  1041,  1042,  1043,
    1044,  1045,  1046,  1047,   210,   211,   212,   213,   218,   219,
     220,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     221,   222,   553,   554,   555,   556,   557,   720,   811,   812,
     813,   814,   815,   816,   817,   818,   721,   722,   723,   724,
     725,   726,   727,   728,   729,   720,   298,   299,   300,   301,
     448,   449,   482,   483,   721,   722,   723,   724,   725,   726,
     727,   728,   729,   450,   451,   478,   479,   271,   494,   492,
     480,   558,   583,   559,   490,   493,   560,   593,   495,   591,
    -477,   584,   604,   595,   599,   496,   747,   605,   927,   561,
     606,   623,   624,   625,   634,   637,   638,   639,   640,   641,
     668,   704,   705,   706,   707,   708,   709,   710,   711,   712,
     713,   714,   715,   716,   717,   731,   928,   745,   934,   737,
     738,   751,   740,   741,  1053,   746,   753,   752,   764,   765,
     754,   748,   800,   803,   804,   805,   806,   907,   908,   909,
     910,   911,   912,   913,   914,   915,   916,   917,   918,  1054,
    1003,   936,   938,  1130,  1131,  1132,   930,   931,   932,   933,
     935,  1133,   952,   957,   958,   959,   558,   962,   559,   963,
     964,   560,   966,   965,   732,   733,   497,   498,   499,   500,
     501,   502,   503,   504,   561,   967,   968,   969,  1123,   972,
     973,   974,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   975,   525,   976,   977,   978,   526,   527,   528,
     529,   530,   531,   532,   533,   979,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   980,   981,   984,   985,
     986,   987,  1125,  1129,   988,   989,   990,   991,   992,   993,
    1134,   994,   995,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   996,   997,   553,   554,   555,   556,   557,   732,
     998,   497,   498,   499,   500,   501,   502,   503,   504,   999,
    1064,  1065,  1066,  1067,  1068,  1069,  1070,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,  1071,   525,  1072,
    1073,  1074,   526,   527,   528,   529,   530,   531,   532,   533,
    1075,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1087,  1090,  1093,  1094,  1095,  1096,  1097,  1098,   544,   545,
     546,   547,   548,   549,   550,   551,   552,  1099,  1100,   553,
     554,   555,   556,   557,  1101,  1102,  1103,  1104,  1105,  1106,
    1126,  1112,  1107,  1113,  1114,  1115,  1135,  1142,  1116,  1127,
    1128,  1140,  1143,  1138,  1144,  1149,  1150,  1151,  1152,  1011,
    1166,  1173,  1174,  1175,  1176,  1177,  1192,  1178,  1179,  1180,
    1182,  1183,  1185,  1194,  1195,  1234,  1221,  1262,   558,  1223,
     559,  1244,  1263,   560,  1264,  1224,  1265,   739,  1225,  1228,
    1229,  1230,  1238,  1239,  1240,  1241,   561,  1242,  1243,  1245,
    1246,  1266,  1248,  1247,  1249,  1252,  1257,  1258,  1267,  1268,
    1273,  1283,  1279,  1290,  1293,  1292,  1294,   225,  1313,  1141,
    1315,  1316,  1220,  1317,  1344,  1320,  1322,  1321,  1323,  1324,
    1325,  1340,   486,  1326,  1327,  1328,  1329,  1330,  1332,  1341,
    1345,  1346,  1342,  1343,  1347,   481,  1281,   491,  1270,     0,
       0,  1349,     0,  1351,  1352,  1353,  1354,  1355,  1356,  1357,
    1358,  1364,  1359,  1360,  1362,  1361,     0,  1363,  1366,     0,
       0,     0,     0,   558,     0,   559,     0,     0,   560,     0,
       0,   732,   742,   497,   498,   499,   500,   501,   502,   503,
     504,   561,     0,     0,     0,     0,     0,     0,     0,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,     0,
     525,     0,     0,     0,   526,   527,   528,   529,   530,   531,
     532,   533,     0,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     544,   545,   546,   547,   548,   549,   550,   551,   552,     0,
       0,   553,   554,   555,   556,   557,   732,     0,   497,   498,
     499,   500,   501,   502,   503,   504,     0,     0,     0,     0,
       0,     0,     0,     0,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,     0,   525,     0,     0,     0,   526,
     527,   528,   529,   530,   531,   532,   533,     0,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   544,   545,   546,   547,   548,
     549,   550,   551,   552,     0,     0,   553,   554,   555,   556,
     557,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   558,     0,   559,     0,     0,
     560,     0,     0,     0,   743,     0,     0,     0,     0,     0,
       0,     0,     0,   561,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     558,     0,   559,     0,     0,   560,     0,     0,   732,   744,
     497,   498,   499,   500,   501,   502,   503,   504,   561,     0,
       0,     0,     0,     0,     0,     0,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,     0,   525,     0,     0,
       0,   526,   527,   528,   529,   530,   531,   532,   533,     0,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   544,   545,   546,
     547,   548,   549,   550,   551,   552,     0,     0,   553,   554,
     555,   556,   557,   732,     0,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,     0,     0,     0,
       0,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,     0,   525,     0,     0,     0,   526,   527,   528,   529,
     530,   531,   532,   533,     0,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   544,   545,   546,   547,   548,   549,   550,   551,
     552,     0,     0,   553,   554,   555,   556,   557,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   558,     0,   559,     0,     0,   560,     0,     0,
       0,  1030,     0,     0,     0,     0,     0,     0,     0,     0,
     561,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   558,     0,   559,
       0,     0,   560,     0,     0,   732,  1164,   497,   498,   499,
     500,   501,   502,   503,   504,   561,     0,     0,     0,     0,
       0,     0,     0,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,     0,   525,     0,     0,     0,   526,   527,
     528,   529,   530,   531,   532,   533,     0,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   544,   545,   546,   547,   548,   549,
     550,   551,   552,     0,     0,   553,   554,   555,   556,   557,
     732,     0,   497,   498,   499,   500,   501,   502,   503,   504,
       0,     0,     0,     0,     0,     0,     0,     0,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,     0,   525,
       0,     0,     0,   526,   527,   528,   529,   530,   531,   532,
     533,     0,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   544,
     545,   546,   547,   548,   549,   550,   551,   552,     0,     0,
     553,   554,   555,   556,   557,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   558,
       0,   559,     0,     0,   560,     0,     0,     0,  1188,     0,
       0,     0,     0,     0,     0,     0,     0,   561,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   558,     0,   559,     0,     0,   560,
       0,     0,   732,  1189,   497,   498,   499,   500,   501,   502,
     503,   504,   561,     0,     0,     0,     0,     0,     0,     0,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
       0,   525,     0,     0,     0,   526,   527,   528,   529,   530,
     531,   532,   533,     0,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   544,   545,   546,   547,   548,   549,   550,   551,   552,
       0,     0,   553,   554,   555,   556,   557,   732,     0,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,     0,     0,     0,     0,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,     0,   525,     0,     0,     0,
     526,   527,   528,   529,   530,   531,   532,   533,     0,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   544,   545,   546,   547,
     548,   549,   550,   551,   552,     0,     0,   553,   554,   555,
     556,   557,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   558,     0,   559,     0,
       0,   560,     0,     0,     0,  1190,     0,     0,     0,     0,
       0,     0,     0,     0,   561,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   558,     0,   559,     0,     0,   560,     0,     0,   732,
    1191,   497,   498,   499,   500,   501,   502,   503,   504,   561,
       0,     0,     0,     0,     0,     0,     0,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,     0,   525,     0,
       0,     0,   526,   527,   528,   529,   530,   531,   532,   533,
       0,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   544,   545,
     546,   547,   548,   549,   550,   551,   552,     0,     0,   553,
     554,   555,   556,   557,   732,     0,   497,   498,   499,   500,
     501,   502,   503,   504,     0,     0,     0,     0,     0,     0,
       0,     0,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,     0,   525,     0,     0,     0,   526,   527,   528,
     529,   530,   531,   532,   533,     0,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   544,   545,   546,   547,   548,   549,   550,
     551,   552,     0,     0,   553,   554,   555,   556,   557,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   558,     0,   559,     0,     0,   560,     0,
       0,     0,  1193,     0,     0,     0,     0,     0,     0,     0,
       0,   561,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   558,     0,
     559,     0,     0,   560,     0,     0,   732,  1295,   497,   498,
     499,   500,   501,   502,   503,   504,   561,     0,     0,     0,
       0,     0,     0,     0,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,     0,   525,     0,     0,     0,   526,
     527,   528,   529,   530,   531,   532,   533,     0,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   544,   545,   546,   547,   548,
     549,   550,   551,   552,     0,     0,   553,   554,   555,   556,
     557,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    -2,   224,     0,     0,     0,     0,     0,
       0,     0,     0,    -8,   -10,   -12,   -14,   -16,   -18,   -20,
     -22,   -24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     558,     0,   559,     0,     0,   560,     0,     0,     0,  -483,
       0,     0,     2,     3,     0,     0,     0,     0,   561,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,   497,   498,   499,   500,   501,   502,
     503,   504,     0,     0,     0,     0,     0,     0,     0,     0,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
       0,     0,     0,     0,     0,     0,   527,   528,   529,   530,
     531,   532,   533,    99,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   642,   643,   644,   645,   646,   647,
     648,   649,   650,   651,   652,   653,     0,     0,     0,     0,
       0,   544,   545,   546,   547,   548,   549,   550,   551,   552,
       0,     0,   553,   554,   555,   556,   557,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,     0,
       0,     0,     0,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,     0,     0,     0,     0,     0,     0,     0,   527,
     528,   529,   530,   531,   532,   533,     0,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   642,   643,   644,
     645,   847,   647,   848,   649,   650,   651,   652,   653,     0,
       0,     0,     0,     0,   544,   545,   546,   547,   548,   549,
     550,   551,   552,     0,     0,   553,   554,   555,   556,   557,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,   250,     0,   654,   251,     0,   558,     0,   559,     0,
       0,     0,     0,   655,   656,     0,   657,     0,     0,     0,
       0,     0,     0,     0,   561,     0,     0,     0,     0,     0,
     497,   498,   499,   500,   501,   502,   503,   504,     0,     0,
       0,     0,     0,     0,     0,     0,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,     0,   525,     0,     0,
       0,   526,   527,   528,   529,   530,   531,   532,   533,     0,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
       0,     0,     0,   249,   250,   849,     0,   251,     0,   850,
     851,   559,     0,     0,     0,     0,   852,   544,   545,   546,
     547,   548,   549,   550,   551,   552,     0,   561,   553,   554,
     555,   556,   557,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,     0,     0,     0,     0,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,     0,
     525,     0,     0,     0,   526,   527,   528,   529,   530,   531,
     532,   533,     0,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     544,   545,   546,   547,   548,   549,   550,   551,   552,     0,
       0,   553,   554,   555,   556,   557,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   859,   860,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   558,     0,   559,     0,     0,   560,     0,     0,
     861,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     561,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   558,     0,   559,     0,     0,
     560,     0,     0,     0,   845,   497,   498,   499,   500,   501,
     502,   503,   504,   561,     0,     0,     0,     0,     0,     0,
       0,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,     0,   525,     0,     0,     0,   526,   527,   528,   529,
     530,   531,   532,   533,     0,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   544,   545,   546,   547,   548,   549,   550,   551,
     552,     0,     0,   553,   554,   555,   556,   557,   497,   498,
     499,   500,   501,   502,   503,   504,     0,     0,     0,     0,
       0,     0,     0,     0,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,     0,   525,     0,     0,     0,   526,
     527,   528,   529,   530,   531,   532,   533,     0,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   544,   545,   546,   547,   548,
     549,   550,   551,   552,     0,     0,   553,   554,   555,   556,
     557,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   558,     0,   559,
       0,     0,   560,     0,     0,     0,  1051,     0,     0,     0,
       0,     0,     0,     0,     0,   561,     0,     0,     0,     0,
       0,     0,   497,   498,   499,   500,   501,   502,   503,   504,
       0,     0,     0,     0,     0,     0,     0,     0,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,     0,   525,
       0,     0,  1333,   526,   527,   528,   529,   530,   531,   532,
     533,     0,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,     0,     0,     0,     0,     0,     0,     0,     0,
     558,     0,   559,     0,     0,   560,     0,     0,   861,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   561,     0,
     553,   554,   555,   556,   557,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,     0,     0,     0,
       0,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,     0,   525,     0,     0,  1335,   526,   527,   528,   529,
     530,   531,   532,   533,     0,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   544,   545,   546,   547,   548,   549,   550,   551,
     552,     0,     0,   553,   554,   555,   556,   557,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   558,     0,   559,     0,     0,   560,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   561,     0,     0,     0,     0,     0,   497,   498,
     499,   500,   501,   502,   503,   504,     0,     0,     0,     0,
       0,     0,     0,     0,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,     0,   525,     0,     0,     0,   526,
     527,   528,   529,   530,   531,   532,   533,     0,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   558,     0,   559,
       0,     0,   560,     0,     0,   544,   545,   546,   547,   548,
     549,   550,   551,   552,     0,   561,   553,   554,   555,   556,
     557,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,    -8,   -10,   -12,   -14,   -16,   -18,   -20,
     -22,   -24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     558,     0,   559,     0,     0,   560,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     0,     0,     0,   561,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-933))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     119,   197,   198,   464,   524,   128,   526,   564,   469,   126,
     471,   490,   473,   831,   493,   669,   495,   949,   575,     1,
       1,   578,   579,   580,   524,     1,   526,     1,   524,     1,
     526,     1,     1,   524,     1,   526,     1,   524,   201,   526,
     524,     1,   526,     1,   526,     1,     1,     1,     1,   233,
     229,     1,   647,   237,   649,   650,   651,     1,   653,   756,
       1,   233,     1,   235,   232,     1,   661,   201,     1,   253,
     249,   730,     1,     1,   242,     1,     1,     1,     1,   233,
       1,   201,     1,     1,     1,     1,   606,     1,     1,     1,
     207,     1,     1,    75,    76,    77,    78,     1,   252,     1,
       1,     1,   659,     1,   624,   625,    75,    76,    77,    78,
       1,     1,   669,     1,     1,    75,    76,    77,    78,     1,
       1,    75,    76,    77,    78,     1,     1,     1,   170,     1,
       1,     1,   201,     1,   654,   655,   201,   657,   180,   836,
     182,   183,   184,   185,   186,   236,   237,   201,   668,     1,
       1,     1,     1,     1,   654,   655,     1,   657,   654,   655,
       1,     1,   253,   654,   655,     1,   289,   654,   655,     1,
     654,   655,   654,   655,     1,   201,     1,     1,   237,     1,
     233,   236,   201,     1,   219,   220,   241,     1,   241,     1,
     849,     1,     1,   852,   253,   656,   716,     1,     1,     1,
     201,     1,   244,     1,   201,     1,   241,     1,     1,     1,
     730,     1,     1,     1,     1,   201,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     730,     1,     1,     1,   248,   201,   201,   251,     1,   201,
       1,     1,     1,     1,     1,     1,     1,   245,   201,    52,
       1,   233,   233,   235,   236,   952,   238,   238,     1,     1,
     855,   233,     1,   245,   245,   235,   236,   243,   242,   748,
     252,   750,   239,   233,     1,   235,   236,   244,   238,   233,
     252,   235,   236,   252,   238,   245,   242,   245,  1220,   846,
     245,   245,   252,   243,   233,   245,   235,   236,   252,   238,
     233,   245,   235,   236,   245,   238,   245,   243,   233,   245,
     235,   236,   245,   238,   243,   243,   242,     1,   242,   242,
     245,   242,  1140,   242,   242,   242,   242,   240,   242,   849,
     242,   241,   852,   242,   236,   233,     1,     1,   242,   859,
     860,   242,   242,   241,   840,   235,   236,     1,     1,   849,
     870,   242,   852,   235,   242,   242,     1,   233,   233,   859,
     860,   242,   236,   859,   860,   235,   483,   484,   859,   860,
     242,   242,   859,   860,   242,   859,   860,   859,   860,  1038,
    1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,     1,
     242,   242,   242,   242,   242,     1,     1,   242,     1,  1053,
     861,   242,   242,  1221,     1,   524,   242,   526,   233,     1,
     242,   236,   236,   235,   236,   242,   241,   241,   236,   229,
     230,   235,   236,   233,   236,     1,   236,   236,     1,   233,
     233,   235,   236,   235,   236,   235,   236,   235,   236,   235,
     236,   235,   236,   236,   236,     1,   236,   236,   236,   236,
     970,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,     1,   236,   236,   236,   930,
     931,   932,   933,   236,   935,   236,   236,   236,   236,   236,
     236,   236,   233,     1,   235,     1,     1,   606,     1,   608,
     233,   233,   235,     1,   233,  1052,  1053,     1,     1,    73,
       1,    73,   229,   230,     1,     1,   233,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,  1038,  1039,
    1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,     1,     1,
       1,     1,     1,     1,     1,   654,   655,     1,  1038,  1039,
    1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,   245,   233,
       1,     1,   675,     1,   671,     1,     1,     1,     1,     1,
       1,     1,  1119,  1120,  1121,  1122,   685,  1124,   233,   233,
       1,     1,     1,     1,     1,     1,     1,     1,     1,   233,
     233,     1,     1,     1,     1,     1,     1,   233,   233,   233,
    1110,   237,   236,   237,  1114,     1,     1,   202,   203,   204,
     205,   206,   207,   208,   209,   201,   642,   253,   233,   253,
     646,   825,   648,   238,   233,     1,   652,   236,   832,     1,
     245,   233,   233,   201,   660,   661,   237,   233,   824,     1,
     233,     1,   751,   170,     1,   831,   233,   247,   248,   229,
     230,   233,   253,   233,   181,     0,   183,   184,   185,   186,
     201,   241,   866,    75,    76,    77,    78,   233,   201,   233,
     233,   233,    41,    42,   238,   233,   238,   235,   236,   201,
     233,   245,   233,   245,   237,   236,   237,   233,    64,    65,
      66,    67,     1,    69,   176,   177,   178,   179,    10,   233,
     253,   235,   253,   201,   235,   236,   237,   233,   202,   203,
     204,   205,   206,   207,  1261,   642,  1226,   244,   201,   646,
      11,   648,   253,    15,   233,   233,   235,   233,   233,   233,
     233,   235,   233,   660,   235,  1245,  1246,   201,  1248,  1249,
     233,  1192,   233,  1253,   229,   230,   233,   233,   233,   233,
     859,   860,   233,   233,   233,   233,   233,   233,   233,   233,
     869,   647,    73,   649,   650,   651,    12,   653,    79,    13,
     233,   233,   233,   233,   233,   233,   233,   201,   233,   233,
     235,   176,   177,   178,   179,    14,   233,  1334,   235,  1336,
    1337,    16,   233,   233,    17,   233,   201,   233,   233,   233,
     233,   233,   233,   233,  1273,   233,   202,   235,  1318,   201,
     201,   207,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   847,   848,   233,   233,   233,   233,   233,   854,   855,
     202,   203,   204,   205,   206,   207,   208,   209,   201,   201,
     252,   201,   201,   201,  1313,   202,   203,   204,   205,   206,
     207,   208,   209,     1,  1364,     3,     4,     5,     6,     7,
       8,     9,    10,     1,  1315,  1316,  1317,   176,   177,   178,
     179,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,   233,    40,   235,   201,   201,    44,    45,    46,    47,
      48,    49,    50,    51,   201,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     1,   201,   201,   229,   230,
     847,   848,   233,   201,   239,     1,   241,   854,   233,   201,
     235,     1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     1,   170,    91,    92,    93,    94,    95,   170,   239,
     239,   241,   241,   181,  1140,   183,   184,   185,   186,   181,
     201,   183,   184,   185,   186,     1,  1152,     3,     4,     5,
       6,     7,     8,     9,    10,   202,   203,   204,   205,   206,
     207,   208,   209,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,   201,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,   244,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,   170,    75,    76,
      77,    78,   229,   230,   201,  1221,   233,   180,   201,   182,
     183,   184,   185,   186,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    18,   201,    91,    92,    93,    94,    95,
     239,   239,   241,   241,   202,   203,   204,   205,   206,   207,
     201,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   201,   229,   230,   201,   235,   233,   237,
     201,   236,   240,   241,   242,   243,   201,   239,   246,   241,
     229,   230,   229,   230,   233,   253,   233,   201,   237,   236,
     201,   239,   241,   241,   201,   236,   202,   203,   204,   205,
     206,   207,   208,   209,   253,  1234,   202,   203,   204,   205,
     206,   207,   202,   203,   204,   205,   206,   207,   239,   239,
     241,   241,   202,   203,   204,   205,   206,   207,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   233,   201,
     235,   236,   462,   238,   201,   465,   233,   467,   201,   236,
     245,   238,   233,   246,   235,   475,   201,   477,   245,   201,
     226,   227,   228,   229,   230,   233,   233,   235,   235,   236,
     239,   238,   241,   201,   239,   239,   241,   241,   245,   235,
     239,   237,   241,   201,   240,   252,   201,     1,   244,     3,
       4,     5,     6,     7,     8,     9,    10,   253,   239,   239,
     241,   241,   201,   201,   201,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,   201,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,   201,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,   201,
     201,   201,   201,   201,   201,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   201,    80,    81,    82,    83,
      84,    85,    86,    87,    88,   241,   201,    91,    92,    93,
      94,    95,     1,   201,     3,     4,     5,     6,     7,     8,
       9,    10,   612,   201,   201,   201,   201,   201,   201,   201,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
     201,    40,   201,   201,   233,    44,    45,    46,    47,    48,
      49,    50,    51,   201,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   201,   201,   201,   201,   201,   201,
     201,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     201,   201,    91,    92,    93,    94,    95,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   201,   233,   233,   233,   233,
     233,   233,   251,   251,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   235,   233,   233,   233,   238,   246,   239,
     249,   235,   233,   237,   251,   251,   240,   235,   251,   233,
     244,   246,   242,   236,   243,   251,   249,   242,    79,   253,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   240,    79,   239,   233,   246,
     246,   239,   246,   246,    39,   246,   243,   246,   241,   241,
     246,   251,   241,   241,   241,   241,   241,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,    73,
      73,   233,   233,   201,   201,   201,   243,   243,   243,   243,
     243,   201,   242,   241,   241,   241,   235,   241,   237,   241,
     241,   240,   239,   241,     1,   244,     3,     4,     5,     6,
       7,     8,     9,    10,   253,   241,   239,   241,   246,   241,
     241,   241,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,   241,    40,   241,   241,   241,    44,    45,    46,
      47,    48,    49,    50,    51,   241,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,   241,   241,   241,   241,
     239,   239,   249,   243,   241,   241,   241,   241,   241,   241,
     201,   241,   241,    80,    81,    82,    83,    84,    85,    86,
      87,    88,   241,   241,    91,    92,    93,    94,    95,     1,
     241,     3,     4,     5,     6,     7,     8,     9,    10,   241,
     241,   241,   241,   241,   241,   241,   241,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,   241,    40,   241,
     241,   241,    44,    45,    46,    47,    48,    49,    50,    51,
     241,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,    80,    81,
      82,    83,    84,    85,    86,    87,    88,   241,   239,    91,
      92,    93,    94,    95,   239,   239,   239,   239,   239,   239,
     248,   239,   241,   239,   239,   239,   201,   236,   241,   241,
     241,   239,   236,   243,   236,   236,   236,   236,   228,    73,
     243,   236,   236,   236,   236,   236,   243,   236,   236,   236,
     236,   236,   236,   233,   233,    41,   239,   201,   235,   241,
     237,   239,   201,   240,   201,   241,   201,   244,   241,   241,
     241,   241,   241,   241,   241,   241,   253,   241,   241,   239,
     239,   201,   239,   241,   239,   241,   239,   241,   201,   201,
     239,   236,   244,   236,   236,   233,   236,   101,   239,   955,
     251,   251,  1138,   251,   236,   241,   239,   241,   239,   239,
     239,   233,   277,   241,   241,   241,   239,   241,   239,   233,
     239,   236,   233,   233,   240,   272,  1236,   289,  1203,    -1,
      -1,   240,    -1,   241,   241,   241,   241,   241,   241,   239,
     236,   239,   241,   240,   236,   240,    -1,   241,   241,    -1,
      -1,    -1,    -1,   235,    -1,   237,    -1,    -1,   240,    -1,
      -1,     1,   244,     3,     4,     5,     6,     7,     8,     9,
      10,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    92,    93,    94,    95,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    92,    93,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,    -1,   237,    -1,    -1,
     240,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     235,    -1,   237,    -1,    -1,   240,    -1,    -1,     1,   244,
       3,     4,     5,     6,     7,     8,     9,    10,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    -1,    91,    92,
      93,    94,    95,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    -1,    91,    92,    93,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   235,    -1,   237,    -1,    -1,   240,    -1,    -1,
      -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,   237,
      -1,    -1,   240,    -1,    -1,     1,   244,     3,     4,     5,
       6,     7,     8,     9,    10,   253,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    -1,    91,    92,    93,    94,    95,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    -1,
      91,    92,    93,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,
      -1,   237,    -1,    -1,   240,    -1,    -1,    -1,   244,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   235,    -1,   237,    -1,    -1,   240,
      -1,    -1,     1,   244,     3,     4,     5,     6,     7,     8,
       9,    10,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    -1,    91,    92,    93,    94,    95,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    -1,    91,    92,    93,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,   237,    -1,
      -1,   240,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   235,    -1,   237,    -1,    -1,   240,    -1,    -1,     1,
     244,     3,     4,     5,     6,     7,     8,     9,    10,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    -1,    91,
      92,    93,    94,    95,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    -1,    91,    92,    93,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,    -1,   237,    -1,    -1,   240,    -1,
      -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,
     237,    -1,    -1,   240,    -1,    -1,     1,   244,     3,     4,
       5,     6,     7,     8,     9,    10,   253,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    92,    93,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     235,    -1,   237,    -1,    -1,   240,    -1,    -1,    -1,   244,
      -1,    -1,    89,    90,    -1,    -1,    -1,    -1,   253,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,   250,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    -1,    91,    92,    93,    94,    95,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    -1,    91,    92,    93,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     229,   230,    -1,   232,   233,    -1,   235,    -1,   237,    -1,
      -1,    -1,    -1,   242,   243,    -1,   245,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    -1,    -1,   229,   230,   231,    -1,   233,    -1,   235,
     236,   237,    -1,    -1,    -1,    -1,   242,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,   253,    91,    92,
      93,    94,    95,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    92,    93,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   235,    -1,   237,    -1,    -1,   240,    -1,    -1,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,    -1,   237,    -1,    -1,
     240,    -1,    -1,    -1,   244,     3,     4,     5,     6,     7,
       8,     9,    10,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    -1,    91,    92,    93,    94,    95,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    92,    93,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,   237,
      -1,    -1,   240,    -1,    -1,    -1,   244,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     235,    -1,   237,    -1,    -1,   240,    -1,    -1,   243,    80,
      81,    82,    83,    84,    85,    86,    87,    88,   253,    -1,
      91,    92,    93,    94,    95,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    -1,    91,    92,    93,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   235,    -1,   237,    -1,    -1,   240,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,   237,
      -1,    -1,   240,    -1,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,   253,    91,    92,    93,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     235,    -1,   237,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    -1,    -1,    -1,    -1,   253,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   250
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    89,    90,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   250,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   277,   278,   283,   285,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,     1,   201,     1,   201,     1,   201,     1,   201,
       1,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,     1,
     236,   201,     1,   242,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   245,   245,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,     1,   201,     1,   201,   201,   201,
     201,   201,   201,     0,     1,   257,    10,   293,    11,   294,
      12,   295,    13,   296,    14,   297,    15,   298,    16,   299,
      17,   300,    18,   301,     1,   233,     1,   233,     1,   229,
     230,   233,   270,     1,   233,     1,   233,     1,   235,     1,
     236,     1,   236,     1,    75,    76,    77,    78,   233,   235,
     236,   238,   245,   252,   267,   268,   271,   273,   274,   279,
     280,   281,   282,   314,     1,   267,     1,   233,     1,   271,
     272,     1,   233,     1,   233,     1,   233,   233,   233,   233,
     233,   233,     1,   233,     1,   233,     1,   233,     1,   233,
       1,   233,     1,   233,     1,   233,     1,   233,     1,   233,
       1,   233,     1,   233,     1,   233,     1,   233,     1,   233,
       1,   233,     1,   236,     1,   236,     1,   236,   236,     1,
     233,     1,   235,   236,     1,   235,   236,     1,   235,   236,
       1,   235,   236,     1,   233,     1,   233,     1,   233,     1,
     233,     1,   233,     1,   233,     1,   233,     1,   233,     1,
     233,     1,   233,     1,   233,     1,   233,     1,   235,   236,
       1,   233,     1,   233,     1,   233,   235,     1,   233,     1,
     233,     1,   233,     1,   233,     1,   233,     1,   233,     1,
     233,     1,   233,     1,   233,     1,   176,   177,   178,   179,
       1,   233,     1,   233,   279,   236,   279,     1,   236,     1,
     233,     1,   233,     1,   233,     1,   236,     1,   236,     1,
     236,     1,   236,     1,   267,     1,   233,     1,   233,     1,
     233,     1,   233,     1,   233,     1,   233,   235,   233,   233,
     235,   233,     1,   236,     1,   236,     1,   233,     1,   243,
     245,     1,   245,     1,   243,   245,     1,   245,     1,   243,
       1,   243,     1,   243,     1,   245,     1,   245,   233,   233,
     249,   281,   251,   251,   247,   248,   274,   229,   249,   313,
     251,   272,   239,   251,   246,   251,   251,     3,     4,     5,
       6,     7,     8,     9,    10,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    40,    44,    45,    46,    47,
      48,    49,    50,    51,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    91,    92,    93,    94,    95,   235,   237,
     240,   253,   309,   317,   320,   321,   322,   323,   324,   331,
     233,   235,   236,   292,   292,   320,   292,   292,   320,   320,
     320,   292,   292,   233,   246,     1,   233,   252,   269,   267,
     267,   233,     1,   235,   269,   236,   269,   287,   269,   243,
       1,   242,     1,   242,   242,   242,   242,     1,   242,     1,
     242,     1,   242,     1,   242,     1,   242,     1,   242,     1,
     242,     1,   242,   242,   242,   242,     1,   242,     1,   242,
       1,   242,     1,   242,   242,     1,   242,   242,   242,   242,
     242,   242,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,   232,   242,   243,   245,   270,   302,
     308,   309,   310,   311,   317,   318,   322,   331,   242,   302,
       1,   242,     1,   242,     1,   242,     1,   242,     1,   242,
       1,   242,     1,   242,     1,   242,     1,   242,     1,   242,
       1,   242,     1,   242,     1,   242,     1,   242,     1,   242,
       1,   242,     1,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,     1,   242,
     201,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     315,   240,     1,   244,   321,     1,   240,   246,   246,   244,
     246,   246,   244,   244,   244,   239,   246,   249,   251,   248,
     251,   239,   246,   243,   246,   232,   242,   275,   276,     1,
     236,   241,     1,   236,   241,   241,   241,   270,   309,     1,
     236,   270,     1,   236,     1,   292,     1,   236,     1,   236,
       1,   236,     1,   233,     1,   233,   236,   241,   233,   309,
     236,   309,     1,   236,     1,   236,     1,   236,     1,   236,
     241,     1,   236,   241,   241,   241,   241,     1,   233,   241,
       1,   202,   203,   204,   205,   206,   207,   208,   209,   303,
     304,   305,   307,     1,   303,   307,     1,   303,   304,   306,
       1,   303,   307,     1,   306,     1,   306,     1,   306,     1,
     303,     1,   306,   302,   302,   244,   320,    67,    69,   231,
     235,   236,   242,   270,   308,   309,   311,   316,   331,   219,
     220,   243,   319,   321,     1,   303,   307,   303,   304,   306,
     307,   309,   319,     1,   267,     1,   233,     1,   271,     1,
     233,     1,   241,     1,   236,     1,   236,   241,   270,   233,
     235,   233,   235,   233,   235,   233,   235,   233,   235,   233,
     235,   233,   235,   233,   235,   233,   235,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   309,
     233,   241,     1,   233,   236,   241,   329,    79,    79,   316,
     243,   243,   243,   243,   233,   243,   233,   269,   233,   269,
     236,   270,   284,   170,   181,   183,   184,   185,   186,   289,
     291,   286,   242,   268,     1,   239,   244,   241,   241,   241,
     239,   241,   241,   241,   241,   241,   239,   241,   239,   241,
     239,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   239,   241,   241,   241,   239,   239,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
       1,   235,   236,    73,   279,   312,     1,   236,   314,     1,
     233,    73,   312,     1,   236,   314,     1,   233,     1,   268,
       1,   233,     1,    67,    69,   308,     1,    52,   233,   241,
     244,   303,   307,   303,   307,   316,   316,   307,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   246,   302,
     302,   244,   320,    39,    73,     1,   236,   314,    73,    79,
     270,   235,   236,   309,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   239,   241,   241,   239,   241,
     241,   239,   241,   241,   241,   241,   241,   241,   241,   241,
     239,   239,   239,   239,   239,   239,   239,   241,   239,   241,
     239,   241,   239,   239,   239,   239,   241,   239,   241,   320,
     320,   320,   320,   246,   320,   249,   248,   241,   241,   243,
     201,   201,   201,   201,   201,   201,   244,   291,   243,   268,
     239,   275,   236,   236,   236,   233,   236,   309,   330,   236,
     236,   236,   228,   241,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   244,   319,   243,   233,   235,   233,
     235,   233,   235,   236,   236,   236,   236,   236,   236,   236,
     236,   309,   236,   236,   309,   236,   233,   236,   244,   244,
     244,   244,   243,   244,   233,   233,   170,   180,   182,   183,
     184,   185,   186,   288,   290,     1,   176,   177,   178,   179,
       1,   233,     1,   236,     1,   236,     1,   236,     1,   236,
     289,   239,   312,   241,   241,   241,   239,   241,   241,   241,
     241,     1,   233,   279,    41,   325,   326,   327,   241,   241,
     241,   241,   241,   241,   239,   239,   239,   241,   239,   239,
     239,   241,   241,   239,   241,   239,   241,   239,   241,   239,
     241,   320,   201,   201,   201,   201,   201,   201,   201,   244,
     290,   244,   312,   239,   233,   236,   309,   236,   270,   244,
      42,   327,   328,   236,   309,   309,   233,   309,   233,   309,
     236,   309,   233,   236,   236,   244,     1,   176,   177,   178,
     179,     1,   233,     1,   233,     1,   236,     1,   236,     1,
     236,     1,   236,   239,   269,   251,   251,   251,   239,   241,
     241,   241,   239,   239,   239,   239,   241,   241,   241,   239,
     241,   269,   239,    43,   320,    43,   320,   320,   233,   309,
     233,   233,   233,   233,   236,   239,   236,   240,    43,   240,
      43,   241,   241,   241,   241,   241,   241,   239,   236,   241,
     240,   240,   236,   241,   239,   309,   241
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
        case 3:

/* Line 1806 of yacc.c  */
#line 493 "cfg.y"
    {}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 494 "cfg.y"
    {}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 495 "cfg.y"
    { yyerror(""); YYABORT;}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 500 "cfg.y"
    {rt=REQUEST_ROUTE;}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 501 "cfg.y"
    {rt=FAILURE_ROUTE;}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 502 "cfg.y"
    {rt=ONREPLY_ROUTE;}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 503 "cfg.y"
    {rt=BRANCH_ROUTE;}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 504 "cfg.y"
    {rt=ERROR_ROUTE;}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 505 "cfg.y"
    {rt=LOCAL_ROUTE;}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 506 "cfg.y"
    {rt=STARTUP_ROUTE;}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 507 "cfg.y"
    {rt=TIMER_ROUTE;}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 508 "cfg.y"
    {rt=EVENT_ROUTE;}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 513 "cfg.y"
    {	tmp=ip_addr2a((yyvsp[(1) - (1)].ipaddr));
							if(tmp==0){
								LM_CRIT("cfg. parser: bad ip address.\n");
								(yyval.strval)=0;
							}else{
								(yyval.strval)=pkg_malloc(strlen(tmp)+1);
								if ((yyval.strval)==0){
									LM_CRIT("cfg. parser: out of memory.\n");
								}else{
									strncpy((yyval.strval), tmp, strlen(tmp)+1);
								}
							}
						}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 526 "cfg.y"
    {	(yyval.strval)=pkg_malloc(strlen((yyvsp[(1) - (1)].strval))+1);
							if ((yyval.strval)==0){
									LM_CRIT("cfg. parser: out of memory.\n");
							}else{
									strncpy((yyval.strval), (yyvsp[(1) - (1)].strval), strlen((yyvsp[(1) - (1)].strval))+1);
							}
						}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 533 "cfg.y"
    {	if ((yyvsp[(1) - (1)].strval)==0) {
								(yyval.strval) = 0;
							} else {
								(yyval.strval)=pkg_malloc(strlen((yyvsp[(1) - (1)].strval))+1);
								if ((yyval.strval)==0){
									LM_CRIT("cfg. parser: out of memory.\n");
								}else{
									strncpy((yyval.strval), (yyvsp[(1) - (1)].strval), strlen((yyvsp[(1) - (1)].strval))+1);
								}
							}
						}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 546 "cfg.y"
    { (yyval.intval)=PROTO_UDP; }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 547 "cfg.y"
    { (yyval.intval)=PROTO_TCP; }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 548 "cfg.y"
    {
			#ifdef USE_TLS
				(yyval.intval)=PROTO_TLS;
			#else
				(yyval.intval)=PROTO_TCP;
				warn("tls support not compiled in");
			#endif
			}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 556 "cfg.y"
    { 
			#ifdef USE_SCTP
				(yyval.intval)=PROTO_SCTP;
			#else
				yyerror("sctp support not compiled in\n");YYABORT;
			#endif
			}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 563 "cfg.y"
    { (yyval.intval)=0; }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 566 "cfg.y"
    { (yyval.intval)=(yyvsp[(1) - (1)].intval); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 567 "cfg.y"
    { (yyval.intval)=0; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 570 "cfg.y"
    { (yyval.intval)=(yyvsp[(1) - (1)].intval); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 571 "cfg.y"
    { (yyval.intval)=(yyvsp[(2) - (2)].intval); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 572 "cfg.y"
    { (yyval.intval)=-(yyvsp[(2) - (2)].intval); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 576 "cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[(1) - (1)].strval), 0, 0); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 577 "cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[(1) - (3)].strval), 0, (yyvsp[(3) - (3)].intval)); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 578 "cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[(3) - (3)].strval), (yyvsp[(1) - (3)].intval), 0); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 579 "cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[(3) - (5)].strval), (yyvsp[(1) - (5)].intval), (yyvsp[(5) - (5)].intval));}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 580 "cfg.y"
    { (yyval.sockid)=0; yyerror(" port number expected"); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 583 "cfg.y"
    {  (yyval.sockid)=(yyvsp[(1) - (1)].sockid) ; }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 584 "cfg.y"
    { (yyval.sockid)=(yyvsp[(1) - (2)].sockid); (yyval.sockid)->next=(yyvsp[(2) - (2)].sockid); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 588 "cfg.y"
    { (yyval.sockid)=(yyvsp[(1) - (1)].sockid); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 589 "cfg.y"
    { (yyval.sockid)=(yyvsp[(1) - (3)].sockid); (yyval.sockid)->children=(yyvsp[(3) - (3)].intval); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 590 "cfg.y"
    { (yyval.sockid)=(yyvsp[(1) - (3)].sockid); set_listen_id_adv((struct socket_id *)(yyvsp[(1) - (3)].sockid), (yyvsp[(3) - (3)].strval), 5060); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 591 "cfg.y"
    { (yyval.sockid)=(yyvsp[(1) - (5)].sockid); set_listen_id_adv((struct socket_id *)(yyvsp[(1) - (5)].sockid), (yyvsp[(3) - (5)].strval), 5060); (yyvsp[(1) - (5)].sockid)->children=(yyvsp[(5) - (5)].intval); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 592 "cfg.y"
    { (yyval.sockid)=(yyvsp[(1) - (5)].sockid); set_listen_id_adv((struct socket_id *)(yyvsp[(1) - (5)].sockid), (yyvsp[(3) - (5)].strval), (yyvsp[(5) - (5)].intval)); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 593 "cfg.y"
    { (yyval.sockid)=(yyvsp[(1) - (7)].sockid); set_listen_id_adv((struct socket_id *)(yyvsp[(1) - (7)].sockid), (yyvsp[(3) - (7)].strval), (yyvsp[(5) - (7)].intval)); (yyvsp[(1) - (7)].sockid)->children=(yyvsp[(7) - (7)].intval); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 596 "cfg.y"
    {  (yyval.sockid)=(yyvsp[(1) - (1)].sockid) ; }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 597 "cfg.y"
    { (yyval.sockid)=(yyvsp[(1) - (2)].sockid); (yyval.sockid)->next=(yyvsp[(2) - (2)].sockid); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 601 "cfg.y"
    {
				s_tmp.s=(yyvsp[(8) - (9)].strval);
				s_tmp.len=strlen((yyvsp[(8) - (9)].strval));
				if (add_rule_to_list(&bl_head,&bl_tail,(yyvsp[(4) - (9)].ipnet),&s_tmp,(yyvsp[(6) - (9)].intval),(yyvsp[(2) - (9)].intval),0)) {
					yyerror("failed to add backlist element\n");YYABORT;
				}
			}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 608 "cfg.y"
    {
				s_tmp.s=(yyvsp[(9) - (10)].strval);
				s_tmp.len=strlen((yyvsp[(9) - (10)].strval));
				if (add_rule_to_list(&bl_head,&bl_tail,(yyvsp[(5) - (10)].ipnet),&s_tmp,
				(yyvsp[(7) - (10)].intval),(yyvsp[(3) - (10)].intval),BLR_APPLY_CONTRARY)) {
					yyerror("failed to add backlist element\n");YYABORT;
				}
			}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 618 "cfg.y"
    {}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 619 "cfg.y"
    {}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 620 "cfg.y"
    { yyerror("bad black list element");}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 624 "cfg.y"
    { 
#ifdef CHANGEABLE_DEBUG_LEVEL
					*debug=(yyvsp[(3) - (3)].intval);
#else
					debug=(yyvsp[(3) - (3)].intval);
#endif
			}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 631 "cfg.y"
    { yyerror("number  expected"); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 632 "cfg.y"
    { dont_fork= !dont_fork ? ! (yyvsp[(3) - (3)].intval):1; }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 633 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 634 "cfg.y"
    { if (!config_check) log_stderr=(yyvsp[(3) - (3)].intval); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 635 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 636 "cfg.y"
    {
					if ( (i_tmp=str2facility((yyvsp[(3) - (3)].strval)))==-1)
						yyerror("bad facility (see syslog(3) man page)");
					if (!config_check)
						log_facility=i_tmp;
									}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 642 "cfg.y"
    { yyerror("ID expected"); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 643 "cfg.y"
    { log_name=(yyvsp[(3) - (3)].strval); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 644 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 645 "cfg.y"
    { 
				yyerror("AVP_ALIASES shouldn't be used anymore\n");
			}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 648 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 649 "cfg.y"
    { received_dns|= ((yyvsp[(3) - (3)].intval))?DO_DNS:0; }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 650 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 651 "cfg.y"
    { received_dns|= ((yyvsp[(3) - (3)].intval))?DO_REV_DNS:0; }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 652 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 653 "cfg.y"
    { dns_try_ipv6=(yyvsp[(3) - (3)].intval); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 654 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 655 "cfg.y"
    { dns_retr_time=(yyvsp[(3) - (3)].intval); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 656 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 657 "cfg.y"
    { dns_retr_no=(yyvsp[(3) - (3)].intval); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 658 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 659 "cfg.y"
    { dns_servers_no=(yyvsp[(3) - (3)].intval); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 660 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 661 "cfg.y"
    { dns_search_list=(yyvsp[(3) - (3)].intval); }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 662 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 663 "cfg.y"
    { port_no=(yyvsp[(3) - (3)].intval); }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 664 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 665 "cfg.y"
    { max_while_loops=(yyvsp[(3) - (3)].intval); }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 666 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 667 "cfg.y"
    { maxbuffer=(yyvsp[(3) - (3)].intval); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 668 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 669 "cfg.y"
    { children_no=(yyvsp[(3) - (3)].intval); }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 670 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 671 "cfg.y"
    { check_via=(yyvsp[(3) - (3)].intval); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 672 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 673 "cfg.y"
    { memlog=(yyvsp[(3) - (3)].intval); memdump=(yyvsp[(3) - (3)].intval); }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 674 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 675 "cfg.y"
    { memdump=(yyvsp[(3) - (3)].intval); }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 676 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 677 "cfg.y"
    { execmsgthreshold=(yyvsp[(3) - (3)].intval); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 678 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 679 "cfg.y"
    { execdnsthreshold=(yyvsp[(3) - (3)].intval); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 680 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 681 "cfg.y"
    { tcpthreshold=(yyvsp[(3) - (3)].intval); }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 682 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 683 "cfg.y"
    {
			#ifdef SHM_MEM
				#ifdef STATISTICS
					if ((yyvsp[(3) - (3)].intval) < 0 || (yyvsp[(3) - (3)].intval) > 100)
						yyerror("SHM threshold has to be a percentage between 0 and 100");
					event_shm_threshold=(yyvsp[(3) - (3)].intval);
				#else
					yyerror("statistics support not compiled in");
				#endif /* STATISTICS */
			#else /* SHM_MEM */
				yyerror("shm memory support not compiled in");
			#endif
			}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 696 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 697 "cfg.y"
    {
			#ifdef PKG_MEM
                                #ifdef STATISTICS
                                        if ((yyvsp[(3) - (3)].intval) < 0 || (yyvsp[(3) - (3)].intval) > 100)
                                                yyerror("PKG threshold has to be a percentage between 0 and 100");
                                        event_pkg_threshold=(yyvsp[(3) - (3)].intval);
                                #else
                                        yyerror("statistics support not compiled in");
                                #endif
			#else /* PKG_MEM */
				yyerror("pkg memory support not compiled in");
			#endif
			}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 710 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 711 "cfg.y"
    { query_buffer_size=(yyvsp[(3) - (3)].intval); }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 712 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 713 "cfg.y"
    { query_flush_time=(yyvsp[(3) - (3)].intval); }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 714 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 715 "cfg.y"
    { sip_warning=(yyvsp[(3) - (3)].intval); }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 716 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 717 "cfg.y"
    { user=(yyvsp[(3) - (3)].strval); }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 718 "cfg.y"
    { user=(yyvsp[(3) - (3)].strval); }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 719 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 720 "cfg.y"
    { group=(yyvsp[(3) - (3)].strval); }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 721 "cfg.y"
    { group=(yyvsp[(3) - (3)].strval); }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 722 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 723 "cfg.y"
    { chroot_dir=(yyvsp[(3) - (3)].strval); }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 724 "cfg.y"
    { chroot_dir=(yyvsp[(3) - (3)].strval); }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 725 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 726 "cfg.y"
    { working_dir=(yyvsp[(3) - (3)].strval); }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 727 "cfg.y"
    { working_dir=(yyvsp[(3) - (3)].strval); }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 728 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 729 "cfg.y"
    { mhomed=(yyvsp[(3) - (3)].intval); }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 730 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 731 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_disable=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 738 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 739 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_async=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 746 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 747 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_async_local_connect_timeout=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 754 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 755 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_async_local_write_timeout=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 762 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 763 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_async_max_postponed_chunks=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 770 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 771 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_accept_aliases=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 778 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 779 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_children_no=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 786 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 787 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_connect_timeout=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 794 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 795 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_send_timeout=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 802 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 803 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_con_lifetime=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 810 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 811 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_listen_backlog=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 818 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 819 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_poll_method=get_poll_type((yyvsp[(3) - (3)].strval));
										if (tcp_poll_method==POLL_NONE){
											LM_CRIT("bad poll method name:"
												" %s\n, try one of %s.\n",
												(yyvsp[(3) - (3)].strval), poll_support);
											yyerror("bad tcp_poll_method "
												"value");
										}
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 833 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_poll_method=get_poll_type((yyvsp[(3) - (3)].strval));
										if (tcp_poll_method==POLL_NONE){
											LM_CRIT("bad poll method name:"
												" %s\n, try one of %s.\n",
												(yyvsp[(3) - (3)].strval), poll_support);
											yyerror("bad tcp_poll_method "
												"value");
										}
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 847 "cfg.y"
    { yyerror("poll method name expected"); }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 848 "cfg.y"
    {
									#ifdef USE_TCP
										tcp_max_connections=(yyvsp[(3) - (3)].intval);
									#else
										warn("tcp support not compiled in");
									#endif
									}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 855 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 856 "cfg.y"
    {
			#ifdef USE_TCP
				tcp_crlf_pingpong=(yyvsp[(3) - (3)].intval);
			#else
				warn("tcp support not compiled in");
			#endif
		}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 863 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 864 "cfg.y"
    {
			#ifdef USE_TCP
				fix_flag_name(&tmp, (yyvsp[(3) - (3)].intval));
				tcp_no_new_conn_bflag = get_flag_id_by_name(FLAG_TYPE_BRANCH, tmp);
				if (!flag_in_range( (flag_t)tcp_no_new_conn_bflag ) )
					yyerror("invalid TCP no_new_conn Branch Flag");
				flag_idx2mask( &tcp_no_new_conn_bflag );
			#else
				warn("tcp support not compiled in");
			#endif
		}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 875 "cfg.y"
    {
			#ifdef USE_TCP
				tcp_no_new_conn_bflag = get_flag_id_by_name(FLAG_TYPE_BRANCH, (yyvsp[(3) - (3)].strval));
				if (!flag_in_range( (flag_t)tcp_no_new_conn_bflag ) )
					yyerror("invalid TCP no_new_conn Branch Flag");
				flag_idx2mask( &tcp_no_new_conn_bflag );
			#else
				warn("tcp support not compiled in");
			#endif
		}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 885 "cfg.y"
    { yyerror("number value expected"); }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 886 "cfg.y"
    {
			#ifdef USE_TCP
			        tcp_keepalive=(yyvsp[(3) - (3)].intval);
			#else
				warn("tcp support not compiled in");
			#endif
		}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 893 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 894 "cfg.y"
    {
			#ifdef USE_TCP
			        tcp_max_msg_chunks=(yyvsp[(3) - (3)].intval);
			#else
				warn("tcp support not compiled in");
			#endif
		}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 901 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 902 "cfg.y"
    {
			#ifdef USE_TCP
			        tcp_max_msg_time=(yyvsp[(3) - (3)].intval);
			#else
				warn("tcp support not compiled in");
			#endif
		}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 909 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 910 "cfg.y"
    { 
			#ifdef USE_TCP
			    #ifndef HAVE_TCP_KEEPCNT
				warn("cannot be enabled (no OS support)");
			    #else
			        tcp_keepcount=(yyvsp[(3) - (3)].intval);
			    #endif
		        #else
				warn("tcp support not compiled in");
			#endif
		}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 921 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 922 "cfg.y"
    { 
			#ifdef USE_TCP
			    #ifndef HAVE_TCP_KEEPIDLE
				warn("cannot be enabled (no OS support)");
			    #else
			        tcp_keepidle=(yyvsp[(3) - (3)].intval);
			    #endif
		        #else
				warn("tcp support not compiled in");
			#endif
		}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 933 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 934 "cfg.y"
    { 
			#ifdef USE_TCP
			    #ifndef HAVE_TCP_KEEPINTVL
				warn("cannot be enabled (no OS support)");
			    #else
			        tcp_keepinterval=(yyvsp[(3) - (3)].intval);
			    #endif
		        #else
				warn("tcp support not compiled in");
			#endif
		}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 945 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 946 "cfg.y"
    {
									#ifdef USE_TLS
										tls_disable=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 953 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 954 "cfg.y"
    { 
									#ifdef USE_TLS
										tls_log=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 961 "cfg.y"
    { yyerror("int value expected"); }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 962 "cfg.y"
    {
									#ifdef USE_TLS
										tls_port_no=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 969 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 970 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->method =
											TLS_USE_SSLv23;
										tls_default_client_domain->method =
											TLS_USE_SSLv23;
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 980 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->method =
											TLS_USE_SSLv2;
										tls_default_client_domain->method =
											TLS_USE_SSLv2;
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 990 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->method =
											TLS_USE_SSLv3;
										tls_default_client_domain->method =
											TLS_USE_SSLv3;
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1000 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->method =
											TLS_USE_TLSv1;
										tls_default_client_domain->method =
											TLS_USE_TLSv1;
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 1010 "cfg.y"
    {
									#ifdef USE_TLS
										yyerror("SSLv23, SSLv2, SSLv3 or TLSv1"
													" expected");
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 1019 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->verify_cert
											= (yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 1027 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1028 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_client_domain->verify_cert
											=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1036 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 1037 "cfg.y"
    {
									#ifdef USE_TLS
										tls_default_server_domain->require_client_cert=(yyvsp[(3) - (3)].intval);
									#else
										warn( "tls support not compiled in");
									#endif
									}
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 1044 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 1045 "cfg.y"
    { 
									#ifdef USE_TLS
										tls_default_server_domain->cert_file=
											(yyvsp[(3) - (3)].strval);
										tls_default_client_domain->cert_file=
											(yyvsp[(3) - (3)].strval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 1055 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 1056 "cfg.y"
    { 
									#ifdef USE_TLS
										tls_default_server_domain->pkey_file=
											(yyvsp[(3) - (3)].strval);
										tls_default_client_domain->pkey_file=
											(yyvsp[(3) - (3)].strval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 1066 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 1067 "cfg.y"
    { 
									#ifdef USE_TLS
										tls_default_server_domain->ca_file =
											(yyvsp[(3) - (3)].strval);
										tls_default_client_domain->ca_file =
											(yyvsp[(3) - (3)].strval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 1077 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 1078 "cfg.y"
    { 
									#ifdef USE_TLS
										tls_default_server_domain->ciphers_list
											= (yyvsp[(3) - (3)].strval);
										tls_default_client_domain->ciphers_list
											= (yyvsp[(3) - (3)].strval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 1088 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 1089 "cfg.y"
    {
									#ifdef USE_TLS
										tls_handshake_timeout=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 1096 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 1097 "cfg.y"
    {
									#ifdef USE_TLS
										tls_send_timeout=(yyvsp[(3) - (3)].intval);
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 1104 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 203:

/* Line 1806 of yacc.c  */
#line 1105 "cfg.y"
    {
									#ifdef USE_TLS
										tstr.s = (yyvsp[(3) - (3)].strval);
										tstr.len = strlen(tstr.s);
										if (parse_avp_spec(&tstr, &tls_client_domain_avp)) {
											yyerror("cannot parse tls_client_avp");
										}
									#else
										warn("tls support not compiled in");
									#endif
									}
    break;

  case 204:

/* Line 1806 of yacc.c  */
#line 1116 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 1119 "cfg.y"
    { server_signature=(yyvsp[(3) - (3)].intval); }
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 1120 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 1121 "cfg.y"
    { server_header.s=(yyvsp[(3) - (3)].strval);
									server_header.len=strlen((yyvsp[(3) - (3)].strval));
									}
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 1124 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 1125 "cfg.y"
    { user_agent_header.s=(yyvsp[(3) - (3)].strval);
									user_agent_header.len=strlen((yyvsp[(3) - (3)].strval));
									}
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 1128 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 1129 "cfg.y"
    { xlog_buf_size = (yyvsp[(3) - (3)].intval); }
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 1130 "cfg.y"
    { xlog_force_color = (yyvsp[(3) - (3)].intval); }
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 1131 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 1132 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 1133 "cfg.y"
    {
							for(lst_tmp=(yyvsp[(3) - (3)].sockid); lst_tmp; lst_tmp=lst_tmp->next){
								if (add_listen_iface(	lst_tmp->name,
														lst_tmp->port,
														lst_tmp->proto,
														lst_tmp->adv_name,
														lst_tmp->adv_port,
														lst_tmp->children,
														0
													)!=0){
									LM_CRIT("cfg. parser: failed"
											" to add listen address\n");
									break;
								}
							}
							 }
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1149 "cfg.y"
    { yyerror("ip address or hostname "
						"expected (use quotes if the hostname includes"
						" config keywords)"); }
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1152 "cfg.y"
    {
					if (bin) {
						yyerror("can only define one binary packet interface");
						YYABORT;
					}

					lst_tmp = mk_listen_id((yyvsp[(3) - (5)].strval), PROTO_UDP, (yyvsp[(5) - (5)].intval));
					bin = new_sock_info(lst_tmp->name,
										lst_tmp->port,
										lst_tmp->proto,
										lst_tmp->adv_name,
										lst_tmp->adv_port,
										lst_tmp->children,
										0);
					if (!bin) {
						LM_CRIT("Failed to create new socket info!\n");
						YYABORT;
					}
							}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 1171 "cfg.y"
    { yyerror("ip address or hostname "
						"expected (use quotes if the hostname includes"
						" config keywords)"); }
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 1174 "cfg.y"
    { bin_children=(yyvsp[(3) - (3)].intval); }
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 1175 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 1176 "cfg.y"
    { 
							for(lst_tmp=(yyvsp[(3) - (3)].sockid); lst_tmp; lst_tmp=lst_tmp->next)
								add_alias(lst_tmp->name, strlen(lst_tmp->name),
											lst_tmp->port, lst_tmp->proto);
							  }
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 1181 "cfg.y"
    { yyerror("hostname expected (use quotes"
							" if the hostname includes config keywords)"); }
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1183 "cfg.y"
    { auto_aliases=(yyvsp[(3) - (3)].intval); }
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 1184 "cfg.y"
    { yyerror("number  expected"); }
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 1185 "cfg.y"
    {
								if ((yyvsp[(3) - (3)].strval)) {
									default_global_address.s=(yyvsp[(3) - (3)].strval);
									default_global_address.len=strlen((yyvsp[(3) - (3)].strval));
								}
								}
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 1191 "cfg.y"
    {yyerror("ip address or hostname "
												"expected"); }
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 1193 "cfg.y"
    {
								tmp=int2str((yyvsp[(3) - (3)].intval), &i_tmp);
								if ((default_global_port.s=pkg_malloc(i_tmp))
										==0){
										LM_CRIT("cfg. parser: out of memory.\n");
										default_global_port.len=0;
								}else{
									default_global_port.len=i_tmp;
									memcpy(default_global_port.s, tmp,
											default_global_port.len);
								};
								}
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 1205 "cfg.y"
    {yyerror("ip address or hostname "
												"expected"); }
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 1207 "cfg.y"
    {
										disable_core_dump=(yyvsp[(3) - (3)].intval);
									}
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 1210 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 233:

/* Line 1806 of yacc.c  */
#line 1211 "cfg.y"
    {
										open_files_limit=(yyvsp[(3) - (3)].intval);
									}
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 1214 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 1215 "cfg.y"
    {
								#ifdef USE_MCAST
										mcast_loopback=(yyvsp[(3) - (3)].intval);
								#else
									warn("no multicast support compiled in");
								#endif
		  }
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 1222 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 1223 "cfg.y"
    {
								#ifdef USE_MCAST
										mcast_ttl=(yyvsp[(3) - (3)].intval);
								#else
									warn("no multicast support compiled in");
								#endif
		  }
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 1230 "cfg.y"
    { yyerror("number expected as tos"); }
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 1231 "cfg.y"
    { tos = (yyvsp[(3) - (3)].intval);
							if (tos<=0)
								yyerror("invalid tos value");
		 }
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 1235 "cfg.y"
    { if (strcasecmp((yyvsp[(3) - (3)].strval),"IPTOS_LOWDELAY")) {
								tos=IPTOS_LOWDELAY;
							} else if (strcasecmp((yyvsp[(3) - (3)].strval),"IPTOS_THROUGHPUT")) {
								tos=IPTOS_THROUGHPUT;
							} else if (strcasecmp((yyvsp[(3) - (3)].strval),"IPTOS_RELIABILITY")) {
								tos=IPTOS_RELIABILITY;
#if defined(IPTOS_MINCOST)
							} else if (strcasecmp((yyvsp[(3) - (3)].strval),"IPTOS_MINCOST")) {
								tos=IPTOS_MINCOST;
#endif
#if defined(IPTOS_LOWCOST)
							} else if (strcasecmp((yyvsp[(3) - (3)].strval),"IPTOS_LOWCOST")) {
								tos=IPTOS_LOWCOST;
#endif
							} else {
								yyerror("invalid tos value - allowed: "
									"IPTOS_LOWDELAY,IPTOS_THROUGHPUT,"
									"IPTOS_RELIABILITY"
#if defined(IPTOS_LOWCOST)
									",IPTOS_LOWCOST"
#endif
#if defined(IPTOS_MINCOST)
									",IPTOS_MINCOST"
#endif
									"\n");
							}
		 }
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 1262 "cfg.y"
    { yyerror("number expected"); }
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 1263 "cfg.y"
    { mpath=(yyvsp[(3) - (3)].strval); strcpy(mpath_buf, (yyvsp[(3) - (3)].strval));
								mpath_len=strlen((yyvsp[(3) - (3)].strval)); 
								if(mpath_buf[mpath_len-1]!='/') {
									mpath_buf[mpath_len]='/';
									mpath_len++;
									mpath_buf[mpath_len]='\0';
								}
							}
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 1271 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 1272 "cfg.y"
    {
										disable_dns_failover=(yyvsp[(3) - (3)].intval);
									}
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 1275 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 1276 "cfg.y"
    {
										disable_dns_blacklist=(yyvsp[(3) - (3)].intval);
									}
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 1279 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 1280 "cfg.y"
    {
				s_tmp.s = (yyvsp[(3) - (7)].strval);
				s_tmp.len = strlen((yyvsp[(3) - (7)].strval));
				if ( create_bl_head( BL_CORE_ID, BL_READONLY_LIST,
				bl_head, bl_tail, &s_tmp)==0) {
					yyerror("failed to create blacklist\n");
					YYABORT;
				}
				bl_head = bl_tail = 0;
				}
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 1290 "cfg.y"
    {
				sl_fwd_disabled=(yyvsp[(3) - (3)].intval);
				}
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 1293 "cfg.y"
    { db_version_table=(yyvsp[(3) - (3)].strval); }
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 1294 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 1295 "cfg.y"
    { db_default_url=(yyvsp[(3) - (3)].strval); }
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 1296 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 1297 "cfg.y"
    { disable_503_translation=(yyvsp[(3) - (3)].intval); }
    break;

  case 255:

/* Line 1806 of yacc.c  */
#line 1298 "cfg.y"
    {
				yyerror("string value expected");
				}
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 1301 "cfg.y"
    { yyerror("unknown config variable"); }
    break;

  case 257:

/* Line 1806 of yacc.c  */
#line 1304 "cfg.y"
    {
			if(*(yyvsp[(2) - (2)].strval)!='/' && mpath!=NULL
					&& strlen((yyvsp[(2) - (2)].strval))+mpath_len<255)
			{
				strcpy(mpath_buf+mpath_len, (yyvsp[(2) - (2)].strval));
				if (stat(mpath_buf, &statf) == -1) {
					i_tmp = strlen(mpath_buf);
					if(strchr((yyvsp[(2) - (2)].strval), '/')==NULL &&
							strncmp(mpath_buf+i_tmp-3, ".so", 3)==0)
					{
						if(i_tmp+strlen((yyvsp[(2) - (2)].strval))<255)
						{
							strcpy(mpath_buf+i_tmp-3, "/");
							strcpy(mpath_buf+i_tmp-2, (yyvsp[(2) - (2)].strval));
							if (stat(mpath_buf, &statf) == -1) {
								mpath_buf[mpath_len]='\0';
								LM_ERR("module '%s' not found in '%s'\n",
									(yyvsp[(2) - (2)].strval), mpath_buf);
								yyerror("failed to load module");
							}
						} else {
							yyerror("failed to load module - path too long");
						}
					} else {
						yyerror("failed to load module - not found");
					}
				}
				LM_DBG("loading module %s\n", mpath_buf);
				if (sr_load_module(mpath_buf)!=0){
					yyerror("failed to load module");
				}
				mpath_buf[mpath_len]='\0';
			} else {
				LM_DBG("loading module %s\n", (yyvsp[(2) - (2)].strval));
				if (sr_load_module((yyvsp[(2) - (2)].strval))!=0){
					yyerror("failed to load module");
				}
			}
		}
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 1343 "cfg.y"
    { yyerror("string expected");  }
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 1344 "cfg.y"
    {
				if (set_mod_param_regex((yyvsp[(3) - (8)].strval), (yyvsp[(5) - (8)].strval), STR_PARAM, (yyvsp[(7) - (8)].strval)) != 0) {
					yyerrorf("Parameter <%s> not found in module <%s> - can't set",
						(yyvsp[(5) - (8)].strval), (yyvsp[(3) - (8)].strval));
				}
			}
    break;

  case 260:

/* Line 1806 of yacc.c  */
#line 1350 "cfg.y"
    {
				if (set_mod_param_regex((yyvsp[(3) - (8)].strval), (yyvsp[(5) - (8)].strval), INT_PARAM, (void*)(yyvsp[(7) - (8)].intval)) != 0) {
					yyerrorf("Parameter <%s> not found in module <%s> - can't set",
						(yyvsp[(5) - (8)].strval), (yyvsp[(3) - (8)].strval));
				}
			}
    break;

  case 261:

/* Line 1806 of yacc.c  */
#line 1356 "cfg.y"
    { yyerror("Invalid arguments"); }
    break;

  case 262:

/* Line 1806 of yacc.c  */
#line 1360 "cfg.y"
    { (yyval.ipaddr)=(yyvsp[(1) - (1)].ipaddr); }
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 1361 "cfg.y"
    { (yyval.ipaddr)=(yyvsp[(1) - (1)].ipaddr); }
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 1364 "cfg.y"
    { 
											(yyval.ipaddr)=pkg_malloc(
													sizeof(struct ip_addr));
											if ((yyval.ipaddr)==0){
												LM_CRIT("cfg. "
													"parser: out of memory.\n"
													);
											}else{
												memset((yyval.ipaddr), 0, 
													sizeof(struct ip_addr));
												(yyval.ipaddr)->af=AF_INET;
												(yyval.ipaddr)->len=4;
												if (((yyvsp[(1) - (7)].intval)>255) || ((yyvsp[(1) - (7)].intval)<0) ||
													((yyvsp[(3) - (7)].intval)>255) || ((yyvsp[(3) - (7)].intval)<0) ||
													((yyvsp[(5) - (7)].intval)>255) || ((yyvsp[(5) - (7)].intval)<0) ||
													((yyvsp[(7) - (7)].intval)>255) || ((yyvsp[(7) - (7)].intval)<0)){
													yyerror("invalid ipv4"
															"address");
													(yyval.ipaddr)->u.addr32[0]=0;
													/* $$=0; */
												}else{
													(yyval.ipaddr)->u.addr[0]=(yyvsp[(1) - (7)].intval);
													(yyval.ipaddr)->u.addr[1]=(yyvsp[(3) - (7)].intval);
													(yyval.ipaddr)->u.addr[2]=(yyvsp[(5) - (7)].intval);
													(yyval.ipaddr)->u.addr[3]=(yyvsp[(7) - (7)].intval);
													/*
													$$=htonl( ($1<<24)|
													($3<<16)| ($5<<8)|$7 );
													*/
												}
											}
												}
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 1398 "cfg.y"
    {
					(yyval.ipaddr)=pkg_malloc(sizeof(struct ip_addr));
					if ((yyval.ipaddr)==0){
						LM_CRIT("ERROR: cfg. parser: out of memory.\n");
					}else{
						memset((yyval.ipaddr), 0, sizeof(struct ip_addr));
						(yyval.ipaddr)->af=AF_INET6;
						(yyval.ipaddr)->len=16;
					#ifdef USE_IPV6
						if (inet_pton(AF_INET6, (yyvsp[(1) - (1)].strval), (yyval.ipaddr)->u.addr)<=0){
							yyerror("bad ipv6 address");
						}
					#else
						yyerror("ipv6 address & no ipv6 support compiled in");
						YYABORT;
					#endif
					}
				}
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 1418 "cfg.y"
    { (yyval.ipaddr)=(yyvsp[(1) - (1)].ipaddr); }
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 1419 "cfg.y"
    {(yyval.ipaddr)=(yyvsp[(2) - (3)].ipaddr); }
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 1422 "cfg.y"
    { 
						#ifdef USE_TLS
							if (tls_new_server_domain((yyvsp[(3) - (6)].ipaddr), (yyvsp[(5) - (6)].intval))) 
								yyerror("tls_new_server_domain failed");
						#else	
							warn("tls support not compiled in");
						#endif
							}
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 1433 "cfg.y"
    { 
						#ifdef USE_TLS
							if (tls_new_client_domain((yyvsp[(3) - (6)].ipaddr), (yyvsp[(5) - (6)].intval)))
								yyerror("tls_new_client_domain failed");
						#else	
							warn("tls support not compiled in");
						#endif
							}
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 1444 "cfg.y"
    { 
						#ifdef USE_TLS
							if (tls_new_client_domain_name((yyvsp[(3) - (4)].strval), strlen((yyvsp[(3) - (4)].strval))))
								yyerror("tls_new_client_domain_name failed");
						#else	
							warn("tls support not compiled in");
						#endif
							}
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 1463 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->method=TLS_USE_SSLv23;
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 1470 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->method=TLS_USE_SSLv2;
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 1477 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->method=TLS_USE_SSLv3;
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 1484 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->method=TLS_USE_TLSv1;
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 1491 "cfg.y"
    { yyerror("SSLv23, SSLv2, SSLv3 or TLSv1 expected"); }
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 1492 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->cert_file=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 1499 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 285:

/* Line 1806 of yacc.c  */
#line 1501 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->pkey_file=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 1508 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 1510 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->ca_file=(yyvsp[(3) - (3)].strval); 
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 288:

/* Line 1806 of yacc.c  */
#line 1517 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 289:

/* Line 1806 of yacc.c  */
#line 1518 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_server_domains->ciphers_list=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 1525 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 1526 "cfg.y"
    {
						#ifdef USE_TLS
									tls_server_domains->verify_cert=(yyvsp[(3) - (3)].intval);
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 292:

/* Line 1806 of yacc.c  */
#line 1533 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 293:

/* Line 1806 of yacc.c  */
#line 1534 "cfg.y"
    {
						#ifdef USE_TLS
									tls_server_domains->require_client_cert=(yyvsp[(3) - (3)].intval);
						#else
									warn( "tls support not compiled in");
						#endif
								}
    break;

  case 294:

/* Line 1806 of yacc.c  */
#line 1541 "cfg.y"
    { 
						yyerror("boolean value expected"); }
    break;

  case 295:

/* Line 1806 of yacc.c  */
#line 1545 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->method=TLS_USE_SSLv23;
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 296:

/* Line 1806 of yacc.c  */
#line 1552 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->method=TLS_USE_SSLv2;
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 297:

/* Line 1806 of yacc.c  */
#line 1559 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->method=TLS_USE_SSLv3;
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 298:

/* Line 1806 of yacc.c  */
#line 1566 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->method=TLS_USE_TLSv1;
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 1573 "cfg.y"
    {
						yyerror("SSLv23, SSLv2, SSLv3 or TLSv1 expected"); }
    break;

  case 300:

/* Line 1806 of yacc.c  */
#line 1575 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->cert_file=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 301:

/* Line 1806 of yacc.c  */
#line 1582 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 302:

/* Line 1806 of yacc.c  */
#line 1584 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->pkey_file=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 303:

/* Line 1806 of yacc.c  */
#line 1591 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 304:

/* Line 1806 of yacc.c  */
#line 1593 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->ca_file=(yyvsp[(3) - (3)].strval); 
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 305:

/* Line 1806 of yacc.c  */
#line 1600 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 306:

/* Line 1806 of yacc.c  */
#line 1601 "cfg.y"
    { 
						#ifdef USE_TLS
									tls_client_domains->ciphers_list=(yyvsp[(3) - (3)].strval);
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 307:

/* Line 1806 of yacc.c  */
#line 1608 "cfg.y"
    { yyerror("string value expected"); }
    break;

  case 308:

/* Line 1806 of yacc.c  */
#line 1609 "cfg.y"
    {
						#ifdef USE_TLS
									tls_client_domains->verify_cert=(yyvsp[(3) - (3)].intval);
						#else
									warn("tls support not compiled in");
						#endif
								}
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 1616 "cfg.y"
    { yyerror("boolean value expected"); }
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 1619 "cfg.y"
    {
				(yyval.strval) = (yyvsp[(1) - (1)].strval);
				}
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 1622 "cfg.y"
    {
				tmp=int2str((yyvsp[(1) - (1)].intval), &i_tmp);
				if (((yyval.strval)=pkg_malloc(i_tmp+1))==0)
					yyerror("cfg. parser: out of memory.\n");
				memcpy( (yyval.strval), tmp, i_tmp);
				(yyval.strval)[i_tmp] = 0;
				}
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 1629 "cfg.y"
    {
				(yyval.strval) = (yyvsp[(1) - (1)].strval);
		}
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 1634 "cfg.y"
    {
						if (rlist[DEFAULT_RT].a!=0) {
							yyerror("overwritting default "
								"request routing table");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &rlist[DEFAULT_RT].a);
					}
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 1642 "cfg.y"
    { 
						if ( strtol((yyvsp[(3) - (7)].strval),&tmp,10)==0 && *tmp==0) {
							/* route[0] detected */
							if (rlist[DEFAULT_RT].a!=0) {
								yyerror("overwritting(2) default "
									"request routing table");
								YYABORT;
							}
							push((yyvsp[(6) - (7)].action), &rlist[DEFAULT_RT].a);
						} else {
							i_tmp = get_script_route_idx((yyvsp[(3) - (7)].strval),rlist,RT_NO,1);
							if (i_tmp==-1) YYABORT;
							push((yyvsp[(6) - (7)].action), &rlist[i_tmp].a);
						}
					}
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 1657 "cfg.y"
    { yyerror("invalid  route  statement"); }
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1660 "cfg.y"
    {
						i_tmp = get_script_route_idx((yyvsp[(3) - (7)].strval),failure_rlist,
								FAILURE_RT_NO,1);
						if (i_tmp==-1) YYABORT;
						push((yyvsp[(6) - (7)].action), &failure_rlist[i_tmp].a);
					}
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 1666 "cfg.y"
    { yyerror("invalid failure_route statement"); }
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 1669 "cfg.y"
    {
						if (onreply_rlist[DEFAULT_RT].a!=0) {
							yyerror("overwritting default "
								"onreply routing table");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &onreply_rlist[DEFAULT_RT].a);
					}
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 1677 "cfg.y"
    {
						i_tmp = get_script_route_idx((yyvsp[(3) - (7)].strval),onreply_rlist,
								ONREPLY_RT_NO,1);
						if (i_tmp==-1) YYABORT;
						push((yyvsp[(6) - (7)].action), &onreply_rlist[i_tmp].a);
					}
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 1683 "cfg.y"
    { yyerror("invalid onreply_route statement"); }
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 1686 "cfg.y"
    {
						i_tmp = get_script_route_idx((yyvsp[(3) - (7)].strval),branch_rlist,
								BRANCH_RT_NO,1);
						if (i_tmp==-1) YYABORT;
						push((yyvsp[(6) - (7)].action), &branch_rlist[i_tmp].a);
					}
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 1692 "cfg.y"
    { yyerror("invalid branch_route statement"); }
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 1695 "cfg.y"
    {
						if (error_rlist.a!=0) {
							yyerror("overwritting default "
								"error routing table");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &error_rlist.a);
					}
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 1703 "cfg.y"
    { yyerror("invalid error_route statement"); }
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 1706 "cfg.y"
    {
						if (local_rlist.a!=0) {
							yyerror("re-definition of local "
								"route detected");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &local_rlist.a);
					}
    break;

  case 326:

/* Line 1806 of yacc.c  */
#line 1714 "cfg.y"
    { yyerror("invalid local_route statement"); }
    break;

  case 327:

/* Line 1806 of yacc.c  */
#line 1717 "cfg.y"
    {
						if (startup_rlist.a!=0) {
							yyerror("re-definition of startup "
								"route detected");
							YYABORT;
						}
						push((yyvsp[(3) - (4)].action), &startup_rlist.a);
					}
    break;

  case 328:

/* Line 1806 of yacc.c  */
#line 1725 "cfg.y"
    { yyerror("invalid startup_route statement"); }
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 1728 "cfg.y"
    {
						i_tmp = 0;
						while (timer_rlist[i_tmp].a!=0 && i_tmp < TIMER_RT_NO) {
							i_tmp++;
						}
						if(i_tmp == TIMER_RT_NO) {
							yyerror("Too many timer routes defined\n");
							YYABORT;
						}
						timer_rlist[i_tmp].interval = (yyvsp[(5) - (9)].intval);
						push((yyvsp[(8) - (9)].action), &timer_rlist[i_tmp].a);
					}
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 1740 "cfg.y"
    { yyerror("invalid timer_route statement"); }
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 1743 "cfg.y"
    {
						i_tmp = get_script_route_idx((yyvsp[(3) - (7)].strval),event_rlist,
								EVENT_RT_NO,1);
						if (i_tmp==-1) YYABORT;
						push((yyvsp[(6) - (7)].action), &event_rlist[i_tmp].a);
					}
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 1749 "cfg.y"
    { yyerror("invalid timer_route statement"); }
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 1754 "cfg.y"
    { (yyval.expr)=mk_exp(AND_OP, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); }
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 1755 "cfg.y"
    { (yyval.expr)=mk_exp(OR_OP, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  }
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 1756 "cfg.y"
    { (yyval.expr)=mk_exp(NOT_OP, (yyvsp[(2) - (2)].expr), 0);  }
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 1757 "cfg.y"
    { (yyval.expr)=mk_exp(EVAL_OP, (yyvsp[(2) - (3)].expr), 0); }
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 1758 "cfg.y"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 1759 "cfg.y"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 1762 "cfg.y"
    {(yyval.intval)=EQUAL_OP; }
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 1763 "cfg.y"
    {(yyval.intval)=DIFF_OP; }
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 1766 "cfg.y"
    {(yyval.intval)=GT_OP; }
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 1767 "cfg.y"
    {(yyval.intval)=LT_OP; }
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 1768 "cfg.y"
    {(yyval.intval)=GTE_OP; }
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 1769 "cfg.y"
    {(yyval.intval)=LTE_OP; }
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 1771 "cfg.y"
    {(yyval.intval)=MATCH_OP; }
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 1772 "cfg.y"
    {(yyval.intval)=NOTMATCH_OP; }
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 1775 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); }
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 1776 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); }
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 1779 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); }
    break;

  case 350:

/* Line 1806 of yacc.c  */
#line 1780 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); }
    break;

  case 351:

/* Line 1806 of yacc.c  */
#line 1781 "cfg.y"
    {(yyval.intval)=(yyvsp[(1) - (1)].intval); }
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 1784 "cfg.y"
    {(yyval.intval)=URI_O;}
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 1785 "cfg.y"
    {(yyval.intval)=FROM_URI_O;}
    break;

  case 354:

/* Line 1806 of yacc.c  */
#line 1786 "cfg.y"
    {(yyval.intval)=TO_URI_O;}
    break;

  case 355:

/* Line 1806 of yacc.c  */
#line 1789 "cfg.y"
    { 
				spec = (pv_spec_t*)pkg_malloc(sizeof(pv_spec_t));
				if (spec==NULL){
					yyerror("no more pkg memory\n");
				}
				memset(spec, 0, sizeof(pv_spec_t));
				tstr.s = (yyvsp[(1) - (1)].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_spec(&tstr, spec)==NULL)
				{
					yyerror("unknown script variable");
				}
				(yyval.specval) = spec;
			}
    break;

  case 356:

/* Line 1806 of yacc.c  */
#line 1803 "cfg.y"
    {
			(yyval.specval)=0; yyerror("invalid script variable name");
		}
    break;

  case 357:

/* Line 1806 of yacc.c  */
#line 1808 "cfg.y"
    {(yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 358:

/* Line 1806 of yacc.c  */
#line 1809 "cfg.y"
    {(yyval.expr)=mk_elem( NO_OP, ACTION_O, 0, ACTIONS_ST, (yyvsp[(1) - (1)].action) ); }
    break;

  case 359:

/* Line 1806 of yacc.c  */
#line 1810 "cfg.y"
    {(yyval.expr)=mk_elem( NO_OP, NUMBER_O, 0, NUMBER_ST, 
											(void*)(yyvsp[(1) - (1)].intval) ); }
    break;

  case 360:

/* Line 1806 of yacc.c  */
#line 1812 "cfg.y"
    {
				(yyval.expr)=mk_elem(NO_OP, SCRIPTVAR_O,0,SCRIPTVAR_ST,(void*)(yyvsp[(1) - (1)].specval));
			}
    break;

  case 361:

/* Line 1806 of yacc.c  */
#line 1815 "cfg.y"
    {(yyval.expr) = mk_elem((yyvsp[(2) - (3)].intval), (yyvsp[(1) - (3)].intval), 0, STR_ST, (yyvsp[(3) - (3)].strval)); 
				 			}
    break;

  case 362:

/* Line 1806 of yacc.c  */
#line 1817 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, NET_ST, (yyvsp[(3) - (3)].ipnet));
								}
    break;

  case 363:

/* Line 1806 of yacc.c  */
#line 1819 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, STR_ST, (yyvsp[(3) - (3)].strval));
								}
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 1821 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, NET_ST, (yyvsp[(3) - (3)].ipnet));
								}
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 1823 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, STR_ST, (yyvsp[(3) - (3)].strval));
								}
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 1827 "cfg.y"
    {(yyval.expr)= mk_elem((yyvsp[(2) - (3)].intval), METHOD_O, 0, STR_ST, (yyvsp[(3) - (3)].strval));
									}
    break;

  case 367:

/* Line 1806 of yacc.c  */
#line 1829 "cfg.y"
    {(yyval.expr) = mk_elem((yyvsp[(2) - (3)].intval), METHOD_O, 0, STR_ST, (yyvsp[(3) - (3)].strval)); 
				 			}
    break;

  case 368:

/* Line 1806 of yacc.c  */
#line 1831 "cfg.y"
    { (yyval.expr)=0; yyerror("string expected"); }
    break;

  case 369:

/* Line 1806 of yacc.c  */
#line 1832 "cfg.y"
    { (yyval.expr)=0; yyerror("invalid operator,"
										"== , !=, or =~ expected");
						}
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 1835 "cfg.y"
    {
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval),SCRIPTVAR_ST,(void*)(yyvsp[(3) - (3)].specval));
			}
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 1838 "cfg.y"
    {
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval),STR_ST,(yyvsp[(3) - (3)].strval));
			}
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 1841 "cfg.y"
    {
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval),STR_ST,(yyvsp[(3) - (3)].strval));
			}
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 1844 "cfg.y"
    {
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval),NUMBER_ST,(void *)(yyvsp[(3) - (3)].intval));
			}
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 1847 "cfg.y"
    { 
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval), MYSELF_ST, 0);
			}
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 1850 "cfg.y"
    { 
				(yyval.expr)=mk_elem( (yyvsp[(2) - (3)].intval), SCRIPTVAR_O,(void*)(yyvsp[(1) - (3)].specval), NULLV_ST, 0);
			}
    break;

  case 376:

/* Line 1806 of yacc.c  */
#line 1853 "cfg.y"
    {(yyval.expr) = mk_elem((yyvsp[(2) - (3)].intval), (yyvsp[(1) - (3)].intval), 0, STR_ST, (yyvsp[(3) - (3)].strval)); 
				 				}
    break;

  case 377:

/* Line 1806 of yacc.c  */
#line 1855 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), (yyvsp[(1) - (3)].intval), 0, MYSELF_ST, 0);
								}
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 1857 "cfg.y"
    { (yyval.expr)=0; yyerror("string or MYSELF expected"); }
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 1858 "cfg.y"
    { (yyval.expr)=0; yyerror("invalid operator,"
									" == , != or =~ expected");
					}
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 1861 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCPORT_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); }
    break;

  case 381:

/* Line 1806 of yacc.c  */
#line 1863 "cfg.y"
    { (yyval.expr)=0; yyerror("number expected"); }
    break;

  case 382:

/* Line 1806 of yacc.c  */
#line 1864 "cfg.y"
    { (yyval.expr)=0; yyerror("==, !=, <,>, >= or <=  expected"); }
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 1865 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTPORT_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); }
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 1867 "cfg.y"
    { (yyval.expr)=0; yyerror("number expected"); }
    break;

  case 385:

/* Line 1806 of yacc.c  */
#line 1868 "cfg.y"
    { (yyval.expr)=0; yyerror("==, !=, <,>, >= or <=  expected"); }
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 1869 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), PROTO_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); }
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 1871 "cfg.y"
    { (yyval.expr)=0;
								yyerror("protocol expected (udp, tcp or tls)");
							}
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 1874 "cfg.y"
    { (yyval.expr)=0; yyerror("equal/!= operator expected"); }
    break;

  case 389:

/* Line 1806 of yacc.c  */
#line 1875 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), AF_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); }
    break;

  case 390:

/* Line 1806 of yacc.c  */
#line 1877 "cfg.y"
    { (yyval.expr)=0; yyerror("number expected"); }
    break;

  case 391:

/* Line 1806 of yacc.c  */
#line 1878 "cfg.y"
    { (yyval.expr)=0; yyerror("equal/!= operator expected"); }
    break;

  case 392:

/* Line 1806 of yacc.c  */
#line 1879 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), MSGLEN_O, 0, NUMBER_ST,
												(void *) (yyvsp[(3) - (3)].intval) ); }
    break;

  case 393:

/* Line 1806 of yacc.c  */
#line 1881 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), MSGLEN_O, 0, NUMBER_ST,
												(void *) BUF_SIZE); }
    break;

  case 394:

/* Line 1806 of yacc.c  */
#line 1883 "cfg.y"
    { (yyval.expr)=0; yyerror("number expected"); }
    break;

  case 395:

/* Line 1806 of yacc.c  */
#line 1884 "cfg.y"
    { (yyval.expr)=0; yyerror("equal/!= operator expected"); }
    break;

  case 396:

/* Line 1806 of yacc.c  */
#line 1885 "cfg.y"
    {	s_tmp.s=(yyvsp[(3) - (3)].strval);
									s_tmp.len=strlen((yyvsp[(3) - (3)].strval));
									ip_tmp=str2ip(&s_tmp);
									if (ip_tmp==0)
										ip_tmp=str2ip6(&s_tmp);
									if (ip_tmp){
										(yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, NET_ST,
												mk_net_bitlen(ip_tmp, 
														ip_tmp->len*8) );
									}else{
										(yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, STR_ST,
												(yyvsp[(3) - (3)].strval));
									}
								}
    break;

  case 397:

/* Line 1806 of yacc.c  */
#line 1899 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, MYSELF_ST, 0);
								}
    break;

  case 398:

/* Line 1806 of yacc.c  */
#line 1901 "cfg.y"
    { (yyval.expr)=0; yyerror( "ip address or hostname"
						 "expected" ); }
    break;

  case 399:

/* Line 1806 of yacc.c  */
#line 1903 "cfg.y"
    { (yyval.expr)=0; 
						 yyerror("invalid operator, ==, != or =~ expected");}
    break;

  case 400:

/* Line 1806 of yacc.c  */
#line 1905 "cfg.y"
    {	s_tmp.s=(yyvsp[(3) - (3)].strval);
									s_tmp.len=strlen((yyvsp[(3) - (3)].strval));
									ip_tmp=str2ip(&s_tmp);
									if (ip_tmp==0)
										ip_tmp=str2ip6(&s_tmp);
									if (ip_tmp){
										(yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, NET_ST,
												mk_net_bitlen(ip_tmp, 
														ip_tmp->len*8) );
									}else{
										(yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, STR_ST,
												(yyvsp[(3) - (3)].strval));
									}
								}
    break;

  case 401:

/* Line 1806 of yacc.c  */
#line 1919 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, MYSELF_ST, 0);
								}
    break;

  case 402:

/* Line 1806 of yacc.c  */
#line 1921 "cfg.y"
    { (yyval.expr)=0; yyerror( "ip address or hostname"
						 			"expected" ); }
    break;

  case 403:

/* Line 1806 of yacc.c  */
#line 1923 "cfg.y"
    { (yyval.expr)=0; 
						yyerror("invalid operator, ==, != or =~ expected");}
    break;

  case 404:

/* Line 1806 of yacc.c  */
#line 1925 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), (yyvsp[(3) - (3)].intval), 0, MYSELF_ST, 0);
								}
    break;

  case 405:

/* Line 1806 of yacc.c  */
#line 1927 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), SRCIP_O, 0, MYSELF_ST, 0);
								}
    break;

  case 406:

/* Line 1806 of yacc.c  */
#line 1929 "cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[(2) - (3)].intval), DSTIP_O, 0, MYSELF_ST, 0);
								}
    break;

  case 407:

/* Line 1806 of yacc.c  */
#line 1931 "cfg.y"
    {	(yyval.expr)=0; 
									yyerror(" URI, SRCIP or DSTIP expected"); }
    break;

  case 408:

/* Line 1806 of yacc.c  */
#line 1933 "cfg.y"
    { (yyval.expr)=0; 
							yyerror ("invalid operator, == or != expected");
						}
    break;

  case 409:

/* Line 1806 of yacc.c  */
#line 1938 "cfg.y"
    { (yyval.ipnet)=mk_net((yyvsp[(1) - (3)].ipaddr), (yyvsp[(3) - (3)].ipaddr)); }
    break;

  case 410:

/* Line 1806 of yacc.c  */
#line 1939 "cfg.y"
    {	if (((yyvsp[(3) - (3)].intval)<0) || ((yyvsp[(3) - (3)].intval)>(long)(yyvsp[(1) - (3)].ipaddr)->len*8)){
								yyerror("invalid bit number in netmask");
								(yyval.ipnet)=0;
							}else{
								(yyval.ipnet)=mk_net_bitlen((yyvsp[(1) - (3)].ipaddr), (yyvsp[(3) - (3)].intval));
							/*
								$$=mk_net($1, 
										htonl( ($3)?~( (1<<(32-$3))-1 ):0 ) );
							*/
							}
						}
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 1950 "cfg.y"
    { (yyval.ipnet)=mk_net_bitlen((yyvsp[(1) - (1)].ipaddr), (yyvsp[(1) - (1)].ipaddr)->len*8); }
    break;

  case 412:

/* Line 1806 of yacc.c  */
#line 1951 "cfg.y"
    { (yyval.ipnet)=0;
						 yyerror("netmask (eg:255.0.0.0 or 8) expected");
						}
    break;

  case 413:

/* Line 1806 of yacc.c  */
#line 1958 "cfg.y"
    {(yyval.strval)=".";}
    break;

  case 414:

/* Line 1806 of yacc.c  */
#line 1959 "cfg.y"
    {(yyval.strval)="-"; }
    break;

  case 415:

/* Line 1806 of yacc.c  */
#line 1962 "cfg.y"
    { (yyval.strval)=(yyvsp[(1) - (1)].strval); }
    break;

  case 416:

/* Line 1806 of yacc.c  */
#line 1963 "cfg.y"
    { (yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[(1) - (3)].strval))+1+strlen((yyvsp[(3) - (3)].strval))+1);
						  if ((yyval.strval)==0){
							LM_CRIT("cfg. parser: memory allocation"
										" failure while parsing host\n");
						  }else{
							memcpy((yyval.strval), (yyvsp[(1) - (3)].strval), strlen((yyvsp[(1) - (3)].strval)));
							(yyval.strval)[strlen((yyvsp[(1) - (3)].strval))]=*(yyvsp[(2) - (3)].strval);
							memcpy((yyval.strval)+strlen((yyvsp[(1) - (3)].strval))+1, (yyvsp[(3) - (3)].strval), strlen((yyvsp[(3) - (3)].strval)));
							(yyval.strval)[strlen((yyvsp[(1) - (3)].strval))+1+strlen((yyvsp[(3) - (3)].strval))]=0;
						  }
						  pkg_free((yyvsp[(1) - (3)].strval)); pkg_free((yyvsp[(3) - (3)].strval));
						}
    break;

  case 417:

/* Line 1806 of yacc.c  */
#line 1975 "cfg.y"
    { (yyval.strval)=0; pkg_free((yyvsp[(1) - (3)].strval)); yyerror("invalid hostname (use quotes if hostname has config keywords)"); }
    break;

  case 418:

/* Line 1806 of yacc.c  */
#line 1979 "cfg.y"
    { (yyval.intval) = EQ_T; }
    break;

  case 419:

/* Line 1806 of yacc.c  */
#line 1980 "cfg.y"
    { (yyval.intval) = COLONEQ_T; }
    break;

  case 420:

/* Line 1806 of yacc.c  */
#line 1981 "cfg.y"
    { (yyval.intval) = PLUSEQ_T; }
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 1982 "cfg.y"
    { (yyval.intval) = MINUSEQ_T;}
    break;

  case 422:

/* Line 1806 of yacc.c  */
#line 1983 "cfg.y"
    { (yyval.intval) = DIVEQ_T; }
    break;

  case 423:

/* Line 1806 of yacc.c  */
#line 1984 "cfg.y"
    { (yyval.intval) = MULTEQ_T; }
    break;

  case 424:

/* Line 1806 of yacc.c  */
#line 1985 "cfg.y"
    { (yyval.intval) = MODULOEQ_T; }
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 1986 "cfg.y"
    { (yyval.intval) = BANDEQ_T; }
    break;

  case 426:

/* Line 1806 of yacc.c  */
#line 1987 "cfg.y"
    { (yyval.intval) = BOREQ_T; }
    break;

  case 427:

/* Line 1806 of yacc.c  */
#line 1988 "cfg.y"
    { (yyval.intval) = BXOREQ_T; }
    break;

  case 428:

/* Line 1806 of yacc.c  */
#line 1992 "cfg.y"
    { (yyval.expr) = mk_elem(VALUE_OP, NUMBERV_O, (void*)(yyvsp[(1) - (1)].intval), 0, 0); }
    break;

  case 429:

/* Line 1806 of yacc.c  */
#line 1993 "cfg.y"
    { (yyval.expr) = mk_elem(VALUE_OP, STRINGV_O, (yyvsp[(1) - (1)].strval), 0, 0); }
    break;

  case 430:

/* Line 1806 of yacc.c  */
#line 1994 "cfg.y"
    { (yyval.expr) = mk_elem(VALUE_OP, STRINGV_O, (yyvsp[(1) - (1)].strval), 0, 0); }
    break;

  case 431:

/* Line 1806 of yacc.c  */
#line 1995 "cfg.y"
    { (yyval.expr) = mk_elem(VALUE_OP, SCRIPTVAR_O, (yyvsp[(1) - (1)].specval), 0, 0); }
    break;

  case 432:

/* Line 1806 of yacc.c  */
#line 1996 "cfg.y"
    { (yyval.expr)= (yyvsp[(1) - (1)].expr); }
    break;

  case 433:

/* Line 1806 of yacc.c  */
#line 1997 "cfg.y"
    { (yyval.expr)=mk_elem( NO_OP, ACTION_O, 0, ACTIONS_ST, (yyvsp[(1) - (1)].action) ); }
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 1998 "cfg.y"
    { 
				(yyval.expr) = mk_elem(PLUS_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			}
    break;

  case 435:

/* Line 1806 of yacc.c  */
#line 2001 "cfg.y"
    { 
				(yyval.expr) = mk_elem(MINUS_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr)); 
			}
    break;

  case 436:

/* Line 1806 of yacc.c  */
#line 2004 "cfg.y"
    { 
				(yyval.expr) = mk_elem(MULT_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			}
    break;

  case 437:

/* Line 1806 of yacc.c  */
#line 2007 "cfg.y"
    { 
				(yyval.expr) = mk_elem(DIV_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			}
    break;

  case 438:

/* Line 1806 of yacc.c  */
#line 2010 "cfg.y"
    { 
				(yyval.expr) = mk_elem(MODULO_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			}
    break;

  case 439:

/* Line 1806 of yacc.c  */
#line 2013 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BAND_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			}
    break;

  case 440:

/* Line 1806 of yacc.c  */
#line 2016 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BOR_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			}
    break;

  case 441:

/* Line 1806 of yacc.c  */
#line 2019 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BXOR_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			}
    break;

  case 442:

/* Line 1806 of yacc.c  */
#line 2022 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BLSHIFT_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			}
    break;

  case 443:

/* Line 1806 of yacc.c  */
#line 2025 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BRSHIFT_OP, EXPR_O, (yyvsp[(1) - (3)].expr), EXPR_ST, (yyvsp[(3) - (3)].expr));
			}
    break;

  case 444:

/* Line 1806 of yacc.c  */
#line 2028 "cfg.y"
    { 
				(yyval.expr) = mk_elem(BNOT_OP, EXPR_O, (yyvsp[(2) - (2)].expr), 0, 0);
			}
    break;

  case 445:

/* Line 1806 of yacc.c  */
#line 2031 "cfg.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); }
    break;

  case 446:

/* Line 1806 of yacc.c  */
#line 2034 "cfg.y"
    {	
			if(!pv_is_w((yyvsp[(1) - (3)].specval)))
				yyerror("invalid left operand in assignment");
			if((yyvsp[(1) - (3)].specval)->trans!=0)
				yyerror(
					"transformations not accepted in right side of assignment");

			mk_action2( (yyval.action), (yyvsp[(2) - (3)].intval),
					SCRIPTVAR_ST,
					EXPR_ST,
					(yyvsp[(1) - (3)].specval),
					(yyvsp[(3) - (3)].expr));
		}
    break;

  case 447:

/* Line 1806 of yacc.c  */
#line 2047 "cfg.y"
    {
			if(!pv_is_w((yyvsp[(1) - (3)].specval)))
				yyerror("invalid left operand in assignment");
			if((yyvsp[(1) - (3)].specval)->trans!=0)
				yyerror(
					"transformations not accepted in right side of assignment");

			mk_action2( (yyval.action), EQ_T,
					SCRIPTVAR_ST,
					NULLV_ST,
					(yyvsp[(1) - (3)].specval),
					0);
		}
    break;

  case 448:

/* Line 1806 of yacc.c  */
#line 2060 "cfg.y"
    {
			if(!pv_is_w((yyvsp[(1) - (3)].specval)))
				yyerror("invalid left operand in assignment");
			/* not all can get NULL with := */
			switch((yyvsp[(1) - (3)].specval)->type) {
				case PVT_AVP:
				break;
				default:
					yyerror("invalid left operand in NULL assignment");
			}
			if((yyvsp[(1) - (3)].specval)->trans!=0)
				yyerror(
					"transformations not accepted in right side of assignment");

			mk_action2( (yyval.action), COLONEQ_T,
					SCRIPTVAR_ST,
					NULLV_ST,
					(yyvsp[(1) - (3)].specval),
					0);
		}
    break;

  case 449:

/* Line 1806 of yacc.c  */
#line 2082 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); }
    break;

  case 450:

/* Line 1806 of yacc.c  */
#line 2083 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); }
    break;

  case 451:

/* Line 1806 of yacc.c  */
#line 2084 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); }
    break;

  case 452:

/* Line 1806 of yacc.c  */
#line 2085 "cfg.y"
    { (yyval.action)=(yyvsp[(2) - (3)].action); }
    break;

  case 453:

/* Line 1806 of yacc.c  */
#line 2086 "cfg.y"
    { (yyval.action)=0; }
    break;

  case 454:

/* Line 1806 of yacc.c  */
#line 2089 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); }
    break;

  case 455:

/* Line 1806 of yacc.c  */
#line 2090 "cfg.y"
    { (yyval.action)=(yyvsp[(2) - (3)].action); }
    break;

  case 456:

/* Line 1806 of yacc.c  */
#line 2091 "cfg.y"
    { (yyval.action)=0; }
    break;

  case 457:

/* Line 1806 of yacc.c  */
#line 2094 "cfg.y"
    {(yyval.action)=append_action((yyvsp[(1) - (2)].action), (yyvsp[(2) - (2)].action)); }
    break;

  case 458:

/* Line 1806 of yacc.c  */
#line 2095 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (1)].action);}
    break;

  case 459:

/* Line 1806 of yacc.c  */
#line 2096 "cfg.y"
    { (yyval.action)=0; yyerror("bad command!)"); }
    break;

  case 460:

/* Line 1806 of yacc.c  */
#line 2099 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (2)].action);}
    break;

  case 461:

/* Line 1806 of yacc.c  */
#line 2100 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (1)].action);}
    break;

  case 462:

/* Line 1806 of yacc.c  */
#line 2101 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action);}
    break;

  case 463:

/* Line 1806 of yacc.c  */
#line 2102 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (1)].action);}
    break;

  case 464:

/* Line 1806 of yacc.c  */
#line 2103 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (2)].action);}
    break;

  case 465:

/* Line 1806 of yacc.c  */
#line 2104 "cfg.y"
    {(yyval.action)=0;}
    break;

  case 466:

/* Line 1806 of yacc.c  */
#line 2105 "cfg.y"
    { (yyval.action)=0; yyerror("bad command: missing ';'?"); }
    break;

  case 467:

/* Line 1806 of yacc.c  */
#line 2108 "cfg.y"
    { mk_action3( (yyval.action), IF_T,
													 EXPR_ST,
													 ACTIONS_ST,
													 NOSUBTYPE,
													 (yyvsp[(2) - (3)].expr),
													 (yyvsp[(3) - (3)].action),
													 0);
									}
    break;

  case 468:

/* Line 1806 of yacc.c  */
#line 2116 "cfg.y"
    { mk_action3( (yyval.action), IF_T,
													 EXPR_ST,
													 ACTIONS_ST,
													 ACTIONS_ST,
													 (yyvsp[(2) - (5)].expr),
													 (yyvsp[(3) - (5)].action),
													 (yyvsp[(5) - (5)].action));
									}
    break;

  case 469:

/* Line 1806 of yacc.c  */
#line 2126 "cfg.y"
    { mk_action2( (yyval.action), WHILE_T,
													 EXPR_ST,
													 ACTIONS_ST,
													 (yyvsp[(2) - (3)].expr),
													 (yyvsp[(3) - (3)].action));
									}
    break;

  case 470:

/* Line 1806 of yacc.c  */
#line 2134 "cfg.y"
    {
											mk_action2( (yyval.action), SWITCH_T,
														SCRIPTVAR_ST,
														ACTIONS_ST,
														(yyvsp[(3) - (7)].specval),
														(yyvsp[(6) - (7)].action));
									}
    break;

  case 471:

/* Line 1806 of yacc.c  */
#line 2143 "cfg.y"
    { (yyval.action)=append_action((yyvsp[(1) - (2)].action), (yyvsp[(2) - (2)].action)); }
    break;

  case 472:

/* Line 1806 of yacc.c  */
#line 2144 "cfg.y"
    { (yyval.action)=(yyvsp[(1) - (1)].action); }
    break;

  case 473:

/* Line 1806 of yacc.c  */
#line 2146 "cfg.y"
    {(yyval.action)=append_action((yyvsp[(1) - (2)].action), (yyvsp[(2) - (2)].action)); }
    break;

  case 474:

/* Line 1806 of yacc.c  */
#line 2147 "cfg.y"
    {(yyval.action)=(yyvsp[(1) - (1)].action);}
    break;

  case 475:

/* Line 1806 of yacc.c  */
#line 2151 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (6)].intval),
													(yyvsp[(4) - (6)].action),
													(void*)1);
											}
    break;

  case 476:

/* Line 1806 of yacc.c  */
#line 2160 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (5)].intval),
													0,
													(void*)1);
											}
    break;

  case 477:

/* Line 1806 of yacc.c  */
#line 2168 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (4)].intval),
													(yyvsp[(4) - (4)].action),
													(void*)0);
									}
    break;

  case 478:

/* Line 1806 of yacc.c  */
#line 2176 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (3)].intval),
													0,
													(void*)0);
							}
    break;

  case 479:

/* Line 1806 of yacc.c  */
#line 2185 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (6)].strval),
													(yyvsp[(4) - (6)].action),
													(void*)1);
											}
    break;

  case 480:

/* Line 1806 of yacc.c  */
#line 2194 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (5)].strval),
													0,
													(void*)1);
											}
    break;

  case 481:

/* Line 1806 of yacc.c  */
#line 2202 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (4)].strval),
													(yyvsp[(4) - (4)].action),
													(void*)0);
									}
    break;

  case 482:

/* Line 1806 of yacc.c  */
#line 2210 "cfg.y"
    { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[(2) - (3)].strval),
													0,
													(void*)0);
							}
    break;

  case 483:

/* Line 1806 of yacc.c  */
#line 2221 "cfg.y"
    { mk_action2( (yyval.action), DEFAULT_T,
													ACTIONS_ST,
													0,
													(yyvsp[(3) - (3)].action),
													0);
									}
    break;

  case 484:

/* Line 1806 of yacc.c  */
#line 2227 "cfg.y"
    { mk_action2( (yyval.action), DEFAULT_T,
													ACTIONS_ST,
													0,
													0,
													0);
									}
    break;

  case 485:

/* Line 1806 of yacc.c  */
#line 2235 "cfg.y"
    {
										elems[1].type = STRING_ST;
										elems[1].u.data = (yyvsp[(1) - (1)].strval);
										(yyval.intval)=1;
										}
    break;

  case 486:

/* Line 1806 of yacc.c  */
#line 2240 "cfg.y"
    {
										if ((yyvsp[(1) - (3)].intval)+1>=MAX_ACTION_ELEMS) {
											yyerror("too many arguments in function\n");
											(yyval.intval)=0;
										}
										elems[(yyvsp[(1) - (3)].intval)+1].type = STRING_ST;
										elems[(yyvsp[(1) - (3)].intval)+1].u.data = (yyvsp[(3) - (3)].strval);
										(yyval.intval)=(yyvsp[(1) - (3)].intval)+1;
										}
    break;

  case 487:

/* Line 1806 of yacc.c  */
#line 2249 "cfg.y"
    {
										(yyval.intval)=0;
										yyerror("numbers used as parameters - they should be quoted");
										}
    break;

  case 488:

/* Line 1806 of yacc.c  */
#line 2253 "cfg.y"
    {
										(yyval.intval)=0;
										yyerror("numbers used as parameters - they should be quoted");
										}
    break;

  case 489:

/* Line 1806 of yacc.c  */
#line 2259 "cfg.y"
    {
						route_elems[0].type = STRING_ST;
						route_elems[0].u.data = (yyvsp[(1) - (1)].strval);
						(yyval.intval)=1;
			}
    break;

  case 490:

/* Line 1806 of yacc.c  */
#line 2264 "cfg.y"
    {
						route_elems[0].type = NUMBER_ST;
						route_elems[0].u.data = (void*)(long)(yyvsp[(1) - (1)].intval);
						(yyval.intval)=1;
			}
    break;

  case 491:

/* Line 1806 of yacc.c  */
#line 2269 "cfg.y"
    {
						route_elems[0].type = SCRIPTVAR_ST;
						route_elems[0].u.data = (yyvsp[(1) - (1)].specval);
						(yyval.intval)=1;
			}
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 2274 "cfg.y"
    {
						if ((yyvsp[(1) - (3)].intval)>=MAX_ACTION_ELEMS) {
							yyerror("too many arguments in function\n");
							(yyval.intval)=-1;
						} else {
							route_elems[(yyvsp[(1) - (3)].intval)].type = STRING_ST;
							route_elems[(yyvsp[(1) - (3)].intval)].u.data = (yyvsp[(3) - (3)].strval);
							(yyval.intval)=(yyvsp[(1) - (3)].intval)+1;
						}
			}
    break;

  case 493:

/* Line 1806 of yacc.c  */
#line 2284 "cfg.y"
    {
						if ((yyvsp[(1) - (3)].intval)>=MAX_ACTION_ELEMS) {
							yyerror("too many arguments in function\n");
							(yyval.intval)=-1;
						} else {
							route_elems[(yyvsp[(1) - (3)].intval)].type = NUMBER_ST;
							route_elems[(yyvsp[(1) - (3)].intval)].u.data = (void*)(long)(yyvsp[(3) - (3)].intval);
							(yyval.intval)=(yyvsp[(1) - (3)].intval)+1;
						}
			}
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 2294 "cfg.y"
    {
						if ((yyvsp[(1) - (3)].intval)+1>=MAX_ACTION_ELEMS) {
							yyerror("too many arguments in function\n");
							(yyval.intval)=-1;
						} else {
							route_elems[(yyvsp[(1) - (3)].intval)].type = SCRIPTVAR_ST;
							route_elems[(yyvsp[(1) - (3)].intval)].u.data = (yyvsp[(3) - (3)].specval);
							(yyval.intval)=(yyvsp[(1) - (3)].intval)+1;
						}
			}
    break;

  case 495:

/* Line 1806 of yacc.c  */
#line 2306 "cfg.y"
    { mk_action2( (yyval.action), FORWARD_T,
											STRING_ST,
											0,
											(yyvsp[(3) - (4)].strval),
											0);
										}
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 2312 "cfg.y"
    {
										mk_action2( (yyval.action), FORWARD_T,
											0,
											0,
											0,
											0);
										}
    break;

  case 497:

/* Line 1806 of yacc.c  */
#line 2319 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 2320 "cfg.y"
    { (yyval.action)=0; yyerror("bad forward "
										"argument"); }
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 2323 "cfg.y"
    { mk_action2( (yyval.action), SEND_T,
											STRING_ST,
											0,
											(yyvsp[(3) - (4)].strval),
											0);
										}
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 2329 "cfg.y"
    { mk_action2( (yyval.action), SEND_T,
											STRING_ST,
											STRING_ST,
											(yyvsp[(3) - (6)].strval),
											(yyvsp[(5) - (6)].strval));
										}
    break;

  case 501:

/* Line 1806 of yacc.c  */
#line 2335 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 2336 "cfg.y"
    { (yyval.action)=0; yyerror("bad send"
													"argument"); }
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 2338 "cfg.y"
    {mk_action2( (yyval.action), DROP_T,0, 0, 0, 0); }
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 2339 "cfg.y"
    {mk_action2( (yyval.action), DROP_T,0, 0, 0, 0); }
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 2340 "cfg.y"
    {mk_action2( (yyval.action), EXIT_T,0, 0, 0, 0); }
    break;

  case 506:

/* Line 1806 of yacc.c  */
#line 2341 "cfg.y"
    {mk_action2( (yyval.action), EXIT_T,0, 0, 0, 0); }
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 2342 "cfg.y"
    {mk_action2( (yyval.action), RETURN_T,
																NUMBER_ST, 
																0,
																(void*)(yyvsp[(3) - (4)].intval),
																0);
												}
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 2348 "cfg.y"
    {mk_action2( (yyval.action), RETURN_T,
																SCRIPTVAR_ST, 
																0,
																(void*)(yyvsp[(3) - (4)].specval),
																0);
												}
    break;

  case 509:

/* Line 1806 of yacc.c  */
#line 2354 "cfg.y"
    {mk_action2( (yyval.action), RETURN_T,
																NUMBER_ST, 
																0,
																(void*)1,
																0);
												}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 2360 "cfg.y"
    {mk_action2( (yyval.action), RETURN_T,
																NUMBER_ST, 
																0,
																(void*)1,
																0);
												}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2366 "cfg.y"
    {mk_action2( (yyval.action), LOG_T, NUMBER_ST, 
													STRING_ST,(void*)4,(yyvsp[(3) - (4)].strval));
									}
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2369 "cfg.y"
    {mk_action2( (yyval.action), LOG_T,
																NUMBER_ST, 
																STRING_ST,
																(void*)(yyvsp[(3) - (6)].intval),
																(yyvsp[(5) - (6)].strval));
												}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 2375 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 2376 "cfg.y"
    { (yyval.action)=0; yyerror("bad log"
									"argument"); }
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2378 "cfg.y"
    {mk_action2((yyval.action), SET_DEBUG_T, NUMBER_ST,
									0, (void *)(yyvsp[(3) - (4)].intval), 0 ); }
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2380 "cfg.y"
    {mk_action2( (yyval.action), SET_DEBUG_T, 0, 0, 0, 0 ); }
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2381 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2382 "cfg.y"
    {mk_action2((yyval.action), SETFLAG_T, NUMBER_ST, 0,
													(void *)(yyvsp[(3) - (4)].intval), 0 ); }
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2384 "cfg.y"
    {mk_action2((yyval.action), SETFLAG_T, STR_ST, 0,
													(void *)(yyvsp[(3) - (4)].strval), 0 ); }
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2386 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2387 "cfg.y"
    {mk_action2( (yyval.action), RESETFLAG_T,
										NUMBER_ST, 0, (void *)(yyvsp[(3) - (4)].intval), 0 ); }
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 2389 "cfg.y"
    {mk_action2( (yyval.action), RESETFLAG_T,
										STR_ST, 0, (void *)(yyvsp[(3) - (4)].strval), 0 ); }
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 2391 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 2392 "cfg.y"
    {mk_action2( (yyval.action), ISFLAGSET_T,
										NUMBER_ST, 0, (void *)(yyvsp[(3) - (4)].intval), 0 ); }
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 2394 "cfg.y"
    {mk_action2( (yyval.action), ISFLAGSET_T,
										STR_ST, 0, (void *)(yyvsp[(3) - (4)].strval), 0 ); }
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 2396 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 2397 "cfg.y"
    {mk_action2( (yyval.action), SETSFLAG_T, NUMBER_ST,
										0, (void *)(yyvsp[(3) - (4)].intval), 0 ); }
    break;

  case 528:

/* Line 1806 of yacc.c  */
#line 2399 "cfg.y"
    {mk_action2( (yyval.action), SETSFLAG_T, STR_ST,
										0, (void *)(yyvsp[(3) - (4)].strval), 0 ); }
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 2401 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 2402 "cfg.y"
    {mk_action2( (yyval.action), RESETSFLAG_T,
										NUMBER_ST, 0, (void *)(yyvsp[(3) - (4)].intval), 0 ); }
    break;

  case 531:

/* Line 1806 of yacc.c  */
#line 2404 "cfg.y"
    {mk_action2( (yyval.action), RESETSFLAG_T,
										STR_ST, 0, (void *)(yyvsp[(3) - (4)].strval), 0 ); }
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 2406 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 2407 "cfg.y"
    {mk_action2( (yyval.action), ISSFLAGSET_T,
										NUMBER_ST, 0, (void *)(yyvsp[(3) - (4)].intval), 0 ); }
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 2409 "cfg.y"
    {mk_action2( (yyval.action), ISSFLAGSET_T,
										STR_ST, 0, (void *)(yyvsp[(3) - (4)].strval), 0 ); }
    break;

  case 535:

/* Line 1806 of yacc.c  */
#line 2411 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 536:

/* Line 1806 of yacc.c  */
#line 2412 "cfg.y"
    {mk_action2( (yyval.action),
													SETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													(void *)(yyvsp[(3) - (6)].intval), (void *)(yyvsp[(5) - (6)].intval) ); }
    break;

  case 537:

/* Line 1806 of yacc.c  */
#line 2416 "cfg.y"
    {mk_action2( (yyval.action),
													SETBFLAG_T,
													NUMBER_ST, STR_ST,
													(void *)(yyvsp[(3) - (6)].intval), (void *)(yyvsp[(5) - (6)].strval) ); }
    break;

  case 538:

/* Line 1806 of yacc.c  */
#line 2420 "cfg.y"
    {mk_action2( (yyval.action), SETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													0, (void *)(yyvsp[(3) - (4)].intval) ); }
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 2423 "cfg.y"
    {mk_action2( (yyval.action), SETBFLAG_T,
													NUMBER_ST, STR_ST,
													0, (void *)(yyvsp[(3) - (4)].strval) ); }
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 2426 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 2427 "cfg.y"
    {mk_action2( (yyval.action), 
													RESETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													(void *)(yyvsp[(3) - (6)].intval), (void *)(yyvsp[(5) - (6)].intval) ); }
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 2431 "cfg.y"
    {mk_action2( (yyval.action), 
													RESETBFLAG_T,
													NUMBER_ST, STR_ST,
													(void *)(yyvsp[(3) - (6)].intval), (void *)(yyvsp[(5) - (6)].strval) ); }
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 2435 "cfg.y"
    {mk_action2( (yyval.action), 
													RESETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													0, (void *)(yyvsp[(3) - (4)].intval) ); }
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 2439 "cfg.y"
    {mk_action2( (yyval.action), 
													RESETBFLAG_T,
													NUMBER_ST, STR_ST,
													0, (void *)(yyvsp[(3) - (4)].strval) ); }
    break;

  case 545:

/* Line 1806 of yacc.c  */
#line 2443 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 2444 "cfg.y"
    {mk_action2( (yyval.action), 
													ISBFLAGSET_T,
													NUMBER_ST, NUMBER_ST,
													(void *)(yyvsp[(3) - (6)].intval), (void *)(yyvsp[(5) - (6)].intval) ); }
    break;

  case 547:

/* Line 1806 of yacc.c  */
#line 2448 "cfg.y"
    {mk_action2( (yyval.action), 
													ISBFLAGSET_T,
													NUMBER_ST, STR_ST,
													(void *)(yyvsp[(3) - (6)].intval), (void *)(yyvsp[(5) - (6)].strval) ); }
    break;

  case 548:

/* Line 1806 of yacc.c  */
#line 2452 "cfg.y"
    {mk_action2( (yyval.action), 
													ISBFLAGSET_T,
													NUMBER_ST, NUMBER_ST,
													0, (void *)(yyvsp[(3) - (4)].intval) ); }
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 2456 "cfg.y"
    {mk_action2( (yyval.action), 
													ISBFLAGSET_T,
													NUMBER_ST, STR_ST,
													0, (void *)(yyvsp[(3) - (4)].strval) ); }
    break;

  case 550:

/* Line 1806 of yacc.c  */
#line 2460 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 2461 "cfg.y"
    {mk_action2( (yyval.action), ERROR_T,
																STRING_ST, 
																STRING_ST,
																(yyvsp[(3) - (6)].strval),
																(yyvsp[(5) - (6)].strval));
												  }
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 2467 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 2468 "cfg.y"
    { (yyval.action)=0; yyerror("bad error"
														"argument"); }
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 2470 "cfg.y"
    { 
						i_tmp = get_script_route_idx( (yyvsp[(3) - (4)].strval), rlist, RT_NO, 0);
						if (i_tmp==-1) yyerror("too many script routes");
						mk_action2( (yyval.action), ROUTE_T, NUMBER_ST,
							0, (void*)(long)i_tmp, 0);
					}
    break;

  case 555:

/* Line 1806 of yacc.c  */
#line 2477 "cfg.y"
    { 
						i_tmp = get_script_route_idx( (yyvsp[(3) - (6)].strval), rlist, RT_NO, 0);
						if (i_tmp==-1) yyerror("too many script routes");
						if ((yyvsp[(5) - (6)].intval) <= 0) yyerror("too many route parameters");

						/* duplicate the list */
						a_tmp = pkg_malloc((yyvsp[(5) - (6)].intval) * sizeof(action_elem_t));
						if (!a_tmp) yyerror("no more pkg memory");
						memcpy(a_tmp, route_elems, (yyvsp[(5) - (6)].intval)*sizeof(action_elem_t));

						mk_action3( (yyval.action), ROUTE_T, NUMBER_ST,	/* route idx */
							NUMBER_ST,						/* number of params */
							SCRIPTVAR_ELEM_ST,				/* parameters */
							(void*)(long)i_tmp,
							(void*)(long)(yyvsp[(5) - (6)].intval),
							(void*)a_tmp);
					}
    break;

  case 556:

/* Line 1806 of yacc.c  */
#line 2495 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 2496 "cfg.y"
    { (yyval.action)=0; yyerror("bad route"
						"argument"); }
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 2498 "cfg.y"
    { mk_action2( (yyval.action), SET_HOST_T, STR_ST,
														0, (yyvsp[(3) - (4)].strval), 0); }
    break;

  case 559:

/* Line 1806 of yacc.c  */
#line 2500 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 560:

/* Line 1806 of yacc.c  */
#line 2501 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); }
    break;

  case 561:

/* Line 1806 of yacc.c  */
#line 2504 "cfg.y"
    { mk_action2( (yyval.action), PREFIX_T, STR_ST,
														0, (yyvsp[(3) - (4)].strval), 0); }
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 2506 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 2507 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); }
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 2509 "cfg.y"
    { mk_action2( (yyval.action), STRIP_TAIL_T, 
									NUMBER_ST, 0, (void *) (yyvsp[(3) - (4)].intval), 0); }
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 2511 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 2512 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"number expected"); }
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 2515 "cfg.y"
    { mk_action2( (yyval.action), STRIP_T, NUMBER_ST,
														0, (void *) (yyvsp[(3) - (4)].intval), 0); }
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 2517 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 2518 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"number expected"); }
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 2520 "cfg.y"
    { 
				{   qvalue_t q;
				if (str2q(&q, (yyvsp[(5) - (6)].strval), strlen((yyvsp[(5) - (6)].strval))) < 0) {
					yyerror("bad argument, q value expected");
				}
				mk_action2( (yyval.action), APPEND_BRANCH_T, STR_ST, NUMBER_ST, (yyvsp[(3) - (6)].strval),
						(void *)(long)q); } 
		}
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 2528 "cfg.y"
    { mk_action2( (yyval.action), APPEND_BRANCH_T,
						STR_ST, NUMBER_ST, (yyvsp[(3) - (4)].strval), (void *)Q_UNSPECIFIED) ; }
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 2530 "cfg.y"
    { mk_action2( (yyval.action), APPEND_BRANCH_T,
						STR_ST, NUMBER_ST, 0, (void *)Q_UNSPECIFIED) ; }
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 2532 "cfg.y"
    { mk_action2( (yyval.action), APPEND_BRANCH_T,
						STR_ST, NUMBER_ST, 0, (void *)Q_UNSPECIFIED ) ; }
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 2534 "cfg.y"
    {
						mk_action1((yyval.action), REMOVE_BRANCH_T, NUMBER_ST, (void*)(yyvsp[(3) - (4)].intval));}
    break;

  case 575:

/* Line 1806 of yacc.c  */
#line 2536 "cfg.y"
    {
						mk_action1( (yyval.action), REMOVE_BRANCH_T, SCRIPTVAR_ST, (yyvsp[(3) - (4)].specval));}
    break;

  case 576:

/* Line 1806 of yacc.c  */
#line 2539 "cfg.y"
    {
				spec = (pv_spec_t*)pkg_malloc(sizeof(pv_spec_t));
				memset(spec, 0, sizeof(pv_spec_t));
				tstr.s = (yyvsp[(3) - (6)].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_spec(&tstr, spec)==NULL)
				{
					yyerror("unknown script variable in first parameter");
				}
				if(!pv_is_w(spec))
					yyerror("read-only script variable in first parameter");

				pvmodel = 0;
				tstr.s = (yyvsp[(5) - (6)].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_format(&tstr, &pvmodel)<0)
				{
					yyerror("error in second parameter");
				}

				mk_action2( (yyval.action), PV_PRINTF_T,
						SCRIPTVAR_ST, SCRIPTVAR_ELEM_ST, spec, pvmodel) ;
			}
    break;

  case 577:

/* Line 1806 of yacc.c  */
#line 2562 "cfg.y"
    {
				if(!pv_is_w((yyvsp[(3) - (6)].specval)))
					yyerror("read-only script variable in first parameter");
				pvmodel = 0;
				tstr.s = (yyvsp[(5) - (6)].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_format(&tstr, &pvmodel)<0)
				{
					yyerror("error in second parameter");
				}

				mk_action2( (yyval.action), PV_PRINTF_T,
						SCRIPTVAR_ST, SCRIPTVAR_ELEM_ST, (yyvsp[(3) - (6)].specval), pvmodel) ;
			}
    break;

  case 578:

/* Line 1806 of yacc.c  */
#line 2577 "cfg.y"
    { mk_action2( (yyval.action), SET_HOSTPORT_T, 
														STR_ST, 0, (yyvsp[(3) - (4)].strval), 0); }
    break;

  case 579:

/* Line 1806 of yacc.c  */
#line 2579 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 580:

/* Line 1806 of yacc.c  */
#line 2580 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument,"
												" string expected"); }
    break;

  case 581:

/* Line 1806 of yacc.c  */
#line 2582 "cfg.y"
    { mk_action2( (yyval.action), SET_PORT_T, STR_ST,
														0, (yyvsp[(3) - (4)].strval), 0); }
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 2584 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 583:

/* Line 1806 of yacc.c  */
#line 2585 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); }
    break;

  case 584:

/* Line 1806 of yacc.c  */
#line 2587 "cfg.y"
    { mk_action2( (yyval.action), SET_USER_T,
														STR_ST, 0, (yyvsp[(3) - (4)].strval), 0); }
    break;

  case 585:

/* Line 1806 of yacc.c  */
#line 2589 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 586:

/* Line 1806 of yacc.c  */
#line 2590 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); }
    break;

  case 587:

/* Line 1806 of yacc.c  */
#line 2592 "cfg.y"
    { mk_action2( (yyval.action), SET_USERPASS_T, 
														STR_ST, 0, (yyvsp[(3) - (4)].strval), 0); }
    break;

  case 588:

/* Line 1806 of yacc.c  */
#line 2594 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 589:

/* Line 1806 of yacc.c  */
#line 2595 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); }
    break;

  case 590:

/* Line 1806 of yacc.c  */
#line 2597 "cfg.y"
    { mk_action2( (yyval.action), SET_URI_T, STR_ST, 
														0, (yyvsp[(3) - (4)].strval), 0); }
    break;

  case 591:

/* Line 1806 of yacc.c  */
#line 2599 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 592:

/* Line 1806 of yacc.c  */
#line 2600 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
										"string expected"); }
    break;

  case 593:

/* Line 1806 of yacc.c  */
#line 2602 "cfg.y"
    { mk_action2( (yyval.action), REVERT_URI_T, 0,0,0,0); }
    break;

  case 594:

/* Line 1806 of yacc.c  */
#line 2603 "cfg.y"
    { mk_action2( (yyval.action), REVERT_URI_T, 0,0,0,0); }
    break;

  case 595:

/* Line 1806 of yacc.c  */
#line 2604 "cfg.y"
    { mk_action2( (yyval.action), SET_DSTURI_T,
													STR_ST, 0, (yyvsp[(3) - (4)].strval), 0); }
    break;

  case 596:

/* Line 1806 of yacc.c  */
#line 2606 "cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 597:

/* Line 1806 of yacc.c  */
#line 2607 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
										"string expected"); }
    break;

  case 598:

/* Line 1806 of yacc.c  */
#line 2609 "cfg.y"
    { mk_action2( (yyval.action), RESET_DSTURI_T,
															0,0,0,0); }
    break;

  case 599:

/* Line 1806 of yacc.c  */
#line 2611 "cfg.y"
    { mk_action2( (yyval.action), RESET_DSTURI_T, 0,0,0,0); }
    break;

  case 600:

/* Line 1806 of yacc.c  */
#line 2612 "cfg.y"
    { mk_action2( (yyval.action), ISDSTURISET_T, 0,0,0,0); }
    break;

  case 601:

/* Line 1806 of yacc.c  */
#line 2613 "cfg.y"
    { mk_action2( (yyval.action), ISDSTURISET_T, 0,0,0,0); }
    break;

  case 602:

/* Line 1806 of yacc.c  */
#line 2614 "cfg.y"
    { mk_action2( (yyval.action), FORCE_RPORT_T,
															0, 0, 0, 0); }
    break;

  case 603:

/* Line 1806 of yacc.c  */
#line 2616 "cfg.y"
    { mk_action2( (yyval.action), FORCE_RPORT_T,0, 0, 0, 0); }
    break;

  case 604:

/* Line 1806 of yacc.c  */
#line 2617 "cfg.y"
    {
					mk_action2( (yyval.action), FORCE_LOCAL_RPORT_T,0, 0, 0, 0); }
    break;

  case 605:

/* Line 1806 of yacc.c  */
#line 2619 "cfg.y"
    {
					mk_action2( (yyval.action), FORCE_LOCAL_RPORT_T,0, 0, 0, 0); }
    break;

  case 606:

/* Line 1806 of yacc.c  */
#line 2621 "cfg.y"
    {
					#ifdef USE_TCP
						mk_action2( (yyval.action), FORCE_TCP_ALIAS_T,NUMBER_ST, 0,
										(void*)(yyvsp[(3) - (4)].intval), 0);
					#else
						yyerror("tcp support not compiled in");
					#endif
												}
    break;

  case 607:

/* Line 1806 of yacc.c  */
#line 2629 "cfg.y"
    {
					#ifdef USE_TCP
						mk_action2( (yyval.action), FORCE_TCP_ALIAS_T,0, 0, 0, 0); 
					#else
						yyerror("tcp support not compiled in");
					#endif
										}
    break;

  case 608:

/* Line 1806 of yacc.c  */
#line 2636 "cfg.y"
    {
					#ifdef USE_TCP
						mk_action2( (yyval.action), FORCE_TCP_ALIAS_T,0, 0, 0, 0);
					#else
						yyerror("tcp support not compiled in");
					#endif
										}
    break;

  case 609:

/* Line 1806 of yacc.c  */
#line 2643 "cfg.y"
    {(yyval.action)=0; 
					yyerror("bad argument, number expected");
					}
    break;

  case 610:

/* Line 1806 of yacc.c  */
#line 2646 "cfg.y"
    {
								mk_action2( (yyval.action), SET_ADV_ADDR_T, STR_ST,
											0, (yyvsp[(3) - (4)].strval), 0);
								}
    break;

  case 611:

/* Line 1806 of yacc.c  */
#line 2650 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); }
    break;

  case 612:

/* Line 1806 of yacc.c  */
#line 2652 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 613:

/* Line 1806 of yacc.c  */
#line 2653 "cfg.y"
    {
								(yyval.action)=0;
								tmp=int2str((yyvsp[(3) - (4)].intval), &i_tmp);
								if ((str_tmp=pkg_malloc(sizeof(str)))==0){
										LM_CRIT("cfg. parser: out of memory.\n");
								}else{
									if ((str_tmp->s=pkg_malloc(i_tmp))==0){
										LM_CRIT("cfg. parser: out of memory.\n");
									}else{
										memcpy(str_tmp->s, tmp, i_tmp);
										str_tmp->len=i_tmp;
										mk_action2( (yyval.action), SET_ADV_PORT_T, STR_ST,
													0, str_tmp, 0);
									}
								}
								            }
    break;

  case 614:

/* Line 1806 of yacc.c  */
#line 2669 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument, "
								"string expected"); }
    break;

  case 615:

/* Line 1806 of yacc.c  */
#line 2671 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 616:

/* Line 1806 of yacc.c  */
#line 2672 "cfg.y"
    {
								mk_action2( (yyval.action), FORCE_SEND_SOCKET_T,
									SOCKID_ST, 0, (yyvsp[(3) - (4)].sockid), 0);
								}
    break;

  case 617:

/* Line 1806 of yacc.c  */
#line 2676 "cfg.y"
    { (yyval.action)=0; yyerror("bad argument,"
								" [proto:]host[:port] expected");
								}
    break;

  case 618:

/* Line 1806 of yacc.c  */
#line 2679 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 619:

/* Line 1806 of yacc.c  */
#line 2680 "cfg.y"
    {
								mk_action2( (yyval.action), SERIALIZE_BRANCHES_T,
									NUMBER_ST, 0, (void*)(long)(yyvsp[(3) - (4)].intval), 0);
								}
    break;

  case 620:

/* Line 1806 of yacc.c  */
#line 2684 "cfg.y"
    {(yyval.action)=0; yyerror("bad argument,"
								" number expected");
								}
    break;

  case 621:

/* Line 1806 of yacc.c  */
#line 2687 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 622:

/* Line 1806 of yacc.c  */
#line 2688 "cfg.y"
    {
								mk_action2( (yyval.action), NEXT_BRANCHES_T, 0, 0, 0, 0);
								}
    break;

  case 623:

/* Line 1806 of yacc.c  */
#line 2691 "cfg.y"
    {(yyval.action)=0; yyerror("no argument is"
								" expected");
								}
    break;

  case 624:

/* Line 1806 of yacc.c  */
#line 2694 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 625:

/* Line 1806 of yacc.c  */
#line 2695 "cfg.y"
    {
								mk_action2( (yyval.action), USE_BLACKLIST_T,
									STRING_ST, 0, (yyvsp[(3) - (4)].strval), 0);
								}
    break;

  case 626:

/* Line 1806 of yacc.c  */
#line 2699 "cfg.y"
    {(yyval.action)=0; yyerror("bad argument,"
								" string expected");
								}
    break;

  case 627:

/* Line 1806 of yacc.c  */
#line 2702 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 628:

/* Line 1806 of yacc.c  */
#line 2703 "cfg.y"
    {
								mk_action2( (yyval.action), UNUSE_BLACKLIST_T,
									STRING_ST, 0, (yyvsp[(3) - (4)].strval), 0);
								}
    break;

  case 629:

/* Line 1806 of yacc.c  */
#line 2707 "cfg.y"
    {(yyval.action)=0; yyerror("bad argument,"
								" string expected");
								}
    break;

  case 630:

/* Line 1806 of yacc.c  */
#line 2710 "cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
    break;

  case 631:

/* Line 1806 of yacc.c  */
#line 2711 "cfg.y"
    { 
									mk_action3( (yyval.action), CACHE_STORE_T,
													STR_ST,
													STR_ST,
													STR_ST,
													(yyvsp[(3) - (8)].strval),
													(yyvsp[(5) - (8)].strval),
													(yyvsp[(7) - (8)].strval));
							}
    break;

  case 632:

/* Line 1806 of yacc.c  */
#line 2721 "cfg.y"
    { 
								elems[0].type = STR_ST; 
								elems[0].u.data = (yyvsp[(3) - (10)].strval); 
								elems[1].type = STR_ST; 
								elems[1].u.data = (yyvsp[(5) - (10)].strval); 
								elems[2].type = STR_ST; 
								elems[2].u.data = (yyvsp[(7) - (10)].strval); 
								elems[3].type = NUMBER_ST; 
								elems[3].u.number = (yyvsp[(9) - (10)].intval);
								(yyval.action) = mk_action(CACHE_STORE_T, 4, elems, line); 
							}
    break;

  case 633:

/* Line 1806 of yacc.c  */
#line 2733 "cfg.y"
    { 
								elems[0].type = STR_ST; 
								elems[0].u.data = (yyvsp[(3) - (10)].strval); 
								elems[1].type = STR_ST; 
								elems[1].u.data = (yyvsp[(5) - (10)].strval); 
								elems[2].type = STR_ST; 
								elems[2].u.data = (yyvsp[(7) - (10)].strval); 
								elems[3].type = SCRIPTVAR_ST; 
								elems[3].u.data = (yyvsp[(9) - (10)].specval);
								(yyval.action) = mk_action(CACHE_STORE_T, 4, elems, line); 
							}
    break;

  case 634:

/* Line 1806 of yacc.c  */
#line 2745 "cfg.y"
    { 
									mk_action2( (yyval.action), CACHE_REMOVE_T,
													STR_ST,
													STR_ST,
													(yyvsp[(3) - (6)].strval),
													(yyvsp[(5) - (6)].strval));
							}
    break;

  case 635:

/* Line 1806 of yacc.c  */
#line 2752 "cfg.y"
    { 
									mk_action3( (yyval.action), CACHE_FETCH_T,
													STR_ST,
													STR_ST,
													SCRIPTVAR_ST,
													(yyvsp[(3) - (8)].strval),
													(yyvsp[(5) - (8)].strval),
													(yyvsp[(7) - (8)].specval));
							}
    break;

  case 636:

/* Line 1806 of yacc.c  */
#line 2761 "cfg.y"
    { 
									mk_action3( (yyval.action), CACHE_COUNTER_FETCH_T,
													STR_ST,
													STR_ST,
													SCRIPTVAR_ST,
													(yyvsp[(3) - (8)].strval),
													(yyvsp[(5) - (8)].strval),
													(yyvsp[(7) - (8)].specval));
							}
    break;

  case 637:

/* Line 1806 of yacc.c  */
#line 2770 "cfg.y"
    { 
								elems[0].type = STR_ST; 
								elems[0].u.data = (yyvsp[(3) - (10)].strval); 
								elems[1].type = STR_ST; 
								elems[1].u.data = (yyvsp[(5) - (10)].strval); 
								elems[2].type = NUMBER_ST; 
								elems[2].u.number = (yyvsp[(7) - (10)].intval);
								elems[3].type = NUMBER_ST;
								elems[3].u.number = (yyvsp[(9) - (10)].intval);
								(yyval.action) = mk_action(CACHE_ADD_T, 4, elems, line); 
							}
    break;

  case 638:

/* Line 1806 of yacc.c  */
#line 2781 "cfg.y"
    { 
								elems[0].type = STR_ST; 
								elems[0].u.data = (yyvsp[(3) - (10)].strval); 
								elems[1].type = STR_ST; 
								elems[1].u.data = (yyvsp[(5) - (10)].strval); 
								elems[2].type = SCRIPTVAR_ST; 
								elems[2].u.data = (yyvsp[(7) - (10)].specval);
								elems[3].type = NUMBER_ST;
								elems[3].u.number = (yyvsp[(9) - (10)].intval);
								(yyval.action) = mk_action(CACHE_ADD_T, 4, elems, line); 
							}
    break;

  case 639:

/* Line 1806 of yacc.c  */
#line 2792 "cfg.y"
    { 
								elems[0].type = STR_ST; 
								elems[0].u.data = (yyvsp[(3) - (10)].strval); 
								elems[1].type = STR_ST; 
								elems[1].u.data = (yyvsp[(5) - (10)].strval); 
								elems[2].type = NUMBER_ST; 
								elems[2].u.number = (yyvsp[(7) - (10)].intval);
								elems[3].type = NUMBER_ST;
								elems[3].u.number = (yyvsp[(9) - (10)].intval);
								(yyval.action) = mk_action(CACHE_SUB_T, 4, elems, line); 
							}
    break;

  case 640:

/* Line 1806 of yacc.c  */
#line 2803 "cfg.y"
    { 
								elems[0].type = STR_ST; 
								elems[0].u.data = (yyvsp[(3) - (10)].strval); 
								elems[1].type = STR_ST; 
								elems[1].u.data = (yyvsp[(5) - (10)].strval); 
								elems[2].type = SCRIPTVAR_ST; 
								elems[2].u.data = (yyvsp[(7) - (10)].specval);
								elems[3].type = NUMBER_ST;
								elems[3].u.number = (yyvsp[(9) - (10)].intval);
								(yyval.action) = mk_action(CACHE_SUB_T, 4, elems, line); 
							}
    break;

  case 641:

/* Line 1806 of yacc.c  */
#line 2814 "cfg.y"
    { 
								elems[0].type = STR_ST; 
								elems[0].u.data = (yyvsp[(3) - (8)].strval); 
								elems[1].type = STR_ST; 
								elems[1].u.data = (yyvsp[(5) - (8)].strval); 
								elems[2].type = STR_ST; 
								elems[2].u.data = (yyvsp[(7) - (8)].strval);
								(yyval.action) = mk_action(CACHE_RAW_QUERY_T, 3, elems, line); 
							}
    break;

  case 642:

/* Line 1806 of yacc.c  */
#line 2823 "cfg.y"
    { 
								elems[0].type = STR_ST; 
								elems[0].u.data = (yyvsp[(3) - (6)].strval); 
								elems[1].type = STR_ST; 
								elems[1].u.data = (yyvsp[(5) - (6)].strval); 
								(yyval.action) = mk_action(CACHE_RAW_QUERY_T, 2, elems, line); 
							}
    break;

  case 643:

/* Line 1806 of yacc.c  */
#line 2830 "cfg.y"
    {
						 			cmd_tmp=(void*)find_cmd_export_t((yyvsp[(1) - (3)].strval), 0, rt);
									if (cmd_tmp==0){
										if (find_cmd_export_t((yyvsp[(1) - (3)].strval), 0, 0)) {
											yyerror("Command cannot be "
												"used in the block\n");
										} else {
											yyerrorf("unknown command <%s>, "
												"missing loadmodule?", (yyvsp[(1) - (3)].strval));
										}
										(yyval.action)=0;
									}else{
										elems[0].type = CMD_ST;
										elems[0].u.data = cmd_tmp;
										(yyval.action) = mk_action(MODULE_T, 1, elems, line);
									}
								}
    break;

  case 644:

/* Line 1806 of yacc.c  */
#line 2847 "cfg.y"
    {
									cmd_tmp=(void*)find_cmd_export_t((yyvsp[(1) - (4)].strval), (yyvsp[(3) - (4)].intval), rt);
									if (cmd_tmp==0){
										if (find_cmd_export_t((yyvsp[(1) - (4)].strval), (yyvsp[(3) - (4)].intval), 0)) {
											yyerror("Command cannot be "
												"used in the block\n");
										} else {
											yyerrorf("unknown command <%s>, "
												"missing loadmodule?", (yyvsp[(1) - (4)].strval));
										}
										(yyval.action)=0;
									}else{
										elems[0].type = CMD_ST;
										elems[0].u.data = cmd_tmp;
										(yyval.action) = mk_action(MODULE_T, (yyvsp[(3) - (4)].intval)+1, elems, line);
									}
								}
    break;

  case 645:

/* Line 1806 of yacc.c  */
#line 2864 "cfg.y"
    { (yyval.action)=0; yyerrorf("bad arguments for "
												"command <%s>", (yyvsp[(1) - (4)].strval)); }
    break;

  case 646:

/* Line 1806 of yacc.c  */
#line 2866 "cfg.y"
    { (yyval.action)=0; yyerrorf("bare word <%s> found, command calls need '()'", (yyvsp[(1) - (2)].strval)); }
    break;

  case 647:

/* Line 1806 of yacc.c  */
#line 2868 "cfg.y"
    {
				mk_action1((yyval.action), XDBG_T, STR_ST, (yyvsp[(3) - (4)].strval));	}
    break;

  case 648:

/* Line 1806 of yacc.c  */
#line 2870 "cfg.y"
    {
				mk_action1((yyval.action), XLOG_T, STR_ST, (yyvsp[(3) - (4)].strval)); }
    break;

  case 649:

/* Line 1806 of yacc.c  */
#line 2872 "cfg.y"
    {
				mk_action2((yyval.action), XLOG_T, STR_ST, STR_ST, (yyvsp[(3) - (6)].strval), (yyvsp[(5) - (6)].strval)); }
    break;

  case 650:

/* Line 1806 of yacc.c  */
#line 2874 "cfg.y"
    {
				mk_action1((yyval.action), RAISE_EVENT_T, STR_ST, (yyvsp[(3) - (4)].strval)); }
    break;

  case 651:

/* Line 1806 of yacc.c  */
#line 2876 "cfg.y"
    {
				mk_action2((yyval.action), RAISE_EVENT_T, STR_ST, SCRIPTVAR_ST, (yyvsp[(3) - (6)].strval), (yyvsp[(5) - (6)].specval)); }
    break;

  case 652:

/* Line 1806 of yacc.c  */
#line 2878 "cfg.y"
    {
				mk_action3((yyval.action), RAISE_EVENT_T, STR_ST, SCRIPTVAR_ST, SCRIPTVAR_ST, (yyvsp[(3) - (8)].strval), (yyvsp[(5) - (8)].specval), (yyvsp[(7) - (8)].specval)); }
    break;

  case 653:

/* Line 1806 of yacc.c  */
#line 2880 "cfg.y"
    {
				mk_action2((yyval.action), SUBSCRIBE_EVENT_T, STR_ST, STR_ST, (yyvsp[(3) - (6)].strval), (yyvsp[(5) - (6)].strval)); }
    break;

  case 654:

/* Line 1806 of yacc.c  */
#line 2882 "cfg.y"
    {
				mk_action3((yyval.action), SUBSCRIBE_EVENT_T, STR_ST, STR_ST, NUMBER_ST, (yyvsp[(3) - (8)].strval), (yyvsp[(5) - (8)].strval), (void*)(long)(yyvsp[(7) - (8)].intval)); }
    break;

  case 655:

/* Line 1806 of yacc.c  */
#line 2884 "cfg.y"
    {
				elems[0].type = STR_ST; 
				elems[0].u.data = (yyvsp[(3) - (14)].strval); 
				elems[1].type = STR_ST; 
				elems[1].u.data = (yyvsp[(5) - (14)].strval); 
				elems[2].type = STR_ST; 
				elems[2].u.data = (yyvsp[(7) - (14)].strval); 
				elems[3].type = STR_ST; 
				elems[3].u.data = (yyvsp[(9) - (14)].strval);
				elems[4].type = STR_ST; 
				elems[4].u.data = (yyvsp[(11) - (14)].strval);
				elems[5].type = SCRIPTVAR_ST; 
				elems[5].u.data = (yyvsp[(13) - (14)].specval);
				(yyval.action) = mk_action(CONSTRUCT_URI_T,6,elems,line); }
    break;

  case 656:

/* Line 1806 of yacc.c  */
#line 2898 "cfg.y"
    {
				elems[0].type = SCRIPTVAR_ST;
				elems[0].u.data = (yyvsp[(3) - (6)].specval);
				elems[1].type = SCRIPTVAR_ST;
				elems[1].u.data = (yyvsp[(5) - (6)].specval); 
				(yyval.action) = mk_action(GET_TIMESTAMP_T,2,elems,line); }
    break;

  case 657:

/* Line 1806 of yacc.c  */
#line 2904 "cfg.y"
    {
				mk_action2((yyval.action), SCRIPT_TRACE_T, 0, 0, 0, 0); }
    break;

  case 658:

/* Line 1806 of yacc.c  */
#line 2906 "cfg.y"
    {
				pvmodel = 0;
				tstr.s = (yyvsp[(5) - (6)].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_format(&tstr, &pvmodel)<0)
					yyerror("error in second parameter");
				mk_action2((yyval.action), SCRIPT_TRACE_T, NUMBER_ST,
						   SCRIPTVAR_ELEM_ST, (void *)(yyvsp[(3) - (6)].intval), pvmodel); }
    break;

  case 659:

/* Line 1806 of yacc.c  */
#line 2914 "cfg.y"
    {
				pvmodel = 0;
				tstr.s = (yyvsp[(5) - (8)].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_format(&tstr, &pvmodel)<0)
					yyerror("error in second parameter");
				mk_action3((yyval.action), SCRIPT_TRACE_T, NUMBER_ST,
						   SCRIPTVAR_ELEM_ST, STR_ST, (void *)(yyvsp[(3) - (8)].intval), pvmodel, (yyvsp[(7) - (8)].strval)); }
    break;



/* Line 1806 of yacc.c  */
#line 9928 "cfg.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 2067 of yacc.c  */
#line 2926 "cfg.y"


extern int column;
extern int startcolumn;
extern char *finame;

#define get_cfg_file_name \
	((finame) ? finame : cfg_file ? cfg_file : "default")

static inline void warn(char* s)
{
	LM_WARN("warning in config file %s, line %d, column %d-%d: %s\n",
			get_cfg_file_name, line, startcolumn, column, s);
}

static void yyerror(char* s)
{
	LM_CRIT("parse error in config file %s, line %d, column %d-%d: %s\n",
			get_cfg_file_name, line, startcolumn, column, s);
	cfg_errors++;
}

#define ERROR_MAXLEN 1024
static void yyerrorf(char *fmt, ...)
{
	char *tmp = pkg_malloc(ERROR_MAXLEN);
	va_list ap;
	va_start(ap, fmt);

	vsnprintf(tmp, ERROR_MAXLEN, fmt, ap);
	yyerror(tmp);

	pkg_free(tmp);
	va_end(ap);
}


static struct socket_id* mk_listen_id(char* host, int proto, int port)
{
	struct socket_id* l;
	l=pkg_malloc(sizeof(struct socket_id));
	if (l==0){
		LM_CRIT("cfg. parser: out of memory.\n");
	}else{
		l->name=host;
		l->port=port;
		l->proto=proto;
		l->adv_name=NULL;
		l->adv_port=0;
		l->next=0;
	}
	return l;
}

static struct socket_id* set_listen_id_adv(struct socket_id* sock,
											char *adv_name,
											int adv_port)
{
	sock->adv_name=adv_name;
	sock->adv_port=adv_port;
	return sock;
}

