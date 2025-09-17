/* Copyright 2022 Ryan Anderson <ryan@michonline.com>
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

/* layer constants */
enum {
    DEF = 0,
    FUN,
};

enum custom_keycode {
    MACRO_CTRL_PAGE_UP = SAFE_RANGE,
    MACRO_KVM_1,
    MACRO_KVM_2,
    MACRO_KVM_3,
    MACRO_KVM_4,
    MACRO_KVM_TG,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[DEF] = LAYOUT(
  QK_BOOT  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , MACRO_CTRL_PAGE_UP,
  KC_GRV , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , RM_NEXT,    MACRO_KVM_TG, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_EQL ,
  LCTL_T(KC_PGUP), KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_TAB ,    KC_ENT , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
  KC_PGDN, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_ESC ,    KC_RALT, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_MINS,
                                          SC_LCPO,                                       SC_RCPC,
                                            KC_BSPC,                                     KC_SPC,
                                              SC_LAPO,                                 SC_RAPC,
                                                SC_LSPO,                              SC_RSPC,
                                                   MO(FUN),                         MO(FUN)
  ),
[FUN] = LAYOUT(
  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
  KC_TAB , _______, MS_UP, MS_WHLU, MS_BTN3, MACRO_KVM_1, RM_TOGG,     KC_MPRV, KC_MNXT, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_F12 ,
  KC_HOME, MS_LEFT, MS_DOWN, MS_RGHT, MS_BTN1, MACRO_KVM_2, RM_SPDU,    KC_MPLY, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
  KC_END , KC_PSCR, KC_INS , MS_WHLD, MS_BTN2, MACRO_KVM_4, RM_SPDD,    MACRO_KVM_3, KC_MUTE, KC_VOLD, KC_VOLU, KC_PAUS, KC_BSLS, KC_PIPE,
                                         _______,                                 _______,
                                            KC_DEL ,                           KC_ENT ,
                                               KC_LGUI,                     _______,
                                                  _______,               _______,
                                      _______,                                        _______
  )
};

/* template for new layouts:
LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                         _______,                                 _______,
                                            _______,                           _______,
                                               _______,                     _______,
                                                  _______,               _______,
                                      _______,                                        _______
  )
*/
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO_CTRL_PAGE_UP:
            if (record->event.pressed) {
                // send some data
                SEND_STRING(SS_LCTL(SS_TAP(X_PGUP)));
            } else {
                // when keycode MACRO_CTRL_PAGE_UP is pressed
            }
            break;
        case MACRO_KVM_1:
            if (record->event.pressed) {
                tap_code(KC_SCRL);
                tap_code(KC_SCRL);
                tap_code(KC_1);
            }
            break;
        case MACRO_KVM_2:
            if (record->event.pressed) {
                tap_code(KC_SCRL);
                tap_code(KC_SCRL);
                tap_code(KC_2);
            }
            break;
        case MACRO_KVM_3:
            if (record->event.pressed) {
                tap_code(KC_SCRL);
                tap_code(KC_SCRL);
                tap_code(KC_3);
            }
            break;
        case MACRO_KVM_4:
            if (record->event.pressed) {
                tap_code(KC_SCRL);
                tap_code(KC_SCRL);
                tap_code(KC_4);
            }
            break;
        case MACRO_KVM_TG:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                tap_code(KC_NUM);
                tap_code(KC_NUM);
                unregister_code(KC_LSFT);
                tap_code(KC_LCTL);
            }
            break;
    }
    return true;
};

/* vim: set ts=2 sw=2 et: */
