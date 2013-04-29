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

#include "Baddy.h"

USING_NS_CC;


void Baddy::update(float dt)
{
    const float speed = 100.0;
    
    CCPoint oldPos = this->getPosition();
    this->setPosition(CCPointMake(oldPos.x, oldPos.y - speed * dt));
    
    if (this->getPosition().y < -10)
    {
        this->reset();
    }
}

void Baddy::draw()
{
    ccDrawColor4B(0, 255, 0, 255);
//    ccDrawLine(this->point1, this->point2);
    
    ccDrawCircle(CCPointZero, 5, 0, 20, false, 1, 1);
}

void Baddy::reset()
{
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCPoint oldPos = this->getPosition();
    this->setPosition(CCPointMake(oldPos.x, size.height + this->speed));
    
    
    int rotDeg = 0.0;// (arc4random()% 90) - 45;
    
    
    this->rotation = (rotDeg * M_PI) / 180;
    //((float)(arc4random() % (int)((M_PI*2) * 100))) / 100.0;
    
    CCAffineTransform transform = CCAffineTransformRotate(CCAffineTransformIdentity, this->rotation);
    
    this->point1 = CCPointApplyAffineTransform(CCPointMake(-40.0, 0.0), transform);
    this->point2 = CCPointApplyAffineTransform(CCPointMake(40.0, 0.0), transform);
}