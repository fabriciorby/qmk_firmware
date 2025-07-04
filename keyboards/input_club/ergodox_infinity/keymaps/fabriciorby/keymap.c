#include QMK_KEYBOARD_H
#include "version.h"
#include "features/mouse_turbo_click.h"

const uint16_t PROGMEM esc_combo[] = {RSFT_T(KC_J), RGUI_T(KC_K), COMBO_END};
const uint16_t PROGMEM tab_combo[] = {LGUI_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM capsl_combo[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM capsr_combo[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM leftb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM rightb_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM leftp_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM rightp_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM leftB_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM rightB_combo[] = {KC_COMMA, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(tab_combo, KC_TAB),
    COMBO(capsr_combo, KC_CAPS_LOCK),
    COMBO(capsl_combo, KC_CAPS_LOCK),
    COMBO(leftp_combo, LSFT(KC_9)),
    COMBO(rightp_combo, LSFT(KC_0)),
    COMBO(leftb_combo, KC_LBRC),
    COMBO(rightb_combo, KC_RBRC),
    COMBO(leftB_combo, LSFT(KC_LBRC)),
    COMBO(rightB_combo, LSFT(KC_RBRC))
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_ergodox(
        'L', 'L', 'L', 'L', 'L', 'L', 'L',
        'L', 'L', 'L', 'L', 'L', 'L', 'L',
        'L', 'L', 'L', 'L', 'L', 'L',
        'L', 'L', 'L', 'L', 'L', 'L', 'L',
        'L', 'L', 'L', 'L', 'L',
        '*', '*',
        '*',
        '*', '*', '*',

        'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'R', 'R', 'R', 'R', 'R', 'R', 'R',
             'R', 'R', 'R', 'R', 'R', 'R',
        'R', 'R', 'R', 'R', 'R', 'R', 'R',
             'R', 'R', 'R', 'R', 'R',
        '*', '*',
        '*',
        '*', '*', '*'
    );


enum custom_layers {
    BASE,   // default layer
    HMOD,   // home row modification
    SYMB,   // symbols
    MDIA,   // media keys
    VIMK,   // vim keys
    WKMN,   // workman layout
};


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN,
  TURBO, // autoclicker key
};

#define KC_COPY LCMD(KC_C)
#define KC_PSTE LCMD(KC_V)
#define KC_CUT  LCMD(KC_X)
#define KC_UNDO LCMD(KC_Z)
#define KC_REDO SCMD(KC_Z)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `~   |   1  |   2  |   3  |   4  |   5  |Delete|           |  +=  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Caps |           | LCmd |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------| Lock |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |' / RCmd|
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift | Z/L1 |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  | //L1 | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |  '"  |OptShf| VIM  | LOptn|                                       |  Up  | Down |   [  |   ]  |RCtrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | TURBO|       |  L1  |  L5  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space| LCmd |------|       |------|Enter   |Backsp|
 *                                 |      |      | End  |       | PgDn |        |ace   |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(
        //Left Hand
//      |               |               |               |               |               |               |               |
        KC_GRV,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_DEL,
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_CAPS,
        KC_ESC,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,
        KC_LSFT,        LT(SYMB,KC_Z),  KC_X,           KC_C,           KC_V,           KC_B,           ALL_T(KC_NO),
        LCTL_T(KC_NO),  KC_QUOT,        LALT(KC_LSFT),  LT(VIMK,KC_NO),  KC_LALT,
        LALT_T(KC_APP), TURBO,
        KC_HOME,
        KC_SPC,         KC_LCMD,        KC_END,

        //Right Hand
//      |               |               |               |               |               |               |               |
        KC_EQL,         KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,
        KC_LCMD,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
                        KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        RGUI_T(KC_QUOT),
        MEH_T(KC_NO),   KC_N,           KC_M,           KC_COMM,        KC_DOT,         LT(SYMB,KC_SLSH),  KC_RSFT,
                        KC_UP,          KC_DOWN,        KC_LBRC,        KC_RBRC,        RCTL_T(KC_NO),
        TG(SYMB),       DF(HMOD),
        KC_PGUP,
        KC_PGDN, KC_ENT, KC_BSPC
    ),
// Base with Home Row Mod
[HMOD] = LAYOUT_ergodox(
        //Left Hand
//      |               |               |               |               |               |               |               |
        KC_GRV,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_DEL,
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_CAPS,
        KC_ESC,         LCTL_T(KC_A),   LALT_T(KC_S),   LGUI_T(KC_D),   LSFT_T(KC_F),   LSA_T(KC_G),
        KC_LSFT,        LT(SYMB,KC_Z),  KC_X,           KC_C,           KC_V,           KC_B,           ALL_T(KC_NO),
        LCTL_T(KC_NO),  KC_QUOT,        LALT(KC_LSFT),  KC_LALT,        LT(VIMK,KC_NO),
        LALT_T(KC_APP), TURBO,
        KC_HOME,
        KC_SPC,         KC_LCMD,        KC_END,

        //Right Hand
//      |               |               |               |               |               |               |               |
        KC_EQL,         KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,
        KC_LCMD,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
                        LSA_T(KC_H),    RSFT_T(KC_J),   RGUI_T(KC_K),   RALT_T(KC_L),   RCTL_T(KC_SCLN),RGUI_T(KC_QUOT),
        MEH_T(KC_NO),   KC_N,           KC_M,           KC_COMM,        KC_DOT,         LT(SYMB,KC_SLSH),  KC_RSFT,
                        KC_UP,          KC_DOWN,        KC_LBRC,        KC_RBRC,        RCTL_T(KC_NO),
        TG(SYMB),       DF(BASE),
        KC_PGUP,
        KC_PGDN, KC_ENT, KC_BSPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   =  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |EE_CLR |      |      |      |      |                                       |   0  |   0  |   .  |   \  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat| BOOTL|       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright| RESET|       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      | DEBUG|       |MAKE  |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       EE_CLR, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       LM_NEXT,QK_BOOTLOADER,
                                               QK_REBOOT,
                               LM_BRID,LM_BRIU,QK_DEBUG_TOGGLE,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_EQL, KC_TRNS,
                         KC_0,   KC_0,    KC_DOT,  KC_BSLS,  KC_TRNS,
       LM_TOGG, TG(BASE),
       KC_TRNS,
       QK_MAKE, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       //Left Hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
       //Right Hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
/* Keymap 3: Vim Keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | Undo | Paste| Copy | Cut  | Redo |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |Delete|      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// VIM KEYS
[VIMK] = LAYOUT_ergodox(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_DEL, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO,
        KC_NO,
        KC_NO, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_UNDO, KC_PSTE, KC_COPY, KC_CUT, KC_REDO, KC_NO,
               KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO,
        KC_NO,
        KC_NO, KC_NO, KC_NO
    ),
/* Keymap 5: Workman
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `~   |   1  |   2  |   3  |   4  |   5  |Delete|           |  +=  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   D  |   R  |   W  |   B  | Caps |           | LCmd |   J  |   F  |   U  |   P  |   ;  |   \    |
 * |--------+------+------+------+------+------| Lock |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |   I  |' / RCmd|
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift | Z/L1 |   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |   .  | //L1 | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |  '"  |OptShf| VIM  | LOptn|                                       |  Up  | Down |   [  |   ]  |RCtrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  |  L1  |       |  L1  |  L4  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|Enter   |Backsp|
 *                                 |      |ace   | End  |       | PgDn |        |ace   |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[WKMN] = LAYOUT_ergodox(
        //Left Hand
//      |               |               |               |               |               |               |               |
        KC_GRV,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_DEL,
        KC_TAB,         KC_Q,           KC_D,           KC_R,           KC_W,           KC_B,           KC_CAPS,
        KC_ESC,         KC_A,           KC_S,           KC_H,           KC_T,           KC_G,
        KC_LSFT,        LT(SYMB,KC_Z),     KC_X,           KC_M,           KC_C,           KC_V,           ALL_T(KC_NO),
        LCTL_T(KC_NO),  KC_QUOT,        LALT(KC_LSFT),  LT(SYMB,KC_NO),  KC_LALT,
        LALT_T(KC_APP), TG(SYMB),
        KC_HOME,
        KC_SPC,         KC_LCMD,        KC_END,

        //Right Hand
//      |               |               |               |               |               |               |               |
        KC_EQL,         KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,
        KC_LCMD,        KC_J,           KC_F,           KC_U,           KC_P,           KC_SCLN,        KC_BSLS,
                        KC_Y,           KC_N,           KC_E,           KC_O,           KC_I,           RGUI_T(KC_QUOT),
        MEH_T(KC_NO),   KC_K,           KC_L,           KC_COMM,        KC_DOT,         LT(SYMB,KC_SLSH),  KC_RSFT,
                        KC_UP,          KC_DOWN,        KC_LBRC,        KC_RBRC,        RCTL_T(KC_NO),
        TG(SYMB),       TG(BASE),
        KC_PGUP,
        KC_PGDN, KC_ENT, KC_BSPC
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case TURBO:
      if (!process_mouse_turbo_click(keycode, record, TURBO)) {
        return false;
      }
      break;
  }
  return true;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = get_highest_layer(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

}

