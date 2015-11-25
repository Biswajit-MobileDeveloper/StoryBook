//
//  CreateAccLayer.h
//  JoshEmma
//
//  Created by Rijing on 4/26/15.
//
//

#ifndef __JoshEmma__CreateAccLayer__
#define __JoshEmma__CreateAccLayer__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;


class CreateAccLayer : public cocos2d::CCLayer, public CCTextFieldDelegate
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch *touch, CCEvent *event);
    
    virtual bool onTextFieldAttachwithIME(CCTextFieldTTF *pSender);
    virtual bool onTextFieldDetachwithIME(CCTextFieldTTF *pSender);
    virtual bool onTextFieldInsertText(CCTextFieldTTF *pSender, const char *text, int nLen);
    virtual bool onTextFieldDeleteBackward(CCTextFieldTTF *pSender, const char *delText, int nLen);
    virtual bool onDraw(CCTextFieldTTF *pSender);
    
    
    CCSprite *bgEmail;
    CCSprite *bgEmailConfirm;
    CCSprite *bgPass;
    CCSprite *bgPassConfirm;
    CCSprite *bgFirstName;
    CCSprite *bgLastName;
    CCSprite *bgChildName;
    CCSprite *bgChildBirth;
    
    CCMenuItemImage *btnNew,*btnClose;
    
    CCTextFieldTTF *txtEmail;
    CCTextFieldTTF *txtEmailConfirm;
    CCTextFieldTTF *txtPass;
    CCTextFieldTTF *txtPassConfirm;
    CCTextFieldTTF *txtFirstName;
    CCTextFieldTTF *txtLastName;
    CCTextFieldTTF *txtChildName;
    CCTextFieldTTF *txtChildBirth;

    
    void onRecover();
    void createBg();
    void createMenu();
    void onClose();
    CREATE_FUNC(CreateAccLayer);
};

#endif /* defined(__JoshEmma__CreateAccLayer__) */
