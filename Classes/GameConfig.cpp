//
//  GameConfig.cpp
//  SwingCopter
//
//  Created by MingFuCui on 8/10/14.
//
//

#include "GameConfig.h"

GameScene* g_lGameScene = NULL;
PlayScene* g_lPlayScene = NULL;

bool g_bSubmit;

int g_nScore=0;
int g_nProblem = 0;
int g_nBestScore=0;
bool g_bADS=false;
bool g_bFromStart = true;
int g_bIsGameOver=0;
bool g_bSound=true;
bool g_bMusic=true;
bool g_bAuto = false;
int direction=0;
int adsIndex=0;
int g_nLife = 3;


CCAnimation* g_frmRed;
CCAnimation* g_frmBlack;


//// rijing customised
int g_nCurrentChar = 1;
int g_nCurrentMap = 0;

void loadGameInfo(){
    srand(time(NULL));

    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(1.0f);
    SimpleAudioEngine::sharedEngine()->setEffectsVolume(1.0f);

    g_nBestScore=CCUserDefault::sharedUserDefault()->getIntegerForKey("BestScore",g_nBestScore);
    g_bADS=CCUserDefault::sharedUserDefault()->getBoolForKey("ADS",g_bADS);
    g_bSound=CCUserDefault::sharedUserDefault()->getBoolForKey("SOUND", g_bSound);
    g_bMusic=CCUserDefault::sharedUserDefault()->getBoolForKey("MUSIC", g_bMusic);
    g_bFromStart = CCUserDefault::sharedUserDefault()->getBoolForKey("start", g_bFromStart);

}

void saveGameInfo(){
    
    CCUserDefault::sharedUserDefault()->setIntegerForKey("BestScore", g_nBestScore);
    CCUserDefault::sharedUserDefault()->setBoolForKey("ADS",g_bADS);
    CCUserDefault::sharedUserDefault()->setBoolForKey("SOUND", g_bSound);
    CCUserDefault::sharedUserDefault()->setBoolForKey("MUSIC", g_bMusic);
    CCUserDefault::sharedUserDefault()->setBoolForKey("start", g_bFromStart);
}
