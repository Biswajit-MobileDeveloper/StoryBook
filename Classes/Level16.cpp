//
//  Level16.cpp
//  JoshEmma
//
//  Created by Rijing on 4/19/15.
//
//

#include "Level16.h"

#include "GameSettingsForLession1.h"
#include "GameConfig.h"
#include "Level15.h"
#include "Level17.h"
#include "BridgeIOS.h"

USING_NS_CC;
CCScene* Level16::scene()
{
    CCScene *scene = CCScene::create();
    Level16 *layer = Level16::create();
    scene->addChild(layer);
    return scene;
}
bool Level16::init()
{
    if ( !CCLayer::init())
    {
        return false;
    }
    this->setTouchEnabled(true);
    createBg();
    createMenu();
    schedule(schedule_selector(Level16::onTimer), 0.1f);
    return true;
}

void Level16::onTimer(){
    nCnt++;
    if(nIndex == 3){
        unscheduleAllSelectors();
        lbSecond->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this, callfunc_selector(Level16::playEffect2)),CCFadeIn::create(1.0f), NULL));
        return;
    }
    if(!g_bAuto) return;
    if (nCnt/100 - 1 == nIndex) {
        pickup(spClam[nIndex]);
    }
    
}

void Level16::createBg()
{
    newSpriteForLession1("level_bg12", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    spHitBox = newSpriteForLession1("waterhitbox", G_SWIDTH/2, getYForLession1(300), this, -1, RATIO_XY);
    
    spSun = newSpriteForLession1("sun", getXForLession1(780), getYForLession1(80), this, -1, RATIO_X);
    spSun->setScale(0.7*G_SCALEX);
    
    newSpriteForLession1("bucket_1", getXForLession1(136), getYForLession1(358), this, 1, RATIO_XY);
    spBucket = newSpriteForLession1("bucket_2", getXForLession1(137), getYForLession1(417), this, 3, RATIO_XY);
    
    newSpriteForLession1("waterhitbox", G_SWIDTH/2, getYForLession1(300), this, 0, RATIO_XY);
    
    spGrass = newSpriteForLession1("grass_1", getXForLession1(650), getYForLession1(320), this, 1, RATIO_XY);
    
    for (int i = 0; i < 3 ; i++) {
        spClam[i] = newSpriteForLession1("clam", getXForLession1(400 + i * 200), getYForLession1(490), this, 2, RATIO_X);
        spClam[i]->runAction(CCRepeatForever::create(CCSequence::create(CCDelayTime::create(1.f*i),CCMoveBy::create(1.5f, ccp(0, getXForLession1(20))), CCMoveBy::create(1.5f, ccp(0, -getXForLession1(20))), NULL)));
    }
    
    
    lbFirst = newLabelForLession1("What's in front of the tall grass?", "Arial", 50, G_SWIDTH/2, getYForLession1(600), this, 0, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabelForLession1("3 grey clams!", "Arial", 50, G_SWIDTH/2, getYForLession1(680), this, 0, RATIO_X);
    lbSecond->setOpacity(0);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f),CCCallFunc::create(this, callfunc_selector(Level16::playEffect1)), CCFadeIn::create(0.5f), NULL));
    
}

void Level16::playEffect1(){
    
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level6_01.wav");
}

void Level16::playEffect2(){
    
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level6_02.wav");
    if(g_bAuto){
        this->runAction(CCSequence::create(CCDelayTime::create(2.f),CCCallFunc::create(this, callfunc_selector(Level16::onNext)),NULL));
    }
}

void Level16::createMenu()
{
    btnBack = newButtonForLession1("back", getXForLession1(100), getYForLession1(670), this, menu_selector(Level16::onBack), false, RATIO_X);
    btnNext = newButtonForLession1("next", G_SWIDTH - getXForLession1(100), getYForLession1(670), this, menu_selector(Level16::onNext), false, RATIO_X);
    CCMenuItemImage *btnHome = newButtonForLession1("home", getXForLession1(100), getYForLession1(70), this, menu_selector(Level16::onHome), false, RATIO_X);
//    btnHome->setOpacity(120);
    menu = CCMenu::create(btnNext,btnBack,btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Level16::onHome()
{
    BridgeIOS::showHomeAlert();
}

void Level16::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Level15::scene(), true));
}

void Level16::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Level17::scene(), false));
}

void Level16::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Level16::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
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
    
    for (int i = 0; i<3; i++) {
        if (spClam[i]->boundingBox().containsPoint(touchLocation)) {
            spClam[i]->stopAllActions();
            pickup(spClam[i]);
            this->setTouchEnabled(false);
            return true;
        }
    }
    
    if (spGrass->boundingBox().containsPoint(touchLocation)) {
        spGrass->stopAllActions();
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("grass.wav");
        
        CCAnimation *animation = CCAnimation::create();
        animation->setDelayPerUnit(0.5f);
        
        for (int i = 0; i < 2; i ++) {
            CCTexture2D *txtr = CCTextureCache::sharedTextureCache()->addImage(CCString::createWithFormat("grass_%d.png", i+1)->getCString());
            CCSize size = txtr->getContentSize();
            CCRect rect = CCRectMake(0, 0, size.width, size.height);
            CCSpriteFrame *frame = CCSpriteFrame::createWithTexture(txtr, rect);
            animation->addSpriteFrame(frame);
        }
        animation->retain();
        
        spGrass->runAction(CCRepeat::create(CCAnimate::create(animation), 2));
        return false;
    }
    if (spHitBox->boundingBox().containsPoint(touchLocation)) {
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("water.wav");
    }
    
    
    return false;
}

void Level16::pickup(CCNode*pNode){
    nIndex++;
    pNode->setScale(G_SCALEX*1.5f);

    
    CCSprite *one = newSpriteForLession1(CCString::createWithFormat("%d", nIndex)->getCString(), pNode->getPosition().x, pNode->getPosition().y, this, 3, RATIO_XY);
    
    SimpleAudioEngine::sharedEngine()->playEffect(CCString::createWithFormat("%d.wav", nIndex)->getCString());
    
    one->runAction(CCSequence::create(CCDelayTime::create(1.f), CCFadeOut::create(0.5f), NULL));
    
    pNode->stopAllActions();
    pNode->runAction(CCSequence::create(CCSpawn::create(CCScaleTo::create(1.0f, G_SCALEX*0.3f), CCJumpTo::create(1.f, ccp(getXForLession1(137), getYForLession1(400)), G_SCALEY*350, 1), NULL), CCCallFuncN::create(this, callfuncN_selector(Level16::removeClam)), NULL));
}

void Level16::removeClam(CCNode *node){

    this->setTouchEnabled(true);
    node->setVisible(false);
    SimpleAudioEngine::sharedEngine()->playEffect("drop.wav");

}

