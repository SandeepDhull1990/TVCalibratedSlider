//
//  TVScaledSliderDemoViewController.m
//  TVScaledSliderDemoViewController
//
//  Created by TaviscaIos on 9/12/12.
//  Copyright (c) 2012 Tavisca. All rights reserved.
//

#import "TVCalibratedSliderDemoViewController.h"
#import "TVCalibratedSlider.h"

@interface TVCalibratedSliderDemoViewController () <TVCalibratedSliderDelegate> {
    TVCalibratedSlider *_programmaticallyCreatedSlider;
}

@property (weak, nonatomic) IBOutlet UIView *containerView;
@property (weak, nonatomic) IBOutlet TVCalibratedSlider *scaledSlider;
- (IBAction)btnDecrementRange:(id)sender;
- (IBAction)btnIncrementRange:(id)sender;

@end

@implementation TVCalibratedSliderDemoViewController
@synthesize containerView;
@synthesize scaledSlider;

- (void)viewDidLoad {
    [super viewDidLoad];
    
    TVScaledSliderRange range;
    range.maximumValue = 5;
    range.minimumValue = 1;
    
    [scaledSlider setRange:range];
    [scaledSlider setValue:3];
    [scaledSlider setTextColorForHighlightedState:[UIColor blackColor]];
    [scaledSlider setStyle:TavicsaStyle];
    scaledSlider.tvSliderValueChangedBlock = ^(id sender){
        NSLog(@"The value is %d",[(TVCalibratedSlider *)sender value]);
    };
    
//    Adding the slider programatically
    
//    _programmaticallyCreatedSlider = [[TVScaledSlider alloc] init];
//    _programmaticallyCreatedSlider.frame = containerView.frame;
//    _programmaticallyCreatedSlider.style = TVScaledSliderStyleCustom;

    _programmaticallyCreatedSlider = [[TVCalibratedSlider alloc] initWithFrame:containerView.bounds withStyle:TavicsaStyle];
//    [_programmaticallyCreatedSlider setThumbImage:nil forState:UIControlStateHighlighted];
//    [_programmaticallyCreatedSlider setThumbImage:nil forState:UIControlStateNormal];
    TVScaledSliderRange range2;
    range2.maximumValue = 15;
    range2.minimumValue = 1;
    [_programmaticallyCreatedSlider setRange:range2];
    [containerView addSubview:_programmaticallyCreatedSlider];
    [_programmaticallyCreatedSlider setTextColorForHighlightedState:[UIColor redColor]];
    [_programmaticallyCreatedSlider setDelegate:self] ;
}

- (IBAction)btnDecrementRange:(id)sender {
    TVScaledSliderRange range;
    range.maximumValue = 2;
    range.minimumValue = -5;
    [scaledSlider setRange:range];
    _programmaticallyCreatedSlider.frame = CGRectMake(10, 0, 100, 150);
}

- (IBAction)btnIncrementRange:(id)sender {
    TVScaledSliderRange range;
    range.maximumValue = 8;
    range.minimumValue = 0;
    [scaledSlider setRange:range];
    _programmaticallyCreatedSlider.frame = CGRectMake(10, 15, 300, 200);
    [_programmaticallyCreatedSlider setRange:range];    
}

- (void)valueChanged:(TVCalibratedSlider *)sender {
    NSLog(@"Delegate called");
}

@end
