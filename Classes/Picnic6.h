//
//  Picnic6.hpp
//  JoshEmma
//
//  Created by Biswajit Paul on 18/11/15.
//
//

#ifndef Picnic6_h
#define Picnic6_h

#include "cocos2d.h"
USING_NS_CC;

class Picnic6 : public cocos2d::CCLayer
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
    void SetvisibilityForTextBackground1();
    void SetvisibilityForTextBackground2();
    
    CCMenu *menu;
    
    void afterMoving();
    void onNext();
    void onBack();
    void createBg();
    void createMenu();
    
    void playEffect1();
    void playEffect2();
    
    void onHome();
    
    CREATE_FUNC(Picnic6);
};


#endif /* Picnic6_hpp */
