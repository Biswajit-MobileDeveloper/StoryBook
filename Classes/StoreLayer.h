//
//  StoreLayer.h
//  JoshEmma
//
//  Created by Rijing on 4/23/15.
//
//

#ifndef __JoshEmma__StoreLayer__
#define __JoshEmma__StoreLayer__

#include "cocos2d.h"
USING_NS_CC;

class StoreLayer : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();

    CCMenuItemImage *btnEnglish;
    CCMenuItemImage *btnSpanish;
    CCMenuItemImage *btnClose;
    
    CCLabelTTF *lbEnglish;
    CCLabelTTF *lbSpanish;
    
    
    void createBg();
    void onClose();
    
    CREATE_FUNC(StoreLayer);
};
#endif /* defined(__JoshEmma__StoreLayer__) */
