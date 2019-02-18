//
//  GSDKDemoViewController.m
//  GrowSDKDemo
//
//  Created by Max on 2019/1/28.
//  Copyright © 2019 陈剑东. All rights reserved.
//

#import "GSDKDemoViewController.h"
#import "GSDKTabBarController.h"
#import "GSDKFuncsViewController.h"
#import <GrowSDK/GrowSDK.h>

#define GSDKAlert(_S_, ...)     [[[UIAlertView alloc] initWithTitle:nil message:[NSString stringWithFormat:(_S_), ##__VA_ARGS__] delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:nil] show]

@interface GSDKDemoViewController ()

@end

@implementation GSDKDemoViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"增长变现";
}

- (IBAction)funcs:(id)sender
{
    GSDKFuncsViewController *vc = [[GSDKFuncsViewController alloc] init];
    [self.navigationController pushViewController:vc animated:YES];
}

- (IBAction)demo:(id)sender
{
    [GrowSDK bindingAcount:@"12345" nickName:@"nickname" avatar:@"https://tvax1.sinaimg.cn/crop.0.0.1242.1242.300/6f030d46ly8fs9lmws1onj20yi0yiwhg.jpg" result:^(NSString *mobUserId, NSError *error) {
        
        if (!error)
        {
            GSDKTabBarController *tabVC = [[GSDKTabBarController alloc] init];
            [self.navigationController presentViewController:tabVC animated:YES completion:nil];
        }
        else
        {
            GSDKAlert(@"%@",error);
        }
    }];
}

@end
