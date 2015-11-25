//
//  BridgeIOS.mm
//  ZombieShock
//
//  Created by MingFuCui on 7/13/14.
//
//

#include "BridgeIOS.h"
#include "MenuScene.h"
#import "AppController.h"
void BridgeIOS::login(const char *username, const char *password){
    AppController *app = (AppController*)[UIApplication sharedApplication].delegate;
    [app loginAccount:[NSString stringWithUTF8String:username] :[NSString stringWithUTF8String:password]];
}

void BridgeIOS::logout(){
    AppController *app = (AppController*)[UIApplication sharedApplication].delegate;
    [app logoutSession];
}

void BridgeIOS::signup(const char*email, const char* password, const char*username, const char*childname, const char*childbirth){
    AppController *app = (AppController*)[UIApplication sharedApplication].delegate;
    [app registerAccount:[NSString stringWithUTF8String:email] :[NSString stringWithUTF8String:username] :[NSString stringWithUTF8String:password] :[NSString stringWithUTF8String:childname] :[NSString stringWithUTF8String:childbirth]];
}

void BridgeIOS::updateUserInfo(const char* username, const char*email, const char*password, const char*oldpassword, const char*childname, const char*childbirth)
{
    AppController *app = (AppController*)[UIApplication sharedApplication].delegate;
    [app updateUserInfo:[NSString stringWithUTF8String:email] :[NSString stringWithUTF8String:username] :[NSString stringWithUTF8String:password] :[NSString stringWithUTF8String:childname] :[NSString stringWithUTF8String:childbirth] :[NSString stringWithUTF8String:oldpassword]];
}

void BridgeIOS::recover(const char *email){
    AppController *app = (AppController*)[UIApplication sharedApplication].delegate;
    [app resetPass:[NSString stringWithUTF8String:email]];
}

bool BridgeIOS::getLoginSession(){
    AppController *app = (AppController*)[UIApplication sharedApplication].delegate;
    return [app getLoginSession];
}

bool BridgeIOS::getIsGuest()
{
    AppController *app = (AppController*)[UIApplication sharedApplication].delegate;
    return app.bGuest;
}


void BridgeIOS::showlogin(){
    AppController *app = (AppController*)[UIApplication sharedApplication].delegate;
    [app showLoginView];
}

void BridgeIOS::showEdit(){
    AppController *app = (AppController*)[UIApplication sharedApplication].delegate;
    [app showEditView];
}

void BridgeIOS::showEditPass()
{
    AppController *app = (AppController*)[UIApplication sharedApplication].delegate;
    [app showEditPassView];
}

void BridgeIOS::showMoreLesson()
{
    AppController *app = (AppController*)[UIApplication sharedApplication].delegate;
    [app showMoreLessons];
}

void BridgeIOS::showHomeAlert()
{
    AppController *app = (AppController*)[UIApplication sharedApplication].delegate;
    [app showHomeAlert];
}

void BridgeIOS::gotoHome(){
    CCDirector::sharedDirector()->replaceScene(MenuScene::scene());
}