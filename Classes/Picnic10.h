//
//  Picnic10.hpp
//  JoshEmma
//
//  Created by Biswajit Paul on 18/11/15.
//
//

#ifndef Picnic10_h
#define Picnic10_h

#include "cocos2d.h"
USING_NS_CC;

class Picnic10 : public cocos2d::CCLayer
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
    
    CCSprite* basketSprite;
    CCSprite* ballSprite;
    CCSprite* joshSprite;
    CCSprite* emmaSprite;
    
    
    CCMenu *menu;
    
    float deltaTimeForJosh;
    float deltaTimeForEmma;
    int jumpNumberForJosh;
    int jumpNumberForEmma;
    
    void afterMoving();
    void onNext();
    void onBack();
    void createBg();
    void createMenu();
    
    void playEffect1();
    void playEffect2();
    
    void onHome();
    
    CREATE_FUNC(Picnic10);
    void update( float dt );
};


#endif /* Picnic10_hpp */
