/* Copyright 2021 forbiehundie
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
    _1,
	_2
};

#define KC_S1 LT(_1, KC_BSPACE)
#define KC_S2 LT(_2, KC_SPACE)
#define KC_AS LALT_T(KC_S)
#define KC_CD LCTL_T(KC_D)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)
#define KC_CK RCTL_T(KC_K)
#define KC_AL RALT_T(KC_L)

// Defines Combos
enum combos {
	TAB_COMBO,
	ESC_COMBO,
	DEL_COMBO,
	BSPC_COMBO,
	QUO_COMBO,
	ENT_COMBO,
	CAP_COMBO,
	NUMBS_COMBO,
	SYMBS_COMBO,
	NUMDEL_COMBO,
	SYMDEL_COMBO,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
	KC_Q,        KC_W,        KC_E,           KC_R,          KC_T,             KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,      \
    KC_A,        KC_AS,       KC_CD,          KC_SF,         KC_G,             KC_H,       KC_SJ,      KC_CK,      KC_AL,      KC_SCOLON, \
	KC_Z,        KC_X,        KC_C,           KC_V,          KC_B,             KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,  \
	                                                  KC_S1,                         KC_S2
	),
[_1] = LAYOUT(
	KC_1,       KC_2,        KC_3,            KC_4,          KC_5,             KC_6,       KC_7,       KC_8,       KC_9,       KC_0,      \
	KC_MINS,    KC_EQL,      KC_LBRC,         KC_RBRC,       KC_BSLS,          KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_GRAVE,  \
	KC_TRNS,    KC_TRNS,     KC_TRNS,         KC_TRNS,       KC_TRNS,          KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_SFTENT, \
	                                                  KC_TRNS,                       KC_BSPC
	),
[_2] = LAYOUT(
	KC_EXLM,    KC_AT,       KC_HASH,         KC_DLR,        KC_PERC,         KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,   \
	KC_UNDS,    KC_PLUS,     KC_LCBR,         KC_RCBR,       KC_PIPE,         KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_TILDE,  \
	KC_TRNS,    KC_TRNS,     KC_TRNS,         KC_TRNS,       KC_TRNS,         KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_SFTENT, \
	                                                  KC_BSPC,                       KC_TRNS
	),
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_S1:
		case KC_S2:
            return false;
        default:
            return true;
    }
}


const uint16_t PROGMEM tab_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM quo_combo[] = {KC_AL, KC_SCOLON, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {KC_DOT, KC_SLASH, COMBO_END};
const uint16_t PROGMEM cap_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM numbs_combo[] = {KC_9, KC_0, COMBO_END};
const uint16_t PROGMEM symbs_combo[] = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM numdel_combo[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM symdel_combo[] = {KC_ASTR, KC_LPRN, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	[TAB_COMBO] = COMBO(tab_combo, KC_TAB),
	[ESC_COMBO] = COMBO(esc_combo, KC_ESC),
	[DEL_COMBO] = COMBO(del_combo, KC_DEL),
	[BSPC_COMBO] = COMBO(bspc_combo, KC_BSPACE),
	[QUO_COMBO] = COMBO(quo_combo, KC_QUOTE),
	[ENT_COMBO] = COMBO(ent_combo, KC_ENTER),
	[CAP_COMBO] = COMBO(cap_combo, KC_CAPS),
	[NUMBS_COMBO] = COMBO(numbs_combo, KC_BSPACE),
	[SYMBS_COMBO] = COMBO(symbs_combo, KC_BSPACE),
	[NUMDEL_COMBO] = COMBO(numdel_combo, KC_DEL),
	[SYMDEL_COMBO] = COMBO(symdel_combo, KC_DEL),
};
