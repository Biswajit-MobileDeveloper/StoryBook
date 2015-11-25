//
//  Slide1.h
//  JoshEmma
//
//  Created by Biswajit Paul on 03/11/15.
//
//

#ifndef __JoshEmma__Slide1__
#define __JoshEmma__Slide1__

#include "cocos2d.h"
USING_NS_CC;

class Slide1 : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch *touch, CCEvent *event);
    
    
    //    CCLayer *SettingLayer;
   // CCSprite *trainSprite;
    
    CCMenuItemImage *btnBack;
    CCMenuItemImage *btnNext;
    CCLabelTTF *lbFirst;
    CCLabelTTF *lbSecond;
    
    CCMenu *menu;
    CCSprite* sunSprite;
    CCSprite* trainSprite;
    CCSprite* labelBackgroundSprite;
    CCSprite* labelBackgroundSpriteForlabel2;

    void afterMoving();
    void onNext();
    void onBack();
    void createBg();
    void createMenu();
    
    void playEffect1();
    void playEffect2();
    
    void SetvisibilityForTextBackground1();
    void SetvisibilityForTextBackground2();
    
    void onHome();
    
    CREATE_FUNC(Slide1);
};


#endif /* defined(__JoshEmma__Slide1__) */
