//
//  Picnic2.h
//  JoshEmma
//
//  Created by Biswajit Paul on 11/11/15.
//
//

#ifndef __JoshEmma__Picnic2__
#define __JoshEmma__Picnic2__

#include "cocos2d.h"
USING_NS_CC;

class Picnic2 : public cocos2d::CCLayer
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
    CCSprite* basketSprite;
    
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
    
    CREATE_FUNC(Picnic2);
};


#endif /* defined(__JoshEmma__Picnic2__) */
