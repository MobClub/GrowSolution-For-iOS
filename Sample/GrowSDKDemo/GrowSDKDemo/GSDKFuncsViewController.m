//
//  GSDKFuncsViewController.m
//  GrowSDKDemo
//
//  Created by Max on 2019/1/28.
//  Copyright © 2019 陈剑东. All rights reserved.
//

#import "GSDKFuncsViewController.h"
#import <GrowSDK/GrowSDK.h>
#import <GrowSDKUI/GrowSDKUI.h>
#import <GrowSDKAdv/GrowSDKAdv.h>

#define GSDKAlert(_S_, ...)     [[[UIAlertView alloc] initWithTitle:nil message:[NSString stringWithFormat:(_S_), ##__VA_ARGS__] delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:nil] show]

@interface GSDKFuncsViewController ()
{
    NSArray *_funNames;
}

@end

@implementation GSDKFuncsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.edgesForExtendedLayout = UIRectEdgeNone;
    self.title = @"功能列表";
    
    _funNames = @[@"绑定",@"展示图文资讯",@"展示视频资讯",@"展示我的",@"展示插屏广告",@"展示信息流广告",@"展示视图广告",@"获取签到信息",@"签到",@"获取邀请码",@"提交邀请码",@"获取我邀请的好友列表"];
    
    //控制任务信息视图的开启和关闭
    [GrowSDKUI defaultUI].enableTaskInfo = NO;
}

#pragma mark - Table view data source


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    return _funNames.count;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"123"];
 
    cell.textLabel.text = _funNames[indexPath.row];
 
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];

    switch (indexPath.row)
    {
        case 0:
            [self _bind];
            break;
        case 1:
            [self _showPT];
            break;
        case 2:
            [self _showVideo];
            break;
        case 3:
            [self _showMe];
            break;
        case 4:
            [self _showInstAd];
            break;
        case 5:
            [self _showStreamAds];
            break;
        case 6:
            [self _showAdView];
            break;
        case 7:
            [self _getSignInfo];
            break;
        case 8:
            [self _signIn];
            break;
        case 9:
            [self _getInviteCode];
            break;
        case 10:
            [self _commitInviteCode];
            break;
        case 11:
            [self _getInviteFriends];
            break;
            
        default:
            break;
    }
}

- (void)_showMe
{
    GSDKBaseViewController *vc = [[GrowSDKUI defaultUI] gsdkUserInfoController:^(NSError *error) {
        
        if (error)
        {
            GSDKAlert(@"%@",error);
        }
    }];
    
    if (vc)
    {
        vc.dismissHandler = ^(GSDKBaseViewController *vc) {
            
            [self.navigationController popViewControllerAnimated:YES];
        };
        
        [self.navigationController pushViewController:vc animated:YES];
    }
}

- (void)_bind
{
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"绑定账号"
                                                                             message:@"在下面填入需要绑定的用户id"
                                                                      preferredStyle:UIAlertControllerStyleAlert];
    
    [alertController addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
        textField.placeholder = @"userid";
    }];
    
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        GSDKAlert(@"已取消");
    }];
    
    UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"绑定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        UITextField *textfield = alertController.textFields.firstObject;
        
        NSString *userid = textfield.text;
        
        [GrowSDK bindingAcount:userid
                      nickName:@"我是昵称"
                        avatar:@"https://tvax1.sinaimg.cn/crop.0.0.1242.1242.300/6f030d46ly8fs9lmws1onj20yi0yiwhg.jpg"
                        result:^(NSString *mobUserId, NSError *error) {
                            
                            NSString *mes;
                            
                            if (error)
                            {
                                mes = [NSString stringWithFormat:@"绑定失败：%@",error];
                            }
                            else
                            {
                                mes = @"绑定成功";
                            }
                            
                            GSDKAlert(@"%@",mes);
                        }];
    }];
    
    [alertController addAction:cancelAction];
    [alertController addAction:confirmAction];
    
    [self.navigationController presentViewController:alertController animated:YES completion:nil];
}

- (void)_showPT
{
    GSDKBaseViewController *vc = [[GrowSDKUI defaultUI] gsdkMainViewController:^(NSError *error) {
        
        if (error)
        {
            GSDKAlert(@"%@",error);
        }
    }];
    
    if (vc)
    {
        vc.dismissHandler = ^(GSDKBaseViewController *vc) {
            
            [self.navigationController popViewControllerAnimated:YES];
        };
        
        [self.navigationController pushViewController:vc animated:YES];
    }
}

