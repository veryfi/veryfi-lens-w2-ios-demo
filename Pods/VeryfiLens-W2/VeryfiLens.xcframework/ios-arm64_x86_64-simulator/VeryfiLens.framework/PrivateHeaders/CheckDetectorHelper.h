//
//  CheckDetectorHelper.h
//  Veryfi-Lens
//
//  Copyright © 2021 Veryfi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RectangleFeature.h"

NS_ASSUME_NONNULL_BEGIN

@interface CheckDetectorHelper : NSObject
@property (nonatomic) BOOL isAutoRotationEnabled;

@property (nonatomic) BOOL isAutoCaptureEnabled;
@property (nonatomic) BOOL isDocumentDetected;
@property (nonatomic, copy) void (^autoCaptureOnFinish)();
@property (nonatomic, copy) void (^autoCaptureOnUpdate)(float);

- (NSArray <RectangleFeature *>*)rectanglesForBuffer:(CVImageBufferRef)buffer;
- (NSArray <RectangleFeature *>*)rectanglesForUIImage:(UIImage *)image;
- (NSArray<UIImage *>*)crop:(UIImage *)image deviceOrientation:(UIDeviceOrientation)deviceOrientation;

- (void)close;
- (void)enableChecksBackCapture:(BOOL)isEnabled;

@end

NS_ASSUME_NONNULL_END
