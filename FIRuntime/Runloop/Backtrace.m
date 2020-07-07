//
//  Backtrace.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/5/29.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "Backtrace.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

@implementation Backtrace

void registerSignalHandler(void) {
    NSSetUncaughtExceptionHandler(&uncaughtExceptionHandler);
    signal(SIGSEGV, handleSignalException);
    signal(SIGFPE, handleSignalException);
    signal(SIGBUS, handleSignalException);
    signal(SIGPIPE, handleSignalException);
    signal(SIGHUP, handleSignalException);
    signal(SIGINT, handleSignalException);
    signal(SIGQUIT, handleSignalException);
    signal(SIGABRT, handleSignalException);
    signal(SIGILL, handleSignalException);
    
    // 在应用崩溃后，保持运行状态而不退出，让响应更加友好
//    CFRunLoopRef runLoop = CFRunLoopGetCurrent();
//    CFArrayRef allModes = CFRunLoopCopyAllModes(runLoop);
//    while (!dismissed) {
//        for (NSString *mode in (__bridge NSArray *)allModes) {
//            CFRunLoopRunInMode((__bridge CFStringRef)mode, 0.001, false);
//        }
//    }
//    CFRelease(allModes);
}

void handleSignalException(int signal) {
    NSMutableString *crashString = [[NSMutableString alloc] init]; void* callstack[128];
    int i, frames = backtrace(callstack, 128);
    char** traceChar = backtrace_symbols(callstack, frames);
    for (i = 0; i <frames; ++i) {
        [crashString appendFormat:@"%s\n", traceChar[i]];
    }
    NSLog(@"crash: %@",crashString);
    free(traceChar);
}


void uncaughtExceptionHandler(NSException *exception) {
    NSString *ret = [NSString stringWithFormat:@"异常名称:\n%@\n\n异常原因:\n%@\n\n出错堆栈内容:\n%@\n",exception.name, exception.reason, exception.callStackSymbols];
    // 将捕获到的 exception 细节上传到后台
    NSLog(@"uncaught: %@",ret);
}

@end
