//
//  PlayScene.h
//  JoshEmma
//
//  Created by Biswajit Paul on 12/11/15.
//
//

#ifndef __JoshEmma__PlayScene__
#define __JoshEmma__PlayScene__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class PlayScene : public cocos2d::CCLayer , public CCTextFieldDelegate
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    
    CCMenuItemImage *iPlay;
    CCMenuItemImage *iStart;
    CCMenuItemImage *iTrigger;
    CCMenuItemImage *iLogin, *iLogout;
    
    CCLayer *lyDash;
    
    CCMenu *menu, *menu_dash;
    
    void onLogout();
    void onDashboard();
    void onPlay();
    void createBg();
    void createMenu();
    void onClose();
    void onMoreLesson();
    void onChangePassword();
    
    void activateMenu();
    void showRecovery();
    void showCreatePage();
    
    void onAccount();
    void onStore();
    void onSetting();
    
    CREATE_FUNC(PlayScene);
};

#endif /* defined(__JoshEmma__PlayScene__) */
