//
//  SubmitButton.h
//  Veryfi-Lens
//
//  Created by Alex Levnikov on 1/20/21.
//  Copyright © 2021 Veryfi. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SubmitButton : UIView

- (instancetype _Nonnull)initWithFrame:(CGRect)frame title: (NSString * _Nullable) title backgroundColor: (UIColor * _Nullable) backgroundColor textColor: (UIColor * _Nullable) textColor cornerRadius: (CGFloat) cornerRadius  borderColor: (UIColor * _Nullable) borderColor didTouchBlock:(void(^ _Nullable)(id _Nullable)) didTouchBlock;
- (void)startAnimating;
- (void)stopAnimating;

@end

