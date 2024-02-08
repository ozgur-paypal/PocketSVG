/*
 * This file is part of the PocketSVG package.
 * Copyright (c) Ponderwell, Ariel Elkin, Fjölnir Ásgeirsson, and Contributors
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "SVGBezierPath.h"
#import "SVGImageView.h"
#import "SVGLayer.h"
#import "SVGEngine.h"


// We need this check and declaration for Tuist because it does not generate SWIFTPM_MODULE_BUNDLE for objc SPM.
#if SWIFT_PACKAGE && !(defined(SWIFTPM_MODULE_BUNDLE))

NSBundle* SWIFTPM_MODULE_BUNDLE() {
    NSString *bundleName = @"PocketSVG_PocketSVG";

    
    NSArray<NSURL*> *candidates = @[
        NSBundle.mainBundle.resourceURL,
        NSBundle.mainBundle.bundleURL
    ];

    for (NSURL* candiate in candidates) {
        NSURL *bundlePath = [candiate URLByAppendingPathComponent:[NSString stringWithFormat:@"%@.bundle", bundleName]];

        NSBundle *bundle = [NSBundle bundleWithURL:bundlePath];
        if (bundle != nil) {
            return bundle;
        }
    }

    @throw [[NSException alloc] initWithName:@"SwiftPMResourcesAccessor" reason:[NSString stringWithFormat:@"unable to find bundle named %@", bundleName] userInfo:nil];
}

#define SWIFTPM_MODULE_BUNDLE SWIFTPM_MODULE_BUNDLE()

#endif
