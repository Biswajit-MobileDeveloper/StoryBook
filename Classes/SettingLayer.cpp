//
//  SettingLayer.cpp
//  JoshEmma
//
//  Created by Rijing on 4/13/15.
//
//

#include "SettingLayer.h"
#include "GameConfig.h"
#include "GameSettings.h"
#include "MenuScene.h"


USING_NS_CC;
CCScene* SettingLayer::scene()
{
    CCScene *scene = CCScene::create();
    SettingLayer *layer = SettingLayer::create();
    scene->addChild(layer);
    return scene;
}
bool SettingLayer::init()
{
    if ( !CCLayer::init())
    {
        return false;
    }
    createBg();
    createMenu();
    return true;
}

void SettingLayer::createBg(){
    
//    CCLayerColor *lyMask = CCLayerColor::create(ccc4(0, 0, 0, 100));
//    lyMask->setPosition(ccp(0, 0));
//    this->addChild(lyMask, -1);
    
    newSprite("setting_bg", G_SWIDTH/2, G_SHEIGHT/2, this, 0, RATIO_XY);
    newLabel("Settings", "Arial MT", 45, G_SWIDTH/2, getY(220), this, 0, RATIO_XY);
    newLabel("Speech", "Arial MT", 40, G_SWIDTH/2 - getX(100), getY(300), this, 0, RATIO_Y);
    newLabel("Autoplay", "Arial MT", 40, G_SWIDTH/2 - getX(100), getY(360), this, 0, RATIO_Y);
    
    btnSpeech= newToggleButton("switch", G_SWIDTH/2 + getX(100), getY(300), this, menu_selector(SettingLayer::onSound), true, RATIO_Y);
    if(!g_bSound){
        btnSpeech->setSelectedIndex(1.0f);
    }
    
    btnAuto = newToggleButton("switch", G_SWIDTH/2 + getX(100), getY(360), this, menu_selector(SettingLayer::onAuto), true, RATIO_Y);
    if(!g_bAuto){
        btnAuto->setSelectedIndex(1.0f);
    }
    
    
    btnFeedback = newButton("feedback", G_SWIDTH/2, getY(430), this, menu_selector(SettingLayer::onRate), false, RATIO_Y);
    btnCredit = newButton("credit", G_SWIDTH/2, getY(500), this, menu_selector(SettingLayer::onCredit), false, RATIO_Y);
    btnClose = newButton("close", getX(800), getY(180), this, menu_selector(SettingLayer::onClose), true, RATIO_XY);
    
    CCMenu *menu = CCMenu::create(btnSpeech, btnAuto, btnFeedback, btnCredit, btnClose,  NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
    
    
}

void SettingLayer::onSpeech(){
    
}

void SettingLayer::createMenu(){

}

void SettingLayer::onCredit()
{
    
}

void SettingLayer::onRate()
{
    
}

void SettingLayer::onSound()
{
    g_bSound = !g_bSound;
    
    if(g_bSound){
        SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(1.f);
        SimpleAudioEngine::sharedEngine()->setEffectsVolume(1.0f);
        
    }
    else
    {
        SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.f);
        SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.0f);
    }
}

void SettingLayer::onAuto()
{
    g_bAuto =! g_bAuto;
}

void SettingLayer::onClose()
{
    g_lPlayScene->activateMenu();
    this->removeFromParentAndCleanup(true);
}

