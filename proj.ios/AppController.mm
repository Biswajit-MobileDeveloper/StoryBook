#import "AppController.h"
#import "EAGLView.h"
#import "cocos2d.h"
#import "AppDelegate.h"
#import "RootViewController.h"
#import <Parse/Parse.h>
#import "MBProgressHUD.h"
#import "LoginViewController.h"
#import "RecoverViewController.h"
#import "CreateViewController.h"
#import "EditViewController.h"
#import "EditPasswordViewController.h"
#import "MorePacksViewController.h"
#import "BridgeIOS.h"


@implementation AppController

#pragma mark -
#pragma mark Application lifecycle

// cocos2d application instance
static AppDelegate s_sharedApplication;
@synthesize bGuest;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:
(NSDictionary *)launchOptions {
 
    self.m_strPass = @"";
    // Override point for customization after application launch.

    [Parse setApplicationId:@"NM963nl5KoDc0PSbFhOgDNyUuWHW835ysFfUSUbn" clientKey:@"9j1b1ZnBzvmNDTme3UzKNQEFallbGJOAMBk5yF1j"];
    [PFFacebookUtils initializeFacebook];
    // Add the view controller's view to the window and display.
    window = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];
    
    // Init the EAGLView
    EAGLView *__glView = [EAGLView viewWithFrame: [window bounds]
                                     pixelFormat: kEAGLColorFormatRGB565
                                      depthFormat: GL_DEPTH24_STENCIL8_OES
                              preserveBackbuffer: NO
                                      sharegroup: nil
                                   multiSampling: NO
                                 numberOfSamples: 0];

    // Use RootViewController manage EAGLView 
    viewController = [[RootViewController alloc] initWithNibName:nil bundle:nil];
    viewController.wantsFullScreenLayout = YES;
    viewController.view = __glView;

    // Set RootViewController to window
    if ( [[UIDevice currentDevice].systemVersion floatValue] < 6.0)
    {
        // warning: addSubView doesn't work on iOS6
        [window addSubview: viewController.view];
    }
    else
    {
        // use this method on ios6
        [window setRootViewController:viewController];
    }
    
    [window makeKeyAndVisible];
    
    [[UIApplication sharedApplication] setStatusBarHidden:true];
    
    cocos2d::CCApplication::sharedApplication()->run();

    return YES;
}
- (void) showLoginView
{

    if(UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone){
        LoginViewController *loginview = [[LoginViewController alloc] initWithNibName:@"LoginViewController" bundle:nil];
        [viewController presentViewController:loginview animated:YES completion:nil];
    }
    else
    {
        LoginViewController *loginview = [[LoginViewController alloc] initWithNibName:@"LoginViewControllerIPAD" bundle:nil];
        [viewController presentViewController:loginview animated:YES completion:nil];

    }
    
}

- (void) showMoreLessons{
    if(UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone){
        MorePacksViewController *morePack = [[MorePacksViewController alloc] initWithNibName:@"MorePacksViewController" bundle:nil];
        [viewController presentViewController:morePack animated:YES completion:nil];
        
    }
    else
    {
        EditPasswordViewController *morePack = [[EditPasswordViewController alloc] initWithNibName:@"MorePacksViewControllerIPAD" bundle:nil];
        [viewController presentViewController:morePack animated:YES completion:nil];
    }

}

- (void) showEditPassView
{
    if(UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone){
        EditPasswordViewController *editView = [[EditPasswordViewController alloc] initWithNibName:@"EditPasswordViewController" bundle:nil];
        [viewController presentViewController:editView animated:YES completion:nil];
        
    }
    else
    {
        EditPasswordViewController *editView = [[EditPasswordViewController alloc] initWithNibName:@"EditPasswordViewControllerIPAD" bundle:nil];
        [viewController presentViewController:editView animated:YES completion:nil];
    }

}

- (void) showEditView
{
    if(UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone){
        EditViewController *editView = [[EditViewController alloc] initWithNibName:@"EditViewController" bundle:nil];
        [viewController presentViewController:editView animated:YES completion:nil];

    }
    else
    {
        EditViewController *editView = [[EditViewController alloc] initWithNibName:@"EditViewControllerIPAD" bundle:nil];
        [viewController presentViewController:editView animated:YES completion:nil];
    }
}

- (void) showHomeAlert
{
    UIAlertView* alertView = [[UIAlertView alloc] initWithTitle:@"Alert" message:@"Are you sure you\n want to restart\n lesson and go\n home?" delegate:self cancelButtonTitle:@"NO" otherButtonTitles:@"YES", nil];
    [alertView show];
//    [alertView release];
}

- (void) registerAccount:(NSString *)strEmail :(NSString*) strName :(NSString*)password
{
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:viewController.view animated:YES];
	hud.labelText = @"Loading...";
    
    PFUser* newUser = [PFUser user];
    newUser.username = strEmail;
    newUser.email = strEmail;
    newUser.password = password;
   

    [newUser signUpInBackgroundWithBlock:^(BOOL succeeded, NSError *error) {
        [MBProgressHUD hideHUDForView:viewController.view animated:YES];
        
        if (error) {
            UIAlertView* alertView = [[UIAlertView alloc] initWithTitle:@"Error" message:[error.userInfo objectForKey:@"error"] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
            [alertView show];
            [alertView release];
        }
        else {
            [[PFInstallation currentInstallation] setObject:newUser forKey:@"user"];
            [[PFInstallation currentInstallation] saveEventually];
        }
    }];
}
- (void) logoutSession
{
    [PFUser logOut];
    [PFUser currentUser];
    [[NSUserDefaults standardUserDefaults] setBool:NO forKey:@"login"];
    bGuest = false;
}

