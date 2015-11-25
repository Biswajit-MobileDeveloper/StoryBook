//
//  Picnic10.cpp
//  JoshEmma
//
//  Created by Biswajit Paul on 18/11/15.
//
//

#include "Picnic10.h"
#include "Picnic9.h"
#include "MenuScene.h"
#include "GameSettings.h"
#include "GameConfig.h"
#include "MenuScene.h"
#include "BridgeIOS.h"


USING_NS_CC;
CCScene* Picnic10::scene()
{
    CCScene *scene = CCScene::create();
    Picnic10 *layer = Picnic10::create();
    scene->addChild(layer);
    return scene;
}

bool Picnic10::init()
{
    if ( !CCLayer::init())
    {
        return false;
    }
    this->setTouchEnabled(true);
    createBg();
    createMenu();
    this->scheduleUpdate();
    return true;
}

void Picnic10::createBg()
{
    newSprite("picnic10-background", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    basketSprite = newSprite("picnic10-basket", getX(920), getY(500), this, 0, RATIO_XY);
    ballSprite = newSprite("picnic10-ball", getX(150), getY(350), this, 0, RATIO_XY);
    joshSprite = newSprite("picnic10-josh", getX(400), getY(380), this, 0, RATIO_XY);
    emmaSprite = newSprite("picnic10-emma", getX(800), getY(380), this, 0, RATIO_XY);
    
    lbFirst = newLabel("Josh and Emma loved their special picnic lunch.", "Arial", 40, G_SWIDTH/2, getY(530), this, 1, RATIO_X);
    lbFirst->setOpacity(0);
    
    labelBackgroundSprite = newSprite("white-1-pixel", G_SWIDTH/2, getY(530), this, 0, RATIO_XY);
    CCSize labelSize = lbFirst->getContentSize();
    labelBackgroundSprite->setScaleX(labelSize.width);
    labelBackgroundSprite->setScaleY(40);
    //labelBackgroundSprite->setOpacity(30);
    labelBackgroundSprite->setVisible(false);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this,callfunc_selector(Picnic10::playEffect1)), CCFadeIn::create(0.5f), CCCallFunc::create(this,callfunc_selector(Picnic10::SetvisibilityForTextBackground1)), NULL));
}


void Picnic10::playEffect1()
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Picnic_10_a.mp3");
}

void Picnic10::playEffect2(){
}


void Picnic10::update( float dt)
{
    deltaTimeForJosh += dt;
    deltaTimeForEmma += dt;
    if (deltaTimeForJosh >= 4.0 )
    {
        joshSprite->setPosition(ccp(getX(400), getY(380)));
        joshSprite->runAction(CCSequence::create(CCJumpBy::create(1.f, ccp(0, 0), 100*G_SCALEY, 1), NULL));
        deltaTimeForJosh = 0;
        // jumpNumberForJosh++;
    }
    
    if (deltaTimeForEmma >= 4.0 )
    {
        emmaSprite->setPosition(ccp(getX(800), getY(380)));
        emmaSprite->runAction(CCSequence::create(CCJumpBy::create(1.f, ccp(0, 0), 100*G_SCALEY, 1), NULL));
        deltaTimeForEmma = 0;
        //jumpNumberForEmma++;
    }
}

void Picnic10::SetvisibilityForTextBackground1()
{
    labelBackgroundSprite->setVisible(true);
}

void Picnic10::SetvisibilityForTextBackground2()
{
    labelBackgroundSpriteForlabel2->setVisible(true);
}



void Picnic10::createMenu()
{
    btnBack = newButton("back", getX(100), getY(600), this, menu_selector(Picnic10::onBack), false, RATIO_X);
    btnNext = newButton("next", G_SWIDTH - getX(100), getY(600), this, menu_selector(Picnic10::onNext), false, RATIO_X);
    
    CCMenuItemImage *btnHome = newButton("home", getX(100), getY(70), this, menu_selector(Picnic10::onHome), false, RATIO_X);
    //        btnHome->setOpacity(120);
    
    menu = CCMenu::create(btnNext,btnBack, btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Picnic10::onHome()
{
    BridgeIOS::showHomeAlert();
}

void Picnic10::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Picnic9::scene(), true));
}

void Picnic10::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, MenuScene::scene(), false));
}

void Picnic10::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Picnic10::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    if (ballSprite->boundingBox().containsPoint(touchLocation)) {
        ballSprite->stopAllActions();
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("ball.wav");
    }
    
    if (joshSprite->boundingBox().containsPoint(touchLocation)) {
        joshSprite->stopAllActions();
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("laugh.wav");
    }
    
    if (emmaSprite->boundingBox().containsPoint(touchLocation)) {
        emmaSprite->stopAllActions();
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("laugh.wav");
    }
    
    return false;
}