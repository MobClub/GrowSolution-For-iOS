//
//  AppDelegate.m
//  GrowSDKDemo
//
//  Created by 陈剑东 on 2018/6/19.
//  Copyright © 2018年 陈剑东. All rights reserved.
//

#import "AppDelegate.h"
#import "GSDKTabBarController.h"
#import "GSDKDemoViewController.h"
#import <ShareSDK/ShareSDK.h>
#import <ShareSDKConnector/ShareSDKConnector.h>
#import "WeiboSDK.h"
#import "WXApi.h"
#import <TencentOpenAPI/QQApiInterface.h>
#import <TencentOpenAPI/TencentOAuth.h>
#import "GSDKDemoNavigation.h"

#import <GrowSDKAdv/GrowSDKAdv.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


#define MOBSSDKSinaWeiboAppKey @"568898243"
//AppSecret
#define MOBSSDKSinaWeiboAppSecret @"38a4f8204cc784f81f9f0daaf31e02e3"
//RedirectUri
#define MOBSSDKSinaWeiboRedirectUri @"http://www.sharesdk.cn"
//AuthType 授权优先类型 web sso both
#define MOBSSDKSinaWeiboAuthType SSDKAuthTypeBoth

//AppID
#define MOBSSDKQQAppID @"100371282"
//AppKey
#define MOBSSDKQQAppKey @"aed9b0303e3ed1e27bae87c33761161d"
//AuthType
#define MOBSSDKQQAuthType SSDKAuthTypeBoth
//useTIM 是否优先使用TIM客户端
#define MOBSSDKQQUseTIM YES
//是否默认返回 UnionID v4.0.2增加
#define MOBSSDKQQBackUnionID NO

//AppID
#define MOBSSDKWeChatAppID @"wx4868b35061f87885"
//AppSecret
#define MOBSSDKWeChatAppSecret @"64020361b8ec4c99936c0e3999a9f249"
//是否默认返回 UnionID v4.0.2增加
#define MOBSSDKWeChatBackUnionID NO

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] init];
    self.window.frame = [UIScreen mainScreen].bounds;
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    
    GSDKDemoNavigation *navi = [[GSDKDemoNavigation alloc] initWithRootViewController:[[GSDKDemoViewController alloc] init]];
    self.window.rootViewController = navi;
    
//    GSDKTabBarController *tabVC = [[GSDKTabBarController alloc]init];
//    self.window.rootViewController = tabVC;
    
    //测试环境用
    //com.mob.code4app
    //21ed27f5dd1cc
    //94baf1d2e35937c26b296ed2644c07f0
    
    //Demo上线发布用
    //com.mob.product.GrowSDK
    //5727050f3f880
    //54dfc758141b98f9aafe2f1e5eb63b09
    

    //调起开屏广告
    [GrowSDKAdv requestLaunchAd:^(NSError *error) {
        
        if (error)
        {
            NSString *errors = [NSString stringWithFormat:@"开屏错误:%@",error];
            
            UIAlertView *al = [[UIAlertView alloc] initWithTitle:nil
                                                         message:errors
                                                        delegate:nil
                                               cancelButtonTitle:@"OK"
                                               otherButtonTitles:nil];
            [al show];
        }
        
    }];

    return YES;
}

@end
