//
//  BridgeIOS.h
//  ZombieShock
//
//  Created by MingFuCui on 7/13/14.
//
//


class BridgeIOS {
public:
    static void login(const char* username, const  char *password);
    static void recover(const char*email);
    static void signup(const char*email, const char* password, const char*username, const char*childname, const char*childbirth);
    static void updateUserInfo(const char* username, const char*email, const char*password, const char*oldpassword, const char*childname, const char*childbirth);
    static bool getLoginSession();
    static void logout();
    static void showlogin();
    static void showEdit();
    static void showEditPass();
    static void showMoreLesson();
    static void showHomeAlert();
    static void gotoHome();
    static bool getIsGuest();
};


