//
//  WelcomeScene.h
//  twenty
//
//  Created by student on 15-6-13.
//
//

#ifndef __twenty__WelcomeScene__
#define __twenty__WelcomeScene__

#include <iostream>
#include <cocos2d.h>
USING_NS_CC;
class WelcomeScene:public Layer
{
public:
    static Scene * createScene();
    virtual bool init();
    void enterMenuScene();
    CREATE_FUNC(WelcomeScene);
    void loadChangeClick();
};
#endif /* defined(__twenty__WelcomeScene__) */
