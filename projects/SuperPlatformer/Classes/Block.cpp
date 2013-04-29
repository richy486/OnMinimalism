//
//  Block.cpp
//  SuperPlatformer
//
//  Created by Richard Adem on 28/04/13.
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

#include "Block.h"

USING_NS_CC;

bool Block::init(float width, float height, cocos2d::CCPoint pos)
{
    CCNode::init();
    
    this->points = new CCPoint[4];
    this->points[0] = CCPointMake(-(width/2), -(height/2)); // 
    this->points[1] = CCPointMake((width/2), -(height/2));
    this->points[2] = CCPointMake((width/2), (height/2));
    this->points[3] = CCPointMake(-(width/2), (height/2));
    
    this->normals = new CCPoint[4];
    this->normals[0] = CCPointMake(0, -1);
    this->normals[1] = CCPointMake(1, 0);
    this->normals[2] = CCPointMake(0, 1);
    this->normals[3] = CCPointMake(-1, 0);
    
    this->setPosition(pos);
    return true;
}

bool Block::isPointInside(cocos2d::CCPoint point)
{
    float maxX = this->getPosition().x + this->points[1].x;
    float minX = this->getPosition().x + this->points[0].x;
    float maxY = this->getPosition().y + this->points[2].y;
    float minY = this->getPosition().y + this->points[0].y;
    if (point.x >= minX && point.x <= maxX
        && point.y >= minY && point.y <= maxY)
    {
        return true;
    }
    
    return false;
}

void Block::update(float dt)
{
    
}
void Block::draw()
{
//    ccDrawColor4B(150, 150, 150, 100);
//    {
//        CCPointMake(-50, -10)
//        , CCPointMake(50, -10)
//        , CCPointMake(50, 10)
//        , CCPointMake(-50, 10)
//        
//    };
    ccColor4F col = {0.5f, 0.5f, 0.5f, 1.0f};
    ccDrawSolidPoly(points, 4, col);
}

int Block::type()
{
    return TYPE_BLOCK;
}