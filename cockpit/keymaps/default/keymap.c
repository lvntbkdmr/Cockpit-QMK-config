/* Copyright 2022 Özkan Çelik -- (github.com/ozkan)
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include QMK_KEYBOARD_H
#include "qmk_unicode_keys.h"

enum cockpit_layer {
   _QWERTY,
   _LOWER,
   _RAISE,
   _FNL,
   _FNR,
   _ARROW,
   _ADJUST
};

enum cockpit_keycodes {
 QWERTY = SAFE_RANGE
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define FNL    MO(_FNL)
#define FNR    MO(_FNR)
#define ARROW  MO(_ARROW)
#define ADJUST MO(_ADJUST)

#define LSFT_CAPS  LSFT_T(KC_CAPS)
#define RSFT_ENT   RSFT_T(KC_ENT)

#define FNR_SPC     LT(FNR, KC_SPC)
#define FNL_ENT     LT(FNL, KC_SPC)
#define ARROW_T LT(ARROW, KC_T)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// QWERTY
// ?-----------------------------------------?                   ?-----------------------------------------?
// ¦  TAB ¦  Q   ¦  W   ¦  E   ¦  R   ¦  T   ¦                   ¦  Y   ¦  U   ¦  I   ¦  O   ¦   P  ¦ BSPC ¦
// +------+------+------+------+------+------¦                   +------+------+------+------+------+------¦
// ¦ CTRL ¦  A   ¦  S   ¦  D   ¦  F   ¦  G   ¦                   ¦  H   ¦  J   ¦  K   ¦  L   ¦ ; :  ¦ ' "  ¦
// +------+------+------+------+------+------¦                   +------+------+------+------+------+------¦
// ¦SFT_CL¦  Z   ¦  X   ¦  C   ¦  V   ¦  B   ¦                   ¦  N   ¦  M   ¦ ,  < ¦ .  > ¦  / ? ¦ ENT  ¦
// ?-----------------------------------------+-------------------+-----------------------------------------?
//                                           ¦   MPLY  ¦  MUTE   ¦
//                     ?---------------------+-------------------+--------------------?
//                     ¦  ALT ¦LOWER ¦  FNL  ¦                   ¦ FNR  ¦RAISE ¦  WIN ¦
//                     ?--------------------------------------------------------------?
//                                                 ¦  UP  ¦
//                                          ?------+------+------?
//                                          ¦ LEFT ¦ DOWN ¦ RIGHT¦
//                                          ?--------------------?

 [_QWERTY] = LAYOUT_cockpit(
   KC_TAB,      KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                 KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_BSPC,
   KC_LCTRL,    KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                 KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
   LSFT_CAPS,   KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                 KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  RSFT_ENT,
                                                 KC_MPLY,   KC_MUTE,
                KC_LALT,   LOWER,    FNL_ENT,                           FNR_SPC,   RAISE,   KC_RGUI,    
                                                        KC_UP,
                                           KC_LEFT,    KC_DOWN,  KC_RGHT

 ),
 
// LOWER 
// ?-----------------------------------------?                   ?-----------------------------------------?
// ¦ ESC  ¦      ¦      ¦      ¦      ¦      ¦                   ¦  7   ¦  8   ¦  9   ¦  -   ¦  =   ¦ DEL  ¦
// +------+------+------+------+------+------¦                   +------+------+------+------+------+------¦
// ¦      ¦      ¦      ¦      ¦      ¦      ¦                   ¦  4   ¦  5   ¦  6   ¦  *   ¦  ~   ¦  `   ¦
// +------+------+------+------+------+------¦                   +------+------+------+------+------+------¦
// ¦      ¦      ¦      ¦      ¦      ¦      ¦                   ¦  1   ¦  2   ¦  3   ¦  0   ¦  \   ¦ ENT  ¦
// ?-----------------------------------------+-------------------+-----------------------------------------?
//                                           ¦  MPRV   ¦  MNXT   ¦
//                     ?---------------------+-------------------+--------------------?
//                     ¦  ALT ¦LOWER ¦  FNL  ¦                   ¦ FNR  ¦RAISE ¦  WIN ¦
//                     ?--------------------------------------------------------------?
//                                                 ¦  UP  ¦
//                                          ?------+------+------?
//                                          ¦ LEFT ¦ DOWN ¦ RIGHT¦
//                                          ?--------------------?


 [_LOWER] = LAYOUT_cockpit(
   KC_ESC,   _______,  _______,   _______,  _______,   _______,               KC_7,  KC_8,   KC_9,   KC_MINS,  KC_EQL,  KC_DEL,
   _______,  _______,  _______,   _______,  _______,   _______,               KC_4,  KC_5,   KC_6,  KC_PAST,   S(KC_GRV),  KC_GRV,
   _______,  _______,  _______,   _______,  _______,   _______,               KC_1,  KC_2,   KC_3,  KC_0,  KC_BSLS,  KC_ENT,
                                                              KC_MPRV,   KC_MNXT,
                             KC_LALT,   LOWER,    _______,                          KC_ENT,   RAISE,   KC_RGUI,    
                                                                     KC_UP,
                                                        KC_LEFT,    KC_DOWN,  KC_RGHT

 ),

// RAISE
// ?-----------------------------------------?                   ?-----------------------------------------?
// ¦  !   ¦  @   ¦  #   ¦  $   ¦  %   ¦  ^   ¦                   ¦  &   ¦  (   ¦  )   ¦   _  ¦  +   ¦ DEL  ¦
// +------+------+------+------+------+------¦                   +------+------+------+------+------+------¦
// ¦      ¦  F1  ¦  F2  ¦  F3  ¦  F4  ¦  F5  ¦                   ¦      ¦  {   ¦  }   ¦      ¦      ¦      ¦
// +------+------+------+------+------+------¦                   +------+------+------+------+------+------¦
// ¦      ¦  F6  ¦  F7  ¦  F8  ¦  F9  ¦ F10  ¦                   ¦  F11 ¦  [   ¦  ]   ¦      ¦  |   ¦ ENT  ¦
// ?-----------------------------------------+-------------------+-----------------------------------------?
//                                           ¦  MPLY   ¦  MUTE   ¦
//                     ?---------------------+-------------------+--------------------?
//                     ¦  ALT ¦LOWER ¦  FNL  ¦                   ¦ FNR  ¦RAISE ¦  WIN ¦
//                     ?--------------------------------------------------------------?
//                                                 ¦  UP  ¦
//                                          ?------+------+------?
//                                          ¦ LEFT ¦ DOWN ¦ RIGHT¦
//                                          ?--------------------?
                 
  

 [_RAISE] = LAYOUT_cockpit(
   S(KC_1),   S(KC_2),  S(KC_3),  S(KC_4),  S(KC_5),  S(KC_6),          S(KC_7),  S(KC_9),   S(KC_0),   S(KC_MINS),   S(KC_EQL),  KC_DEL,
   _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,          _______,  S(KC_LBRC),   S(KC_RBRC),   _______,   _______,  _______,
   _______,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,             KC_F11,  KC_LBRC,  KC_RBRC,  _______,  S(KC_BSLS),  KC_ENT,
                                               KC_MPLY,   KC_MUTE,
              KC_LALT,   LOWER,    FNL_ENT,                           FNR_SPC,   RAISE,   KC_RGUI,    
                                                      KC_UP,
                                         KC_LEFT,    KC_DOWN,  KC_RGHT

 ),

// FNR 
// ?-----------------------------------------?                   ?-----------------------------------------?
// ¦ ESC  ¦      ¦      ¦  €   ¦  £   ¦      ¦                   ¦      ¦      ¦      ¦      ¦      ¦      ¦
// +------+------+------+------+------+------¦                   +------+------+------+------+------+------¦
// ¦      ¦      ¦   Ş  ¦      ¦      ¦  Ğ   ¦                   ¦      ¦      ¦      ¦      ¦      ¦      ¦
// +------+------+------+------+------+------¦                   +------+------+------+------+------+------¦
// ¦      ¦      ¦      ¦  Ç   ¦      ¦      ¦                   ¦      ¦      ¦      ¦      ¦      ¦      ¦
// ?-----------------------------------------+-------------------+-----------------------------------------?
//                                           ¦  MPLY   ¦  MUTE   ¦
//                     ?---------------------+-------------------+--------------------?
//                     ¦  ALT ¦LOWER ¦  FNL  ¦                   ¦ FNR  ¦RAISE ¦  WIN ¦
//                     ?--------------------------------------------------------------?
//                                                 ¦  UP  ¦
//                                          ?------+------+------?
//                                          ¦ LEFT ¦ DOWN ¦ RIGHT¦
//                                          ?--------------------?


 [_FNR] = LAYOUT_cockpit(
   KC_ESC,   _______,  _______,  _______,  _______,  _______,               _______,  _______,  _______,  _______,  _______,  _______,
   _______,  _______,  UK_TRS,    _______,  _______,  UK_TRG,                _______,  _______,  _______,  _______,  _______,  _______,
   _______,  _______,  _______,  UK_TRC,  _______,  _______,               _______,  _______,  _______,  _______,  _______,  _______,
                                                         KC_MPLY,   KC_MUTE,
                        KC_LALT,   LOWER,    FNL_ENT,                           FNR_SPC,   RAISE,   KC_RGUI,    
                                                                KC_UP,
                                                   KC_LEFT,    KC_DOWN,  KC_RGHT

 ),

// FNL
// ?-----------------------------------------?                   ?-----------------------------------------?
// ¦ ESC  ¦CMD+1 ¦CMD+2 ¦CMD+3 ¦CMD+4 ¦CMD+5 ¦                   ¦      ¦  Ü   ¦  ıİ  ¦   Ö  ¦      ¦ DEL  ¦
// +------+------+------+------+------+------¦                   +------+------+------+------+------+------¦
// ¦      ¦CMD+6 ¦CMD+6 ¦CMD+6 ¦CMD+9 ¦CMD+0 ¦                   ¦      ¦      ¦      ¦      ¦   :  ¦   "  ¦
// +------+------+------+------+------+------¦                   +------+------+------+------+------+------¦
// ¦      ¦      ¦      ¦      ¦      ¦      ¦                   ¦      ¦      ¦      ¦  ~   ¦   ?  ¦ ENT  ¦
// ?-----------------------------------------+-------------------+-----------------------------------------?
//                                           ¦  MPLY   ¦  MUTE   ¦
//                     ?---------------------+-------------------+--------------------?
//                     ¦  ALT ¦LOWER ¦  FNL  ¦                   ¦ FNR  ¦RAISE ¦  WIN ¦
//                     ?--------------------------------------------------------------?
//                                                 ¦  UP  ¦
//                                          ?------+------+------?
//                                          ¦ LEFT ¦ DOWN ¦ RIGHT¦
//   

 [_FNL] = LAYOUT_cockpit(
   KC_ESC,  KC_LGUI(KC_1),  KC_LGUI(KC_2),  KC_LGUI(KC_3),  KC_LGUI(KC_4),  KC_LGUI(KC_5),               _______,  UK_TRU,  UK_TRI,   UK_TRO,  _______,  KC_DEL,
   _______,  KC_LGUI(KC_6),  KC_LGUI(KC_7),  KC_LGUI(KC_8),  KC_LGUI(KC_9),  KC_LGUI(KC_0),               _______,  _______,  _______,  _______,      S(KC_SCLN),  S(KC_QUOT),
   _______,  _______,  _______,  _______,  _______,  _______,               _______,  _______,  _______,  S(KC_GRV),   S(KC_SLSH),  KC_ENT,
                                                         KC_MPLY,   KC_MUTE,
                        KC_LALT,   LOWER,    FNL_ENT,                           KC_ENT,   RAISE,   KC_RGUI,    
                                                                KC_UP,
                                                   KC_LEFT,    KC_DOWN,  KC_RGHT

 ),
 

// ARROW
// ?-----------------------------------------?                   ?-----------------------------------------?
// ¦ ESC  ¦      ¦      ¦      ¦      ¦      ¦                   ¦C_PREV¦ PGUP ¦  UP  ¦      ¦      ¦      ¦
// +------+------+------+------+------+------¦                   +------+------+------+------+------+------¦
// ¦      ¦      ¦      ¦      ¦NAV T ¦      ¦                   ¦ HOME ¦ LEFT ¦ DOWN ¦ RGHT ¦ END  ¦MPLY  ¦
// +------+------+------+------+------+------¦                   +------+------+------+------+------+------¦
// ¦      ¦      ¦      ¦      ¦      ¦      ¦                   ¦C_NEXT¦PGDOWN¦      ¦VLDOWN¦ VLUP ¦MUTE  ¦
// ?-----------------------------------------+-------------------+-----------------------------------------?
//                                           ¦  MPLY   ¦  MUTE   ¦
//                     ?---------------------+-------------------+--------------------?
//                     ¦  ALT ¦LOWER ¦  FNL  ¦                   ¦ FNR  ¦RAISE ¦  WIN ¦
//                     ?--------------------------------------------------------------?
//                                                 ¦  UP  ¦
//                                          ?------+------+------?
//                                          ¦ LEFT ¦ DOWN ¦ RIGHT¦
//                                          ?--------------------?


 [_ARROW] = LAYOUT_cockpit(
   _______,  _______,  _______,   _______,  _______,   _______,               KC_MPRV,   KC_PGUP,    KC_UP,      _______,     _______,    _______, 
   _______,  _______,  _______,   _______,  _______,   _______,               KC_HOME,   KC_LEFT,    KC_DOWN,    KC_RGHT,     KC_END,     KC_MPLY, 
   _______,  _______,  _______,   _______,  _______,   _______,               KC_MNXT,   KC_PGDOWN,  _______,    KC_VOLD,     KC_VOLU,    KC_MUTE, 
                                                             KC_MPLY,   KC_MUTE,
                            KC_LALT,   LOWER,    FNL_ENT,                           FNR_SPC,   RAISE,   KC_RGUI,    
                                                                    KC_UP,
                                                       KC_LEFT,    KC_DOWN,  KC_RGHT

 ),


// ADJUST
// ?-----------------------------------------?                   ?-----------------------------------------?
// ¦      ¦      ¦      ¦      ¦      ¦      ¦                   ¦      ¦      ¦      ¦QWERTY¦ C.HD ¦COLEMK¦
// +------+------+------+------+------+------¦                   +------+------+------+------+------+------¦
// ¦      ¦      ¦      ¦      ¦      ¦      ¦                   ¦      ¦      ¦      ¦      ¦      ¦      ¦
// +------+------+------+------+------+------¦                   +------+------+------+------+------+------¦
// ¦      ¦      ¦      ¦      ¦      ¦      ¦                   ¦ RESET¦      ¦      ¦      ¦      ¦      ¦
// ?-----------------------------------------+-------------------+-----------------------------------------?
//                                           ¦  MPLY   ¦  MUTE   ¦
//                     ?---------------------+-------------------+--------------------?
//                     ¦  ALT ¦LOWER ¦  FNL  ¦                   ¦ FNR  ¦RAISE ¦  WIN ¦
//                     ?--------------------------------------------------------------?
//                                                 ¦  UP  ¦
//                                          ?------+------+------?
//                                          ¦ LEFT ¦ DOWN ¦ RIGHT¦
//                                          ?--------------------?


 [_ADJUST] = LAYOUT_cockpit(
   RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,                  UC_MAC,  US_LNX,  UC_WINC,  QWERTY,   XXXXXXX,   XXXXXXX,
   RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,                  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,
   XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,             RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,
                                                              KC_MPLY,   KC_MUTE,
                             KC_LALT,   LOWER,    FNL_ENT,                           FNR_SPC,   RAISE,   KC_RGUI,    
                                                                     KC_UP,
                                                        KC_LEFT,    KC_DOWN,  KC_RGHT

 ),
};




layer_state_t layer_state_set_user(layer_state_t state) {
 return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
   if (index == 0) { /* First encoder: Right encoder */
       if (clockwise) {
           tap_code_delay(KC_VOLU, 10);
       } else {
           tap_code_delay(KC_VOLD, 10);
       }
   } else if (index == 1) { /* Second encoder: Left encoder */
       if (IS_LAYER_ON(_LOWER)) { 
             if (clockwise) {
                 tap_code(KC_BRIU);
             } else {
                 tap_code(KC_BRID);
             }
       } else {
             if (clockwise) {
                 tap_code(KC_PGUP);
             } else {
                 tap_code(KC_PGDN);
             }
       }
   }
   return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
 switch (keycode) {
   case QWERTY:
     if (record->event.pressed) {
       set_single_persistent_default_layer(_QWERTY);
     }
     return false;
     break;
 }
 return true;
}
