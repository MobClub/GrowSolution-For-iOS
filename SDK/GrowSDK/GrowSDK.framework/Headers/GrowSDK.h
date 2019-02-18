//
//  GrowSDK.h
//  GrowSDK
//
//  Created by 陈剑东 on 2018/6/19.
//  Copyright © 2018年 陈剑东. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GSDKTaskInfo.h"
#import "GSDKFriend.h"

typedef void(^GSDKBindAccountHandler) (NSString *mobUserId, NSError *error);
typedef void(^GSDKTaskInfoHandler) (GSDKTaskInfo *taskInfo, NSError *error);
typedef void(^GSDKSignHandler) (NSInteger coins, NSError *error);
typedef void(^GSDKFriendListHandler) (NSArray<GSDKFriend *> *friendList, NSError *error);

@interface GrowSDK : NSObject

#pragma mark - 用户系统

/**
 绑定第三方用户id 【调用下列所有接口前,必须要首先调用此接口绑定用户系统】

 @param userId 第三方用户id
 @param nickName 第三方用户昵称
 @param avatar 第三方用户头像地址
 @param result 回调
 */
+ (void)bindingAcount:(NSString *)userId
             nickName:(NSString *)nickName
               avatar:(NSString *)avatar
               result:(GSDKBindAccountHandler)result;


#pragma mark - 签到系统

/**
 获取当日签到任务信息
 
 @param result 回调
 */
+ (void)getTaskInfo:(GSDKTaskInfoHandler)result;

/**
 进行签到
 
 @param result 回调
 */
+ (void)signInToday:(GSDKSignHandler)result;


#pragma mark - 好友邀请

/**
 获取当前用户邀请码

 @param result 回调
 */
+ (void)getInviteCodeForCurrentUser:(void(^)(NSString *, NSError *))result;

/**
 输入邀请码
 
 @param referCode 邀请码
 @param result 回调
 */
+ (void)inputInviteCode:(NSString *)referCode result:(void(^)(NSError *))result;

/**
 获取好友列表
 
 @param pageIndex 页码 【从 0 开始】
 @param pageSize 单页数量
 @param result 回调结果
 */
+ (void)getFriendList:(NSInteger)pageIndex pageSize:(NSInteger)pageSize result:(GSDKFriendListHandler)result;

@end
