/*----------------------------------------------------------------------*/
/* Now Come on Over Here And Fuck Me Up The Ass - Ncohafmuta V 1.2.1    */
/*----------------------------------------------------------------------*/
/*  This code is a collection of software that originally started       */
/*  as a system called:                                                 */
/*                       IFORMS V 1.0                                   */
/*            Interactive FORum Multiplexor Software - (C) Deep         */
/*                 Last update 25/9/94                                  */
/*                                                                      */
/* As a result of extensive changes, it can no longer be considered     */
/* the same code                                                        */
/*                     -Cygnus (Anthony J. Biacco - Ncohafmuta Ent.)    */
/*                                                                      */
/* Legal note:  This code may NOT be freely distributed.  Doing so may  */
/*              be in violation of the US Munitions laws which cover    */
/*              exportation of encoding technology.                     */
/*----------------------------------------------------------------------*/

/* last modified: Apr 8th, 1999  Cygnus */

#define VERSION  "Ncohafmuta 1.2.1 by Cygnus"
#define UDATA_VERSION "122.ver" /* ONLY CYGNUS CHANGES THIS!!		*/
				/* see README.converting for more info  */

/* This makes common macros for these socket functions to be portable to win32 systems */
#if defined(WIN32) && !defined(__CYGWIN32__)
HANDLE hThread;

#ifdef _DEFINING_CONSTANTS
int S_READ(int sock, char *str, int len) { return recv(sock,str,len,0); }
int S_WRITE(int sock, char *str, int len) { return send(sock,str,len,0); }
#else
extern int S_READ(int sock, char *str, int len);
extern int S_WRITE(int sock, char *str, int len);
#endif

#define CLOSE closesocket
#else
#define S_READ read
#define S_WRITE write
#define CLOSE close
#endif
	

/*--------------------------------------------------------*/
/* Change this to the owner's id on this system           */
/* so promotions can be made                              */
/* THIS PERSON IS GIVEN THE HIGHEST LEVEL IN THE SYSTEM   */
/* ALL LOWERCASE                                          */
/*--------------------------------------------------------*/
#define ROOT_ID      "cygnus"

/*--------------------------------------------------------*/
/* Change this to the talkers email address that mail     */
/* can be sent to. This is also the addy that mail from   */
/* the talker will come from.                             */
/* YOU MUST SET THIS!                                     */
/*--------------------------------------------------------*/
#define SYSTEM_EMAIL "pw@ncohafmuta.com"

/*--------------------------------------------------------*/
/* Change this to the domain of the machine the talker is */
/* on. (i.e. if you're on talker.com, set to talker.com   */
/* if you're on joe.blow.net, set to blow.net             */
/* This will only be used if we cant get the domain from  */
/* getdomainname()                                        */
/*--------------------------------------------------------*/
#define DEF_DOMAIN "ncohafmuta.com"

/*--------------------------------------------------------*/
/* change BOT_ID to the bot's id on this system           */
/* if you're using the bot, otherwise comment out         */
/* ALL LOWERCASE                                          */
/*--------------------------------------------------------*/
#define BOT_ID       "spokes"

/*--------------------------------------------------------*/
/* change this to the name of the owner of the bot        */
/* ALL LOWERCASE                                          */
/*--------------------------------------------------------*/
#define BOTS_ROOTID  "cygnus"

/*---------------------------------------------------------------------*/
/* Set to what you want to call the talker and then change the rest of */
/* occurences where you see the marker  SYSNAME                        */
/*                                                                     */
/* DO NOT USE A SINGLE QUOTE (') or DOUBLE QUOTE (") IN THE NAME       */
/*---------------------------------------------------------------------*/
#define SYSTEM_NAME "PinWHeeLs"

/*------------------------------------------------*/
/* Password encryption key                        */
/*                                                */
/* You should NOT need to change this at all!     */
/*                                                */
/* WARNING: Never change this once you have users */
/*          it is used to encrypt the passwords   */
/*          and if you change it they will not be */
/*          able to get back in                   */
/*------------------------------------------------*/

#ifdef _DEFINING_CONSTANTS
int lock[]={'D','E','E','P','L','O','C','K'};  /* 8 chars */
int num_locks=8;                                       
#else
extern int lock[];
extern int num_locks;
#endif

/*--------------------------------------------------------*/
/* strings you MIGHT want to change                       */
/* Strings containing ^<two_letter code> in them contain  */
/* color..read about color use in helpfiles/coloruse      */
/* and ".set color test" online                           */
/*--------------------------------------------------------*/

                        /* <username> <ip addy> <user #>:<socket #> <host> */
#define SYS_SITE_LINE   "%-13.13s %-15.15s (%2.2d:%3.3d) %s"
#define SYNTAX_ERROR    "Huh?  Type '.h' for help."
#define ANNOUNCEMENT_HI " [** ^HGARRIVING is:^ %s %s ^HR(%s)^ **] "
#define ANNOUNCEMENT_LO " [^HGARRIVING is:^ %s %s ^HR(%s)^ ] "
#define SYS_DEPART_HI   " [** ^HMLEAVING is:^ %s %s **]"
#define SYS_DEPART_LO   " [ ^HMLEAVING is,^ %s %s ]"

/* Connection responses */
#define WWW_CLOSED "<HTML><CENTER><H1>Sorry - the web port is not open for access at this time</H1></CENTER><BR></HTML>\n"
#define WHO_CLOSED "Sorry - the who port is not open for access at this time\n"
#define WIZ_CLOSED "Sorry - the system is closed to further wiz logins at the moment"
#define SYS_CLOSED "Sorry - the system is closed to further logins at the moment"
#define TOTAL_USERS_MESS "                *** Currently serving  %ld  happy Lag Haters ***"
#define BANNED_MESS "* Your site has been banned , email %s *"
#define BANNED_NEW_MESS "New user accounts are prohibited from your site."
#define BANNED_COMMENT  "None."

/* Login messages */
#define SYS_LOGIN       "So, what's your name?: "
#define SYS_PASSWD_PROMPT "Enter your secret code: "
#define PASS_VERIFY     "Please re-enter your secret code: "
#define EMAIL_VERIFY    "Enter an email address we can send your password to: "
#define PASEMAIL_VERIFY "Enter the password you were given in email: "

/* Login responses */
#define ATTEMPT_MESS    "Maximum attempts exceeded..."

/* New user message when re-entered password doesn't match the first */
#define NON_VERIFY      "Come now, your secret codes have to match."

