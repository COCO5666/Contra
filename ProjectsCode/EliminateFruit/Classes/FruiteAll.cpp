//
//  FruiteAll.cpp
//  LoveEveryDayToElimate
//
//  Created by xingweihao456 on 15-7-20.
//
//

#include "FruiteAll.h"
Apple::Apple()
{
    this->initWithFile("Apple.png");
    setFruitType();
}
void Apple::setFruitType()
{
    type=Fruit::Type::Apple;
}
Fruit::Type Apple::getFruitType()
{
    return type;
}
#pragma Banner
Banner::Banner()
{
    this->initWithFile("Banner.png");
    setFruitType();
}
void Banner::setFruitType()
{
    type=Fruit::Type::Banner;
}
Fruit::Type Banner::getFruitType()
{
    return type;
}
#pragma Cherry
Cherry::Cherry()
{
    this->initWithFile("Cherry.png");
    setFruitType();
}
void Cherry::setFruitType()
{
    type=Fruit::Type::Cherry;
}
Fruit::Type Cherry::getFruitType()
{
    return type;
}
#pragma CyanGrape
CyanGrape::CyanGrape()
{
    this->initWithFile("CyanGrape.png");
    setFruitType();
}
void CyanGrape::setFruitType()
{
    type=Fruit::Type::CyanGrape;
}
Fruit::Type CyanGrape::getFruitType()
{
    return type;
}
#pragma KiwiFruit

KiwiFruit::KiwiFruit()
{
    this->initWithFile("KiwiFruit.png");
    setFruitType();
}
void KiwiFruit::setFruitType()
{
    type=Fruit::Type::KiwiFruit;
}
Fruit::Type KiwiFruit::getFruitType()
{
    return type;
}

#pragma Origin
Origin::Origin()
{
    this->initWithFile("Origin.png");
    setFruitType();
}
void Origin::setFruitType()
{
    type=Fruit::Type::Origin;
}
Fruit::Type Origin::getFruitType()
{
    return type;
}
#pragma Strawberry
Strawberry::Strawberry()
{
    this->initWithFile("Strawberry.png");
    setFruitType();
}
void Strawberry::setFruitType()
{
    type=Fruit::Type::Strawberry;
}
Fruit::Type Strawberry::getFruitType()
{
    return type;
}
#pragma Watermelon
Watermelon::Watermelon()
{
    this->initWithFile("Watermelon.png");
    setFruitType();
}
void Watermelon::setFruitType()
{
    type=Fruit::Type::Watermelon;
}
Fruit::Type Watermelon::getFruitType()
{
    return type;
}










