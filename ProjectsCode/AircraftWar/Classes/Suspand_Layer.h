//
//  Suspand_Layer.h
//  a4
//
//  Created by student on 15-7-12.
//
//

#ifndef __a4__Suspand_Layer__
#define __a4__Suspand_Layer__

#include <iostream>
#include <cocos2d.h>
USING_NS_CC;
class Suspand_Layer:public Layer
{
public:
    Suspand_Layer();
    ~Suspand_Layer();
public:
    virtual  bool init();
    CREATE_FUNC(Suspand_Layer);
public:
    void back_game(Ref *sender);
};
#endif /* defined(__a4__Suspand_Layer__) */