#define PASS_NOT_RIGHT  "Nah, that's not right!"
#define NO_NEW_LOGIN    "New user creation is not allowed at this time"
#define ONLY_LET        "Only letters are allowed in login name"
#define SYS_NAME_SHORT  "Nah, that name is too short"
#define SYS_NAME_LONG   "Nah, that name is too long"
#define SYS_PASSWD_LONG "Password too long"
#define SYS_PASSWD_INVA "Invalid password given [must be at least 3 letters]."
#define PASS_NO_NAME1   "Password cannot be the login name."
#define PASS_NO_NAME2   "That's like suicide!"
#define IF_QUIT_LOGIN   "\nAbandoning login attempt\n"
#define NEW_CREATE      "A New account has been created for you!"
#define NEW_USER_MESS   "Well well well, a new user..."
#define ALREADY_ON      "^HGAlready online! - Terminating old session and saving comm buffers^"
#define TERMIN          "This session is being terminated"

#define AFK_BACK        "- %s is back -"
#define AFK_BACK2       "Terminal UN-locked! You are back!"
#define AFK_BACK3       "- You are back from %s! -"
#define HELP_HELP       "The command is \".help\" If you are new here type \".h help\""
#define NEW_USER_TO_WIZ "**NEW USER**  %s at %s (%s)\07"
#define NEW_HELP        "\n\r\07              **Please read  .h new  .faq  AND  .rules**"
#define NEW_HELP2       "\07     ** To auto-promote yourself, do .desc, .entpro, and .set gender **"
#define SYS_LOOK_FAILED " * Lookup Failed * "
#define SYS_RES_OFF     " Resolver turned off "

/* Prompts */
#define CONF_PROMPT     "** Press RETURN to continue, Q to stop reading **"
#define PROFILE_PROMPT  "(S)ave, (V)iew, (R)edo, or (A)bort?: "

/* No No No */
#define NO_USER_STR     "  [Dude, the user doesn't exist]"
#define NO_WIZ_ENTRY    "You are not permitted to enter the wizard port."
#define NO_NEWS         "There is no news today"
#define NO_FAQ          "FAQ is not available."
#define NO_MAP          "There is no map."
#define NO_WIZLIST      "There is no wizard list."
#define NO_TLIST        "There is no talkers on the list."
#define NO_RULESFILE    "There are no rules defined."
#define NO_ROOM         "There is no such room!"
#define NO_SINGSTR      "You forgot the words already?!"
#define NO_COMM         "You can't do that in your current condition!"
#define NO_SHOUT        "You can hardly make a sound."
#define NO_SHOUT_SOS    "You have been naughty, wizards don't want to be bugged by you."
#define NO_MATCH_SUIC   "The password you entered doesn't match your current password."
#define NOT_UNIQUE      "Name was not unique, matched: %s"
#define NOT_WORTHY      "Sorry - you're not worthy of that command"
#define GIVE_CAPNAME    "You have to give your name!"

#define BYE_MESS        "\07Goodbye! See ya soon!..."
#define IDLE_BYE_MESS   "\07Well you had your chance....Bye bye"
#define USE_MESS        "%16.16s after %s of use"
                        /* DATE after DAYS,HOURS,MINUTES of use */
                        /* sent on .quit */
/* Tic-tac-toe stuff */
#define TTT_WON		"Yippee!! you beat %s at TTT :)"
#define TTT_LOST	"Doh!! you lost TTT to %s :("
#define TTT_DRAW	"Your TTT game with %s is a draw :|"
#define TTT_ABORT1	"You abort your TTT game against %s."
#define TTT_ABORT2	"%s aborts your TTT game."
#define TTT_PLAYING	"Sorry, but %s is currently playing someone else"
#define TTT_OFFERED	" %s has offered a game of Tic Tac Toe"
#define TTT_MY_MOVE (1<<18)
#define TTT_AM_NOUGHT (1<<19)

/* Hangman stuff */
#define HANG_BADGUESS	"Your guess is wrong!!  And you know what that means..."
#define HANG_BADLETTER	"That letter isn't in the word!  And you know what that means..."
#define HANG_WON	"^HGCongratz!  You guessed the word without dying!^"
#define HANG_LOST	"^HRUh-oh!  You couldn't guess the word and died!^"
#define HANG_GUESSED	"You have already guessed that letter!  And you know what that means..."
#define HANG_1OCCUR	"Well done!  There was 1 occurrence of the letter %s"
#define HANG_MOCCUR	"Well done!  There were %d occurrences of the letter %s"

#define APROMOTE_MESS   "Thank you. You have been auto-promoted to ^%s^"
#define PROMOTE_MESS    "^HR%s^ has promoted you to ^HR%s^"
#define UPROMOTE_MESS   "You have promoted ^HR%s^ to ^HR%s^"
#define DEMOTE_MESS     "^HR%s^ has demoted you to ^HR%s^"
#define UDEMOTE_MESS    "You have demoted ^HR%s^ to ^HR%s^"
#define DEF_KILL_MESS   "You have been vaporized ...   HAVE A NICE DAY."
#define XCOMM_CANT      "%s wanted to xcomm you!"
#define XCOMMON_MESS    "I suspect you made somebody mad. Now you are a zombie."
#define XCOMMOFF_MESS   "You have been returned to the living users. Play nice or else"
#define GCOMM_CANT      "%s wanted to gagcomm you!"
#define GCOMMON_MESS    "Not behaving ourselves, are we? Gotta pay the piper now"
#define GCOMMOFF_MESS   "The piper thinks you have paid your dues. Play nice or else."
#define FROG_CANT       "%s wanted to turn you into a frog, hah!"
#define FROGON_MESS     "Someone turned you into kermit's cousin. Ribbit!"
#define FROGOFF_MESS    "Maybe a princess didn't kiss you, but you're not a frog anymore :)"
#define FROG_TALK       "Ribbit, ribbit"
#define FROG_EMOTE      "croaks at everyone.\0"
#define FROG_SEMOTE     "croaks at you"
#define FROG_ECHO       "A frog croaks nearby."
#define MUZZLE_CANT     "%s wanted to muzzle you!"
#define MUZZLEON_MESS   "You are no longer allowed to shout"
#define MUZZLEOFF_MESS  "You are again allowed to shout"
#define ANCHOR_CANT     "%s wanted to staple you to the floor, hah!"
#define ANCHORON_MESS   "Someone just stapled you to floor. Time for a snickers?"
#define ANCHOROFF_MESS  "You are again free to move around!"
#define ANCHORED_DOWN   "Where do you think you're going stapled to the floor?"
#define MOVE_TOUSER     "A force grabs you and pulls you into the beyond!!"
#define MOVE_TOREST     "%s is pulled into the beyond!"
#define MOVE_TONEW      "%s appears from nowhere!"
#define ARREST_TOUSER   "A man in a white coat grabs you and throws you into a van!!"
#define ARREST_TOREST   "A man in a white coat grabs %s and throws them into a van!!"
#define ARREST_TOJAIL   "A group of white coats bring %s in!!"
#define COME_VIS        "%s steps out of the shadows."
#define UCOME_VIS       "%s You step out of the shadows."
#define GO_INVIS        "%s fades into the darkness..."
#define UGO_INVIS       "%s You fade, shimmer, and vanish..."
#define COME_TELEMESS   "arrives in a blinding flash!"
#define GO_TELEMESS     "%s disappears in a shimmer of light!"

