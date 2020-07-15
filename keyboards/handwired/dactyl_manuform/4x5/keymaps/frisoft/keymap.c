#include QMK_KEYBOARD_H


#define _BASE 0
#define _NAV 1
// #define _RAISE2 2
// #define _RAISE3 3
#define _NUMPAD 4  
#define _SYM 5  

// Fillers to make layering more clear

#define ____ KC_TRNS
#define XXXX KC_NO

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

// #define SFT_F  SFT_T(KC_F)
// #define SFT_J  SFT_T(KC_J)
// #define CTL_D  CTL_T(KC_D)
// #define CTL_K  SFT_T(KC_K)
// #define ALT_S  ALT_T(KC_S)
// #define ALT_L  ALT_T(KC_L)

// #define SFT_4  SFT_T(KC_4)
// #define SFT_7  SFT_T(KC_7)
// #define CTL_3  CTL_T(KC_3)
// #define CTL_8  SFT_T(KC_8)
// #define ALT_2  ALT_T(KC_2)
// #define ALT_9  ALT_T(KC_9)

#define SFT_Z     SFT_T(KC_Z)
#define SFT_QUOT  SFT_T(KC_QUOT)

#define CTL_A     CTL_T(KC_A)
#define CTL_SCLN  CTL_T(KC_SCLN)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2
// #define RAISE1 MO(_NAV)
// #define RAISE2 LM(_RAISE2, MOD_LGUI)
// #define RAISE2 MO(_RAISE2)
#define RAISE3 MO(_RAISE3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * ,----------------------------------,                             ,----------------------------------,
 * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |      |   s  |   d  |   f  |      |                             |      |   j  |   k  |   l  |      |
 * |   a  |   +  |   +  |   +  |   g  |                             |   h  |   +  |   +  |   +  |  ;:  |
 * |      |  ALT | CTRL | SHIFT|      |                             |      |SHIFT | CTRL |  ALT |      |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |  ,<  |  .>  |  '"  |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |  [{  |  ]}  |                                                         |  -_  |  =+  |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      | ESC  |  BS  |                             | SPACE|ENTER |
 *                      |  +   |   +  |                             |  +   |  +   |
 *                      | SHIFT| CTRL |                             | ALT  |SHIFT |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    | TAB  | HOME | | END  | DEL  |
 *                                    '------+------' '------+------'
 *                                    | Raise|  ~   | | GUI  | Lower|
 *                                    '------+------' '------+------' */

/*
[_BASE] = LAYOUT( \
  KC_Q,        KC_W,        KC_E,        KC_R,         KC_T,                                       KC_Y, KC_U,         KC_I,           KC_O,          KC_P,      \
  KC_A,        KC_S,        KC_D,        KC_F,         KC_G,                                       KC_H, KC_J,         KC_K,           KC_L,          KC_SCLN,  \
  KC_Z,        KC_X,        KC_C,        KC_V,         KC_B,                                       KC_N, KC_M,         KC_COMM,        KC_DOT,        KC_QUOT, \
               KC_LBRC,     KC_RBRC,                                                                                   KC_MINS,        KC_EQL,            \
                                                           SFT_ESC, CTL_BSPC,    ALT_SPC, SFT_ENT,                                             \
                                                           KC_TAB,  RAISE,       LOWER,   KC_DEL,                                              \
                                                           KC_HOME, KC_GRV,      KC_LGUI, KC_END
),
*/

[_BASE] = LAYOUT( \
  KC_Q,        KC_W,          KC_E,             KC_R,          KC_T,                              KC_Y, KC_U,         KC_I,           KC_O,           KC_P,    \
  KC_A,        LT(_SYM,KC_S), LT(_NUMPAD,KC_D), LT(_NAV,KC_F), KC_G,                              KC_H, KC_J,         KC_K,           KC_L,           LT(_NAV,KC_SCLN), \
  SFT_T(KC_Z), KC_X,          KC_C,             KC_V,          KC_B,                              KC_N, KC_M,         KC_COMM,        KC_DOT,         SFT_T(KC_QUOT), \
               KC_LBRC,       KC_RBRC,                                                                                KC_MINS,        KC_EQL,                \
                                                        KC_ESC, KC_BSPC,                           KC_SPC, KC_ENT,                                  \
                                                 OSM(MOD_LCTL), OSM(MOD_LSFT),              OSM(MOD_RSFT), OSM(MOD_RCTL),                                  \
                                                 OSM(MOD_LALT), GUI_T(KC_TAB),              OSM(MOD_LGUI), OSM(MOD_LALT)
),

