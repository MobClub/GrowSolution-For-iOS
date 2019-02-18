//
//  VLionManager.h
//  VLionADSDKDemo
//
//  Created by iOS on 2017/10/9.
//  Copyright © 2017年 zhulin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VLionAdConfiguration.h"
#import "VLionADStatusDef.h"
#import "VLionNativeAdNewsModel.h"
#import "VLionNativeAdAppWallModel.h"
#import "VLionNativeAdShufflingModel.h"
#import "VLionNativeAdWaterfallModel.h"
#import "VLionNativeAdInformationFlowModel.h"

typedef void(^VLionNativeAdNewsHandler)(VLionNativeAdNewsModel *_Nullable adModel, NSDictionary * _Nullable errorDic);
typedef void(^VLionNativeAdAppWallHandler)(VLionNativeAdAppWallModel *_Nullable adModel, NSDictionary * _Nullable errorDic);
typedef void(^VLionNativeAdShufflingHandler)(VLionNativeAdShufflingModel *_Nullable adModel, NSDictionary * _Nullable errorDic);
typedef void(^VLionNativeAdWaterfallHandler)(VLionNativeAdWaterfallModel *_Nullable adModel, NSDictionary * _Nullable errorDic);
typedef void(^VLionNativeAdInformationFlowHandler)(VLionNativeAdInformationFlowModel *_Nullable adModel, NSDictionary * _Nullable errorDic);

@interface VLionManager : NSObject

@property (nonatomic, readonly) NSString *_Nonnull appId;

+ (VLionManager *_Nonnull)manager;

/**
 单例对象，建议后面都用此方法实例化，尤其swift，后面manager会取代掉。
 */
+ (VLionManager * _Nonnull)defaultManager;

/**
 根据AppId初始化广告SDK

 @param appId 瑞狮平台注册的AppId,不填将导致无法请求广告数据
              瑞狮平台地址:http://puma.vlion.cn
 */
- (void)initVLionSDKWithAppId:(NSString *_Nonnull)appId;

/**
 开屏广告
 
 @param tagId            广告位Id,由vlion提供,请到瑞狮SSP后台获取
 @param configuration    广告显示参数配置
 @param keyWindow        App的keyWindow
 @param placeholderImage 占位图 (最好是启动页图片)
 @param completeBlock    广告数据回调  window:SDK内部创建的广告位容器window,设置此window的大小可重新设置开屏广告的大小 w:广告物料的宽（单位px） h:广告物料的高（单位px）
 @param successBlock     加载成功回调
 @param failedBlock      失败回调,errorDic:错误信息
 @param finishBlock      开屏广告,未点击,读秒结束,完成回调(点击跳过)
 @param adClickBlock     点击广告回调
 @param adBackBlock      广告跳转web页后返回回调
 */
- (void)vl_setupLaunchAdWithTagId:(NSString *_Nonnull)tagId
                    configuration:(VLionAdConfiguration *_Nonnull)configuration
                        keyWindow:(UIWindow *_Nonnull)keyWindow
                 placeholderImage:(UIImage *_Nullable)placeholderImage
                    completeBlock:(void(^_Nullable)(CGFloat w,CGFloat h,UIWindow *_Nonnull window))completeBlock
                     successBlock:(void(^_Nullable)(void))successBlock
                      failedBlock:(void(^_Nullable)(NSDictionary *_Nullable errorDic))failedBlock
                      finishBlock:(void(^_Nullable)(void))finishBlock
                     adClickBlock:(void(^_Nullable)(void))adClickBlock
                      adBackBlock:(void(^_Nullable)(void))adBackBlock;

/**
 插屏广告

 @param tagId               广告位Id 由vlion提供。请到瑞狮SSP后台获取
 @param configuration       广告显示参数配置，可设置图片类广告view的填充模式
 @param superView           广告父视图（必传）
 @param placeholderImage    占位图（必传）
 @param viewController      当前控制器（必传），若不传，点击广告无法跳转
 @param completeBlock       广告数据请求成功回调   interstitialView:广告位容器 w:广告物料的宽（单位px） h:广告物料的高(单位px) closeBtnH:关闭按钮的高; 可根据返回物料宽高比重新设置容器的宽高，以免出现广告展示和容器比例不一致问题 注*重新设置广告位容器frame时，高度请加上关闭按钮的高，否则广告视图可能被拉伸
 @param successBlock        加载完成回调，建议在此回调中将广告容器添加到要展示的view上
 @param failedBlock         失败回调
 @param closeBlock          关闭按钮点击事件回调，建议在该回调中移除广告容器
 @param adClickBlock        点击广告
 @param adBackBlock         web类广告返回
 */
- (void)vl_interstitialWithTagId:(NSString *_Nonnull)tagId
                   configuration:(VLionAdConfiguration *_Nonnull)configuration
                       superView:(UIView *_Nonnull)superView
                placeholderImage:(UIImage *_Nonnull)placeholderImage
                  viewController:(UIViewController *_Nonnull)viewController
                   completeBlock:(void(^_Nullable)(UIView *_Nullable interstitialView, float w, float h, float closeBtnH ))completeBlock
                    successBlock:(void(^_Nullable)(void))successBlock
                     failedBlock:(void(^_Nullable)(NSDictionary *_Nullable errorDic))failedBlock
                      closeBlock:(void(^_Nullable)(void))closeBlock
                    adClickBlock:(void(^_Nullable)(void))adClickBlock
                     adBackBlock:(void(^_Nullable)(void))adBackBlock;

