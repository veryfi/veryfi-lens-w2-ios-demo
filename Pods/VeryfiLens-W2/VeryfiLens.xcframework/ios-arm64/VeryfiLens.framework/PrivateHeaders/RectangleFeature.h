//
//  RectangleFeature.h
//  Veryfi Lens
//  Copyright © 2020 Veryfi. All rights reserved.
//
#import <UIKit/UIKit.h>

/**
 * RectangleFeature that describes found document frame.
 * @author Veryfi
 *
 * @property topLeft
 * @property topRight
 * @property bottomRight
 * @property bottomLeft
 */
@interface RectangleFeature : NSObject

@property (nonatomic) CGPoint topLeft;
@property (nonatomic) CGPoint topRight;
@property (nonatomic) CGPoint bottomRight;
@property (nonatomic) CGPoint bottomLeft;

@end
