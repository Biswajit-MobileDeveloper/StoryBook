//
//  Picnic3.h
//  JoshEmma
//
//  Created by Biswajit Paul on 11/11/15.
//
//

#ifndef __JoshEmma__Picnic3__
#define __JoshEmma__Picnic3__

#include "cocos2d.h"
USING_NS_CC;

class Picnic3 : public cocos2d::CCLayer
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
    
    CCSprite* labelBackgroundSprite;
    CCSprite* labelBackgroundSpriteForlabel2;
    CCSprite* blanketSprite;
    CCSprite* basketSprite;
    CCSprite* joshSprite;
    CCSprite* emmaSprite;
    CCSprite* ballSprite;

    
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
    
    CREATE_FUNC(Picnic3);
};

#endif /* defined(__JoshEmma__Picnic3__) */
