//
//  GSDKDemoNavigation.m
//  GrowSDKDemo
//
//  Created by Brilance on 2018/7/11.
//  Copyright © 2018年 陈剑东. All rights reserved.
//

#import "GSDKDemoNavigation.h"

@interface GSDKDemoNavigation () <UINavigationControllerDelegate,UIGestureRecognizerDelegate>

@end

@implementation GSDKDemoNavigation

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.delegate = self;
    self.interactivePopGestureRecognizer.delegate = self;
}

- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated {
    
    [self.view endEditing:YES];
    [super pushViewController:viewController animated:animated];
    
}


#pragma mark --UINavigationControllerDelegate--
- (void)navigationController:(UINavigationController *)navigationController
       didShowViewController:(UIViewController *)viewController
                    animated:(BOOL)animated
{
    self.interactivePopGestureRecognizer.enabled = YES;
}

//是否可以侧滑
- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gestureRecognizer
{
    if (self.viewControllers.count == 1 && [gestureRecognizer isKindOfClass:[UIScreenEdgePanGestureRecognizer class]])
        
        return NO;
    
    return YES;
    
}

@end
