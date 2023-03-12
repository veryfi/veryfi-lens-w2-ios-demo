//
//  ImageHelper.h
//  Veryfi-Lens
//
//  Created by Alex Levnikov on 30.06.21.
//  Copyright © 2021 Veryfi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ImageHelperObjC : NSObject
+ (UIImage *)rotateUIImage:(UIImage *)image;
+ (UIImage *)rotateUIImage:(UIImage *)image orientation:(UIDeviceOrientation)orientation;
+ (UIImage *)rotateUIImage:(UIImage*)sourceImage
                 clockwise:(BOOL)clockwise;

+ (UIImage *)imageFromSampleBuffer:(CMSampleBufferRef)buffer;
+ (UIImage *)imageFromSampleBuffer:(CMSampleBufferRef)buffer
                          maxWidth:(double) maxWidth;

+ (UIImage *)imagefromPDF:(NSString *)path;

+ (CVPixelBufferRef)cvPixelBufferFromImage:(UIImage *)image;
+ (CMSampleBufferRef)bufferForImage:(UIImage *)image;
@end

NS_ASSUME_NONNULL_END
