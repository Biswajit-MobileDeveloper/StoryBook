//
//  RecoverLayer.h
//  JoshEmma
//
//  Created by Rijing on 4/26/15.
//
//

#ifndef __JoshEmma__RecoverLayer__
#define __JoshEmma__RecoverLayer__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;


class RecoverLayer : public cocos2d::CCLayer, public CCTextFieldDelegate
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
    CCMenuItemImage *btnRecover,*btnClose;
    CCTextFieldTTF *txtMail;
    
    void onRecover();
    void createBg();
    void createMenu();
    void onClose();
    CREATE_FUNC(RecoverLayer);
};

#endif /* defined(__JoshEmma__RecoverLayer__) */
