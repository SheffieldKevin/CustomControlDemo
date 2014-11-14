//
//  MIContext.h
//  MovieMaker
//
//  Created by Kevin Meaney on 19/10/2014.
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NSInteger MIBaseReference;
extern const MIBaseReference kMIInvalidElementReference;

@class MIBaseObject;

/**
 @brief MIContext MovingImages context holding references to base objects
 @discussion Every base object that is a member of a MIContext has a base
 reference that is unique in that context and can be used to obtain a
 base object from the context. Every base object also has an object type and
 an object name. Objects can be obtained by their object type and name. This
 is not guaranteed to be unique (an object of a particular type can be given
 the same name as another object of the same type) but with judicious choice
 of object names then to all intents and purposes obtaining objects by their
 type and name can be reliable. A less reliable way of obtaining an object is
 via it's type and and type index. Deletion of other objects affects the
 object index so you might not get the object you expect. This approach
 should not be used.
*/
@interface MIContext : NSObject

/// Return the number of objects.
@property (readonly, assign) NSInteger numberOfObjects;

/**
 @brief If a context is not specified then the default context will be used.
 @discussion This is the accessor to the default context which will always
 return the same context whenever it is called.
*/
+(MIContext *)defaultContext;

/// The designated initializer
-(instancetype)init;

/// Add an object to the context and return its unique object reference.
-(MIBaseReference)addObject:(MIBaseObject *)object;

/// Remove the object with object reference. Return YES for success otherwise NO.
-(BOOL)removeObjectWithReference:(MIBaseReference)objectReference;

/// Remove the object. Returns YES if successful otherwise NO.
-(BOOL)removeObject:(MIBaseObject *)object;

/// Remove all objects
-(void)removeAllObjects;

/// Remove all objects by type
-(void)removeAllObjectsWithType:(NSString *)objectType;

/// Return the object which has the object reference. Returns nil on failure
-(MIBaseObject *)objectWithReference:(MIBaseReference)reference;

/// Return the object which has object type and name. Returns nil on failure
-(MIBaseObject *)objectWithType:(NSString *)type name:(NSString *)name;

/// Return the object which has object type and index. Return nil on failure
-(MIBaseObject *)objectWithType:(NSString *)type index:(NSInteger)index;

/// Return the number of objects of a particular type. Returns -1 if unknown type
-(NSInteger)numberOfObjectsOfType:(NSString *)objectType;

@end
