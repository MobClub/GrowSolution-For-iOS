//
//  GrowSDK.h
//  GrowSDK
//
//  Created by 陈剑东 on 2018/6/19.
//  Copyright © 2018年 陈剑东. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^GSDKBindAccountHandler) (NSString *mobUserId, NSError *error);

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

@end