//
//  GSDKTaskInfo.h
//  GrowSDK
//
//  Created by 陈剑东 on 2018/7/2.
//  Copyright © 2018年 陈剑东. All rights reserved.
//

#import <MOBFoundation/MOBFDataModel.h>


/**
 当日签到任务信息
 */
@interface GSDKTaskInfo : MOBFDataModel

/**
 当日是否签到
 */
@property (nonatomic) BOOL isSignToday;

/**
 累计签到时间 (值为 1 - 7)
 */
@property (nonatomic) NSInteger signCount;

@end
