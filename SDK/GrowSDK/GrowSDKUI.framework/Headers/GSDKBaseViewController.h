//
//  GSDKBaseViewController.h
//  GrowSDKDemo
//
//  Created by Brilance on 2018/6/19.
//  Copyright © 2018年 陈剑东. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface GSDKBaseViewController : UIViewController

/**
 是否显示导航栏返回按钮
 */
@property (assign, nonatomic) BOOL showBackItem;

/**
 返回按钮点击事件设置
 */
@property (nonatomic, copy) void(^dismissHandler)(GSDKBaseViewController *);

@end
