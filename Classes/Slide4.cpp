//
//  Slide4.cpp
//  JoshEmma
//
//  Created by Biswajit Paul on 04/11/15.
//
//

#include "Slide4.h"
#include "GameSettings.h"
#include "GameConfig.h"
#include "Slide3.h"
#include "Slide5.h"
#include "BridgeIOS.h"

USING_NS_CC;
CCScene* Slide4::scene()
{
    CCScene *scene = CCScene::create();
    Slide4 *layer = Slide4::create();
    scene->addChild(layer);
    return scene;
}
bool Slide4::init()
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

void Slide4::createBg()
{
    newSprite("slide04-background", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    
    lbFirst = newLabel("Josh and Emma find a seat near the back of the train,", "Arial", 35, G_SWIDTH/2, getY(530), this, 1, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabel("right in front of the caboose.", "Arial", 35, G_SWIDTH/2, getY(580), this, 1, RATIO_X);
    lbSecond->setOpacity(0);
    labelBackgroundSprite = newSprite("white-1-pixel", G_SWIDTH/2, getY(530), this, 0, RATIO_XY);
    labelBackgroundSpriteForlabel2 = newSprite("white-1-pixel", G_SWIDTH/2, getY(580), this, 0, RATIO_XY);
    CCSize labelSize = lbFirst->getContentSize();
    CCSize labelSize2 = lbSecond->getContentSize();
    labelBackgroundSprite->setScaleX(labelSize.width);
    labelBackgroundSprite->setScaleY(35);
    //labelBackgroundSprite->setOpacity(30);
    labelBackgroundSpriteForlabel2->setScaleX(labelSize2.width);
    labelBackgroundSpriteForlabel2->setScaleY(35);
  //  labelBackgroundSpriteForlabel2->setOpacity(30);
    labelBackgroundSpriteForlabel2->setVisible(false);
    labelBackgroundSprite->setVisible(false);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this,callfunc_selector(Slide4::playEffect1)), CCFadeIn::create(0.5f), CCCallFunc::create(this,callfunc_selector(Slide4::SetvisibilityForTextBackground1)), NULL));
    lbSecond->runAction(CCSequence::create(CCDelayTime::create(5.0f), CCFadeIn::create(0.5f), CCCallFunc::create(this,callfunc_selector(Slide4::SetvisibilityForTextBackground2)), NULL));
}

void Slide4::playEffect1()
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Train_04_a.mp3");
}

void Slide4::playEffect2(){
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Train_02_b_whistle.mp3");
    if(g_bAuto){
        this->runAction(CCSequence::create(CCDelayTime::create(2.f),CCCallFunc::create(this, callfunc_selector(Slide4::onNext)),NULL));
    }
}

void Slide4::SetvisibilityForTextBackground1()
{
    labelBackgroundSprite->setVisible(true);
}

void Slide4::SetvisibilityForTextBackground2()
{
    labelBackgroundSpriteForlabel2->setVisible(true);
}



void Slide4::createMenu()
{
    btnBack = newButton("back", getX(100), getY(600), this, menu_selector(Slide4::onBack), false, RATIO_X);
    btnNext = newButton("next", G_SWIDTH - getX(100), getY(600), this, menu_selector(Slide4::onNext), false, RATIO_X);
    
    CCMenuItemImage *btnHome = newButton("home", getX(100), getY(70), this, menu_selector(Slide4::onHome), false, RATIO_X);
    //        btnHome->setOpacity(120);
    
    menu = CCMenu::create(btnNext,btnBack, btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Slide4::onHome()
{
    BridgeIOS::showHomeAlert();
}


void Slide4::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f,Slide3::scene(), true));
}

void Slide4::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Slide5::scene(), false));
}

void Slide4::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Slide4::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    return false;
}
