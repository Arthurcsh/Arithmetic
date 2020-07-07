//
//  GraphicsView.m
//  FIRuntime
//
//  Created by chengshaohua on 2020/6/25.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "GraphicsView.h"

@implementation GraphicsView

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
 */
- (void)drawRect:(CGRect)rect {
    // Drawing code
    // 创建画布生成图形上下文
//    UIGraphicsBeginImageContextWithOptions(CGSizeMake(100, 100), NO, 0);
    // 获取刚创建的画布
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextAddRect(context, self.frame);
    CGContextSetFillColorWithColor(context, UIColor.whiteColor.CGColor);
    CGContextFillPath(context);
    
    CGContextAddEllipseInRect(context, CGRectMake(80, 120, 60, 60));
    CGContextSetFillColorWithColor(context, UIColor.redColor.CGColor);
    CGContextFillPath(context);
    
    NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle defaultParagraphStyle] mutableCopy];
    paragraphStyle.alignment = NSTextAlignmentCenter;
    UIFont *font = [UIFont systemFontOfSize:26];
    CGFloat fontheigh = font.lineHeight;
    CGContextSetFillColorWithColor(context, UIColor.darkGrayColor.CGColor);
    [@"Graphics" drawWithRect:CGRectMake(220, 130, 140, fontheigh) options:NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingTruncatesLastVisibleLine attributes:@{NSFontAttributeName:font,NSParagraphStyleAttributeName:paragraphStyle, NSStrikethroughStyleAttributeName:@(NSUnderlineStyleSingle)} context:nil];
    
//    UIGraphicsEndImageContext();
}

/**
 * drawLayer:inContext
 */
- (void)drawLayer:(CALayer *)layer inContext:(CGContextRef)ctx {
    [super drawLayer:layer inContext:ctx];
    
}

@end
