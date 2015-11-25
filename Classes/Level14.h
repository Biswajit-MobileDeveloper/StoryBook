//
//  Level14.h
//  JoshEmma
//
//  Created by Rijing on 4/18/15.
//
//

#ifndef __JoshEmma__Level14__
#define __JoshEmma__Level14__

#include "cocos2d.h"
USING_NS_CC;

class Level14 : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch *touch, CCEvent *event);

    CCMenuItemImage *btnBack;
    CCMenuItemImage *btnNext;
    CCMenu *menu;
    
    CCSprite *spFeather,*spFeaderShadow, *spBucket;
    CCLabelTTF *lbFirst;
    CCLabelTTF *lbSecond;
    bool bFlip;
    int nTimer;
    void onTimer();
    void afterMoving();
    void flipFeather();
    void onNext();
    void onBack();
    void createBg();
    void createMenu();
    void pickup();
    void removeFeather();
    void playEffect1();
    void playEffect2();
    void onHome();
    
    
    CREATE_FUNC(Level14);
};

#endif /* defined(__JoshEmma__Level14__) */
