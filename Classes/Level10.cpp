//
//  Level10.cpp
//  JoshEmma
//
//  Created by Rijing on 4/19/15.
//
//

#include "Level10.h"

#include "GameSettingsForLession1.h"
#include "GameConfig.h"
#include "Level19.h"
#include "Level10.h"
#include "MenuScene.h"
#include "BridgeIOS.h"

USING_NS_CC;
CCScene* Level10::scene()
{
    CCScene *scene = CCScene::create();
    Level10 *layer = Level10::create();
    scene->addChild(layer);
    return scene;
}
bool Level10::init()
{
    if ( !CCLayer::init())
    {
        return false;
    }
    this->setTouchEnabled(true);
    createBg();
    createMenu();
    schedule(schedule_selector(Level10::onTimer), 0.1f);
    return true;
}

void Level10::afterMoving()
{
    //    shadowBall->setVisible(true);
}

void Level10::onTimer(){
    

    if(nIndex > 4){
        unscheduleAllSelectors();
    }
}

void Level10::createBg()
{
    newSpriteForLession1("level_bg12", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    spHitBox = newSpriteForLession1("waterhitbox", G_SWIDTH/2, getYForLession1(300), this, -1, RATIO_XY);
    spSun = newSpriteForLession1("sun", getXForLession1(780), getYForLession1(80), this, -1, RATIO_X);
    spSun->setScale(0.7*G_SCALEX);
    
    newSpriteForLession1("shadow_child", getXForLession1(320), getYForLession1(500), this, -1, RATIO_Y);
    newSpriteForLession1("shadow_child", getXForLession1(700), getYForLession1(500), this, -1, RATIO_Y);
    
    josh = newSpriteForLession1("josh_air", getXForLession1(300), getYForLession1(300), this, -1, RATIO_Y);
    
    josh->runAction(CCSequence::create(CCMoveBy::create(1.f, ccp(0, 100 * G_SCALEY)), CCMoveBy::create(1.f, ccp(0, -100 * G_SCALEY)), CCMoveBy::create(1.f, ccp(0, 150 * G_SCALEY)),CCMoveTo::create(1.f, ccp(getXForLession1(300), getYForLession1(300))), NULL));
    
    emma = newSpriteForLession1("emma_air", getXForLession1(700), getYForLession1(300), this, -1, RATIO_Y);
    emma->runAction(CCSequence::create(CCMoveBy::create(1.f, ccp(0, 100 * G_SCALEY)), CCMoveBy::create(1.f, ccp(0, -100 * G_SCALEY)), CCMoveBy::create(1.f, ccp(0, 100 * G_SCALEY)),CCMoveTo::create(1.f, ccp(getXForLession1(700), getYForLession1(300))), NULL));
    
    lbFirst = newLabelForLession1("Josh and Emma had lots of", "Arial", 50, G_SWIDTH/2, getYForLession1(600), this, 0, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabelForLession1("fun at the beach!", "Arial", 50, G_SWIDTH/2, getYForLession1(680), this, 0, RATIO_X);
    lbSecond->setOpacity(0);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this, callfunc_selector(Level10::playEffect)), CCFadeIn::create(0.5f), NULL));
    lbSecond->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCFadeIn::create(0.5f), NULL));
}

void Level10::playEffect(){
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level10_01.wav");
}

void Level10::createMenu()
{
    btnBack = newButtonForLession1("back", getXForLession1(100), getYForLession1(670), this, menu_selector(Level10::onBack), false, RATIO_X);
    btnNext = newButtonForLession1("next", G_SWIDTH - getXForLession1(100), getYForLession1(670), this, menu_selector(Level10::onNext), false, RATIO_X);
    CCMenuItemImage *btnHome = newButtonForLession1("home", getXForLession1(100), getYForLession1(70), this, menu_selector(Level10::onHome), false, RATIO_X);
//    btnHome->setOpacity(120);

    
    menu = CCMenu::create(btnNext,btnBack,btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Level10::onHome()
{
    BridgeIOS::showHomeAlert();
}

void Level10::onBack(){

    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");

    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Level19::scene(), true));
}

void Level10::onNext(){

    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, MenuScene::scene(), false));

}

void Level10::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Level10::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    if (spSun->boundingBox().containsPoint(touchLocation)) {
        spSun->stopAllActions();
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("sun.wav");
        spSun->runAction(CCRotateBy::create(1.0f, 360.f));
        return true;
    }
    if (josh->boundingBox().containsPoint(touchLocation)||emma->boundingBox().containsPoint(touchLocation))
    {
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("laugh.wav");
        return true;
    }
    
    if (spHitBox->boundingBox().containsPoint(touchLocation)) {
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("water.wav");
    }
    return false;
}

void Level10::pickup(CCNode*pNode){
    
    pNode->stopAllActions();
    pNode->runAction(CCSequence::create(CCSpawn::create(CCScaleTo::create(1.0f, G_SCALEX*0.3f), CCJumpTo::create(1.f, ccp(getXForLession1(137), getYForLession1(400)), G_SCALEY*350, 1), NULL), CCCallFuncN::create(this, callfuncN_selector(Level10::removeClam)), NULL));
}

void Level10::removeClam(CCNode *node){
    nIndex++;
//    SimpleAudioEngine::sharedEngine()->playEffect("drop.wav");
    node->setVisible(false);
}
