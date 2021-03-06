//
//  Bullet.cpp
//  a4
//
//  Created by student on 15-7-11.
//
//

#include "Bullet.h"
#include "ManagerBase.h"

bool Bullet::init()
{
    if (!Sprite::init())
    {
        return false;
    }
    return true;
}
//void Bullet::initBullet(char *bullet_name)
//{
//    auto spr_name=String::createWithFormat("%s",bullet_name);
//
//        
//    this->initWithFile(spr_name->getCString());
//}
//建议用c++11的新特性
void Bullet::initBullet( __String bullet_name)
{
    /*
     初始化图像文件，运行时如果它耗尽空间，容量将以33%的比例增加。
   　　使用TextureMgr加载文件。
     */
    this->initWithFile(bullet_name.getCString());
}

void Bullet::onEnterTransitionDidFinish()
{
    Sprite::onEnterTransitionDidFinish();
    scheduleUpdate();
}
void Bullet::onExit()
{
    unscheduleUpdate();
    Sprite::onExit();
}
void Bullet::update(float delta)
{
    this->setPositionY(this->getPositionY()+5);
    if (this->getPositionY()>Director::getInstance()->getWinSize().height)
    {
        this->removeFromParentAndCleanup(true);
        ManagerBase::getInstance()->remove_bullet_list(this);
    }
}