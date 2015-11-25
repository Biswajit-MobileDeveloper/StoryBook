//
//  Picnic6.cpp
//  JoshEmma
//
//  Created by Biswajit Paul on 18/11/15.
//
//

#include "Picnic6.h"
#include "Picnic5.h"
#include "Picnic7.h"
#include "GameSettings.h"
#include "GameConfig.h"
#include "MenuScene.h"
#include "BridgeIOS.h"


USING_NS_CC;
CCScene* Picnic6::scene()
{
    CCScene *scene = CCScene::create();
    Picnic6 *layer = Picnic6::create();
    scene->addChild(layer);
    return scene;
}

bool Picnic6::init()
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

void Picnic6::createBg()
{
    newSprite("picnic06-backgroundt", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    lbFirst = newLabel("Pretzels are a great salty,", "Arial", 40, G_SWIDTH/2, getY(530), this, 1, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabel("crunchy side to go with our sandwiches.", "Arial", 40, G_SWIDTH/2, getY(580), this, 1, RATIO_X);
    lbSecond->setOpacity(0);
    
    labelBackgroundSprite = newSprite("white-1-pixel", G_SWIDTH/2, getY(530), this, 0, RATIO_XY);
    labelBackgroundSpriteForlabel2 = newSprite("white-1-pixel", G_SWIDTH/2, getY(580), this, 0, RATIO_XY);
    CCSize labelSize = lbFirst->getContentSize();
    CCSize labelSize2 = lbSecond->getContentSize();
    labelBackgroundSprite->setScaleX(labelSize.width);
    labelBackgroundSprite->setScaleY(40);
    //labelBackgroundSprite->setOpacity(30);
    labelBackgroundSpriteForlabel2->setScaleX(labelSize2.width);
    labelBackgroundSpriteForlabel2->setScaleY(40);
   // labelBackgroundSpriteForlabel2->setOpacity(30);
    labelBackgroundSpriteForlabel2->setVisible(false);
    labelBackgroundSprite->setVisible(false);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this,callfunc_selector(Picnic6::playEffect1)), CCFadeIn::create(0.5f), CCCallFunc::create(this,callfunc_selector(Picnic6::SetvisibilityForTextBackground1)), NULL));
    lbSecond->runAction(CCSequence::create(CCDelayTime::create(3.0f), CCCallFunc::create(this,callfunc_selector(Picnic6::playEffect2)),CCFadeIn::create(1.0f), CCCallFunc::create(this,callfunc_selector(Picnic6::SetvisibilityForTextBackground2)), NULL));
}


void Picnic6::playEffect1()
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Picnic_06_a.mp3");
}

void Picnic6::playEffect2(){
}


void Picnic6::SetvisibilityForTextBackground1()
{
    labelBackgroundSprite->setVisible(true);
}

void Picnic6::SetvisibilityForTextBackground2()
{
    labelBackgroundSpriteForlabel2->setVisible(true);
}



void Picnic6::createMenu()
{
    btnBack = newButton("back", getX(100), getY(600), this, menu_selector(Picnic6::onBack), false, RATIO_X);
    btnNext = newButton("next", G_SWIDTH - getX(100), getY(600), this, menu_selector(Picnic6::onNext), false, RATIO_X);
    
    CCMenuItemImage *btnHome = newButton("home", getX(100), getY(70), this, menu_selector(Picnic6::onHome), false, RATIO_X);
    //        btnHome->setOpacity(120);
    
    menu = CCMenu::create(btnNext,btnBack, btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Picnic6::onHome()
{
    BridgeIOS::showHomeAlert();
}

void Picnic6::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Picnic5::scene(), true));
}

void Picnic6::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Picnic7::scene(), false));
}

void Picnic6::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Picnic6::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
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