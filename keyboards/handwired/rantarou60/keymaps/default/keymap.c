#include "rantarou60.h"
#include "led.h"

#define _QWERTY 0
#define _FN1 1
#define _FN2 2
#define KC_ KC_TRNS
#define KC_X0 MO(_FN2)
#define KC_X1 MO(_FN1)

enum keyboard_macros {
    MACRO_BACKLIT,
    MACRO_BREATH_TOGGLE,
    MACRO_BREATH_SPEED_INC,
    MACRO_BREATH_SPEED_DEC,
    MACRO_BREATH_DEFAULT
};

// Func macro definitions.
#define KC_LED  FUNC(0)
//#define KC_LEDB M(MACRO_BACKLIT)
#define KC_LEDI FUNC(1)
#define KC_LEDD FUNC(2)
#define KC_BRT  M(MACRO_BREATH_TOGGLE)
#define KC_BRTI M(MACRO_BREATH_SPEED_INC)
#define KC_BRTD M(MACRO_BREATH_SPEED_DEC)
#define KC_BRTR M(MACRO_BREATH_DEFAULT)

// Enable these functions using FUNC(n) macro.
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_BACKLIGHT_TOGGLE(),
    [1] = ACTION_BACKLIGHT_INCREASE(),
    [2] = ACTION_BACKLIGHT_DECREASE()
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = KEYMAP(
 /*,----+----+----+----+----+----+----+----+----+----+----+----+----+--------. */
    GESC, 1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 0  ,MINS,EQL ,  BSPC  ,
 /*|----`----`----`----`----`----`----`----`----`----`----`----`----`--------| */
    TAB   , Q  , W  , E  , R  , T  , Y  , U  , I  , O  , P  ,LBRC,RBRC, BSLS ,
 /*|------`----`----`----`----`----`----`----`----`----`----`----`----`------| */
    CAPS   , A  , S  , D  , F  , G  , H  , J  , K  , L  ,SCLN,QUOT,    ENTER ,
 /*|-------`----`----`----`----`----`----`----`----`----`----`----`----------| */
    LSFT     , Z  , X  , C  , V  , B  , N  , M  ,COMM,DOT ,SLSH,       RSFT  ,
 /*|---------`----`----`----`----`----`----`----`----`----`----`-------------| */
    LCTL ,LGUI ,LALT ,            SPACE             ,RALT  ,X1   ,X0   ,RCTL
 /*`-----+-----+-----+------------------------------+------+-----+-----'-----' */
  ),

  [_FN1] = KEYMAP(
 /*,----+----+----+----+----+----+----+----+----+----+----+----+----+--------. */
    GRV , F1 , F2 , F3 , F4 , F5 , F6 , F7 , F8 , F9 ,F10 ,F11 ,F12 ,   DEL  ,
 /*|esc-`-1--`-2--`-3--`-4--`-5--`-6--`-7--`-8--`-9--`-0--`mnus`plus`--bksp--| */
          ,PGUP, UP ,PGDN,    ,    ,    ,    ,    ,    ,PSCR,    ,    ,      ,
 /*|tab---`-q--`-w--`-e--`-r--`-t--`-y--`-u--`-i--`-o--`-p--`-{--`-}--`--|---| */
           ,LEFT,DOWN,RGHT,    ,    ,HOME,    ,    ,    ,    ,    ,          ,
 /*|caps---`-a--`-s--`-d--`-f--`-g--`-h--`-j--`-k--`-l--`-;--`-'--`----enter-| */
             ,INS ,DEL ,    ,    ,    ,END ,MUTE,VOLD,VOLU,    ,             ,
 /*|shift----`-z--`-x--`-c--`-v--`-b--`-n--`-m--`-,--`-.--`-/--`-------shift-| */
         ,     ,     ,                              ,      ,     ,     ,
 /*`ctrl-+-gui-+-alt-+----------space---------------+-alt--+-fn1-+-fn2-'ctrl-' */
  ),

  [_FN2] = KEYMAP(
 /*,----+----+----+----+----+----+----+----+----+----+----+----+----+--------. */
        ,LED ,LEDI,LEDD,BRT ,BRTI,BRTD,BRTR,    ,    ,    ,    ,    ,        ,
 /*|esc-`-1--`-2--`-3--`-4--`-5--`-6--`-7--`-8--`-9--`-0--`mnus`plus`--bksp--| */
          ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,      ,
 /*|tab---`-q--`-w--`-e--`-r--`-t--`-y--`-u--`-i--`-o--`-p--`-{--`-}--`--|---| */
           ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,          ,
 /*|caps---`-a--`-s--`-d--`-f--`-g--`-h--`-j--`-k--`-l--`-;--`-'--`----enter-| */
             ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,             ,
 /*|shift----`-z--`-x--`-c--`-v--`-b--`-n--`-m--`-,--`-.--`-/--`-------shift-| */
         ,     ,     ,                              ,      ,     ,     ,
 /*`ctrl-+-gui-+-alt-+----------space---------------+-alt--+-fn1-+-fn2-'ctrl-' */
  )
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
//        case 0:
//          if (record->event.pressed) {
//            register_code(KC_RSFT);
//          } else {
//            unregister_code(KC_RSFT);
//          }
//        break;

        case MACRO_BREATH_TOGGLE:
          if (record->event.pressed) {
              breathing_toggle();
          }
        break;

        case MACRO_BREATH_SPEED_INC:
          if (record->event.pressed) {
              breathing_speed_inc(1);
          }
        break;

        case MACRO_BREATH_SPEED_DEC:
          if (record->event.pressed) {
              breathing_speed_dec(1);
          }
        break;

        case MACRO_BREATH_DEFAULT:
          if (record->event.pressed) {
              breathing_defaults();
          }
        break;

        case MACRO_BACKLIT:
          if (record->event.pressed) {
              backlight_step();
          }
        break;
      }
    return MACRO_NONE;
};
