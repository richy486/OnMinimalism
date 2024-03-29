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

#include "PassableBlock.h"

USING_NS_CC;

bool PassableBlock::init(float width, float height, cocos2d::CCPoint pos, float r, float g, float b)
{
    Block::init(width, height, pos);
    
    this->r = r;
    this->g = g;
    this->b = b;
    
    return true;
}
void PassableBlock::update(float dt)
{
}
void PassableBlock::draw()
{
    ccColor4F col = {this->r, this->g, this->b, 1.0f};
    ccDrawSolidPoly(this->points, 4, col);
}

int PassableBlock::type()
{
    return TYPE_PASSABLEBLOCK;
}