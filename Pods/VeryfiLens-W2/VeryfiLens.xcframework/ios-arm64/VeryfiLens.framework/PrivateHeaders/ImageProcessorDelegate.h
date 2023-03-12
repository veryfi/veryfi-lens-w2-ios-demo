//
//  ImageProcessorDelegate.h
//  Veryfi-Lens
//
//  Created by Sebastian Giraldo on 17/02/22.
//  Copyright © 2022 Veryfi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RectangleFeature.h"

NS_ASSUME_NONNULL_BEGIN

@class CreditCard;

@protocol ImageProcessorDelegate <NSObject>

- (void)imageProcessorUpdatedBorders:(NSArray<RectangleFeature *> *)rectangles
                               image:(CIImage *)image;
- (void)imageProcessorDidCaptureImage:(NSArray<UIImage *> *)images
                         isDocument:(BOOL)isDocument;
- (void)imageProcessorUpdatedAutoCaptureProgress:(CGFloat)value;
- (void)imageProcessorUpdatedImageBrightnessValue:(double)value;
- (void)imageProcessorNotifyWithMessage:(NSString *)message;
- (void)imageProcessorCapturedCreditCard:(CreditCard *)creditCard;
- (void)imageProcessorCaptureImage;
- (void)updatePreviewStitching:(UIImage *)image;
- (void)notifyToSlowDown;
- (void)notifyBackToNormal;
- (void)notifyToTryAgainStitching;
@end

NS_ASSUME_NONNULL_END
