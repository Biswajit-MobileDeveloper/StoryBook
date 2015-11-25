//
//  RecoverLayer.cpp
//  JoshEmma
//
//  Created by Rijing on 4/26/15.
//
//

#include "RecoverLayer.h"

#include "GameConfig.h"
#include "GameSettings.h"
#include "MenuScene.h"
#include "BridgeIOS.h"


USING_NS_CC;
CCScene* RecoverLayer::scene()
{
    CCScene *scene = CCScene::create();
    RecoverLayer *layer = RecoverLayer::create();
    scene->addChild(layer);
    return scene;
}
bool RecoverLayer::init()
{
    if ( !CCLayer::init())
    {
        return false;
    }
    this->setTouchEnabled(true);
    createBg();
    createMenu();
    return true;
}

void RecoverLayer::createBg(){
    
    this-> runAction(CCMoveBy::create(0.1f, ccp(0, G_SCALEY*100)));
    newSprite("recover_bg", G_SWIDTH/2, G_SHEIGHT/2, this, 0, RATIO_XY);
    //    newLabel("Account", "Arial MT", 45, G_SWIDTH/2, getY(220), this, 0, RATIO_XY);
    bgEmail = newSprite("edit_bg", G_SWIDTH/2 - getX(125), getY(410), this, 0, RATIO_XY);
    
    btnRecover = newButton("recovery", G_SWIDTH/2, getY(510), this, menu_selector(RecoverLayer::onRecover), true, RATIO_XY);
    btnClose = newButton("close", getX(800), getY(180), this, menu_selector(RecoverLayer::onClose), true, RATIO_XY);
    
    CCMenu *menu = CCMenu::create(btnClose, btnRecover,  NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
    
    txtMail = (CCTextFieldTTF*)CCTextFieldTTF::textFieldWithPlaceHolder("email", CCSizeMake(250, 20), kCCTextAlignmentCenter, "Arial", 15);
    ::setScale(txtMail, RATIO_XY);
    
    
    txtMail->setDelegate(this);
    txtMail->setPosition(bgEmail->getPosition());
    txtMail->setColorSpaceHolder(ccGRAY);
    txtMail->setColor(ccBLACK);
    this->addChild(txtMail, 1);
}

void RecoverLayer::createMenu(){

}

void RecoverLayer::onRecover(){
    this->removeFromParentAndCleanup(true);
    g_lMenuScene->activateMenu();
    BridgeIOS::recover(txtMail->getString());

}

void RecoverLayer::onClose()
{
    g_lMenuScene->activateMenu();
    this->removeFromParentAndCleanup(true);
}


bool RecoverLayer::ccTouchBegan(CCTouch *touch, CCEvent *event){
    CCPoint location = touch->getLocation();
    location = CCDirector::sharedDirector()->convertToGL(location);
    CCPoint touchLocation = CCPointMake(location.x, G_SHEIGHT-location.y - G_SCALEY*100);
    
    if (bgEmail->boundingBox().containsPoint(touchLocation)) {
        txtMail->attachWithIME();
        txtMail->setString("");
        return true;
    }
    return true;
}



void RecoverLayer::registerWithTouchDispatcher(){
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool RecoverLayer::onTextFieldAttachwithIME(CCTextFieldTTF *pSender)
{
    return false;
    
}
bool RecoverLayer::onTextFieldDetachwithIME(CCTextFieldTTF *pSender)
{
    return false;
}
bool RecoverLayer::onTextFieldInsertText(CCTextFieldTTF *pSender, const char *text, int nLen){
    return false;
}
bool RecoverLayer::onTextFieldDeleteBackward(CCTextFieldTTF *pSender, const char *delText, int nLen){
    return false;
}
bool RecoverLayer::onDraw(CCTextFieldTTF *pSender){
    return false;
}