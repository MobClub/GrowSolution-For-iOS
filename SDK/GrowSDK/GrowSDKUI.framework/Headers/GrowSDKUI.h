//
//  GrowSDKUI.h
//  GrowSDKUI
//
//  Created by 陈剑东 on 2018/7/11.
//  Copyright © 2018年 陈剑东. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, GSDKUIControllerShowType) {
    GSDKUIControllerShowTypePush = 1,    //Push跳转
    GSDKUIControllerShowTypePresent = 2  //模态跳转
};

@interface GrowSDKUI : NSObject

 /**
  推出视图动画类型
  */
@property (nonatomic) GSDKUIControllerShowType type;

/**
 获取单例对象
 
 @return 单例
 */
+ (GrowSDKUI *)defaultUI;

/**
 展示模块

 @param fromController 来源控制器
 */
- (void)showFrom:(UIViewController *)fromController result:(void (^)(NSError *error))result;


/**
 获取主控制器

 @return 主控制器
 */
- (UIViewController *)gsdkMainViewController:(void (^)(NSError *error))result;

@end
