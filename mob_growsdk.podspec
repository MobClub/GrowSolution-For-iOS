Pod::Spec.new do |s|
  s.name                  = 'mob_growsdk'
  s.version               = "1.3.0"
  s.summary               = 'mob.com 增长变现解决方案'
  s.license               = 'Copyright © 2012-2018 mob.com'
  s.author                = { "mob" => "mobproducts@163.com" }

  s.homepage              = 'http://www.mob.com'
  s.source                = { :http => 'http://dev.ios.mob.com/files/download/growsdk/v1.3.0.zip' }
  s.platform              = :ios
  s.ios.deployment_target = "8.0"
  #s.default_subspecs     = 'GrowSDK'

  s.frameworks    = 'WebKit','AdSupport','MessageUI','SafariServices'
  s.dependency 'MOBFoundation'
  s.dependency 'JiMu'
  s.dependency 'mob_sharesdk'
  s.dependency 'mob_cmssdk/CMSSDK'
  s.dependency 'mob_sharesdk/ShareSDKPlatforms/QQ'
  s.dependency 'mob_sharesdk/ShareSDKPlatforms/SinaWeibo'
  s.dependency 'mob_sharesdk/ShareSDKPlatforms/WeChat'
  s.dependency 'Masonry'
  s.dependency 'MJRefresh'


  s.vendored_frameworks = 'SDK/GrowSDK/GrowSDK.framework',
                          'SDK/GrowSDK/GrowSDKUI.framework', 
                          'SDK/GrowSDK/GrowSDKAdv.framework',
                          'SDK/Required/MSC.framework',
                          'SDK/GrowSDK/Support/Ads/BaiduLib/BaiduMobAdSDK.framework',
                          'SDK/GrowSDK/Support/Ads/VLionADSDK/VLionADSDK.framework',
                          'SDK/GrowSDK/Support/News/YL/YLDataSDK.framework'

  s.resources = 'SDK/GrowSDK/GrowSDKResource.bundle', 
                'SDK/CMSSDK/CMSSDKUI.bundle',
                'SDK/GrowSDK/Support/Ads/BaiduLib/baidumobadsdk.bundle',
                'SDK/GrowSDK/Support/Ads/VLionADSDK/VLionAdImg.bundle'

end
