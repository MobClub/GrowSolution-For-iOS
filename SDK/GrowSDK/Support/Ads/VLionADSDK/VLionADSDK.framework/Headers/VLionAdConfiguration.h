//
//  ADLaunchConfiguration.h
//  VLionADSDKDemo
//
//  Created by cnliveJunBo on 17/10/10.
//  Copyright © 2017年 zhulin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>

/** 显示完成动画时间默认时间 */
static CGFloat const showFinishAnimateTimeDefault = 0.8;

/** 显示完成动画类型 */
typedef NS_ENUM(NSInteger , ShowFinishAnimate) {
    
    /** 无动画 */
    ShowFinishAnimateNone = 1,
    
    /** 普通淡入(default) */
    ShowFinishAnimateFadein = 2,
    
    /** 放大淡入 */
    ShowFinishAnimateLite = 3,
    
    /** 左右翻转(类似网易云音乐) */
    ShowFinishAnimateFlipFromLeft = 4,
    
    /** 下上翻转 */
    ShowFinishAnimateFlipFromBottom = 5,
    
    /** 向上翻页 */
    ShowFinishAnimateCurlUp = 6,
};

typedef NS_ENUM(NSUInteger, AdSkipButtonType) {
    AdSkipButtonTypeNone            = 1,    //无
    AdSkipButtonTypeTime            = 2,    //倒计时
    AdSkipButtonTypeText            = 3,    //跳过
    AdSkipButtonTypeTimeAndText     = 4     //倒计时 + 跳过
};

typedef NS_ENUM(NSUInteger, WebAdContentMode) {
    WebAdContentModeFill,           //填充
    WebAdContentModeFit,            //自适应
};

@interface VLionAdConfiguration : NSObject

+ (VLionAdConfiguration *)defaultConfiguration;

#pragma mark - 公共属性

/**
 *  跳过按钮类型(default SkipTypeTimeText) (仅开屏广告设置有效)
 */
@property(nonatomic,assign)AdSkipButtonType skipButtonType;

/**
 *  显示完成动画(default ShowFinishAnimateFadein) (仅开屏广告设置有效)
 */
@property(nonatomic,assign)ShowFinishAnimate showFinishAnimate;

/**
 *  显示完成动画时间(default 0.8 , 单位:秒) (仅开屏广告设置有效)
 */
@property(nonatomic,assign)CGFloat showFinishAnimateTime;

/**
 *  设置广告的frame(开屏 :default [UIScreen mainScreen].bounds)
 */
@property (nonatomic,assign) CGRect frame;

/**
 设置GIF动图是否只循环播放一次 (仅对动图设置有效)
 */
@property (nonatomic, assign) BOOL GIFImageCycleOnce;

#pragma mark - Web广告相关
/**
 *  web广告缩放模式(default WebAdContentModeFill) (仅对web广告设置有效)
 */
@property(nonatomic,assign)WebAdContentMode webContentMode;

#pragma mark - 图片广告相关
/**
 *  图片广告缩放模式(default UIViewContentModeScaleToFill) (仅对图片广告设置有效)
 */
@property(nonatomic,assign)UIViewContentMode contentMode;

#pragma mark - 视频广告相关
/**
 *  视频缩放模式(default MPMovieScalingModeAspectFill) (仅对视频广告设置有效)
 */
@property(nonatomic,assign)MPMovieScalingMode scalingMode;


#pragma mark - 广告切换动画（以下接口仅横幅广告和插屏广告设置有效）

/**
 *  动画样式（默认 kCATransitionFade），详见transition types
 */
@property (nonatomic, strong) NSString *aniType;

/**
 *  默认 kCATransitionFromRight，详见transition subtypes
 */
@property (nonatomic, strong) NSString *aniSubtype;

/**
 *  动画时长（默认 0.4）
 */
@property (nonatomic, assign) float duration;

@end
