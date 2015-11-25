//
//  MenuScene.cpp
//  JoshEmma
//
//  Created by Rijing on 4/13/15.
//
//

#include "MenuScene.h"
#include "SettingLayer.h"
#include "CreditLayer.h"
#include "StoreLayer.h"
//#include "LoginLayer.h"
#include "Level11.h"
#include "Slide1.h"
#include "Picnic1.h"
//#include "RecoverLayer.h"
//#include "CreateAccLayer.h"
//#include "EditAccLayer.h"
#include "BridgeIOS.h"

#include "GameSettings.h"
#include "GameConfig.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;


CCScene* MenuScene::scene()
{
    CCScene *scene = CCScene::create();
    MenuScene *layer = MenuScene::create();
    scene->addChild(layer);
    return scene;
}
bool MenuScene::init()
{
    if ( !CCLayer::init())
    {
        return false;
    }

//    this->setTouchEnabled(true);
    //g_lPlayScene = this;
    createBg();
    createMenu();
    
    return true;
}

void MenuScene::createBg()
{
    newSprite("background", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
//    lyDash = CCLayer::create();
//    lyDash->setPosition(ccp(G_SWIDTH/2, 0));
//    this->addChild(lyDash, 2);
//    CCSprite*dash_bg = newSprite("dash_bg", G_SWIDTH, G_SHEIGHT/2, lyDash, 0, RATIO_XY);
//    dash_bg->setAnchorPoint(ccp(1.0f, 0.5f));
//    
//
//    CCMenuItemImage *iAccount = newButton("account", getX(1000), getY(150), this, menu_selector(MenuScene::onAccount), true, RATIO_X);
//    CCMenuItemImage *iChangePass = newButton("editPass", getX(1000), getY(250), this, menu_selector(MenuScene::onChangePassword), true, RATIO_X);
//
//    CCMenuItemImage *iSetting = newButton("setting", getX(1000), getY(350), this, menu_selector(MenuScene::onSetting), true, RATIO_X);
//    CCMenuItemImage *iStore = newButton("store", getX(1000), getY(450), this, menu_selector(MenuScene::onStore), true, RATIO_X);
//    CCMenuItemImage *iClose = newButton("close1", getX(860), getY(30), this, menu_selector(MenuScene::onClose), true, RATIO_X);
//    
//    iLogout = newButton("logout", getX(1000), getY(540), this, menu_selector(MenuScene::onLogout), true, RATIO_X);
//    iLogin = newButton("login", getX(1000), getY(540), this, menu_selector(MenuScene::onLogout), true, RATIO_X);
//    
//    
//    menu_dash = CCMenu::create(iAccount,iSetting,iStore,iLogout,iLogin,iClose,iChangePass, NULL);
//    menu_dash->setPosition(ccp(0, 0));
//    lyDash->addChild(menu_dash, 0);
}

void MenuScene::onClose(){
    menu->setEnabled(true);
    lyDash->runAction(CCMoveTo::create(0.5f, ccp(G_SWIDTH/2, 0)));
}

void MenuScene::onLogout(){
    menu->setEnabled(true);
    lyDash->runAction(CCMoveTo::create(0.5f, ccp(G_SWIDTH/2, 0)));
    if(!BridgeIOS::getLoginSession()){
        BridgeIOS::showlogin();
        
    }
    else
    {
        BridgeIOS::logout();
    }

}

void MenuScene::onChangePassword()
{
    menu->setEnabled(true);
    lyDash->runAction(CCMoveTo::create(0.5f, ccp(G_SWIDTH/2, 0)));
//    if(!BridgeIOS::getLoginSession()){
//        BridgeIOS::showlogin();
//        
//    }
//    else
//    {
        BridgeIOS::showEditPass();
//    }
    
}

void MenuScene::createMenu()
{
//    iStart = newButton("play", G_SWIDTH - getX(330), getY(630), this, menu_selector(MenuScene::onPlay), false, RATIO_X);
//    iPlay = newButton("dashboard", getX(330), getY(630), this, menu_selector(MenuScene::onMoreLesson), true, RATIO_X);
    iTrigger = newButton("trigger", G_SWIDTH - getX(50), getY(50), this, menu_selector(MenuScene::onDashboard), true, RATIO_X);
    
     jeOnTheBeach = newButton("beach", getX(128), G_SHEIGHT/2, this, menu_selector(MenuScene::onFirstLession), true, RATIO_X);
    jeRideTheTrain = newButton("train", getX(348), G_SHEIGHT/2, this, menu_selector(MenuScene::onSecondLession), true, RATIO_X);
    jeHaveAPicnic = newButton("picnic", getX(568), G_SHEIGHT/2, this, menu_selector(MenuScene::onThirdLession), true, RATIO_X);
    jeGoToTheZoo = newButton("zoo", getX(778), G_SHEIGHT/2, this, menu_selector(MenuScene::onFourthLession), true, RATIO_X);
    jeFlyAKite = newButton("kite", getX(1008), G_SHEIGHT/2, this, menu_selector(MenuScene::onFifthLession), true, RATIO_X);
    
    menu = CCMenu::create(iTrigger, jeOnTheBeach, jeFlyAKite, jeGoToTheZoo, jeHaveAPicnic, jeRideTheTrain, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
    
//    if(!BridgeIOS::getLoginSession()){
//        BridgeIOS::showlogin();
//        iLogin->setVisible(true);
//        iLogout->setVisible(false);
//
//    }
//    else
//    {
//        iLogin->setVisible(false);
//        iLogout->setVisible(true);
//    }
}

void MenuScene::onMoreLesson()
{
    BridgeIOS::showMoreLesson();
}

void MenuScene::onFirstLession()
{
    if (BridgeIOS::getLoginSession()||BridgeIOS::getIsGuest()) {
        SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
        CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f, Level11::scene(), false));
        return;
    }
    BridgeIOS::showlogin();
}

