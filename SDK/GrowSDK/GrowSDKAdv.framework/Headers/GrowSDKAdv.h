//
//  GrowSDKAdv.h
//  GrowSDKAdv
//
//  Created by 陈剑东 on 2018/10/24.
//  Copyright © 2018年 陈剑东. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "GSDKAdModel.h"
#import "GrowSDKAdvTypeDefine.h"

@interface GrowSDKAdv : NSObject

/**
 获取开屏广告 【调用后将自动显示;建议在应用启动时 [application:didFinishLaunchingWithOptions:]中调用】
 
 @param result 回调
 */
+ (void)requestLaunchAd:(GSDKAdLaunchAdHandler)result;

/**
 获取插屏广告

 @param result 回调
 */
+ (void)requestInstAd:(GSDKInstAdHandler)result;

/**
 获取信息流广告

 @param result 回调
 */
+ (void)requestAdStream:(GSDKAdStreamHandler)result;

/**
 获取广告视图Banner 【建议广告视图比例默认宽高比为3:2】
 
 @param size 尺寸大小
 @param viewController 跳转控制器
 @param result 回调
 */
+ (void)requestBanner:(CGSize)size viewController:(UIViewController *)vc onClick:(GSDKAdClickHandler)clickHandler result:(GSDKBannerAdHandler)result;

@end
