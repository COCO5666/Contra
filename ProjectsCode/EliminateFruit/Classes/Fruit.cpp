//
//  Fruit.cpp
//  LoveEveryDayToElimate
//
//  Created by xingweihao456 on 15-7-20.
//
//

#include "Fruit.h"
/*
 Apple=1,
 Banner,
 Cherry,
 CyanGrape,
 KiwiFruit,
 Origin,
 */
ParticleSun * Fruit::setFlower(int n)
{
    char name[100];
    switch (n) {
        case Fruit::Type::Apple:
            sprintf(name, "Apple.png");
            break;
        case Fruit::Type::Banner:
            sprintf(name, "Banner.png");
            break;
        case Fruit::Type::Cherry:
            sprintf(name, "Cherry.png");
            break;
        case Fruit::Type::CyanGrape:
            sprintf(name, "CyanGrape.png");
            break;
        case Fruit::Type::KiwiFruit:
            sprintf(name, "KiwiFruit.png");
            break;
        case Fruit::Type::Origin:
            sprintf(name, "Origin.png");
            break;
    }
    auto spFlower=ParticleSun::createWithTotalParticles(200);
    spFlower->setTexture(Director::getInstance()->getTextureCache()->addImage(name));
    spFlower->setDuration(0.1);
    spFlower->setLife(0.1);
    //spFlower->setAngle(90);
    //spFlower->setAngleVar(360);
    return spFlower;
}