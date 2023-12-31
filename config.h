/* See LICENSE file for copyright and license details. */

#include <X11/XF86keysym.h>
#define SESSION_FILE "/tmp/dwm-session"

#define CURRENT_TERMINAL "kitty"
#define BROWSER "flatpak run com.brave.Browser"

/* appearance */
static const unsigned int borderpx       = 1;   /* border pixel of windows */
static const unsigned int snap           = 18;  /* snap pixel */
static const int swallowfloating         = 0;   /* 1 means swallow floating windows by default */
static const unsigned int gappih         = 20;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 30;  /* vert outer gap between windows and screen edge */
static const int smartgaps          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = 'A';
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */


/* alt-tab configuration */
static const unsigned int tabmodkey        = 0x40; /* (Alt) when this key is held down the alt-tab functionality stays active. Must be the same modifier as used to run alttabstart */
static const unsigned int tabcyclekey      = 0x17; /* (Tab) when this key is hit the menu moves one position forward in client stack. Must be the same key as used to run alttabstart */
static const unsigned int tabposy          = 1;    /* tab position on Y axis, 0 = top, 1 = center, 2 = bottom */
static const unsigned int tabposx          = 1;    /* tab position on X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxwtab          = 600;  /* tab menu width */
static const unsigned int maxhtab          = 200;  /* tab menu height */

/* Indicators: see patch/bar_indicators.h for options */
// static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
// static int tiledindicatortype            = INDICATOR_NONE;
// static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
// static const char *fonts[]               = { "monospace:size=10" };
static const char *fonts[]          = { "FiraMono Nerd Font:size=12", "fontAwesome:size=14" };
// static const char *fonts[]          = { "FantasqueSansMono:style=bold:size=12", "JoyPixels:pixelsize=14", "siji:pixelsize=14", "fontAwesome:size=14" };
// static const char dmenufont[]            = "monospace:size=10";
static const char dmenufont[]       = "FiraMono Nerd Font:size=12";

static const char *tags[] = { "1", "2", "3", "4", "5"};


static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};
// static char c000000[]                    = "#000000"; // placeholder value
//
// static char normfgcolor[]                = "#bbbbbb";
// static char normbgcolor[]                = "#222222";
// static char normbordercolor[]            = "#444444";
// static char normfloatcolor[]             = "#db8fd9";
//
// static char selfgcolor[]                 = "#eeeeee";
// static char selbgcolor[]                 = "#005577";
// static char selbordercolor[]             = "#005577";
// static char selfloatcolor[]              = "#005577";
//
// static char titlenormfgcolor[]           = "#bbbbbb";
// static char titlenormbgcolor[]           = "#222222";
// static char titlenormbordercolor[]       = "#444444";
// static char titlenormfloatcolor[]        = "#db8fd9";
//
// static char titleselfgcolor[]            = "#eeeeee";
// static char titleselbgcolor[]            = "#005577";
// static char titleselbordercolor[]        = "#005577";
// static char titleselfloatcolor[]         = "#005577";
//
// static char tagsnormfgcolor[]            = "#bbbbbb";
// static char tagsnormbgcolor[]            = "#222222";
// static char tagsnormbordercolor[]        = "#444444";
// static char tagsnormfloatcolor[]         = "#db8fd9";
//
// static char tagsselfgcolor[]             = "#eeeeee";
// static char tagsselbgcolor[]             = "#005577";
// static char tagsselbordercolor[]         = "#005577";
// static char tagsselfloatcolor[]          = "#005577";
//
// static char hidnormfgcolor[]             = "#005577";
// static char hidselfgcolor[]              = "#227799";
// static char hidnormbgcolor[]             = "#222222";
// static char hidselbgcolor[]              = "#222222";
//
// static char urgfgcolor[]                 = "#bbbbbb";
// static char urgbgcolor[]                 = "#222222";
// static char urgbordercolor[]             = "#ff0000";
// static char urgfloatcolor[]              = "#db8fd9";



