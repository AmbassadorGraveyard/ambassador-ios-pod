//
//  AMBWelcomScreenParamets.h
//  Ambassador
//
//  Created by Jake Dunahee on 3/1/16.
//  Copyright © 2016 Ambassador. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AMBWelcomeScreenParameters : NSObject

- (instancetype)init;

@property (nonatomic, strong) NSString * referralMessage;
@property (nonatomic, strong) NSString * detailMessage;
@property (nonatomic, strong) NSString * actionButtonTitle;
@property (nonatomic, strong) NSArray * linkArray;
@property (nonatomic, strong) UIColor * accentColor;

@end
