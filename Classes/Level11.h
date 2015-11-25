//
//  Level11.h
//  JoshEmma
//
//  Created by Rijing on 4/16/15.
//
//

#ifndef __JoshEmma__Level11__
#define __JoshEmma__Level11__

#include "cocos2d.h"
USING_NS_CC;

class Level11 : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch *touch, CCEvent *event);

    
    //    CCLayer *SettingLayer;
    CCSprite *spSun;
    
    CCMenuItemImage *btnBack;
    CCMenuItemImage *btnNext;
    CCLabelTTF *lbFirst;
    CCLabelTTF *lbSecond;
    
    CCMenu *menu;
    
    void afterMoving();
    void onNext();
    void onBack();
    void createBg();
    void createMenu();
    
    void playEffect1();
    void playEffect2();
    
    void onHome();

    
    CREATE_FUNC(Level11);
};

#endif /* defined(__JoshEmma__Level11__) */
