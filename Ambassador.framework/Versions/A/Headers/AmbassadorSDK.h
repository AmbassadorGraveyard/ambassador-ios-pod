//
//  Ambassador.h
//  Copyright (c) 2015 ZFERRAL INC (dba Ambassador Software). All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "AMBConversionParameters.h"
#import "AMBWelcomeScreenViewController.h"

// Enum for Conversion status types
typedef enum conversionStatus {
    ConversionSuccessful, // Conversion was successfully sent to Ambassador.
    ConversionPending, // Conversion has been saved to the database, but not yet sent to Ambassasdor. The main reason for this is because no referrer was found yet.
    ConversionError // Conversion parameter object contains an error(s).  Will not attempt to send to Ambassador until fixed.
} ConversionStatus;


@interface AmbassadorSDK : NSObject

/**
 
 Initializes the Ambassador SDK in an application using the provided credentials.
 
 Recommended to put inside of the AppDelegate's 'didFinishLaunchingWithOptions:' function to initialize Ambassador as soon as possible.
 
 @param universalToken Token provided by Ambassador which gives access to use Ambassador's SDK.
 @param universalID An ID provided by Ambassador which gives access to use Ambassador's SDK.
 
 */
+ (void)runWithUniversalToken:(NSString *)UniversalToken universalID:(NSString *)universalID;


/**
 
 Identifies a user and associates it with the given email.
 
 Recommended to put on a login screen or after the initial call to run Ambassador if you have the user's email stored.
 
 @param email User's email address which is used to identify a user.
 
 @warning This method is deprecated as of version 1.0.4.
 
 */
+ (void)identifyWithEmail:(NSString *)email __attribute__((deprecated("Use method 'identifyWithUserID: traits:' instead")));


/** 
 
 Identifies a user based a unique userID and a dictionary of traits.
 
 Recommended to put on a login screen or after the initial call to run Ambassador if you have the user's info stored.
 
 @param userID A unique ID tied to the user being identified
 @param traits Extra values tied to the user. Ex: Email, first name, last name, etc.
 @param options Used to pass extra options for the identify call. Ex: Passing the key/pair value '@"campaign" : @"1"' will auto-enroll the user in the campaign.
 
 @warning It is highly recommended to at least include an 'email' value in the traits dictionary in order for full functionality in the Ambassador SDK.
 
 */
+ (void)identifyWithUserID:(NSString *)userID traits:(NSDictionary *)traits options:(NSDictionary *)options;


/**
 
 Clears an identified user's saved data.
 
 Recommended to put this function on a logout action.
 
 @warning This function acts as a secondary layer of security, so it is highly recommended to utilize it.
 
 */
+ (void)unidentify;


/**
 
 Registers a conversion with Ambassador.
 
 @param conversionParameters The object used to set all of the values for a specific conversion.
 @param restrictToInstall Boolean value that decides if the conversion should only be allowed to get called once.
 @param completion Block that tells the user when the conversion is done attempting to send.  Block passes back the conversion, the conversionStatus, and an error if one occurs.
 
 */
+ (void)registerConversion:(AMBConversionParameters *)conversionParameters restrictToInstall:(BOOL)restrictToInstall completion:(void (^)(AMBConversionParameters *conversion, ConversionStatus conversionStatus, NSError *error))completion __attribute__((deprecated("Use method 'trackEvent: properties: options:' instead")));


/**
 
 Tracks an event with Ambassador.
 
 Currently, the only event Ambassador tracks is a conversion.
 
 @param eventName An optional value for the name of the event being tracked. 
 @param properties Properties set for the event. Ex: Campaign, email, revenue, etc.
 @param options Additional options that can be set for the event. 
 
 @warning In order to register the event as a conversion, the key/pair value '@"conversion" : @YES' must be added to the 'options' dictionary.
 
 */
+ (void)trackEvent:(NSString *)eventName properties:(NSDictionary *)properties options:(NSDictionary *)options;


/**
 
 Tracks an event with Ambassador.
 
 Currently, the only event Ambassador tracks is a conversion.
 
 @param eventName An optional value for the name of the event being tracked.
 @param properties Properties set for the event. Ex: Campaign, email, revenue, etc.
 @param options Additional options that can be set for the event.
 @param completion If event is a conversion, this block that tells the user when the conversion is done attempting to send.  Block passes back the conversion, the conversionStatus, and an error if one occurs.
 
 @warning In order to register the event as a conversion, the key/pair value '@"conversion" : @YES' must be added to the 'options' dictionary.
 
 */
+ (void)trackEvent:(NSString *)eventName properties:(NSDictionary *)properties options:(NSDictionary *)options completion:(void (^)(AMBConversionParameters *conversion, ConversionStatus conversionStatus, NSError *error))completion;


/**
 
 Presents a full-page modal 'Refer-A-Friend' (RAF) view-controller.
 
 It is important that the view-controller being passed is in the view hierarchy before the call is made.
 
 @param ID The campaign's ID that is tied to the RAF.
 @param viewController The view-controller which is presenting the RAF.
 @param themePlist An optional parameter which tells the RAF which theme to use when presenting.  If nil, Ambassador's generic theme will be used.
 
 @warning Calling this function in a view-controller's 'viewDidLoad' or 'viewWillAppear' functions may result in failure.
 
 */
+ (void)presentRAFForCampaign:(NSString *)ID FromViewController:(UIViewController *)viewController withThemePlist:(NSString*)themePlist;


/**
 
 Creates a Welcome Screen view-controller based on an Ambassador's data.
 
 The Welcome Screen will only be available if the app was installed from an Ambassador referral.
 
 @param parameters An object that contains the parameters used to customize the Welcome Screen.
 @param available A block that gets called if a referral took place and passes back the AMBWelcomeScreenViewController to be handled.
 
 */
+ (void)presentWelcomeScreen:(AMBWelcomeScreenParameters*)parameters ifAvailable:(void(^)(AMBWelcomeScreenViewController *welcomeScreenVC))available;

@end
