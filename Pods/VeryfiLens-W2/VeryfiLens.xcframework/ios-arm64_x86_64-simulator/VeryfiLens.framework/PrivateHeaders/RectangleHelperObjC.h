//
//  RectangleHelper.h
//  Veryfi-Lens
//
//  Created by Alex Levnikov on 30.06.21.
//  Copyright © 2021 Veryfi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AVFoundation/AVFoundation.h"
@class RectangleFeature;

NS_ASSUME_NONNULL_BEGIN

@interface RectangleHelperObjC : NSObject
+ (UIBezierPath *)getPathFromRectangleFeature:(RectangleFeature *)rectangle
                                        image:(CIImage *)image
                                      preview:(AVCaptureVideoPreviewLayer *)preview
                               roundedCorders:(BOOL)roundedCorders;

+ (RectangleFeature *)convertRectangleFeature:(RectangleFeature *)rectangle
                                        image:(CIImage *)image
                                      preview:(AVCaptureVideoPreviewLayer *)preview;

@end

NS_ASSUME_NONNULL_END
