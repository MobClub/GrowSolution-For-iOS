//
//  VLionNativeAdInformationFlowModel.h
//  VLionADSDKDemo
//
//  Created by 张旭 on 2017/10/12.
//  Copyright © 2017年 zhulin. All rights reserved.
//  信息流广告

#import <Foundation/Foundation.h>
#import "VLionNativeAdIconModel.h"
#import "VLionNativeAdNativeModel.h"

@interface VLionNativeAdInformationFlowModel : NSObject
@property (nonatomic ,assign) int             status;//状态码
@property (nonatomic ,assign) int             adt;//创意类型
@property (nonatomic ,copy) NSString * _Nullable      cid;//物料ID
@property (nonatomic ,strong) VLionNativeAdNativeModel* _Nullable   nativead;//原生
@property (nonatomic ,assign) int             tagid;//广告位id
@property (nonatomic ,strong) NSArray <NSString *>* _Nullable    imp_tracking;//曝光监测地址
@property (nonatomic ,strong) NSArray <NSString *>* _Nullable    dp_tracking;//deeplink曝光监测地址
@property (nonatomic ,strong) NSArray <NSString *>* _Nullable    clk_tracking;//点击监测地址
@property (nonatomic ,assign) int             interact_type;//点击行为0-网页,1-下载

+ (VLionNativeAdInformationFlowModel *_Nonnull)modelWithData:(NSDictionary *_Nullable)data;
@end
//{
//    adt = 3;
//    cid = "425_d";
//    "imp_tracking" =     (
//                          "http://a.vlion.cn/se?e=MTUwODE1MDU0MQkxNzEJNDI1CQkJczAxLjEwNzMxNTA4MTUwNTQxMjAzLm42M1l5VmJVanpWMi43UkpVSU5ZegkwCQkxCTAJCTE5NURFOTE2LUFEMjEtNDNCQi1BQkJFLUY2QzJCMTgzNzc1Nw==&t=425"
//                          );
//    nativead =     {
//        button = "\U70b9\U51fb";
//        desc = "\U9886\U5148\U7684\U5927\U6570\U636e\U6280\U672f\U670d\U52a1\U5546 \U6548\U679c\U8d4b\U80fd";
//        icon =         (
//                        {
//                            h = 300;
//                            url = "http://m.kejet.net/ms/tj/dsp/images/ssp/160128_300_300.jpg";
//                            w = 300;
//                        }
//                        );
//        img =         (
//                       {
//                           h = 1280;
//                           url = "http://m.kejet.net/ms/tj/dsp/images/ssp/160129_720_1280.jpg";
//                           w = 720;
//                       }
//                       );
//        ldp = "http://a.vlion.cn/sc?e=MTUwODE1MDU0MQkxNzEJNDI1CQkJczAxLjEwNzMxNTA4MTUwNTQxMjAzLm42M1l5VmJVanpWMi43UkpVSU5ZegkwCQkxCTAJCTE5NURFOTE2LUFEMjEtNDNCQi1BQkJFLUY2QzJCMTgzNzc1Nw==&t=425&f=0&g=aHR0cDovL3d3dy52bGlvbi5jbg==";
//        rating = 3;
//        title = "\U9886\U5148\U7684\U5927\U6570\U636e\U6280\U672f\U670d\U52a1\U5546";
//    };
//    status = 101;
//    tagid = 425;
//}

