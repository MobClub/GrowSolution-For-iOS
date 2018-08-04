//
//  GSDKDemoViewController.m
//  GrowSDKDemo
//
//  Created by Brilance on 2018/7/3.
//  Copyright © 2018年 陈剑东. All rights reserved.
//

#import "GSDKDemoViewController.h"
#import <GrowSDK/GrowSDK.h>
#import <GrowSDKUI/GrowSDKUI.h>
#import <MOBFoundation/MOBFDataService.h>

@interface GSDKDemoViewController ()
{
    
    __weak IBOutlet UILabel *_lbMobUserId;
    __weak IBOutlet UITextField *_userIdTextField;
}

@end

@implementation GSDKDemoViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    self.navigationItem.title = @"看新闻";
}
- (IBAction)binding:(id)sender
{

    [GrowSDK bindingAcount:_userIdTextField.text
                  nickName:@"我是昵称"
                    avatar:@"https://tvax1.sinaimg.cn/crop.0.0.1242.1242.300/6f030d46ly8fs9lmws1onj20yi0yiwhg.jpg"
                    result:^(NSString *mobUserId, NSError *error) {

                        if (!error)
                        {
                            [[MOBFDataService sharedInstance] setCacheData:_userIdTextField.text forKey:@"last" domain:@"GSDKDemo"];
                            _lbMobUserId.text = mobUserId;
                            NSLog(@"mobUserId:%@",mobUserId);
                        }
                        else
                        {
                            NSLog(@"error:%@",error);
                        }
                        
                    }];
}

- (IBAction)putInLast:(id)sender
{
     NSString *last = [[MOBFDataService sharedInstance] cacheDataForKey:@"last" domain:@"GSDKDemo"];
    
    _userIdTextField.text = last;
    
}

- (IBAction)startGrowSDK:(id)sender
{
    [GrowSDKUI defaultUI].type = GSDKUIControllerShowTypePresent;
    [[GrowSDKUI defaultUI] showFrom:self result:^(NSError *error) {
        
        if (error)
        {
            UIAlertView *al = [[UIAlertView alloc] initWithTitle:@"提示" message:@"请先绑定用户" delegate:nil cancelButtonTitle:@"好的" otherButtonTitles:nil];
            [al show];
        }
        
    }];

}


@end
