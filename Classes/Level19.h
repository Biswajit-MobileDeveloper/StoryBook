//
//  Level19.h
//  JoshEmma
//
//  Created by Rijing on 4/19/15.
//
//

#ifndef __JoshEmma__Level19__
#define __JoshEmma__Level19__

#include "cocos2d.h"
USING_NS_CC;

class Level19 : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch *touch, CCEvent *event);
    
    CCLabelTTF *lbFirst;
    
    CCLabelTTF *lbSecond[5];
    
    CCMenuItemImage *btnBack;
    CCMenuItemImage *btnNext;
    CCSprite *spThing[5],*shadowThing[5];
    CCMenu *menu;
    
    void onTimer();
    void afterFirst();
    void afterMoving();
    void onNext();
    void onBack();
    void createBg();
    void createMenu();
    void pickup(CCNode*pNode);
    void removeClam(CCNode *node);
    void playEffect();
    void pickup(CCNode*pNode, int nIndex);
    void showShadow();
    int index, nCnt, nAAA;
    
    void onHome();
    
    CREATE_FUNC(Level19);
};

#endif /* defined(__JoshEmma__Level19__) */
