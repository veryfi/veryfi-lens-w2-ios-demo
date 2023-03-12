//
//  ImageHelperC.h
//  Veryfi-Lens
//
//  Created by Alex Levnikov on 15.11.21.
//  Copyright © 2021 Veryfi. All rights reserved.
//

#import <UIKit/UIKit.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#import "AVFoundation/AVFoundation.h"

NS_ASSUME_NONNULL_BEGIN
@interface ImageHelperC : NSObject
+ (cv::Mat)matFromImage:(UIImage *)image;
+ (cv::Mat)matFromPixelBuffer:(CVImageBufferRef)pixelBuffer;
+ (UIImage *)imageFromMat:(cv::Mat)cvMat;
+(std::vector<cv::Point>)getBoundingBoxFromFrame:(cv::Mat)imageMath rateWidth:(float) rateWidth rateHeight: (float)rateHeight;
NS_ASSUME_NONNULL_END
@end
