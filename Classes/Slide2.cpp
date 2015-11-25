//
//  Slide2.cpp
//  JoshEmma
//
//  Created by Biswajit Paul on 03/11/15.
//
//

#include "Slide2.h"

#include "GameSettings.h"
#include "GameConfig.h"
#include "Slide1.h"
#include "Slide3.h"
#include "BridgeIOS.h"

USING_NS_CC;
CCScene* Slide2::scene()
{
    CCScene *scene = CCScene::create();
    Slide2 *layer = Slide2::create();
    scene->addChild(layer);
    return scene;
}
bool Slide2::init()
{
    if ( !CCLayer::init())
    {
        return false;
    }
    this->setTouchEnabled(true);
    createBg();
    createMenu();
    deltaTime = 0.0;
    return true;
}

void Slide2::createBg()
{
    newSprite("slide02-background", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    trainSprite = newSprite("slide02-train", G_SWIDTH/2, getY(275), this, 0, RATIO_XY);
    joshAndEmmaSprite = newSprite("slide02-joshemma", G_SWIDTH/2, getY(550), this, 0, RATIO_XY);
    lbFirst = newLabel("Josh and Emma wait to ride on the train. As it pulls into the station,", "Arial", 35, G_SWIDTH/2, getY(530), this, 1, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabel("riders wave and the conductor blows the whistle.", "Arial", 35, G_SWIDTH/2, getY(580), this, 1, RATIO_X);
    lbSecond->setOpacity(0);
    
    labelBackgroundSprite = newSprite("white-1-pixel", G_SWIDTH/2, getY(530), this, 0, RATIO_XY);
    labelBackgroundSpriteForlabel2 = newSprite("white-1-pixel", G_SWIDTH/2, getY(580), this, 0, RATIO_XY);
    CCSize labelSize = lbFirst->getContentSize();
    CCSize labelSize2 = lbSecond->getContentSize();
    labelBackgroundSprite->setScaleX(labelSize.width);
    labelBackgroundSprite->setScaleY(42);
   // labelBackgroundSprite->setOpacity(30);
    labelBackgroundSpriteForlabel2->setScaleX(labelSize2.width);
    labelBackgroundSpriteForlabel2->setScaleY(42);
   // labelBackgroundSpriteForlabel2->setOpacity(30);
    labelBackgroundSpriteForlabel2->setVisible(false);
    labelBackgroundSprite->setVisible(false);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this, callfunc_selector(Slide2::playEffect1)), CCFadeIn::create(0.5f), CCCallFunc::create(this, callfunc_selector(Slide2::SetvisibilityForTextBackground1)), NULL));
    lbSecond->runAction(CCSequence::create(CCDelayTime::create(7.0f), CCFadeIn::create(0.5f), CCCallFunc::create(this, callfunc_selector(Slide2::SetvisibilityForTextBackground2)), NULL));
    this->scheduleUpdate();
}


void Slide2::update( float dt)
{
    CCLOG("Update %f", dt);
    deltaTime += dt;
    if (deltaTime >= 11.0 )
    {
        this->runAction(CCCallFunc::create(this, callfunc_selector(Slide2::playEffect2)));
        deltaTime = 0.0;
    }
    
}

void Slide2::playEffect1()
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Train_02_a.mp3");
}

void Slide2::playEffect2(){
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("whistle.mp3");
    if(g_bAuto){
        this->runAction(CCSequence::create(CCDelayTime::create(2.f),CCCallFunc::create(this, callfunc_selector(Slide2::onNext)),NULL));
    }
}

void Slide2::SetvisibilityForTextBackground1()
{
    labelBackgroundSprite->setVisible(true);
}

void Slide2::SetvisibilityForTextBackground2()
{
    labelBackgroundSpriteForlabel2->setVisible(true);
}


void Slide2::createMenu()
{
    btnBack = newButton("back", getX(100), getY(600), this, menu_selector(Slide2::onBack), false, RATIO_X);
    btnNext = newButton("next", G_SWIDTH - getX(100), getY(600), this, menu_selector(Slide2::onNext), false, RATIO_X);
    
    CCMenuItemImage *btnHome = newButton("home", getX(100), getY(70), this, menu_selector(Slide1::onHome), false, RATIO_X);
    //        btnHome->setOpacity(120);
    
    menu = CCMenu::create(btnNext,btnBack, btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Slide2::onHome()
{
    BridgeIOS::showHomeAlert();
}


void Slide2::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f,Slide1::scene(), true));
}

void Slide2::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
   CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Slide3::scene(), false));
}

void Slide2::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Slide2::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    if (trainSprite->boundingBox().containsPoint(touchLocation)) {
        trainSprite->stopAllActions();
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("whistle.mp3");
        // spSun->runAction(CCRotateBy::create(1.0f, 360.f));
    }
    if (joshAndEmmaSprite->boundingBox().containsPoint(touchLocation))
    {
        joshAndEmmaSprite->stopAllActions();
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("laugh.wav");
    }
    return false;
}

