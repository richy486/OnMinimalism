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

#include "HelloWorldScene.h"
#include "Player.h"
#include "Baddy.h"
#include "Line.h"
#include "Block.h"
#include "MovingBlock.h"
#include "PassableBlock.h"
#include "CollectableBlock.h"
#include "LevelManager.h"

#define TOLL 0.002

USING_NS_CC;

#define STARTPOINT_FROM_TOP ccp(size.width/2, 15)
#define STARTPOINT_FROM_BOTTOM ccp(size.width/2, size.height - 15)
#define STARTPOINT_FROM_LEFT ccp(size.width - 15, size.height/2)
#define STARTPOINT_FROM_RIGHT ccp(15, size.height/2)

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        
        return false;
    }

	this->player1 = NULL;
    this->player2 = NULL;
    this->line = NULL;
    this->baddy = NULL;
    this->blocks = NULL;
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCLayerColor *blueSky = CCLayerColor::create(ccc4(255, 255, 255, 255));
    this->addChild(blueSky);
    
    leftDown = false;
    rightDown = false;
    upDown = false;
    downDown = false;
    
    aDown = false;
    dDown = false;
    wDown = false;
    sDown = false;    
    
    this->startPos = STARTPOINT_FROM_TOP;
    this->currentLevel = 0;
    
    
    
    this->player1 = new Player();
    this->player1->init(1, 0, 0, this->startPos);
    this->addChild(this->player1, 100);
    
//    this->player2 = new Player();
//    this->player2->initWithColour(0, 0, 1);
//    this->player2->setPosition(ccp(100, 100));
//    this->addChild(player2);    
    
    this->blocks = new CCArray();
    this->exits = new int[4];
    
    this->levelManager = new LevelManager();
    this->levelManager->setupLevel(this->currentLevel, this->blocks, this->exits);
    CCObject *block = NULL;
    CCARRAY_FOREACH(this->blocks, block)
    {
        this->addChild((CCNode*)block);
    }
    

//    this->ball = CCSprite::create("koalio_stand.png");
//    this->ball->setPosition(ccp(size.width/2, size.height/2));
//    this->addChild(this->ball, 0);
    
    
//    CCSprite *dot = CCSprite::create("dot.png");
//    dot->setPosition(player->getPosition());
//    this->addChild(dot);
    
    TargetPlatform target = CCApplication::sharedApplication()->getTargetPlatform();
    if ( target == kTargetLinux || target == kTargetMacOS)// target == kTargetWindows ||
    {
        this->setKeypadEnabled(true);
    }
    else
    {
        this->setTouchEnabled(true);
    }
    
    
    // schedule
    this->schedule(schedule_selector(HelloWorld::update));
    
    this->player1->playStartAnimation();
    
    return true;
}

void HelloWorld::onEnterTransitionDidFinish() {
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCKeyboardDispatcher* dispatcher = pDirector->getKeyboardDispatcher();
    dispatcher->addDelegate(this, INT_MIN + 1);

    CCLayer::onEnterTransitionDidFinish();
}
#define SHIFTED     0x8000
void HelloWorld::ccTouchesBegan(CCSet *touches, CCEvent *event)
{
    CCSetIterator it;
    CCTouch* touch;
    for( it = touches->begin(); it != touches->end(); it++) 
    {
        touch = (CCTouch*)(*it);
        
        CCPoint touchLocation = this->convertToNodeSpace(touch->getLocation());  //[self convertTouchToNodeSpace:t];
        CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
        


    }
/*
	if(GetKeyState(VK_UP) & SHIFTED)  
      {  
           CCLog("up (up)");
		   upDown = true;
      }

	if(GetKeyState(VK_DOWN) & SHIFTED)  
      {  
           CCLog("down (up)");
		   downDown = true;
      }
	if(GetKeyState(VK_LEFT) & SHIFTED)  
      {  
           //CCLog("down (up)");
		   leftDown = true;
      }
	if(GetKeyState(VK_RIGHT) & SHIFTED)  
      {  
           //CCLog("down (up)");
		   rightDown = true;
      }
  */
}

