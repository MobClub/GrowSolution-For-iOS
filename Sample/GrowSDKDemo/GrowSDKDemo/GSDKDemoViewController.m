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
#import <GrowSDKAdv/GrowSDKAdv.h>
#import <MOBFoundation/MOBFDataService.h>

@interface GSDKDemoViewController ()
{
    
    __weak IBOutlet UILabel *_lbMobUserId;
    __weak IBOutlet UITextField *_userIdTextField;
    
}

@property (nonatomic, weak) GSDKAdView *adView;

@end

@implementation GSDKDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    self.navigationItem.title = @"首页";
    
    //设置导航栏标题
//    NSDictionary *attributes=[NSDictionary dictionaryWithObjectsAndKeys: [UIFont fontWithName:@"PingFangSC-Medium" size:16],NSFontAttributeName,[MOBFColor colorWithRGB:0x272831],NSForegroundColorAttributeName,nil];
    //[self.navigationController.navigationBar setTitleTextAttributes:attributes];
    
    
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(keyboardHide)];
    tap.cancelsTouchesInView = NO;
    [self.view addGestureRecognizer:tap];
}

- (void)keyboardHide
{
    [_userIdTextField resignFirstResponder];
}

- (void)viewWillAppear:(BOOL)animated
{
    //开发者重置自身的导航设置
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
                            [[NSNotificationCenter defaultCenter] postNotificationName:@"BindingSuccess" object:nil];
                        }
                        else
                        {
                            
                            UIAlertView *al = [[UIAlertView alloc] initWithTitle:nil
                                                                         message:[NSString stringWithFormat:@"%@",error]
                                                                        delegate:nil
                                                               cancelButtonTitle:@"OK"
                                                               otherButtonTitles:nil];
                            [al show];
                            

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
    //[GrowSDKUI defaultUI].type = GSDKUIControllerShowTypePush;
    [[GrowSDKUI defaultUI] showFrom:self result:^(NSError *error) {
        
    }];
    
}

- (IBAction)showInstAd:(UIButton *)sender
{
    [GrowSDKAdv requestInstAd:^(BOOL isReady, GSDKInstAdView *instView, NSError *error) {

        if (isReady)
        {
            [instView showFromRootViewController:self];
        }

    }];
}

- (IBAction)showStreamAds:(UIButton *)sender
{
    [GrowSDKAdv requestAdStream:^(NSArray<GSDKAdStream *> *objects, NSError *error) {
       
        if (!error)
        {
            [objects enumerateObjectsUsingBlock:^(GSDKAdStream * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                
                NSString *news = [NSString stringWithFormat:@"广告总数:%lu \n 下标:%d \n title:%@ \n imgUrl:%@",(unsigned long)objects.count, idx,obj.title,obj.imageUrl];
                
                UIAlertView *al = [[UIAlertView alloc] initWithTitle:nil
                                                             message:news
                                                            delegate:nil
                                                   cancelButtonTitle:@"OK"
                                                   otherButtonTitles:nil];
                [al show];
            }];
            
        }
        
    }];
}
- (IBAction)showAdView:(id)sender
{
    //建议宽高比为 3：2
    
    CGFloat width = [UIScreen mainScreen].bounds.size.width;
    
    __weak typeof(GSDKDemoViewController*) weakSelf = self; 
    [GrowSDKAdv requestAdView:CGSizeMake(width, width * 2 / 3) result:^(GSDKAdView *adView, NSError *error) {
        
        if (!error)
        {
            [weakSelf.view addSubview:adView];
            weakSelf.adView = adView;
            [adView start];
            
        }

    }];
    
}
- (IBAction)removeAdView:(id)sender
{
    if (self.adView)
    {
        [self.adView removeFromSuperview];
        self.adView = nil;
    }
    
    
}
- (IBAction)getSignInfo:(id)sender
{
    [GrowSDK getTaskInfo:^(GSDKTaskInfo *taskInfo, NSError *error) {
        
        if (!error)
        {
            [self showMessage:[NSString stringWithFormat:@":今天是否签到:%d - 累计签到:%d",taskInfo.isSignToday,taskInfo.signCount]];
        }
        else
        {
            [self showMessage:[NSString stringWithFormat:@"获取失败，原因:%@",error.userInfo[@"error"]]];
        }

    }];
}

- (IBAction)signIn:(id)sender
{
    [GrowSDK signInToday:^(NSInteger coins, NSError *error) {
       
        if (!error)
        {
            [self showMessage:[NSString stringWithFormat:@"签到成功，获得金币:%ld",coins]];
        }
        else
        {
            [self showMessage:[NSString stringWithFormat:@"签到失败，原因:%@",error.userInfo[@"error"]]];
        }
        
    }];
}

- (void)showMessage:(NSString *)msg
{
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:nil
                                                                             message:msg
                                                                      preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction *act = [UIAlertAction actionWithTitle:@"OK"
                                                  style:UIAlertActionStyleDefault
                                                handler:nil];
    
    [alertController addAction:act];
    
    [self presentViewController:alertController animated:YES completion:nil];
}

@end
