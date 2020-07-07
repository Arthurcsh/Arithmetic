//
//  GraphicsViewController.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/6/25.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "GraphicsViewController.h"
#import "GraphicsView.h"

@interface GraphicsViewController ()

@end

@implementation GraphicsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = UIColor.whiteColor;
    [self drawGraphicsImage];
}

- (void)drawGraphicsImage {
    GraphicsView *view = [GraphicsView new];
    view.frame = self.view.frame;
    [self.view addSubview:view];
}

@end
