//
//  LoginLayer.h
//  JoshEmma
//
//  Created by Rijing on 4/23/15.
//
//

#ifndef __JoshEmma__LoginLayer__
#define __JoshEmma__LoginLayer__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;


class LoginLayer : public cocos2d::CCLayer, public CCTextFieldDelegate
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

    
    CCSprite *bgEmail, *bgPass;
    CCMenuItemImage *btnSubmit, *btnCreate, *btnRecover,  *btnClose;
    CCTextFieldTTF *txtMail;
    CCTextFieldTTF *txtPass;
    

    
    void onSubmit();
    void onCreate();
    void onRecover();
    void createBg();
    void createMenu();
    void onClose();
    CREATE_FUNC(LoginLayer);
};

#endif /* defined(__JoshEmma__LoginLayer__) */
