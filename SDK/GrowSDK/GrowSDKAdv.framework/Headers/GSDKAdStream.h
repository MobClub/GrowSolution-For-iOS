//
//  GSDKAdStream.h
//  GrowSDKAdv
//
//  Created by 陈剑东 on 2018/10/29.
//  Copyright © 2018年 陈剑东. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface GSDKAdStream : NSObject

@property (nonatomic, copy, readonly) NSString *title;

@property (nonatomic, copy, readonly) NSString *imageUrl;

- (void)handleClick:(UIView *)view;

@end