/**
 横幅广告

 @param tagId               广告位Id 由vlion提供。请到瑞狮SSP后台获取
 @param configuration       广告显示参数配置，可设置图片类广告view的填充模式
 @param superView           广告父视图（必传）
 @param placeholderImage    占位图（必传）
 @param viewController      当前控制器（必传），若不传，点击广告无法跳转
 @param completeBlock       广告数据请求成功回调  bannerView:广告位容器 w:广告物料的宽（单位px） h:广告物料的高（单位px）; 可根据返回物料宽高比重新设置容器的宽高，以免出现广告展示和容器比例不一致问题
 @param successBlock        加载完成回调，建议在此回调中将广告容器添加到要展示的view上
 @param failedBlock         失败回调
 @param adClickBlock        点击广告
 @param adBackBlock         web类广告返回
 */
- (void)vl_bannerWithTagId:(NSString *_Nonnull)tagId
             configuration:(VLionAdConfiguration *_Nonnull)configuration
                 superView:(UIView *_Nonnull)superView
          placeholderImage:(UIImage *_Nonnull)placeholderImage
            viewController:(UIViewController *_Nonnull)viewController
             completeBlock:(void(^_Nullable)(UIView *_Nullable bannerView, float w, float h))completeBlock
              successBlock:(void(^_Nullable)(void))successBlock
               failedBlock:(void(^_Nullable)(NSDictionary *_Nullable errorDic))failedBlock
              adClickBlock:(void(^_Nullable)(void))adClickBlock
               adBackBlock:(void(^_Nullable)(void))adBackBlock;


/**
 *  更新广告（横幅和插屏广告设置有效）
 @param superView           广告父视图（必传）
 @param successBlock        加载完成回调，建议在此回调中将广告容器添加到要展示的view上
 @param failedBlock         失败回调
 */
- (void)vl_updateBanner:(UIView *_Nonnull)superView
           successBlock:(void(^_Nullable)(void))successBlock
            failedBlock:(void(^_Nullable)(NSDictionary *_Nullable errorDic))failedBlock;

/**
 *  销毁并移除广告（仅对横幅和插屏广告设置有效）
 */
- (void)vl_destroyBannerOrInterstitialAdvertisement:(UIView *_Nonnull)superView;

/**
 激励广告
 
 @param tagId            广告位Id,由vlion提供,请到瑞狮SSP后台获取
 @param inViewController 当前控制器（必传），若不传，点击广告无法跳转
 @param completeBlock    广告数据回调
 @param successBlock     加载成功回调
 @param failedBlock      失败回调,errorDic:错误信息
 @param finishBlock      开屏广告,未点击,读秒结束,完成回调(点击跳过)
 @param adClickBlock     点击广告回调
 @param adBackBlock      广告跳转web页后返回回调
 */
- (void)vl_excitationAdWithTagId:(NSString *_Nonnull)tagId
                inViewController:(UIViewController *_Nonnull)viewController
                   completeBlock:(void(^_Nullable)(void))completeBlock
                    successBlock:(void(^_Nullable)(void))successBlock
                     failedBlock:(void(^_Nullable)(NSDictionary *_Nullable errorDic))failedBlock
                     finishBlock:(void(^_Nullable)(void))finishBlock
                      closeBlock:(void(^_Nullable)(void))closeBlock
                    adClickBlock:(void(^_Nullable)(void))adClickBlock
                     adBackBlock:(void(^_Nullable)(void))adBackBlock;

/**
 请求原生新闻类型广告模型数据

 @param tagId 广告位id
 @param handler 回调
 */
- (void)vl_nativeAdNewsWithTagId:(NSString *_Nonnull)tagId handler:(VLionNativeAdNewsHandler _Nullable)handler;

/**
 请求原生应用墙类型广告模型数据
 
 @param tagId 广告位id
 @param handler 回调
 */
- (void)vl_nativeAdAppWallWithTagId:(NSString *_Nonnull)tagId handler:(VLionNativeAdAppWallHandler _Nullable)handler;

/**
 请求原生轮播图类型广告模型数据
 
 @param tagId 广告位id
 @param handler 回调
 */
- (void)vl_nativeAdShufflingWithTagId:(NSString *_Nonnull)tagId handler:(VLionNativeAdShufflingHandler _Nullable)handler;

/**
 请求原生瀑布流类型广告模型数据
 
 @param tagId 广告位id
 @param handler 回调
 */
- (void)vl_nativeAdWaterfallWithTagId:(NSString *_Nonnull)tagId handler:(VLionNativeAdWaterfallHandler _Nullable)handler;

/**
 请求原生信息流类型广告模型数据
 
 @param tagId 广告位id
 @param handler 回调
 */
- (void)vl_nativeAdInformationFlowWithTagId:(NSString *_Nonnull)tagId handler:(VLionNativeAdInformationFlowHandler _Nullable)handler;


/**
 点击原生广告跳转

 @param model 原生模型
 @param upPoint 手势离开屏幕坐标(坐标原点为广告视图左上角)
 @param downPoint 手势接触屏幕坐标(坐标原点为广告视图左上角)
 @param viewController 跳转的控制器
  @param adBackBlock 返回回调
 */
- (void)clickNativedAdWithModel:(id _Nonnull)model upPoint:(CGPoint)upPoint downPoint:(CGPoint)downPoint viewController:(UIViewController *_Nonnull)viewController adBackBlock:(void (^_Nullable)(void))adBackBlock;

#pragma mark - 缓存清除及大小
/**
 *  清除VLionAd本地缓存(图片,gif,视频)
 */
+(void)clearDiskCache;

/**
 *  获取VLionAd本地缓存大小(M)
 */
+(float)diskCacheSize;

/**
 *  缓存路径
 */
+(NSString *_Nullable)vlAdCachePath;

+ (NSString *_Nullable)getVLionSDKVersion;

@end

