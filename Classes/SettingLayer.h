//
//  SettingLayer.h
//  JoshEmma
//
//  Created by Rijing on 4/13/15.
//
//

#ifndef __JoshEmma__SettingLayer__
#define __JoshEmma__SettingLayer__

#include "cocos2d.h"
USING_NS_CC;

class SettingLayer : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    
    CCMenuItemToggle *btnSpeech;
    CCMenuItemToggle *btnAuto;
    CCMenuItemImage *btnFeedback, *btnCredit,  *btnClose;
    
    
    void onCredit();
    void onRate();
    void onSound();
    void onAuto();
    void onSpeech();
    void createBg();
    void createMenu();
    void onClose();
    CREATE_FUNC(SettingLayer);
};
#endif /* defined(__JoshEmma__SettingLayer__) */
