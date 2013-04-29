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

#ifndef __SuperPlatformer__MovingBlock__
#define __SuperPlatformer__MovingBlock__

#include <iostream>
#include "cocos2d.h"
#include "Block.h"

#define TYPE_MOVINGBLOCK 10292

class MovingBlock : public Block
{
public:
    virtual bool init(float width, float height, cocos2d::CCPoint pos, cocos2d::CCPoint moveTo, float time, float timeOffset);
    void update(float dt);
    void draw();
    
    virtual int type();
    
    cocos2d::CCPoint origPos;
    cocos2d::CCPoint moveTo;
    float time;
    float timeOffset;
    bool smashFrame;
    
protected:
    float runningTime;
};

#endif /* defined(__SuperPlatformer__MovingBlock__) */
