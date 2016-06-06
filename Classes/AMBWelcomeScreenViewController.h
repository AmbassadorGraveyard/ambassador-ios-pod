//
//  AMBWelcomeScreenViewController.h
//  Ambassador
//
//  Created by Jake Dunahee on 2/29/16.
//  Copyright © 2016 Ambassador. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AMBWelcomeScreenParameters.h"

@protocol AMBWelcomeScreenDelegate <NSObject>

@optional
- (void)welcomeScreenActionButtonPressed:(UIButton*)actionButton;
- (void)welcomeScreenLinkPressedAtIndex:(NSInteger)linkIndex;

@end


@interface AMBWelcomeScreenViewController : UIViewController

@property (nonatomic, strong) AMBWelcomeScreenParameters * parameters;
@property (nonatomic, weak) id<AMBWelcomeScreenDelegate> delegate;

@end



