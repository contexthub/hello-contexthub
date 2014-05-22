//
//  CarbonBlack.h
//  ContextHub
//
//  Created by Travis Fischer on 9/18/13.
//  Copyright (c) 2013 ChaiOne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import  <UIKit/UIKit.h>
#import "CCHElementManifestService.h"
#import "CCHDevicesService.h"
#import "CCHSubscriptionResourceChangeHandler.h"

/**
 * The primary interface with the ContextHub Black SDK
 */
@interface ContextHub : NSObject <CLLocationManagerDelegate>

/**
 * Returns the default instance of CabonBlack
 */
+ (ContextHub *)sharedInstance;

/**
 * Registers the app with ContextHub. This call should be made on app launch.
 * You must register your app with the ContextHub SDK before you use any of the other API's profided in this SDK.
 * @param appId The application id that is assigned on ContextHub.
 */
+ (void)registerWithAppId:(NSString *)appId;


/**
 * The application's ID registered with ContextHub
 */
+ (NSString *)applicationId;

/**
 * The ID for the device
 */
+ (NSString *)deviceId;


/**
 returns the location from the ContextHub location manager
 */
+ (CLLocation *)currentLocation;

- (BOOL)addLocationManagerDelegate:(id <CLLocationManagerDelegate>)delegate;
- (BOOL)removeLocationManagerDelegate:(id<CLLocationManagerDelegate>)delegate;

/**
 When contextual elements are changed, ContextHub will send background push notifications to the applicaiton letting you know that new content is available.
 This will allow the context events to update and stay in sync with the server.  Otherwise, the user will need to relaunch the app to recieving context changes.
 @param application that is receiving the remote notification.
 @param userInfo that was delivered with the remote notification.
 @param completion a completion block that is executed when the context sync is completed.
 */
+ (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo completion:(void(^)(enum UIBackgroundFetchResult result))completion;

@end
