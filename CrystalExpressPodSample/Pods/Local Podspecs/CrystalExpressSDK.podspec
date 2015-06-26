Pod::Spec.new do |s|
  s.name         = "CrystalExpressSDK"
  s.version      = "1.1.2"

  s.summary      = "SDK library for Crystal Express Ad."
  s.homepage     = "http://demo.intowow.com/"
  s.license      = { :type => 'Copyright', :text => <<-LICENSE
                    Copyright (c) 2015 Intowow. All rights reserved.\n
                    LICENSE
                 }
  s.author       = { "intowow Co., Ltd" => "http://intowow.com/" }

  s.source       = { :http => "https://s3-ap-northeast-1.amazonaws.com/intowow/ios_ce_pod_sdk/libCrystalExpressSDK-1.1.2.zip" }
  s.platform     = :ios, "7.0"

  s.vendored_libraries  = "libCrystalExpressSDK-1.1.2.a"
  s.preserve_paths      = "libCrystalExpressSDK-1.1.2.a"
  s.source_files        = "Headers/*.h"
  s.public_header_files = "Headers/*.h"
  s.resources           = "Resources/*"

  s.dependency 'AFNetworking', '~> 2.3'
  s.dependency 'AWSiOSSDKv2', '2.0.15'
  s.dependency 'AFDownloadRequestOperation'
  s.dependency 'SocketRocket'
  s.dependency 'JSONKit-NoWarning'
  s.dependency 'SSZipArchive'
  s.dependency 'NJKWebViewProgress'
  s.dependency 'MTStatusBarOverlay', '~> 0.9'

  s.libraries    = "sqlite3", "c++", "z"
  s.frameworks   = "AdSupport", "AVFoundation", "CFNetwork", "CoreMedia", "CoreTelephony", "MessageUI", "MobileCoreServices", "SystemConfiguration"
end
