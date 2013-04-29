//
//    On Minimalism for Ludum Dare 26
//    Copyright (C) 2013 Richard Adem
//
//    This program is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public License
//    as published by the Free Software Foundation; either version 2
//    of the License, or (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#ifndef __SuperPlatformer__LevelManager__
#define __SuperPlatformer__LevelManager__

#include <iostream>
#include "cocos2d.h"

#define EXIT_TOP 0
#define EXIT_BOTTOM 1
#define EXIT_LEFT 2
#define EXIT_RIGHT 3

class LevelManager
{
public:
    void setupLevel(int index, cocos2d::CCArray *blocks, int *exits);
};

#endif /* defined(__SuperPlatformer__LevelManager__) */
