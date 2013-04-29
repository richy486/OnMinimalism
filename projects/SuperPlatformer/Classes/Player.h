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

#ifndef __SuperPlatformer__Player__
#define __SuperPlatformer__Player__

#include <iostream>
#include "cocos2d.h"

struct Circle {
    float radius;
    cocos2d::ccColor3B colour;
};

class Player : public cocos2d::CCNode
{
public:
    cocos2d::CCPoint velocity;
    
    virtual bool init(float r, float g, float b, cocos2d::CCPoint pos);
    void update(float dt);
    
    float r, g, b;
    
    virtual void draw(void);
    
    cocos2d::CCPoint *pastLocations;
    int pastLocationSize;
    int pastLocationLastIndex;
    
    void playStartAnimation();
    void playWinAnimation();
    
    bool hasControl;
    
    Circle *winCircles;
    int winCirclesCount;
    float winTime;
    bool hasWon;
    
private:
    
protected:
    float startAnimationTime;
};

#endif /* defined(__SuperPlatformer__Player__) */
