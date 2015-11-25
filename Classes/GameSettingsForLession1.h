//
//  GameSettingsForLession1.h
//  JoshEmma
//
//  Created by Biswajit Paul on 09/11/15.
//
//

#ifndef __JoshEmma__GameSettingsForLession1__
#define __JoshEmma__GameSettingsForLession1__

#include "GameConfig.h"

#define G_ORG_WIDTH 1024.0f
#define G_ORG_HEIGHT 768.0f

#define G_SWIDTH    (CCDirector::sharedDirector()->getVisibleSize().width)  //Screen width
#define G_SHEIGHT   (CCDirector::sharedDirector()->getVisibleSize().height)   //Screen height

#define G_SCALEX    (G_SWIDTH / G_ORG_WIDTH)
#define G_SCALEY    (G_SHEIGHT / G_ORG_HEIGHT)
#define G_SCALEO    (G_SCALEX<G_SCALEY?G_SCALEX:G_SCALEY)

#define DISX(X)  (X * G_SCALEX)
#define DISY(Y)  (Y * G_SCALEY)
#define DISO(O)  (O * G_SCALEO)

#define COL_ROW_TO_POINT(col, row) ccp(START_X+DELTA*col, START_Y+DELTA*row)

#define PIPE_DISTACE    getX(500)

typedef enum
{
    RATIO_XY = 0,
    RATIO_X,
    RATIO_Y,
    RATIO_O,
    RATIO_NO,
}Ratio;

float getXForLession1(int x);
float getYForLession1(int y);

CCSprite *newSpriteForLession1(const char *sName, float x, float y, CCNode* target, int zOrder, int nRatio);
CCMenuItemImage *newButtonForLession1(const char* btnName, float x, float y, CCNode* target, SEL_MenuHandler selector, bool isOneImage, int nRatio);

CCMenuItemToggle *newToggleButtonForLession1(const char *btnName, float x, float y, CCNode* target, SEL_MenuHandler selector, bool isOneImage, int nRatio);

CCLabelAtlas* newLabelForLession1(const char* txt, float x, float y, CCNode* target, int zOrder, int nRatio);
CCLabelTTF* newLabelForLession1(const char* txt, const char* fontname, int fontsize, float x, float y, CCNode* target, int zOrder, int Ratio);

void setScaleForLession1(CCNode *node, int nRatio);
void showParticleForLession1(const char *filename, CCNode *target, CCPoint pos);

void playEffectForLessionm1(const char* filename);
void loadSoundsForLession1();

#endif /* defined(__JoshEmma__GameSettingsForLession1__) */
