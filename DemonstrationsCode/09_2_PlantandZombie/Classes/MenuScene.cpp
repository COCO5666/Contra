//
//  MenuScene.cpp
//  twenty
//
//  Created by student on 15-6-13.
//
//

#include "MenuScene.h"
Scene  * MenuScene::createScene()
{
    auto  menuSene = Scene::create();
    auto menuLayer=MenuScene::create();//生成layer，需要重写int方法
    menuSene->addChild(menuLayer);
    return menuSene;
}
bool MenuScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    auto visibleSize=Director::getInstance()->getWinSize();
    auto origin=Director::getInstance()->getVisibleOrigin();
    auto sprite=Sprite::create("main_background.png");
    sprite->setPosition(Vec2(visibleSize.width/2+origin.x, visibleSize.height/2+origin.y));
    this->addChild(sprite,0);
    
    //成就
    auto accomplishItem=MenuItemImage::create("chengjiu.png","chengjiu1.png");
    accomplishItem->setPosition(40,40);
    accomplishItem->setScale(0.5);
    
    auto riskModeItem=MenuItemImage::create("select11.png", "select10.png");
    riskModeItem->setPosition(345, 255);
    riskModeItem->setScale(0.95);
    auto miniModeItem=MenuItemImage::create("select21.png", "select20.png");
    miniModeItem->setPosition(340,205);
    miniModeItem->setScale(0.9);
    auto  puzzleModeItem=MenuItemImage::create("select31.png", "select30.png");
    puzzleModeItem->setPosition(335,160);
    puzzleModeItem->setScale(0.86);
    auto liveModeItem=MenuItemImage::create("select41.png", "select40.png");
    liveModeItem->setPosition(332, 120);
    liveModeItem->setScale(0.84);
    
    auto mapItem=MenuItemImage::create("shop0.png", "shop1.png");
    mapItem->setPosition(280, 30);
    mapItem->setScale(0.6);
    auto shopItem=MenuItemImage::create("SelectorScreen_AlmanacHighlight.png", "SelectorScreen_Almanac.png");
    shopItem->setPosition(200, 50);
    shopItem->setScale(0.4);
    
    auto menu=Menu::create(shopItem,mapItem,accomplishItem,riskModeItem,miniModeItem,puzzleModeItem,liveModeItem,NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu,1);
    
    auto label=Label::createWithTTF("Welcome to the game world！", "fonts/Marker Felt.ttf", 30);
    //auto label=Label::createWithTTF("欢迎进入游戏世界！","fonts/HKYuanMini.ttf", 20);
    label->setWidth(400);
    label->setPosition(Vec2(240,160));
    this->addChild(label);
    return true;
}