#define INVIS_ACTION_LABEL "A shadow"
#define INVIS_TALK_LABEL   "A mysterious voice"
#define INVIS_MOVES        "Something disturbs the air."

#define STAFF_PREFIX       "<wiz>" /* goes before wiztells and wiz messes */

#define NOW_PUBLIC      "Room access returned to public"
#define WHO_COLOR       "Current citizens on ^HM%s^"
#define WWHO_COLOR      "Current wizards on ^HM%s^"
#define FWHO_COLOR      "Current friends on ^HM%s^"
#define WHO_PLAIN       "Current citizens on %s"
#define SHORT_WHO       "%d citizen%s %s connected."
#define SHADOW_COLOR    "There %s ^HM%d^ shadow%s"
#define SHADOW_PLAIN    "There %s %d shadow%s"
#define SHADOW_WWW      "<tr> <td colspan=\"2\">There %s <b>%i</b> shadow%s at the moment</td> </tr>"
#define USERCNT_COLOR   "Total of ^HG%d^ citizen%s signed on."
#define WUSERCNT_COLOR  "Total of ^HG%d^ wizard%s signed on."
#define FUSERCNT_COLOR  "Total of ^HG%d^ friend%s signed on."
#define USERCNT_PLAIN   "Total of %d citizen%s signed on."
#define USERCNT_WWW     "<tr> <td colspan=\"6\">There %s <b>%i</b> citizen%s logged on right now</td></tr>"
#define USER_WRITE      "You write the message on the board."
#define OTHER_WRITE     "%s writes a message on the board"
#define INVIS_WRITE     "A ghostly hand writes a message on the board"

/* Message defaults */
#define DEF_DESC        "-- a new citizen"
#define DEF_EMAIL       "--- email not specified ---"
#define DEF_GENDER      "No idea"
#define DEF_SUCC        "Thank you for paging me."
#define DEF_FAIL        "I'm not here right now."
#define DEF_URL         "--- homepage not specified ---"
#define DEF_PICURL      "--- picture not specified --- "
#define DEF_ICQ		"No idea"
#define DEF_ENTER       "walks in."
 /* DEFAULT exitmessage must leave space for room name at the end */
#define DEF_EXIT        "goes to the"

/* Communication formats */
/* The @@ chars in these formats is used to turn off the color codes    */
/* before the next to last " is printed. If you're not using an end     */
/* character like a " after the user's message the @@ can be taken out  */
/*                                                                      */
/* Some VIS_ and INVIS_ defines are the SAME but the VIS_ ones replace  */
/* the first %s with the users name and the INVIS_ ones replace it with */
/* either INVIS_ACTION_LABEL or INVIS_TALK_LABEL                        */
/*                                                                      */
/* ALSO NOTE: The bot operates on using the default communications for- */
/*            mats..so if you change these at all, the bot is not gonna */
/*            work unless you modify the bot's code.  Sorry.            */
#define VIS_SAYS        "%s says \"%s@@\""
#define INVIS_SAYS      "* %s says \"%s@@\""
#define VIS_DIRECTS     "%s says ^(to %s)^ \"%s@@\""
#define INVIS_DIRECTS   "* %s says ^(to %s)^ \"%s@@\""
#define VIS_TELLS       "%s tells you: \"%s@@\""
#define INVIS_TELLS     "%s tells you: \"%s@@\""
#define VIS_FROMTELLS   " <priv-com %s>: %s"
#define VIS_FROMLINK    " <priv-link %s>: %s"
#define VIS_MUTTERS     "%s mutters \"%s@@\" (to everyone but %s)"
#define INVIS_MUTTERS   "* %s mutters \"%s@@\" (to everyone but %s)" 
#define VIS_MUTEMOTE    "%s%s@@ (behind %s's back)"
#define INVIS_MUTEMOTE  "* %s%s@@ (behind %s's back)"
#define USER_SHOUTS     "%s shouts \"%s@@\""
#define INVIS_SHOUTS    "%s shouts \"%s@@\""
#define YOU_SHOUT       "You shout \"%s@@\""
#define USER_SHTHINKS   "& %s thinks . o O ( %s@@ )"
#define INVIS_SHTHINKS  "& %s thinks . o O ( %s@@ )"
#define YOU_SHTHINKS    "You think to everyone . o O ( %s@@ )"

#define IS_PRIVATE      "You left in a room that is now private so will be put in the main room."
#define IS_ARRESTED     "You can't do that while you're arrested!"
#define IS_GAGGED       "That user has you gagged. Sorry."
#define IS_ENTERING     "That user is entering a profile, room description, or vote topic at the moment"
#define IS_BANNED       "Sorry, that name is banned from use on this talker"
#define VIS_IN_HERE     "^There %s %d shadow%s in here.^"

 /* Message that gets mailed to users who exceed their mailsize quota */
#define MAILFILE_NOTIFY "Your mailbox has exceeded the size limit by %ld characters. You will not be able to receive any more mail until you delete some of the messages in you mailbox."

 /* Message that goes to a sender that exceeeds his or her sentmail quota */
#define MAILFILE2_NOTIFY "Your sentmail box has exceeded the size limit by %ld characters. Please delete some sentmail so that messages can be written to it again."

#define MAILFROM_TALKER "\n^HY==^ You have mail waiting from ^HGTHE TALKER^ ^HY==^"
#define MAILFROM_USER "\n^HY==^ You have mail waiting from ^HG%s^ ^HY==^"
#define MAIL_AUTOFWD "New_mail has been sent to your email address. *autofwd*"
#define MAIL_TO "You write %s some mail"
#define MAIL_NEW "\07You have  ^HG%i ^ new mail message%s"
#define MAIL_ACCESS "==> last mail access was %s"

/* SYSNAME */
#define EXT_WHO1 "+------------------------------------------+\n\r"
#define EXT_WHO2 "| External who list                V1.2    |\n\r"
#define EXT_WHO3 "| For PinWHeeLs  Port %-4d                 |\n\r"
#define EXT_WHO4 "+------------------------------------------+\n\r\n\r"
/* SYSNAME */