- (void) updateUserInfo:(NSString*) strName
{
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:viewController.view animated:YES];
    hud.labelText = @"Loading...";
    
    
    PFUser *user = [PFUser currentUser];
    user.username = strName;
    [user saveInBackgroundWithBlock:^(BOOL succeeded, NSError *error) {
        [MBProgressHUD hideHUDForView:viewController.view animated:YES];
        if (error) {
            UIAlertView* alertView = [[UIAlertView alloc] initWithTitle:@"Error" message:[error.userInfo objectForKey:@"error"] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
            [alertView show];
            [alertView release];
        }
        else
        {
            NSLog(@"Anonymous user logged in.");
        }
        
    }];
}
- (BOOL) getLoginSession{
    BOOL isLogin = [[NSUserDefaults standardUserDefaults] boolForKey:@"login"];
//    PFUser* currentUser = [PFUser currentUser];
//    if (currentUser) {
////        [[PFInstallation currentInstallation] setObject:currentUser forKey:@"user"];
////        [[PFInstallation currentInstallation] saveInBackground];
//        return  true;
//    }
//    else
        return isLogin;
}

- (void) resetPass:(NSString *)strEmail
{
    [PFUser requestPasswordResetForEmailInBackground:strEmail];
    UIAlertView* alertView = [[UIAlertView alloc] initWithTitle:@"Alert!" message:@"Sent mail" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
    [alertView show];
    [alertView release];
}

-(void) loginAccount:(NSString *)strName :(NSString*) strPass :(BOOL)isGuest
{
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:viewController.view animated:YES];
	hud.labelText = @"Loading...";
    
    if (isGuest) {
        [PFAnonymousUtils logInWithBlock:^(PFUser *user, NSError *error) {
            [MBProgressHUD hideHUDForView:viewController.view animated:YES];
            if (error) {
                UIAlertView* alertView = [[UIAlertView alloc] initWithTitle:@"Error" message:[error.userInfo objectForKey:@"error"] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
                [alertView show];
                [alertView release];
            }
            else
            {
                NSLog(@"Anonymous user logged in.");
                bGuest = true;
            }
                
        }];
    }
    else
    {
        [PFUser logInWithUsernameInBackground:strName password:strPass block:^(PFUser *user, NSError *error) {
            [MBProgressHUD hideHUDForView:viewController.view animated:YES];
            
            if (error) {
                UIAlertView* alertView = [[UIAlertView alloc] initWithTitle:@"Error" message:[error.userInfo objectForKey:@"error"] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
                [alertView show];
                [alertView release];
            }
            else
            {
                [[PFInstallation currentInstallation] setObject:user forKey:@"user"];
                [[PFInstallation currentInstallation] saveEventually];
                self.m_strPass = [NSString stringWithFormat:@"%@", strPass];
                [[NSUserDefaults standardUserDefaults] setBool:YES forKey:@"login"];
                NSLog(@"++++++_____+++++%@", self.m_strPass);
            }
        }];
    }
    
    
    
}

- (void) updatePasswordWithNewPassword:(NSString*)str oldPassword:(NSString*)strOld
{
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:viewController.view animated:YES];
    hud.labelText = @"Loading...";
    
    if (![strOld isEqualToString:self.m_strPass]){
        UIAlertView* alertView = [[UIAlertView alloc] initWithTitle:@"Error" message:@"You have not match old password or You are a guest!" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
        [alertView show];
        [alertView release];
        return;
    }
    
    PFUser *user = [PFUser currentUser];
    user.password = str;
    [user saveInBackgroundWithBlock:^(BOOL succeeded, NSError *error) {
        [MBProgressHUD hideHUDForView:viewController.view animated:YES];
        if (error) {
            UIAlertView* alertView = [[UIAlertView alloc] initWithTitle:@"Error" message:[error.userInfo objectForKey:@"error"] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
            [alertView show];
            [alertView release];
        }
        else
        {
            NSLog(@"Anonymous user logged in.");
        }
        
    }];

}


- (void)application:(UIApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken
{
    // Store the deviceToken in the current installation and save it to Parse.
    PFInstallation *currentInstallation = [PFInstallation currentInstallation];
    [currentInstallation setDeviceTokenFromData:deviceToken];
    [currentInstallation saveInBackground];
}


- (void)applicationWillResignActive:(UIApplication *)application {
    /*
     Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
     Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
     */
    cocos2d::CCDirector::sharedDirector()->pause();
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    /*
     Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
     */
    cocos2d::CCDirector::sharedDirector()->resume();
    if(bGuest)
    {
        bGuest = false;
        
    }
    if(![self getLoginSession]) [self showLoginView];
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    /*
     Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
     If your application supports background execution, called instead of applicationWillTerminate: when the user quits.
     */
    cocos2d::CCApplication::sharedApplication()->applicationDidEnterBackground();
//    if(bGuest) {
//        [PFUser logOut];
//        [PFUser currentUser];
//    }
    
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    /*
     Called as part of  transition from the background to the inactive state: here you can undo many of the changes made on entering the background.
     */
    cocos2d::CCApplication::sharedApplication()->applicationWillEnterForeground();
   
}

- (void)applicationWillTerminate:(UIApplication *)application {
    /*
     Called when the application is about to terminate.
     See also applicationDidEnterBackground:.
     */
    if(bGuest) {
        [PFUser logOut];
        [PFUser currentUser];
    }

}


-(void) alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    if(buttonIndex == 1)
    {
        BridgeIOS::gotoHome();
    }
    else
    {
        return;
    }

}


#pragma mark -
#pragma mark Memory management

- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application {
    /*
     Free up as much memory as possible by purging cached data objects that can be recreated (or reloaded from disk) later.
     */
}


- (void)dealloc {
    [window release];
    [super dealloc];
}


@end
