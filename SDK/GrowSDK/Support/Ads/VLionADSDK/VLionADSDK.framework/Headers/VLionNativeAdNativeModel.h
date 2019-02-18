//
//  VLionNativeAdNativeModel.h
//  VLionADSDKDemo
//
//  Created by 张旭 on 2017/10/16.
//  Copyright © 2017年 zhulin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VLionNativeAdIconModel.h"

/**
 *  原生广告类型
 */
typedef NS_ENUM(NSUInteger, NativeType) {
    NativeTypeInformationFlow       = 11,    //信息流
    NativeTypeShuffling             = 12,    //轮播图
    NativeTypeWaterfall             = 13,    //瀑布流
    NativeTypeNews                  = 14,    //新闻放送
    NativeTypeAppWall               = 15     //应用墙
};

@interface VLionNativeAdNativeModel : NSObject
@property (nonatomic ,copy) NSString * _Nullable            ldp;//跳转url

@property (nonatomic ,strong) NSArray <VLionNativeAdIconModel *>* _Nullable            icon;//图标model
@property (nonatomic ,strong) NSArray <VLionNativeAdIconModel *>* _Nullable            img;//大图model
@property (nonatomic ,copy) NSString * _Nullable            title;//标题名称

@property (nonatomic ,copy) NSString * _Nullable            desc;//标题描述
@property (nonatomic ,assign) int             rating;//评定星级
@property (nonatomic ,copy) NSString * _Nullable            button;//按钮标题
@property (nonatomic ,assign) int            download_count;//下载次数
@property (nonatomic ,copy) NSString * _Nullable            app_download_url    ;//下载地址,和ldp二选一
@property (nonatomic ,copy) NSString * _Nullable      deeplink;//deeplink

+ (VLionNativeAdNativeModel *_Nonnull)modelWithData:(NSDictionary *_Nullable)data type:(NativeType)type;
@end
//信息流
//{
//    "title": "",
//    "ldp": "",
//    "icon": [
//             {
//                 "url": "",
//                 "w": "",
//                 "h": ""
//             }
//             ],
//    "desc": "",
//    "img": [
//            {
//                "url": "",
//                "w": "",
//                "h": ""
//            }
//            ],
//    "rating": "",
//    "button": "",
//    "download_count": ""
//}

//轮播图
//{
//    "title": "",
//    "ldp": "",
//    "img": [
//            {
//                "url": "",
//                "w": "",
//                "h": ""
//            }
//            ],
//    "desc": ""
//}

//瀑布流
//{
//    "title": "",
//    "ldp": "",
//    "img": [
//            {
//                "url": "",
//                "w": "",
//                "h": ""
//            }
//            ],
//    "desc": ""
//}

//新闻放送
//{
//    "title": "1",
//    "ldp": "",
//    "icon": [
//             {
//                 "url": "",
//                 "w": "",
//                 "h": ""
//             }
//             ],
//    "rating": ""
//}

//应用墙
//{
//    "title": "1",
//    "ldp": "",
//    "icon": [
//             {
//                 "url": "",
//                 "w": "",
//                 "h": ""
//             }
//             ],
//    "desc": "",
//    "rating": "",
//    "button": "",
//    "download_count": ""
//}

