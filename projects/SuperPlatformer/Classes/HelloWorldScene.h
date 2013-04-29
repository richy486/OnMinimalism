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

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class Player;
class Baddy;
class Line;
class LevelManager;

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
    
    cocos2d::CCTMXTiledMap *map;
    cocos2d::CCTMXLayer *walls;
    
    void update(float dt);
    void ccTouchesBegan(cocos2d::CCSet *touches, cocos2d::CCEvent *event);
    void ccTouchesMoved(cocos2d::CCSet *touches, cocos2d::CCEvent *event);
    void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    
    void onEnterTransitionDidFinish();
    void keyDown(cocos2d::CCKeyboard* pKeyboard);
    void keyUp(cocos2d::CCKeyboard* pKeyboard);
    
private:
    Player *player1;
    Player *player2;
    
    Baddy *baddy;
    
    Line *line;
    
    cocos2d::CCArray *blocks;
    int *exits;
    
    cocos2d::CCPoint startPos;
    LevelManager *levelManager;
    
protected:
    cocos2d::CCSprite *ball;
    
    bool leftDown;
    bool rightDown;
    bool upDown;
    bool downDown;
    
    bool aDown;
    bool dDown;
    bool wDown;
    bool sDown;
    bool lineIntersection(cocos2d::CCPoint point1a, cocos2d::CCPoint point1b, cocos2d::CCPoint point2a, cocos2d::CCPoint point2b, float *intersectingPointX, float *intersectingPointY);
    float wrap(float value, float max, float min);
    
    int currentLevel;
};

#endif // __HELLOWORLD_SCENE_H__
