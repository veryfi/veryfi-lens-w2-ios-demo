//
//  DocumentDetectorHelper.h
//  Veryfi-Lens
//
//  Created by Alex Levnikov on 10.08.21.
//  Copyright © 2021 Veryfi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RectangleFeature.h"
#import <CoreMedia/CoreMedia.h>

NS_ASSUME_NONNULL_BEGIN

@class EncryptionSettings;

@interface DocumentDetectorHelper : NSObject
@property (nonatomic) BOOL isDocumentDetected;
@property (nonatomic) BOOL isAutoRotationEnabled;
@property (nonatomic) BOOL isAutoCaptureEnabled;
@property (nonatomic, copy) void (^autoCaptureOnFinish)();
@property (nonatomic, copy) void (^autoCaptureOnUpdate)(float);

- (instancetype)initWithEcryptionSettings: (EncryptionSettings *) encryptionSettings
                                  isGPUOn: (BOOL) gpuIsOn
                       isSkewCorrectionOn: (BOOL) isSkewCorrectionOn
                          isAutoCaptureOn: (BOOL) isAutoCaptureEnabled
                    isAutoRotationEnabled: (BOOL) isAutoRotationEnabled
                          cleanBorderIsOn: (BOOL) cleanBorderIsOn;
- (NSArray <RectangleFeature *>*)getDetectedRectangles;
- (NSArray <RectangleFeature *>*)rectanglesForBuffer:(CVImageBufferRef)buffer;
- (NSArray <RectangleFeature *>*)rectanglesForUIImage:(UIImage *)image;
- (NSArray<UIImage *>*)crop:(UIImage *)image;

- (void)close;

@end

NS_ASSUME_NONNULL_END