void HelloWorld::ccTouchesMoved(CCSet *touches, CCEvent *event)
{
    CCSetIterator it;
    CCTouch* touch;
    for( it = touches->begin(); it != touches->end(); it++)
    {
        touch = (CCTouch*)(*it);
        
        CCPoint touchLocation = this->convertToNodeSpace(touch->getLocation());  //[self convertTouchToNodeSpace:t];
        
        //get previous touch and convert it to node space
        CCPoint previousTouchLocation = touch->getPreviousLocationInView();//[t previousLocationInView:[t view]];
        CCSize screenSize = CCDirector::sharedDirector()->getWinSize(); // [[CCDirector sharedDirector] winSize];
        previousTouchLocation = ccp(previousTouchLocation.x, screenSize.height - previousTouchLocation.y);
 
    }

	
}

void HelloWorld::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
    // Choose one of the touches to work with
//    CCTouch* touch = (CCTouch*)( touches->anyObject() );
    
//    player->setPosition(ccp(player->getPosition().x, player->getPosition().y -5));
    
    
    CCSetIterator it;
    CCTouch* touch;
    for( it = touches->begin(); it != touches->end(); it++)
    {
        touch = (CCTouch*)(*it);
        CCPoint touchLocation = this->convertToNodeSpace(touch->getLocation());  //[self convertTouchToNodeSpace:t];
        CCSize screenSize = CCDirector::sharedDirector()->getWinSize(); // [[CCDirector sharedDirector] winSize];

    }
/*
	if (!(GetKeyState(VK_UP) & SHIFTED))
      {  
           CCLog("up (down)");
		   upDown = false;
      }

	if (!(GetKeyState(VK_DOWN) & SHIFTED))
      {  
           CCLog("up (down)");
		   downDown = false;
      }
	if (!(GetKeyState(VK_LEFT) & SHIFTED))
      {  
           //CCLog("up (down)");
		   leftDown = false;
      }
	if (!(GetKeyState(VK_RIGHT) & SHIFTED))
      {  
           //CCLog("up (down)");
		   rightDown = false;
      }
	  */
}

void HelloWorld::keyDown(CCKeyboard* pKeyboard)
{
    if (pKeyboard->getKey() == 123) // left
    {
        leftDown = true;
    }
    if (pKeyboard->getKey() == 124) // right
    {
        rightDown = true;
    }
    if (pKeyboard->getKey() == 126) // up
    {
        upDown = true;
    }
    if (pKeyboard->getKey() == 125) // down
    {
        downDown = true;
    }
    
    if (pKeyboard->getKey() == 0) // left
    {
        aDown = true;
    }
    if (pKeyboard->getKey() == 2) // right
    {
        dDown = true;
    }
    if (pKeyboard->getKey() == 13) // up
    {
        wDown = true;
    }
    if (pKeyboard->getKey() == 1) // down
    {
        sDown = true;
    }
}

void HelloWorld::keyUp(CCKeyboard* pKeyboard)
{
    if (pKeyboard->getKey() == 123) // left
    {
        leftDown = false;
    }
    if (pKeyboard->getKey() == 124) // right
    {
        rightDown = false;
    }
    if (pKeyboard->getKey() == 126) // up
    {
        upDown = false;
    }
    if (pKeyboard->getKey() == 125) // down
    {
        downDown = false;
    }
    
    if (pKeyboard->getKey() == 0) // left
    {
        aDown = false;
    }
    if (pKeyboard->getKey() == 2) // right
    {
        dDown = false;
    }
    if (pKeyboard->getKey() == 13) // up
    {
        wDown = false;
    }
    if (pKeyboard->getKey() == 1) // down
    {
        sDown = false;
    }
}


