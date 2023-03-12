//
//  BorderDrawer.h
//  Veryfi-Lens
//
//  Created by Alex Levnikov on 1.07.21.
//  Copyright © 2021 Veryfi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RectangleFeature.h"
#import "AVFoundation/AVFoundation.h"



@interface BorderDrawer : NSObject
- (instancetype)initWithRootView: (UIView *) view
                    previewLayer: (AVCaptureVideoPreviewLayer *) previewLayer;

- (void)setBorderDetectUI:(UIColor *)fillColor
              strokeColor:(UIColor *)strokeColor;
- (void)drawBordersForRectangle: (NSArray<RectangleFeature *> *) rectangles image: (CIImage *) image roundedCorners: (BOOL) roundedCorners;
- (void)clearWithDelay:(BOOL)shouldDelay;
- (void)finish;
@end