static const unsigned int baralpha = 0xd0;
// static const unsigned int borderalpha = OPAQUE;
// static const unsigned int alphas[][3] = {
// 	/*                       fg      bg        border     */
// 	[SchemeNorm]         = { OPAQUE, baralpha, borderalpha },
// 	[SchemeSel]          = { OPAQUE, baralpha, borderalpha },
// 	[SchemeTitleNorm]    = { OPAQUE, baralpha, borderalpha },
// 	[SchemeTitleSel]     = { OPAQUE, baralpha, borderalpha },
// 	[SchemeTagsNorm]     = { OPAQUE, baralpha, borderalpha },
// 	[SchemeTagsSel]      = { OPAQUE, baralpha, borderalpha },
// 	[SchemeHidNorm]      = { OPAQUE, baralpha, borderalpha },
// 	[SchemeHidSel]       = { OPAQUE, baralpha, borderalpha },
// 	[SchemeUrg]          = { OPAQUE, baralpha, borderalpha },
// };

// static char *colors[][ColCount] = {
// 	/*                       fg                bg                border                float */
// 	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
// 	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
// 	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
// 	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
// 	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
// 	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
// 	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
// 	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
// 	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
// };




// const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
// static Sp scratchpads[] = {
//    /* name          cmd  */
//    {"spterm",      spcmd1},
// };

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
// static char *tagicons[][NUMTAGS] =
// {
// 	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
// 	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
// 	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
// };


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
// static const Rule rules[] = {
// 	/* xprop(1):
// 	 *	WM_CLASS(STRING) = instance, class
// 	 *	WM_NAME(STRING) = title
// 	 *	WM_WINDOW_ROLE(STRING) = role
// 	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
// 	 */
// 	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
// 	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
// 	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
// 	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
// 	RULE(.class = "Gimp", .tags = 1 << 4)
// 	RULE(.class = "Firefox", .tags = 1 << 7)
// 	RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1)
// };
//

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Brave",  NULL,       NULL,         1 << 4,       0,           -1 },
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
// static const BarRule barrules[] = {
// 	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
// 	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
// 	{  0,        0,     BAR_ALIGN_RIGHT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
// 	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
// 	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status,             draw_status,            click_statuscmd,         NULL,                    "status" },
// 	{ -1,        0,     BAR_ALIGN_NONE,   width_awesomebar,         draw_awesomebar,        click_awesomebar,        NULL,                    "awesomebar" },
// };

/* layout(s) */
static const float mfact     = 0.65; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
// static const int nstack      = 0;    /* number of clients in primary stack area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};
//
//
// static const Layout layouts[] = {
// 	/* symbol     arrange function, { nmaster, nstack, layout, master axis, stack axis, secondary stack axis, symbol func } */
// 	{ "[]=",      flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, TOP_TO_BOTTOM, 0, NULL } }, // default tile layout
//  	{ "><>",      NULL,             {0} },    /* no layout function means floating behavior */
// 	{ "[M]",      flextile,         { -1, -1, NO_SPLIT, MONOCLE, MONOCLE, 0, NULL } }, // monocle
// 	{ "|||",      flextile,         { -1, -1, SPLIT_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, // columns (col) layout
// 	{ ">M>",      flextile,         { -1, -1, FLOATING_MASTER, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // floating master
// 	{ "[D]",      flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, MONOCLE, 0, NULL } }, // deck
// 	{ "TTT",      flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // bstack
// 	{ "===",      flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, // bstackhoriz
// 	{ "|M|",      flextile,         { -1, -1, SPLIT_CENTERED_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, TOP_TO_BOTTOM, NULL } }, // centeredmaster
// 	{ "-M-",      flextile,         { -1, -1, SPLIT_CENTERED_HORIZONTAL, TOP_TO_BOTTOM, LEFT_TO_RIGHT, LEFT_TO_RIGHT, NULL } }, // centeredmaster horiz
// 	{ ":::",      flextile,         { -1, -1, NO_SPLIT, GAPPLESSGRID, GAPPLESSGRID, 0, NULL } }, // gappless grid
// 	{ "[\\]",     flextile,         { -1, -1, NO_SPLIT, DWINDLE, DWINDLE, 0, NULL } }, // fibonacci dwindle
// 	{ "(@)",      flextile,         { -1, -1, NO_SPLIT, SPIRAL, SPIRAL, 0, NULL } }, // fibonacci spiral
// 	{ "[T]",      flextile,         { -1, -1, SPLIT_VERTICAL, LEFT_TO_RIGHT, TATAMI, 0, NULL } }, // tatami mats
// 	{ "[]=",      tile,             {0} },
// 	{ "[M]",      monocle,          {0} },
// 	{ "|M|",      centeredmaster,   {0} },
// 	{ "HHH",      grid,             {0} },
// };


