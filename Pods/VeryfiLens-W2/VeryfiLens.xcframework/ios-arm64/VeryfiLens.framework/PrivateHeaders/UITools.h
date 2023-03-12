//
//  UITools.h
//
//  (c) Veryfi.com
//

#import <UIKit/UIKit.h>

@interface UITools : NSObject

+ (void)getURL:(NSString *)url;

+ (NSString *)stringFromDate:(NSDate *)date;

+ (NSString *)dtNow:(NSString*)key;

+ (UIButton *)createButton:(NSString *)imgName
        accessibilityLabel:(NSString *)accessibilityLabel
               frameCGRect:(CGRect)frameCGRect
          instanceCallerVC:(id)instanceCallerVC
                    action:(SEL)action
                       tag:(NSInteger)tag;

+ (NSString *)convert_UTCDate_to_LocalDate_String:(NSDate *)utcDate
                                       dateFormat:(NSString *)dateFormat;

+ (UIView *)createCircularButtonView:(NSString *)imgName
                              imgObj:(UIImage *)imgObj
                  accessibilityLabel:(NSString *)accessibilityLabel
                         frameCGRect:(CGRect)frameCGRect
                           tintColor:(UIColor *)tintColor
                    instanceCallerVC:(id)instanceCallerVC
                              action:(SEL)action
                                 tag:(NSInteger)tag
                        paddingValue:(float)paddingValue
                       hasBlurEffect:(BOOL)hasBlurEffect
                      isBlurAdaptive:(BOOL)isBlurAdaptive;
@end
