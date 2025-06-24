/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "features/mouse_turbo_click.h"

const uint16_t PROGMEM esc_combo[] = {RSFT_T(KC_J), RGUI_T(KC_K), COMBO_END};
const uint16_t PROGMEM tab_combo[] = {LGUI_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM caps_combo[] = {LSFT_T(KC_F), RSFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM leftb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM rightb_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM leftp_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM rightp_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM leftB_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM rightB_combo[] = {KC_COMMA, KC_DOT, COMBO_END};



combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(tab_combo, KC_TAB),
    COMBO(caps_combo, KC_CAPS_LOCK),
    COMBO(leftp_combo, LSFT(KC_9)),
    COMBO(rightp_combo, LSFT(KC_0)),
    COMBO(leftb_combo, KC_LBRC),
    COMBO(rightb_combo, KC_RBRC),
    COMBO(leftB_combo, LSFT(KC_LBRC)),
    COMBO(rightB_combo, LSFT(KC_RBRC))
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x5_3(
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
                  '*', '*', '*',  '*', '*', '*'
    );

enum custom_keycodes {
    TURBO
};

enum custom_layers {
    BASE,
    MEDIA,
    NAV,
    MOUSE,
    SYM,
    NUM,
    FUN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
    * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
    * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
    * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
    * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
    * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
    * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
    *           ┌───┐                   ┌───┐
    *           │GUI├───┐           ┌───┤Alt│
    *           └───┤Bsp├───┐   ┌───┤Ent├───┘
    *               └───┤   │   │   ├───┘
    *                   └───┘   └───┘
    */
    [BASE] = LAYOUT_split_3x5_3(
        KC_Q,         KC_W,         KC_E,         KC_R,        KC_T,            KC_Y,         KC_U,         KC_I,         KC_O,                 KC_P,
LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), LSA_T(KC_G),     LSA_T(KC_H), RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SEMICOLON),
        KC_Z,         KC_X,         KC_C,         KC_V,        KC_B,            KC_N,         KC_M,      KC_COMM,       KC_DOT,              KC_SLSH,
          LT(MEDIA,KC_ESCAPE), LT(NAV, KC_SPACE), LT(MOUSE, KC_TAB),     LT(SYM, KC_ENTER), LT(NUM, KC_BSPC), LT(FUN, KC_DELETE)
    ),
    [MEDIA] = LAYOUT_split_3x5_3(
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,   KC_NO,                             KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                  KC_NO,   KC_NO,   KC_NO,           KC_MSTP,   KC_MPLY,  KC_MUTE
    ),
    [NAV] = LAYOUT_split_3x5_3(
       KC_NO,   KC_NO, DT_DOWN,   DT_UP,DT_PRNT,                               KC_UNDO,    KC_PSTE,    KC_COPY,  KC_CUT,   KC_PSCR,
     KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_CAPS_LOCK,                          KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT, KC_CAPS_LOCK,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                               KC_INSERT,  KC_PGDN,    KC_PGUP,  KC_HOME,  KC_END,
                                  KC_NO,   KC_NO,   KC_NO,            KC_ENTER, KC_BSPC,    KC_DELETE
    ),
    [MOUSE] = LAYOUT_split_3x5_3(
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                               KC_UNDO,  KC_PSTE,  KC_COPY,  KC_CUT,   KC_NO,
     KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_CAPS_LOCK,                          KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   TURBO,                               KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  KC_NO,
                                  KC_NO,   KC_NO,   KC_NO,            KC_BTN1,  KC_BTN2,  KC_BTN3
    ),
    [SYM] = LAYOUT_split_3x5_3(
 LSFT(KC_LBRC),    LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_RBRC),           KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,
LSFT(KC_QUOTE),    LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_EQUAL),          KC_NO,   KC_RSFT,  KC_RGUI,  KC_RALT,  KC_RCTL,
LSFT(KC_GRAVE),    LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_BACKSLASH),      KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,
                               LSFT(KC_9), LSFT(KC_0), LSFT(KC_MINUS),          KC_NO,   KC_NO,    KC_NO
    ),
    [NUM] = LAYOUT_split_3x5_3(
        KC_LBRC,  KC_7, KC_8, KC_9, KC_RBRC,                                    KC_NO,  KC_NO,      KC_NO,    KC_NO,    KC_NO,
        KC_QUOTE, KC_4, KC_5, KC_6, KC_EQUAL,                                   KC_NO,  KC_RSFT,  KC_RGUI,  KC_RALT,  KC_RCTL,
        KC_GRAVE, KC_1, KC_2, KC_3, KC_BACKSLASH,                               KC_NO,  KC_NO,      KC_NO,    KC_NO,    KC_NO,
                                  KC_DOT, KC_0, KC_MINUS,               KC_NO,  KC_NO,  KC_NO
    ),
    [FUN] = LAYOUT_split_3x5_3(
        KC_PSCR,        KC_F7,    KC_F8,    KC_F9,    KC_F10,                    KC_NO,  KC_NO,      KC_NO,    KC_NO,    KC_NO,
        KC_SCROLL_LOCK, KC_F4,    KC_F5,    KC_F6,    KC_F11,                    KC_NO,  KC_RSFT,  KC_RGUI,  KC_RALT,  KC_RCTL,
        KC_PAUSE,       KC_F1,    KC_F2,    KC_F3,    KC_F12,                    KC_NO,  KC_NO,      KC_NO,    KC_NO,    KC_NO,
                                    LGUI(KC_SPACE), KC_SPACE, KC_TAB,    KC_NO,  KC_NO,  KC_NO
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_mouse_turbo_click(keycode, record, TURBO)) { return false; }
  return true;
}