/*------------------------------------------------------------------*/
/* these are the files needed to run the talker                     */
/*------------------------------------------------------------------*/

#define INIT_FILE    "init_data"
#define MESSDIR      "messboards"
#define NEWSFILE     "lib/newsfile"
#define LOGFILE      "syslog"
#define HELPDIR      "helpfiles"
#define MAILDIR      "maildir"
#define RESTRICT_DIR "restrict"
#define RESTRICT_NEW_DIR "newrestrict"
#define USERDIR      "users"                 
#define PICTURE_DIR  "picture"            
#define FAQFILE      "lib/faqfile"
#define LASTFILE     "lastcommand"
#define MAPFILE      "lib/mapfile"
#define PRO_DIR      "prodir"
#define LIBDIR       "lib"
#define LASTLOGS     "lib/lastlogs"
#define SCHEDFILE    "lib/schedule"
#define WIZFILE      "lib/wizlist"
#define EXEMFILE     "lib/exempts"
#define NBANFILE     "lib/namebans"
#define AGREEFILE    "lib/agreefile"
#define VERIFILE     "lib/emailver/veritracking"
#define VERIINSTRUCT "lib/emailver/e-instruct1"
#define VERINSTRUCT2 "lib/emailver/e-instruct2"
#define VERIEMAIL    "lib/emailver/veriemail"
#define ACTVYFILE    "lib/activity"
#define RULESFILE    "lib/rulesfile"
#define TALKERLIST   "lib/talkerlist"
#define SYSFULLFILE  "lib/sysfullfile"
#define NUKEWARN     "lib/nukewarn"
#define HANGDICT     "lib/hangman_words"
#define WLOGDIR      "warnings"

#define WEBFILES     "webfiles"
#define WEBCONFIG    "webfiles/webport.cfg"


/* Hostname resolution options */
/* the talker-wide DNS cache lookup files, for when resolve_names = 1    */
/* if you will never use resolve_names = 1, these 2 settings dont matter */
/* See docs/README.dns_resolving for more info                           */
#define SITECACHE_FILE     "lib/sitecash"
#define SITECACHE_FILE_DEF "lib/sitecash.def"

/* the side-wide DNS cache lookup files, for when resolve_names = 2      */
/* if you will never use resolve_names = 2, these 2 settings dont matter */
/* See docs/README.dns_resolving for more info                           */
#define SITE_WIDE_CACHE_FILE   "/.sitecash"
#define SITE_WIDE_REQUEST_FILE "/.sitecash.req"

/* talker-wide DNS cache limit size, for when resolve_names = 1        */
/* if you will never use resolve_names = 1, this setting doesnt matter */
#define SITECACHE_SIZE 250

/* end of hostname resolution options */


#if !defined(WIN32) || defined(__CYGWIN32__)
#define PROGNAME     "./restart"    /* file used to restart talker */
#endif

/* If the following programs exist on your system..you can find them        */
/* by doing a "locate sendmail" and "which fortune" at the UNIX prompt      */
/* and inserting the proper paths here                                      */
/* If you do not have sendmail, you can fallback to using the normal "mail" */
/* program. You can find its correct path by typing "which mail"            */
/* sendmail is USUALLY under /usr/bin/sendmail or /usr/lib/sendmail         */

#define MAILPROG     "/usr/sbin/sendmail -t"      /* program used to send email */
						  /* if sendmail, use -t switch */
#define FORTPROG     "/usr/local/bin/fortune"  /* program used to */
                                                  /* send a fortune  */

/*-------------------------------------------------------------------*/
/* string size constants                                             */
/*-------------------------------------------------------------------*/

#define ARR_SIZE      9700  /* max socket can take is 9600 (+100 to be sure) */
#define OUT_BUFF_SIZE 1000  /* for write_str and write_str_nr         */
#define MAX_LINE_LEN  200   /* number of characters to store to one line */
                            /* of the conversation buffer             */
#define DESC_LEN      41    /* max short description length           */
#define NAME_LEN      21    /* max username length                    */
#define FILE_NAME_LEN 256
#define NUM_LINES     15    /* number of lines of conversation to store */
#define TOPIC_LEN     45    /* max room topic length                  */
#define HOME_LEN      66    /* WWW homepage length                    */
#define EMAIL_LENGTH  80    /* max email address length               */
#define MAX_ENTERM    80    /* max room entermessage length + 2       */
#define MAX_EXITM     45    /* max room exitmessage length + 2        */
#define REASON_LEN    320   /* max length of siteban reason to file   */
                            /* and for .wlog for users                */
#define ATMOS_LEN     161   /* 2 lines of text & a possible @ for newline */
#define KILL_LEN      160   /* max message on a custom .kill          */

#define PRO_LINES     15    /* max number of profile lines stored     */
#define VOTE_LINES    10    /* max number of vote topic lines stored  */
#define ROOM_DESC_LINES     10    /* max number of room desc lines    */
#define MAX_ALERT     15    /* max users a person can be alerted of   */
#define MAX_GAG       15    /* max users a person can gag             */
#define MAX_GRAVOKES  15    /* max commands total you can grant to or */
			    /* revoke from a user  */
#define MAX_ATMOS     10    /* max number of atmospherics per room    */
#define MAX_AUTOFORS  15    /* max number of forwarded smails allowed */
                            /* per day per user. For SPAM precaution  */
#define MAX_MAILSIZE  50000 /* max size in bytes user mailboxes can be */
#define MAX_SMAILSIZE 40000 /* max size in bytes user SENT mailboxes   */
                            /* can be                                  */

/* This is how many abbreviations are declared in the command           */
/* structure sys[]  Default is fine unless you change them in server.c  */
#define NUM_ABBRS     16    /* number of commands that have character */
                            /* abbreviations and can be changed       */

/*-------------------------------------------------------------------*/
/* room or area constants                                            */
/*-------------------------------------------------------------------*/

#define MAX_AREAS   60      /* max rooms for server */
#define PRINUM      2       /* no. of users in room b4 it can be private */ 
#define ARREST_ROOM "outhouse"  /* room that arrested users go to */
#define HEAD_ROOM   "headquarters"  /* room for special users only, which */
                                    /* are defined in go()                */
#define NERF_ROOM   "arena" /* only room to nerf in */
#define BOT_ROOM    "pond"  /* room the bot STAYS in and in which a */
                            /* blank say is not .review for bot reasons */