[_NAV] = LAYOUT( \
  RESET,   ____,    ____,    ____,    ____,                          LALT(KC_LEFT), KC_PGDOWN, KC_PGUP, LALT(KC_RIGHT), ____, \
  ____,    ____,    ____,    ____,    ____,                          KC_LEFT,       KC_DOWN,   KC_UP,   KC_RIGHT,       ____, \
  ____,    ____,    ____,    ____,    ____,                          KC_GRV,        KC_BSLS,   KC_SLSH, KC_QUES,        KC_PIPE, \
           ____,    ____,                                                                       ____,       ____,             \
                                            ____, ____,  ____, ____,                                                          \
                                            ____, ____,  ____, ____,                                                          \
                                            ____, ____,  ____, ____                                                           \
),

[_NUMPAD] = LAYOUT( \
  ____,    ____,    ____,    ____,    ____,                          ____,   KC_7,   KC_8,   KC_9,   ____, \
  ____,    ____,    ____,    ____,    ____,                          ____,   KC_4,   KC_5,   KC_6,   ____, \
  ____,    ____,    ____,    ____,    ____,                          ____,   KC_1,   KC_2,   KC_3,   ____, \
           ____,    ____,                                                            KC_0,   KC_DOT,             \
                                            ____, ____,  ____, ____,                                                          \
                                            ____, ____,  ____, ____,                                                          \
                                            ____, ____,  ____, ____                                                           \
),

[_SYM] = LAYOUT( \
  ____,    ____,    ____,    ____,    ____,                          ____,   KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, \
  ____,    ____,    ____,    ____,    ____,                          ____,   KC_DLR,   KC_PERC, KC_CIRC, ____, \
  ____,    ____,    ____,    ____,    ____,                          ____,   KC_EXLM,  KC_AT,   KC_HASH, ____, \
           ____,    ____,                                                              KC_RPRN, ____,             \
                                            ____, ____,  ____, ____,                                                          \
                                            ____, ____,  ____, ____,                                                          \
                                            ____, ____,  ____, ____                                                           \
),

/*
[_RAISE2] = LAYOUT( \
  KC_EXLM,      KC_AT,         KC_HASH,      KC_DLR,       KC_PERC,                          KC_CIRC, KC_AMPR,      KC_ASTR,      KC_LPRN,       KC_RPRN,       \
  KC_1,         KC_2,          KC_3,         KC_4,         KC_5,                             KC_6,    KC_7,         KC_8,         KC_9,          KC_0,          \
  XXXX,         XXXX,          XXXX,         XXXX,         KC_TILDE,                         KC_GRV,  KC_BSLS,      KC_SLSH,      KC_QUES,       KC_PIPE,       \
                KC_F11,        KC_F12,                                                                              ____,         ____,                         \
                                                                    ____, ____,  ____, ____,                                                                    \
                                                                    ____, ____,  ____, ____,                                                                    \
                                                                    ____, ____,  ____, ____                                                                     \
),
*/

/*
[_RAISE3] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,    KC_F9,  KC_F10, \
  ____,    ____,    ____,    ____,    ____,                             ____,    ____,    ____,     KC_F11, KC_F12, \
  ____,    ____,    ____,    ____,    ____,                             ____,    ____,    ____,     ____,   ____,   \
           ____,    ____,                                                                 ____,     ____,           \
                                              ____, ____,  ____, ____,                                              \
                                              ____, ____,  ____, ____,                                              \
                                              ____, ____,  ____, ____                                               \
)
*/

/* Raise (OLD)
 * ,----------------------------------,                             ,----------------------------------,
 * |RESET |      |  mup |      |      |                             | VOL+ |      |  up  |      | PgUp |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |      | mleft| mdown|mright|      |                             | MUTE | left | down |right | PgDn |
 */

/* Raise
 * ,----------------------------------,                             ,----------------------------------,
 * |RESET |      |      |      |      |                             | VOL+ |      |  up  |      | PgUp |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |      | ALT  | CRTL |SHIFT |      |                             | MUTE | left | down |right | PgDn |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      |      |      |      |      |                             | VOL- |  /   |  \   |  ?   |  |   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |      |                                                         | mbtn |mbtn2 |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */

