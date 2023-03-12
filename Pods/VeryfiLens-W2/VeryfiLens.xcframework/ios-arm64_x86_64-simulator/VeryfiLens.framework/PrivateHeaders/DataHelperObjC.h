//
//  DataHelper.h
//  VeryfiLens
//
//  Created by Alex Levnikov on 15.11.21.
//  Copyright © 2021 Veryfi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DataHelperObjC : NSObject
+ (NSString*)base64forData:(NSData*)data;
@end

NS_ASSUME_NONNULL_END
