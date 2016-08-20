/* See LICENSE file for copyright and license details. */

#include <stdint.h>
#include <stdbool.h>


#define MY_STATUS \
    sprintf(stext, "dwm-%s",   \
        VERSION                          \
        );


/* appearance */
static const char *fonts[]          = { "monospace:size=17" };
static const char dmenufont[]       = "monospace:size=17";
static const char normbordercolor[] = "#444444";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#bbbbbb";
static const char selbordercolor[]  = "#005577";
static const char selbgcolor[]      = "#005577";
static const char selfgcolor[]      = "#eeeeee";
static const ssize_t borderpx        = 3;        /* border pixel of windows Like xmonad */
static const uint32_t snap          = 32;       /* snap pixel */
static const _Bool showbar           = true;        /* 0 means no bar */
static const _Bool topbar            = true;        /* 0 means bottom bar */





/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6" };



static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	// { "Gimp",     NULL,       NULL,       0,            1,           -1 },
	// { "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
    {0}
};





/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const ssize_t nmaster     = 1;    /* number of clients in master area */
static const bool resizehints = false;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
};



#define MODKEY Mod1Mask /* key definitions */
/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } } // SLANK: c-style struct init

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", 
    "-m", dmenumon    , 
    "-fn", dmenufont  , 
    "-nb", normbgcolor, 
    "-nf", normfgcolor, 
    "-sb", selbgcolor , 
    "-sf", selfgcolor , 
    NULL };

static const char *termcmd[]    = { "urxvt"   , NULL };
static const char *browsercmd[] = { "chromium", NULL };


// SLANK: c-style struct init
static Key keys[] = {
	/* modifier                     key        function        argument */
    { MODKEY,                       XK_l,      view_right,     {0} }, // by slankdev
    { MODKEY,                       XK_h,      view_left,      {0} }, // by slankdev
    { MODKEY|ShiftMask|ControlMask, XK_l,      view_right,     {0} }, // by slankdev
    { MODKEY|ShiftMask|ControlMask, XK_h,      view_left,      {0} }, // by slankdev
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_f,      spawn,          {.v = browsercmd } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },

    { MODKEY,                       XK_1,      view,           {.ui = 1 << 0 } },
    { MODKEY,                       XK_2,      view,           {.ui = 1 << 1 } },
    { MODKEY,                       XK_3,      view,           {.ui = 1 << 2 } },
    { MODKEY,                       XK_4,      view,           {.ui = 1 << 3 } },
    { MODKEY,                       XK_5,      view,           {.ui = 1 << 4 } },
    { MODKEY,                       XK_6,      view,           {.ui = 1 << 5 } },
	{ MODKEY|ShiftMask,             XK_1,      tag,            {.ui = 1 << 0} }, 
	{ MODKEY|ShiftMask,             XK_2,      tag,            {.ui = 1 << 1} }, 
	{ MODKEY|ShiftMask,             XK_3,      tag,            {.ui = 1 << 2} }, 
	{ MODKEY|ShiftMask,             XK_4,      tag,            {.ui = 1 << 3} }, 
	{ MODKEY|ShiftMask,             XK_5,      tag,            {.ui = 1 << 4} }, 
	{ MODKEY|ShiftMask,             XK_6,      tag,            {.ui = 1 << 5} }, 
};





// SLANK: c-style struct init
/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

