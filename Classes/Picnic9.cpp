//
//  Picnic9.cpp
//  JoshEmma
//
//  Created by Biswajit Paul on 18/11/15.
//
//

#include "Picnic9.h"
#include "Picnic8.h"
#include "Picnic10.h"
#include "GameSettings.h"
#include "GameConfig.h"
#include "MenuScene.h"
#include "BridgeIOS.h"


USING_NS_CC;
CCScene* Picnic9::scene()
{
    CCScene *scene = CCScene::create();
    Picnic9 *layer = Picnic9::create();
    scene->addChild(layer);
    return scene;
}

bool Picnic9::init()
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

void Picnic9::createBg()
{
    newSprite("picnic09-backgroundt", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    pitaSprite = newSprite("picnic09-pita", getX(500), getY(340), this, 0, RATIO_XY);
    juiceSprite = newSprite("picnic09-juice", getX(150), getY(180), this, 0, RATIO_XY);
    pretzelsSprite = newSprite("picnic09-pretzels", getX(200), getY(480), this, 0, RATIO_XY);
    peachSprite = newSprite("picnic09-peach", getX(930), getY(500), this, 0, RATIO_XY);
    pastaSprite = newSprite("picnic09-pasta", getX(930), getY(180), this, 0, RATIO_XY);
    lbFirst = newLabel("What’s special about this picnic? Oh, I see! Everything..", "Arial", 35, G_SWIDTH/2, getY(530), this, 1, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabel("starts with the letter P, just like the word picnic.", "Arial", 35, G_SWIDTH/2, getY(580), this, 1, RATIO_X);
    lbSecond->setOpacity(0);
    
    labelBackgroundSprite = newSprite("white-1-pixel", G_SWIDTH/2, getY(530), this, 0, RATIO_XY);
    labelBackgroundSpriteForlabel2 = newSprite("white-1-pixel", G_SWIDTH/2, getY(580), this, 0, RATIO_XY);
    CCSize labelSize = lbFirst->getContentSize();
    CCSize labelSize2 = lbSecond->getContentSize();
    labelBackgroundSprite->setScaleX(labelSize.width);
    labelBackgroundSprite->setScaleY(40);
   // labelBackgroundSprite->setOpacity(30);
    labelBackgroundSpriteForlabel2->setScaleX(labelSize2.width);
    labelBackgroundSpriteForlabel2->setScaleY(40);
   // labelBackgroundSpriteForlabel2->setOpacity(30);
    labelBackgroundSpriteForlabel2->setVisible(false);
    labelBackgroundSprite->setVisible(false);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this,callfunc_selector(Picnic9::playEffect1)), CCFadeIn::create(0.5f), CCCallFunc::create(this,callfunc_selector(Picnic9::SetvisibilityForTextBackground1)), NULL));
    lbSecond->runAction(CCSequence::create(CCDelayTime::create(4.0f), CCCallFunc::create(this,callfunc_selector(Picnic9::playEffect2)),CCFadeIn::create(1.0f), CCCallFunc::create(this,callfunc_selector(Picnic9::SetvisibilityForTextBackground2)), NULL));
}


void Picnic9::playEffect1()
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Picnic_09_a.mp3");
}

void Picnic9::playEffect2(){
}


void Picnic9::SetvisibilityForTextBackground1()
{
    labelBackgroundSprite->setVisible(true);
}

void Picnic9::SetvisibilityForTextBackground2()
{
    labelBackgroundSpriteForlabel2->setVisible(true);
}



void Picnic9::createMenu()
{
    btnBack = newButton("back", getX(100), getY(600), this, menu_selector(Picnic9::onBack), false, RATIO_X);
    btnNext = newButton("next", G_SWIDTH - getX(100), getY(600), this, menu_selector(Picnic9::onNext), false, RATIO_X);
    
    CCMenuItemImage *btnHome = newButton("home", getX(100), getY(70), this, menu_selector(Picnic9::onHome), false, RATIO_X);
    //        btnHome->setOpacity(120);
    
    menu = CCMenu::create(btnNext,btnBack, btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Picnic9::onHome()
{
    BridgeIOS::showHomeAlert();
}

void Picnic9::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Picnic8::scene(), true));
}

void Picnic9::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Picnic10::scene(), false));
}

void Picnic9::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Picnic9::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
        CCPoint touchLocation = touch->getLocationInView();
        touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
        if (juiceSprite->boundingBox().containsPoint(touchLocation)) {
            juiceSprite->stopAllActions();
            SimpleAudioEngine::sharedEngine()->stopAllEffects();
            SimpleAudioEngine::sharedEngine()->playEffect("Picnic_04_a.mp3");
         }
    
        if (pitaSprite->boundingBox().containsPoint(touchLocation)) {
            pitaSprite->stopAllActions();
            SimpleAudioEngine::sharedEngine()->stopAllEffects();
            SimpleAudioEngine::sharedEngine()->playEffect("Picnic_05_a.mp3");
        }
    
        if (pastaSprite->boundingBox().containsPoint(touchLocation)) {
            pastaSprite->stopAllActions();
            SimpleAudioEngine::sharedEngine()->stopAllEffects();
            SimpleAudioEngine::sharedEngine()->playEffect("Picnic_07_a.mp3");
        }
    
        if (pretzelsSprite->boundingBox().containsPoint(touchLocation)) {
            pretzelsSprite->stopAllActions();
            SimpleAudioEngine::sharedEngine()->stopAllEffects();
            SimpleAudioEngine::sharedEngine()->playEffect("Picnic_06_a.mp3");
        }
    
        if (peachSprite->boundingBox().containsPoint(touchLocation)) {
            peachSprite->stopAllActions();
            SimpleAudioEngine::sharedEngine()->stopAllEffects();
            SimpleAudioEngine::sharedEngine()->playEffect("Picnic_08_a.mp3");
        }
    return false;
}