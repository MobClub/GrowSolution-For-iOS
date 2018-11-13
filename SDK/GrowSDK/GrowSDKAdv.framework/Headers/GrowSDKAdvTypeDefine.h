//
//  GrowSDKAdvTypeDefine.h
//  GrowSDKAdv
//
//  Created by 陈剑东 on 2018/10/31.
//  Copyright © 2018年 陈剑东. All rights reserved.
//

#ifndef GrowSDKAdvTypeDefine_h
#define GrowSDKAdvTypeDefine_h

/**
 开屏广告回调
 
 @param error 错误
 */
typedef void(^LaunchAdHandler) (NSError *error);

/**
 Banner广告回调
 
 @param adView 广告视图
 @param error 错误
 */
typedef void(^AdViewHandler) (GSDKAdView *adView, NSError *error);

/**
 信息流广告回调
 
 @param objects 广告实体数组
 @param error 错误
 */
typedef void(^StreamHandler) (NSArray<GSDKAdStream *> *objects,  NSError *error);

/**
 插屏广告回调

 @param isReady 是否已加载好
 @param instView 插屏广告
 @param error 错误
 */
typedef void(^InstAdHandler) (BOOL isReady, GSDKInstAdView *instView, NSError *error);


/**
 广告类型枚举

 - GSDKAdvTypeBaidu: 百度
 */
typedef NS_ENUM(NSUInteger, GSDKAdvType) {
    GSDKAdvTypeBaidu = 1,
};


#endif /* GrowSDKAdvTypeDefine_h */
