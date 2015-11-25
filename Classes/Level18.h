//
//  Level18.h
//  JoshEmma
//
//  Created by Rijing on 4/19/15.
//
//

#ifndef __JoshEmma__Level18__
#define __JoshEmma__Level18__

#include "cocos2d.h"
USING_NS_CC;

class Level18 : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch *touch, CCEvent *event);
    
    CCLabelTTF *lbFirst;
    CCLabelTTF *lbSecond;
    
    CCMenuItemImage *btnBack;
    CCMenuItemImage *btnNext;
    CCSprite *spFlower[5], *shadowFlower[5], *spBucket;
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
    
    
    CREATE_FUNC(Level18);
};

#endif /* defined(__JoshEmma__Level18__) */
