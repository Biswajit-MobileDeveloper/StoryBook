//
//  Picnic7.cpp
//  JoshEmma
//
//  Created by Biswajit Paul on 18/11/15.
//
//

#include "Picnic7.h"
#include "Picnic6.h"
#include "Picnic8.h"
#include "GameSettings.h"
#include "GameConfig.h"
#include "MenuScene.h"
#include "BridgeIOS.h"


USING_NS_CC;
CCScene* Picnic7::scene()
{
    CCScene *scene = CCScene::create();
    Picnic7 *layer = Picnic7::create();
    scene->addChild(layer);
    return scene;
}

bool Picnic7::init()
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

void Picnic7::createBg()
{
    newSprite("picnic07-backgroundt", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    lbFirst = newLabel("Emma loves Mom’s pasta salad.", "Arial", 40, G_SWIDTH/2, getY(530), this, 1, RATIO_X);
    lbFirst->setOpacity(0);
    labelBackgroundSprite = newSprite("white-1-pixel", G_SWIDTH/2, getY(530), this, 0, RATIO_XY);
     CCSize labelSize = lbFirst->getContentSize();
    labelBackgroundSprite->setScaleX(labelSize.width);
    labelBackgroundSprite->setScaleY(40);
    //labelBackgroundSprite->setOpacity(30);
    labelBackgroundSprite->setVisible(false);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this,callfunc_selector(Picnic7::playEffect1)), CCFadeIn::create(0.5f), CCCallFunc::create(this,callfunc_selector(Picnic7::SetvisibilityForTextBackground1)), NULL));
   // lbSecond->runAction(CCSequence::create(CCDelayTime::create(3.0f), CCCallFunc::create(this,callfunc_selector(Picnic7::playEffect2)),CCFadeIn::create(1.0f), CCCallFunc::create(this,callfunc_selector(Picnic7::SetvisibilityForTextBackground2)), NULL));
}


void Picnic7::playEffect1()
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Picnic_07_a.mp3");
}

void Picnic7::playEffect2(){
}


void Picnic7::SetvisibilityForTextBackground1()
{
    labelBackgroundSprite->setVisible(true);
}


void Picnic7::createMenu()
{
    btnBack = newButton("back", getX(100), getY(600), this, menu_selector(Picnic7::onBack), false, RATIO_X);
    btnNext = newButton("next", G_SWIDTH - getX(100), getY(600), this, menu_selector(Picnic7::onNext), false, RATIO_X);
    
    CCMenuItemImage *btnHome = newButton("home", getX(100), getY(70), this, menu_selector(Picnic7::onHome), false, RATIO_X);
    //        btnHome->setOpacity(120);
    
    menu = CCMenu::create(btnNext,btnBack, btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Picnic7::onHome()
{
    BridgeIOS::showHomeAlert();
}

void Picnic7::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Picnic6::scene(), true));
}

void Picnic7::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Picnic8::scene(), false));
}

void Picnic7::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Picnic7::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    //    CCPoint touchLocation = touch->getLocationInView();
    //    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    //    if (spSun->boundingBox().containsPoint(touchLocation)) {
    //        spSun->stopAllActions();
    //        SimpleAudioEngine::sharedEngine()->stopAllEffects();
    //        SimpleAudioEngine::sharedEngine()->playEffect("sun.wav");
    //        spSun->runAction(CCRotateBy::create(1.0f, 360.f));
    //    }
    return false;
}