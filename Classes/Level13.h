//
//  Level13.h
//  JoshEmma
//
//  Created by Rijing on 4/16/15.
//
//

#ifndef __JoshEmma__Level13__
#define __JoshEmma__Level13__

#include "cocos2d.h"
USING_NS_CC;

class Level13 : public cocos2d::CCLayer
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
    CCMenu *menu;
    
    CCLabelTTF *lbFirst;
    CCLabelTTF *lbSecond;
    
    void afterMoving();
    void onNext();
    void onBack();
    void createBg();
    void createMenu();
    void playEffect();
    void onHome();
    
    CCSprite *Josh, *Emma,*spHitBox;
    
    CREATE_FUNC(Level13);
};

#endif /* defined(__JoshEmma__Level13__) */
