//
//  TVScaledSlider.h
//
//  Created by TavisacaIos on 9/4/12.
//  Copyright (c) 2012 Tavisca. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef struct {
    short int minimumValue;
    short int maximumValue;
} TVScaledSliderRange;


typedef enum {
    TVScaledSliderStyleDefault ,
    TavicsaStyle
} TVScaledSliderStyle;

typedef void (^TVSliderValueChangedBlock)(id sender);

@protocol TVCalibratedSliderDelegate;

/**
 A control used to select a value from a bunch of values. 
 This control is drawn as horizontal bar with scale below it.
 -------
 USAGE :
 -------
 TVScaledSlider *programmaticallyCreatedTVSlider = [[TVScaledSlider alloc] initWithFrame:CGRectMake(..,..,..,..) withStyle:TavicsaStyle];
 [programmaticallyCreatedTVSlider setRange:range];
 [programmaticallyCreatedTVSlider setDelegate:self] ;
 
 */

@interface TVCalibratedSlider : UIView

@property (nonatomic, weak) id<TVCalibratedSliderDelegate> delegate;

@property (nonatomic, copy) TVSliderValueChangedBlock tvSliderValueChangedBlock;

@property (nonatomic, strong) UIColor *markerValueColor;

@property (nonatomic) TVScaledSliderStyle style;

/**
 @abstract Initialize the slider with a frame and style.
 
 @param frame
 @param style Constant indicating slider style.
 @return TVScaledSlider or nil.
 */
- (id)initWithFrame:(CGRect)frame withStyle:(TVScaledSliderStyle)style;

/**
 @abstract Sets the current value.
 @param value
 */
- (void)setValue:(NSInteger)value ;

/**
 @abstract Returns the current value of the slider.
 @return Value The value of the position where the slider is currently positioned.
 */
- (NSInteger)value ;

/**
 @abstract Set the slider range.
 @param range
 */
- (void)setRange:(TVScaledSliderRange)range;

/**
 @return Slider range.
 */
- (TVScaledSliderRange)range;

/**
 @abstract Assigns a maximum track image to the specified control states.

 @param imageName The minimum track image name to associate with the specified states.
 @param capInsets  The values to use for the cap insets.
 @param state The control state with which to associate the image.
 */
- (void)setMaximumTrackImage:(NSString *)imageName withCapInsets:(UIEdgeInsets)capInsets forState:(UIControlState)state;

/**
 @abstract Assigns a minimum track image to the specified control states.
 
 @param imageName The minimum track image name to associate with the specified states.
 @param capInsets  The values to use for the cap insets.
 @param state The control state with which to associate the image
 */
- (void)setMinimumTrackImage:(NSString *)imageName withCapInsets:(UIEdgeInsets)capInsets forState:(UIControlState)state;

/**
 @abstract Sets the image as the thumb image of the slider for the specified state.
 
 @param imageName  The thumb image to associate with the specified states.
 @param state      The control state with which to associate the image.
 */
- (void)setThumbImage:(NSString *)imageName forState:(UIControlState)state;

/**
 @abstract Sets the thumb image with offset relative to the center of the track.
 
 @discussion Offset is needed when using a custom thumb image to position it relative to track (not complusory).
 @param imageName The thumb image to associate with the specified states.
 @param state The control state with which to associate the image.
 @param offset The offset point relative to the track.
 */
- (void)setThumbImage:(NSString *)imageName forState:(UIControlState)state withOffsetRelativeToCenterOfTrack:(CGPoint)offset;

/**
 @abstract Set the marker image.
 @param imageName Image Name for the marker image.
 */
- (void)setScaleMarkerImage:(NSString *)imageName;

/**
 @abstract Set the text color on the highlighted thumb image.
 @param color Text color on the highlighted thumb image.
 */
- (void)setTextColorForHighlightedState:(UIColor *)color;
@end


@protocol TVCalibratedSliderDelegate <NSObject>

/**
 @abstract This method will be called by the TVScaledSlider when the value of slider changes.
 @param tvScaledSlider TVScaledSlider
 */
- (void)valueChanged:(TVCalibratedSlider *)tvScaledSlider;
@end