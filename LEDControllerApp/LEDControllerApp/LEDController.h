//
//  LEDController.h
//  LEDControllerApp
//
//  Created by Greg Cotten on 10/26/14.
//  Copyright (c) 2014 Greg Cotten. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ORSSerialPort/ORSSerialPortManager.h>
#import <ORSSerialPort/ORSSerialPort.h>

@interface LEDController : NSObject <ORSSerialPortDelegate>

@property (nonatomic) double redValue;
@property (nonatomic) double greenValue;
@property (nonatomic) double blueValue;
@property (nonatomic) int maxLEDs;

@property (nonatomic) BOOL serialPortIsOpen;

@property (nonatomic, strong) ORSSerialPortManager *serialPortManager;
@property (nonatomic, strong) ORSSerialPort *serialPort;

-(void)appWillTerminate;



@end
