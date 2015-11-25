//
//  Picnic3.cpp
//  JoshEmma
//
//  Created by Biswajit Paul on 11/11/15.
//
//

#include "Picnic3.h"
#include "Picnic2.h"
#include "GameSettings.h"
#include "GameConfig.h"
#include "MenuScene.h"
#include "Picnic4.h"
#include "BridgeIOS.h"


USING_NS_CC;
CCScene* Picnic3::scene()
{
    CCScene *scene = CCScene::create();
    Picnic3 *layer = Picnic3::create();
    scene->addChild(layer);
    return scene;
}

bool Picnic3::init()
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

void Picnic3::createBg()
{
    newSprite("picnic03-background", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    basketSprite = newSprite("picnic03-basket", getX(975), getY(500), this, 0, RATIO_XY);
    ballSprite = newSprite("picnic03-ball", getX(80), getY(350), this, 0, RATIO_XY);
    joshSprite = newSprite("picnic03-josh", getX(296), getY(486), this, 0, RATIO_XY);
    emmaSprite = newSprite("picnic03-emma", getX(835), getY(375), this, -1, RATIO_XY);
    blanketSprite = newSprite("picnic03-blanket", getX(560), getY(370), this, -1, RATIO_XY);
    
    lbFirst = newLabel("Josh and Emma help lay out the picnic blanket so..", "Arial", 35, G_SWIDTH/2, getY(530), this, 1, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabel("they can unpack the basket and see what’s inside.", "Arial", 35, G_SWIDTH/2, getY(580), this, 1, RATIO_X);
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
    //labelBackgroundSpriteForlabel2->setOpacity(30);
    labelBackgroundSpriteForlabel2->setVisible(false);
    labelBackgroundSprite->setVisible(false);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this,callfunc_selector(Picnic3::playEffect1)), CCFadeIn::create(0.5f), CCCallFunc::create(this,callfunc_selector(Picnic3::SetvisibilityForTextBackground1)), NULL));
    lbSecond->runAction(CCSequence::create(CCDelayTime::create(5.0f), CCCallFunc::create(this,callfunc_selector(Picnic3::playEffect2)),CCFadeIn::create(1.0f), CCCallFunc::create(this,callfunc_selector(Picnic3::SetvisibilityForTextBackground2)), NULL));
}


void Picnic3::playEffect1()
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Picnic_03_a.mp3");
}

void Picnic3::playEffect2(){
}

void Picnic3::SetvisibilityForTextBackground1()
{
    labelBackgroundSprite->setVisible(true);
}

void Picnic3::SetvisibilityForTextBackground2()
{
    labelBackgroundSpriteForlabel2->setVisible(true);
}


void Picnic3::createMenu()
{
    btnBack = newButton("back", getX(100), getY(600), this, menu_selector(Picnic3::onBack), false, RATIO_X);
    btnNext = newButton("next", G_SWIDTH - getX(100), getY(600), this, menu_selector(Picnic3::onNext), false, RATIO_X);
    
    CCMenuItemImage *btnHome = newButton("home", getX(100), getY(70), this, menu_selector(Picnic3::onHome), false, RATIO_X);
    //        btnHome->setOpacity(120);
    
    menu = CCMenu::create(btnNext,btnBack, btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Picnic3::onHome()
{
    BridgeIOS::showHomeAlert();
}

void Picnic3::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Picnic2::scene(), true));
}

void Picnic3::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Picnic4::scene(), false));
}

void Picnic3::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Picnic3::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
        CCPoint touchLocation = touch->getLocationInView();
        touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
        if (blanketSprite->boundingBox().containsPoint(touchLocation))
        {
            blanketSprite->stopAllActions();
            SimpleAudioEngine::sharedEngine()->stopAllEffects();
            SimpleAudioEngine::sharedEngine()->playEffect("Picnic_03_b_blanket.mp3");
        }
    
        if (ballSprite->boundingBox().containsPoint(touchLocation))
        {
            ballSprite->stopAllActions();
            SimpleAudioEngine::sharedEngine()->stopAllEffects();
            SimpleAudioEngine::sharedEngine()->playEffect("ball.wav");
        }
    
        if (joshSprite->boundingBox().containsPoint(touchLocation))
        {
            joshSprite->stopAllActions();
            SimpleAudioEngine::sharedEngine()->stopAllEffects();
            SimpleAudioEngine::sharedEngine()->playEffect("laugh.wav");
        }
    
        if (emmaSprite->boundingBox().containsPoint(touchLocation))
        {
            emmaSprite->stopAllActions();
            SimpleAudioEngine::sharedEngine()->stopAllEffects();
            SimpleAudioEngine::sharedEngine()->playEffect("laugh.wav");
        }
    
//        if (basketSprite->boundingBox().containsPoint(touchLocation))
//        {
//            basketSprite->stopAllActions();
//            SimpleAudioEngine::sharedEngine()->stopAllEffects();
//            SimpleAudioEngine::sharedEngine()->playEffect("Picnic_03_b_blanket.mp3");
//        }
    return false;
}