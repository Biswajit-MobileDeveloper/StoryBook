//
//  Level15.cpp
//  JoshEmma
//
//  Created by Rijing on 4/19/15.
//
//

#include "Level15.h"

#include "GameSettingsForLession1.h"
#include "GameConfig.h"
#include "Level14.h"
#include "Level16.h"
#include "BridgeIOS.h"

USING_NS_CC;
CCScene* Level15::scene()
{
    CCScene *scene = CCScene::create();
    Level15 *layer = Level15::create();
    scene->addChild(layer);
    return scene;
}
bool Level15::init()
{
    if ( !CCLayer::init())
    {
        return false;
    }
    this->setTouchEnabled(true);
    createBg();
    createMenu();
    schedule(schedule_selector(Level15::onTimer));
    return true;
}

void Level15::onTimer()
{
    nCnt++;
    if(bStar1 && bStar2){
        lbSecond->runAction(CCSequence::create(CCDelayTime::create(1.0f),CCCallFunc::create(this, callfunc_selector(Level15::playEffect2)), CCFadeIn::create(1.0f), NULL));
//        this->setTouchEnabled(false);
        unscheduleAllSelectors();
        return;
    }
    if(!g_bAuto) return;
    
    if (!bStar1  && nCnt >= 100) {
        nCnt = 0;
        shadowStar1->setVisible(false);
        bStar1 = true;
        pickup(star1);
    }
    if (!bStar2  && nCnt >= 100) {
        nCnt = 0;
        bStar2 = true;
        shadowStar2->setVisible(false);
        pickup(star2);
    }
}

void Level15::createBg()
{
    
    newSpriteForLession1("level_bg12", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    spHitBox = newSpriteForLession1("waterhitbox", G_SWIDTH/2, getYForLession1(300), this, -1, RATIO_XY);
    spSun = newSpriteForLession1("sun", getXForLession1(780), getYForLession1(80), this, -1, RATIO_X);
    spSun->setScale(0.7*G_SCALEX);
    
    newSpriteForLession1("bucket_1", getXForLession1(136), getYForLession1(358), this, 1, RATIO_XY);
    spBucket = newSpriteForLession1("bucket_2", getXForLession1(137), getYForLession1(417), this, 3, RATIO_XY);
    
    
    spRock = newSpriteForLession1("rock", getXForLession1(410), G_SHEIGHT/2, this, 1, RATIO_XY);
    spRockShadow = newSpriteForLession1("shadow_rock", getXForLession1(410), G_SHEIGHT/2, this, -1, RATIO_XY);
    
    star1 = newSpriteForLession1("star", getXForLession1(650), getYForLession1(400), this, 1, RATIO_X);
    star2 = newSpriteForLession1("star", getXForLession1(850), getYForLession1(400), this, 1, RATIO_X);
    shadowStar1 = newSpriteForLession1("shadow_star", getXForLession1(650), getYForLession1(400), this, 0, RATIO_X);
    shadowStar2 = newSpriteForLession1("shadow_star", getXForLession1(850), getYForLession1(400), this, 0, RATIO_X);
    
    star1->runAction(CCRepeatForever::create(CCSequence::create(CCRotateTo::create(1.0f, 30), CCRotateTo::create(1.0f, 0), NULL)));
    star2->runAction(CCRepeatForever::create(CCSequence::create(CCRotateTo::create(1.0f, 30), CCRotateTo::create(1.0f, 0), NULL)));
    shadowStar1->runAction(CCRepeatForever::create(CCSequence::create(CCRotateTo::create(1.0f, 30), CCRotateTo::create(1.0f, 0), NULL)));
    shadowStar2->runAction(CCRepeatForever::create(CCSequence::create(CCRotateTo::create(1.0f, 30), CCRotateTo::create(1.0f, 0), NULL)));
    
    newSpriteForLession1("waterhitbox", G_SWIDTH/2, getYForLession1(300), this, 0, RATIO_XY);


    lbFirst = newLabelForLession1("What's next to the big rock?", "Arial", 50, G_SWIDTH/2, getYForLession1(600), this, 0, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabelForLession1("2 orange, pointy starfish!", "Arial", 50, G_SWIDTH/2, getYForLession1(680), this, 0, RATIO_X);
    lbSecond->setOpacity(0);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f),CCCallFunc::create(this, callfunc_selector(Level15::playEffect1)), CCFadeIn::create(1.0f), NULL));
    
    
}

