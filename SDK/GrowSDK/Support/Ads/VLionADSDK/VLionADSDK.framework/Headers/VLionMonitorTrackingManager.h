//
//  VLionMonitorTrackingManager.h
//  VLionADSDKDemo
//
//  Created by 张旭 on 2017/10/13.
//  Copyright © 2017年 zhulin. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface VLionMonitorTrackingManager : NSObject

+ (VLionMonitorTrackingManager *_Nonnull)manager;

- (void)uploadTrackingUrls:(NSArray <NSString *>*_Nullable)trackingUrls;
@end

typedef void(^TrackingCompleteHandler)(NSURLResponse * _Nullable response, NSData * _Nullable data, NSError * _Nullable connectionError);

@interface VLionMonitorTrackingUpload : NSObject
- (void)initWithUrl:(NSString * _Nonnull)url queue:(NSOperationQueue *_Nonnull)queue completionHandler:(TrackingCompleteHandler _Nullable )completionHandler;

@end

