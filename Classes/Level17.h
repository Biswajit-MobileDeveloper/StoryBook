//
//  Level17.h
//  JoshEmma
//
//  Created by Rijing on 4/19/15.
//
//

#ifndef __JoshEmma__Level17__
#define __JoshEmma__Level17__

#include "cocos2d.h"
USING_NS_CC;

class Level17 : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch *touch, CCEvent *event);
    
    //    CCLayer *SettingLayer;
    CCSprite *spBall, *shadowBall, *spBucket;
    
    CCLabelTTF *lbFirst;
    CCLabelTTF *lbSecond;
    
    CCMenuItemImage *btnBack;
    CCMenuItemImage *btnNext;
    CCSprite *spShell[4], *shadowShell[4];
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
    
    int nIndex, nCnt;
    void onHome();
    
    CREATE_FUNC(Level17);
};

#endif /* defined(__JoshEmma__Level17__) */
