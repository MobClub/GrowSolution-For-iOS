# GrowSolution-For-iOS(增长变现解决方案)
### 增长变现解决方案通过阅读、签到、分享等方式积攒金币兑换零钱，并支持提现。使用本方案能够为App带来用户的拉新及持续活跃。简单接近无成本的集成，除了带来用户增量及活跃，也给开发者提供额外的收入的途径。
**当前的版本**

- iOS v1.0.0

**官网文档**
[增长变现解决方案快速集成文档](http://wiki.mob.com/ios-growsdk/)

- - - - - - - - - - - -

### 一、获取AppKey,AppSecret

##### 1.打开Mob官网，在官网选择登录或注册，新用户先注册，老用户直接登录。

![x1](https://lh3.googleusercontent.com/-hMUXeh5t45E/W02Ut6PWr6I/AAAAAAAABso/4z10PBem4GUIxMcUVWU3M1vzo3WbVBW-wCHMYCw/I/x1.png)

注册页面如下图:
![x2](https://lh3.googleusercontent.com/-N74F51ogtMM/W02VUZE28CI/AAAAAAAABsw/H05JMy8n0z0_lvS0NBA-DWhbMKcPpN8rwCHMYCw/I/x2.png)


##### 2.注册或登录完成后，会返回首页，选择导航栏,找到"变现增长解决方案"并点击进入。随后将进入增长变现解决方案应用后台,选择创建应用,如下图：

![](https://lh3.googleusercontent.com/-bzRuib5v9J4/W2VKcFI7zHI/AAAAAAAABtM/WIOyZ2yLoIooVCtgi0YciIvDGIWpdBcagCHMYCw/I/x3.png)

填入基本资料
![](https://lh3.googleusercontent.com/-0EhW9DAJMy8/W2VKcivU-RI/AAAAAAAABtc/uCKzSnoEYbg6eX18uZRViXwyLl8wq1PIQCHMYCw/I/x3-1.png)

完成创建后,点击进入应用,进入'设置',即可得到App Key和App Secret;
![](https://lh3.googleusercontent.com/-8c_Vaccdk-Q/W2VKcg9dFJI/AAAAAAAABtY/V43n0K6t_8QiWB1VDJhvNMh91ApT2YpmgCHMYCw/I/X3-2.png)

##### 3.从上述步骤申请并获取所得的AppKey, AppSecret,请在项目的Info.plist中分别添加’MOBAppKey’, ‘MOBAppSecret’此两字段并分别对应填入,如图
![](https://lh3.googleusercontent.com/-NZr5PI7PM6I/W2VKciKXLTI/AAAAAAAABts/taEo0WbJQrIfDpTJwJEnJ86mBnfF_F_NwCHMYCw/I/x4.png)

##### 4.应用后台填入所需要使用的社交平台的配置信息,最多支持新浪微博,微信及QQ。
进入您的应用,设置 - 分享配置,填入需要的社交平台信息
![](https://lh3.googleusercontent.com/-mvjniAKcwBw/W2VKcn_ZUxI/AAAAAAAABtg/qhY-FuAVi8MJCm7plKo0gYOyBKs90cpWACHMYCw/I/x4-1.png)

##### 并注意在Xcode项目的Info.plist进行相关的配置:
**URLScheme:**
* 新浪微博:```wb+appkey```
* QQ:```tencent+appid/QQ+appid(appid转换成八位16进制数)```
* 微信:```微信的appid```

**白名单LSApplicationQueriesSchemes:**
可参考[iOS9+系统适配](http://wiki.mob.com/%E9%80%82%E9%85%8Dios-9%EF%BC%8B%E7%B3%BB%E7%BB%9F/)中第三大点,也可参考demo,如图:
![](https://lh3.googleusercontent.com/-SrhZLSt6pzk/W2VKdDAbWII/AAAAAAAABto/tPZBk08p5kYqKC6OpK8i4UDBHWeqEkL0wCHMYCw/I/x6.jpg)

**App Transport Security Settings**
设置ATS
![](https://lh3.googleusercontent.com/-87mXoBxl518/W2VKcJR40KI/AAAAAAAABtU/CnQzKnmhZ74dk3IFaLFEnfODuBiDp_iFgCHMYCw/I/15333648321459.jpg)

### 二、下载SDK并添加到项目

>增长变现解决方案是一整套的方案功能,其功能由多个SDK组合而成

##### （1）手动导入SDK
解压后名为SDK的文件夹内会包含以下内容

```
GrowSDK - 增长变现解决方案主体库
CMSSDK - MobSDK之一,提供咨询内容
ShareSDK - MobSDK之一,提供分享模块
Required - 基础支撑/工具类库
BaiduMobAd - 合作方百度AdSDK
```

![](https://lh3.googleusercontent.com/-gZzgKRuGQUU/W2VKckkdj1I/AAAAAAAABtk/lnpRYo1qWHYMuT_5H5BVO6_fbVec-lGmACHMYCw/I/x11.png)

选择Copy以复制SDK到项目
![](https://lh3.googleusercontent.com/-PYr0IXzhHYU/W2VKcOK0frI/AAAAAAAABtQ/5bXBo-zmXHE_hWJmDCMdVzGXYYJEs-kgwCHMYCw/I/x12.png)

添加系统依赖库:

```
-AdSupport.framework
-WebKit.framework
-MessageUI.framework
-libstdc++ 
-libz1.2.5
-libsqlite3 微信SDK所需
```

![](https://lh3.googleusercontent.com/-W-Ozz46Vadc/W2VKcidBKiI/AAAAAAAABtw/xKyy8tj6CrsGxL9VSrfYkyJcoSrvDw_BwCHMYCw/I/x13.png)

##### （2）pod导入

1. 首先 cd 至项目的根目录，执行 pod setup；

2. 按需在 Podfile 文件中添加命令：

```
pod 'mob_growsdk'
```

3. 如果之前没有安装过，第一次使用请先执行

安装库：```pod install```

如果之前一次没有已经安装过，那只需要在执行

更新库：```pod update```

### 三、添加代码

##### 1.绑定用户
>增长变现解决方案需要您有自己的用户系统支持,并将你的用户id(及同时支持头像、昵称)与我们的服务进行绑定。

导入头文件

```
#import <GrowSDK/GrowSDK.h>
```

进行绑定

```
[GrowSDK bindingAcount:@"YourUserId"
              nickName:@"YourUserNickName"
                avatar:@"YourUserAvatarUrl"
                result:^(NSString *mobUserId, NSError *error) {
                        //返回的mobUserId为内部流通的经转化的用户id,可不用理会   
}];
```

##### 2.展示模块
>增长变现解决方案整个木块的入口为控制器,直接调用展现即可。【注意展现前必须要执行上述第1步‘绑定用户’】

导入头文件
```
#import <GrowSDKUI/GrowSDKUI.h>
```

选定展示类型,并进行展示

```
[GrowSDKUI defaultUI].type = GSDKUIControllerShowTypePresent;
[[GrowSDKUI defaultUI] showFrom:self result:^(NSError *error) {
        
}];
```