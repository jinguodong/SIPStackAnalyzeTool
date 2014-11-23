/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

/* Line 2068 of yacc.c  */
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



/* Line 2068 of yacc.c  */
#line 317 "cfg.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