- (void)_showVideo
{
    GSDKBaseViewController *vc = [[GrowSDKUI defaultUI] gsdkVideoInfosController:^(NSError *error) {
        
        if (error)
        {
            GSDKAlert(@"%@",error);
        }
    }];
    
    if (vc)
    {
        vc.dismissHandler = ^(GSDKBaseViewController *vc) {
            
            [self.navigationController popViewControllerAnimated:YES];
        };
        
        [self.navigationController pushViewController:vc animated:YES];
    }
}

- (void)_showInstAd
{
    [GrowSDKAdv requestInstAd:^(NSError *error) {
        
        if (error)
        {
            GSDKAlert(@"inst error:%@", error);
        }
    }];
}

- (void)_showStreamAds
{
    [GrowSDKAdv requestAdStream:^(NSArray<GSDKAdModel *> *objects, NSError *error) {
        
        if (!error)
        {
            [objects enumerateObjectsUsingBlock:^(GSDKAdModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {

                NSString *news = [NSString stringWithFormat:@"广告总数:%lu \n 下标:%ld \n title:%@ \n imgUrl:%@",(unsigned long)objects.count, idx,obj.title,obj.mainImageURLString];
                 
                GSDKAlert(@"%@",news);
            }];
        }
        else
        {
            GSDKAlert(@"%@",error);
        }
    }];
}

#define ADCOMPVIEW_SIZE_320x50        CGSizeMake(320, 50)
#define ADCOMPVIEW_SIZE_480x44        CGSizeMake(480, 44)
#define ADCOMPVIEW_SIZE_300x250       CGSizeMake(300, 250)
#define ADCOMPVIEW_SIZE_480x60        CGSizeMake(480, 60)
#define ADCOMPVIEW_SIZE_728x90        CGSizeMake(728, 90)

- (void)_showAdView
{
    //建议宽高比为 3：2
    
    [GrowSDKAdv requestBanner:ADCOMPVIEW_SIZE_320x50 viewController:self  onClick:nil result:^(UIView *adView, NSError *error) {
        
        if (!error)
        {
            [self.view addSubview:adView];
            
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(10 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                [adView removeFromSuperview];
            });
        }
    }];
}

- (void)_getSignInfo
{
    [GrowSDK getTaskInfo:^(GSDKTaskInfo *taskInfo, NSError *error) {
        
        if (!error)
        {
            GSDKAlert(@":今天是否签到:%d - 累计签到:%ld",taskInfo.isSignToday,(long)taskInfo.signCount);
        }
        else
        {
            GSDKAlert(@"获取失败，原因:%@",error.userInfo[@"error"]);
        }
    }];
}

- (void)_signIn
{
    [GrowSDK signInToday:^(NSInteger coins, NSError *error) {
        
        if (!error)
        {
            GSDKAlert(@"签到成功，获得金币:%ld",coins);
        }
        else
        {
            GSDKAlert(@"签到失败，原因:%@",error.userInfo[@"error"]);
        }
    }];
}

- (void)_getInviteCode
{
    [GrowSDK getInviteCodeForCurrentUser:^(NSString *code, NSError *error) {
        
        if (error)
        {
            GSDKAlert(@"错误L：%@",error);
        }
        else
        {
            GSDKAlert(@"邀请码：%@",code);
        }
    }];
}

- (void)_commitInviteCode
{
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"提交邀请码"
                                                                             message:@"在下面填入好友邀请时发给你的邀请码"
                                                                      preferredStyle:UIAlertControllerStyleAlert];
    
    [alertController addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
        textField.placeholder = @"邀请码";
    }];
    
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        GSDKAlert(@"已取消");
    }];
    
    UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"提交" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        UITextField *textfield = alertController.textFields.firstObject;
        
        NSString *invitedCode = textfield.text;
        
        [GrowSDK inputInviteCode:invitedCode result:^(NSError *error) {
            
            if (!error)
            {
                GSDKAlert(@"提交成功");
            }
            else
            {
                GSDKAlert(@"失败：%@",error);
            }
        }];
    }];
    
    [alertController addAction:cancelAction];
    [alertController addAction:confirmAction];
    
    [self.navigationController presentViewController:alertController animated:YES completion:nil];
}

- (void)_getInviteFriends
{
    [GrowSDK getFriendList:0 pageSize:50 result:^(NSArray<GSDKFriend *> *friendList, NSError *error) {
        
        if (error)
        {
            GSDKAlert(@"错误：%@",error);
        }
        else
        {
            NSMutableArray *m = @[].mutableCopy;
            
            for (GSDKFriend *obj in friendList) {
                [m addObject:obj.userName?:@""];
            }
            
            GSDKAlert(@"用户userNames：%@",m);
        }
    }];
}

@end
