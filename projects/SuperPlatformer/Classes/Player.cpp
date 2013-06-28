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

#include "Player.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

#define TOTAL_START_ANIMATION_TIME 1.0
#define TOTAL_WIN_ANIMATION_TIME 0.2

void ccFillPoly( CCPoint *poli, int points, bool closePolygon );

bool Player::init(float r, float g, float b, CCPoint pos)
{
    CCNode::init();
    
    this->r = r;
    this->g = g;
    this->b = b;
    
    this->velocity = ccp(0.0, 0.0);
    
    this->pastLocationSize = 2;
    this->pastLocations = new CCPoint[this->pastLocationSize];
    this->pastLocationLastIndex = 0;
    
    this->hasControl = true;
    this->hasWon = false;
    
    for (int i = 0; i < this->pastLocationSize; ++i)
    {
        this->pastLocations[i] = pos;
    }
    
    this->setPosition(pos);
    
    this->winCirclesCount = 40;
    this->winCircles = new Circle[this->winCirclesCount];
    for (int i = 0; i < this->winCirclesCount; ++i)
    {
        this->winCircles[i].radius = -1;
    }
    this->winTime = 0.0;
    
    return true;
}

void Player::playStartAnimation()
{
    this->startAnimationTime = TOTAL_START_ANIMATION_TIME;
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Spawn.wav");
}

void Player::playWinAnimation()
{
    this->hasControl = false;
    this->hasWon = true;
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Win.wav");
//    this->winTime = TOTAL_WIN_ANIMATION_TIME;
}


void Player::update(float dt)
{
    if (this->hasControl)
    {
        CCPoint oldPos = this->getPosition();
        this->pastLocations[this->pastLocationLastIndex] = oldPos;
        if (++(this->pastLocationLastIndex) >= this->pastLocationSize)
        {
            this->pastLocationLastIndex = 0;
        }
        
        const float maxSpeed = 2.0;
        
        const CCPoint minMovement = ccp(-maxSpeed, -maxSpeed);
        const CCPoint maxMovement = ccp(maxSpeed, maxSpeed);
        this->velocity = ccpClamp(this->velocity, minMovement, maxMovement);
        
        CCPoint newPos = CCPointMake(this->getPosition().x + this->velocity.x, this->getPosition().y + this->velocity.y);
        this->setPosition(newPos);
        
        this->velocity.x *= 0.75;
        this->velocity.y *= 0.75;
    }
    
    if (this->startAnimationTime > 0.0)
    {
        this->startAnimationTime -=  1 / 60.0f;//dt;
    }
    
    if (this->hasWon)
    {
        if (this->winTime > 0.0)
        {
            this->winTime -=  1 / 60.0f;//dt;
        }
        else
        {
            this->winTime = TOTAL_WIN_ANIMATION_TIME;
            
            for (int i = 0; i < this->winCirclesCount; ++i)
            {
                if (this->winCircles[i].radius < 0.0)
                {
                    ccColor3B colour;
                    float fraction = ((float)(rand()%10000)) / 10000;
                    int sp = fraction / 0.166666666666;
                    float z = fraction - (sp * 0.166666666666);
                    float change = z / 0.166666666666;
                    switch (sp) {
                        case 0:
                            colour = ccc3(255, 255 - (255 * change), 0);
                            break;
                        case 1:
                            colour = ccc3(255, 0, 255 * change);
                            break;
                        case 2:
                            colour = ccc3(255 - (255 * change), 0, 255);
                            break;
                        case 3:
                            colour = ccc3(0, 255 * change, 255);
                            break;
                        case 4:
                            colour = ccc3(0, 255, 255 - (255 * change));
                            break;
                        case 5:
                            colour = ccc3(255 * change, 255, 0);
                            break;
                            
                        default:
                            break;
                    }
                    
                    this->winCircles[i].radius = 20.0;
                    this->winCircles[i].colour = colour;
                    
                    break;
                }
            }
        }
    }
}

//void Player::draw()
void Player::draw()
{
    if (!this->hasWon)
    {
        ccDrawColor4B(this->r * 255, this->g * 255, this->b * 255, 255);
        CCPoint point = CCPointMake(0, 0);
        ccDrawPoint(point);
    
    
        if (this->startAnimationTime > 0.0)
        {
            float percent = this->startAnimationTime / TOTAL_START_ANIMATION_TIME;
            
            ccColor3B colour;
            float fraction = ((float)(rand()%10000)) / 10000;
            int sp = fraction / 0.166666666666;
            float z = fraction - (sp * 0.166666666666);
            float change = z / 0.166666666666;
            switch (sp) {
                case 0:
                    colour = ccc3(255, 255 - (255 * change), 0);
                    break;
                case 1:
                    colour = ccc3(255, 0, 255 * change);
                    break;
                case 2:
                    colour = ccc3(255 - (255 * change), 0, 255);
                    break;
                case 3:
                    colour = ccc3(0, 255 * change, 255);
                    break;
                case 4:
                    colour = ccc3(0, 255, 255 - (255 * change));
                    break;
                case 5:
                    colour = ccc3(255 * change, 255, 0);
                    break;
                    
                default:
                    break;
            }
            ccDrawColor4B(colour.r, colour.g, colour.b, 255);
            ccDrawCircle(point, 30 * percent, 0, 20, false, 1.0, 1.0);
        }
    }
    else
    {
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        
        for (int i = 0; i < this->winCirclesCount; ++i)
        {
            if (this->winCircles[i].radius > 0)
            {
                ccDrawColor4B(this->winCircles[i].colour.r, this->winCircles[i].colour.g, this->winCircles[i].colour.b, 255);
                ccDrawCircle(ccp(size.width/2 - this->getPosition().x, size.height/2 - this->getPosition().y), this->winCircles[i].radius, 0, 40, false, 1.0, 1.0);
                
                this->winCircles[i].radius += 1.0;
                
                if (this->winCircles[i].radius > 300)
                {
                    this->winCircles[i].radius = -1;
                }
            }
        }
    }
}


void ccFillPoly( CCPoint *poli, int points, bool closePolygon )
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    ccGLEnableVertexAttribs( kCCVertexAttribFlag_Position );
    kmGLPushMatrix();
#else
    // Default GL states: GL_TEXTURE_2D, GL_VERTEX_ARRAY, GL_COLOR_ARRAY, GL_TEXTURE_COORD_ARRAY
    // Needed states: GL_VERTEX_ARRAY,
    // Unneeded states: GL_TEXTURE_2D, GL_TEXTURE_COORD_ARRAY, GL_COLOR_ARRAY
    glDisable(GL_TEXTURE_2D);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, poli);
#endif
    
    if( closePolygon )
        //	 glDrawArrays(GL_LINE_LOOP, 0, points);
        glDrawArrays(GL_TRIANGLE_FAN, 0, points);
    else
        glDrawArrays(GL_LINE_STRIP, 0, points);
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    kmGLPopMatrix();
#else
    // restore default state
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnable(GL_TEXTURE_2D);
#endif
}
