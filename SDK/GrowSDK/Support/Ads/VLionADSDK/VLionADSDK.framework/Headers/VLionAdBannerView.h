//
//  VLionAdBannerView.h
//  VLionADSDKDemo
//
//  Created by iOS on 2017/10/11.
//  Copyright © 2017年 zhulin. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VLionWebBaseView.h"
#import "VLionAdConfiguration.h"

@interface VLionAdBannerView : VLionWebBaseView

- (void)timingChangedAdWithTagId:(NSString *)tagId
                             adt:(NSString *)adt
                   configuration:(VLionAdConfiguration *)configuration
                placeholderImage:(UIImage *)placeholderImage
                  viewController:(UIViewController *)viewController
                       superView:(UIView *)superView
                   completeBlock:(void(^)(UIView *bannerView, float width, float height))completeBlock
                    successBlock:(void(^)(void))successBlock
                     failedBlock:(void(^)(NSDictionary *errorDic))failedBlock
                      closeBlock:(void(^)(void))closeBlock
                    adClickBlock:(void(^)(void))adClickBlock
                     adBackBlock:(void(^)(void))adBackBlock;

/**
 *  销毁banner
 */
- (void)destroyBannerAdvertisement;

/**
 *  更新广告数据
 */
- (void)updateBannerSuccessBlock:(void(^)(void))successBlock
                     failedBlock:(void(^)(NSDictionary *errorDic))failedBlock;

@end
