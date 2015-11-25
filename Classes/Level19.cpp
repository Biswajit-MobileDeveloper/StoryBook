//
//  Level19.cpp
//  JoshEmma
//
//  Created by Rijing on 4/19/15.
//
//

#include "Level19.h"

#include "GameSettingsForLession1.h"
#include "GameConfig.h"
#include "Level18.h"
#include "Level10.h"
#include "BridgeIOS.h"

USING_NS_CC;
CCScene* Level19::scene()
{
    CCScene *scene = CCScene::create();
    Level19 *layer = Level19::create();
    scene->addChild(layer);
    return scene;
}
bool Level19::init()
{
    if ( !CCLayer::init())
    {
        return false;
    }
    
    createBg();
    createMenu();
    schedule(schedule_selector(Level19::onTimer), 0.1f);
    return true;
}

void Level19::afterMoving()
{
    //    shadowBall->setVisible(true);
}

void Level19::onTimer(){
    nCnt++;
    if(!g_bAuto)return;
//    if (nCnt/100 == index) {
//
//        shadowThing[index]->setScaleY(1.5*G_SCALEY);
//        shadowThing[index]->setScaleX(1.5*G_SCALEX);
//        pickup(spThing[index], index);
//        nAAA++;
//
//    }
//    index = nAAA;
}

void Level19::createBg()
{
    newSpriteForLession1("level_bg16", G_SWIDTH/2, G_SHEIGHT/2, this, -1, RATIO_XY);
    
    lbFirst = newLabelForLession1("Look what we found!", "Arial", 50, G_SWIDTH/2, getYForLession1(670), this, 0, RATIO_X);
    lbFirst->setOpacity(0);
    
    lbFirst->runAction(CCSequence::create(CCDelayTime::create(1.5f),CCCallFunc::create(this, callfunc_selector(Level19::playEffect)), CCFadeIn::create(0.5f),CCDelayTime::create(2.0f), CCFadeOut::create(0.5f), CCCallFunc::create(this, callfunc_selector(Level19::afterFirst)), NULL));
    
    lbSecond[0] = newLabelForLession1("1 white, fluffy feather!", "Arial", 50, G_SWIDTH/2, getYForLession1(670), this, 3, RATIO_X);
    lbSecond[0]->setOpacity(0);
    
    lbSecond[1] = newLabelForLession1("2 orange,  pointy starfish!", "Arial", 50, G_SWIDTH/2, getYForLession1(670), this, 3, RATIO_X);
    lbSecond[1]->setOpacity(0);
    
    lbSecond[2] = newLabelForLession1("3 grey clams!", "Arial", 50, G_SWIDTH/2, getYForLession1(670), this, 3, RATIO_X);
    lbSecond[2]->setOpacity(0);
    
    lbSecond[3] = newLabelForLession1("4 colorful seashells!", "Arial", 50, G_SWIDTH/2, getYForLession1(670), this, 3, RATIO_X);
    lbSecond[3]->setOpacity(0);
    
    lbSecond[4] = newLabelForLession1("5 pretty, purple flowers!", "Arial", 50, G_SWIDTH/2, getYForLession1(670), this, 3, RATIO_X);
    lbSecond[4]->setOpacity(0);
    
    
    
    spThing[0] =  newSpriteForLession1("thing1", getXForLession1(120), getYForLession1(150), this, 0, RATIO_Y);
    spThing[1] =  newSpriteForLession1("thing2", getXForLession1(380), getYForLession1(150), this, 0, RATIO_Y);
    spThing[2] =  newSpriteForLession1("thing3", getXForLession1(800), getYForLession1(180), this, 0, RATIO_Y);
    spThing[3] =  newSpriteForLession1("thing4", getXForLession1(280), getYForLession1(450), this, 0, RATIO_Y);
    spThing[4] =  newSpriteForLession1("thing5", getXForLession1(730), getYForLession1(450), this, 0, RATIO_Y);
    
    shadowThing[0] = newSpriteForLession1("shadow_thing1", getXForLession1(120), getYForLession1(150), this, -1, RATIO_Y);
    shadowThing[1] = newSpriteForLession1("shadow_thing2", getXForLession1(380), getYForLession1(150), this, -1, RATIO_Y);
    shadowThing[2] = newSpriteForLession1("shadow_thing3", getXForLession1(800), getYForLession1(180), this, -1, RATIO_Y);
    shadowThing[3] = newSpriteForLession1("shadow_thing4", getXForLession1(280), getYForLession1(450), this, -1, RATIO_Y);
    shadowThing[4] = newSpriteForLession1("shadow_thing5", getXForLession1(730), getYForLession1(450), this, -1, RATIO_Y);

}

void Level19::playEffect(){
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level9_01.wav");

}

void Level19::afterFirst(){
    this->setTouchEnabled(true);
}

void Level19::createMenu()
{
    btnBack = newButtonForLession1("back", getXForLession1(100), getYForLession1(670), this, menu_selector(Level19::onBack), false, RATIO_X);
    btnNext = newButtonForLession1("next", G_SWIDTH - getXForLession1(100), getYForLession1(670), this, menu_selector(Level19::onNext), false, RATIO_X);
    CCMenuItemImage *btnHome = newButtonForLession1("home", getXForLession1(100), getYForLession1(70), this, menu_selector(Level19::onHome), false, RATIO_X);
//    btnHome->setOpacity(120);
    menu = CCMenu::create(btnNext,btnBack,btnHome, NULL);
    menu->setPosition(ccp(0, 0));
    this->addChild(menu, 0);
}

void Level19::onHome()
{
    BridgeIOS::showHomeAlert();
}

void Level19::onBack(){
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Level18::scene(), true));
}

void Level19::onNext(){

    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playEffect("page_flip.wav");   
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.0f, Level10::scene(), false));
}

void Level19::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool Level19::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    for (int i = 0; i < 5; i++) {
        if(spThing[i]->boundingBox().containsPoint(touchLocation)){
//            pickup(spThing[i]);
            this->setTouchEnabled(false);
            shadowThing[i]->setScale(1.5*G_SCALEY);
            pickup(spThing[i], i);
            return true;
        }
    }
    
    return false;
}

void Level19::pickup(CCNode*pNode, int nIndex){
    
    pNode->setScale(1.5*G_SCALEY);

    
    CCSprite *one = newSpriteForLession1(CCString::createWithFormat("%d", nIndex + 1)->getCString(), pNode->getPosition().x, pNode->getPosition().y, this, 3, RATIO_XY);
    
    SimpleAudioEngine::sharedEngine()->playEffect(CCString::createWithFormat("level%d_02.wav", nIndex + 4)->getCString());
    
    one->runAction(CCSequence::create(CCDelayTime::create(1.f), CCFadeOut::create(0.5f), CCCallFuncN::create(this, callfuncN_selector(Level19::removeClam)), NULL));
    
    lbSecond[nIndex]->runAction(CCSequence::create(CCFadeIn::create(0.5f), CCDelayTime::create(1.f), CCFadeOut::create(0.5f),CCCallFunc::create(this, callfunc_selector(Level19::showShadow)),NULL));
    index = nIndex;
}

void Level19::showShadow(){

    this->setTouchEnabled(true);
    spThing[index]->setScale(G_SCALEY);
    shadowThing[index]->setScale(G_SCALEY);
    
    
}

void Level19::removeClam(CCNode *node)
{
    node->setVisible(false);
}