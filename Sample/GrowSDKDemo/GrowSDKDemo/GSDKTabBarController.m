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
    
    [GrowSDKUI defaultUI].enableTaskInfo = YES;
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(reloadTabbarVC) name:@"BindingSuccess" object:nil];
    
    NSMutableArray *vcs = @[].mutableCopy;
    
    void(^dismissHandler)(UIViewController *) = ^(UIViewController *controller){
        
        [self.presentingViewController dismissViewControllerAnimated:YES completion:nil];
    };
    
    GSDKBaseViewController *gsdkVC = [[GrowSDKUI defaultUI] gsdkMainViewController:nil];
    gsdkVC.dismissHandler = dismissHandler;
    if (gsdkVC)
    {
        UIViewController *naviGsdk = [self addChildController:gsdkVC title:@"图文" normalImage:@"tab1a" selectedImage:@"tab1b"];
        [vcs addObject:naviGsdk];
    }
    
    GSDKBaseViewController *videoVC = [[GrowSDKUI defaultUI] gsdkVideoInfosController:nil];
    videoVC.dismissHandler = dismissHandler;
    if (videoVC)
    {
        UIViewController *naviGsdk = [self addChildController:videoVC title:@"视频" normalImage:@"tab2a" selectedImage:@"tab2b"];
        [vcs addObject:naviGsdk];
    }
    
    GSDKBaseViewController *userVC = [[GrowSDKUI defaultUI] gsdkUserInfoController:nil];
    userVC.dismissHandler = dismissHandler;
    if (userVC)
    {
        UIViewController *naviGsdk = [self addChildController:userVC title:@"我的" normalImage:@"tab3a" selectedImage:@"tab3b"];
        [vcs addObject:naviGsdk];
    }
    
    [self setViewControllers:vcs];
    
}

//用户绑定后刷新tab
- (void)reloadTabbarVC
{
//    NSMutableArray *tabbarViewControllers = [self.viewControllers mutableCopy];
//    if (tabbarViewControllers.count > 1) {
//        [tabbarViewControllers removeObjectAtIndex:1];
//    }
//
//    UIViewController * gsdkVC = [[GrowSDKUI defaultUI] gsdkMainViewController:^(NSError *error) {
//
//    }];
//    if (gsdkVC) {
//        UIViewController *naviGsdk = [self addChildController:gsdkVC title:@"图文" normalImage:@"tab1a" selectedImage:@"tab1b"];
//        [tabbarViewControllers addObject:naviGsdk];
//
////        UIViewController *naviGsdk_1 = [self addChildController:gsdkVC title:@"test" normalImage:@"tab2a" selectedImage:@"tab2b"];
////        [tabbarViewControllers addObject:naviGsdk_1];
//
//
//        [self setViewControllers:tabbarViewControllers];
//    }
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
