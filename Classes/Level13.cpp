//
//  Level13.cpp
//  JoshEmma
//
//  Created by Rijing on 4/16/15.
//
//

#include "Level13.h"

#include "GameSettingsForLession1.h"
#include "GameConfig.h"
#include "Level14.h"
#include "Level12.h"
#include "BridgeIOS.h"

USING_NS_CC;
CCScene* Level13::scene()
{
    CCScene *scene = CCScene::create();
    Level13 *layer = Level13::create();
    scene->addChild(layer);
    return scene;
}
bool Level13::init()
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

void Level13::createBg()
{
    newSpriteForLession1("level_bg12", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    spHitBox = newSpriteForLession1("waterhitbox", G_SWIDTH/2, getYForLession1(300), this, -1, RATIO_XY);
    
    spSun = newSpriteForLession1("sun", getXForLession1(780), getYForLession1(80), this, -1, RATIO_X);
    spSun->setScale(0.7*G_SCALEX);
    
    
    Josh = newSpriteForLession1("josh", getXForLession1(300), getYForLession1(330), this, 0, RATIO_Y);
    Emma = newSpriteForLession1("emma", getXForLession1(700), getYForLession1(330), this, 0, RATIO_Y);
    
    
    lbFirst = newLabelForLession1("Help Josh and Emma put their beach", "Arial", 50, G_SWIDTH/2, getYForLession1(600), this, 0, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabelForLession1("treasures in the red bucket", "Arial", 50, G_SWIDTH/2, getYForLession1(680), this, 0, RATIO_X);
    lbSecond->setOpacity(0);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f),CCCallFunc::create(this,callfunc_selector(Level13::playEffect)), CCFadeIn::create(1.0f), NULL));
    lbSecond->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCFadeIn::create(1.0f), NULL));
    
}


void Level13::playEffect(){

    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level3_01.wav");
    if(g_bAuto){
        this->runAction(CCSequence::create(CCDelayTime::create(4.f),CCCallFunc::create(this, callfunc_selector(Level13::onNext)),NULL));
    }
}

void Level13::createMenu()
{
    btnBack = newButtonForLession1("back", getXForLession1(100), getYForLession1(670), this, menu_selector(Level13::onBack), false, RATIO_X);
    btnNext = newButtonForLession1("next", G_SWIDTH - getXForLession1(100), getYForLession1(670), this, menu_selector(Level13::onNext), false, RATIO_X);
    CCMenuItemImage *btnHome = newButtonForLession1("home", getXForLession1(100), getYForLession1(70), this, menu_selector(Level13::onHome), false, RATIO_X);
//    btnHome->setOpacity(120);
    menu = CCMenu::create(btnNext,btnBack,btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Level13::onHome()
{
    BridgeIOS::showHomeAlert();
}

void Level13::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Level12::scene(), true));
}

void Level13::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Level14::scene(), false));
}

void Level13::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Level13::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    if (spSun->boundingBox().containsPoint(touchLocation)) {
        spSun->stopAllActions();
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("sun.wav");

        spSun->runAction(CCRotateBy::create(1.0f, 360.f));
        return false;
    }
    
    if (Josh->boundingBox().containsPoint(touchLocation) || Emma->boundingBox().containsPoint(touchLocation)) {
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("laugh.wav");
        return false;
    }
    
    if (spHitBox->boundingBox().containsPoint(touchLocation)) {
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("water.wav");
    }


    
    
    return false;
}