/*
[_RAISE] = LAYOUT( \
  ____, ____,  KC_MU, ____,  ____,                          KC_VOLU, ____,    KC_UP,   ____,     KC_PGUP,   \
  ____, KC_ML, KC_MD, KC_MR, ____,                          KC_MUTE, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDOWN, \
  ____, ____,  ____,  ____,  ____,                          KC_VOLD, KC_SLSH, KC_BSLS, KC_QUES,  KC_PIPE,   \
           ____,    ____,                                                     KC_MB1,  KC_MB2,              \
                                            ____, ____,  ____, ____,                                                 \
                                            ____, ____,  ____, ____,                                                 \
                                            ____, ____,  ____, ____                                                  \
),
*/



/* Raise2
 * ,-------------------------------------,                             ,-------------------------------------,
 * |  F1  |  F2   |  F3   |  F4   |  F5  |                             |  F6  |  F7   |  F8   |  F9   |  F10 |
 * |------+-------+-------+-------+------|                             |--------------+-------+-------+------|
 * |      |   2   |   3   |   4   |      |                             |      |   7   |   8   |   9   |      |
 * |  1   |   +   |   +   |   +   |  5   |                             |  6   |   +   |   +   |   +   |  0   |
 * |      |  ALT  | CTRL  | SHIFT |      |                             |      | SHIFT | CTRL  |  ALT  |      |
 * |------+-------+-------+-------+------|                             |------|-------+-------+-------+------|
 * |  !   |   @   |   #   |   $   |  %   |                             |  ^   |   &   |   *   |    (  |  )   |
 * |------+-------+-------+--------------,                             ,--------------+-------+-------+------,
 *        |  F11  |  F12  |                                                           |   -   |   =   |
 *        '-------+-------'--------------'                             '--------------'-------+-------'
 *                        |       |      |                             |      |       |
 *                        |    KC_LGUI   |      |                             |      |       |
 *                        |       |      |                             |      |       |
 *                        '-------+------'                             '------+-------'
 *                                       '------+------' '------+------'
 *                                       |      |      | |      |      |
 *                                       '------+------' '------+------'
 *                                       |      |      | |      |      |
 *                                       '------+------' '------+------'
 */ 


/*
[_LOWER] = LAYOUT( \
  KC_F1,          KC_F2,         KC_F3,          KC_F4,          KC_F5,                            KC_F6,   KC_F7,            KC_F8,          KC_F9,          KC_F10,         \
  KC_1,           KC_2,          KC_3,           KC_4,           KC_5,                             KC_6,    KC_7,             KC_8,           KC_9,           KC_0,           \
  SFT_T(KC_EXLM), CTL_T(KC_AT),  ALT_T(KC_HASH), LGUI_T(KC_DLR), KC_PERC,                          KC_CIRC, LGUI_T(KC_AMPR),  ALT_T(KC_ASTR), CTL_T(KC_LPRN), SFT_T(KC_RPRN), \
                  KC_F11,        KC_F12,                                                                                      ____,           ____,                           \
                                                                          ____, ____,  ____, ____,                                                                            \
                                                                          ____, ____,  ____, ____,                                                                            \
                                                                          ____, ____,  ____, ____                                                                             \
)
*/


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


/* combos */
enum combos {
  YU_BSPC
  // TI_TICK,
  // SL_SLASH,
  // HA_HASH,
  // PI_PIPE
};

const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
// const uint16_t PROGMEM ti_combo[] = {KC_T, KC_I, COMBO_END};
// const uint16_t PROGMEM sl_combo[] = {KC_S, KC_L, COMBO_END};
// const uint16_t PROGMEM ha_combo[] = {KC_H, KC_A, COMBO_END};
// const uint16_t PROGMEM pi_combo[] = {KC_P, KC_I, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [YU_BSPC] = COMBO(yu_combo, KC_BSPC),
  // [TI_TICK] = COMBO(ti_combo, KC_GRV),
  // [SL_SLASH] = COMBO(sl_combo, KC_SLSH),
  // [HA_HASH] = COMBO(ha_combo, KC_HASH),
  // [PI_PIPE] = COMBO(pi_combo, KC_PIPE)
};
