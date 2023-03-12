//
//  RectangleHelperC.h
//  VeryfiLens
//
//  Created by Alex Levnikov on 15.11.21.
//  Copyright © 2021 Veryfi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AVFoundation/AVFoundation.h"
#import "CoreImage/CoreImage.h"
#import "RectangleFeature.h"
#include <opencv2/core.hpp>


NS_ASSUME_NONNULL_BEGIN

@interface RectangleHelperC : NSObject
+ (std::vector<CGPoint>)convertPointsFromRectangleFeature:(RectangleFeature *)rectangle
                                                    image:(CIImage *)image
                                                  preview:(AVCaptureVideoPreviewLayer *)preview;

+ (NSArray <RectangleFeature *>*)rectanglesFromCorners:(std::vector<cv::Point>)corners
                                           imageWidth:(int)imageWidth
                                          imageHeight:(int)imageHeight;

+ (RectangleFeature *)rectangleFromCorners:(std::vector<cv::Point>)corners
                              previewWidth:(int)previewWidth
                             previewHeight:(int)previewHeight;

+ (std::vector<cv::Point>)cornersFromRectangles:(NSArray <RectangleFeature *>*)rectangles
                              previewWidth:(int)previewWidth
                             previewHeight:(int)previewHeight;
@end

NS_ASSUME_NONNULL_END
