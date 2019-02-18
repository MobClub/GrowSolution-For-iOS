//
//  GSDKAdObject.h
//  GrowSDKAdv
//
//  Created by Max on 2019/1/30.
//  Copyright © 2019 陈剑东. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MOBFoundation/MOBFDataModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSDKAdModel : MOBFDataModel

/**
 广告id
 */
@property (nonatomic, copy) NSString *cid;

/**
 * 标题 text
 */
@property (copy, nonatomic)  NSString *title;
/**
 * 描述 text
 */
@property (copy, nonatomic)  NSString *text;

/**
 * 小图 url
 */
@property (copy, nonatomic) NSString *iconImageURLString;
/**
 * 大图 url
 */
@property (copy, nonatomic) NSString *mainImageURLString;

/**
 * 广告标识图标 url
 */
@property (copy, nonatomic) NSString *adLogoURLString;

/**
 * 广告跳转 url
 */
@property (nonatomic, copy) NSString *url;

/**
 广告时长
 */
@property (assign, nonatomic) NSInteger duration;

/**
 处理点击
 */
- (void)handleClick:(UIView *)view WithViewController:(UIViewController *)vc;

@end

NS_ASSUME_NONNULL_END
