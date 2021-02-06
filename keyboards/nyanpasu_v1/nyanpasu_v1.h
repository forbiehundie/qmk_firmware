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

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the Keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    K00, K01, K02, K03, K04, K05,   K06, K07, K16,   K15, K14, K13, K12, K11, K10,  \
    K20, K21, K22, K23, K24, K25,   K26, K27, K36,   K35, K34, K33, K32, K31, K30,  \
	K40, K41, K42, K43, K44, K45,   K46, K47, K56,   K55, K54, K53, K52, K51, K50,  \
	K60, K61, K62, K63,    K64,     K66, K67, K76,      K75,   K73, K72, K71, K70   \
) \
{ \
    { K00, K01, K02, K03, K04,   K05,   K06, K07 }, \
    { K10, K11, K12, K13, K14,   K15,   K16 }, \
	{ K20, K21, K22, K23, K24,   K25,   K26, K27 }, \
	{ K30, K31, K32, K33, K34,   K35,   K36 }, \
	{ K40, K41, K42, K43, K44,   K45,   K46, K47 }, \
	{ K50, K51, K52, K53, K54,   K55,   K56 }, \
	{ K60, K61, K62, K63, K64,   KC_NO, K66, K67 }, \
	{ K70, K71, K72, K73, KC_NO, K75,   K76 }  \
}
