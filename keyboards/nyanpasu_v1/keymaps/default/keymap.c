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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_TAB,     KC_Q,        KC_W,        KC_E,            KC_R,          KC_T,            KC_KP_7,    KC_KP_8,    KC_KP_9,         KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPACE, \
        KC_ESC,     KC_A,        KC_S,        KC_D,            KC_F,          KC_G,            KC_KP_4,    KC_KP_5,    KC_KP_6,         KC_H,       KC_J,       KC_K,       KC_L,       KC_SCOLON,  KC_QUOTE, \
		KC_LSHIFT,	KC_Z,        KC_X,        KC_C,            KC_V,          KC_B,            KC_KP_1,    KC_KP_2,    KC_KP_3,         KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,   KC_SFTENT, \
		KC_LCTRL,   KC_LGUI,     KC_LALT,     KC_NUMLOCK,       LT(_FN1,KC_SPACE),             KC_KP_0,    KC_KP_DOT,  KC_SFTENT,       LT(_FN2,KC_SPACE),      KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT
		),
    [_FN1] = LAYOUT(
        KC_TRNS,    KC_1,        KC_2,        KC_3,            KC_4,          KC_5,            KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_DEL, \
		KC_GRAVE,   KC_MINUS,    KC_EQUAL,    KC_LBRACKET,     KC_RBRACKET,   KC_BSLASH,       KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, \
		KC_TRNS,    KC_F1,       KC_F2,       KC_F3,           KC_F4,         KC_F5,           KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_F6,      KC_F7,      KC_F8,      KC_TRNS,    KC_TRNS,    KC_TRNS, \
		KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_CAPS,               KC_TRNS,                  KC_TRNS,    KC_TRNS,    KC_TRNS,               KC_BSPACE,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
    ),
	[_FN2] = LAYOUT(
        KC_TRNS,    KC_EXLM,     KC_AT,       KC_HASH,         KC_DLR,        KC_PERC,         KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_DEL, \
		KC_TILDE,   KC_UNDS,     KC_PLUS,     KC_LCBR,         KC_RCBR,       KC_PIPE,         KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, \
		KC_TRNS,    KC_F1,       KC_F2,       KC_F3,           KC_F4,         KC_F5,           KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_F6,      KC_F7,      KC_F8,      KC_TRNS,    KC_TRNS,    KC_TRNS, \
		KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_CAPS,               KC_BSPACE,                KC_TRNS,    KC_TRNS,    KC_TRNS,               KC_TRNS,          KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
    )
};
