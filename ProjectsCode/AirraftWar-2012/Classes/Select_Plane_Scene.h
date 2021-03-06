//
//  Select_Plane_Scene.h
//  a4
//
//  Created by student on 15-7-26.
//
//

#ifndef __a4__Select_Plane_Scene__
#define __a4__Select_Plane_Scene__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;
#include <ui/CocosGUI.h>
using namespace ui;

class Select_Plane_Scene:public Scene
{
public:
    virtual bool init();
    CREATE_FUNC(Select_Plane_Scene);
    void bgsoundCallback(Ref *sender);
    static Select_Plane_Scene *getInstance();
    //改变音量进度条的回调函数
    void changeVolumnProgress(Ref *render,Slider::EventType type);
private:
    static Select_Plane_Scene *instance_;
    UserDefault * de;//为了实现音乐的快速播放和暂停，使用UserDefault存取播放状态
};

#endif /* defined(__a4__Select_Plane_Scene__) */
