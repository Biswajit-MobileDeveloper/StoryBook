//
//  Slide3.h
//  JoshEmma
//
//  Created by Biswajit Paul on 04/11/15.
//
//

#ifndef __JoshEmma__Slide3__
#define __JoshEmma__Slide3__

#include "cocos2d.h"
USING_NS_CC;

class Slide3 : public cocos2d::CCLayer
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
    CCSprite* trainSprite;
    CCSprite* josh;
    CCSprite* emma;
    CCSprite* labelBackgroundSprite;
    CCSprite* labelBackgroundSpriteForlabel2;
    
    void afterMoving();
    void onNext();
    void onBack();
    void createBg();
    void createMenu();
    
    void playEffect1();
    void playEffect2();
    
    void onHome();
    void SetvisibilityForTextBackground1();
    void SetvisibilityForTextBackground2();
    
    CREATE_FUNC(Slide3);
};

#endif /* defined(__JoshEmma__Slide3__) */
