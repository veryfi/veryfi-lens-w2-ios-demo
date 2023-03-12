//
//  BlurHelper.h
//  Veryfi-Lens
//
//  Created by Alex Levnikov on 30.06.21.
//  Copyright © 2021 Veryfi. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface BlurHelper : NSObject
+ (double)blurForImage:(UIImage *) image;
+ (double)blurFastImage:(UIImage *) image;
+ (BOOL)isImageBlured:(UIImage *)image;
@end

NS_ASSUME_NONNULL_END
