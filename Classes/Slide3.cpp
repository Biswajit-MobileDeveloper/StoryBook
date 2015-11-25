//
//  Slide3.cpp
//  JoshEmma
//
//  Created by Biswajit Paul on 04/11/15.
//
//

#include "Slide3.h"
#include "GameSettings.h"
#include "GameConfig.h"
#include "Slide2.h"
#include "Slide4.h"
#include "BridgeIOS.h"

USING_NS_CC;
CCScene* Slide3::scene()
{
    CCScene *scene = CCScene::create();
    Slide3 *layer = Slide3::create();
    scene->addChild(layer);
    return scene;
}
bool Slide3::init()
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

void Slide3::createBg()
{
    newSprite("slide03-background", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    trainSprite = newSprite("slide03-train", getX(520), getY(480), this, -1, RATIO_XY);
    josh = newSprite("joshRT", getX(255), getY(440), this, 0, RATIO_XY);
    emma = newSprite("emmaRT", getX( 742), getY(370), this, 0, RATIO_XY);
    lbFirst = newLabel("The train looks just like the one Josh and Emma play with at home,", "Arial", 35, G_SWIDTH/2, getY(530), this, 1, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabel("only much much bigger.", "Arial", 35, G_SWIDTH/2, getY(580), this, 1, RATIO_X);
    lbSecond->setOpacity(0);
    
    labelBackgroundSprite = newSprite("white-1-pixel", G_SWIDTH/2, getY(530), this, 0, RATIO_XY);
    labelBackgroundSpriteForlabel2 = newSprite("white-1-pixel", G_SWIDTH/2, getY(580), this, 0, RATIO_XY);
    CCSize labelSize = lbFirst->getContentSize();
    CCSize labelSize2 = lbSecond->getContentSize();
    labelBackgroundSprite->setScaleX(labelSize.width);
    labelBackgroundSprite->setScaleY(42);
  //  labelBackgroundSprite->setOpacity(30);
    labelBackgroundSpriteForlabel2->setScaleX(labelSize2.width);
    labelBackgroundSpriteForlabel2->setScaleY(42);
  //  labelBackgroundSpriteForlabel2->setOpacity(30);
    labelBackgroundSpriteForlabel2->setVisible(false);
    labelBackgroundSprite->setVisible(false);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this,callfunc_selector(Slide3::playEffect1)), CCFadeIn::create(0.5f), CCCallFunc::create(this,callfunc_selector(Slide3::SetvisibilityForTextBackground1)), NULL));
    lbSecond->runAction(CCSequence::create(CCDelayTime::create(6.0f), CCFadeIn::create(0.5f), CCCallFunc::create(this,callfunc_selector(Slide3::SetvisibilityForTextBackground2)), NULL));
}

void Slide3::playEffect1()
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Train_03_a.mp3");
}

void Slide3::playEffect2(){
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Train_02_b_whistle.mp3");
    if(g_bAuto){
        this->runAction(CCSequence::create(CCDelayTime::create(2.f),CCCallFunc::create(this, callfunc_selector(Slide3::onNext)),NULL));
    }
}

void Slide3::SetvisibilityForTextBackground1()
{
    labelBackgroundSprite->setVisible(true);
}

void Slide3::SetvisibilityForTextBackground2()
{
    labelBackgroundSpriteForlabel2->setVisible(true);
}



void Slide3::createMenu()
{
    btnBack = newButton("back", getX(100), getY(600), this, menu_selector(Slide3::onBack), false, RATIO_X);
    btnNext = newButton("next", G_SWIDTH - getX(100), getY(600), this, menu_selector(Slide3::onNext), false, RATIO_X);
    
    CCMenuItemImage *btnHome = newButton("home", getX(100), getY(70), this, menu_selector(Slide3::onHome), false, RATIO_X);
    //        btnHome->setOpacity(120);
    
    menu = CCMenu::create(btnNext,btnBack, btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);

}

void Slide3::onHome()
{
    BridgeIOS::showHomeAlert();
}


void Slide3::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f,Slide2::scene(), true));
}

void Slide3::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Slide4::scene(), false));
}

void Slide3::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Slide3::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    if (trainSprite->boundingBox().containsPoint(touchLocation)) {
        trainSprite->stopAllActions();
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("whistle.mp3");
        // spSun->runAction(CCRotateBy::create(1.0f, 360.f));
    }
    
    if (josh->boundingBox().containsPoint(touchLocation))
    {
        josh->stopAllActions();
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("laugh.wav");
    }
    
    if (emma->boundingBox().containsPoint(touchLocation))
    {
        emma->stopAllActions();
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("laugh.wav");
    }
    return false;
}

