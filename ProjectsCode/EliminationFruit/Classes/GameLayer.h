//
//  GameLayer.h
//  LoveEveryDayToElimate
//
//  Created by xingweihao456 on 15-7-20.
//
//

#ifndef __LoveEveryDayToElimate__GameLayer__
#define __LoveEveryDayToElimate__GameLayer__

#include "cocos2d.h"
USING_NS_CC;
class GameLayer : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameLayer);
};
#endif /* defined(__LoveEveryDayToElimate__GameLayer__) */
