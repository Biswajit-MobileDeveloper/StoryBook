//
//  EditAccLayer.cpp
//  JoshEmma
//
//  Created by Rijing on 4/27/15.
//
//

#include "EditAccLayer.h"


#include "GameConfig.h"
#include "GameSettings.h"
#include "MenuScene.h"
#include "BridgeIOS.h"


USING_NS_CC;
CCScene* EditAccLayer::scene()
{
    CCScene *scene = CCScene::create();
    EditAccLayer *layer = EditAccLayer::create();
    scene->addChild(layer);
    return scene;
}
bool EditAccLayer::init()
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

void EditAccLayer::createBg(){
    
    this-> runAction(CCMoveBy::create(0.1f, ccp(0, G_SCALEY*100)));
    newSprite("editacc_bg", G_SWIDTH/2, G_SHEIGHT/2, this, 0, RATIO_XY);
    
    bgEmail = newSprite("edit_bg", G_SWIDTH/2 - getX(125), getY(270), this, 0, RATIO_XY);
    bgNewPass = newSprite("edit_bg", G_SWIDTH/2 + getX(125), getY(270), this, 0, RATIO_XY);
    bgFirstName = newSprite("edit_bg", G_SWIDTH/2 - getX(125), getY(310), this, 0, RATIO_XY);
    bgLastName = newSprite("edit_bg", G_SWIDTH/2 + getX(125), getY(310), this, 0, RATIO_XY);
    bgChildName = newSprite("edit_bg", G_SWIDTH/2 - getX(125), getY(440), this, 0, RATIO_XY);
    bgChildBirth = newSprite("edit_bg", G_SWIDTH/2 + getX(125), getY(440), this, 0, RATIO_XY);
    bgCurrentPass = newSprite("edit_bg", G_SWIDTH/2, getY(510), this, 0, RATIO_XY);
    
    btnSubmit = newButton("editaccount", G_SWIDTH/2, getY(560), this, menu_selector(EditAccLayer::onRecover), true, RATIO_XY);
    btnClose = newButton("close", getX(800), getY(180), this, menu_selector(EditAccLayer::onClose), true, RATIO_XY);
    
    CCMenu *menu = CCMenu::create(btnClose, btnSubmit,  NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
    
    txtEmail = (CCTextFieldTTF*)CCTextFieldTTF::textFieldWithPlaceHolder("Email Address", CCSizeMake(200, 20), kCCTextAlignmentCenter, "Arial", 15);
    ::setScale(txtEmail, RATIO_XY);
    
    txtEmail->setDelegate(this);
    txtEmail->setPosition(bgEmail->getPosition());
    txtEmail->setColorSpaceHolder(ccGRAY);
    txtEmail->setColor(ccBLACK);
    this->addChild(txtEmail, 1);
    
    txtPassConfirm = (CCTextFieldTTF*)CCTextFieldTTF::textFieldWithPlaceHolder("Retype Email", CCSizeMake(200, 20), kCCTextAlignmentCenter, "Arial", 15);
    ::setScale(txtPassConfirm, RATIO_XY);
    txtPassConfirm->setDelegate(this);
    txtPassConfirm->setPosition(bgNewPass->getPosition());
    txtPassConfirm->setColorSpaceHolder(ccGRAY);
    txtPassConfirm->setColor(ccBLACK);
    this->addChild(txtPassConfirm, 1);
    
    txtFirstName = (CCTextFieldTTF*)CCTextFieldTTF::textFieldWithPlaceHolder("Password", CCSizeMake(200, 20), kCCTextAlignmentCenter, "Arial", 15);
    ::setScale(txtFirstName, RATIO_XY);
    txtFirstName->setDelegate(this);
    txtFirstName->setPosition(bgFirstName->getPosition());
    txtFirstName->setColorSpaceHolder(ccGRAY);
    txtFirstName->setColor(ccBLACK);
    this->addChild(txtFirstName, 1);
    
    txtLastName = (CCTextFieldTTF*)CCTextFieldTTF::textFieldWithPlaceHolder("Retype Password", CCSizeMake(200, 20), kCCTextAlignmentCenter, "Arial", 15);
    ::setScale(txtLastName, RATIO_XY);
    txtLastName->setDelegate(this);
    txtLastName->setPosition(bgLastName->getPosition());
    txtLastName->setColorSpaceHolder(ccGRAY);
    txtLastName->setColor(ccBLACK);
    this->addChild(txtLastName, 1);
    
    txtChildName = (CCTextFieldTTF*)CCTextFieldTTF::textFieldWithPlaceHolder("Child's Name", CCSizeMake(200, 20), kCCTextAlignmentCenter, "Arial", 15);
    ::setScale(txtChildName, RATIO_XY);
    
    txtChildName->setDelegate(this);
    txtChildName->setPosition(bgChildName->getPosition());
    txtChildName->setColorSpaceHolder(ccGRAY);
    txtChildName->setColor(ccBLACK);
    this->addChild(txtChildName, 1);
    
    txtChildBirth = (CCTextFieldTTF*)CCTextFieldTTF::textFieldWithPlaceHolder("Child's Birth", CCSizeMake(200, 20), kCCTextAlignmentCenter, "Arial", 15);
    ::setScale(txtChildBirth, RATIO_XY);
    txtChildBirth->setDelegate(this);
    txtChildBirth->setPosition(bgChildBirth->getPosition());
    txtChildBirth->setColorSpaceHolder(ccGRAY);
    txtChildBirth->setColor(ccBLACK);
    this->addChild(txtChildBirth, 1);
    
    txtCurrentPass = (CCTextFieldTTF*)CCTextFieldTTF::textFieldWithPlaceHolder("Current Password", CCSizeMake(200, 20), kCCTextAlignmentCenter, "Arial", 15);
    ::setScale(txtCurrentPass, RATIO_XY);
    txtCurrentPass->setDelegate(this);
    txtCurrentPass->setPosition(bgCurrentPass->getPosition());
    txtCurrentPass->setColorSpaceHolder(ccGRAY);
    txtCurrentPass->setColor(ccBLACK);
    this->addChild(txtCurrentPass, 1);
}

void EditAccLayer::createMenu()
{
    
}

void EditAccLayer::onRecover(){
    this->removeFromParentAndCleanup(true);
    g_lMenuScene->activateMenu();
    BridgeIOS::updateUserInfo(txtFirstName->getString(), txtEmail->getString(), txtPassConfirm->getString(), txtCurrentPass->getString(), txtChildName->getString(), txtChildBirth->getString());
}

void EditAccLayer::onClose()
{
    g_lMenuScene->activateMenu();
    this->removeFromParentAndCleanup(true);
}


bool EditAccLayer::ccTouchBegan(CCTouch *touch, CCEvent *event){
    CCPoint location = touch->getLocation();
    location = CCDirector::sharedDirector()->convertToGL(location);
    CCLOG("%.2f---%.2f", location.x, location.y);
    CCLOG("%.2f---%.2f", bgEmail->boundingBox().origin.x, bgEmail->boundingBox().origin.y);
    
    CCPoint touchLocation = CCPointMake(location.x, G_SHEIGHT-location.y - G_SCALEY*100);
    
    if (bgEmail->boundingBox().containsPoint(touchLocation)) {
        txtEmail->attachWithIME();
        txtEmail->setString("");
        return true;
    }
    if (bgNewPass->boundingBox().containsPoint(touchLocation)) {
        txtPassConfirm->attachWithIME();
        txtPassConfirm->setString("");
        return true;
    }
    
    if (bgFirstName->boundingBox().containsPoint(touchLocation)) {
        txtFirstName->attachWithIME();
        txtFirstName->setString("");
        return true;
    }
    if (bgLastName->boundingBox().containsPoint(touchLocation)) {
        txtLastName->attachWithIME();
        txtLastName->setString("");
        return true;
    }
    if (bgChildName->boundingBox().containsPoint(touchLocation)) {
        txtChildName->attachWithIME();
        txtChildName->setString("");
        return true;
    }
    if (bgChildBirth->boundingBox().containsPoint(touchLocation)) {
        txtChildBirth->attachWithIME();
        txtChildBirth->setString("");
        return true;
    }
    if (bgCurrentPass->boundingBox().containsPoint(touchLocation)) {
        txtCurrentPass->attachWithIME();
        txtCurrentPass->setString("");
        return true;
    }
    return true;
}

void EditAccLayer::registerWithTouchDispatcher(){
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool EditAccLayer::onTextFieldAttachwithIME(CCTextFieldTTF *pSender)
{
    return false;
    
}
bool EditAccLayer::onTextFieldDetachwithIME(CCTextFieldTTF *pSender)
{
    return false;
}
bool EditAccLayer::onTextFieldInsertText(CCTextFieldTTF *pSender, const char *text, int nLen){
    return false;
}
bool EditAccLayer::onTextFieldDeleteBackward(CCTextFieldTTF *pSender, const char *delText, int nLen){
    return false;
}
bool EditAccLayer::onDraw(CCTextFieldTTF *pSender){
    return false;
}