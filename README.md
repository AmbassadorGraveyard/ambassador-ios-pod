# Ambassador iOS SDK

# How do I install the iOS SDK?

The preferred way to install the framework is with CocoaPods. Add a dependency in your Podfile with the following line:

```
pod 'Ambassador', '1.1.2'
```

If you don't use CocoaPods, follow these steps to install the Ambassador SDK in your Objective-C or Swift project.

* [Download](https://s3-us-west-2.amazonaws.com/ambassador-readmeio/Framework.zip) the SDK zip file, unzip it, and drag the enclosed framework and bundle files into your project beneath the project file (the zip file is attached at the bottom of this article).
![](https://files.readme.io/ENXWNp3dRkKdsmymGzCG_ios_sdk_1.png)

* Elect to copy the SDK files into your project.
![](https://files.readme.io/vVBH2Pt9TVaErBQTFcoP_ios_sdk_2.png)
* Go to __Build Phases__ and link to the following library:
  * libicucore
![](https://files.readme.io/UFb2v0Q6OZTI9CJrBhyw_ios_sdk_3.png)

* Add "-ObjC" and "-lstdc++" flags under "Build Settings > Other Linker Flags"
![](https://files.readme.io/3b660e5-Pasted_Image_4_24_18__10_43_AM.png)

### Adding a bridging header (Swift projects)
The SDK is written in Objective-C. In addition to the previous steps, installing the SDK into a Swift project requires a bridging header. If your project doesn't already have a bridging header, you can add one easily. If you already have a bridging header due to another library or framework, go to [Configuring a Bridging header (Swift Projects)](#section-configuring-a-bridging-header-swift-projects-).

* Add a new file to your project.
![](https://files.readme.io/wZIMtbkVRUanF1hofVBx_ios_sdk_5.png)

* Select the Objective-C file type.
![](https://files.readme.io/VuLE37gTJuiKKGUgOC2w_ios_sdk_6.png)

* This is essentially a dummy file which can be named anything.
![](https://files.readme.io/GVXhOEVQQJm8iP0W5B0i_ios_sdk_7.png)

* A Prompt will appear asking if you want to configure a bridging header. Select Yes.
![](https://files.readme.io/C9whbZgCS6SHEcVuulPE_ios_sdk_8.png)

* This will create both the dummy Objective-C file and a bridging header sharing the name of your project.
![](https://files.readme.io/Q5HMRDSPGFJkVyntD2gE_ios_sdk_9.png)

* At this point, you can delete the dummy Objective-C file. It is no longer needed.
![](https://files.readme.io/LMB7HXWJRk6AOzl97PqO_ios_sdk_10.png)

## Configuring a Bridging header (Swift projects)

In the bridging header, add an import statement for the Ambassador SDK.

```
#import <Ambassador/Ambassador.h>
```

## Initializing Ambassador

1. If you're using Objective-C, import the Ambassador framework in your __AppDelegate.m__.

**Objective-C**
```
#import <Ambassador/Ambassador.h>
```

2. You will want to run Ambassador inside of the __application:didFinishLaunchingWithOptions:__ function in your __AppDelegate.m__. You will need a Universal ID and SDK Token. Your Universal ID can be found on your [snippet page](https://cdn.getambassador.com/editor) by clicking the "Here you go" link in the center of the page. Your SDK Token will be provided to you by Ambassador.

**Objective-C**

```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {\n  // Override point for customization after application launch.\n  \n  [AmbassadorSDK runWithUniversalToken:<your_sdk_token> universalID:<your_universal_id>];\n\n  return YES;\n}
```

**Swift**
```
func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool\n{\n    // Override point for customization after application launch.\n\n    AmbassadorSDK.runWithUniversalToken(<your_sdk_token>, universalID:<your_universal_id>)\n\n    return true\n
```


## Usage

#### For instructions on how to use the SDK, check out our <a href="https://docs.getambassador.com/v2.0.0/page/ios-sdk">Official Documentation</a>.

## Release Notes

1.1.2


    Improve the SVC popup timing
    Make conversion API call more robust
    Improve logs for conversions

1.1.1


    Added more robust support for navigation and tab controllers

1.1.0


    Improved code to handle JSON responses more gracefully.
    Improved error handling on the RAF widget based on the status of the contact provided.
    Improved version tracking for future updates.
    Deprecated welcome message.
    Updated deprecated method IdentifyWithEmail so it no longer sends the email as the UID.
    Improved the identify Safari View Controller experience.
    Added confirmation that Twitter and Facebook are installed when sharing.

All versions


    Deprecated the Welcome Message feature

1.0.12


    Added iOS 11 support
    Fixed large close button icon

1.0.11


    Add bitcode support for arm64, swift projects

1.0.10


    Fix Swift 3.x compatibility issues
    Changed safari view controller animation to popover
    Refactored callback behavior to fire after view controller closed
    Included safari view controller for iOS 9+

Upgrading from v1.0.9

Note: Swift 3.x apps should upgrade to this version.

1.0.9


    Add optional callback to identify method
    Add ability to customize identify landing page time (LandingPageMinimumSeconds)
    Made iOS 9 identify functionality consistent with iOS 10
    Add better default message for LandingPageMessage

Upgrading from v1.0.8

    Note that the Safari View Controller will now show on screen for iOS 9 + for identify calls.

1.0.8 (Retired)


    Added new method to get referring short code
    Added new method to get campaign from short code
    Added support for iOS 10
    Added customizable landing page for identify

1.0.7 (Retired)


    Updated identifyWithUserID and trackEvent methods

Upgrading from v1.0.6

    The options dictionary was removed from the identifyWithUserID and trackEvent methods. You no longer need to pass this object to these methods.

1.0.6 (Retired)


    Updated crash analytics
    Refactoring and bug fixes

1.0.5 (Retired)


    Updated some AmbassadorSDK functions to handle more data
    Refactoring and minor bug fixes

Upgrading from v1.0.4

    Highly recommended to upgrade from any deprecated functions
    For more information on installing and implementing AmbassadorSDK check here




## Download

<a href="https://s3-us-west-2.amazonaws.com/ambassador-readmeio/Framework.zip" style="font-size:large">Framework.zip</a>