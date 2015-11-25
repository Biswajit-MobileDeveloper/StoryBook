//
//  Level16.h
//  JoshEmma
//
//  Created by Rijing on 4/19/15.
//
//

#ifndef __JoshEmma__Level16__
#define __JoshEmma__Level16__

#include "cocos2d.h"
USING_NS_CC;

class Level16 : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch *touch, CCEvent *event);
    
    //    CCLayer *SettingLayer;
    
    CCSprite *spSun;
    CCSprite *spGrass, *spGrassShadow,*spBucket,*spHitBox;
    CCSprite *spClam[3];
    
    CCLabelTTF *lbFirst;
    CCLabelTTF *lbSecond;
    
    CCMenuItemImage *btnBack;
    CCMenuItemImage *btnNext;
    CCMenu *menu;
    
    void onTimer();
    void afterMoving();
    void onNext();
    void onBack();
    void createBg();
    void createMenu();
    void pickup(CCNode*pNode);
    void removeClam(CCNode *node);
    void playEffect1();
    void playEffect2();
    void onHome();
    
    int nIndex, nCnt;

    
    CREATE_FUNC(Level16);
};

#endif /* defined(__JoshEmma__Level16__) */
