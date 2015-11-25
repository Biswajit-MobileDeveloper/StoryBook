//
//  LoginViewController.m
//  JoshEmma
//
//  Created by Rijing on 4/30/15.
//
//

#import "LoginViewController.h"
#import "AppController.h"
#import "RecoverViewController.h"
#import "CreateViewController.h"

#import "GameConfig.h"




@interface LoginViewController ()
{
    IBOutlet UITextField *txtEmail;
    IBOutlet UITextField *txtPass;
    
    IBOutlet UIButton *btnClose;
    IBOutlet UIButton *btnSubmit;
    IBOutlet UIButton *btnCreate;    
    IBOutlet UIButton *btnRecover;
    IBOutlet UIButton *btnGuestLogin;
    
}

@end

@implementation LoginViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidDisappear:(BOOL)animated
{
//    [super viewDidDisappear:true];
//    [self dismissViewControllerAnimated:YES completion:nil];
   
    
}

- (void)viewDidAppear:(BOOL)animated
{
    if (g_bSubmit) {
        [self dismissViewControllerAnimated:true completion:nil];
    }
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    g_bSubmit = false;
    [btnClose.layer setCornerRadius:10.f];
    [btnClose.layer setMasksToBounds:YES];
    
    [btnSubmit.layer setCornerRadius:10.f];
    [btnSubmit.layer setMasksToBounds:YES];
    
    [btnCreate.layer setCornerRadius:10.f];
    [btnCreate.layer setMasksToBounds:YES];
    
    [btnRecover.layer setCornerRadius:10.f];
    [btnRecover.layer setMasksToBounds:YES];
    
    [btnGuestLogin.layer setCornerRadius:10.f];
    [btnGuestLogin.layer setMasksToBounds:YES];
    
    UITapGestureRecognizer *tapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(resignKeyboard:)];
    tapRecognizer.numberOfTapsRequired = 1;
    [self.view addGestureRecognizer:tapRecognizer];
    
}

- (void)resignKeyboard:(UIGestureRecognizer*)gestureRecognizer
{
    [txtEmail resignFirstResponder];
    [txtPass resignFirstResponder];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc
{
    [txtEmail release];
    [txtPass release];
    [btnClose release];
    [btnSubmit release];
    [btnCreate release];
    [btnRecover release];
    [btnGuestLogin release];
    [super dealloc];
}
- (IBAction)onClose:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)onSubmit:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
    AppController *app = (AppController*)[[UIApplication sharedApplication] delegate];
    [app loginAccount:txtEmail.text :txtPass.text :false];
}

- (IBAction)onCreate:(id)sender {
    if(UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone){
        CreateViewController *createView = [[CreateViewController alloc] initWithNibName:@"CreateViewController" bundle:nil];
        [self presentViewController:createView animated:YES completion:nil];
    }
    else
    {
        CreateViewController *createView = [[CreateViewController alloc] initWithNibName:@"CreateViewControllerIPAD" bundle:nil];
        [self presentViewController:createView animated:YES completion:nil];

    }
}

- (IBAction)onRecover:(id)sender {
    
    if(UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone){
        RecoverViewController *recoveryView = [[RecoverViewController alloc] initWithNibName:@"RecoverViewController" bundle:nil];
        [self presentViewController:recoveryView animated:YES completion:nil];
    }
    else
    {
        RecoverViewController *recoveryView = [[RecoverViewController alloc] initWithNibName:@"RecoverViewControllerIPAD" bundle:nil];
        [self presentViewController:recoveryView animated:YES completion:nil];
    }
}

- (IBAction)onGuestLogin:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];

    AppController *app = (AppController*)[[UIApplication sharedApplication] delegate];
    [app loginAccount:txtEmail.text :txtPass.text :true];
}


- (void) textFieldDidEndEditing:(UITextField *)textField
{
    [txtPass resignFirstResponder];
    [txtEmail resignFirstResponder];
    
}

-(BOOL) textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return true;
}

@end
