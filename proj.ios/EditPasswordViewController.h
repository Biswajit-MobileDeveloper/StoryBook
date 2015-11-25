//
//  EditPasswordViewController.h
//  JoshEmma
//
//  Created by Shenhua on 6/30/15.
//
//

#import <UIKit/UIKit.h>

@interface EditPasswordViewController : UIViewController<UITextFieldDelegate>
{
    IBOutlet UITextField *txtOldPasword;
    IBOutlet UITextField *txtNewPassword;
    IBOutlet UIButton *btnClose;
    IBOutlet UIButton *btnSubmit;
    
}
- (IBAction)onSubmit:(id)sender;
- (IBAction)onClose:(id)sender;


@end
