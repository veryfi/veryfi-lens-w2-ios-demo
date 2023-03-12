//
//  Stitcher.h
//  Veryfi-Lens
//
//  Copyright © 2020 Veryfi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CoreVideo/CoreVideo.h"
#import "AVFoundation/AVFoundation.h"
#import "ImageProcessorDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@protocol LongReceiptProcessorDelegate
-(void)longReceiptProcessorDidUpdatePreview: (UIImage *) image;
-(void)longReceiptProcessorDidUpdateBorders: (NSArray <RectangleFeature *> *) borders image: (CIImage *) image;
-(void)longReceiptProcessorShouldSlowDown: (BOOL) shouldSlowDown;
-(void)longReceiptProcessorDidStitchImage: ( UIImage * _Nullable ) image;
@end


@interface StitcherHelper : NSObject
@property(nonatomic) BOOL isStitching;
@property(nonatomic, weak) id<LongReceiptProcessorDelegate> delegate;
- (void)clean;
- (instancetype)init;
- (void)processBuffer:(CMSampleBufferRef)buffer;
- (void)processImage:(UIImage *)image;
- (UIImage *)stitchedImage;
- (int)getMergedCount;
- (void)start;
- (void)stop;
@end

NS_ASSUME_NONNULL_END
