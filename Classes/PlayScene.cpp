//
//  PlayScene.cpp
//  JoshEmma
//
//  Created by Biswajit Paul on 12/11/15.
//
//

#include "PlayScene.h"

#include "SettingLayer.h"
#include "CreditLayer.h"
#include "StoreLayer.h"
#include "MenuScene.h"
//#include "LoginLayer.h"
#include "Level11.h"
//#include "RecoverLayer.h"
//#include "CreateAccLayer.h"
//#include "EditAccLayer.h"
#include "BridgeIOS.h"
#include "GameSettingsForLession1.h"
#include "GameConfig.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;


CCScene* PlayScene::scene()
{
    CCScene *scene = CCScene::create();
    PlayScene *layer = PlayScene::create();
    scene->addChild(layer);
    return scene;
}
bool PlayScene::init()
{
    if ( !CCLayer::init())
    {
        return false;
    }
    
    //    this->setTouchEnabled(true);
    g_lPlayScene = this;
    createBg();
    createMenu();
    
    return true;
}

void PlayScene::createBg()
{
    newSpriteForLession1("main_bg", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    lyDash = CCLayer::create();
    lyDash->setPosition(ccp(G_SWIDTH/2, 0));
    this->addChild(lyDash, 2);
    CCSprite*dash_bg = newSpriteForLession1("dash_bg", G_SWIDTH, G_SHEIGHT/2, lyDash, 0, RATIO_XY);
    dash_bg->setAnchorPoint(ccp(1.0f, 0.5f));
    
    
    CCMenuItemImage *iAccount = newButtonForLession1("account", getXForLession1(885), getYForLession1(250), this, menu_selector(PlayScene::onAccount), true, RATIO_X);
    CCMenuItemImage *iChangePass = newButtonForLession1("editPass", getXForLession1(885), getXForLession1(350), this, menu_selector(PlayScene::onChangePassword), true, RATIO_X);
    
    CCMenuItemImage *iSetting = newButtonForLession1("setting", getXForLession1(885), getYForLession1(450), this, menu_selector(PlayScene::onSetting), true, RATIO_X);
    CCMenuItemImage *iStore = newButtonForLession1("store", getXForLession1(885), getYForLession1(550), this, menu_selector(PlayScene::onStore), true, RATIO_X);
    CCMenuItemImage *iClose = newButtonForLession1("close1", getXForLession1(740), getYForLession1(30), this, menu_selector(PlayScene::onClose), true, RATIO_X);
    
    iLogout = newButtonForLession1("logout", getXForLession1(885), getYForLession1(640), this, menu_selector(PlayScene::onLogout), true, RATIO_X);
    iLogin = newButtonForLession1("login", getXForLession1(885), getYForLession1(640), this, menu_selector(PlayScene::onLogout), true, RATIO_X);
    
    
    menu_dash = CCMenu::create(iAccount,iSetting,iStore,iLogout,iLogin,iClose,iChangePass, NULL);
    menu_dash->setPosition(ccp(0, 0));
    lyDash->addChild(menu_dash, 0);
}

void PlayScene::onClose(){
    menu->setEnabled(true);
    lyDash->runAction(CCMoveTo::create(0.5f, ccp(G_SWIDTH/2, 0)));
}

void PlayScene::onLogout(){
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

void PlayScene::onChangePassword()
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

void PlayScene::createMenu()
{
    iStart = newButtonForLession1("play", G_SWIDTH - getXForLession1(330), getYForLession1(630), this, menu_selector(PlayScene::onPlay), false, RATIO_X);
    iPlay = newButtonForLession1("dashboard", getXForLession1(330), getYForLession1(630), this, menu_selector(PlayScene::onMoreLesson), true, RATIO_X);
    iTrigger = newButtonForLession1("trigger", G_SWIDTH - getXForLession1(50), getYForLession1(50), this, menu_selector(PlayScene::onDashboard), true, RATIO_X);
    
    menu = CCMenu::create(iStart,iPlay,iTrigger, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
    
    if(!BridgeIOS::getLoginSession()){
        BridgeIOS::showlogin();
        iLogin->setVisible(true);
        iLogout->setVisible(false);
        
    }
    else
    {
        iLogin->setVisible(false);
        iLogout->setVisible(true);
    }
}

void PlayScene::onMoreLesson()
{
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f, MenuScene::scene(), false));
}

void PlayScene::onPlay(){
    if (BridgeIOS::getLoginSession()||BridgeIOS::getIsGuest()) {
        SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
        CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f, Level11::scene(), false));
        return;
    }
    BridgeIOS::showlogin();
}

void PlayScene::onDashboard(){
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

void PlayScene::onSetting()
{
    SettingLayer *settingLayer = SettingLayer::create();
    settingLayer->setPosition(ccp(0, -G_SHEIGHT));
    this->addChild(settingLayer, 0);
    settingLayer->runAction(CCMoveTo::create(0.5f, ccp(0, 0)));
    lyDash->runAction(CCMoveTo::create(0.5f, ccp(G_SWIDTH/2, 0)));
}

void PlayScene::activateMenu()
{
    menu->setEnabled(true);
    
}

void PlayScene::showRecovery(){
    //    RecoverLayer *layer = RecoverLayer::create();
    //    layer->setPosition(ccp(0, -G_SHEIGHT));
    //    this->addChild(layer, 0);
    //    layer->runAction(CCMoveTo::create(0.5f, ccp(0, 0)));
}

void PlayScene::showCreatePage(){
    //    CreateAccLayer *layer = CreateAccLayer::create();
    //    layer->setPosition(ccp(0, -G_SHEIGHT));
    //    this->addChild(layer, 0);
    //    layer->runAction(CCMoveTo::create(0.5f, ccp(0, 0)));
}

void PlayScene::onAccount(){
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

void PlayScene::onStore(){
    StoreLayer *storeLayer = StoreLayer::create();
    storeLayer->setPosition(ccp(0, -G_SHEIGHT));
    this->addChild(storeLayer, 0);
    storeLayer->runAction(CCMoveTo::create(0.5f, ccp(0, 0)));
    lyDash->runAction(CCMoveTo::create(0.5f, ccp(G_SWIDTH/2, 0)));
}


