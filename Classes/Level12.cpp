//
//  Level12.cpp
//  JoshEmma
//
//  Created by Rijing on 4/16/15.
//
//

#include "Level12.h"

#include "GameSettingsForLession1.h"
#include "GameConfig.h"
#include "Level11.h"
#include "Level13.h"
#include "BridgeIOS.h"

USING_NS_CC;
CCScene* Level12::scene()
{
    CCScene *scene = CCScene::create();
    Level12 *layer = Level12::create();
    scene->addChild(layer);
    return scene;
}
bool Level12::init()
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

void Level12::createBg()
{
    newSpriteForLession1("level_bg12", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    
    spSun = newSpriteForLession1("sun", getXForLession1(780), getYForLession1(80), this, -1, RATIO_X);
    spSun->setScale(0.7*G_SCALEX);
    
    spBall = newSpriteForLession1("ball", getXForLession1(150), getYForLession1(393) , this, 1, RATIO_X);
    spBallShadow = newSpriteForLession1("shadow_ball", getXForLession1(150), getYForLession1(393), this, -1, RATIO_X);
    
    
    spRock = newSpriteForLession1("rock", getXForLession1(410), G_SHEIGHT/2, this, 1, RATIO_XY);
    spRockShadow = newSpriteForLession1("shadow_rock", getXForLession1(410), G_SHEIGHT/2, this, -1, RATIO_XY);
    
    spHitBox = newSpriteForLession1("waterhitbox", G_SWIDTH/2, getYForLession1(300), this, 0, RATIO_XY);
    
    spGrass = newSpriteForLession1("grass_1", getXForLession1(750), G_SHEIGHT/2, this, 1, RATIO_XY);
    
    lbFirst = newLabelForLession1("Josh and Emma want to look around.", "Arial", 50, G_SWIDTH/2, getYForLession1(600), this, 0, RATIO_X);
    lbFirst->setOpacity(0);
    lbSecond = newLabelForLession1("What will they find?", "Arial", 50, G_SWIDTH/2, getYForLession1(680), this, 0, RATIO_X);
    lbSecond->setOpacity(0);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFunc::create(this,callfunc_selector(Level12::playEffect1)), CCFadeIn::create(0.5f), NULL));
    
    lbSecond->runAction(CCSequence::create(CCDelayTime::create(3.5f), CCCallFunc::create(this,callfunc_selector(Level12::playEffect2)), CCFadeIn::create(0.5f), NULL));
    
}

void Level12::playEffect1()
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level2_01.wav");
}

void Level12::playEffect2(){
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level2_02.wav");
    if(g_bAuto){
        this->runAction(CCSequence::create(CCDelayTime::create(2.f),CCCallFunc::create(this, callfunc_selector(Level12::onNext)),NULL));
    }
}


void Level12::createMenu()
{
    btnBack = newButtonForLession1("back", getXForLession1(100), getYForLession1(670), this, menu_selector(Level12::onBack), false, RATIO_X);
    btnNext = newButtonForLession1("next", G_SWIDTH - getXForLession1(100), getYForLession1(670), this, menu_selector(Level12::onNext), false, RATIO_X);
    CCMenuItemImage *btnHome = newButtonForLession1("home", getXForLession1(100), getYForLession1(70), this, menu_selector(Level12::onHome), false, RATIO_X);
//    btnHome->setOpacity(120);
    menu = CCMenu::create(btnNext,btnBack,btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Level12::onHome()
{
    BridgeIOS::showHomeAlert();
}


void Level12::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Level11::scene(), true));
}

void Level12::onNext(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Level13::scene(), false));
}

void Level12::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Level12::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
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
    if (spBall->boundingBox().containsPoint(touchLocation)) {
        spBall->stopAllActions();
        spBall->setPosition(ccp(getXForLession1(150), getYForLession1(393)));
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("ball.wav");
        spBallShadow->setVisible(false);
        spBall->runAction(CCSequence::create(CCJumpBy::create(0.6f, ccp(0, 0), 150*G_SCALEY, 1),CCJumpBy::create(0.4f, ccp(0, 0), 80*G_SCALEY, 1),CCJumpBy::create(0.2f, ccp(0, 0), 40*G_SCALEY, 1), CCCallFunc::create(this, callfunc_selector(Level12::showShadow)),NULL));
        return false;
    }
    
    if (spRock->boundingBox().containsPoint(touchLocation)) {
        spRock->stopAllActions();
        spRock->setPosition(ccp(getXForLession1(410), G_SHEIGHT/2));
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect("rock.wav");
        spRockShadow->setVisible(false);
        spRock->runAction(CCSequence::create(CCJumpBy::create(1.f, ccp(0, 0), 150*G_SCALEY, 1),CCCallFunc::create(this, callfunc_selector(Level12::showShadow)), NULL));
        return false;
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

void Level12::showShadow()
{
    spBallShadow->setVisible(true);
    spRockShadow->setVisible(true);
}
