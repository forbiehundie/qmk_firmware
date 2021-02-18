/* Copyright 2020 forbiehundie
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
    _FN1,
	_FN2
};

#define KC_S1 LT(_FN1, KC_SPACE)
#define KC_S2 LT(_FN2, KC_SPACE)
#define KC_AS LALT_T(KC_S)
#define KC_CD LCTL_T(KC_D)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)
#define KC_CK RCTL_T(KC_K)
#define KC_AL RALT_T(KC_L)

//define combos
enum combo_events {
	DEL_COMBO,
	CAP_COMBO,
};

//tap dances declarations
enum {
	KP_7,
	KP_8,
	KP_9,
	KP_6,
	KP_DOT,
};

// tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	[KP_7] = ACTION_TAP_DANCE_DOUBLE(KC_KP_7, KC_KP_SLASH),
	[KP_8] = ACTION_TAP_DANCE_DOUBLE(KC_KP_8, KC_KP_ASTERISK),
	[KP_9] = ACTION_TAP_DANCE_DOUBLE(KC_KP_9, KC_KP_MINUS),
	[KP_6] = ACTION_TAP_DANCE_DOUBLE(KC_KP_6, KC_KP_PLUS),
	[KP_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_KP_DOT, KC_DEL),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_TAB,     KC_Q,        KC_W,        KC_E,            KC_R,          KC_T,            TD(KP_7),   TD(KP_8),   TD(KP_9),        KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPACE, \
        KC_ESC,     KC_A,        KC_AS,       KC_CD,           KC_SF,         KC_G,            KC_KP_4,    KC_KP_5,    TD(KP_6),        KC_H,       KC_SJ,      KC_CK,      KC_AL,      KC_SCOLON,  KC_QUOTE,  \
		KC_LSHIFT,	KC_Z,        KC_X,        KC_C,            KC_V,          KC_B,            KC_KP_1,    KC_KP_2,    KC_KP_3,         KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,   KC_SFTENT, \
		KC_LCTRL,   KC_LGUI,     KC_LALT,     KC_NUMLOCK,             KC_S1,                   KC_KP_0,    TD(KP_DOT), KC_SFTENT,             KC_S2,            KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT
		),
    [_FN1] = LAYOUT(
        KC_TRNS,    KC_1,        KC_2,        KC_3,            KC_4,          KC_5,            KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_DEL,  \
		KC_GRAVE,   KC_MINUS,    KC_EQUAL,    KC_LBRACKET,     KC_RBRACKET,   KC_BSLASH,       KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_TRNS,    KC_TRNS, \
		KC_TRNS,    KC_F1,       KC_F2,       KC_F3,           KC_F4,         KC_F5,           KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,  \
		KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,               KC_TRNS,                  KC_TRNS,    KC_TRNS,    KC_TRNS,               KC_BSPACE,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
    ),
	[_FN2] = LAYOUT(
        KC_TRNS,    KC_EXLM,     KC_AT,       KC_HASH,         KC_DLR,        KC_PERC,         KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_DEL,  \
		KC_TILDE,   KC_UNDS,     KC_PLUS,     KC_LCBR,         KC_RCBR,       KC_PIPE,         KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_TRNS,    KC_TRNS, \
		KC_TRNS,    KC_F1,       KC_F2,       KC_F3,           KC_F4,         KC_F5,           KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,  \
		KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,               KC_BSPACE,                KC_TRNS,    KC_TRNS,    KC_TRNS,               KC_TRNS,          KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
    )
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

const uint16_t PROGMEM del_combo[] = {KC_P, KC_BSPACE, COMBO_END};
const uint16_t PROGMEM cap_combo[] = {KC_C, KC_B, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	[DEL_COMBO] = COMBO(del_combo, KC_DEL),
	[CAP_COMBO] = COMBO(cap_combo, KC_CAPS),
};