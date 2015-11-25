//
//  CreateViewController.m
//  JoshEmma
//
//  Created by Rijing on 4/30/15.
//
//

#import "CreateViewController.h"
#import "GameConfig.h"
#import "AppController.h"

@interface CreateViewController ()
{
    
    IBOutlet UITextField *txtEmail;
    IBOutlet UITextField *txtPass;
    IBOutlet UITextField *txtFirstName;
    IBOutlet UITextField *txtLastName;
    IBOutlet UIButton *btnCreate;
    IBOutlet UIButton *btnClose;
    BOOL isParent;

    
}


@end

@implementation CreateViewController

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
    isParent = YES;

    [btnCreate.layer setCornerRadius:10.f];
    [btnCreate.layer setMasksToBounds:YES];

    [btnClose.layer setCornerRadius:10.f];
    [btnClose.layer setMasksToBounds:YES];
    
    UITapGestureRecognizer *tapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(resignKeyboard:)];
    tapRecognizer.numberOfTapsRequired = 1;
    [self.view addGestureRecognizer:tapRecognizer];
    
}

- (void)resignKeyboard:(UIGestureRecognizer*)gestureRecognizer
{
//    [self.view setFrame:CGRectMake(0, 0, self.view.bounds.size.height, self.view.bounds.size.width)];
    
    [txtEmail resignFirstResponder];
    [txtPass resignFirstResponder];
    [txtFirstName resignFirstResponder];
    [txtLastName resignFirstResponder];
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc {
    [txtEmail release];

    [txtPass release];

    [txtFirstName release];
    [txtLastName release];
    [btnCreate release];
    [btnClose release];
    [super dealloc];
}
- (IBAction)onClose:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)onSubmit:(id)sender
{
    [self dismissViewControllerAnimated:YES completion:nil];
    
    g_bSubmit = true;
    
    AppController *app = (AppController*)[[UIApplication sharedApplication] delegate];
    [app registerAccount:txtEmail.text :[NSString stringWithFormat:@"%@%@", txtFirstName.text, txtLastName.text] :txtPass.text];
}

- (BOOL) textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}

- (BOOL) textFieldShouldEndEditing:(UITextField *)textField
{
    [self.view setFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height)];
    

    return YES;
}

- (BOOL) textFieldShouldBeginEditing:(UITextField *)textField
{
    return YES;
}

@end
