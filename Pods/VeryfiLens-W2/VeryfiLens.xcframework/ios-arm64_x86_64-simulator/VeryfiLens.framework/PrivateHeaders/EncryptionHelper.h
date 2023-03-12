//
//  EncryptionHelper.h
//  Veryfi-Lens
//
//  Created by Alex Levnikov on 10/21/20.
//  Copyright © 2020 Veryfi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EncryptionHelper : NSObject
+ (NSData *)encryptData:(NSData *)data forKey:(NSString *)secretKey iv:(NSString *)iv;
+ (NSData *)decryptData:(NSData *)data forKey:(NSString *)secretKey iv:(NSString *)iv;
+ (NSString *)decryptDataString:(NSString *)data forKey:(NSString *)secretKey;
+ (NSString *)SHA1_16:(NSString *)input;
+ (NSString *)SHA256_16:(NSString *)input;
@end

