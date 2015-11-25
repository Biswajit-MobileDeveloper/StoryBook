//
//  EditPasswordViewController.m
//  JoshEmma
//
//  Created by Shenhua on 6/30/15.
//
//

#import "EditPasswordViewController.h"
#import "AppController.h"
#import <Parse/Parse.h>

@interface EditPasswordViewController ()

@end

@implementation EditPasswordViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    [btnSubmit.layer setCornerRadius:10.f];
    [btnSubmit.layer setMasksToBounds:YES];
    
    [btnClose.layer setCornerRadius:10.f];
    [btnClose.layer setMasksToBounds:YES];
    
    UITapGestureRecognizer *tapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(resignKeyboard:)];
    tapRecognizer.numberOfTapsRequired = 1;
    [self.view addGestureRecognizer:tapRecognizer];
    
}

- (void)resignKeyboard:(UIGestureRecognizer*)gestureRecognizer
{
    [txtNewPassword resignFirstResponder];
    [txtOldPasword resignFirstResponder];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc {
    [txtOldPasword release];
    [txtNewPassword release];
    [btnClose release];
    [btnSubmit release];
    [super dealloc];
}
- (IBAction)onSubmit:(id)sender {
//    PFUser *user = [PFUser currentUser];
//
//
//    if (user) {
//        NSString *userPass = user.password;
//        NSLog(@"%@", userPass);
//        if ([user.password isEqual:txtOldPasword.text]) {
        AppController *app = (AppController*)[[UIApplication sharedApplication] delegate];
        [app updatePasswordWithNewPassword:txtNewPassword.text oldPassword:txtOldPasword.text];
        
//        }
//    }
    
    [self dismissViewControllerAnimated:YES completion:nil];
    
    
}

- (IBAction)onClose:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (BOOL) textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}

-(BOOL) textFieldShouldEndEditing:(UITextField *)textField
{
    return YES;
}

- (BOOL) textFieldShouldBeginEditing:(UITextField *)textField
{
    
    return YES;
}
@end
