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
#import "LEDController.h"

@interface AppDelegate ()

@property (weak) IBOutlet NSWindow *window;
@property (weak) IBOutlet LEDController *ledController;


@end

@implementation AppDelegate

- (void)applicationWillTerminate:(NSNotification *)notification
{
    [self.ledController appWillTerminate];
}

@end
