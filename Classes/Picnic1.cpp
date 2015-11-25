//
//  Picnic1.cpp
//  JoshEmma
//
//  Created by Biswajit Paul on 07/11/15.
//
//

#include "Picnic1.h"
#include "GameSettings.h"
#include "GameConfig.h"
#include "MenuScene.h"
#include "Picnic2.h"
#include "BridgeIOS.h"


USING_NS_CC;
CCScene* Picnic1::scene()
{
    CCScene *scene = CCScene::create();
    Picnic1 *layer = Picnic1::create();
    scene->addChild(layer);
    return scene;
}
bool Picnic1::init()
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

void Picnic1::createBg()
{
    newSprite("picnic01-background", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    joshSprite = newSprite("picnic01-josh", getX(252), getY(330), this, 0, RATIO_XY);
    emmaSprite = newSprite("picnic01-emma", getX(854), getY(330), this, 0, RATIO_XY);
    ballSprite = newSprite("picnic03-ball", getX(540), getY(350), this, 0, RATIO_XY);
    sunSprite = newSprite("picnic01-sun", getX(852), getY(50), this, 0, RATIO_XY);
    
    lbFirst = newLabel("Josh and Emma are getting hungry,", "Arial", 40, G_SWIDTH/2, getY(530), this, 1, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabel("it must be time for lunch.", "Arial", 40, G_SWIDTH/2, getY(580), this, 1, RATIO_X);
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
  //  labelBackgroundSpriteForlabel2->setOpacity(30);
    labelBackgroundSpriteForlabel2->setVisible(false);
    labelBackgroundSprite->setVisible(false);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this,callfunc_selector(Picnic1::playEffect1)), CCFadeIn::create(0.5f), CCCallFunc::create(this,callfunc_selector(Picnic1::SetvisibilityForTextBackground1)), NULL));
    lbSecond->runAction(CCSequence::create(CCDelayTime::create(3.0f), CCCallFunc::create(this,callfunc_selector(Picnic1::playEffect2)),CCFadeIn::create(1.0f), CCCallFunc::create(this,callfunc_selector(Picnic1::SetvisibilityForTextBackground2)), NULL));
}


void Picnic1::playEffect1()
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Picnic_01_a.mp3");
}

void Picnic1::playEffect2(){
}

void Picnic1::SetvisibilityForTextBackground1()
{
    labelBackgroundSprite->setVisible(true);
}

void Picnic1::SetvisibilityForTextBackground2()
{
    labelBackgroundSpriteForlabel2->setVisible(true);
}

void Picnic1::createMenu()
{
    btnBack = newButton("back", getX(100), getY(600), this, menu_selector(Picnic1::onBack), false, RATIO_X);
    btnNext = newButton("next", G_SWIDTH - getX(100), getY(600), this, menu_selector(Picnic1::onNext), false, RATIO_X);
    
    CCMenuItemImage *btnHome = newButton("home", getX(100), getY(70), this, menu_selector(Picnic1::onHome), false, RATIO_X);
    //        btnHome->setOpacity(120);
    
    menu = CCMenu::create(btnNext,btnBack, btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Picnic1::onHome()
{
    BridgeIOS::showHomeAlert();
}

void Picnic1::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, MenuScene::scene(), true));
}

void Picnic1::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Picnic2::scene(), false));
}

void Picnic1::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Picnic1::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
        CCPoint touchLocation = touch->getLocationInView();
        touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
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
    
        if (sunSprite->boundingBox().containsPoint(touchLocation)) {
            sunSprite->stopAllActions();
            SimpleAudioEngine::sharedEngine()->stopAllEffects();
            SimpleAudioEngine::sharedEngine()->playEffect("sun_picnic.wav");
        }
    
        if (ballSprite->boundingBox().containsPoint(touchLocation)) {
            ballSprite->stopAllActions();
            SimpleAudioEngine::sharedEngine()->stopAllEffects();
            SimpleAudioEngine::sharedEngine()->playEffect("ball.wav");
        }
    return false;
}