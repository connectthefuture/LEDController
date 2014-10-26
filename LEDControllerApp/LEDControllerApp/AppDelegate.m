//
//  AppDelegate.m
//  LEDControllerApp
//
//  Created by Greg Cotten on 10/26/14.
//  Copyright (c) 2014 Greg Cotten. All rights reserved.
//

#import "AppDelegate.h"
#import <ORSSerialPort/ORSSerialPortManager.h>
#import <ORSSerialPort/ORSSerialPort.h>

@interface AppDelegate ()

@property (weak) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationWillTerminate:(NSNotification *)notification
{
    NSArray *ports = [[ORSSerialPortManager sharedSerialPortManager] availablePorts];
    for (ORSSerialPort *port in ports) { [port close]; }
}

@end
