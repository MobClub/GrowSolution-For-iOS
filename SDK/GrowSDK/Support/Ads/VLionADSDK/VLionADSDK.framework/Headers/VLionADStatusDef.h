//
//  VLionADStatusDef.h
//  VLionADSDKDemo
//
//  Created by 张旭 on 2017/10/17.
//  Copyright © 2017年 zhulin. All rights reserved.
//

#ifndef VLionADStatusDef_h
#define VLionADStatusDef_h

/**
 *  广告创意类型
 */
typedef NS_ENUM(NSUInteger, VLionAdErrorType) {
    
    VLionAdErrorTypeNull                = 102,    //无默认广告且无广告返回
    VLionAdErrorTypeTagIdInvalid        = 105,    //广告位id无效
};

/**
 *  原生广告类型
 */
typedef NS_ENUM(NSUInteger, NativeAdType) {
    NativeAdTypeInformationFlow       = 11,    //信息流
    NativeAdTypeShuffling             = 12,    //轮播图
    NativeAdTypeWaterfall             = 13,    //瀑布流
    NativeAdTypeNews                  = 14,    //新闻放送
    NativeAdTypeAppWall               = 15     //应用墙
};

/**
 *  状态码类型
 */
typedef NS_ENUM(NSUInteger, errorCode) {
    errorCode_SUCCESS                 = 0,//正常
    errorCode_NON_NETWORK             = 1,//网络异常
    errorCode_NON_AD                  = 2,//无广告
    errorCode_SHOW_INTERVAL_LIMITED   = 3,//频繁展示/操作
    errorCode_TAGID_INEFFECT          = 4 //广告位id无效
};

#endif /* VLionADStatusDef_h */
