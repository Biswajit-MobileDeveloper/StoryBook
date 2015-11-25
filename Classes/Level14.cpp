//
//  Level14.cpp
//  JoshEmma
//
//  Created by Rijing on 4/18/15.
//
//

#include "Level14.h"
#include "GameSettingsForLession1.h"
#include "GameConfig.h"
#include "Level15.h"
#include "Level13.h"
#include "BridgeIOS.h"

USING_NS_CC;
CCScene* Level14::scene()
{
    CCScene *scene = CCScene::create();
    Level14 *layer = Level14::create();
    scene->addChild(layer);
    return scene;
}
bool Level14::init()
{
    if ( !CCLayer::init())
    {
        return false;
    }
    this->setTouchEnabled(true);
    createBg();
    createMenu();
    bFlip = false;
    schedule(schedule_selector(Level14::onTimer), 0.1f);
    return true;
}
void Level14::onTimer(){
    if(!g_bAuto) return;
        nTimer++;
        if (nTimer >= 100) {
            unscheduleAllSelectors();
            pickup();
        }
    
}

void Level14::flipFeather(){

    bFlip =!bFlip;
    spFeather->setFlipX(bFlip);
}

void Level14::createBg()
{
    newSpriteForLession1("level_bg13", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    
    newSpriteForLession1("bucket_1", getXForLession1(136), getYForLession1(358), this, -1, RATIO_XY);
    spBucket = newSpriteForLession1("bucket_2", getXForLession1(137), getYForLession1(417), this, 1, RATIO_XY);
    
    
    spFeather = newSpriteForLession1("feather", G_SWIDTH, getYForLession1(0), this, 0, RATIO_X);
    
    spFeather->runAction(CCSequence::create(CCMoveTo::create(1.f, ccp(getXForLession1(600), getYForLession1(150))),CCCallFunc::create(this, callfunc_selector(Level14::flipFeather)),CCMoveTo::create(0.8f, ccp(getXForLession1(900), getYForLession1(280))),CCCallFunc::create(this, callfunc_selector(Level14::flipFeather)),CCMoveTo::create(1.f, ccp(getXForLession1(650), getYForLession1(400))),CCCallFunc::create(this, callfunc_selector(Level14::afterMoving)), NULL));
    spFeaderShadow = newSpriteForLession1("shadow_feather", getXForLession1(650), getYForLession1(400), this, -1, RATIO_X);
    spFeaderShadow->setVisible(false);
    
    lbFirst = newLabelForLession1("What's on the sand?", "Arial", 50, G_SWIDTH/2, getYForLession1(600), this, 0, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabelForLession1("1 white, fluffy feather!", "Arial", 50, G_SWIDTH/2, getYForLession1(680), this, 0, RATIO_X);
    lbSecond->setOpacity(0);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this, callfunc_selector(Level14::playEffect1)), CCFadeIn::create(1.0f), NULL));
    
    
}

void Level14::afterMoving(){
        spFeaderShadow->setVisible(true);
}

void Level14::playEffect1(){
    
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level4_01.wav");
}

void Level14::playEffect2(){
    
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level4_02.wav");
    if(g_bAuto){
        this->runAction(CCSequence::create(CCDelayTime::create(2.f),CCCallFunc::create(this, callfunc_selector(Level14::onNext)),NULL));
    }
}

void Level14::pickup()
{
    spFeaderShadow->setVisible(false);
    spFeather->setScale(G_SCALEX*1.5f);

    spFeather->setPosition(ccpAdd(spFeather->getPosition(), ccp(0, 30*G_SCALEY)));
    
    CCSprite *one = newSpriteForLession1("1", spFeather->getPosition().x, spFeather->getPosition().y, this, 1, RATIO_XY);
    SimpleAudioEngine::sharedEngine()->playEffect("1.wav");
    one->runAction(CCSequence::create(CCDelayTime::create(1.f), CCFadeOut::create(0.5f), NULL));
    
    spFeather->runAction(CCSequence::create(CCSpawn::create(CCScaleTo::create(1.0f, G_SCALEX*0.3f), CCJumpTo::create(1.f, ccp(getXForLession1(137), getYForLession1(400)), G_SCALEY*300, 1), NULL), CCCallFunc::create(this, callfunc_selector(Level14::removeFeather)), NULL));
}

void Level14::removeFeather(){
//    spFeather->removeFromParentAndCleanup(true);
    SimpleAudioEngine::sharedEngine()->playEffect("drop.wav");

    spFeather->setVisible(false);
    this->setTouchEnabled(true);
    lbSecond->runAction(CCSequence::create(CCDelayTime::create(1.0f),CCCallFunc::create(this, callfunc_selector(Level14::playEffect2)), CCFadeIn::create(1.0f), NULL));
}

void Level14::createMenu()
{
    btnBack = newButtonForLession1("back", getXForLession1(100), getYForLession1(670), this, menu_selector(Level14::onBack), false, RATIO_X);
    btnNext = newButtonForLession1("next", G_SWIDTH - getXForLession1(100), getYForLession1(670), this, menu_selector(Level14::onNext), false, RATIO_X);
    CCMenuItemImage *btnHome = newButtonForLession1("home", getXForLession1(100), getYForLession1(70), this, menu_selector(Level14::onHome), false, RATIO_X);
//    btnHome->setOpacity(120);
    menu = CCMenu::create(btnNext,btnBack,btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Level14::onHome()
{
    BridgeIOS::showHomeAlert();
}

void Level14::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Level13::scene(), true));
}

void Level14::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Level15::scene(), false));
}

void Level14::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Level14::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    
    if (spBucket->boundingBox().containsPoint(touchLocation)) {
        spBucket->stopAllActions();
        //        spFeather->runAction(CCRotateBy::create(1.0f, 360.f));
//        this->unscheduleAllSelectors();
//        pickup();
//        this->setTouchEnabled(false);
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("bucket.wav");
        return false;
    }
    
    if (spFeather->boundingBox().containsPoint(touchLocation)) {
        spFeather->stopAllActions();
//        spFeather->runAction(CCRotateBy::create(1.0f, 360.f));
        this->unscheduleAllSelectors();
        pickup();
        this->setTouchEnabled(false);
        return false;
    }
    if(touchLocation.x < getXForLession1(150) && touchLocation.y > 650*G_SCALEY){
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("water.wav");
        
    }
    
    return false;
}