//
//  ViewController.m
//  FIRuntime
//
//  Created by CSH on 2020/4/12.
//  Copyright © 2020 www.bundwealth.com. All rights reserved.
//

#import "ViewController.h"
#import "Person.h"
#import "DupllcatesPoint.h"
#import "BlockForwarding.h"
#import "CharReverse.h"
#import "SumNumTarget.h"
#import "FRuntime.h"
#import "CustomMode.h"
#import "GCDTread.h"
#import "GraphicsViewController.h"

@interface ViewController ()



@property (nonatomic, copy) NSString *testStr;
@property (nonatomic, strong) IBOutlet UIImageView *avatarImageView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self initMainPage];
    
    
    // runtime消息转发
//    Person *person = [Person new];
//    [person run];
    
//    NSMutableArray *dupllcates = [[NSMutableArray alloc] initWithObjects:@1,@3,@3,@5,@6,@7,@7,@8,@9,@2,@6,@11,@13,nil];
//    [DupllcatesPoint removeDupllcates:dupllcates];
//    [DupllcatesPoint solutionDupllcates:dupllcates];
    
//    [self gcd_dispatch];
    [self gcd_group_semaphore];
    
//    __strong NSString *string __attribute__((cleanup(stringCleanUp))) = @"chengshaohua";
    
//    [self memoryManager];
    
    // 测试Block __block
//    [[[BlockForwarding alloc] init] initBlock];
    
//    char reverse[] = "hello, world";
//    char_reverse(reverse);
//    NSLog(@"--- reverser result: %s", reverse);
    
//    NSArray *array = @[@(1),@(3),@(4),@(7),@(2),@(9),@(6)];
//    NSArray *result = [SumNumTarget sumNumber:array target:9];
//    NSLog(@"--- sum result: %@", result);
    
    // runloop自定义mode
//    CustomMode *custom = [[CustomMode alloc] init];
//    [custom runLoopModeTest];
    
    FRuntime *runtime = [FRuntime new];
    [runtime testIVarProperty];
    [runtime addClassMethod];
    
}

/**
 * 初始化首页视图
 */
- (void)initMainPage {
    [self drawGraphicsImage];
    
//    [self drawShanpeLayer];
}

- (void)drawGraphicsImage {
    CGRect size = self.avatarImageView.frame;
    CALayer *shadowLayer = [CALayer layer];
    shadowLayer.frame = size;
    shadowLayer.backgroundColor = UIColor.whiteColor.CGColor;
    shadowLayer.shadowColor = UIColor.darkGrayColor.CGColor;
    shadowLayer.shadowOffset = CGSizeMake(4, 2);
    shadowLayer.shadowOpacity = 0.5;
    shadowLayer.cornerRadius = size.size.height/2;
    
    [self.view.layer insertSublayer:shadowLayer atIndex:0];
    self.avatarImageView.layer.cornerRadius = shadowLayer.cornerRadius;
    self.avatarImageView.layer.masksToBounds = YES;  // 触发off-screen渲染
    self.avatarImageView.layer.borderWidth = 2;
    self.avatarImageView.layer.borderColor = UIColor.grayColor.CGColor;
}

/**
 * Layer.masksToBounds & Layer.cornerRadius改进 CAShapeLayer
 */
- (void)drawShanpeLayer {
    CGRect bounds = self.avatarImageView.bounds;
    CGRect size = self.avatarImageView.frame;
    CALayer *shadowLayer = [CALayer layer];
    shadowLayer.frame = size;
    shadowLayer.backgroundColor = UIColor.whiteColor.CGColor;
    shadowLayer.shadowColor = UIColor.darkGrayColor.CGColor;
    shadowLayer.shadowOffset = CGSizeMake(4, 2);
    shadowLayer.shadowOpacity = 0.5;
    shadowLayer.cornerRadius = bounds.size.height/2;
    [self.view.layer insertSublayer:shadowLayer atIndex:0];
    
    CAShapeLayer *shanpeLayer = [CAShapeLayer new];
    shanpeLayer.frame = bounds;
    shanpeLayer.fillColor = UIColor.lightGrayColor.CGColor;
    
    UIBezierPath *bezierPath = [UIBezierPath bezierPathWithRoundedRect:bounds cornerRadius:bounds.size.height/2];
    bezierPath.lineWidth = 2;
    shanpeLayer.path = bezierPath.CGPath;
    self.avatarImageView.layer.mask = shanpeLayer;
}


// 检测crash崩溃信息
- (IBAction)crashAction:(id)sender {
//    char *names;
//    names[3] = 'b';
    
    FRuntime *runtime = [FRuntime new];
    [runtime methodObjc];
}

- (IBAction)drawGraphics:(id)sender {
    GraphicsViewController *graphicsViewController = [GraphicsViewController new];
    [self.navigationController pushViewController:graphicsViewController animated:YES];
}


static void stringCleanUp(__strong NSString **string) {
    NSLog(@"clearup:  %@", *string);
}


/**
 * TaggedPointer
 * iOS用于优化NSNumber，NSDate，NSString等小对象的存储，将对象指针拆分，一部分保留数据，一部分作特殊标。不够存数据时，会动态分配内存进行存储，维护引用计数，指针存储对象地址值，其实就是上面的方式二，传统方式
 *
 * 当String的内容有中文或者特殊字符(非ASCII字符)时，那么就只能存储为String指针
 */
- (void)memoryManager {
    dispatch_queue_t queue = dispatch_get_global_queue(0, 0);
    for(int i=0;i<10000;i++) {
        dispatch_async(queue, ^{
            self.testStr = [NSString stringWithFormat:@"1234567890123"];
        });
    }
    NSLog(@"-- memroy: %@", [self.testStr class]);
}


/**
 * GCD是苹果公司为多核的并行运算解决方案，会自动利用更多的CPU内核，
 * GCD自动管理线程的生命周期(创建、调度、销毁)
 *
 * GCD的两个核心概念：任务和队列
 */

/**
 * 全局队列本质上就是并发队列
 * 并发队列&全局队列
 * 并发队列有自定义名称，可以跟踪错误，全局队列没有
 * 在ARC中不需要考虑内存释放，在MRC中需要手动dispatch_release(queue)释放内存，全局队列只有一个由系统管理
 * 一般情况下使用全局队列，但是对于同一类业务创建一个固定的队列进行管理，如SDK为两使被导入的SDK不影响到主应用的其他业务队列操作，建议创建自己专属的队列
 */
- (void)gcd_dispatch {
    // 串行队列，异步执行：会新建一个线程，按串行顺序执行. DISPATCH_QUEUE_SERIAL = NULL
    dispatch_queue_t queue = dispatch_queue_create("com.chshua.dispatch", DISPATCH_QUEUE_SERIAL);
    for (int i=0; i<10; i++) {
        dispatch_async(queue, ^{
            NSLog(@"%@ --- %d", [NSThread currentThread], i);
        });
    }
    
    // 并行队列，异步执行：会新建多个线程，无法确定任务执行顺序
    dispatch_queue_t concurrent = dispatch_queue_create("com.chshua.dispatch", DISPATCH_QUEUE_CONCURRENT);
    for (int i=0; i<10; i++) {
        dispatch_async(concurrent, ^{
            NSLog(@"%@ --- %d", [NSThread currentThread], i);
        });
    }
}

- (void)gcd_group_semaphore {
    [GCDTread concurrentGroupSemaphore];
}


@end
