//
//  MISimpleRenderer.h
//  MovieMaker
//
//  Created by Kevin Meaney on 03/11/2014.
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

// #import <Foundation/Foundation.h>
@import Foundation;
@import QuartzCore;

#import "MIReplyDictionary.h"

@class MIContext;

@interface MISimpleRenderer : NSObject

/// Assign variables which will be used when interpreting the draw dictionary.
@property (nonatomic, copy) NSDictionary *variables;

/// Instantiate the renderer. Designated initializer.
-(instancetype)initWithDrawDictionary:(NSDictionary *)drawDict;

/// Draw into the context. Assumes already oriented to bottom left is 0,0.
-(void)drawIntoCGContext:(CGContextRef)context;

/// Assign an image to the image collection with identifier.
-(void)assignImage:(CGImageRef)image withIdentifier:(NSString *)identifier;

/// Remove image from image collection with identifier.
-(void)removeImageWithIdentifier:(NSString *)identifer;

@end
