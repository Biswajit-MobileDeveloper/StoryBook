//
//  Slide1.cpp
//  JoshEmma
//
//  Created by Biswajit Paul on 03/11/15.
//
//

#include "Slide1.h"
#include "GameSettings.h"
#include "GameConfig.h"
#include "MenuScene.h"
#include "Slide2.h"
#include "BridgeIOS.h"


USING_NS_CC;
CCScene* Slide1::scene()
{
    CCScene *scene = CCScene::create();
    Slide1 *layer = Slide1::create();
    scene->addChild(layer);
    return scene;
}
bool Slide1::init()
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

void Slide1::createBg()
{
    newSprite("slide01-background", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    trainSprite = newSprite("slide01-train", - getX(250), getY(295), this, 0, RATIO_XY);
    sunSprite = newSprite("slide01-trigger-sun", getX( 820 ), getY(50), this, 0, RATIO_XY);
    trainSprite->runAction(CCMoveTo::create(5.f, ccp(G_SWIDTH - getX(480), trainSprite->getPosition().y)));
   lbFirst = newLabel("Mom is taking Josh and Emma for a special surprise..", "Arial", 42, G_SWIDTH/2, getY(530), this, 1, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabel("a ride on the beach train!", "Arial", 42, G_SWIDTH/2, getY(580), this, 1, RATIO_X);
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
    //labelBackgroundSpriteForlabel2->setOpacity(30);
    labelBackgroundSpriteForlabel2->setVisible(false);
    labelBackgroundSprite->setVisible(false);
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this,callfunc_selector(Slide1::playEffect1)), CCFadeIn::create(0.5f), CCCallFunc::create(this,callfunc_selector(Slide1::SetvisibilityForTextBackground1)), NULL));
    lbSecond->runAction(CCSequence::create(CCDelayTime::create(5.0f), CCCallFunc::create(this,callfunc_selector(Slide1::playEffect2)),CCFadeIn::create(1.0f),CCCallFunc::create(this,callfunc_selector(Slide1::SetvisibilityForTextBackground2)), NULL));
}


void Slide1::playEffect1()
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Train_01_a.mp3");
}

void Slide1::playEffect2(){
}

void Slide1::SetvisibilityForTextBackground1()
{
    labelBackgroundSprite->setVisible(true);
}

void Slide1::SetvisibilityForTextBackground2()
{
    labelBackgroundSpriteForlabel2->setVisible(true);
}

void Slide1::createMenu()
{
    btnBack = newButton("back", getX(100), getY(600), this, menu_selector(Slide1::onBack), false, RATIO_X);
    btnNext = newButton("next", G_SWIDTH - getX(100), getY(600), this, menu_selector(Slide1::onNext), false, RATIO_X);
    
    CCMenuItemImage *btnHome = newButton("home", getX(100), getY(70), this, menu_selector(Slide1::onHome), false, RATIO_X);
    //        btnHome->setOpacity(120);
    
    menu = CCMenu::create(btnNext,btnBack, btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Slide1::onHome()
{
    BridgeIOS::showHomeAlert();
}

void Slide1::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, MenuScene::scene(), true));
}

void Slide1::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Slide2::scene(), false));
}

void Slide1::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Slide1::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    if (sunSprite->boundingBox().containsPoint(touchLocation)) {
        sunSprite->stopAllActions();
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("sun_train.wav");
       // spSun->runAction(CCRotateBy::create(1.0f, 360.f));
    }
    if (trainSprite->boundingBox().containsPoint(touchLocation))
    {
        trainSprite->stopAllActions();
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("whistle.mp3");
    }
    return false;
}