//
//  DataScoures.h
//  LoveEveryDayToElimate
//
//  Created by xingweihao456 on 15-7-20.
//
//

#ifndef __LoveEveryDayToElimate__DataScoures__
#define __LoveEveryDayToElimate__DataScoures__

#include <iostream>
using namespace std;
#include "cocos2d.h"
USING_NS_CC;
class DataScoures
{
public:
    string CheckPoint;
    int HightSocre;
    int PassTheScore;
    int Unclock;
};
class Json
{
private:
    Json();
public:
    vector<DataScoures*> datas;
   static Json* GetInstance();
public:
    void ParseJson();
    void ParseUpdateJson();
    void printDatas();
};
#endif /* defined(__LoveEveryDayToElimate__DataScoures__) */
