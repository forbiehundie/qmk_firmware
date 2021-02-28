/* Copyright 2020
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _NUM,
    _SYM
};

#define SPACE_NUM LT(_NUM, KC_SPC)
#define SPACE_SYM LT(_SYM, KC_SPC)
#define KC_AS LALT_T(KC_S)
#define KC_CD LCTL_T(KC_D)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)
#define KC_CK RCTL_T(KC_K)
#define KC_AL RALT_T(KC_L)

// Defines Combos
enum combo_events {
	DEL_COMBO,
	QUO_COMBO,
	ENT_COMBO,
	CAP_COMBO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
    [_BASE] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_AS,   KC_CD,   KC_SF,   KC_G,    KC_H,    KC_SJ,   KC_CK,   KC_AL,            KC_SCLN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        KC_LCTL, KC_LGUI, KC_LALT,              SPACE_NUM,  SPACE_SYM,                   KC_RALT, KC_RGUI, KC_RCTL
    ),

    [_NUM] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,          _______,
        _______,          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______,
        _______, _______, _______,                   _______, KC_BSPC,                    _______, _______, _______
    ),

    [_SYM] = LAYOUT(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,          _______,
        _______,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______,
        _______, _______, _______,                   KC_BSPC, _______,                    _______, _______, _______
    )
};

const uint16_t PROGMEM del_combo[] = {KC_P, KC_BSPC, COMBO_END};
const uint16_t PROGMEM quo_combo[] = {KC_AL, KC_SCOLON, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {KC_DOT, KC_SLASH, COMBO_END};
const uint16_t PROGMEM cap_combo[] = {KC_C, KC_B, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	[DEL_COMBO] = COMBO(del_combo, KC_DEL),
	[QUO_COMBO] = COMBO(quo_combo, KC_QUOTE),
	[ENT_COMBO] = COMBO(ent_combo, KC_ENTER),
	[CAP_COMBO] = COMBO(cap_combo, KC_CAPS),
};