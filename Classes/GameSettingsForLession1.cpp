//
//  GameSettingsForLession1.cpp
//  JoshEmma
//
//  Created by Biswajit Paul on 09/11/15.
//
//

#include "GameSettingsForLession1.h"

float getXForLession1(int x)
{
    float fx;
    
    fx = G_SWIDTH * x / G_ORG_WIDTH;
    return fx;
}

float getYForLession1(int y)
{
    float fy;
    fy = G_SHEIGHT - G_SHEIGHT * y / G_ORG_HEIGHT;
    return fy;
}

void playEffectForLession1(const char* filename)
{
    if (g_bSound)
        SimpleAudioEngine::sharedEngine()->playEffect(filename);
}

CCSprite *newSpriteForLession1(const char *sName, float x, float y,CCNode *target, int zOrder, int nRatio)
{
    CCSprite *sprite = CCSprite::create(CCString::createWithFormat("%s.png",sName)->getCString());
    setScaleForLession1(sprite, nRatio);
    
    sprite->setPosition(ccp(x, y));
    target->addChild(sprite ,zOrder);
    return sprite;
}

CCMenuItemImage *newButtonForLession1(const char * btnName, float x, float y,CCNode *target, SEL_MenuHandler selector, bool  isOneImage, int nRatio)
{
    CCMenuItemImage *item;
    
    if(isOneImage){
        item =CCMenuItemImage::create(CCString::createWithFormat("btn_%s.png", btnName)->getCString(),CCString::createWithFormat("btn_%s.png", btnName)->getCString(),CCString::createWithFormat("btn_%s.png",btnName)->getCString(),target, selector);
        
        CCSprite* normalImage=(CCSprite* )item->getNormalImage();
        CCSprite* selectedImage=(CCSprite*)item->getSelectedImage();
        CCSprite* disabledImage=(CCSprite*)item->getDisabledImage();
        
        selectedImage->setColor(ccc3(normalImage->getColor().r-100, normalImage->getColor().g-100,normalImage->getColor().b-100));
        disabledImage->setColor(ccc3(normalImage->getColor().r-100, normalImage->getColor().g-100,normalImage->getColor().b-100));
        
    }else{
        item = CCMenuItemImage::create(CCString::createWithFormat("btn_%s_normal.png", btnName)->getCString(),CCString::createWithFormat("btn_%s_pressed.png", btnName)->getCString(),target, selector);
        
    }
    setScaleForLession1(item, nRatio);
    item->setPosition(ccp(x, y));
    
    return item;
}


CCMenuItemToggle *newToggleButtonForLession1(const char *btnName, float x, float y,CCNode *target, SEL_MenuHandler selector, bool  isOneImage, int nRatio)
{
    CCMenuItemToggle *item;
    CCMenuItemImage *itemOn, *itemOff;
    
    if(isOneImage)
    {
        itemOn = CCMenuItemImage::create(CCString::createWithFormat("btn_%s_on.png", btnName)->getCString(),CCString::createWithFormat("btn_%s_on.png", btnName)->getCString());
        
        itemOff = CCMenuItemImage::create(CCString::createWithFormat("btn_%s_off.png", btnName)->getCString(),CCString::createWithFormat("btn_%s_off.png", btnName)->getCString());
        
        
        CCSprite* normalImage=(CCSprite* )itemOff->getNormalImage();
        CCSprite* selectedImage=(CCSprite*)itemOff->getSelectedImage();
        //        CCSprite* disabledImage=(CCSprite*)itemOff->getDisabledImage();
        
        //        selectedImage->setColor(ccc3(normalImage->getColor().r-200, normalImage->getColor().g-200,normalImage->getColor().b-200));
        //        disabledImage->setColor(ccc3(normalImage->getColor().r-100, normalImage->getColor().g-100,normalImage->getColor().b-100));
        //        normalImage->setColor(ccc3(normalImage->getColor().r-200, normalImage->getColor().g-200,normalImage->getColor().b-200));
    }
    else
    {
        itemOn = CCMenuItemImage::create(CCString::createWithFormat("btn_%son_u.png", btnName)->getCString(),CCString::createWithFormat("btn_%son_d.png", btnName)->getCString());
        
        itemOff = CCMenuItemImage::create(CCString::createWithFormat("btn_%soff_u.png", btnName)->getCString(),CCString::createWithFormat("btn_%soff_d.png", btnName)->getCString());
    }
    item = CCMenuItemToggle::createWithTarget(target, selector,itemOn, itemOff, NULL);
    setScaleForLession1(item, nRatio);
    item->setPosition(ccp(x, y));
    return item;
}

CCLabelAtlas* newLabelForLession1(const char* txt, float x, float y, CCNode* target, int zOrder, int nRatio){
    CCLabelAtlas* label=CCLabelAtlas::create(txt, "number.png", 50, 75, '0');
    label->setScale(G_SCALEY);
    label->setAnchorPoint(ccp(0.5, 0.5));
    label->setPosition(ccp(x, y));
    target->addChild(label, zOrder);
    return label;
    
}

CCLabelTTF* newLabelForLession1(const char* txt, const char* fontname, int fontsize, float x, float y, CCNode* target, int zOrder, int Ratio){
    CCLabelTTF* label = CCLabelTTF::create(txt, "Arial Rounded MT Bold", fontsize);
    label->setScale(G_SCALEY);
    label->setAnchorPoint(ccp(0.5, 0.5));
    label->setPosition(ccp(x, y));
    label->setColor(ccc3(0, 0, 0));
    target->addChild(label, zOrder);
    return label;
}

void setScaleForLession1(CCNode *node, int nRatio)
{
    if(nRatio == RATIO_XY)
    {
        node->setScaleX(G_SCALEX);
        node->setScaleY(G_SCALEY);
    }
    else if(nRatio == RATIO_X)
        node->setScale (G_SCALEX);
    else if(nRatio == RATIO_Y)
        node->setScale(G_SCALEY);
    else if(nRatio == RATIO_O)
        node->setScale(G_SCALEO);
}
void showParticleForLession1(const char *filename, CCNode *target, CCPoint pos)
{
    //    CCParticleSystemQuad *particle =CCParticleSystemQuad::create(filename);
    //    particle->setPosition(pos);
    //    particle->setScale(G_SCALEY);
    //    target->addChild(particle);
}

void loadSoundsForLession1()
{
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("level1_01.wav");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("level1_02.wav");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("level2_01.wav");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("level2_02.wav");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("level3_01.wav");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("level4_01.wav");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("level4_02.wav");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("level5_01.wav");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("level5_02.wav");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("level6_01.wav");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("level6_02.wav");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("level7_01.wav");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("level7_02.wav");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("level8_01.wav");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("level8_02.wav");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("level9_01.wav");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("level10_01.wav");
    
    //    SimpleAudioEngine::sharedEngine()->preloadEffect("button.mp3");
    //    SimpleAudioEngine::sharedEngine()->preloadEffect("sfx_hit.mp3");
    //    SimpleAudioEngine::sharedEngine()->preloadEffect("Landing.mp3");
    //    SimpleAudioEngine::sharedEngine()->preloadEffect("Jump.mp3");
}