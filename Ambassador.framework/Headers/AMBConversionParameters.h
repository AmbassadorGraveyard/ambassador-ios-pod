//
//  ConversionParameters.h
//  iOS_Framework
//
//  Created by Diplomat on 6/29/15.
//  Copyright (c) 2015 ZFERRAL, INC (dba Ambassador Software). All rights reserved.
//

#import <Foundation/Foundation.h>


@interface AMBConversionParameters : NSObject

@property (nonatomic, retain) NSNumber * mbsy_campaign;
@property (nonatomic, retain) NSString * mbsy_email;
@property (nonatomic, retain) NSString * mbsy_first_name;
@property (nonatomic, retain) NSString * mbsy_last_name;
@property (nonatomic, retain) NSNumber * mbsy_email_new_ambassador;
@property (nonatomic, retain) NSString * mbsy_uid;
@property (nonatomic, retain) NSString * mbsy_custom1;
@property (nonatomic, retain) NSString * mbsy_custom2;
@property (nonatomic, retain) NSString * mbsy_custom3;
@property (nonatomic, retain) NSNumber * mbsy_auto_create;
@property (nonatomic, retain) NSNumber * mbsy_revenue;
@property (nonatomic, retain) NSNumber * mbsy_deactivate_new_ambassador;
@property (nonatomic, retain) NSString * mbsy_transaction_uid;
@property (nonatomic, retain) NSString * mbsy_add_to_group_id;
@property (nonatomic, retain) NSString * mbsy_event_data1;
@property (nonatomic, retain) NSString * mbsy_event_data2;
@property (nonatomic, retain) NSString * mbsy_event_data3;
@property (nonatomic, retain) NSNumber * mbsy_is_approved;

@end
