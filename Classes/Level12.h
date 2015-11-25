//
//  Level12.h
//  JoshEmma
//
//  Created by Rijing on 4/16/15.
//
//

#ifndef __JoshEmma__Level12__
#define __JoshEmma__Level12__

#include "cocos2d.h"
USING_NS_CC;

class Level12 : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch *touch, CCEvent *event);
    
    //    CCLayer *SettingLayer;
    CCSprite *spSun;
    CCSprite *spBall, *spBallShadow;
    CCSprite *spRock, *spRockShadow;
    CCSprite *spGrass, *spGrassShadow;
    
    CCSprite *spHitBox;
    
    CCLabelTTF *lbFirst;
    CCLabelTTF *lbSecond;
    
    CCMenuItemImage *btnBack;
    CCMenuItemImage *btnNext;
    CCMenu *menu;
    
    void afterMoving();
    void onNext();
    void onBack();
    void createBg();
    void createMenu();
    void playEffect1();
    void playEffect2();
    void showShadow();
    void onHome();
    
    CREATE_FUNC(Level12);
};

#endif /* defined(__JoshEmma__Level12__) */