#define INIT_ROOM   0       /* main, normal talker room       */
                            /* 0 = first room defined in init_data */

/* Try not to change this setting after users are already made    */
/* IF you make this the same as INIT_ROOM, users will not be able */
/* to .home or .go until they set a description or are a level    */
/* higher than 0                                                  */
/* I suggest making this room right after INIT_ROOM in            */
/* config/init_data                                               */
#define NEW_ROOM    "newbie_heaven"    /* room that newbies log into */

/*-------------------------------------------------------------------*/
/* misc. constants used throughout the code                          */
/*-------------------------------------------------------------------*/

#define TRUE            1
#define FALSE           0

#ifndef NULL
#define NULL            0
#endif

#define NEW             1
#define ANY             2

#define SIZ            500
#define MAX_CHAR_BUFF  560 /* max output a user can give in one shot */   
                           /* default was 380, about 4.5 lines, now  */   
                           /* 7 lines.. 80 chars x 7 lines is 560    */   

#define SHOW_HIDDEN     1

#define PAUSE_LOGIN     1   /* set to 1 if you want users to have to   */
			    /* hit enter after they see their login    */
                            /* stats before entering the room, on      */
                            /* login. If not, set to 0                 */

#define AFK_NERF        0   /* set to 1 if you want users to be able to  */
                            /* go afk or bafk in the nerf_room */

#define DAYS_OFF        30  /* users this number of days old to be      */
                            /* nuked on a auto-expire or .expire -n     */
                            /* These users are also shown in .expire    */

#define AUTO_EXPIRE     2   /* This sets the option for automatically  */
			    /* expiring users older than DAYS_OFF,     */
			    /* daily at midnight. Here's the options:  */
			    /* 0 - Disable expiring, Disable warning   */
			    /* 1 - Disable expiring, Enable warning    */
			    /* 2 - Enable expiring, Enable warning     */
			    /* 3 - Enable expiring, Disable warning    */
			    /*                                         */
                            /* Set it to some other number if you want */
                            /* to do the .expire -n yourself           */
			    /* Warning explained below with TIME_TO_GO */
                            /* Use ".auto expire" online to toggle     */

#define TIME_TO_GO	3   /* The time in days a user has left before */
			    /* an auto-expire will remove them. When   */
			    /* the user hits this number of days b4    */
			    /* the nuking, an email will be sent out   */
			    /* to them, provided they have their email */
			    /* addy set. This number must be a whole   */
			    /* number greater than 0 to be activated.  */

#define NUKE_NOSET      1   /* set this to 1 if you want the talker to */
                            /* automatically nuke users on logout that */
                            /* haven't set a short description         */
                            /* use ".auto nuke" while online to toggle */

#define AUTO_PROMOTE    1   /* set this to 1 if you want users to be   */
                            /* able to promote themselves after they   */
                            /* do .desc, .entpro, and .set gender      */
                            /* use ".auto promote" online to toggle    */

#define FOLLOWIS_JOIN   0   /* set this to 1 if you want .follow to    */
                            /* allow teleports instead of the room     */
                            /* having to be connected                  */

#define ANON_SUGGEST    0   /* set this to 1 is you want suggestions   */
                            /* with .suggest to be anonymous, or to 0  */
                            /* if you want the users name with their   */
                            /* suggestion.                             */

#define LONGLOGIN_WHO   1   /* the type of who shown when user types   */
                            /* who at the login prompt. 0 is a .swho   */
                            /* 1 is a normal .who                      */

#define REBOOT_A_CRASH  0   /* if we crash from a segmentation fault or */
                            /* bus error (usual crash causes) should we */
                            /* reboot? 1 for yes, 0 for no              */

#define NUM_MOTDS       2   /* number of MOTDs in the lib directory     */
                            /* to be picked from at random for a login  */
                            /* screen. 2 would mean there's an motd0    */
                            /* and motd1. Just an example               */

#define SUB_BANNAME     1   /* for .banname, should names be banned     */
                            /* exactly the way given or as sub-strings. */
                            /* Exactly means that if you ban 'joe' only */
                            /* 'joe' will be banned. sub-string means   */
                            /* if you ban 'joe' then joe, papajoe, joey */
                            /* ,etc.. will be banned                    */
                            /* Set to 1 for sub-strings, 0 for exactly  */

#define MAX_NEW_PER_DAY 50  /* Max new users per day the system allows  */
			    /* Can change online with ".quota"          */

#define COLOR_DEFAULT	0   /* Is coloring for new users on by default? */
			    /* 0 for no, 1 for yes			*/
			    /* Coloring by default for new users is	*/
			    /* DISCOURAGED because you dont know if the */
			    /* users terminal is capable of it. It may  */
			    /* have unpredictable results to their      */
			    /* screen.  You have been warned!		*/

#define	TZONE   "localtime"	/* if set to localtime,talker time will */
				/* be whatever the servers localtime is */
				/* i.e. talker.com is set to GMT.If you */
				/* want it to be different, enter the   */
				/* path to the timezone file in the     */
				/* tzinfo talker directory. i.e. if you */
				/* want US Pacific standard time, set   */
				/* to "US/Pacific"			*/

/* Standard footer that is put on the end of an auto-forwarded smail */
#define EXT_MAIL1     "\n          ---------------------------------------------------------------\n"
#define EXT_MAIL2     "                       This is your new mail from %s\n"
#define EXT_MAIL3     "                  Do not reply to this through normal e-mail\n"
#define EXT_MAIL4     " \n"
#define EXT_MAIL5     "              If you wish to respond to the writer of this message\n"
/* if they have their email address set and is visible */
#define EXT_MAIL8     "              you may reply to the address above normally.\n"
/* if not */
#define EXT_MAIL9     "              you must mail them on the talker.\n"
/* next line used if an RFC-compliant mail program is not used */
#define EXT_MAIL10    "              try replying to %s\n"
#define EXT_MAIL7     "          ---------------------------------------------------------------\n"

/*-------------------------------------------------------*/
/* these sizes control the number of connections allowed */
/* Dont set the NUM_USERS to a real high number unless   */
/* you know your talker will get this many people simul- */
/* taneously..it will eat more RAM. 40 is a good start   */
/*-------------------------------------------------------*/

#define NUM_USERS           40 
#define NUM_WIZES           5
#define MAX_WHO_CONNECTS    2
#define MAX_WWW_CONNECTS    2
#define MAX_INTERCONNECTS   10
#define MAX_CYPHERCONNECTS  10
#define MAX_USERS           NUM_USERS + NUM_WIZES 

