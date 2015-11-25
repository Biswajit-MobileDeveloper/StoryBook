//
//  GameSettings.cpp
//  SwingCopter
//
//  Created by MingFuCui on 8/10/14.
//
//

#include "GameSettings.h"


float getX(int x)
{
    float fx;

    fx = G_SWIDTH * x / G_ORG_WIDTH;
    return fx;
}

float getY(int y)
{
    float fy;
    fy = G_SHEIGHT - G_SHEIGHT * y / G_ORG_HEIGHT;
    return fy;
}

void playEffect(const char* filename)
{
    if (g_bSound)
        SimpleAudioEngine::sharedEngine()->playEffect(filename);
}

CCSprite *newSprite(const char *sName, float x, float y,CCNode *target, int zOrder, int nRatio)
{
    CCSprite *sprite = CCSprite::create(CCString::createWithFormat("%s.png",sName)->getCString());
    setScale(sprite, nRatio);
    
    sprite->setPosition(ccp(x, y));
    target->addChild(sprite ,zOrder);
    return sprite;
}

CCMenuItemImage *newButton(const char * btnName, float x, float y,CCNode *target, SEL_MenuHandler selector, bool  isOneImage, int nRatio)
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
    setScale(item, nRatio);
    item->setPosition(ccp(x, y));
    
    return item;
}


CCMenuItemToggle *newToggleButton(const char *btnName, float x, float y,CCNode *target, SEL_MenuHandler selector, bool  isOneImage, int nRatio)
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
    setScale(item, nRatio);
    item->setPosition(ccp(x, y));
    return item;
}

CCLabelAtlas* newLabel(const char* txt, float x, float y, CCNode* target, int zOrder, int nRatio){
    CCLabelAtlas* label=CCLabelAtlas::create(txt, "number.png", 50, 75, '0');
    label->setScale(G_SCALEX);
    label->setAnchorPoint(ccp(0.5, 0.5));
    label->setPosition(ccp(x, y));
    target->addChild(label, zOrder);
    return label;
    
}

CCLabelTTF* newLabel(const char* txt, const char* fontname, int fontsize, float x, float y, CCNode* target, int zOrder, int Ratio){
    CCLabelTTF* label = CCLabelTTF::create(txt, "Arial Rounded MT Bold", fontsize);
    label->setScale(G_SCALEX);
    label->setAnchorPoint(ccp(0.5, 0.5));
    label->setPosition(ccp(x, y));
    label->setColor(ccc3(0, 0, 0));
    target->addChild(label, zOrder);
    return label;
}

void setScale(CCNode *node, int nRatio)
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
void showParticle(const char *filename, CCNode *target, CCPoint pos)
{
    //    CCParticleSystemQuad *particle =CCParticleSystemQuad::create(filename);
    //    particle->setPosition(pos);
    //    particle->setScale(G_SCALEY);
    //    target->addChild(particle);
}

void loadSounds()
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
    
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Train_01_a.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Train_02_a.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Train_02_b_whistle.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Train_03_a.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Train_04_a.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Train_05_a.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Train_06_a.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Train_07_a.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Train_08_a.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Train_09_a.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Train_10_a.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Zoo_04_b_adult monkey.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Zoo_05_b_adult lion.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Zoo_07_b_adult zebra.mp3");
}







