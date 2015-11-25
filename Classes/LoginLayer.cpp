//
//  LoginLayer.cpp
//  JoshEmma
//
//  Created by Rijing on 4/23/15.
//
//

#include "LoginLayer.h"

#include "GameConfig.h"
#include "GameSettings.h"
#include "MenuScene.h"
#include "BridgeIOS.h"


USING_NS_CC;
CCScene* LoginLayer::scene()
{
    CCScene *scene = CCScene::create();
    LoginLayer *layer = LoginLayer::create();
    scene->addChild(layer);
    return scene;
}
bool LoginLayer::init()
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

void LoginLayer::createBg(){
    
    this-> runAction(CCMoveBy::create(0.1f, ccp(0, G_SCALEY*100)));
    newSprite("login_bg", G_SWIDTH/2, G_SHEIGHT/2, this, 0, RATIO_XY);
//    newLabel("Account", "Arial MT", 45, G_SWIDTH/2, getY(220), this, 0, RATIO_XY);
    bgEmail = newSprite("edit_bg", G_SWIDTH/2 - getX(125), getY(390), this, 0, RATIO_XY);
    bgPass = newSprite("edit_bg", G_SWIDTH/2 + getX(125), getY(390), this, 0, RATIO_XY);
    
    btnSubmit = newButton("submit", G_SWIDTH/2, getY(450), this, menu_selector(LoginLayer::onSubmit), true, RATIO_XY);
    btnCreate = newButton("createacc", G_SWIDTH/2 - getX(125), getY(510), this, menu_selector(LoginLayer::onCreate), true, RATIO_XY);
    btnRecover = newButton("recoveracc", G_SWIDTH/2 + getX(125),getY(510), this, menu_selector(LoginLayer::onRecover), true, RATIO_XY);
    btnClose = newButton("close", getX(800), getY(180), this, menu_selector(LoginLayer::onClose), true, RATIO_XY);
    
    CCMenu *menu = CCMenu::create(btnClose, btnSubmit, btnCreate, btnRecover,  NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
    
    txtMail = (CCTextFieldTTF*)CCTextFieldTTF::textFieldWithPlaceHolder("email/username", CCSizeMake(200, 20), kCCTextAlignmentCenter, "Arial", 15);
    ::setScale(txtMail, RATIO_XY);
    
    txtMail->setDelegate(this);
    txtMail->setPosition(bgEmail->getPosition());
    txtMail->setColorSpaceHolder(ccGRAY);
    txtMail->setColor(ccBLACK);
    this->addChild(txtMail, 1);

    txtPass = (CCTextFieldTTF*)CCTextFieldTTF::textFieldWithPlaceHolder("password", CCSizeMake(200, 20), kCCTextAlignmentCenter, "Arial", 15);
    ::setScale(txtPass, RATIO_XY);
    txtPass->setDelegate(this);
    txtPass->setPosition(bgPass->getPosition());
    txtPass->setColorSpaceHolder(ccGRAY);
    txtPass->setColor(ccBLACK);
    this->addChild(txtPass, 1);
}

void LoginLayer::createMenu(){
    this->removeFromParentAndCleanup(true);
}

void LoginLayer::onSubmit(){
    this->removeFromParentAndCleanup(true);
    g_lMenuScene->activateMenu();
    BridgeIOS::login(txtMail->getString(), txtPass->getString());
}
void LoginLayer::onCreate(){
    this->removeFromParentAndCleanup(true);
    g_lMenuScene->showCreatePage();
}
void LoginLayer::onRecover(){
    this->removeFromParentAndCleanup(true);
    g_lMenuScene->showRecovery();
}

void LoginLayer::onClose()
{
    g_lMenuScene->activateMenu();
    this->removeFromParentAndCleanup(true);
}


bool LoginLayer::ccTouchBegan(CCTouch *touch, CCEvent *event){
    CCPoint location = touch->getLocation();
    location = CCDirector::sharedDirector()->convertToGL(location);
    
    CCPoint touchLocation = CCPointMake(location.x, G_SHEIGHT-location.y - G_SCALEY*100);
    
    if (bgEmail->boundingBox().containsPoint(touchLocation)) {
        txtMail->attachWithIME();
        txtMail->setString("");
        return true;
    }
    if (bgPass->boundingBox().containsPoint(touchLocation)){
        txtPass->attachWithIME();
        txtPass->setString("");
        return true;
    }
    return true;
}



void LoginLayer::registerWithTouchDispatcher(){
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool LoginLayer::onTextFieldAttachwithIME(CCTextFieldTTF *pSender)
{
    return false;
    
}
bool LoginLayer::onTextFieldDetachwithIME(CCTextFieldTTF *pSender)
{
    return false;
}
bool LoginLayer::onTextFieldInsertText(CCTextFieldTTF *pSender, const char *text, int nLen){
    return false;
}
bool LoginLayer::onTextFieldDeleteBackward(CCTextFieldTTF *pSender, const char *delText, int nLen){
    return false;
}
bool LoginLayer::onDraw(CCTextFieldTTF *pSender){
    return false;
}