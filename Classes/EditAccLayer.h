//
//  EditAccLayer.h
//  JoshEmma
//
//  Created by Rijing on 4/27/15.
//
//

#ifndef __JoshEmma__EditAccLayer__
#define __JoshEmma__EditAccLayer__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;


class EditAccLayer : public cocos2d::CCLayer, public CCTextFieldDelegate
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
    CCSprite *bgNewPass;
    CCSprite *bgFirstName;
    CCSprite *bgLastName;
    CCSprite *bgChildName;
    CCSprite *bgChildBirth;
    CCSprite *bgCurrentPass;
    
    CCMenuItemImage *btnSubmit,*btnClose;
    

    CCTextFieldTTF *txtEmail;
    CCTextFieldTTF *txtPassConfirm;
    CCTextFieldTTF *txtFirstName;
    CCTextFieldTTF *txtLastName;
    CCTextFieldTTF *txtChildName;
    CCTextFieldTTF *txtChildBirth;
    CCTextFieldTTF *txtCurrentPass;
    
    void onFocustext(CCTextFieldTTF *pSender);
    void onRecover();
    void createBg();
    void createMenu();
    void onClose();
    CREATE_FUNC(EditAccLayer);
};

#endif /* defined(__JoshEmma__EditAccLayer__) */
