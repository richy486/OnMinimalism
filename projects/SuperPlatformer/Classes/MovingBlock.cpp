//
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

#include "MovingBlock.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

bool MovingBlock::init(float width, float height, cocos2d::CCPoint pos, cocos2d::CCPoint moveTo, float time, float timeOffset)
{
    Block::init(width, height, pos);
    
    this->origPos = pos;
    this->moveTo = moveTo;
    this->time = time;
    this->timeOffset = timeOffset;
    this->smashFrame = false;
    
    this->setPosition(this->moveTo);

	this->runningTime = 0.0;
    
    return true;
}

void MovingBlock::update(float dt)
{
    this->runningTime += 1 / 60.0f;//dt;
    
    if (this->runningTime >= this->time + this->timeOffset)
    {
        this->timeOffset = 0;
        this->runningTime = 0;
        this->smashFrame = true;
        
        this->setPosition(this->moveTo);
        
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Hit_Hurt5.wav");
    }
    else if (this->getPosition().x != this->origPos.x || this->getPosition().y != this->origPos.y)
    {
        this->smashFrame = false;
        
        float percent = this->runningTime / this->time;
        
        float difX = this->getPosition().x - this->origPos.x;
        float difY = this->getPosition().y - this->origPos.y;
        
        CCPoint pos = ccp(this->getPosition().x - (difX * percent), this->getPosition().y - (difY * percent));
        this->setPosition(pos);
    }
    
}
void MovingBlock::draw()
{
    Block::draw();
}

int MovingBlock::type()
{
    return TYPE_MOVINGBLOCK;
}