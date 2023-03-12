//
//  OCRDetectorHelper.h
//  Veryfi-Lens
//
//  Copyright © 2022 Veryfi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreMedia/CoreMedia.h>

NS_ASSUME_NONNULL_BEGIN

@class OCRResult, EncryptionSettings;

typedef void (^OCRAutoCaptureOnUpdate)(OCRResult*);
typedef void (^OCRAutoCaptureOnError)(NSString*);
typedef void (^OCRAutoCaptureOnFinish)(OCRResult*, UIImage *);

typedef void (^OCRProcessFrameResult)(OCRResult*, UIImage *);

@interface OCRDetectorHelper : NSObject

@property (nonatomic) BOOL isAutoCaptureEnabled;
@property (nonatomic, copy) OCRAutoCaptureOnFinish autoCaptureOnFinish;
@property (nonatomic, copy) OCRAutoCaptureOnUpdate autoCaptureOnUpdate;
@property (nonatomic, copy) OCRAutoCaptureOnError autoCaptureOnError;

- (instancetype)initWithEcryptionSettings: (EncryptionSettings *) encryptionSettings;
- (instancetype)init NS_UNAVAILABLE;
- (void)processImage: (UIImage *) image completion: (OCRProcessFrameResult) completion;
- (void)processFrame: (CMSampleBufferRef) buffer completion: (OCRProcessFrameResult) completion;
- (void)processAutoCaptureWithFrame: (CMSampleBufferRef)imageMat;

- (void)close;

@end

NS_ASSUME_NONNULL_END
