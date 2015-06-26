//
//  StreamADHelper.h
//  Pods
//
//  Created by roylo on 2014/10/31.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ADView;
@protocol StreamADHelperDelegate <NSObject>
- (NSIndexPath *)onADLoaded:(UIView *)adView atIndexPath:(NSIndexPath *)indexPath isPreroll:(BOOL)isPreroll;
- (void)onADAnimation:(UIView *)adView atIndexPath:(NSIndexPath *)indexPath;
- (BOOL)checkIdle;
@end

@interface StreamADHelper : NSObject
@property (nonatomic, assign) BOOL isActiveSection;
@property (nonatomic, weak) id<StreamADHelperDelegate> delegate;

- (instancetype)initWithPlacement:(NSString *)placement;
- (void)preroll;
- (UIView *)requestADAtPosition:(NSIndexPath *)indexPath;
- (void)updateVisiblePosition:(UITableView *)tableView;
- (NSOrderedSet *)getLoadedAds;
- (void)stopADs;
- (void)setActive:(BOOL)isActive;
- (BOOL)isAdAtIndexPath:(NSIndexPath *)indexPath;
- (void)setPreferAdWidth:(CGFloat)width;
- (CGFloat)getCurrentAdWidthSetting;
- (void)cleanADs;

#pragma mark - event listener
- (void)scrollViewDidScroll:(UIScrollView *)scrollView tableView:(UITableView *)tableView;
- (void)tableView:(UITableView *)tableView didEndDisplayingCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)scrollViewStateChanged;
@end