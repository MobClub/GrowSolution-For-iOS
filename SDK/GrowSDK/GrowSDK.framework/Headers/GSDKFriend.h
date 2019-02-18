//
//  GSDKFriend.h
//  GrowSDK
//
//  Created by 陈剑东 on 2018/6/26.
//  Copyright © 2018年 陈剑东. All rights reserved.
//

#import <MOBFoundation/MOBFDataModel.h>

@interface GSDKFriend : MOBFDataModel

/**
 用户Id
 */
@property (nonatomic, copy) NSString *userId;

/**
 昵称
 */
@property (nonatomic, copy) NSString *userName;

/**
 头像
 */
@property (nonatomic, copy) NSString *avatar;

/**
 时间
 */
@property (nonatomic, copy) NSString *time;

/**
 当前收益
 */
@property (nonatomic) NSInteger income;

/**
 预期收益
 */
@property (nonatomic) NSInteger except;

@end
