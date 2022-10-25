/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 0;   /* border pixel of windows */
static const unsigned int snap           = 8;  /* snap pixel */
static const int swallowfloating         = 1;   /* 1 means swallow floating windows by default */

#ifdef desktop
static const unsigned int gappih         = 6;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 6;  /* vert inner gap between windows */

static const unsigned int gappoh         = 5;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 5;  /* vert outer gap between windows and screen edge */
#elif laptop
static const unsigned int gappih         = 12;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 12;  /* vert inner gap between windows */

static const unsigned int gappoh         = 12;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 12;  /* vert outer gap between windows and screen edge */
#endif

static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 0;   /* 0 means bottom bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = -1;

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_LARGER_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;

#ifdef desktop
static const char *fonts[]          = {
   "LiterationMono Nerd Font:pixelsize=14:antialias=true:autohint=true",
   "JoyPixels:pixelsize=12:antialias=true:autohint=true",
   "Latin Modern Math:pixelsize=12:antialias=true:autohint=true",
};
#elif laptop
static const char *fonts[]          = {
   "LiterationMono Nerd Font:pixelsize=20:antialias=true:autohint=true",
   "JoyPixels:pixelsize=18:antialias=true:autohint=true",
   "Latin Modern Math:pixelsize=18:antialias=true:autohint=true",
};
#endif

static const char dmenufont[]            = "monospace:size=10";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#005577";
static char selfloatcolor[]              = "#005577";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#005577";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#005577";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";




static char *colors[][ColCount] = {
    /*                       fg                bg                border                float */
    [SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
    [SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
    [SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
    [SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
    [SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
    [SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
    [SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
    [SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
    [SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};



static const char *const autostart[] = {
    "zsh", "-c", "/home/$USERNAME/.config/init/init.sh", NULL,
    NULL /* terminate */
};


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
static char *tagicons[][NUMTAGS] =
{
    [DEFAULT_TAGS]        = { "一", "二", "三", "四", "五", "六", "セ", "八", "九" },
    [ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
    [ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


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
static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     *  WM_WINDOW_ROLE(STRING) = role
     *  _NET_WM_WINDOW_TYPE(ATOM) = wintype
     */
    RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
    RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
    RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
    RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
#ifdef desktop
    RULE(.class = "firefox", .monitor = 1)

    RULE(.title = "Sqlectron", .monitor = 1, .tags = 1 << 1)

    RULE(.title = "Discord", .monitor = 0)

    RULE(.class = "spotify", .monitor = 3, .tags = 1 << 1)
    RULE(.class = "Spotify", .monitor = 3, .tags = 1 << 1)

    RULE(.title = "Entertainment", .monitor = 3)
    RULE(.title = "qBittorrent", .monitor = 3, .tags = 1 << 8)
#endif
    RULE(.class = "st", .isterminal = 1)
    RULE(.class = "St", .isterminal = 1)

    RULE(.class = "MultiMC 5 - Version 0.6.16-custom", .isterminal = 0)
    RULE(.title = "Chrome", .isterminal = 0)
    RULE(.title = "chrome", .isterminal = 0)
    RULE(.title = "chrome", .isterminal = 0)
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
static const BarRule barrules[] = {
    /* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
    { -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
    { statusmon, 0,     BAR_ALIGN_RIGHT,  width_status,             draw_status,            click_status,            NULL,                    "status" },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */



static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
};


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
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *sudodmenucmd[] = { "sudo", "dmenu_run", NULL };

static const char *termcmd[]  = { "st", NULL };

static const char *dmenuappimagecmd[] = { "dmenu-appimage", NULL };

static const char *dmenuinsertcmd[] = { "dmenu-insert", NULL };
static const char *dmenuoutputcmd[] = { "dmenu-output", NULL };

static const char *dmenubluetoothcmd[] = { "st", "-e", "bluetooth", NULL };

static const char *dmenurestartcmd[] = { "dmenu-restart", NULL };

static const char *dmenupowercmd[] = { "dmenu-power", NULL };

static const char *browsercmd[] = { "chrome", NULL };

static const char *wallpapercmd[] = { "wallpaper-window", NULL };

static const char *eclipsecmd[] = { "eclipse", NULL };

static const char *discordcmd[] = { "discord", NULL };
static const char *spotifycmd[] = { "spotify", NULL };

#include <X11/XF86keysym.h>

static Key keys[] = {
    /* modifier                     key            function                argument */
    { MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
    { MODKEY|ShiftMask,             XK_space,  spawn,          {.v = sudodmenucmd } },

    { MODKEY,                       XK_a,      spawn,          {.v = dmenuappimagecmd } },

    { MODKEY,                       XK_i,      spawn,          {.v = dmenuinsertcmd } },
    { MODKEY,                       XK_o,      spawn,          {.v = dmenuoutputcmd } },

    { MODKEY,                       XK_b,      spawn,          {.v = dmenubluetoothcmd } },

    { MODKEY,                       XK_r,      spawn,          {.v = dmenurestartcmd } },

    { MODKEY,                       XK_F4,     spawn,          {.v = dmenupowercmd } },

    { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },

    // Volume keys
    { MODKEY|ShiftMask,             XK_comma,  spawn,          SHCMD("volume -d 5") },
    { MODKEY|ShiftMask,             XK_period, spawn,          SHCMD("volume -i 5") },

    { 0,              XF86XK_AudioRaiseVolume, spawn,          SHCMD("volume -i 5") },
    { 0,              XF86XK_AudioLowerVolume, spawn,          SHCMD("volume -d 5") },
    { 0,              XF86XK_AudioMute,        spawn,          SHCMD("volume -m") },

    { 0,              XF86XK_AudioPlay,        spawn,          SHCMD("mpris-ctl pp") },
    { 0,              XF86XK_AudioPause,       spawn,          SHCMD("mpris-ctl pp") },
    { 0,              XF86XK_AudioStop,        spawn,          SHCMD("mpris-ctl pause") },
    { 0,              XF86XK_AudioNext,        spawn,          SHCMD("mpris-ctl --player active next") },
    { 0,              XF86XK_AudioPrev,        spawn,          SHCMD("mpris-ctl --player active prev") },

    { 0,              XF86XK_MonBrightnessUp,  spawn,          SHCMD("brightness -i 5") },
    { 0,              XF86XK_MonBrightnessDown,spawn,          SHCMD("brightness -d 5") },

    { MODKEY,                       XK_c,      spawn,          {.v = browsercmd } },
    { MODKEY,                       XK_w,      spawn,          {.v = wallpapercmd } },
    { MODKEY,                       XK_e,      spawn,          {.v = eclipsecmd } },
    { MODKEY,                       XK_s,      spawn,          {.v = spotifycmd } },
    { MODKEY,                       XK_d,      spawn,          {.v = discordcmd } },

    { MODKEY,                       XK_f,      togglebar,      {0} },

    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },

    { MODKEY,                       XK_p,      zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },

    { MODKEY|ShiftMask,             XK_c,      quit,           {0} },
    { MODKEY,                       XK_q,      killclient,     {0} },

    { MODKEY,                       XK_h,      focusmon,       {.i = -1 } },
    { MODKEY,                       XK_l,      focusmon,       {.i = +1 } },

    { MODKEY|ShiftMask,             XK_h,      focustagmon,    {.i = -1 } },
    { MODKEY|ShiftMask,             XK_l,      focustagmon,    {.i = +1 } },

    // Music keys
    { MODKEY,                       XK_comma,  spawn,          SHCMD("mpris-ctl --player active prev") },
    { MODKEY,                       XK_period, spawn,          SHCMD("mpris-ctl --player active pp") },
    { MODKEY,                       XK_slash,  spawn,          SHCMD("mpris-ctl --player active next") },

    TAGKEYS(                        XK_1,                                  0)
    TAGKEYS(                        XK_2,                                  1)
    TAGKEYS(                        XK_3,                                  2)
    TAGKEYS(                        XK_4,                                  3)
    TAGKEYS(                        XK_5,                                  4)
    TAGKEYS(                        XK_6,                                  5)
    TAGKEYS(                        XK_7,                                  6)
    TAGKEYS(                        XK_8,                                  7)
    TAGKEYS(                        XK_9,                                  8)
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask           button          function        argument */
    { ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,                   Button2,        zoom,           {0} },
    { ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
    { ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,                   Button1,        view,           {0} },
    { ClkTagBar,            0,                   Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};
