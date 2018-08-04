//
//  MSCCommand.h
//  MSC
//
//  Created by 冯鸿杰 on 2017/10/9.
//  Copyright © 2017年 Mob. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MSCConnection;
@class MSCCommand;

/**
 命令委托
 */
@protocol MSCCommandDelegate<NSObject>

@optional

/**
 查询命令返回

 @param command 命令对象
 @param recordset 记录集
 @param error 错误信息
 */
- (void)queryCommandDidResult:(MSCCommand *)command
                    recordset:(NSArray<NSDictionary<NSString *, id> *> *)recordset
                        error:(NSError *)error;

/**
 插入命令返回

 @param command 命令对象
 @param objectId 新对象标识
 @param error 错误信息
 */
- (void)insertCommandDidResult:(MSCCommand *)command
                      objectId:(NSString *)objectId
                         error:(NSError *)error;


/**
 更新命令返回

 @param command 命令对象
 @param error 错误信息
 */
- (void)updateCommandDidResult:(MSCCommand *)command
                         error:(NSError *)error;

/**
 删除命令返回
 
 @param command 命令对象
 @param error 错误信息
 */
- (void)deleteCommandDidResult:(MSCCommand *)command
                         error:(NSError *)error;

@end

/**
 每条CQL为一个Command对象，该类型为CQL的载体
 */
@interface MSCCommand : NSObject

/**
 委托对象
 */
@property (nonatomic, weak) id<MSCCommandDelegate> delegate;

/**
 自定义数据
 */
@property (nonatomic, strong) id userdata;

/**
 CQL脚本内容
 */
@property (nonatomic, copy, readonly) NSString *text;

/**
 连接器对象
 */
@property (nonatomic, weak, readonly) MSCConnection *connection;

/**
 初始化命令对象

 @param queryText 查询的CQL脚本内容
 @return 命令对象
 */
- (instancetype)initWithQueryText:(NSString *)queryText;

/**
 初始化命令对象

 @param queryText 查询的CQL脚本内容
 @param connection 连接器对象
 @return 命令对象
 */
- (instancetype)initWithQueryText:(NSString *)queryText
                       connection:(MSCConnection *)connection;

/**
 初始化命令对象

 @param insertText 插入的CQL脚本内容
 @return 命令对象
 */
- (instancetype)initWithInsertText:(NSString *)insertText;

/**
 初始化命令对象

 @param insertText 插入的CQL脚本内容
 @param connection 连接器对象
 @return 命令对象
 */
- (instancetype)initWithInsertText:(NSString *)insertText
                        connection:(MSCConnection *)connection;


/**
 初始化命令对象

 @param updateText 更新的CQL脚本内容
 @return 命令对象
 */
- (instancetype)initWithUpdateText:(NSString *)updateText;

/**
 初始化命令对象

 @param updateText 更新的CQL脚本内容
 @param connection 连接器对象
 @return 命令对象
 */
- (instancetype)initWithUpdateText:(NSString *)updateText
                        connection:(MSCConnection *)connection;

/**
 初始化命令对象

 @param deleteText 删除的CQL脚本内容
 @return 命令对象
 */
- (instancetype)initWithDeleteText:(NSString *)deleteText;

/**
 初始化命令对象

 @param deleteText 删除的CQL脚本内容
 @param connection 连接器对象
 @return 命令对象
 */
- (instancetype)initWithDeleteText:(NSString *)deleteText
                        connection:(MSCConnection *)connection;

/**
 执行命令
 */
- (void)execute;

@end