/*-------------------------------------------------------------------*/
/* alarm, timers, countdowns, and atmos info                         */
/*-------------------------------------------------------------------*/
#ifdef _DEFINING_CONSTANTS
int     ATMOS_RESET     = 5;
int     ATMOS_FACTOR    = 5;
int     ATMOS_COUNTDOWN = 5;
int     ATMOS_LAST      = 0;
#else
extern int ATMOS_RESET;
extern int ATMOS_FACTOR;
extern int ATMOS_COUNTDOWN;
extern int ATMOS_LAST;
#endif

#define MAX_ATIME     60    /* alarm time in seconds */
                            /* DONT CHANGE unless you know what */
                            /* youre doing                      */
#define IDLE_TIME     240   /* time in mins. user can idle before booting */
#define LOGIN_TIMEOUT 2     /* time in mins. before the user is       */
                            /* kicked out of the login prompt         */

/*---------------------------------------*/
/* Definitions for the types of commands */
/* Normally leave these alone            */
/*---------------------------------------*/
#define NONE 0
#define COMM 1
#define INFO 2
#define MAIL 3
#define MESG 4
#define MISC 5
#define MOOV 6
#define BANS 7
#define SETS 8

/* Globals that have to do with ranks */
/* NOTE: It is not wise to EVER make the superuser rank and the  */
/* Senior level the same number                                  */

#define RANKS "01234"        /* Your ranks, lowest to highest */

/*----------------------------------------------------*/
/* this line is the odds for each rank for .fight,    */
/* separated by commas                                */
/* Make the odds what you want and make sure you have */
/* a number for every rank                            */
/*----------------------------------------------------*/
#ifdef _DEFINING_CONSTANTS
int odds[]={10, 30, 270, 2150, 21000};
#else
extern int odds[];
#endif

#define MIN_HIDE_LEVEL  2    /* level at which invisibility is allowed */
                             /* also level users can see invis users   */
                             /* in .who list */
#define ROOMVIS_LEVEL   3    /* level at which users can see the name */
                             /* of an invisible room in .w */
#define MONITOR_LEVEL   2    /* level at which monitor is allowed */
#define EMAIL_LEVEL     3    /* level at which a hidden email is shown */
#define WHO_LEVEL       1    /* level at which user can see ranks on */
                             /* the .who list */
#define LINENUM_LEVEL   2    /* level at which line numbers on message */
                             /* boards can be seen */
#define GRIPE_LEVEL     3    /* level that can read gripes and hidden  */
                             /* room message boards*/
#define CBUFF_LEVEL     2    /* level that can clear all buffers */
#define IDLE_LEVEL      2    /* level exempt from idle timeouts  */
#define TELEP_LEVEL     2    /* level that can teleport to rooms */
#define PRIV_ROOM_RANK  2    /* rank before private without two users   */
#define EXPIRE_EXEMPT  -1    /* users at or above this level get 30     */
                             /* extra days before they're up for an     */
                             /* expire.  Set to -1 to disable the bonus */
#define WIZ_LEVEL       2    /* wiz rank         */
                             /* this user is seen under .wizards, gets */
                             /* wiztells, can go through gags and      */
                             /* other priv-com stopage, etc.. */
#define SENIOR_LEVEL    3    /* level that can unmuzzle THEMSELVES  */
#define MAX_LEVEL       4    /* highest level in the system  */


/* Do NOT make TO_SAME and TO_ABOVE both 1..it doesn't work      */
/* because if you allow users to promote others to a rank higher */
/* than their own, OF COURSE you're gonna allow PROMOTE_TO_SAME  */
/* 1-YES  0-NO */
#define PROMOTE_TO_SAME  1   /* allow promotions to the same level as promoter */
#define PROMOTE_TO_ABOVE 0   /* allow promotions to a higher level as promoter */
#define DEMOTE_SAME      0   /* allows a wiz or higher to demote users */
                             /* same level as them */

#ifdef _DEFINING_CONSTANTS
/*------------------------------*/
/*  Rank descriptors            */
/*------------------------------*/
char *ranks[]={"Newbie",
               "Wheeler",
               "Wizard",
               "Manager",
               "Admin"};

/*----------------------------*/
/* Port status descriptors    */
/*----------------------------*/
char *opcl[]={"CLOSED",
              "OPEN"};
#else
extern char *ranks[];
extern char *opcl[];
#endif

/*--------------------------------------------------------*/
/* Message types used for writeall                        */
/*--------------------------------------------------------*/
#define NUM_IGN_FLAGS 24
typedef struct
{
        char text[32];
} flag_names_type;
#ifdef _DEFINING_CONSTANTS
flag_names_type flag_names[NUM_IGN_FLAGS+1] = {
       {"misc_things"},
       {"afks"}, 
       {"says"}, 
       {"logs"},
       {"shouts"},
       {"knocks"},
       {"messages"},
       {"topics"},
       {"kills"},
       {"bcasts"},
       {"moves"},
       {"echos"},
       {"greets"},
       {"pictures"},
       {"fights"},
       {"atmos"}, 
       {"wiztells"},
       {"succs"}, 
       {"fails"},
       {"nerfs"}, 
       {"roomdescs"},
       {"beeps"},
       {"tictactoes"},
       {"<not defined yet>"},
       {""}
      };
#else
extern flag_names_type flag_names[NUM_IGN_FLAGS+1];
#endif

#define NONE      0
#define AFK_TYPE  1   /* .afk .bafk */
#define SAY_TYPE  2   /* .say .emote .mutter .to */
#define LOGIO     3   /* logins and logouts */
#define SHOUT     4   /* .shout .shemote .shthink */
#define KNOCK     5   /* .knock */
#define MESSAGE   6   /* .write */  
#define TOPIC     7   /* .topic */
#define KILL      8   /* .kill */
#define BCAST     9   /* .bcast .bbcast name changes */
#define MOVE      10  /* .move .bring .hide */
#define ECHOM     11  /* .echo */
#define GREET     12  /* .greet */
#define PICTURE   13  /* .picture .ptell */   
#define FIGHT     14  /* .fight */
#define ATMOS     15  /* atmospherics */
#define WIZT      16  /* .wiztell */
#define SUCCS     17  /* .succs after priv. comm */
#define FAILS     18  /* .fails after failed priv. comm */
#define NERFS     19  /* .nerf */
#define ROOMD     20  /* room descriptions in .look */
#define BEEPS     21  /* any beeping */
#define TTTS      22  /* tic-tac-toes */
#define MISC2     23  /* future */

