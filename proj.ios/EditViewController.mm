//
//  EditViewController.m
//  JoshEmma
//
//  Created by Rijing on 4/30/15.
//
//

#import "EditViewController.h"
#import "AppController.h"

@interface EditViewController ()
{
    IBOutlet UITextField *txtFirstName;
    IBOutlet UITextField *txtLastName;
    
    IBOutlet UIButton *btnEditDone;
    IBOutlet UIButton *btnClose;
    BOOL isParent;
}

@end

@implementation EditViewController

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
    [btnClose.layer setCornerRadius:10.f];
    [btnClose.layer setMasksToBounds:YES];
    
    [btnEditDone.layer setCornerRadius:10.f];
    [btnEditDone.layer setMasksToBounds:YES];
    
    UITapGestureRecognizer *tapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(resignKeyboard:)];
    tapRecognizer.numberOfTapsRequired = 1;
    [self.view addGestureRecognizer:tapRecognizer];

}

- (void)resignKeyboard:(UIGestureRecognizer*)gestureRecognizer
{
    [txtFirstName resignFirstResponder];
    [txtLastName resignFirstResponder];
   
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc {
    
    [txtFirstName release];
    [txtLastName release];
   
    [btnEditDone release];
    [btnClose release];
    
    [super dealloc];
}
- (IBAction)onClose:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
    
}

- (IBAction)onEditDone:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
    AppController *app = (AppController*)[[UIApplication sharedApplication] delegate];
    [app updateUserInfo:[NSString stringWithFormat:@"%@%@", txtFirstName.text, txtLastName.text]];
}

- (BOOL) textFieldShouldBeginEditing:(UITextField *)textField
{
    

    return YES;
}

- (BOOL) textFieldShouldEndEditing:(UITextField *)textField{
//    [self.view setFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height)];
    return YES;
}



- (BOOL) textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}

@end
