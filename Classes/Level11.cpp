//
//  Level11.cpp
//  JoshEmma
//
//  Created by Rijing on 4/16/15.
//
//

#include "Level11.h"
#include "GameSettingsForLession1.h"
#include "GameConfig.h"
#include "MenuScene.h"
#include "Level12.h"
#include "BridgeIOS.h"


USING_NS_CC;
CCScene* Level11::scene()
{
    CCScene *scene = CCScene::create();
    Level11 *layer = Level11::create();
    scene->addChild(layer);
    return scene;
}
bool Level11::init()
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

void Level11::createBg()
{
    newSpriteForLession1("level_bg11", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    
    spSun = newSpriteForLession1("sun", getXForLession1(850), getYForLession1(150), this, -1, RATIO_X);
    CCSprite *cloud1 = newSpriteForLession1("cloud1", - getXForLession1(250), getYForLession1(300), this, 0, RATIO_XY);
    cloud1->runAction(CCMoveTo::create(5.f, ccp(G_SWIDTH/2 - getXForLession1(250), cloud1->getPosition().y)));
    
    CCSprite *cloud2 = newSpriteForLession1("cloud2", G_SWIDTH + getXForLession1(250), getYForLession1(350), this, 0, RATIO_XY);
    cloud2->runAction(CCMoveTo::create(5.f, ccp(G_SWIDTH/2 + getXForLession1(250), cloud2->getPosition().y)));
    lbFirst = newLabelForLession1("It's a beautiful, sunny day.", "Arial", 50, G_SWIDTH/2, getYForLession1(600), this, 0, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabelForLession1("Let's go to the beach!", "Arial", 50, G_SWIDTH/2, getYForLession1(680), this, 0, RATIO_X);
    lbSecond->setOpacity(0);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this,callfunc_selector(Level11::playEffect1)), CCFadeIn::create(0.5f), NULL));
    lbSecond->runAction(CCSequence::create(CCDelayTime::create(3.0f), CCCallFunc::create(this,callfunc_selector(Level11::playEffect2)),CCFadeIn::create(1.0f), NULL));
}


void Level11::playEffect1()
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level1_01.wav");
}

void Level11::playEffect2(){
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level1_02.wav");
    if(g_bAuto){
        this->runAction(CCSequence::create(CCDelayTime::create(2.f),CCCallFunc::create(this, callfunc_selector(Level11::onNext)),NULL));
    }
}



void Level11::createMenu()
{
    btnBack = newButtonForLession1("back", getXForLession1(100), getYForLession1(670), this, menu_selector(Level11::onBack), false, RATIO_X);
    btnNext = newButtonForLession1("next", G_SWIDTH - getXForLession1(100), getYForLession1(670), this, menu_selector(Level11::onNext), false, RATIO_X);
    
    CCMenuItemImage *btnHome = newButtonForLession1("home", getXForLession1(100), getYForLession1(70), this, menu_selector(Level11::onHome), false, RATIO_X);
//        btnHome->setOpacity(120);
    
    menu = CCMenu::create(btnNext,btnBack, btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Level11::onHome()
{
    BridgeIOS::showHomeAlert();
}

void Level11::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, MenuScene::scene(), true));
}

void Level11::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Level12::scene(), false));
}

void Level11::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Level11::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    if (spSun->boundingBox().containsPoint(touchLocation)) {
        spSun->stopAllActions();
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("sun.wav");
        spSun->runAction(CCRotateBy::create(1.0f, 360.f));
    }
    return false;
}