//
//  GameSettings.h
//  SwingCopter
//
//  Created by MingFuCui on 8/10/14.
//
//

#ifndef ___SwingCopter__GameSettings__
#define ___SwingCopter__GameSettings__

#include "GameConfig.h"


#define G_ORG_WIDTH 1136.0f
#define G_ORG_HEIGHT 640.0f

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

float getX(int x);
float getY(int y);

CCSprite *newSprite(const char *sName, float x, float y, CCNode* target, int zOrder, int nRatio);
CCMenuItemImage *newButton(const char* btnName, float x, float y, CCNode* target, SEL_MenuHandler selector, bool isOneImage, int nRatio);

CCMenuItemToggle *newToggleButton(const char *btnName, float x, float y, CCNode* target, SEL_MenuHandler selector, bool isOneImage, int nRatio);

CCLabelAtlas* newLabel(const char* txt, float x, float y, CCNode* target, int zOrder, int nRatio);
CCLabelTTF* newLabel(const char* txt, const char* fontname, int fontsize, float x, float y, CCNode* target, int zOrder, int Ratio);

void setScale(CCNode *node, int nRatio);
void showParticle(const char *filename, CCNode *target, CCPoint pos);

void playEffect(const char* filename);
void loadSounds();

#endif /* defined(___SwingCopter__GameSettings__) */
