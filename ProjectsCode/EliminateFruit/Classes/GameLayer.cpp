//
//  GameLayer.cpp
//  LoveEveryDayToElimate
//
//  Created by xingweihao456 on 15-7-20.
//
//

#include "GameLayer.h"
#include "FruiteManager.h"
Scene* GameLayer::createScene()
{
    auto scene = Scene::create();

    auto layer = GameLayer::create();

    scene->addChild(layer);
    
    return scene;
}

// on "init" you need to initialize your instance
bool GameLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    FruiteManager *fruit=new FruiteManager(this);
    return true;
}