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

#include "CollectableBlock.h"

USING_NS_CC;

bool CollectableBlock::init(cocos2d::CCPoint pos, const char *pszFileName)
{
    this->sprite = CCSprite::create(pszFileName);
    float width, height;
    width = this->sprite->getContentSize().width;
    height = this->sprite->getContentSize().height;
    this->addChild(this->sprite);
    
    Block::init(width, height, pos);
    
    return true;
}
void CollectableBlock::update(float dt)
{}
void CollectableBlock::draw()
{}

int CollectableBlock::type()
{
    return TYPE_COLLECTABLEBLOCK;
}