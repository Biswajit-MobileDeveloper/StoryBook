//
//  Level15.h
//  JoshEmma
//
//  Created by Rijing on 4/19/15.
//
//

#ifndef __JoshEmma__Level15__
#define __JoshEmma__Level15__

#include "cocos2d.h"
USING_NS_CC;

class Level15 : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch *touch, CCEvent *event);
    
    
    //    CCLayer *SettingLayer;
    CCSprite *spSun, *spRock, *spRockShadow,*spBucket;
    CCSprite *star1, *star2, *shadowStar1, *shadowStar2,*spHitBox;
    bool bStar1, bStar2;
    
    CCMenuItemImage *btnBack;
    CCMenuItemImage *btnNext;
    CCMenu *menu;
    
    CCLabelTTF *lbFirst;
    CCLabelTTF *lbSecond;
    
    void pickup(CCNode*pNode);
    void removeStar(CCNode *node);
    void onNext();
    void onBack();
    void createBg();
    void createMenu();
    void onTimer();
    void playEffect1();
    void playEffect2();
    void showShadow();
    int nIndex, nCnt;
    
    void onHome();

    
    CREATE_FUNC(Level15);
};

#endif /* defined(__JoshEmma__Level15__) */
