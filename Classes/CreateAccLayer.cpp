//
//  CreateAccLayer.cpp
//  JoshEmma
//
//  Created by Rijing on 4/26/15.
//
//

#include "CreateAccLayer.h"

#include "GameConfig.h"
#include "GameSettings.h"
#include "MenuScene.h"
#include "BridgeIOS.h"


USING_NS_CC;
CCScene* CreateAccLayer::scene()
{
    CCScene *scene = CCScene::create();
    CreateAccLayer *layer = CreateAccLayer::create();
    scene->addChild(layer);
    return scene;
}
bool CreateAccLayer::init()
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

void CreateAccLayer::createBg(){
    
    this-> runAction(CCMoveBy::create(0.1f, ccp(0, G_SCALEY*100)));
    newSprite("create_bg", G_SWIDTH/2, G_SHEIGHT/2, this, 0, RATIO_XY);
    
    bgEmail = newSprite("edit_bg", G_SWIDTH/2 - getX(125), getY(270), this, 0, RATIO_XY);
    bgEmailConfirm = newSprite("edit_bg", G_SWIDTH/2 + getX(125), getY(270), this, 0, RATIO_XY);
    bgPass = newSprite("edit_bg", G_SWIDTH/2 - getX(125), getY(310), this, 0, RATIO_XY);
    bgPassConfirm = newSprite("edit_bg", G_SWIDTH/2 + getX(125), getY(310), this, 0, RATIO_XY);
    bgFirstName = newSprite("edit_bg", G_SWIDTH/2 - getX(125), getY(350), this, 0, RATIO_XY);
    bgLastName = newSprite("edit_bg", G_SWIDTH/2 + getX(125), getY(350), this, 0, RATIO_XY);
    bgChildName = newSprite("edit_bg", G_SWIDTH/2 - getX(125), getY(460), this, 0, RATIO_XY);
    bgChildBirth = newSprite("edit_bg", G_SWIDTH/2 + getX(125), getY(460), this, 0, RATIO_XY);
    
    
    btnNew = newButton("newaccount", G_SWIDTH/2, getY(560), this, menu_selector(CreateAccLayer::onRecover), true, RATIO_XY);
    btnClose = newButton("close", getX(800), getY(180), this, menu_selector(CreateAccLayer::onClose), true, RATIO_XY);
    
    CCMenu *menu = CCMenu::create(btnClose, btnNew,  NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
    
    txtEmail = (CCTextFieldTTF*)CCTextFieldTTF::textFieldWithPlaceHolder("Email Address", CCSizeMake(200, 20), kCCTextAlignmentCenter, "Arial", 15);
    ::setScale(txtEmail, RATIO_XY);
    txtEmail->setDelegate(this);
    txtEmail->setPosition(bgEmail->getPosition());
    txtEmail->setColorSpaceHolder(ccGRAY);
    txtEmail->setColor(ccBLACK);
    this->addChild(txtEmail, 1);
    
    txtEmailConfirm = (CCTextFieldTTF*)CCTextFieldTTF::textFieldWithPlaceHolder("Retype Email", CCSizeMake(200, 20), kCCTextAlignmentCenter, "Arial", 15);
    ::setScale(txtEmailConfirm, RATIO_XY);
    txtEmailConfirm->setDelegate(this);
    txtEmailConfirm->setPosition(bgEmailConfirm->getPosition());
    txtEmailConfirm->setColorSpaceHolder(ccGRAY);
    txtEmailConfirm->setColor(ccBLACK);
    this->addChild(txtEmailConfirm, 1);
    
    txtPass = (CCTextFieldTTF*)CCTextFieldTTF::textFieldWithPlaceHolder("Password", CCSizeMake(200, 20), kCCTextAlignmentCenter, "Arial", 15);
    ::setScale(txtPass, RATIO_XY);
    txtPass->setDelegate(this);
    txtPass->setPosition(bgPass->getPosition());
    txtPass->setColorSpaceHolder(ccGRAY);
    txtPass->setColor(ccBLACK);
    this->addChild(txtPass, 1);
    
    txtPassConfirm = (CCTextFieldTTF*)CCTextFieldTTF::textFieldWithPlaceHolder("Retype Password", CCSizeMake(200, 20), kCCTextAlignmentCenter, "Arial", 15);
    ::setScale(txtPassConfirm, RATIO_XY);
    
    txtPassConfirm->setDelegate(this);
    txtPassConfirm->setPosition(bgPassConfirm->getPosition());
    txtPassConfirm->setColorSpaceHolder(ccGRAY);
    txtPassConfirm->setColor(ccBLACK);
    this->addChild(txtPassConfirm, 1);
    
    txtFirstName = (CCTextFieldTTF*)CCTextFieldTTF::textFieldWithPlaceHolder("First Name", CCSizeMake(200, 20), kCCTextAlignmentCenter, "Arial", 15);
    ::setScale(txtFirstName, RATIO_XY);
    txtFirstName->setDelegate(this);
    txtFirstName->setPosition(bgFirstName->getPosition());
    txtFirstName->setColorSpaceHolder(ccGRAY);
    txtFirstName->setColor(ccBLACK);
    this->addChild(txtFirstName, 1);
    
    txtLastName = (CCTextFieldTTF*)CCTextFieldTTF::textFieldWithPlaceHolder("Last Name", CCSizeMake(200, 20), kCCTextAlignmentCenter, "Arial", 15);
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
}

void CreateAccLayer::createMenu()
{

}

void CreateAccLayer::onRecover(){
    this->removeFromParentAndCleanup(true);
    g_lMenuScene->activateMenu();
    BridgeIOS::signup(txtEmail->getString(), txtPassConfirm->getString(), txtFirstName->getString(), txtChildName->getString(), txtChildBirth->getString());
}

void CreateAccLayer::onClose()
{
    g_lMenuScene->activateMenu();
    this->removeFromParentAndCleanup(true);
}


bool CreateAccLayer::ccTouchBegan(CCTouch *touch, CCEvent *event){

    CCPoint location = touch->getLocation();
    location = CCDirector::sharedDirector()->convertToGL(location);
    CCPoint touchLocation = CCPointMake(location.x, G_SHEIGHT-location.y - G_SCALEY*100);
    
    if (bgEmail->boundingBox().containsPoint(touchLocation)) {
        txtEmail->attachWithIME();
        txtEmail->setString("");
        return true;
    }
    if (bgEmailConfirm->boundingBox().containsPoint(touchLocation)) {
        txtEmailConfirm->attachWithIME();
        txtEmailConfirm->setString("");
        return true;
    }
    if (bgPass->boundingBox().containsPoint(touchLocation)) {
        txtPass->attachWithIME();
        txtPass->setString("");
        return true;
    }
    if (bgPassConfirm->boundingBox().containsPoint(touchLocation)) {
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
    return true;
}



void CreateAccLayer::registerWithTouchDispatcher(){
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool CreateAccLayer::onTextFieldAttachwithIME(CCTextFieldTTF *pSender)
{
    return false;
    
}
bool CreateAccLayer::onTextFieldDetachwithIME(CCTextFieldTTF *pSender)
{
    return false;
}
bool CreateAccLayer::onTextFieldInsertText(CCTextFieldTTF *pSender, const char *text, int nLen){
    return false;
}
bool CreateAccLayer::onTextFieldDeleteBackward(CCTextFieldTTF *pSender, const char *delText, int nLen){
    return false;
}
bool CreateAccLayer::onDraw(CCTextFieldTTF *pSender){
    return false;
}