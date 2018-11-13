//
//  GSDKTabBarController.m
//  GrowSDKDemo
//
//  Created by Brilance on 2018/6/19.
//  Copyright © 2018年 陈剑东. All rights reserved.
//

#import "GSDKTabBarController.h"
#import "GSDKDemoNavigation.h"
#import "GSDKDemoViewController.h"
#import <MOBFoundation/MOBFColor.h>
#import <GrowSDKUI/GrowSDKUI.h>


@interface GSDKTabBarController ()

@end

@implementation GSDKTabBarController


- (void)viewDidLoad{
    [super viewDidLoad];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(reloadTabbarVC) name:@"BindingSuccess" object:nil];
    
//    [[UITabBarItem appearance] setTitleTextAttributes:[NSDictionary dictionaryWithObjectsAndKeys:[UIColor grayColor],NSForegroundColorAttributeName, nil] forState:UIControlStateNormal];
//
//    [[UITabBarItem appearance] setTitleTextAttributes:[NSDictionary dictionaryWithObjectsAndKeys:[UIColor blueColor],NSForegroundColorAttributeName, nil] forState:UIControlStateSelected];
    
    // 首页
    UIViewController * naviHome = [self addChildController:[[GSDKDemoViewController alloc]init] title:@"首页" normalImage:@"home_normal" selectedImage:@"home_select"];
    
    [self setViewControllers: @[naviHome]];
    
}

//用户绑定后刷新tab
- (void)reloadTabbarVC
{
    NSMutableArray *tabbarViewControllers = [self.viewControllers mutableCopy];
    if (tabbarViewControllers.count > 1) {
        [tabbarViewControllers removeObjectAtIndex:1];
    }
    
    UIViewController * gsdkVC = [[GrowSDKUI defaultUI] gsdkMainViewController:^(NSError *error) {
        
    }];
    if (gsdkVC) {
        UIViewController *naviGsdk = [self addChildController:gsdkVC title:@"新闻" normalImage:@"account_normal" selectedImage:@"account_select"];
        [tabbarViewControllers addObject:naviGsdk];
        [self setViewControllers:tabbarViewControllers];
    }
    
}

#pragma mark
#pragma mark --- 添加子控制器 ---
- (UIViewController *)addChildController:(UIViewController *)controller
                                   title:(NSString *)title
                             normalImage:(NSString *)normalImage
                           selectedImage:(NSString *)selectedImage
{
//    UIViewController *vc = [[NSClassFromString(controller) alloc] init];
    controller.tabBarItem.title = title;
    
    UIImage *normal = [UIImage imageNamed:normalImage];
    normal = [normal imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    controller.tabBarItem.image = normal;
    
    UIImage *selectImg = [UIImage imageNamed:selectedImage];
    selectImg = [selectImg imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    controller.tabBarItem.selectedImage = selectImg;
    
    GSDKDemoNavigation *navi = [[GSDKDemoNavigation alloc] initWithRootViewController:controller];
    //[self addChildViewController:navi];
    
    return navi;
}


-(void)dealloc{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

@end
