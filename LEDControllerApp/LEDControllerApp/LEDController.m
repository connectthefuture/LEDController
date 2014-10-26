//
//  LEDController.m
//  LEDControllerApp
//
//  Created by Greg Cotten on 10/26/14.
//  Copyright (c) 2014 Greg Cotten. All rights reserved.
//

#import "LEDController.h"

@implementation LEDController

-(instancetype)init{
    self = [super init];
    if (self)
    {
        self.serialPortManager = [ORSSerialPortManager sharedSerialPortManager];
        self.serialPort = [ORSSerialPort serialPortWithPath:@"/dev/tty.usbmodem427881"];
        self.serialPort.delegate = self;
        [self.serialPort setBaudRate:@115200];
        [self.serialPort open];
        [self setDefaultValues];
    }
    return self;
}

-(void)updateMicro{
    if (self.serialPort.isOpen) {
        char data[6];
        data[0] = 0;
        data[1] = (char)(self.redValue*255);
        data[2] = 1;
        data[3] = (char)(self.greenValue*255);
        data[4] = 2;
        data[5] = (char)(self.blueValue*255);
        [self.serialPort sendData:[NSData dataWithBytes:data length:6]];
    }
}

-(void)setDefaultValues{
    self.redValue = .5;
    self.greenValue = .5;
    self.blueValue = .5;
}


-(void)setRedValue:(double)redValue{
    _redValue = redValue;
    [self updateMicro];
}

-(void)setGreenValue:(double)greenValue{
    _greenValue = greenValue;
    [self updateMicro];
}

-(void)setBlueValue:(double)blueValue{
    _blueValue = blueValue;
    [self updateMicro];
}

-(void)serialPort:(ORSSerialPort *)serialPort didReceiveData:(NSData *)data{
    if (data) {
        NSLog(@"%@", [NSString stringWithUTF8String:data.bytes]);
    }
}

-(void)serialPortWasOpened:(ORSSerialPort *)serialPort{
    NSLog(@"%@ opened", serialPort);
}

-(void)serialPortWasRemovedFromSystem:(ORSSerialPort *)serialPort{
    
}


@end