void MenuScene::onSecondLession()
{
    if (BridgeIOS::getLoginSession()||BridgeIOS::getIsGuest()) {
        SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
        CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f, Slide1::scene(), false));
        return;
    }
    BridgeIOS::showlogin();
}

void MenuScene::onThirdLession()
{
    if (BridgeIOS::getLoginSession()||BridgeIOS::getIsGuest()) {
        SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
        CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f, Picnic1::scene(), false));
        return;
    }
    BridgeIOS::showlogin();
}

void MenuScene::onFourthLession()
{
//    if (BridgeIOS::getLoginSession()||BridgeIOS::getIsGuest()) {
//        SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
//        CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f, Slide1::scene(), false));
//        return;
//    }
//    BridgeIOS::showlogin();
}

void MenuScene::onFifthLession()
{
//    if (BridgeIOS::getLoginSession()||BridgeIOS::getIsGuest()) {
//        SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
//        CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f, Slide1::scene(), false));
//        return;
//    }
//    BridgeIOS::showlogin();
}



void MenuScene::onDashboard(){
    menu->setEnabled(false);
    lyDash->runAction(CCMoveTo::create(0.5f, ccp(0, 0)));
    if(!BridgeIOS::getLoginSession()){
        iLogin->setVisible(true);
        iLogout->setVisible(false);
    }
    else
    {
        iLogin->setVisible(false);
        iLogout->setVisible(true);
    }
}

void MenuScene::onSetting()
{
    SettingLayer *settingLayer = SettingLayer::create();
    settingLayer->setPosition(ccp(0, -G_SHEIGHT));
    this->addChild(settingLayer, 0);
    settingLayer->runAction(CCMoveTo::create(0.5f, ccp(0, 0)));
    lyDash->runAction(CCMoveTo::create(0.5f, ccp(G_SWIDTH/2, 0)));
}

void MenuScene::activateMenu()
{
    menu->setEnabled(true);
    
}

void MenuScene::showRecovery(){
//    RecoverLayer *layer = RecoverLayer::create();
//    layer->setPosition(ccp(0, -G_SHEIGHT));
//    this->addChild(layer, 0);
//    layer->runAction(CCMoveTo::create(0.5f, ccp(0, 0)));
}

void MenuScene::showCreatePage(){
//    CreateAccLayer *layer = CreateAccLayer::create();
//    layer->setPosition(ccp(0, -G_SHEIGHT));
//    this->addChild(layer, 0);
//    layer->runAction(CCMoveTo::create(0.5f, ccp(0, 0)));
}

void MenuScene::onAccount(){
//    if(!BridgeIOS::getLoginSession()) return;
    menu->setEnabled(true);
    lyDash->runAction(CCMoveTo::create(0.5f, ccp(G_SWIDTH/2, 0)));
    if(!BridgeIOS::getLoginSession()){
        BridgeIOS::showlogin();
        
    }
    else
    {
        BridgeIOS::showEdit();
    }
}

void MenuScene::onStore(){
    StoreLayer *storeLayer = StoreLayer::create();
    storeLayer->setPosition(ccp(0, -G_SHEIGHT));
    this->addChild(storeLayer, 0);
    storeLayer->runAction(CCMoveTo::create(0.5f, ccp(0, 0)));
    lyDash->runAction(CCMoveTo::create(0.5f, ccp(G_SWIDTH/2, 0)));
}


