//
//  SelectPlanePage.h
//  a4
//
//  Created by student on 15-7-26.
//
//

#ifndef __a4__SelectPlanePage__
#define __a4__SelectPlanePage__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class SelectPlanePage:public Node
{
public:
    static SelectPlanePage *create( int page);
    bool initLevelPage(int page);
    void menuStartCallback(Ref * pSender);
public:
    int page_;
};
#endif /* defined(__a4__SelectPlanePage__) */
