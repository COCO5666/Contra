//
//  ManagerBase.h
//  a4
//
//  Created by student on 15-7-11.
//
//

#ifndef __a4__ManagerBase__
#define __a4__ManagerBase__

#include "cocos2d.h"
USING_NS_CC;
#include "Bullet.h"
#include "EnemyBase.h"
class ManagerBase
{
private://单例
    ManagerBase();
    ~ManagerBase();
public:
    static ManagerBase *getInstance();
    static void deleteInstance();
private:
    static  ManagerBase *manager_;
public:
    //从容器中获取敌机列表
    Vector<EnemyBase*> &getEnemyList()
    {
        return enemy_list_;
    }
    //从容器中获取子弹列表
    Vector<Bullet *> &getBulletList()
    {
        return bullet_list_;
    }
    // 大Boss子弹精灵数组
    Vector<Sprite*> &getBossBulletList()
    {
        return bossBullet_List_;
    }
    void set_enemy_list(EnemyBase *enemy);
    void remove_enemy_list(EnemyBase *enemy);
    void set_bullet_list(Bullet *bullet);
    void remove_bullet_list(Bullet *bullet);
    void set_bossBullet_list(Sprite *bossBullet);
    void remove_bossBullt_list(Sprite *bossBullet);
public:
    //定义两个容器，用来存放敌机和子弹
    Vector<EnemyBase *>enemy_list_;
    Vector<Bullet *>bullet_list_;
    Vector<Sprite *>bossBullet_List_;
};

#endif /* defined(__a4__ManagerBase__) */
