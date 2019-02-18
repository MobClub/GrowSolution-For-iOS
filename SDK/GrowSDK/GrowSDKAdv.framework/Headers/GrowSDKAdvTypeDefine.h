//
//  GrowSDKAdvTypeDefine.h
//  GrowSDKAdv
//
//  Created by 陈剑东 on 2018/10/31.
//  Copyright © 2018年 陈剑东. All rights reserved.
//

#ifndef GrowSDKAdvTypeDefine_h
#define GrowSDKAdvTypeDefine_h
@class GSDKAdModel;

/**
 开屏广告回调
 
 @param error 错误
 */
typedef void(^GSDKAdLaunchAdHandler) (NSError *error);

/**
 Banner广告回调
 
 @param adView 广告视图
 @param error 错误
 */
typedef void(^GSDKBannerAdHandler) (UIView *adView, NSError *error);

/**
 信息流广告回调
 
 @param objects 广告实体数组
 @param error 错误
 */
typedef void(^GSDKAdStreamHandler) (NSArray<GSDKAdModel *> *objects,  NSError *error);

/**
 插屏广告回调

 @param error 错误
 */
typedef void(^GSDKInstAdHandler) (NSError *error);

/**
 广告点击回调
 */
typedef void(^GSDKAdClickHandler) (void);


/**
 广告类型枚举

 - GSDKAdvTypeBaidu: 百度
 */
typedef NS_ENUM(NSUInteger, GSDKAdvType) {
    GSDKAdvTypeBaidu = 1,
};

// 错误码定义域
#define GSDKADVErrorDomain @"GSDKErrorDomain"

#endif /* GrowSDKAdvTypeDefine_h */
