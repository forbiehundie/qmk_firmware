/*
Copyright 2018 QMK Contributors

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

enum {
	TD_MUTE_DEAFEN,
	TD_PRTSCRN,
	TD_ALTF4
};

qk_tap_dance_action_t tap_dance_actions[] = {
	
	[TD_MUTE_DEAFEN] = ACTION_TAP_DANCE_DOUBLE(KC_F13, KC_F14),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(TD(TD_MUTE_DEAFEN)),

};
