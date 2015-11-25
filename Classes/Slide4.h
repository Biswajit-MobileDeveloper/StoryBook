//
//  Slide4.h
//  JoshEmma
//
//  Created by Biswajit Paul on 04/11/15.
//
//

#ifndef __JoshEmma__Slide4__
#define __JoshEmma__Slide4__

#include "cocos2d.h"
USING_NS_CC;

class Slide4 : public cocos2d::CCLayer
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
    CCSprite* labelBackgroundSprite;
    CCSprite* labelBackgroundSpriteForlabel2;

    
    CCMenu *menu;
    
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
    
    
    CREATE_FUNC(Slide4);
};


#endif /* defined(__JoshEmma__Slide4__) */