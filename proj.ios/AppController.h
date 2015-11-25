#import <UIKit/UIKit.h>

@class RootViewController;

@interface AppController : NSObject <UIApplicationDelegate, UIAlertViewDelegate> {
    UIWindow *window;
    RootViewController    *viewController;
//    BOOL bGuest;
    
}

@property(nonatomic, assign) BOOL bGuest;
@property (nonatomic, strong)NSString *m_strPass;

- (void) registerAccount:(NSString *)strEmail :(NSString*) strName :(NSString*)password;
-(void) loginAccount:(NSString *)strName :(NSString*) strPass :(BOOL)isGuest;
- (void) resetPass:(NSString *)strEmail;
- (BOOL) getLoginSession;
- (void) logoutSession;
- (void) updateUserInfo:(NSString*) strName;
- (void) showLoginView;
- (void) showEditView;
- (void) showEditPassView;
- (void) showMoreLessons;
- (void) showHomeAlert;
- (void) updatePasswordWithNewPassword:(NSString*)str oldPassword:(NSString*)strOld;


@end

