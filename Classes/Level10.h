//
//  Level10.h
//  JoshEmma
//
//  Created by Rijing on 4/19/15.
//
//

#ifndef __JoshEmma__Level10__
#define __JoshEmma__Level10__

#include "cocos2d.h"
USING_NS_CC;

class Level10 : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch *touch, CCEvent *event);
    
    
    CCSprite *josh, *emma,*spHitBox;
    CCLabelTTF *lbFirst;
    CCLabelTTF *lbSecond;
    CCSprite *spSun;
    CCMenuItemImage *btnBack;
    CCMenuItemImage *btnNext;
    CCSprite *spThing[5],*shadowThing[5];
    CCMenu *menu;
    
    void onTimer();
    void afterMoving();
    void onNext();
    void onBack();
    void createBg();
    void createMenu();
    void pickup(CCNode*pNode);
    void removeClam(CCNode *node);
    void playEffect();
    void onHome();
    
    int nIndex, nCnt;
    
    
    CREATE_FUNC(Level10);
};


#endif /* defined(__JoshEmma__Level10__) */
