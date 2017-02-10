/* See LICENSE file for copyright and license details. */
#include <stdint.h>
#include <stdbool.h>


#define MY_STATUS \
    sprintf(stext, "dwm-%s",   \
        VERSION                          \
        );


/* appearance */
static const char *fonts[]          = { "monospace:size=11" };
static const char dmenufont[]       = "monospace:size=11";
static const char normbordercolor[] = "#444444";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#bbbbbb";
static const char selbordercolor[]  = "#005577";
static const char selbgcolor[]      = "#005577";
static const char selfgcolor[]      = "#eeeeee";
static const size_t borderpx        = 3;        /* border pixel of windows Like xmonad */
static const uint32_t snap          = 32;       /* snap pixel */
static const bool showbar           = true;        /* 0 means no bar */
static const bool topbar            = true;        /* 0 means bottom bar */


/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6" };


static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	// { "Gimp",     NULL,       NULL,       0,            1,           -1 },
	// { "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
    {"webbrowser", NULL, NULL, 1 << 8, 1, -1},
    {0, NULL, NULL, 0, 0, 0}
};


/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const size_t nmaster     = 1;    /* number of clients in master area */
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


static Key keys[] = {
	/* modifier                     key        function        argument */
    { MODKEY,                       XK_l,      slankdev_view_right,     {0} },
    { MODKEY,                       XK_h,      slankdev_view_left,      {0} },
    { MODKEY|ShiftMask|ControlMask, XK_l,      slankdev_view_right,     {0} },
    { MODKEY|ShiftMask|ControlMask, XK_h,      slankdev_view_left,      {0} },
	{ MODKEY,                       XK_p,      spawn,          Arg::set_v(dmenucmd) },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          Arg::set_v(termcmd) },
	{ MODKEY,                       XK_f,      spawn,          Arg::set_v(browsercmd) },
	{ MODKEY,                       XK_j,      focusstack,     Arg::set_i(+1) },
	{ MODKEY,                       XK_k,      focusstack,     Arg::set_i(-1) },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_h,      setmfact,       Arg::set_f(-0.05) },
	{ MODKEY|ShiftMask,             XK_l,      setmfact,       Arg::set_f(0.05) },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_j,      slankdev_movestack,      Arg::set_i(+1) },
	{ MODKEY|ShiftMask,             XK_k,      slankdev_movestack,      Arg::set_i(-1) },

    { MODKEY,                       XK_1,      view,           Arg::set_ui(1 << 0) },
    { MODKEY,                       XK_2,      view,           Arg::set_ui(1 << 1) },
    { MODKEY,                       XK_3,      view,           Arg::set_ui(1 << 2) },
    { MODKEY,                       XK_4,      view,           Arg::set_ui(1 << 3) },
    { MODKEY,                       XK_5,      view,           Arg::set_ui(1 << 4) },
    { MODKEY,                       XK_6,      view,           Arg::set_ui(1 << 5) },
	{ MODKEY|ShiftMask,             XK_1,      tag,            Arg::set_ui(1 << 0) },
	{ MODKEY|ShiftMask,             XK_2,      tag,            Arg::set_ui(1 << 1) },
	{ MODKEY|ShiftMask,             XK_3,      tag,            Arg::set_ui(1 << 2) },
	{ MODKEY|ShiftMask,             XK_4,      tag,            Arg::set_ui(1 << 3) },
	{ MODKEY|ShiftMask,             XK_5,      tag,            Arg::set_ui(1 << 4) },
	{ MODKEY|ShiftMask,             XK_6,      tag,            Arg::set_ui(1 << 5) },
};


/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      Arg::set_v(&layouts[2]) },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          Arg::set_v(termcmd) },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
