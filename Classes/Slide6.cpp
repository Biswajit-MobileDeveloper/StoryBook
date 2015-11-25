//
//  Slide6.cpp
//  JoshEmma
//
//  Created by Biswajit Paul on 04/11/15.
//
//

#include "Slide6.h"
#include "GameSettings.h"
#include "GameConfig.h"
#include "Slide5.h"
#include "Slide7.h"
#include "BridgeIOS.h"


USING_NS_CC;
CCScene* Slide6::scene()
{
    CCScene *scene = CCScene::create();
    Slide6 *layer = Slide6::create();
    scene->addChild(layer);
    return scene;
}
bool Slide6::init()
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

void Slide6::createBg()
{
    newSprite("slide06-background", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    lion = newSprite("slide06-lion", getX(180), getY(190), this, 0, RATIO_XY);
    monkey = newSprite("slide06-monkey", getX(600), getY(90), this, 0, RATIO_XY);
    zebra = newSprite("slide06-zebra", getX(1000), getY(190), this, 0, RATIO_XY);
    joshAndEmmaSprite = newSprite("slide06-joshemma",G_SWIDTH/2, getY(500), this, 0, RATIO_XY);
    lbFirst = newLabel("The train goes right past the zoo.", "Arial", 40, G_SWIDTH/2, getY(530), this, 1, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabel("Josh and Emma wave to all of the animals.", "Arial", 40, G_SWIDTH/2, getY(580), this, 1, RATIO_X);
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
  //  labelBackgroundSpriteForlabel2->setOpacity(30);
    labelBackgroundSpriteForlabel2->setVisible(false);
    labelBackgroundSprite->setVisible(false);

    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this,callfunc_selector(Slide6::playEffect1)), CCFadeIn::create(0.5f), CCCallFunc::create(this,callfunc_selector(Slide6::SetvisibilityForTextBackground1)), NULL));
    lbSecond->runAction(CCSequence::create(CCDelayTime::create(4.0f), CCFadeIn::create(0.5f), CCCallFunc::create(this,callfunc_selector(Slide6::SetvisibilityForTextBackground2)), NULL));
}

void Slide6::playEffect1()
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Train_06_a.mp3");
}

void Slide6::playEffect2(){
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Train_02_b_whistle.mp3");
    if(g_bAuto){
        this->runAction(CCSequence::create(CCDelayTime::create(2.f),CCCallFunc::create(this, callfunc_selector(Slide5::onNext)),NULL));
    }
}


void Slide6::SetvisibilityForTextBackground1()
{
    labelBackgroundSprite->setVisible(true);
}

void Slide6::SetvisibilityForTextBackground2()
{
    labelBackgroundSpriteForlabel2->setVisible(true);
}


void Slide6::createMenu()
{
    btnBack = newButton("back", getX(100), getY(600), this, menu_selector(Slide6::onBack), false, RATIO_X);
    btnNext = newButton("next", G_SWIDTH - getX(100), getY(600), this, menu_selector(Slide6::onNext), false, RATIO_X);
    
    CCMenuItemImage *btnHome = newButton("home", getX(100), getY(70), this, menu_selector(Slide6::onHome), false, RATIO_X);
    //        btnHome->setOpacity(120);
    
    menu = CCMenu::create(btnNext,btnBack, btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);

}

void Slide6::onHome()
{
    BridgeIOS::showHomeAlert();
}


void Slide6::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f,Slide5::scene(), true));
}

void Slide6::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Slide7::scene(), false));
}

void Slide6::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Slide6::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    if (lion->boundingBox().containsPoint(touchLocation)) {
        lion->stopAllActions();
        lion->setPosition(ccp(getX(180), getY(190)));
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("Zoo_05_b_adult lion.mp3");
        lion->runAction(CCSequence::create(CCJumpBy::create(1.f, ccp(0, 0), 80*G_SCALEY, 1), NULL));
    }
    if (monkey->boundingBox().containsPoint(touchLocation)) {
        monkey->stopAllActions();
        monkey->setPosition(ccp(getX(600), getY(90)));
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("Zoo_04_b_adult monkey.mp3");
       // monkey->runAction(CCSequence::create(CCJumpBy::create(0.6f, ccp(0, 0), 150*G_SCALEY, 1),CCJumpBy::create(0.4f, ccp(0, 0), 80*G_SCALEY, 1),CCJumpBy::create(0.2f, ccp(0, 0), 40*G_SCALEY, 1), NULL));
        auto rotation = CCRotateTo::create(.5, 45.0);
        auto reverseRotation = CCRotateTo::create(.50, 0);
       // auto reverseRotation = CCRotateTo::create(2.0, monk);
        monkey->runAction(CCSequence::create(rotation, reverseRotation, rotation, reverseRotation, NULL));
    }
    
    if (zebra->boundingBox().containsPoint(touchLocation)) {
        zebra->stopAllActions();
        zebra->setPosition(ccp(getX(1000), getY(190)));
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("Zoo_07_b_adult zebra.mp3");
        zebra->runAction(CCSequence::create( CCScaleBy::create(1.0, 1.5),CCScaleBy::create(1.0, .67), NULL));
    }
    
    if( joshAndEmmaSprite->boundingBox().containsPoint(touchLocation))
    {
        joshAndEmmaSprite->stopAllActions();
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("laugh.wav");

    }
    return false;
}