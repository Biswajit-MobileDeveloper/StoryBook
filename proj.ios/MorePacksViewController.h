//
//  MorePacksViewController.h
//  JoshEmma
//
//  Created by Shenhua on 6/30/15.
//
//

#import <UIKit/UIKit.h>

@interface MorePacksViewController : UIViewController
{
    IBOutlet UIScrollView *scrollView;
    IBOutlet UIView *contentView;
    IBOutlet UIButton *btnClose;
}
- (IBAction)onClose:(id)sender;



@end