/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },


/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };

// static const char *termcmd[]  = { "st", NULL };

/* This defines the name of the executable that handles the bar (used for signalling purposes) */
#define STATUSBAR "dwmblocks"

static const char *update_sb_volume[] = { "pkill", "-RTMIN+10", "dwmblocks", NULL };

/* commands */
static const char *termcmd[]  = { "kitty", NULL };
static const char *killcmd[]  = { "pkill", "dwm", NULL };
static const char *voltcmd[]  = { "pactl", "set-default-sink", "alsa_output.usb-Universal_Audio_Volt_476_22142040012320-00.analog-surround-40", NULL };
static const char *t9procmd[] = { "pactl", "set-default-sink", "alsa_output.usb-Feixiang_USB_HIFI_Audio-01.analog-stereo", NULL };
static const char *hyperxcmd[] = { "pactl", "set-default-sink", "alsa_output.usb-Kingston_HyperX_Cloud_II_Wireless_000000000001-00.analog-stereo", NULL };
static const char *upvol[] =   { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%", NULL };
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "-5%", NULL };
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute", "@DEFAULT_SINK@", "toggle", NULL };

static const Key keys[] = {
	/* modifier                     key            function                argument */
	{ MODKEY,		                  	XK_space,   	 spawn,                  SHCMD("rofi -show drun") },
	{ MODKEY|ShiftMask,	           	XK_s,        	 spawn,                  SHCMD("flameshot gui") },
  { MODKEY|ControlMask,          	XK_m,   	     spawn,                  {.v = voltcmd } },
	{ MODKEY|ControlMask,          	XK_comma,      spawn,                  {.v = t9procmd } },
	{ MODKEY|ControlMask,          	XK_period,     spawn,                  {.v = hyperxcmd } },
	{ MODKEY|ShiftMask,	           	XK_c,        	 spawn,                  SHCMD("compile-dwm.fish") },
	{ MODKEY|ShiftMask,             XK_q,          spawn,                  {.v = killcmd } },
	{ MODKEY,                       XK_p,          spawn,                  {.v = dmenucmd } },
	{ MODKEY,                       XK_Return,     spawn,                  {.v = termcmd } },
	{ MODKEY,                       XK_b,          togglebar,              {0} },
	{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_j,          rotatestack,            {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_k,          rotatestack,            {.i = -1 } },
	// { MODKEY|Mod4Mask,              XK_j,          inplacerotate,          {.i = +2 } }, // same as rotatestack
	// { MODKEY|Mod4Mask,              XK_k,          inplacerotate,          {.i = -2 } }, // same as reotatestack
	// { MODKEY|Mod4Mask|ShiftMask,    XK_j,          inplacerotate,          {.i = +1} },
	// { MODKEY|Mod4Mask|ShiftMask,    XK_k,          inplacerotate,          {.i = -1} },
	{ MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_i,          incnmaster,             {.i = -1 } },
	// { MODKEY|ControlMask,           XK_i,          incnstack,              {.i = +1 } },
	// { MODKEY|ControlMask,           XK_u,          incnstack,              {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
	// { MODKEY|ShiftMask,             XK_h,          setcfact,               {.f = +0.25} },
	// { MODKEY|ShiftMask,             XK_l,          setcfact,               {.f = -0.25} },
	// { MODKEY|ShiftMask,             XK_o,          setcfact,               {0} },
	{ MODKEY,                       XK_Return,     zoom,                   {0} },
	{ MODKEY|Mod1Mask,              XK_u,          incrgaps,               {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_u,          incrgaps,               {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_i,          incrigaps,              {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_o,          incrogaps,              {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_o,          incrogaps,              {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_6,          incrihgaps,             {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_7,          incrivgaps,             {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_8,          incrohgaps,             {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_9,          incrovgaps,             {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,          togglegaps,             {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,          defaultgaps,            {0} },
	// { Mod1Mask,                     XK_Tab,        alttabstart,            {0} },
	// { MODKEY|ControlMask,           XK_z,          showhideclient,         {0} },
	{ MODKEY,                       XK_q,          killclient,             {0} },
	{ MODKEY|ShiftMask,             XK_q,          quit,                   {0} },
	{ MODKEY|ShiftMask,             XK_r,          quit,                   {1} },
	{ MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,          setlayout,              {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,          setlayout,              {.v = &layouts[2]} },
	// { MODKEY|ControlMask,           XK_t,          rotatelayoutaxis,       {.i = +1 } },   /* flextile, 1 = layout axis */
	// { MODKEY|ControlMask,           XK_Tab,        rotatelayoutaxis,       {.i = +2 } },   /* flextile, 2 = master axis */
	// { MODKEY|ControlMask|ShiftMask, XK_Tab,        rotatelayoutaxis,       {.i = +3 } },   /* flextile, 3 = stack axis */
	// { MODKEY|ControlMask|Mod1Mask,  XK_Tab,        rotatelayoutaxis,       {.i = +4 } },   /* flextile, 4 = secondary stack axis */
	// { MODKEY|Mod5Mask,              XK_t,          rotatelayoutaxis,       {.i = -1 } },   /* flextile, 1 = layout axis */
	// { MODKEY|Mod5Mask,              XK_Tab,        rotatelayoutaxis,       {.i = -2 } },   /* flextile, 2 = master axis */
	// { MODKEY|Mod5Mask|ShiftMask,    XK_Tab,        rotatelayoutaxis,       {.i = -3 } },   /* flextile, 3 = stack axis */
	// { MODKEY|Mod5Mask|Mod1Mask,     XK_Tab,        rotatelayoutaxis,       {.i = -4 } },   /* flextile, 4 = secondary stack axis */
	// { MODKEY|ControlMask,           XK_Return,     mirrorlayout,           {0} },          /* flextile, flip master and stack areas */
	{ MODKEY,                       XK_d,      setlayout,              {0} },
	{ MODKEY|ShiftMask,             XK_d,      togglefloating,         {0} },
	// { MODKEY,                       XK_grave,      togglescratch,          {.ui = 0 } },
	// { MODKEY|ControlMask,           XK_grave,      setscratch,             {.ui = 0 } },
	// { MODKEY|ShiftMask,             XK_grave,      removescratch,          {.ui = 0 } },
	{ MODKEY|ControlMask,           XK_s,          togglesticky,           {0} },
	// { MODKEY,                       XK_0,          view,                   {.ui = ~SPTAGMASK } },
	// { MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~SPTAGMASK } },
	{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
	{ 0,                            XF86XK_AudioLowerVolume, spawn, {.v = update_sb_volume } },
	{ 0,                            XF86XK_AudioMute, spawn,        {.v = update_sb_volume } },
	{ 0,                            XF86XK_AudioRaiseVolume, spawn, {.v = update_sb_volume } },
	{ 0,                            XF86XK_AudioLowerVolume, spawn, {.v = downvol } },
	{ 0,                            XF86XK_AudioMute, spawn,        {.v = mutevol } },
	{ 0,                            XF86XK_AudioRaiseVolume, spawn, {.v = upvol   } },
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	// { ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
	// { ClkWinTitle,          0,                   Button3,        showhideclient, {0} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	// { ClkStatusText,        0,                   Button1,        sigstatusbar,   {.i = 1 } },
	// { ClkStatusText,        0,                   Button2,        sigstatusbar,   {.i = 2 } },
	// { ClkStatusText,        0,                   Button3,        sigstatusbar,   {.i = 3 } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	// { ClkClientWin,         MODKEY|ShiftMask,    Button3,        dragcfact,      {0} },
	// { ClkClientWin,         MODKEY|ShiftMask,    Button1,        dragmfact,      {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};


