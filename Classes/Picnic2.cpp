//
//  Picnic2.cpp
//  JoshEmma
//
//  Created by Biswajit Paul on 11/11/15.
//
//

#include "Picnic2.h"
#include "GameSettings.h"
#include "GameConfig.h"
#include "MenuScene.h"
#include "Picnic1.h"
#include "Picnic3.h"
#include "BridgeIOS.h"


USING_NS_CC;
CCScene* Picnic2::scene()
{
    CCScene *scene = CCScene::create();
    Picnic2 *layer = Picnic2::create();
    scene->addChild(layer);
    return scene;
}
bool Picnic2::init()
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

void Picnic2::createBg()
{
    newSprite("picnic02-background", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    basketSprite = newSprite("picnic02-basket", getX(630), getY(350), this, 0, RATIO_XY);
    
    lbFirst = newLabel("Mom says she packed a special picnic lunch for the beach.", "Arial", 40, G_SWIDTH/2, getY(530), this, 1, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabel("I wonder what makes it so special.", "Arial", 40, G_SWIDTH/2, getY(580), this, 1, RATIO_X);
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
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this,callfunc_selector(Picnic2::playEffect1)), CCFadeIn::create(0.5f), CCCallFunc::create(this,callfunc_selector(Picnic2::SetvisibilityForTextBackground1)), NULL));
    lbSecond->runAction(CCSequence::create(CCDelayTime::create(5.0f), CCCallFunc::create(this,callfunc_selector(Picnic2::playEffect2)),CCFadeIn::create(1.0f), CCCallFunc::create(this,callfunc_selector(Picnic2::SetvisibilityForTextBackground2)), NULL));
}


void Picnic2::playEffect1()
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Picnic_02_a.mp3");
}

void Picnic2::playEffect2(){
}

void Picnic2::SetvisibilityForTextBackground1()
{
    labelBackgroundSprite->setVisible(true);
}

void Picnic2::SetvisibilityForTextBackground2()
{
    labelBackgroundSpriteForlabel2->setVisible(true);
}

void Picnic2::createMenu()
{
    btnBack = newButton("back", getX(100), getY(600), this, menu_selector(Picnic2::onBack), false, RATIO_X);
    btnNext = newButton("next", G_SWIDTH - getX(100), getY(600), this, menu_selector(Picnic2::onNext), false, RATIO_X);
    
    CCMenuItemImage *btnHome = newButton("home", getX(100), getY(70), this, menu_selector(Picnic2::onHome), false, RATIO_X);
    //        btnHome->setOpacity(120);
    
    menu = CCMenu::create(btnNext,btnBack, btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Picnic2::onHome()
{
    BridgeIOS::showHomeAlert();
}

void Picnic2::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Picnic1::scene(), true));
}

void Picnic2::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Picnic3::scene(), false));
}

void Picnic2::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Picnic2::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
        CCPoint touchLocation = touch->getLocationInView();
        touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
        if (basketSprite->boundingBox().containsPoint(touchLocation)) {
            basketSprite->stopAllActions();
            SimpleAudioEngine::sharedEngine()->stopAllEffects();
            //SimpleAudioEngine::sharedEngine()->playEffect("Picnic_03_b_blanket.mp3");
        }
    return false;
}