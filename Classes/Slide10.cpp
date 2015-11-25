//
//  Slide10.cpp
//  JoshEmma
//
//  Created by Biswajit Paul on 04/11/15.
//
//

#include "Slide10.h"
#include "GameSettings.h"
#include "GameConfig.h"
#include "Slide9.h"
#include "MenuScene.h"
#include "BridgeIOS.h"

USING_NS_CC;
CCScene* Slide10::scene()
{
    CCScene *scene = CCScene::create();
    Slide10 *layer = Slide10::create();
    scene->addChild(layer);
    return scene;
}
bool Slide10::init()
{
    if ( !CCLayer::init())
    {
        return false;
    }
    deltaTimeForJosh = 0;
    deltaTimeForEmma = 0;
    jumpNumberForEmma = 0;
    jumpNumberForJosh = 0;
    this->setTouchEnabled(true);
    this->scheduleUpdate();
    createBg();
    createMenu();
    
    return true;
}

void Slide10::createBg()
{
    newSprite("slide10-background", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    josh = newSprite("slide10-josh", getX(500), getY(250), this, 0, RATIO_XY);
    emma = newSprite("slide10-emma", getX(800), getY(250), this, 0, RATIO_XY);
    
    lbSecond = newLabel("Josh and Emma love riding the beach train.", "Arial", 35, G_SWIDTH/2, getY(580), this, 1, RATIO_X);
    lbSecond->setOpacity(0);
    
    labelBackgroundSpriteForlabel2 = newSprite("white-1-pixel", G_SWIDTH/2, getY(580), this, 0, RATIO_XY);
    CCSize labelSize2 = lbSecond->getContentSize();
     labelBackgroundSpriteForlabel2->setScaleX(labelSize2.width);
    labelBackgroundSpriteForlabel2->setScaleY(35);
   // labelBackgroundSpriteForlabel2->setOpacity(30);
    labelBackgroundSpriteForlabel2->setVisible(false);
   
    lbSecond->runAction(CCSequence::create(CCDelayTime::create(1.0f),CCCallFunc::create(this,callfunc_selector(Slide10::playEffect1)), CCFadeIn::create(0.5f), CCCallFunc::create(this,callfunc_selector(Slide10::SetvisibilityForTextBackground2)), NULL));
}

void Slide10::playEffect1()
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Train_10_a.mp3");
}

void Slide10::playEffect2(){
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Train_02_b_whistle.mp3");
    if(g_bAuto){
        this->runAction(CCSequence::create(CCDelayTime::create(2.f),CCCallFunc::create(this, callfunc_selector(Slide9::onNext)),NULL));
    }
}



void Slide10::SetvisibilityForTextBackground2()
{
    labelBackgroundSpriteForlabel2->setVisible(true);
}


void Slide10::update( float dt)
{
    deltaTimeForJosh += dt;
    deltaTimeForEmma += dt;
    if (deltaTimeForJosh >= 4.0 )
    {
        josh->setPosition(ccp(getX(500), getY(250)));
        josh->runAction(CCSequence::create(CCJumpBy::create(1.f, ccp(0, 0), 100*G_SCALEY, 1), NULL));
        deltaTimeForJosh = 0;
       // jumpNumberForJosh++;
    }
    
    if (deltaTimeForEmma >= 4.0 )
    {
        emma->setPosition(ccp(getX(800), getY(250)));
        emma->runAction(CCSequence::create(CCJumpBy::create(1.f, ccp(0, 0), 100*G_SCALEY, 1), NULL));
        deltaTimeForEmma = 0;
        //jumpNumberForEmma++;
    }
}


void Slide10::createMenu()
{
    btnBack = newButton("back", getX(100), getY(600), this, menu_selector(Slide10::onBack), false, RATIO_X);
    btnNext = newButton("next", G_SWIDTH - getX(100), getY(600), this, menu_selector(Slide10::onNext), false, RATIO_X);
    
    CCMenuItemImage *btnHome = newButton("home", getX(100), getY(70), this, menu_selector(Slide10::onHome), false, RATIO_X);
    //        btnHome->setOpacity(120);
    
    menu = CCMenu::create(btnNext,btnBack, btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);

}

void Slide10::onHome()
{
   BridgeIOS::showHomeAlert();
}


void Slide10::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f,Slide9::scene(), true));
}

void Slide10::onNext()
{
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, MenuScene::scene(), false));
}

void Slide10::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Slide10::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    if( josh->boundingBox().containsPoint(touchLocation))
    {
        josh->stopAllActions();
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("laugh.wav");
        
    }
    
    if( emma->boundingBox().containsPoint(touchLocation))
    {
        emma->stopAllActions();
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("laugh.wav");
        
    }

    return false;
}