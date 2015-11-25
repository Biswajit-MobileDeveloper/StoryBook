//
//  Level17.cpp
//  JoshEmma
//
//  Created by Rijing on 4/19/15.
//
//

#include "Level17.h"

#include "GameSettingsForLession1.h"
#include "GameConfig.h"
#include "Level16.h"
#include "Level18.h"
#include "BridgeIOS.h"

USING_NS_CC;
CCScene* Level17::scene()
{
    CCScene *scene = CCScene::create();
    Level17 *layer = Level17::create();
    scene->addChild(layer);
    return scene;
}
bool Level17::init()
{
    if ( !CCLayer::init())
    {
        return false;
    }
    this->setTouchEnabled(true);
    createBg();
    createMenu();
    schedule(schedule_selector(Level17::onTimer), 0.1f);
    return true;
}

void Level17::afterMoving()
{
    shadowBall->setVisible(true);
}

void Level17::onTimer(){
    nCnt++;
    if(nIndex == 4){
        unscheduleAllSelectors();
        lbSecond->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this, callfunc_selector(Level17::playEffect2)), CCFadeIn::create(1.0f), NULL));
        return;
    }

    if(!g_bAuto)return;
    if (nCnt/100 - 1 == nIndex) {
        shadowShell[nIndex]->setVisible(false);
        pickup(spShell[nIndex]);

    }
}

void Level17::createBg()
{
    newSpriteForLession1("level_bg14", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    newSpriteForLession1("bucket_1", getXForLession1(136), getYForLession1(358), this, 1, RATIO_XY);
    spBucket = newSpriteForLession1("bucket_2", getXForLession1(137), getYForLession1(417), this, 3, RATIO_XY);
    
    spBall = newSpriteForLession1("ball", getXForLession1(700), G_SHEIGHT/2, this, 3, RATIO_X);
    spBall->setPosition(ccp(G_SWIDTH, getYForLession1(0)));
    spBall->runAction(CCSequence::create(CCMoveTo::create(0.7f, ccp(getXForLession1(700), G_SHEIGHT/2)), CCMoveBy::create(0.5f, ccp(0, getXForLession1(150))), CCMoveTo::create(0.5f, ccp(getXForLession1(700), G_SHEIGHT/2)),CCMoveBy::create(0.4f, ccp(0, getXForLession1(100))), CCMoveTo::create(0.3f, ccp(getXForLession1(700), G_SHEIGHT/2)),CCMoveBy::create(0.2f, ccp(0, getXForLession1(50))), CCMoveTo::create(0.1f, ccp(getXForLession1(700), G_SHEIGHT/2)), CCCallFunc::create(this, callfunc_selector(Level17::afterMoving)), NULL));
    
    shadowBall = newSpriteForLession1("shadow_ball", getXForLession1(705), G_SHEIGHT/2, this, 0, RATIO_X);
    shadowBall->setVisible(false);
    
    spShell[0] = newSpriteForLession1("seashell1", getXForLession1(450), getYForLession1(400), this, 2, RATIO_X);
    spShell[1] = newSpriteForLession1("seashell2", getXForLession1(420), getYForLession1(200), this, 2, RATIO_X);
    spShell[2] = newSpriteForLession1("seashell3", getXForLession1(700), getYForLession1(180), this, 2, RATIO_X);
    spShell[3] = newSpriteForLession1("seashell4", getXForLession1(900), getYForLession1(400), this, 2, RATIO_X);
    shadowShell[0] = newSpriteForLession1("shadow_shell1", getXForLession1(450), getYForLession1(400), this, 1, RATIO_X);
    shadowShell[1] = newSpriteForLession1("shadow_shell2", getXForLession1(420), getYForLession1(200), this, 1, RATIO_X);
    shadowShell[2] = newSpriteForLession1("shadow_shell3", getXForLession1(700), getYForLession1(180), this, 1, RATIO_X);
    shadowShell[3] = newSpriteForLession1("shadow_shell4", getXForLession1(900), getYForLession1(400), this, 1, RATIO_X);
    
    
    for (int i = 0; i < 4; i ++) {
        spShell[i]->runAction(CCRepeatForever::create(CCSequence::create(CCRotateBy::create(2.f, 20),CCRotateBy::create(1.f, -20), NULL)));
        shadowShell[i]->runAction(CCRepeatForever::create(CCSequence::create(CCRotateBy::create(2.f, 20),CCRotateBy::create(1.f, -20), NULL)));
    }
    
    
    lbFirst = newLabelForLession1("What's around the beach ball?", "Arial", 50, G_SWIDTH/2, getYForLession1(600), this, 0, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabelForLession1("4 colorful seashells!", "Arial", 50, G_SWIDTH/2, getYForLession1(680), this, 0, RATIO_X);
    lbSecond->setOpacity(0);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f),CCCallFunc::create(this, callfunc_selector(Level17::playEffect1)), CCFadeIn::create(0.5f), NULL));
    
}

