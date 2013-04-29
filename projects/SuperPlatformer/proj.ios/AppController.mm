/****************************************************************************
 Copyright (c) 2010 cocos2d-x.org
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#import <UIKit/UIKit.h>
#import "AppController.h"
#import "cocos2d.h"
#import "EAGLView.h"
#import "AppDelegate.h"

#import "RootViewController.h"

@implementation AppController

#pragma mark -
#pragma mark Application lifecycle

// cocos2d application instance
static AppDelegate s_sharedApplication;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {    
    
    // Override point for customization after application launch.

    // Add the view controller's view to the window and display.
    window = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];
    EAGLView *__glView = [EAGLView viewWithFrame: [window bounds]
                                        pixelFormat: kEAGLColorFormatRGBA8
                                        depthFormat: GL_DEPTH_COMPONENT16
                                 preserveBackbuffer: NO
                                                                                 sharegroup:nil
                                                                          multiSampling:NO
                                                                    numberOfSamples:0];
    [__glView setMultipleTouchEnabled:YES];
    
    // Use RootViewController manage EAGLView 
    viewController = [[RootViewController alloc] initWithNibName:nil bundle:nil];
    viewController.wantsFullScreenLayout = YES;
    viewController.view = __glView;

    // Set RootViewController to window
    if ( [[UIDevice currentDevice].systemVersion floatValue] < 6.0)
    {
        // warning: addSubView doesn't work on iOS6
        [window addSubview: viewController.view];
    }
    else
    {
        // use this method on ios6
        [window setRootViewController:viewController];
    }
    
    [window makeKeyAndVisible];

    [[UIApplication sharedApplication] setStatusBarHidden: YES];
    
    cocos2d::CCApplication::sharedApplication()->run();
    
    // test
//    // origin=(x=94, y=30.4934) size=(width=12, height=26)
//    CGRect pRect = CGRectMake(94, 30.4934, 12, 26);
//    cocos2d::CCRect pRect2 = cocos2d::CCRectMake(94, 30.4934, 12, 26);
//    
//    // origin=(x=96, y=16) size=(width=16, height=16)
//    CGRect tileRect = CGRectMake(96, 16, 16, 16);
//    cocos2d::CCRect tileRect2 = cocos2d::CCRectMake(96, 16, 16, 16);
//    
//    CGRect intersection = CGRectIntersection(pRect, tileRect);
//    cocos2d::CCRect intersection2 = CCRectIntersection(pRect2, tileRect2);
//    
//    NSLog(@"intersection x: %.02f, y: %.02f, w: %.02f, h: %.02f"
//          , intersection.origin.x
//          , intersection.origin.y
//          , intersection.size.width
//          , intersection.size.height);
//    
//    NSLog(@"intersection2 x: %.02f, y: %.02f, w: %.02f, h: %.02f"
//          , intersection2.origin.x
//          , intersection2.origin.y
//          , intersection2.size.width
//          , intersection2.size.height);
    
    
//    (lldb) p collisionBox
//    (CGRect) $1 = origin=(x=94, y=37) size=(width=12, height=26)
//    (lldb) p diff
//    (CGPoint) $2 = (x=0, y=-4.67422)
    
//    CGRect collisionBox = CGRectMake(94, 37, 12, 26);
//    cocos2d::CCRect collisionBox2 = cocos2d::CCRectMake(94, 37, 12, 26);
//    CGPoint diff = CGPointMake(0, -4.67422);
//    cocos2d::CCPoint diff2 = cocos2d::CCPointMake(0, -4.67422);
//    
//    CGRect returnBoundingBox = CGRectOffset(collisionBox, diff.x, diff.y);
//    cocos2d::CCRect returnBoundingBox2 = CCRectOffset(collisionBox2, diff2.x, diff2.y);
//    
//    NSLog(@"returnBoundingBox x: %.02f, y: %.02f, w: %.02f, h: %.02f"
//          , returnBoundingBox.origin.x
//          , returnBoundingBox.origin.y
//          , returnBoundingBox.size.width
//          , returnBoundingBox.size.height);
//
//    NSLog(@"returnBoundingBox2 x: %.02f, y: %.02f, w: %.02f, h: %.02f"
//          , returnBoundingBox2.origin.x
//          , returnBoundingBox2.origin.y
//          , returnBoundingBox2.size.width
//          , returnBoundingBox2.size.height);
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    /*
     Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
     Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
     */
    cocos2d::CCDirector::sharedDirector()->pause();
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    /*
     Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
     */
    cocos2d::CCDirector::sharedDirector()->resume();
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    /*
     Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
     If your application supports background execution, called instead of applicationWillTerminate: when the user quits.
     */
    cocos2d::CCApplication::sharedApplication()->applicationDidEnterBackground();
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    /*
     Called as part of  transition from the background to the inactive state: here you can undo many of the changes made on entering the background.
     */
    cocos2d::CCApplication::sharedApplication()->applicationWillEnterForeground();
}

- (void)applicationWillTerminate:(UIApplication *)application {
    /*
     Called when the application is about to terminate.
     See also applicationDidEnterBackground:.
     */
}


#pragma mark -
#pragma mark Memory management

- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application {
    /*
     Free up as much memory as possible by purging cached data objects that can be recreated (or reloaded from disk) later.
     */
}


- (void)dealloc {
    [super dealloc];
}


@end

