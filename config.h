/* see LICENSE for copyright and license */

#ifndef CONFIG_H
#define CONFIG_H

#include <X11/XF86keysym.h>

/** buttons **/
#define ALTKEY            Mod1Mask    /* ALT key */
#define SUPERKEY          Mod4Mask    /* Super/Windows key */
#define CONTROL           ControlMask /* Control key */
#define SHIFT             ShiftMask   /* Shift key */

/** generic settings **/
#define MASTER_SIZE     0.50
#define SHOW_PANEL      True      /* show panel by default on exec */
#define TOP_PANEL       True      /* False mean panel is on bottom */
#define PANEL_HEIGHT    15        /* 0 for no space for panel, thus no panel */
#define DEFAULT_MODE    TILE      /* TILE MONOCLE BSTACK GRID */
#define ATTACH_ASIDE    True      /* False means new window is master */
#define FOLLOW_MOUSE    False     /* Focus the window the mouse just entered */
#define FOLLOW_WINDOW   False     /* Follow the window when moved to a different desktop */
#define CLICK_TO_FOCUS  False     /* Focus an unfocused window when clicked */
#define BORDER_WIDTH    2         /* window border width */
#define FOCUS           "#268bd2" /* focused window border color   */
#define UNFOCUS         "#073642" /* unfocused window border color */
#define DESKTOPS        8         /* number of desktops - edit DESKTOPCHANGE keys to suit */
#define DEFAULT_DESKTOP 0         /* the desktop to focus on exec */
#define MINWSZ          50        /* minimum window size in pixels */

#define FOCUS_BUTTON    Button3

/* open applications to specified desktop with specified mode.
 * if desktop is negative, then current is assumed */
static const AppRule rules[0];
    /*  class     desktop  follow  float */

/* helper for spawning shell commands */
#define SHCMD(cmd) {.com = (const char*[]){"/bin/sh", "-c", cmd, NULL}}

/** commands **/
static const char *urxvt[]           = { "urxvt", NULL};
static const char *dmenu[]           = { "/home/skqf/.bin/my_dmenu", NULL};
static const char *telega[]          = { "/usr/bin/telegram-desktop", NULL};
static const char *browser[]         = { "/usr/bin/qutebrowser", NULL};
static const char *discord[]         = { "/usr/bin/discord", NULL};
static const char *dunst_mute[]      = { "dunstctl", "set-paused", "toggle"};
static const char *dunst_clear[]     = { "dunstctl", "close-all"};
static const char *screen_full[]     = { "/home/skqf/.bin/screen_full", NULL};
static const char *screen_area[]     = { "/home/skqf/.bin/screen_area", NULL};
static const char *screen_save[]     = { "/home/skqf/.bin/screen_save", NULL};
static const char *volume_increase[] = { "/usr/bin/pamixer", "-i", "5"};
static const char *volume_decrease[] = { "/usr/bin/pamixer", "-d", "5"};
static const char *volume_mute[]     = { "/usr/bin/pamixer", "-t"};

#define DESKTOPCHANGE(K,N) \
    {  ALTKEY,             K,              change_desktop, {.i = N}}, \
    {  ALTKEY|ShiftMask,   K,              client_to_desktop, {.i = N}},

/** Shortcuts **/
static Key keys[] = {
    /* modifier          key            function           argument */
    {  ALTKEY,             XK_b,          togglepanel,       {NULL}},
    {  ALTKEY,             XK_BackSpace,  focusurgent,       {NULL}},
    {  ALTKEY,             XK_0,          killclient,        {NULL}},
    {  ALTKEY,             XK_j,          next_win,          {NULL}},
    {  ALTKEY,             XK_k,          prev_win,          {NULL}},
    {  ALTKEY,             XK_h,          resize_master,     {.i = -20}}, /* decrease size in px */
    {  ALTKEY,             XK_l,          resize_master,     {.i = +20}}, /* increase size in px */
    {  ALTKEY,             XK_o,          resize_stack,      {.i = -10}}, /* shrink   size in px */
    {  ALTKEY,             XK_p,          resize_stack,      {.i = +10}}, /* grow     size in px */
    {  ALTKEY|CONTROL,     XK_h,          rotate,            {.i = -1}},
    {  ALTKEY|CONTROL,     XK_l,          rotate,            {.i = +1}},
    {  ALTKEY|SHIFT,       XK_h,          rotate_filled,     {.i = -1}},
    {  ALTKEY|SHIFT,       XK_l,          rotate_filled,     {.i = +1}},
    {  ALTKEY,             XK_Tab,        last_desktop,      {NULL}},
    {  ALTKEY,             XK_Return,     swap_master,       {NULL}},
    {  ALTKEY|SHIFT,       XK_j,          move_down,         {NULL}},
    {  ALTKEY|SHIFT,       XK_k,          move_up,           {NULL}},
    {  ALTKEY|SHIFT,       XK_t,          switch_mode,       {.i = TILE}},
    {  ALTKEY|SHIFT,       XK_m,          switch_mode,       {.i = MONOCLE}},
    {  ALTKEY|SHIFT,       XK_b,          switch_mode,       {.i = BSTACK}},
    {  ALTKEY|SHIFT,       XK_g,          switch_mode,       {.i = GRID}},
    {  ALTKEY|SHIFT,       XK_f,          switch_mode,       {.i = FLOAT}},
    {  ALTKEY|CONTROL,     XK_F11,        quit,              {.i = 0}}, /* quit with exit value 0 */
    {  ALTKEY|CONTROL,     XK_F12,        quit,              {.i = 1}}, /* quit with exit value 1 */

    {  SUPERKEY,             XK_Return,     spawn,             {.com = urxvt}},
    {  SUPERKEY,             XK_f,          spawn,             {.com = browser}},
    {  SUPERKEY,             XK_t,          spawn,             {.com = telega}},
    {  SUPERKEY,             XK_d,          spawn,             {.com = discord}},
    {  SUPERKEY,             XK_p,          spawn,             {.com = dmenu}},

    {  ALTKEY|SHIFT,         XK_c,          spawn,             {.com = dunst_clear}},
    {  ALTKEY|SHIFT,         XK_q,          spawn,             {.com = dunst_mute}},

    {  0,                    XK_Print,      spawn,             {.com = screen_full}},
    {  CONTROL,              XK_Print,      spawn,             {.com = screen_area}},
    {  CONTROL|SHIFT,        XK_Print,      spawn,             {.com = screen_save}},

    {  0,                    XF86XK_AudioLowerVolume,      spawn,             {.com = volume_decrease}},
    {  0,                    XF86XK_AudioRaiseVolume,      spawn,             {.com = volume_increase}},
    {  0,                    XF86XK_AudioMute,             spawn,             {.com = volume_mute}},


       DESKTOPCHANGE(    XK_1,                             0)
       DESKTOPCHANGE(    XK_2,                             1)
       DESKTOPCHANGE(    XK_3,                             2)
       DESKTOPCHANGE(    XK_4,                             3)
       DESKTOPCHANGE(    XK_5,                             4)
       DESKTOPCHANGE(    XK_6,                             5)
       DESKTOPCHANGE(    XK_7,                             6)
       DESKTOPCHANGE(    XK_8,                             7)
};

static Button buttons[] = {
    {  ALTKEY,    Button1,     mousemotion,   {.i = MOVE}},
    {  ALTKEY,    Button3,     mousemotion,   {.i = RESIZE}},
};
#endif
