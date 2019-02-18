//
//  GrowSDKUI.h
//  GrowSDKUI
//
//  Created by 陈剑东 on 2018/7/11.
//  Copyright © 2018年 陈剑东. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GSDKBaseViewController.h"

typedef NS_ENUM(NSUInteger, GSDKUIControllerShowType) {
    GSDKUIControllerShowTypePush = 1,    //Push跳转
    GSDKUIControllerShowTypePresent = 2  //模态跳转
};

@interface GrowSDKUI : NSObject

/**
 资讯界面显示任务信息,默认为YES
 */
@property (assign, nonatomic) BOOL enableTaskInfo;

/**
 获取单例对象
 
 @return 单例
 */
+ (GrowSDKUI *)defaultUI;

/**
 获取图文资讯控制器(需要导航栏控制器)

 @return 主控制器
 */
- (GSDKBaseViewController *)gsdkMainViewController:(void (^)(NSError *error))result;

/**
 获取视频资讯控制器
 
 @return 主控制器（需要导航栏控制器）
 */
- (GSDKBaseViewController *)gsdkVideoInfosController:(void (^)(NSError *error))result;

/**
 获取任务系统的控制器
 
 @return 用户控制器
 */
- (GSDKBaseViewController *)gsdkUserInfoController:(void (^)(NSError *error))result;


#pragma mark - Deprecated

@property (nonatomic) GSDKUIControllerShowType type __deprecated_msg("Discard form v1.3.0");

- (void)showFrom:(UIViewController *)fromController result:(void (^)(NSError *error))result __deprecated_msg("Discard form v1.3.0");

@end