void Level17::playEffect1(){
    
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level7_01.wav");
}

void Level17::playEffect2(){
    
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level7_02.wav");
    if(g_bAuto){
        this->runAction(CCSequence::create(CCDelayTime::create(2.f),CCCallFunc::create(this, callfunc_selector(Level17::onNext)),NULL));
    }
}

void Level17::createMenu()
{
    btnBack = newButtonForLession1("back", getXForLession1(100), getYForLession1(670), this, menu_selector(Level17::onBack), false, RATIO_X);
    btnNext = newButtonForLession1("next", G_SWIDTH - getXForLession1(100), getYForLession1(670), this, menu_selector(Level17::onNext), false, RATIO_X);
    CCMenuItemImage *btnHome = newButtonForLession1("home", getXForLession1(100), getYForLession1(70), this, menu_selector(Level17::onHome), false, RATIO_X);
//    btnHome->setOpacity(120);
    menu = CCMenu::create(btnNext,btnBack,btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Level17::onHome()
{
    BridgeIOS::showHomeAlert();
}

void Level17::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Level16::scene(), true));
}

void Level17::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Level18::scene(), false));
}

void Level17::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Level17::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    
    if (spBall->boundingBox().containsPoint(touchLocation)) {
        spBall->stopAllActions();
        spBall->setPosition(ccp(getXForLession1(700), G_SHEIGHT/2));
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("ball.wav");
        shadowBall->setVisible(false);
        spBall->runAction(CCSequence::create(CCJumpBy::create(0.6f, ccp(0, 0), 150*G_SCALEY, 1),CCJumpBy::create(0.4f, ccp(0, 0), 80*G_SCALEY, 1),CCJumpBy::create(0.2f, ccp(0, 0), 40*G_SCALEY, 1), CCCallFunc::create(this, callfunc_selector(Level17::afterMoving)),NULL));
        return false;
    }
    
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
    
    for (int i = 0; i < 4; i++) {
        if(spShell[i]->boundingBox().containsPoint(touchLocation)){
            pickup(spShell[i]);
            shadowShell[i]->setVisible(false);
            this->setTouchEnabled(false);
            return true;
        }
    }
    
    if(touchLocation.y>680*G_SCALEY){
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("water.wav");
    }
    
    
    return false;
}

void Level17::pickup(CCNode*pNode){
    
    nIndex++;
    pNode->setScale(G_SCALEX*1.5f);

    
    CCSprite *one = newSpriteForLession1(CCString::createWithFormat("%d", nIndex)->getCString(), pNode->getPosition().x, pNode->getPosition().y, this, 3, RATIO_XY);
    
    SimpleAudioEngine::sharedEngine()->playEffect(CCString::createWithFormat("%d.wav", nIndex)->getCString());
    
    one->runAction(CCSequence::create(CCDelayTime::create(1.f), CCFadeOut::create(0.5f), NULL));
    pNode->stopAllActions();
    pNode->runAction(CCSequence::create(CCSpawn::create(CCScaleTo::create(1.0f, G_SCALEX*0.3f), CCJumpTo::create(1.f, ccp(getXForLession1(137), getYForLession1(400)), G_SCALEY*350, 1), NULL), CCCallFuncN::create(this, callfuncN_selector(Level17::removeClam)), NULL));
}

void Level17::removeClam(CCNode *node){
    node->setVisible(false);
    this->setTouchEnabled(true);
    SimpleAudioEngine::sharedEngine()->playEffect("drop.wav");

}