//
//  VLionNativeAdNewsModel.h
//  VLionADSDKDemo
//
//  Created by 张旭 on 2017/10/12.
//  Copyright © 2017年 zhulin. All rights reserved.
//  新闻大放送广告

#import <Foundation/Foundation.h>
#import "VLionNativeAdIconModel.h"
#import "VLionNativeAdNativeModel.h"

@interface VLionNativeAdNewsModel : NSObject

@property (nonatomic ,assign) int             status;//状态码
@property (nonatomic ,assign) int             adt;//创意类型
@property (nonatomic ,copy) NSString * _Nullable      cid;//物料ID
@property (nonatomic ,strong) VLionNativeAdNativeModel* _Nullable   nativead;//原生
@property (nonatomic ,assign) int             tagid;//广告位id
@property (nonatomic ,strong) NSArray <NSString *>* _Nullable    imp_tracking;//曝光监测地址
@property (nonatomic ,strong) NSArray <NSString *>* _Nullable    dp_tracking;//deeplink曝光监测地址
@property (nonatomic ,strong) NSArray <NSString *>* _Nullable    clk_tracking;//点击监测地址
@property (nonatomic ,assign) int             interact_type;//点击行为0-网页,1-下载

+ (VLionNativeAdNewsModel *_Nonnull)modelWithData:(NSDictionary *_Nullable)data;
@end