/*-----------------------------------------------------------------*/
/* Gagged types                                                    */
/*  These are message types that user Y won't see from user X when */
/*  a .gag is put on user X by user Y                              */
/*  The whole list is right above this comment                     */
/*  Private communication, mail, and .examine/.ustat being         */
/*  gagged is a GIVEN                                              */
/*-----------------------------------------------------------------*/
#ifdef _DEFINING_CONSTANTS
int gagged_types[]={ECHOM,PICTURE,
		    GREET,SAY_TYPE,
		    SHOUT,KNOCK,
		    FIGHT,AFK_TYPE,
		    NERFS,TTTS};

/*-----------------------------------------------------------*/
/* Port offsets (added) to the main port, which is           */
/* defined in config/init_data.                              */
/*-----------------------------------------------------------*/
int WIZARD_OFFSET =  50;   /* wiz port for incoming          */
int WHO_OFFSET    =   1;   /* standard offset for who        */
int WWW_OFFSET    =  30;   /* www offset                     */
int INTER_OFFSET  =   2;   /* inter talker offset         DONT CHANGE   */
int CRYPT_OFFSET  =   3;   /* offset for caller-id verify DONT CHANGE   */
#else
extern int gagged_types[];
extern int WIZARD_OFFSET;
extern int WHO_OFFSET;
extern int WWW_OFFSET;
extern int INTER_OFFSET;
extern int CRYPT_OFFSET;
#endif

#ifdef _DEFINING_CONSTANTS
int resolve_names=1;    /* are we resolving to alphanumeric addresses?  */
#else
extern int resolve_names;
#endif

/* abbreviation structure */
typedef struct {
char abbr[2]; 
char com[20];
} Abbr;

/*-----------------------------*/
/* Macro variable definitions  */
/*-----------------------------*/
#define NERF_MACRO      0   /* set to 1 if you want users to be able to */
                            /* make macros for .nerf                    */
#define NUM_MACROS    20    /* number of macros allowed                 */
#define MACRO_LEN     100   /* max macro length                         */
#define CANT_MACRO      "Sorry, you can't macro that command."
#define MACRO_NLONG     "Sorry, that macro name is too long."
#define MACRO_LONG      "Sorry, that macro is too long."

typedef struct {
char name[12];
char body[MACRO_LEN+1];
} Macro;

/*-----------------------------------------------------------*/
/*  .expire exempted users - this defines 20 names           */
/*   never CHANGE these strings, only add more if you need   */
/*-----------------------------------------------------------*/
#define NUM_EXPIRES 20
#ifdef _DEFINING_CONSTANTS
char expired[NUM_EXPIRES][22] =
  {
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name"
};
#else
extern char expired[NUM_EXPIRES][22];
#endif

/*-----------------------------------------------------------*/
/*  names banned from logging in - this defines 20 names     */
/*   never CHANGE these strings, only add more if you need   */
/*-----------------------------------------------------------*/
#define NUM_NAMEBANS 20
#ifdef _DEFINING_CONSTANTS
char nbanned[NUM_NAMEBANS][22] =
  {
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name",
  "name"
  };
#else
extern char nbanned[NUM_NAMEBANS][22];
#endif

/*----------------------------------------------*/
/* Colors for random color exits list in .look  */
/*----------------------------------------------*/
#define NUM_COLORS 7
#ifdef _DEFINING_CONSTANTS
char color_text[NUM_COLORS][15] =  
 {
  "^HR",
  "^HG",
  "^HY",
  "^HB",
  "^HM",
  "^HC",
  "^HW"
  };
#else
extern char color_text[NUM_COLORS][15];
#endif

/** red, green, yellow, blue, purple, cyan, white **/

/* User structure */
struct profile {                                                   
	char name[NAME_LEN];
	char password[NAME_LEN];                               
	char desc[DESC_LEN]; /* user description */
	char email_addr[EMAIL_LENGTH];               
	char sex[32];                               
	char site[21]; /* internet site number */
        char init_date[25];                            
        char init_site[21];                           
        char init_netname[64]; /* 1.1.0 */
        char last_date[25];                      
        char last_site[21];                 
        char entermsg[MAX_ENTERM];
        char exitmsg[MAX_EXITM+1];
        char succ[MAX_ENTERM];
        char fail[MAX_ENTERM];
        char homepage[HOME_LEN];
        char creation[25];
        char security[MAX_AREAS+1];
	char login_name[NAME_LEN];
	char login_pass[NAME_LEN];
	char phone_user[NAME_LEN];
        char mutter[45];
        char page_file[80];
	 char *pro_start,*pro_end;
        int pro_enter;
         char *roomd_start,*roomd_end;
        int roomd_enter;
         char *vote_start,*vote_end;
        int vote_enter;
        int locked;                    
	int suspended;                     
	int area;
	int listen;
	int shout;
	int igtell;
	int color;
        int clrmail; /* User is clearing his mail file */
	int sock;  /* socket number */
	int monitor;
	int time;  /* length of time user has been on */
	int vis;   /* is user visible */
	int super;
	int invite;  /* area currently invited to */
	int last_input; /* this and warning are used for idle check */
	int warning_given;
	int logging_in;  /* user is logging in */
        int attleft;  /* no. of logging in attempts left */
	int file_posn;
	char net_name[64]; /* internet site name */
	Macro Macros[NUM_MACROS];
        int  conv_count;
        char conv[NUM_LINES+1][MAX_LINE_LEN+1];
        int cat_mode;
        int rows;
        int cols;
        int car_return;
        int abbrs;
        int white_space;
        int line_count;
        int number_lines;
        int times_on;
        int afk;
        int lockafk;
        int upper;
        int lower;
        int aver;
        long totl;
        int autor;
        int autof;
        int automsgs; /* 1.0.26 */
        int gagcomm;  /* 1.0.26 */
        int semail;
        int quote;
        int hilite;
        int new_mail;
        long numcoms;
        int mail_num;
        int numbering;
        char flags[NUM_IGN_FLAGS+2];
        char real_id[50];
        char attach_port;
        int  char_buffer_size;
        char char_buffer[MAX_CHAR_BUFF];
        int friend_num;
	char friends[MAX_ALERT][NAME_LEN+1]; /* 1.2.0 */
        int gag_num;
	char gagged[MAX_GAG][NAME_LEN+1];    /* 1.2.0 */
        int revokes_num;
	char revokes[MAX_GRAVOKES][10];    /* 1.2.0b-pl11 */
        int nerf_shots,nerf_energy;
        int nerf_kills,nerf_killed;
        int passhid;
        int pbreak;
        int beeps;       /* 1.1.0 */
        int mail_warn;   /* 1.1.0 */
        long rawtime;
        int muz_time;
        int xco_time;
        int gag_time;  /* 1.0.26 */
        int frog;      /* 1.0.26 */
        int frog_time; /* 1.0.26 */
        int promote;   /* 1.0.26 */
        char home_room[NAME_LEN];
        char afkmsg[46];
        char last_name[64];        /* 1.0.26 */
        Abbr custAbbrs[NUM_ABBRS+10];
        char say_name[NAME_LEN];   /* 1.1.0 */
	int help;	/* 1.2.0 */
	int who;	/* 1.2.0 */
	int ttt_kills,ttt_killed;		/* 1.2.1 */
	int ttt_board,ttt_opponent,ttt_playing; /* 1.2.1 - temp */
	int hang_wins,hang_losses;		/* 1.2.1 */
	int hang_stage;				/* 1.2.1 - temp */
	char hang_word[TOPIC_LEN];		/* 1.2.1 - temp */
	char hang_word_show[TOPIC_LEN];		/* 1.2.1 - temp */
	char hang_guess[TOPIC_LEN];		/* 1.2.1 - temp */
        int anchor;	/* 1.2.0 */
	int anchor_time;	/* 1.2.0 */
	char webpic[HOME_LEN];	/* 1.2.0 */
	int t_ent;	/* 1.2.0 - temp */
	int t_num;	/* 1.2.0 - temp */
	char t_name[24];	/* 1.2.0 - temp */
	char t_host[31];	/* 1.2.0 - temp */
	char t_ip[16];		/* 1.2.0 - temp */
	char t_port[6];		/* 1.2.0 - temp */
	unsigned int rwho;	/* 1.2.0 - temp */
	short int needs_hostname;	/* 1.2.0b-pl8 - temp */
	int tempsuper;		/* 1.2.0b-pl11 - temp */
	int promptseq;		/* 1.2.0b-pl12 - temp */
	char icq[20];		/* 1.2.1 */
	char miscstr1[10];	/* 1.2.1 */
	char miscstr2[10];	/* 1.2.1 */
	char miscstr3[10];	/* 1.2.1 */
	char miscstr4[10];	/* 1.2.1 */
	int miscnum1;		/* 1.2.1 */
	int miscnum2;		/* 1.2.1 */
	int miscnum3;		/* 1.2.1 */
	int miscnum4;		/* 1.2.1 */
	int miscnum5;		/* 1.2.1 */
        };
