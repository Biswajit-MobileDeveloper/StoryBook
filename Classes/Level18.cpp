//
//  Level18.cpp
//  JoshEmma
//
//  Created by Rijing on 4/19/15.
//
//

#include "Level18.h"

#include "GameSettingsForLession1.h"
#include "GameConfig.h"
#include "Level17.h"
#include "Level19.h"
#include "BridgeIOS.h"

USING_NS_CC;
CCScene* Level18::scene()
{
    CCScene *scene = CCScene::create();
    Level18 *layer = Level18::create();
    scene->addChild(layer);
    return scene;
}
bool Level18::init()
{
    if ( !CCLayer::init())
    {
        return false;
    }
    this->setTouchEnabled(true);
    createBg();
    createMenu();
    schedule(schedule_selector(Level18::onTimer), 0.1f);
    return true;
}

void Level18::afterMoving()
{
//    shadowBall->setVisible(true);
}

void Level18::onTimer(){
    if(nIndex > 4){
        unscheduleAllSelectors();
        lbSecond->runAction(CCSequence::create(CCDelayTime::create(1.0f),CCCallFunc::create(this, callfunc_selector(Level18::playEffect2)), CCFadeIn::create(1.0f), NULL));
        
    }
    if(!g_bAuto)return;
    
    nCnt++;
    if (nCnt/100 - 1 == nIndex) {
        shadowFlower[nIndex]->setVisible(false);
        pickup(spFlower[nIndex]);
        
    }
}

void Level18::createBg()
{
    newSpriteForLession1("level_bg15", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    newSpriteForLession1("bucket1_1", getXForLession1(141), getYForLession1(341), this, 1, RATIO_XY);
    spBucket = newSpriteForLession1("bucket1_2", getXForLession1(137), getYForLession1(417), this, 3, RATIO_XY);
    
    
    spFlower[0] = newSpriteForLession1("flower1", getXForLession1(600), getYForLession1(200), this, 2, RATIO_X);
    spFlower[1] = newSpriteForLession1("flower2", getXForLession1(800), getYForLession1(200), this, 2, RATIO_X);
    spFlower[2] = newSpriteForLession1("flower3", getXForLession1(500), getYForLession1(400), this, 2, RATIO_X);
    spFlower[3] = newSpriteForLession1("flower4", getXForLession1(700), getYForLession1(400), this, 2, RATIO_X);
    spFlower[4] = newSpriteForLession1("flower5", getXForLession1(900), getYForLession1(400), this, 2, RATIO_X);
    
    shadowFlower[0] = newSpriteForLession1("shadow_flower1", getXForLession1(600), getYForLession1(200), this, 1, RATIO_X);
    shadowFlower[1] = newSpriteForLession1("shadow_flower2", getXForLession1(800), getYForLession1(200), this, 1, RATIO_X);
    shadowFlower[2] = newSpriteForLession1("shadow_flower3", getXForLession1(500), getYForLession1(400), this, 1, RATIO_X);
    shadowFlower[3] = newSpriteForLession1("shadow_flower4", getXForLession1(700), getYForLession1(400), this, 1, RATIO_X);
    shadowFlower[4] = newSpriteForLession1("shadow_flower5", getXForLession1(900), getYForLession1(400), this, 1, RATIO_X);
    
    
    for (int i = 0; i < 5; i ++) {
        spFlower[i]->runAction(CCRepeatForever::create(CCSequence::create(CCDelayTime::create(1*i),CCMoveBy::create(2.f, ccp(0, 20*G_SCALEY)),CCMoveBy::create(1.f, ccp(0, -20*G_SCALEY)), NULL)));
        shadowFlower[i]->runAction(CCRepeatForever::create(CCSequence::create(CCDelayTime::create(1*i),CCMoveBy::create(2.f, ccp(0, 20*G_SCALEY)),CCMoveBy::create(1.f, ccp(0, -20*G_SCALEY)), NULL)));
    }
    
    
    lbFirst = newLabelForLession1("What's floating on the water?", "Arial", 50, G_SWIDTH/2, getYForLession1(600), this, 0, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabelForLession1("5 pretty, purple flowers!", "Arial", 50, G_SWIDTH/2, getYForLession1(680), this, 0, RATIO_X);
    lbSecond->setOpacity(0);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this, callfunc_selector(Level18::playEffect1)),CCFadeIn::create(0.5f), NULL));
    
}

void Level18::playEffect1(){
    
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level8_01.wav");
}

void Level18::playEffect2(){
    
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level8_02.wav");
    if(g_bAuto){
        this->runAction(CCSequence::create(CCDelayTime::create(2.f),CCCallFunc::create(this, callfunc_selector(Level18::onNext)),NULL));
    }
}

void Level18::createMenu()
{
    btnBack = newButtonForLession1("back", getXForLession1(100), getYForLession1(670), this, menu_selector(Level18::onBack), false, RATIO_X);
    btnNext = newButtonForLession1("next", G_SWIDTH - getXForLession1(100), getYForLession1(670), this, menu_selector(Level18::onNext), false, RATIO_X);
    CCMenuItemImage *btnHome = newButtonForLession1("home", getXForLession1(100), getYForLession1(70), this, menu_selector(Level18::onHome), false, RATIO_X);
//    btnHome->setOpacity(120);
    menu = CCMenu::create(btnNext,btnBack,btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Level18::onHome()
{
    BridgeIOS::showHomeAlert();
}

void Level18::onBack(){
    
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();

    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Level17::scene(), true));
}

void Level18::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Level19::scene(), false));
}

void Level18::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Level18::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
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
    for (int i = 0; i < 5; i++) {
        if(spFlower[i]->boundingBox().containsPoint(touchLocation)){
            pickup(spFlower[i]);
            this->setTouchEnabled(false);
            shadowFlower[i]->setVisible(false);
            return true;
        }
    }
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->playEffect("water.wav");
    
    return false;
}

void Level18::pickup(CCNode*pNode){
    nIndex++;
    pNode->setScale(G_SCALEX*1.5f);

    
    CCSprite *one = newSpriteForLession1(CCString::createWithFormat("%d", nIndex)->getCString(), pNode->getPosition().x, pNode->getPosition().y, this, 3, RATIO_XY);
    
    SimpleAudioEngine::sharedEngine()->playEffect(CCString::createWithFormat("%d.wav", nIndex)->getCString());
    
    one->runAction(CCSequence::create(CCDelayTime::create(1.f), CCFadeOut::create(0.5f), NULL));
    pNode->stopAllActions();
    pNode->runAction(CCSequence::create(CCSpawn::create(CCScaleTo::create(1.0f, G_SCALEX*0.3f), CCJumpTo::create(1.f, ccp(getXForLession1(137), getYForLession1(400)), G_SCALEY*350, 1), NULL), CCCallFuncN::create(this, callfuncN_selector(Level17::removeClam)), NULL));
}

void Level18::removeClam(CCNode *node){
    nIndex++;
    this->setTouchEnabled(true);
    node->setVisible(false);
    SimpleAudioEngine::sharedEngine()->playEffect("drop.wav");

}