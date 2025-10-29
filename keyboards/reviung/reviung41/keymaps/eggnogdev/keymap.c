/* Copyright 2020 gtips
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

enum layer_names {
    _DVORAK,
    _QWERTY,
    _MOUSE,
    _LOWER,
    _RAISE,
    _ADJUST
};

// TODO: implement new symbol and number layer
// TODO: make lctl tap/hold with esc
// TODO: make lshft tap/hold with capslock
// TODO: make rgui tap/hold with layer change (probably for _ADJUST)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT(
    KC_TAB,   KC_QUOT,  KC_COMM,  KC_DOT,  KC_P,     KC_Y,                 KC_F,        KC_G,     KC_C,  KC_R,  KC_L,  KC_BSPC,
    KC_LSFT,  KC_A,     KC_O,     KC_E,    KC_U,     KC_I,                 KC_D,        KC_H,     KC_T,  KC_N,  KC_S,  KC_MINUS,
    KC_LCTL,  KC_SCLN,  KC_Q,     KC_J,    KC_K,     KC_X,                 KC_B,        KC_M,     KC_W,  KC_V,  KC_Z,  RSFT_T(KC_ENT),
                                           KC_LALT,  MO(_LOWER),  KC_SPC,  MO(_RAISE),  KC_RGUI
  ),

  [_QWERTY] = LAYOUT(
    KC_TAB,   KC_Q,  KC_W,  KC_E,  KC_R,     KC_T,                 KC_Y,        KC_U,     KC_I,     KC_O,    KC_P,     KC_BSPC,
    KC_LSFT,  KC_A,  KC_S,  KC_D,  KC_F,     KC_G,                 KC_H,        KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
    KC_LCTL,  KC_Z,  KC_X,  KC_C,  KC_V,     KC_B,                 KC_N,        KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  RSFT_T(KC_ENT),
                                   KC_LALT,  MO(_LOWER),  KC_SPC,  MO(_RAISE),  KC_RGUI
  ),

  [_MOUSE] = LAYOUT(
    KC_TAB,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                 XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  MS_BTN2,  MS_BTN1,  XXXXXXX,                 MS_LEFT,     MS_DOWN,  MS_UP,    MS_RGHT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  MS_BTN5,  MS_BTN4,  XXXXXXX,                 MS_WHLL,     MS_WHLD,  MS_WHLU,  MS_WHLR,  XXXXXXX,  XXXXXXX,
                                            KC_LALT,  MO(_LOWER),  XXXXXXX,    MO(_RAISE),  KC_RGUI
  ),
  
  [_LOWER] = LAYOUT(
    KC_ESC,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,           KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    _______,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE,           KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_GRV,   KC_TILD,
    _______,  KC_LALT,  KC_LGUI,  KC_CAPS,  KC_QUES,  KC_DQUO,           KC_HOME,  KC_PGDN,  KC_PGUP,  KC_PSCR,  KC_END,   RSFT_T(KC_SPC),
                                            _______,  _______,  KC_ENT,  _______,  _______
  ),
  
  [_RAISE] = LAYOUT(
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                     KC_6,     KC_7,   KC_8,     KC_9,     KC_0,     KC_DEL,
    _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,                  KC_F1,    KC_F2,  KC_F3,    KC_F4,    KC_F5,    KC_F6,
    _______,  KC_RALT,  KC_RGUI,  KC_CAPS,  KC_SLSH,  KC_QUOT,                  KC_F7,    KC_F8,  KC_F9,    KC_F10,   KC_F11,   KC_F12,
                                            _______,  _______,  LCTL(KC_BSPC),  _______,  _______
  ),
  
  [_ADJUST] = LAYOUT(
    UG_VALU,  UG_SATU,  UG_HUEU,  UG_NEXT,  XXXXXXX,  UG_TOGG,            XXXXXXX,  DF(_DVORAK),  DF(_QWERTY),  DF(_MOUSE),  XXXXXXX,  XXXXXXX,
    UG_VALD,  UG_SATD,  UG_HUED,  UG_PREV,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,      XXXXXXX,      XXXXXXX,     XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            QK_BOOT,  XXXXXXX,      XXXXXXX,      XXXXXXX,     XXXXXXX,  XXXXXXX,
                                            _______,  _______,  XXXXXXX,  _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

