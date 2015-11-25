//
//  MenuScene.h
//  JoshEmma
//
//  Created by Rijing on 4/13/15.
//
//

#ifndef __JoshEmma__MenuScene__
#define __JoshEmma__MenuScene__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class MenuScene : public cocos2d::CCLayer , public CCTextFieldDelegate
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    
    CCMenuItemImage *iPlay;
    CCMenuItemImage *iStart;
    CCMenuItemImage *iTrigger;
    CCMenuItemImage *iLogin, *iLogout;
    
    CCMenuItemImage* jeOnTheBeach;
    CCMenuItemImage* jeRideTheTrain;
    CCMenuItemImage* jeHaveAPicnic;
    CCMenuItemImage* jeGoToTheZoo;
    CCMenuItemImage* jeFlyAKite;
    
    CCLayer *lyDash;
    
    CCMenu *menu, *menu_dash;

    void onLogout();
    void onDashboard();
    //void onPlay();
    void onFirstLession( );
    void onSecondLession( );
    void onThirdLession( );
    void onFourthLession( );
    void onFifthLession( );
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
    
    CREATE_FUNC(MenuScene);
};

#endif /* defined(__JoshEmma__MenuScene__) */