/* typedef profile *UserPtr; */
#ifdef _DEFINING_CONSTANTS
struct profile ustr[MAX_USERS];
struct profile t_ustr;
#else
extern struct profile ustr[MAX_USERS];
extern struct profile t_ustr;
#endif

/*** START OF MISC STRUCTURES ***/

/* Connection counts */
struct {
        long logins_today;
        long logins_since_start;
        long quota;
        long new_since_start;
        long new_users_today;
        long tot_users;
        long tot_expired; /* 1.2.0 */
        int cache_hits;   /* 1.2.0b-pl8 */
        int cache_misses; /* 1.2.0b-pl8 */
} system_stats;

/* area structure */
struct {
        char name[NAME_LEN];
        char move[MAX_AREAS];  /* where u can move to from area */
        char topic[TOPIC_LEN+1];
        int private;   
        int hidden;
        int secure;
        int mess_num;  /* num. of messages in area */
        int conv_line; /* next line of conv string to write to */
        int atmos;     /* whether atmospherics are turned on or off */
        } astr[MAX_AREAS];
        
/* Fight structure */
struct {
        int first_user;
        int second_user;
        int issued;
        int time;
       } fight;
        
/* Graphical logins per day structure (.meter -l) */
struct {
        int logins;  
       } logstat[24];
        
/* Miscellaneous port structures */
struct {
        int sock;
        char site[21];
        char net_name[64];
       } whoport[MAX_WHO_CONNECTS];

struct {
        int sock;
        int method;
        int req_length;
        char keypair[700];
        char file[256];
        char site[21];
        char net_name[64];
       } wwwport[MAX_WWW_CONNECTS];


/***** EXPERIMENTAL VARIABLES *****/

#define VEMAIL_L	0
#define LOGIN_L		1
#define ERROR_L		2
#define WARNING_L	3
#define SYSLOG_ALSO	1
#define NEWLINE		1
#define NONEWLINE	0
#define EMAILLOG	"logs/emailver.log"
#define LOGINLOG	"logs/logins.log"
#define ERRORLOG	"logs/errors.log"
#define WARNINGLOG	"logs/warnings.log"

/* Web server return errors */
#define BAD_REQUEST		1
#define NOT_FOUND		2

/* Do we need a web server header for the response? */
#define NO_HEADER		0
#define HEADER			1

#define SYS_VAR "%system%"
#define USER_VAR "%user%"

#if defined(__OSF__) || defined(__osf__)
/* WNOHANG causes the wait to not hang if there are no stopped */
/* or terminated                                               */
#define WNOHANG         0x1     /* dont hang in wait */
#endif /* OSF */

/* Define ECHO if it isn't defined */
#if !defined(ECHO)
#define ECHO 0x00000008
#endif

/*----------------------------------------------------------------------*/
/* Define some macros                                                   */
/*                                                                      */
/*  wbuf     - writes a string to file                                  */
/*  wbufnocr - writes a string to file without a newline, for abbrs     */
/*  wval     - write a numeric value to file                            */
/*  wlong    - write a long numeric value to file, for numcoms, etc..   */
/*  wtime    - write a time structure to file as a readable string      */
/*  rbuf     - read a string from a file                                */
/*  rbufnocr - read a string from a file without ending on a newline    */
/*  rval     - read a numeric value from a file                         */
/*  rtime    - read a time string from a file                           */
/*  rlong    - read a long numeric value from a file                    */
/*----------------------------------------------------------------------*/
#undef feof  /* otherwise feof func. wont compile */
#define LOOP_FOREVER while(1)

#define wbuf(buf) putbuf(f, buf)
#define wbufnocr(buf) fprintf (f, "%s ", (char *)buf) 
#define wval(val) fprintf (f, "%d\n", val)
#define wlong(val) fprintf (f, "%ld\n", val)
#define wtime(val) fprintf (f, "%ld\n", val)
#define rbuf(buf,buflen) getbuf(f, buf, buflen)  
#define rbufnocr(buf) fscanf (f, "%s ", (char *)buf)
#define rval(val) val=getint(f)
#define rtime(val) val=getlong(f)
#define rlong(val) val=getlong(f)   
#define FCLOSE(file) if (file) fclose(file)
#define CHECK_NAME(var) if (check_fname(var,user)) { \
                          write_str(user,"Illegal name."); \
                          return;}
