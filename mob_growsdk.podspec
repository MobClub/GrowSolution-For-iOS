Pod::Spec.new do |s|
  s.name                  = 'mob_growsdk'
  s.version               = "1.0.0"
  s.summary               = 'mob.com 增长变现解决方案'
  s.license               = 'Copyright © 2012-2018 mob.com'
  s.author                = { "mob" => "mobproducts@163.com" }

  s.homepage              = 'http://www.mob.com'
  s.source                = { :git => "https://github.com/MobClub/GrowSolution-For-iOS.git", :tag => s.version.to_s }
  s.platform              = :ios
  s.ios.deployment_target = "8.0"
  #s.default_subspecs      = 'GrowSDK'

  s.frameworks    = 'WebKit','AdSupport','MessageUI'
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
                          'SDK/Required/MSC.framework',
                          'SDK/BaiduMobAd/BaiduMobAdSDK.framework'

  s.resources = 'SDK/GrowSDK/GrowSDKResource.bundle', 
                'SDK/CMSSDK/CMSSDKUI.bundle',
                'SDK/BaiduMobAd/baidumobadsdk.bundle'



end
