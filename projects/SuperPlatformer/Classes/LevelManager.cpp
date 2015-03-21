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

#include "LevelManager.h"
#include "Block.h"
#include "MovingBlock.h"
#include "PassableBlock.h"
#include "CollectableBlock.h"

USING_NS_CC;

void setUpLevel(cocos2d::CCArray *blocks, int *exits);


void LevelManager::setupLevel(int index, cocos2d::CCArray *blocks, int *exits)
{
    blocks->removeAllObjects();
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    switch (index) {
        case 0:
        {
            // blocks
            for (int i = 0; i < 2; ++i)
            {
                Block *block = new Block();
                block->init(300, 20, CCPointMake(100 + (i * 220), 100 + (i * 100)));
                blocks->addObject(block);
            }
            
            exits[EXIT_TOP] = 1;
            exits[EXIT_BOTTOM] = -1;
            exits[EXIT_LEFT] = -1;
            exits[EXIT_RIGHT] = -1;
        }
            break;
        case 1:
        {
            {
                MovingBlock *block = new MovingBlock();
                block->init(100, 20, ccp(100, 100), ccp(60, 100), 2.0, 0.0);
                blocks->addObject(block);
            }
            {
                Block *block = new Block();
                block->init(500, 20, CCPointMake(300, 100));
                blocks->addObject(block);
            }
            
            {
                MovingBlock *block = new MovingBlock();
                block->init(100, 20, ccp(size.width - 100, 200), ccp(size.width - 60, 200), 2.0, 0.0);
                blocks->addObject(block);
            }
            {
                Block *block = new Block();
                block->init(500, 20, CCPointMake(size.width - 300, 200));
                blocks->addObject(block);
            }
            
            
            exits[EXIT_TOP] = 2;
            exits[EXIT_BOTTOM] = 0;
            exits[EXIT_LEFT] = -1;
            exits[EXIT_RIGHT] = -1;
        }
            break;
        case 2:
        {
            // blocks
            {
                Block *block = new Block();
                block->init(400, 20, CCPointMake(200, 110));
                blocks->addObject(block);
            }
            
            for (int i = 0; i < 4; ++i)
            {
                MovingBlock *movingBlock = new MovingBlock();
                movingBlock->init(20, 100, ccp(200 + (i * 40), 200), ccp(200 + (i * 40), 160), 2.0, (i * 0.5));
                blocks->addObject(movingBlock);
                
                Block *block = new Block();
                block->init(20, 200, ccp(200 + (i * 40), 270));
                blocks->addObject(block);
            }
            
            exits[EXIT_TOP] = -1;
            exits[EXIT_BOTTOM] = 1;
            exits[EXIT_LEFT] = 3;
            exits[EXIT_RIGHT] = -1;
        }
            break;
        case 3:
        {
            // blocks
            {
                Block *block = new Block();
                block->init(340, 20, CCPointMake(400, 110));
                blocks->addObject(block);
            }
            {
                Block *block = new Block();
                block->init(20, 120, CCPointMake(size.width/2, size.height/2));
                blocks->addObject(block);
            }
            {
                Block *block = new Block();
                block->init(300, 20, CCPointMake(100, 210));
                blocks->addObject(block);
            }
            
            exits[EXIT_TOP] = 4;
            exits[EXIT_BOTTOM] = 10;
            exits[EXIT_LEFT] = 8;
            exits[EXIT_RIGHT] = 2;
        }
            break;
        case 4:
        {
            // blocks
            for (int i = 0; i < 2; ++i)
            {
                MovingBlock *movingBlockLeft = new MovingBlock();
                movingBlockLeft->init(100, 20, ccp(size.width/2 - 80, 200 + (i * 40)), ccp(size.width/2 - 40, 200 + (i * 40)), 1.5, i * 0.2);
                blocks->addObject(movingBlockLeft);

                Block *blockLeft = new Block();
                blockLeft->init(150, 20, CCPointMake(size.width/2 - 160, 200 + (i * 40)));
                blocks->addObject(blockLeft);
                
                MovingBlock *movingBlockRight = new MovingBlock();
                movingBlockRight->init(100, 20, ccp(size.width/2 + 80, 200 + (i * 40)), ccp(size.width/2 + 40, 200 + (i * 40)), 1.5, i * 0.2);
                blocks->addObject(movingBlockRight);
                
                Block *blockRight = new Block();
                blockRight->init(150, 20, CCPointMake(size.width/2 + 160, 200 + (i * 40)));
                blocks->addObject(blockRight);
            }
            
            
            exits[EXIT_TOP] = 5;
            exits[EXIT_BOTTOM] = 3;
            exits[EXIT_LEFT] = -1;
            exits[EXIT_RIGHT] = -1;
        }
            break;
        case 5:
        {
            // blocks
            for (int i = 0; i < 8; ++i)
            {
                MovingBlock *movingBlockLeft = new MovingBlock();
                movingBlockLeft->init(100, 20, ccp(size.width/2 - 80, 50 + (i * 40)), ccp(size.width/2 - 40, 50 + (i * 40)), 1.0, i * 0.2);
                blocks->addObject(movingBlockLeft);
                
                Block *blockLeft = new Block();
                blockLeft->init(150, 20, CCPointMake(size.width/2 - 160, 50 + (i * 40)));
                blocks->addObject(blockLeft);
                
                MovingBlock *movingBlockRight = new MovingBlock();
                movingBlockRight->init(100, 20, ccp(size.width/2 + 80, 50 + (i * 40)), ccp(size.width/2 + 40, 50 + (i * 40)), 1.0, i * 0.2);
                blocks->addObject(movingBlockRight);
                
                Block *blockRight = new Block();
                blockRight->init(150, 20, CCPointMake(size.width/2 + 160, 50 + (i * 40)));
                blocks->addObject(blockRight);
            }
            
            
            exits[EXIT_TOP] = 6;
            exits[EXIT_BOTTOM] = 4;
            exits[EXIT_LEFT] = -1;
            exits[EXIT_RIGHT] = -1;
        }
            break;
        case 6:
        {
            // blocks
            {
                MovingBlock *movingBlockLeft = new MovingBlock();
                movingBlockLeft->init(200, 100, ccp(size.width/2 - 40, 150), ccp(size.width/2 + 100 - 40, 150), 1.5, 0.0);
                blocks->addObject(movingBlockLeft);
                
                Block *blockLeft = new Block();
                blockLeft->init(270, 100, CCPointMake(size.width/2 - 100, 150));
                blocks->addObject(blockLeft);
            }
            {
                Block *block = new Block();
                block->init(20, size.height, CCPointMake(400, size.height/2));
                blocks->addObject(block);
            }
            
            exits[EXIT_TOP] = 7;
            exits[EXIT_BOTTOM] = 5;
            exits[EXIT_LEFT] = -1;
            exits[EXIT_RIGHT] = -1;
        }
            break;
        case 7:
        {
            // blocks
            
            {
                MovingBlock *movingBlockLeft = new MovingBlock();
                movingBlockLeft->init(100, 20, ccp(size.width*0.1 - 80, 50), ccp(size.width*0.1 - 40, 50), 1.0, 0.0);
                blocks->addObject(movingBlockLeft);
                
//                Block *blockLeft = new Block();
//                blockLeft->init(150, 20, CCPointMake(size.width*0.1 - 160, 50));
//                blocks->addObject(blockLeft);
                
                MovingBlock *movingBlockRight = new MovingBlock();
                movingBlockRight->init(100, 20, ccp(size.width*0.1 + 80, 50 ), ccp(size.width*0.1 + 40, 50), 1.0, 0.0);
                blocks->addObject(movingBlockRight);
                
                Block *blockRight = new Block();
                blockRight->init(380, 20, CCPointMake(size.width*0.6, 50));
                blocks->addObject(blockRight);
            }
            
            {
                MovingBlock *movingBlock = new MovingBlock();
                movingBlock->init(100, 20, ccp(size.width - 100, 100), ccp(size.width - 60, 100), 2.0, 0.0);
                blocks->addObject(movingBlock);
            
                Block *block = new Block();
                block->init(500, 20, CCPointMake(size.width - 300, 100));
                blocks->addObject(block);
            }
            
            
            {
                MovingBlock *movingBlock = new MovingBlock();
                movingBlock->init(100, 20, ccp(100, 150), ccp(60, 150), 2.0, 0.0);
                blocks->addObject(movingBlock);
            
                Block *block = new Block();
                block->init(500, 20, CCPointMake(300, 150));
                blocks->addObject(block);
            }
            
            for (int i = 0; i < 4; ++i)
            {
                MovingBlock *movingBlock = new MovingBlock();
                movingBlock->init(20, 100, ccp(100 + (i * 40), 240), ccp(100 + (i * 40), 200), 2.0, (i * 0.5));
                blocks->addObject(movingBlock);
                
                Block *block = new Block();
                block->init(20, 200, ccp(100 + (i * 40), 310));
                blocks->addObject(block);
            }
            
//            for (int i = 0; i < 4; ++i)
            {
                MovingBlock *movingBlock = new MovingBlock();
                movingBlock->init(100, 20, ccp(size.width/2 + 140, 200), ccp(size.width/2 + 200, 200), 2.0, 0.0);
                blocks->addObject(movingBlock);
                
                Block *block = new Block();
                block->init(180, 20, CCPointMake(size.width/2 + 60, 200));
                blocks->addObject(block);
            }
            
            {
                MovingBlock *movingBlock = new MovingBlock();
                movingBlock->init(100, 20, ccp(size.width/2 + 60, 240), ccp(size.width/2 + 40, 240), 2.0, 0.5);
                blocks->addObject(movingBlock);
                
                Block *block = new Block();
                block->init(180, 20, CCPointMake(size.width/2 + 140, 240));
                blocks->addObject(block);
            }
            
            {
                MovingBlock *movingBlock = new MovingBlock();
                movingBlock->init(100, 20, ccp(size.width/2 + 140, 280), ccp(size.width/2 + 200, 280), 2.0, 1.0);
                blocks->addObject(movingBlock);
                
                Block *block = new Block();
                block->init(180, 20, CCPointMake(size.width/2 + 60, 280));
                blocks->addObject(block);
            }
            
            exits[EXIT_TOP] = 8;
            exits[EXIT_BOTTOM] = 6;
            exits[EXIT_LEFT] = -1;
            exits[EXIT_RIGHT] = -1;
        }
            break;
        case 8:
        {
            {
                Block *block = new Block();
                block->init(20, size.height * 0.8, CCPointMake(size.width/2, size.height/2));
                blocks->addObject(block);
            }
            
            // left half
            for (int i = 0; i < 6; ++i)
            {
                float posX = size.width * 0.25 + (i%2 == 0 ? 20 : -20);
                float posY = 42 + (40 * i);
                
                Block *block = new Block();
                block->init(size.width*0.40, 20, CCPointMake(posX, posY));
                blocks->addObject(block);
                
                for (int j = 0; j < 4 && i < 5; ++j)
                {
                    float posXMoving = posX + ((j-2) * 40) + (i%2 == 0 ? 0 : 40);
                    float posYMoving = posY;
                    
                    MovingBlock *movingBlock = new MovingBlock();
                    movingBlock->init(20, 20, ccp(posXMoving, posYMoving), ccp(posXMoving, posYMoving + 20), 1.0, (i * 0.1) + (j * 0.1));
                    blocks->addObject(movingBlock);
                }
            }
            
            // bottom right
            {
                Block *blockLower = new Block();
                blockLower->init(size.width*0.5, 20, CCPointMake(size.width*0.75 + 20, 42));
                blocks->addObject(blockLower);
                
                for (int i = 0; i < 5; ++i)
                {
                    Block *block = new Block();
                    block->init(20, 50, CCPointMake(size.width/2 + 30 + (i * 40), size.height * 0.27 + (i%2 == 0 ? -20 : 20)));
                    blocks->addObject(block);
                }
                
                Block *blockUpper = new Block();
                blockUpper->init(size.width*0.4, 20, CCPointMake(size.width*0.75 - 20, size.height * 0.4));
                blocks->addObject(blockUpper);
            }
            
            // top right
            for (int i = 0; i < 3; ++i)
            {
                float posX = size.width * 0.75 + (i%2 == 0 ? 20 : -20);
                float posY = size.height/2 + 25 + (40 * i);
                
                Block *block = new Block();
                block->init(size.width*0.4, 20, CCPointMake(posX, posY));
                blocks->addObject(block);
                
                if (i > 0)
                {
                    MovingBlock *movingBlock = new MovingBlock();
                    movingBlock->init(153, 20, ccp(size.width * 0.75 + (i%2 == 0 ? 0 : -1), posY), ccp(size.width * 0.75 + (i%2 == 0 ? 0 : -1), posY - 20), 2.0, 0.0);
                    blocks->addObject(movingBlock);
                }
            }
            
            exits[EXIT_TOP] = 9;
            exits[EXIT_BOTTOM] = 7;
            exits[EXIT_LEFT] = -1;
            exits[EXIT_RIGHT] = 3;
        }
            break;
        case 9:
        {
            Block *blockHora = new Block();
            blockHora->init(size.width*0.75, 20, CCPointMake(size.width*0.25, 100));
            blocks->addObject(blockHora);
            
            Block *blockVert = new Block();
            blockVert->init(20, size.height*0.75, CCPointMake(size.width*0.63, 210));
            blocks->addObject(blockVert);
            
            exits[EXIT_TOP] = 13;
            exits[EXIT_BOTTOM] = 8;
            exits[EXIT_LEFT] = 12;
            exits[EXIT_RIGHT] = 12;
        }
            break;
        case 10:
        {
            for (int i = 0; i < 12; ++i)
            {
                if (i%4 != 0)
                {
                    MovingBlock *movingBlockLeft = new MovingBlock();
                    movingBlockLeft->init(100, 20, ccp(size.width - 80, 50 + (i * 20)), ccp(size.width - 40, 50 + (i * 20)), 1.3, i * 0.2);
                    blocks->addObject(movingBlockLeft);
                }
                
                Block *blockLeft = new Block();
                blockLeft->init(500, 20, CCPointMake(size.width/2 - 80, 50 + (i * 20)));
                blocks->addObject(blockLeft);
            }
            
            exits[EXIT_TOP] = 3;
            exits[EXIT_BOTTOM] = 11;
            exits[EXIT_LEFT] = -1;
            exits[EXIT_RIGHT] = -1;
        }
            break;
        case 11:
        {
            Block *block = new Block();
            block->init(size.width*0.8, 20, CCPointMake(size.width*0.6, 200));
            blocks->addObject(block);
            
            for (int i = 0; i < 3; ++i)
            {
                MovingBlock *movingBlockTop = new MovingBlock();
                movingBlockTop->init(20, 50, ccp(106 + (i * 40), 150), ccp(106 + (i * 40), 150 - 50), 1.0, i%2 == 0 ? 0.0 : 0.5);
                blocks->addObject(movingBlockTop);
                
                Block *blockTop = new Block();
                blockTop->init(20, 80, ccp(106 + (i * 40), 160));
                blocks->addObject(blockTop);
            
                MovingBlock *movingBlockBottom = new MovingBlock();
                movingBlockBottom->init(20, 50, ccp(106 + (i * 40), 50), ccp(106 + (i * 40), 50 + 50), 1.0, i%2 == 0 ? 0.5 : 0.0);
                blocks->addObject(movingBlockBottom);
                
                Block *blockBottom = new Block();
                blockBottom->init(20, 80, ccp(106 + (i * 40), 40));
                blocks->addObject(blockBottom);
            }
            
            exits[EXIT_TOP] = 10;
            exits[EXIT_BOTTOM] = 12;
            exits[EXIT_LEFT] = -1;
            exits[EXIT_RIGHT] = -1;
        }
            break;
        case 12:
        {
            Block *block = new Block();
            block->init(100, 100, CCPointMake(size.width*0.5, size.height*0.5));
            blocks->addObject(block);
            
            exits[EXIT_TOP] = 11;
            exits[EXIT_BOTTOM] = -1;
            exits[EXIT_LEFT] = 9;
            exits[EXIT_RIGHT] = 9;
        }
            break;
        case 13:
        {
            for (int i = 0; i < 10; ++i)
            {
                MovingBlock *movingBlockBottom = new MovingBlock();
                movingBlockBottom->init(40, 20, ccp(size.width/2 - 30, 40 + (i * 20)), ccp(size.width/2, 40 + (i * 20)), 1.0, ((10-i) * -0.1));
                blocks->addObject(movingBlockBottom);
            }
            {
                Block *block = new Block();
                block->init(40, 240, CCPointMake(size.width/2 - 30, 120));
                blocks->addObject(block);
            }
            {
                Block *block = new Block();
                block->init(220, 20, CCPointMake(size.width*0.25, 220));
                blocks->addObject(block);
            }
            
            {
                Block *block = new Block();
                block->init(220, size.height, CCPointMake(size.width*0.75 + 5, size.height/2));
                blocks->addObject(block);
            }
            {
                MovingBlock *movingBlockBottom = new MovingBlock();
                movingBlockBottom->init(50, 200, ccp(size.width*0.5 + 40, 130), ccp(size.width*0.5, 130), 2.0, 0.0);
                blocks->addObject(movingBlockBottom);
            }
            
            exits[EXIT_TOP] = 14;
            exits[EXIT_BOTTOM] = 9;
            exits[EXIT_LEFT] = -1;
            exits[EXIT_RIGHT] = -1;
        }
            break;
        case 14:
        {
            {
                MovingBlock *movingBlockBottom = new MovingBlock();
                movingBlockBottom->init(size.width, 200, ccp(size.width + 40, size.height/2), ccp(size.width*0.5, size.height/2), 2.0, 0.0);
                blocks->addObject(movingBlockBottom);
            }
            
            exits[EXIT_TOP] = 15;
            exits[EXIT_BOTTOM] = 13;
            exits[EXIT_LEFT] = -1;
            exits[EXIT_RIGHT] = -1;
        }
            break;
        case 15:
        {
            float gap = 43;
            {
                MovingBlock *movingBlockBottom = new MovingBlock();
                movingBlockBottom->init(size.width, 80, ccp(-40, size.height/2 - gap), ccp(size.width*0.5, size.height/2 - gap), 1.0, -0.5);
                blocks->addObject(movingBlockBottom);
            }
            
            {
                MovingBlock *movingBlockBottom = new MovingBlock();
                movingBlockBottom->init(size.width, 80, ccp(-40, size.height/2 + gap), ccp(size.width*0.5, size.height/2 + gap), 1.0, 0.0);
                blocks->addObject(movingBlockBottom);
            }
            
            exits[EXIT_TOP] = 16;
            exits[EXIT_BOTTOM] = 14;
            exits[EXIT_LEFT] = -1;
            exits[EXIT_RIGHT] = -1;
        }
            break;
        case 16:
        {
            {
                Block *blockLeft = new Block();
                blockLeft->init((size.width/2) - 10, 100, CCPointMake((size.width*0.25) - 10, 0));
                blocks->addObject(blockLeft);
                
                Block *blockRight = new Block();
                blockRight->init((size.width/2) - 10, 100, CCPointMake((size.width*0.75) + 10, 0));
                blocks->addObject(blockRight);
            }
            {
                Block *block = new Block();
                block->init(size.width, 20, CCPointMake(size.width*0.5 - 40, 80));
                blocks->addObject(block);
            }
            {
                MovingBlock *movingBlockBottom = new MovingBlock();
                movingBlockBottom->init(size.width, 20, ccp(size.width*-0.5 -40, 60), ccp(size.width*0.5, 60), 2.0, 0.0);
                blocks->addObject(movingBlockBottom);
            }
            
            {
                Block *block = new Block();
                block->init(20, size.height, CCPointMake(size.width - 50, size.height/2 + 80));
                blocks->addObject(block);
            }
            
            exits[EXIT_TOP] = 17;
            exits[EXIT_BOTTOM] = 15;
            exits[EXIT_LEFT] = 16;
            exits[EXIT_RIGHT] = 16;
        }
            break;
        case 17:
        {
            for (int i = 0; i < 3; ++i)
            {
                Block *block = new Block();
                block->init(size.width
                            , 30
                            , CCPointMake(size.width/2 + (i%2==0 ? -40 : 40)
                                          , 80 + (i * 80)
                           ));
                blocks->addObject(block);
            }
            
            {
                MovingBlock *movingBlockBottom = new MovingBlock();
                movingBlockBottom->init(160, size.height, ccp(size.width*0.75, size.height*1.5), ccp(size.width*0.75, size.height*0.5), 1.8, 0.0);
                blocks->addObject(movingBlockBottom);
            }
            {
                MovingBlock *movingBlockBottom = new MovingBlock();
                movingBlockBottom->init(160, size.height, ccp(size.width*0.25, size.height*-0.5), ccp(size.width*0.25, size.height*0.5), 1.7, 0.0);
                blocks->addObject(movingBlockBottom);
            }
            
            exits[EXIT_TOP] = 18;
            exits[EXIT_BOTTOM] = 16;
            exits[EXIT_LEFT] = -1;
            exits[EXIT_RIGHT] = -1;
        }
            break;
        case 18:
        {
            {
                Block *blockLeft = new Block();
                blockLeft->init((size.width/2) - 10, size.height, CCPointMake((size.width*0.25) - 10, size.height/2));
                blocks->addObject(blockLeft);
                
                Block *blockRight = new Block();
                blockRight->init((size.width/2) - 10, size.height, CCPointMake((size.width*0.75) + 10, size.height/2));
                blocks->addObject(blockRight);
            }
            
            exits[EXIT_TOP] = 19;
            exits[EXIT_BOTTOM] = 17;
            exits[EXIT_LEFT] = -1;
            exits[EXIT_RIGHT] = -1;
        }
            break;
        case 19:
        {
            {
                Block *blockLeft = new Block();
                blockLeft->init((size.width/2) - 10, size.height, CCPointMake((size.width*0.25) - 4, size.height/2));
                blocks->addObject(blockLeft);
                
                Block *blockRight = new Block();
                blockRight->init((size.width/2) - 10, size.height, CCPointMake((size.width*0.75) + 4, size.height/2));
                blocks->addObject(blockRight);
            }
            
            exits[EXIT_TOP] = 20;
            exits[EXIT_BOTTOM] = 18;
            exits[EXIT_LEFT] = -1;
            exits[EXIT_RIGHT] = -1;
        }
            break;
        case 20:
        {
            {
                Block *blockLeft = new Block();
                blockLeft->init((size.width/2) - 10, size.height, CCPointMake((size.width*0.25) + 2, size.height/2));
                blocks->addObject(blockLeft);
                
                Block *blockRight = new Block();
                blockRight->init((size.width/2) - 10, size.height, CCPointMake((size.width*0.75) - 2, size.height/2));
                blocks->addObject(blockRight);
            }
            
            exits[EXIT_TOP] = 21;
            exits[EXIT_BOTTOM] = 19;
            exits[EXIT_LEFT] = -1;
            exits[EXIT_RIGHT] = -1;
        }
            break;
        case 21:
        {
            float colourIncrease = 0.05;
            for (int i = 0; i < 15; ++i)
            {
                float colourComponent = 1.0 - (i * colourIncrease);
                PassableBlock *block = new PassableBlock();
                block->init(200 - (i* 10), 200 - (i* 10), CCPointMake((size.width*0.5), (size.height*0.5)), colourComponent, colourComponent, colourComponent);
                blocks->addObject(block);
            }
            
            CollectableBlock *collectable = new CollectableBlock();
            collectable->init(CCPointMake((size.width*0.5), (size.height*0.5)), "potato.png");
            blocks->addObject(collectable);
            
            exits[EXIT_TOP] = -1;
            exits[EXIT_BOTTOM] = 20;
            exits[EXIT_LEFT] = -1;
            exits[EXIT_RIGHT] = -1;
        }
            break;
        default:
            break;
    }
    
    setUpLevel(blocks, exits);
    
}

