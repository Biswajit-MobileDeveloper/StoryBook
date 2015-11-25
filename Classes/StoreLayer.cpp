//
//  StoreLayer.cpp
//  JoshEmma
//
//  Created by Rijing on 4/23/15.
//
//

#include "StoreLayer.h"
#include "cocos2d.h"

#include "GameConfig.h"
#include "GameSettings.h"
#include "MenuScene.h"


USING_NS_CC;
CCScene* StoreLayer::scene()
{
    CCScene *scene = CCScene::create();
    StoreLayer *layer = StoreLayer::create();
    scene->addChild(layer);
    return scene;
}
bool StoreLayer::init()
{
    if ( !CCLayer::init())
    {
        return false;
    }
    createBg();
    return true;
}

void StoreLayer::createBg(){
    
    newSprite("setting_bg", G_SWIDTH/2, G_SHEIGHT/2, this, 0, RATIO_XY);
    newLabel("Store", "Arial MT", 50, G_SWIDTH/2, getY(220), this, 0, RATIO_XY);

    lbEnglish = newLabel("English", "Arial MT", 30, G_SWIDTH/2 - getX(180), getY(320), this, 0, RATIO_XY);
    lbSpanish = newLabel("Spanish", "Arial MT", 30, G_SWIDTH/2 - getX(180), getY(400), this, 0, RATIO_XY);

    lbEnglish->setAnchorPoint(ccp(0, 0.5f));
    lbSpanish->setAnchorPoint(ccp(0, 0.5f));
    
    btnEnglish = newButton("select", G_SWIDTH/2 + getX(120), getY(320), this, menu_selector(StoreLayer::onClose), true, RATIO_XY);
    btnEnglish->setScale(0.8*G_SCALEX);
    btnSpanish = newButton("buy", G_SWIDTH/2 + getX(120), getY(400), this, menu_selector(StoreLayer::onClose), true, RATIO_XY);
    btnSpanish->setScale(0.8*G_SCALEX);
    btnClose = newButton("close", getX(800), getY(180), this, menu_selector(StoreLayer::onClose), true, RATIO_XY);
    
    CCMenu *menu = CCMenu::create(btnClose,btnEnglish,btnSpanish, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void StoreLayer::onClose()
{
    g_lPlayScene->activateMenu();
    this->removeFromParentAndCleanup(true);
}