void HelloWorld::update(float dt)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	if(GetAsyncKeyState(VK_UP) & SHIFTED)
      {  
           CCLog("up (up)");
		   upDown = true;
      }
	else
	{
		upDown = false;
	}


	if(GetAsyncKeyState(VK_DOWN) & SHIFTED)  
      {  
           CCLog("down (up)");
		   downDown = true;
      }
	else
	{
		downDown = false;
	}
	if(GetAsyncKeyState(VK_LEFT) & SHIFTED)  
      {  
           //CCLog("down (up)");
		   leftDown = true;
      }
	else
	{
		leftDown = false;
	}
	if(GetAsyncKeyState(VK_RIGHT) & SHIFTED)  
      {  
           //CCLog("down (up)");
		   rightDown = true;
      }
	else
	{
		rightDown = false;
	}
#endif
    
    const float speed = 1.0;

    if (leftDown) // left
    {
        this->player1->velocity.x -= speed;
    }
    if (rightDown) // right
    {
        this->player1->velocity.x += speed;
    }
    if (upDown) // up
    {
        this->player1->velocity.y += speed;
    }
    if (downDown) // down
    {
        this->player1->velocity.y -= speed;
    }
    this->player1->update(dt);
    
	//upDown = false;
	//downDown = false;
    /*
    if (this->player2)
    {
        if (aDown) // left
        {
            this->player2->velocity.x -= speed;
        }
        if (dDown) // right
        {
            this->player2->velocity.x += speed;
        }
        if (wDown) // up
        {
            this->player2->velocity.y += speed;
        }
        if (sDown) // down
        {
            this->player2->velocity.y -= speed;
        }
        this->player2->update(dt);
    }
	*/
    
    if (this->line)
    {
        this->line->point1 = this->player1->getPosition();
        this->line->point2 = this->player2->getPosition();
        this->line->update(dt);
    }
    
    if (this->baddy)
    {
        this->baddy->update(dt);
    }
    
    if (this->blocks && !this->player1->hasWon)
    {
        CCObject *block = NULL;
        CCARRAY_FOREACH(this->blocks, block)
        {
            block->update(dt);
//            ((Block*)block)->update(dt);
            
            if (((Block*)block)->type() == TYPE_PASSABLEBLOCK)
            {
                continue;
            }
            if (((Block*)block)->type() == TYPE_COLLECTABLEBLOCK)
            {
                bool inside = ((Block*)block)->isPointInside(this->player1->getPosition());
                
                if (inside)
                {
                    this->player1->playWinAnimation();
                    
                    continue;
                }
            }
            
            bool hasIntersection = false;
            for (int i = 0; i < 4; ++i)
            {
                CCPoint point = ccp(((Block*)block)->points[i].x + ((Block*)block)->getPosition().x, ((Block*)block)->points[i].y + ((Block*)block)->getPosition().y);
                int nextIndex = i >= 3 ? 0 : i+1;
                CCPoint nextPoint = ccp(((Block*)block)->points[nextIndex].x + ((Block*)block)->getPosition().x, ((Block*)block)->points[nextIndex].y + ((Block*)block)->getPosition().y);
                
                CCPoint oldPlayerPos = this->player1->pastLocations[this->player1->pastLocationLastIndex];
                CCPoint curPlayerPos = this->player1->getPosition();
                
                float interX, interY;
                hasIntersection = this->lineIntersection(point, nextPoint
                                                  , oldPlayerPos, curPlayerPos
                                                  , &interX, &interY);
                
                if (hasIntersection)
                {
                    CCPoint normal = ((Block*)block)->normals[i];
                    CCPoint newPos = ccp(interX + normal.x, interY + normal.y);
                    this->player1->setPosition(newPos);


                    
                    this->player1->velocity = CCPointZero;
                }
            }
            
            if (hasIntersection)
            {
//                break;
            }
            
            if (((Block*)block)->type() == TYPE_MOVINGBLOCK)
            {
                if (((MovingBlock*)block)->smashFrame)
                {
                    bool inside = ((Block*)block)->isPointInside(this->player1->getPosition());
                    
                    if (inside)
                    {
                        this->player1->setPosition(this->startPos);
                        for (int i = 0; i < this->player1->pastLocationSize; ++i)
                        {
                            this->player1->pastLocations[i] = this->startPos;
                        }
                        this->player1->playStartAnimation();
                    }
                }
            }
        }
    }
    
    int nextLevel = -1;
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    if (this->exits[EXIT_TOP] >= 0 && this->player1->getPosition().y > size.height)
    {
        nextLevel = this->exits[EXIT_TOP];
        this->startPos = STARTPOINT_FROM_TOP;
    }
    else if (this->exits[EXIT_BOTTOM] >= 0 && this->player1->getPosition().y < 0)
    {
        nextLevel = this->exits[EXIT_BOTTOM];
        this->startPos = STARTPOINT_FROM_BOTTOM;
    }
    else if (this->exits[EXIT_LEFT] >= 0 && this->player1->getPosition().x < 0)
    {
        nextLevel = this->exits[EXIT_LEFT];
        this->startPos = STARTPOINT_FROM_LEFT;
    }
    else if (this->exits[EXIT_RIGHT] >= 0 && this->player1->getPosition().x > size.width)
    {
        nextLevel = this->exits[EXIT_RIGHT];
        this->startPos = STARTPOINT_FROM_RIGHT;
    }
    
    if (nextLevel >= 0)
    {
        this->player1->setPosition(this->startPos);
        for (int i = 0; i < this->player1->pastLocationSize; ++i)
        {
            this->player1->pastLocations[i] = this->startPos;
        }
        
        if (nextLevel != this->currentLevel)
        {
            CCObject *block = NULL;
            CCARRAY_FOREACH(this->blocks, block)
            {
                ((CCNode*)block)->removeFromParent();
            }
            
            this->currentLevel = nextLevel;
            
            this->levelManager->setupLevel(this->currentLevel, this->blocks, this->exits);
            block = NULL;
            CCARRAY_FOREACH(this->blocks, block)
            {
                this->addChild((CCNode*)block);
            }
        }
        
    }
    
    
    
}