void setUpLevel(cocos2d::CCArray *blocks, int *exits)
{
    
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    // bottom
    if (exits[EXIT_BOTTOM] >= 0)
    {
        Block *blockLeft = new Block();
        blockLeft->init((size.width/2) - 10, 20, CCPointMake((size.width*0.25) - 10, 0));
        blocks->addObject(blockLeft);
        
        Block *blockRight = new Block();
        blockRight->init((size.width/2) - 10, 20, CCPointMake((size.width*0.75) + 10, 0));
        blocks->addObject(blockRight);
    }
    else
    {
        Block *block = new Block();
        block->init(size.width, 20, CCPointMake(size.width/2, 0));
        blocks->addObject(block);
    }
    
    // top
    if (exits[EXIT_TOP] >= 0)
    {
        Block *blockLeft = new Block();
        blockLeft->init((size.width/2) - 10, 20, CCPointMake((size.width*0.25) - 10, size.height));
        blocks->addObject(blockLeft);
        
        Block *blockRight = new Block();
        blockRight->init((size.width/2) - 10, 20, CCPointMake((size.width*0.75) + 10, size.height));
        blocks->addObject(blockRight);
    }
    else
    {
        Block *blockRight = new Block();
        blockRight->init(size.width, 20, CCPointMake(size.width/2, size.height));
        blocks->addObject(blockRight);
    }
    
    // left
    if (exits[EXIT_LEFT] >= 0)
    {
        Block *blockTop = new Block();
        blockTop->init(20, (size.height/2) - 10, CCPointMake(0, (size.height*0.25) - 10));
        blocks->addObject(blockTop);
        
        Block *blockBottom = new Block();
        blockBottom->init(20, (size.height/2) - 10, CCPointMake(0, (size.height*0.75) + 10));
        blocks->addObject(blockBottom);
    }
    else
    {
        Block *block = new Block();
        block->init(20, size.height, CCPointMake(0, size.height/2));
        blocks->addObject(block);
    }
    
    // right
    if (exits[EXIT_RIGHT] >= 0)
    {
        Block *blockTop = new Block();
        blockTop->init(20, (size.height/2) - 10, CCPointMake(size.width, (size.height*0.25) - 10));
        blocks->addObject(blockTop);
        
        Block *blockBottom = new Block();
        blockBottom->init(20, (size.height/2) - 10, CCPointMake(size.width, (size.height*0.75) + 10));
        blocks->addObject(blockBottom);
    }
    else
    {
        Block *block = new Block();
        block->init(20, size.height, CCPointMake(size.width, size.height/2));
        blocks->addObject(block);
    }
}
