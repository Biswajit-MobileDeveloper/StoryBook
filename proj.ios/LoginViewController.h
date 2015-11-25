//
//  LoginViewController.h
//  JoshEmma
//
//  Created by Rijing on 4/30/15.
//
//

#import <UIKit/UIKit.h>

@interface LoginViewController : UIViewController<UITextFieldDelegate>

- (IBAction)onClose:(id)sender;

- (IBAction)onSubmit:(id)sender;

- (IBAction)onCreate:(id)sender;

- (IBAction)onRecover:(id)sender;

- (IBAction)onGuestLogin:(id)sender;

@end
