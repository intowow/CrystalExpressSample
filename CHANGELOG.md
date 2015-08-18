## [1.3.8]() (2015-08-??)
#### Feature
* Open source CEBannerADHelper

## [1.3.7]() (2015-08-10)
#### Feature
* Open source CETableViewADHelper, CEContentADHelper, CECardADHelper
* Add custom click action setting to support customized click action
* Ad click callback add landing url parameter
* Add macro replacer in 3rd party tracking url which is defined in China MMA v1.5 (`__OS__, __IDFA__, __ANDROIDID__`)
* Add `- (void)setAdCustomIndexPaths:(NSArray *)adIndexPaths` in CETableViewADHelper to allow setting fixed position for stream ads configure by App publisher
* Support SPLASH2_WEBVIEW AD format

#### Fixed
* Check whether placement hierarchy need update every time in CheckSDK method
* No onHide message sent in Stream AD while AD is not playing
* Set AD placement request time at AdShow and AdHide
* Add retry in SDK asset download
* Fix content AD dealloc bug
* Fix avplayer dealloc won't stop video
* Fix UI minor bugs
* Enhance error handling in SDK asset fetch (add retry for 3 times)
* Check Placement Hierarchy need reload in checkSDK everytime to avoid http failed

## [1.3.6]() (2015-08-07)
#### Feature
* Refactor ADView.h to hide some private method and properties.

#### Fixed
* Cancel AD request if SDK is not ready to serve to avoid massive AD requests in stream.

## [1.3.5]() (2015-08-05)
#### Fixed
* Cancel Splash AD request if there's already a Splash AD in current view hierarchy

## [1.3.4]() (2015-08-04)
#### Feature
* Add `- (void)setAdVerticalMargin:(float)verticalMargin;` in CETableViewADHelper API to allow customized stream AD's vertical margin
* Add `- (void)setAdBackgroundColor:(UIColor *)bgColor;` in CETableViewADHelepr API to allow customized stream AD's background color
* Add `- (void)setAdCellCustomizedBlock:(void (^)(UITableViewCell *adCell))customizedAdCellBlock;` in CETableViewADHelper API to allow customized ad view decoration
* Set AD UITableViewCell background color to clearColor
* Add `- (void)setAutoPlay:(BOOL)enableAutoPlay;` in CETableViewADHelper API to allow disable AD auto play
* Add `- (void)startAdAtIndexPath:(NSIndexPath *)indexPath;` in CETableViewADHelper API to allow manually start AD play
* Add `- (void)stopAdAtIndexPath:(NSIndexPath *)indexPath;` in CETableViewADHelper API to allow manually stop AD play

#### Fixed
* Fix iOS7 / iOS8 landscape viewcontroller present animation inconsistency bug
* Fix CETableViewADHelper cleanAds reset lastAddedPostion calculate wrong bug

## [1.3.3]() (2015-08-04)

#### Feature
* Add API for app to input App's AD position to avoid CrystalExpress insert beside App's AD

#### Fixed
* CETableViewADHelper - (NSIndexPath *)positionToIndexPath:(int)position calculate wrong bug
* Add flag in CETableViewADHelper loadAd to control load CrystalExpress AD


## [1.3.2]() (2015-08-03)

#### Feature
* Replace WiFi marquee with WiFi hint label animation and tag
* Optimize card format cover UI

#### Fixed
* Change Splash Ad cancel auto dimiss timer to viewWillDisappear
* Stream AD does not set active placement in CEStreamADHelper
* Allow user interaction while AD view animating
* Fix Stream AD insertion algorithm


## [1.3.1]() (2015-07-30)

#### Feature
* Support some bulit-in Splash AD present/dismiss animations
* Support customized Splash AD present/dismiss animation

#### Fixed
* Change CETableViewADHelper API from `refreshAd` to `cleanAds` to clearify the meaning
* Fix CEStreamADHelper strong delegate reference
* Fix CESplashAD does not release pointer while viewcontroller dismissed

## [1.3.0]() (2015-07-29)

#### Feature
* Support multiple frequency cap
* Support geo targeting AD serving
* Support multiple 3rd party impression tracking
* Support QR code change current geographic location
* New Splash/Stream integration API

#### Fixed
* Wrong frequency cap time calculate
* Does not check glocal capped in ADMatcher
* Only CPH time slot check in Prefetcher
