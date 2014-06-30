//
//  SUHost.h
//  Sparkle
//
//  Copyright 2008 Andy Matuschak. All rights reserved.
//

#import "SUUpdater.h"
#import "SUAppcast.h"
#import "SUAppcastItem.h"
#import "SUVersionComparisonProtocol.h"

@interface SUHost : NSObject
{
@private
    NSString *defaultsDomain;
    BOOL usesStandardUserDefaults;
}

@property (retain, readonly) NSBundle *bundle;

+ (NSString *)systemVersionString;

- (instancetype)initWithBundle:(NSBundle *)aBundle;
@property (readonly, copy) NSString *bundlePath;
@property (readonly, copy) NSString *appSupportPath;
@property (readonly, copy) NSString *installationPath;
@property (readonly, copy) NSString *name;
@property (readonly, copy) NSString *version;
@property (readonly, copy) NSString *displayVersion;
@property (readonly, copy) NSImage *icon;
@property (getter=isRunningOnReadOnlyVolume, readonly) BOOL runningOnReadOnlyVolume;
@property (getter=isBackgroundApplication, readonly) BOOL backgroundApplication;
@property (readonly, copy) NSString *publicDSAKey;
@property (readonly, copy) NSArray *systemProfile;

- (id)objectForInfoDictionaryKey:(NSString *)key;
- (BOOL)boolForInfoDictionaryKey:(NSString *)key;
- (id)objectForUserDefaultsKey:(NSString *)defaultName;
- (void)setObject:(id)value forUserDefaultsKey:(NSString *)defaultName;
- (BOOL)boolForUserDefaultsKey:(NSString *)defaultName;
- (void)setBool:(BOOL)value forUserDefaultsKey:(NSString *)defaultName;
- (id)objectForKey:(NSString *)key;
- (BOOL)boolForKey:(NSString *)key;

@end
