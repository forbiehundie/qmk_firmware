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
	_GAME,
	_GAMENUM
};

#define SPACE_NUM LT(_NUM, KC_SPC)
#define GAME_NUM LT(_GAMENUM, KC_SFTENT)
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
	SLSH_COMBO,
	GQUO_COMBO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
    [_BASE] = LAYOUT_625_space(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_AS,   KC_CD,   KC_SF,   KC_G,    KC_H,    KC_SJ,   KC_CK,   KC_AL,            KC_SCLN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SFTENT,
        KC_LCTL, KC_LGUI, KC_LALT,                     SPACE_NUM,                                 KC_RALT, KC_RCTL
    ),

    [_NUM] = LAYOUT_625_space(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_CAPS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,          _______,
        _______,          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   _______, _______, _______,
        _______, _______, _______,                      _______,                                TO(_GAME), _______
    ),

    [_GAME] = LAYOUT_625_space(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,             KC_SCLN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  GAME_NUM,
        KC_LCTL, KC_LGUI, KC_LALT,                      KC_SPACE,                                 KC_RALT, KC_RCTL
    ),
	
	[_GAMENUM] = LAYOUT_625_space(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_CAPS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,          _______,
        _______,          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   _______, _______, _______,
        _______, _______, _______,                       _______,                               TO(_BASE), _______ 
	),
};

const uint16_t PROGMEM del_combo[] = {KC_P, KC_BSPC, COMBO_END};
const uint16_t PROGMEM quo_combo[] = {KC_AL, KC_SCOLON, COMBO_END};
const uint16_t PROGMEM gquo_combo[] = {KC_L, KC_SCOLON, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	[DEL_COMBO] = COMBO(del_combo, KC_DEL),
	[QUO_COMBO] = COMBO(quo_combo, KC_QUOTE),
	[GQUO_COMBO] = COMBO(gquo_combo, KC_QUOTE),
	[SLSH_COMBO] = COMBO(slsh_combo, KC_SLSH),
};