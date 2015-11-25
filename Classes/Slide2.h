//
//  Slide2.h
//  JoshEmma
//
//  Created by Biswajit Paul on 03/11/15.
//
//

#ifndef __JoshEmma__Slide2__
#define __JoshEmma__Slide2__

#include "cocos2d.h"
USING_NS_CC;

class Slide2 : public cocos2d::CCLayer
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
    float deltaTime;
    CCMenu *menu;
    
    CCSprite* trainSprite;
    CCSprite* joshAndEmmaSprite;
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
    
    CREATE_FUNC(Slide2);
    
    void update( float dt );
};


#endif /* defined(__JoshEmma__Slide2__) */
