/**
 * This file's original source is from Matt Stevens: https://github.com/mattstevens/xcode-googletest/wiki
 */

#import <XCTest/XCTest.h>

@interface GoogleTestStub : XCTest

+ (instancetype)testCaseStubWithName:(NSString *)name suite:(NSString *)suiteName;
+ (instancetype)testSuiteStubWithName:(NSString *)name testCaseCount:(NSUInteger)count;

@end
