#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();
    virtual bool init();    
	CREATE_FUNC(HelloWorld);
    void callBack(Ref *sender); 
	void callBack1(Ref *sender);
};

#endif // __HELLOWORLD_SCENE_H__