void Level15::playEffect1()
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level5_01.wav");
}

void Level15::playEffect2(){
    
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level5_02.wav");
    
    if(g_bAuto){
        this->runAction(CCSequence::create(CCDelayTime::create(2.f),CCCallFunc::create(this, callfunc_selector(Level15::onNext)),NULL));
    }
}

void Level15::createMenu()
{
    btnBack = newButtonForLession1("back", getXForLession1(100), getYForLession1(670), this, menu_selector(Level15::onBack), false, RATIO_X);
    btnNext = newButtonForLession1("next", G_SWIDTH - getXForLession1(100), getYForLession1(670), this, menu_selector(Level15::onNext), false, RATIO_X);
    CCMenuItemImage *btnHome = newButtonForLession1("home", getXForLession1(100), getYForLession1(70), this, menu_selector(Level15::onHome), false, RATIO_X);
//    btnHome->setOpacity(120);
    menu = CCMenu::create(btnNext,btnBack,btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Level15::onHome()
{
    BridgeIOS::showHomeAlert();
}

void Level15::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Level14::scene(), true));
}

void Level15::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Level16::scene(), false));
}

void Level15::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}
void Level15::showShadow()
{
    spRockShadow->setVisible(true);
}
bool Level15::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
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
    
    if (spRock->boundingBox().containsPoint(touchLocation)) {
        spRock->stopAllActions();
        spRock->setPosition(ccp(getXForLession1(410), G_SHEIGHT/2));
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("rock.wav");
        spRockShadow->setVisible(false);
        spRock->runAction(CCSequence::create(CCJumpBy::create(1.f, ccp(0, 0), 150*G_SCALEY, 1),CCCallFunc::create(this, callfunc_selector(Level15::showShadow)), NULL));
        return false;
    }
    
    
    if (star1->boundingBox().containsPoint(touchLocation)){
        shadowStar1->setVisible(false);
        this->setTouchEnabled(false);
        bStar1 = true;
        pickup(star1);
        return false;
    }
    if (star2->boundingBox().containsPoint(touchLocation)) {
        shadowStar2->setVisible(false);
        this->setTouchEnabled(false);
        bStar2 = true;
        pickup(star2);
        return false;
    }
    if (spHitBox->boundingBox().containsPoint(touchLocation)) {
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("water.wav");
    }
    return false;
}

void Level15::pickup(CCNode*pNode){
    nIndex++;
    pNode->setScale(G_SCALEX*1.5f);

    
    CCSprite *one = newSpriteForLession1(CCString::createWithFormat("%d", nIndex)->getCString(), pNode->getPosition().x, pNode->getPosition().y, this, 1, RATIO_XY);
    
    SimpleAudioEngine::sharedEngine()->playEffect(CCString::createWithFormat("%d.wav", nIndex)->getCString());
    
    one->runAction(CCSequence::create(CCDelayTime::create(1.f), CCFadeOut::create(0.5f), NULL));
    
    
    pNode->stopAllActions();
    pNode->runAction(CCSequence::create(CCSpawn::create(CCScaleTo::create(1.0f, G_SCALEX*0.3f), CCJumpTo::create(1.f, ccp(getXForLession1(137), getYForLession1(400)), G_SCALEY*350, 1),CCRotateBy::create(1.0f, 360.f), NULL), CCCallFuncN::create(this, callfuncN_selector(Level15::removeStar)), NULL));
}

void Level15::removeStar(CCNode *node){
    this->setTouchEnabled(true);
    SimpleAudioEngine::sharedEngine()->playEffect("drop.wav");

    node->setVisible(false);
}