bool HelloWorld::lineIntersection(CCPoint point1a, CCPoint point1b, CCPoint point2a, CCPoint point2b, float *intersectingPointX, float *intersectingPointY)
{
    double A1 = point1b.y - point1a.y;
    double B1 = point1a.x - point1b.x;
    double C1 = A1 * point1a.x + B1 * point1a.y;
    
    double A2 = point2b.y - point2a.y;
    double B2 = point2a.x - point2b.x;
    double C2 = A2 * point2a.x + B2 * point2a.y;
    
    double det = A1*B2 - A2*B1;
    
    double x, y;
    if (det == 0)
    {
        return false;
    }
    else
    {
        x = (B2*C1 - B1*C2)/det;
        y = (A1*C2 - A2*C1)/det;
    }
    
    bool onLineX1 = MIN(point1a.x, point1b.x) <= x + TOLL && x - TOLL <= MAX(point1a.x, point1b.x);
    bool onLineY1 = MIN(point1a.y, point1b.y) <= y + TOLL && y - TOLL <= MAX(point1a.y, point1b.y);
    bool onLineX2 = MIN(point2a.x, point2b.x) <= x + TOLL && x - TOLL <= MAX(point2a.x, point2b.x);
    bool onLineY2 = MIN(point2a.y, point2b.y) <= y + TOLL && y - TOLL <= MAX(point2a.y, point2b.y);
    
    *intersectingPointX = x;
    *intersectingPointY = y;
    
    if (onLineX1 && onLineY1 && onLineX2 && onLineY2)
    {
        return true;
    }
    return false;
}

float HelloWorld::wrap(float value, float max, float min)
{
    value -= min;
    max -= min;
    if (max == 0)
        return min;
    
    value = fmod(value, max);
    value += min;
    while (value < min)
    {
        value += max;
    }
    
    return value;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


