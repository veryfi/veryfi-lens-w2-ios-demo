//
//  CardDetector.h
//  Veryfi-Lens
//
//  Created by Alex Levnikov on 5.08.21.
//  Copyright © 2021 Veryfi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreMedia/CoreMedia.h>
#import "RectangleFeature.h"

NS_ASSUME_NONNULL_BEGIN

@class CreditCard, EncryptionSettings;

typedef void (^AutoCaptureOnUpdate)(CreditCard*);
typedef void (^AutoCaptureOnError)(NSString*);
typedef void (^AutoCaptureOnFinish)(CreditCard*);

@interface CardDetectorHelper : NSObject

@property (nonatomic, readonly) BOOL isAutoCaptureModelsEnabled;
@property (nonatomic, readonly) BOOL isCardDetected;
@property (nonatomic, readonly) BOOL isImageAutoDetected;
@property (nonatomic, readonly) BOOL isGpuEnabled;
@property (nonatomic) BOOL isAutoRotationEnabled;
@property (nonatomic) BOOL isAutoCaptureEnabled;
@property (nonatomic, copy) AutoCaptureOnFinish autoCaptureOnFinish;
@property (nonatomic, copy) AutoCaptureOnUpdate autoCaptureOnUpdate;
@property (nonatomic, copy) AutoCaptureOnError autoCaptureOnError;

- (instancetype)initWithEcryptionSettings: (EncryptionSettings *) encryptionSettings gpuEnabled: (BOOL) gpuEnabled;
- (void)initAutocaptureModels;
- (instancetype)init NS_UNAVAILABLE;
- (CreditCard *)dataFromCreditCard:(UIImage *)image;

- (BOOL)detectCard:(CMSampleBufferRef)buffer;
- (UIImage *)cropCard:(UIImage *)image;
- (NSArray <RectangleFeature *>*)rectanglesForBuffer:(CVImageBufferRef)buffer;
- (NSArray <RectangleFeature *>*)rectanglesForUIImage:(UIImage *)image;
- (void)close;
- (void)reset;

@end

NS_ASSUME_NONNULL_END
