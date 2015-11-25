//
//  RecoverViewController.m
//  JoshEmma
//
//  Created by Rijing on 4/30/15.
//
//

#import "RecoverViewController.h"
#import "AppController.h"
#import "GameConfig.h"

@interface RecoverViewController ()
{
    
    IBOutlet UIButton *btnClose;
    IBOutlet UIButton *btnRecovery;
    IBOutlet UITextField *txtEmail;
    
}
@end

@implementation RecoverViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    [btnClose.layer setCornerRadius:10.f];
    [btnClose.layer setMasksToBounds:YES];
    
    [btnRecovery.layer setCornerRadius:10.f];
    [btnRecovery.layer setMasksToBounds:YES];
    
    UITapGestureRecognizer *tapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(resignKeyboard:)];
    tapRecognizer.numberOfTapsRequired = 1;
    [self.view addGestureRecognizer:tapRecognizer];
    
}

- (void)resignKeyboard:(UIGestureRecognizer*)gestureRecognizer
{
    [txtEmail resignFirstResponder];
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
    
}

- (void)dealloc {
    [btnClose release];
    [btnRecovery release];
    [txtEmail release];
    [super dealloc];
}
- (IBAction)onClose:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)onSubmit:(id)sender {
    g_bSubmit = true;
    [self dismissViewControllerAnimated:YES completion:nil];
    AppController *app = (AppController*)[[UIApplication sharedApplication] delegate];
    [app resetPass:txtEmail.text];
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
