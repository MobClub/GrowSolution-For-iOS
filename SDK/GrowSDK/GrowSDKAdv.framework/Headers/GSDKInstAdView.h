//
//  GSDKInstAdView.h
//  GrowSDKAdv
//
//  Created by 陈剑东 on 2018/10/29.
//  Copyright © 2018年 陈剑东. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface GSDKInstAdView : NSObject

@property (nonatomic) BOOL isReady;

- (void)showFromRootViewController:(UIViewController*)rootViewController;

@end
