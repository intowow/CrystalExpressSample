# CrystalExpressSDK Test scenarios
## 1. Introduction
- This doc is designed to help you verify the CrystalExpress integration tracking message & AD display correctness.
- This doc is __NOT__ used to guide you for how to integrate CrystalExpress AD.
- The tracking message we listed here are sample format of tracking messages, the `adid`, `device_id` ... etc. value will not be the same as yours.

## 2. Test prestage setup
- Make sure you have your AD well-prepared and setup ready at server side.
- Init I2WAPI with verbose log, this may display the debug message in the debug console.

```objc
[I2WAPI initWithVerboseLog:YES];
```

- Verify that you Crsytal_id is filled correct in CrystalExpress.plist
- Open the test verification web page to verify the tracking message

## 3. Test cases
### 3.1 - First time lanuch App with CrsytalExpressSDK
> If this is the first time to use integrate CrystalExpressSDK, you should expect and verify the following tracking event happens.

1. Launch app. Verify web page for received __Open__ tracking message
> {"type":"open","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"APP","time":1431315115113,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}
2. Verify web page for received __Register__ tracking message
> {"props":{"ov":"8.2","idfa":"B11047684A7F4AB587E93A0E798FBA83","ot":1,"av":"1.0","sv":10010002,"dm":"Simulator","mf":"Apple Inc."},"type":"register","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"APP","time":1431315115221,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}
3. If there's some ADs ready at server side, SDK shold start to download its creatives. Once an AD is downloaded successfully, verify web page for received __Fetch__ tracking message
> {"props":{"item_id":1818},"type":"fetch","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"AD","time":1431315053535,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}
4. Leave app by pressing Home button, verify web page for received __Clost__ tracking message. The props should have the duration time which indicates the duration between open to close in seconds.
> {"props":{"duration":446453},"type":"close","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"APP","time":1431315491557,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}

---
### 3.2 - Display a Splash Video AD
1. Launch/Open app. Verify web page for received __Open__ tracking message
> {"type":"open","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"APP","time":1431315115113,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}
2. Request an splash AD and display it. When splsh AD viewcontroller is successfully presented. Verify web page for received __Impression__ tracking message
> {"props":{"placement":"OPEN_SPLASH","place":1,"item_id":1818},"type":"impression","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"AD","time":1431315723247,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}
3. You should see video AD start playing with mute status
4. Watch 10 seconds of AD, verify web page for received __AD_Request__ tracking message
> {"props":{"requests":{"OPEN_SPLASH":{"1":1}}},"type":"ad_request","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"ADREQ","time":1431315726371,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}
5. Click on video area, unmute the video AD. Verify web page for received __Unmute__ tracking message
> {"props":{"placement":"OPEN_SPLASH","place":1,"item_id":1896},"type":"unmute","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"AD","time":1431317302725,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}
6. Click on video area again, mute the Video AD. Verify web page for received __Mute__ tracking message
> {"props":{"placement":"OPEN_SPLASH","place":1,"item_id":1896},"type":"mute","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"AD","time":1431317314692,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}
7. Click on video AD engage area, should redirect you to AD landing page. Verify web page for received __Click__ tracking message and __Video_view__ tracking message
> {"props":{"placement":"OPEN_SPLASH","place":1,"item_id":1799},"type":"click","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"AD","time":1431317503439,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}
> 
> {"props":{"percentage":60,"duration":17976,"engaged":true,"place":1,"item_id":1799},"type":"video_view","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"AD","time":1431317504092,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}
8. Go back to app video AD, AD should replay itself with mute status. 
9. Watch the complete video AD, when it's reach to end, AD should auto replay itself. Verify web page for received __Video_view__ tracking message
> {"props":{"percentage":100,"duration":29419,"engaged":false,"place":1,"item_id":1865},"type":"video_view","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"AD","time":1431318528647,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}
10. Click on the close button to dismiss the AD view controller. Verify web page for received __Video_view__ tracking message
> {"props":{"percentage":17,"duration":4851,"engaged":false,"place":1,"item_id":1799},"type":"video_view","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"AD","time":1431317705624,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}

---
### 3.3 - Display a Stream Video AD
1. Launch/Open app. Verify web page for received __Open__ tracking message
> {"type":"open","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"APP","time":1431315115113,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}
2. Go to in-stream section that should display the stream video AD. Scroll until a stream video AD appear. Verify web page for received __Impression__ tracking message
> {"props":{"placement":"STREAM","place":1,"item_id":1865},"type":"impression","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"AD","time":1431318281463,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}
3. You should see video AD start playing with mute status
4. Watch 10 seconds of AD, verify web page for received __AD_Request__ tracking message
> {"props":{"requests":{"STREAM":{"1":1}}},"type":"ad_request","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"ADREQ","time":1431318282465,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}
5. Click on video area, unmute the video AD. Verify web page for received __Unmute__ tracking message
> {"props":{"placement":"STREAM","place":1,"item_id":1865},"type":"unmute","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"AD","time":1431318464931,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}
6. Click on video area again, mute the Video AD. Verify web page for received __Mute__ tracking message
> {"props":{"placement":"STREAM","place":1,"item_id":1865},"type":"mute","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"AD","time":1431318466565,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}
7. Click on video AD engage area, should redirect you to AD landing page. Verify web page for received __Click__ tracking message and __Video_view__ tracking message
> {"props":{"placement":"STREAM","place":1,"item_id":1865},"type":"click","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"AD","time":1431318467600,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}
> 
> {"props":{"percentage":15,"duration":4159,"engaged":true,"place":1,"item_id":1865},"type":"video_view","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"AD","time":1431318468298,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}
8. Go back to app video AD, AD should replay itself with mute status. Scroll until this AD is complete invisable in current view. Verify web page for received __Video_view__ tracking message
> {"props":{"percentage":17,"duration":4851,"engaged":false,"place":1,"item_id":1799},"type":"video_view","device_id":"659ED405duck8FFBduck41C9duckB07Aduck6F04748BD11C","cat":"AD","time":1431317705624,"nt":2,"version":4,"crystal_id":"2a317bd038f742a082ee284b478a8e37"}

---

