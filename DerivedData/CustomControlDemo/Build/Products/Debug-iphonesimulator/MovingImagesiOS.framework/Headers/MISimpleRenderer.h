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

@property (readonly, strong) MIContext *miContext;

/// Do we have a draw dictionary that contains the drawing instructions.
@property (readonly) BOOL hasDictionary;

/// Assign variables which will be used when interpreting the draw dictionary.
@property (strong) NSDictionary *variables;

/**
 @property createImage. A block that takes a dictionary, and returns an image.
 @discussion Assign a create image block or swift function to this property.
 The block or function should create the image based on the contents of the
 dictionary.
*/
@property (nonatomic, copy) CGImageRef(^createImage)(NSDictionary *);

/// Instantiate the renderer. Designated initializer.
-(instancetype)initWithMIContext:(MIContext *)miContext;

/// Assign the draw dictionary.
-(void)setDrawDictionary:(NSDictionary *)drawDict;

/// Using the draw instructions in the draw dictionary draw into the context.
-(void)drawIntoCGContext:(CGContextRef)context isFlipped:(BOOL)flipped;

@end
