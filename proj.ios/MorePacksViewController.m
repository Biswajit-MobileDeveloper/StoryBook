//
//  MorePacksViewController.m
//  JoshEmma
//
//  Created by Shenhua on 6/30/15.
//
//

#import "MorePacksViewController.h"

@interface MorePacksViewController ()

@end

@implementation MorePacksViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    [scrollView setContentSize:contentView.frame.size];
    [btnClose.layer setCornerRadius:10.f];
    [btnClose.layer setMasksToBounds:YES];

}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (void)dealloc {
    [scrollView release];
    [contentView release];
    [btnClose release];
    [super dealloc];
}
- (IBAction)onClose:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}
@end
