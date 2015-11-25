//
//  GameConfig.h
//  SwingCopter
//
//  Created by MingFuCui on 8/10/14.
//
//

#ifndef ___SwingCopter__GameConfig__
#define ___SwingCopter__GameConfig__
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
//#include "GameScene.h"
#include "PlayScene.h"


class GameScene;


#define PTM_RATIO 32.0f

using namespace cocos2d;
using namespace CocosDenshion;

extern GameScene* g_lGameScene;
extern PlayScene* g_lPlayScene;
extern bool g_bSubmit;

extern bool g_bAuto;
extern int g_nScore;
extern int g_nProblem;
extern int g_nBestScore;
extern bool g_bADS;
extern bool g_bFromStart;
extern int g_nLife;
extern bool g_bSound;
extern bool g_bMusic;
extern int g_bIsGameOver;

extern CCAnimation* g_frmBlack;
extern CCAnimation* g_frmRed;


/// rijing customised
extern int g_nCurrentChar;
extern int g_nCurrentMap;

extern int adsIndex;
void loadGameInfo();
void saveGameInfo();

#define START_X (G_SWIDTH/2-getX(315-39))
#define START_Y (G_SHEIGHT/2-getX(315-47))
#define DELTA getX(78)


#endif /* defined(___SwingCopter__GameConfig__) */
