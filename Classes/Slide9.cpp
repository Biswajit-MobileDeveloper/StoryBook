//
//  Slide9.cpp
//  JoshEmma
//
//  Created by Biswajit Paul on 04/11/15.
//
//

#include "Slide9.h"
#include "GameSettings.h"
#include "GameConfig.h"
#include "Slide8.h"
#include "Slide10.h"
#include "BridgeIOS.h"

USING_NS_CC;
CCScene* Slide9::scene()
{
    CCScene *scene = CCScene::create();
    Slide9 *layer = Slide9::create();
    scene->addChild(layer);
    return scene;
}
bool Slide9::init()
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

void Slide9::createBg()
{
    newSprite("slide09-background", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    joshAndEmmaSprite = newSprite("slide09-joshemma", getX(465), getY(375), this, 0, RATIO_XY);
    lbFirst = newLabel("As they leave, the conductor gives Josh and Emma", "Arial", 35, G_SWIDTH/2, getY(530), this, 1, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabel("their own engineer hats.", "Arial", 35, G_SWIDTH/2, getY(580), this, 1, RATIO_X);
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
    //labelBackgroundSpriteForlabel2->setOpacity(30);
    labelBackgroundSpriteForlabel2->setVisible(false);
    labelBackgroundSprite->setVisible(false);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this,callfunc_selector(Slide9::playEffect1)), CCFadeIn::create(0.5f), CCCallFunc::create(this,callfunc_selector(Slide9::SetvisibilityForTextBackground1)), NULL));
    lbSecond->runAction(CCSequence::create(CCDelayTime::create(5.0f), CCFadeIn::create(0.5f), CCCallFunc::create(this,callfunc_selector(Slide9::SetvisibilityForTextBackground2)), NULL));
}

void Slide9::playEffect1()
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Train_09_a.mp3");
}

void Slide9::playEffect2(){
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Train_02_b_whistle.mp3");
    if(g_bAuto){
        this->runAction(CCSequence::create(CCDelayTime::create(2.f),CCCallFunc::create(this, callfunc_selector(Slide9::onNext)),NULL));
    }
}


void Slide9::SetvisibilityForTextBackground1()
{
    labelBackgroundSprite->setVisible(true);
}

void Slide9::SetvisibilityForTextBackground2()
{
    labelBackgroundSpriteForlabel2->setVisible(true);
}


void Slide9::createMenu()
{
    btnBack = newButton("back", getX(100), getY(600), this, menu_selector(Slide9::onBack), false, RATIO_X);
    btnNext = newButton("next", G_SWIDTH - getX(100), getY(600), this, menu_selector(Slide9::onNext), false, RATIO_X);
    
    CCMenuItemImage *btnHome = newButton("home", getX(100), getY(70), this, menu_selector(Slide9::onHome), false, RATIO_X);
    //        btnHome->setOpacity(120);
    
    menu = CCMenu::create(btnNext,btnBack, btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);

}

void Slide9::onHome()
{
    BridgeIOS::showHomeAlert();
}


void Slide9::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f,Slide8::scene(), true));
}

void Slide9::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Slide10::scene(), false));
}

void Slide9::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Slide9::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    if( joshAndEmmaSprite->boundingBox().containsPoint(touchLocation))
    {
        joshAndEmmaSprite->stopAllActions();
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("laugh.wav");
        
    }
    return false;
}