//
//  MIBaseObjectSemiPublicInterface.h
//  MovieMaker
//
//  Created by Kevin Meaney on 09/05/2014.
//  Copyright (c) 2014 Kevin Meaney. All rights reserved.

@import Foundation;
@import CoreGraphics;

@class MIContext;

// Importing MIHandleCommands.h for definition of MICommandCompletionHandler.
#import "MIHandleCommands.h"

// Importing MIBaseObjectPublicInterface.h for GetClass and GetObject functions.
#import "MIBaseObjectPublicInterface.h"

/**
 @brief A protocol that all classes that inherit from MIBaseObject conform to.
 @discussion MIBaseObjectSemiPublicInterface Semi public interface.
 The result dictionary from all these commands is similar. All these objects
 return a reply dictionary which are managed by the MIReplyDictionary functions.
 
 The command dict passed into all these methods should provide the information
 necessary to perform the command.
*/
@protocol MIBaseObjectSemiPublicInterface <NSObject>

#pragma mark - The protocol required class and object methods

@required

/**
 @brief A Class method to handle the get property command.
 @discussion All classes that conform to the MIBaseObjectSemiPublicInterface
 protocol must implement this method. The property key MIJSONPropertyKey is
 required and its property value is the name of the requested class property.
 @param commandDict A dictionary describing the get property command.
 @param context The relevant context. If nil will use default context if needed.
 @result A dictionary returning error code and results.
 */
+(NSDictionary *)handleGetPropertyCommand:(NSDictionary *)commandDict
                                inContext:(MIContext *)context;

/**
 @brief A Class method to handle the making of an object command.
 @discussion All classes that conform to the MIBaseObjectSemiPublicInterface
 protocol must implement this method. The dictionary commandDict should define
 all the properties necessary to create the object.
 @param commandDict A dictionary describing the make object command.
 @param context The relevant context. If nil will use default context.
 @result A dictionary returning error code and results.
 */
+(NSDictionary *)handleMakeObjectCommand:(NSDictionary *)commandDict
                               inContext:(MIContext *)context;

/**
 @brief A class method to close all objects which are members of the class.
 @discussion A required method of the MIBaseObjectSemiPublicInterface. Will
 close all objects that are members of the class.
 @param commandDict A dictionary describing the close all objects command.
 @param context The relevant context. If nil will use default context.
 @result A dictionary returning error code and results.
 */
+(NSDictionary *)handleCloseAllObjectsCommand:(NSDictionary *)commandDict
                                    inContext:(MIContext *)context;

/// An instance method to handle the get property command.
-(NSDictionary *)handleGetPropertyCommand:(NSDictionary *)commandDict;

/// An instance protocol method to handle the get properties command.
-(NSDictionary *)handleGetPropertiesCommand:(NSDictionary *)commandDict;

/// An instance method to close the object.
-(NSDictionary *)handleCloseCommand:(NSDictionary *)commandDict;

@optional

#pragma mark - Class and object optional protocol methods

/// Calculate the size the drawn text takes up. bitmap, pdf, graphics context
+(NSDictionary *)handleCalculateGraphicSizeOfTextCommand:(NSDictionary *)dict
                                               inContext:(MIContext *)context;

#pragma mark Object instance methods handled by more than one type of base object

/**
 @brief A instance method to handle setting a property of the object.
 @discussion handled by objects of type: imagefilterchain, imageexporter,
 imageimporter, nsgraphicscontext
*/
-(NSDictionary *)handleSetPropertyCommand:(NSDictionary *)commandDict;

#pragma mark Object methods specific to bitmap, pdf, nsgraphicscontext objects

/// Draw synchronously the element into the context.
-(NSDictionary *)handleDrawElementCommand:(NSDictionary *)commandDict;

/// Draw asynchronously the element into the context.
-(NSDictionary *)handleDrawElementCommand:(NSDictionary *)command
               asyncWithCompletionHandler:(MICommandCompletionHandler)handler;

/// Assign the function that will make the requested image. Not a prop coz swift
// -(void)applyCreateImageFunction:(CGImageRef(^)(NSDictionary *))makeImageFunction;

#pragma mark Object methods specific to bitmap, nsgraphicscontext objects

/// The snapshot command method handled by bitmapcontext and nsgraphicscontext.
-(NSDictionary *)handleSnapshotCommand:(NSDictionary *)commandDict;

#pragma mark Instance methods specific to a image exporter object

/// An method to handle setting properties of an exporter object.
-(NSDictionary *)handleSetPropertiesCommand:(NSDictionary *)commandDict;

/// Add an image obtained from a secondary object to the image exporter object.
-(NSDictionary *)handleAddImageCommand:(NSDictionary *)commandDict;

/// Perform export command synchronously.
-(NSDictionary *)handleExportCommand:(NSDictionary *)commandDict;

/// Perform the export command asynchronously.
-(NSDictionary *)handleExportCommand:(NSDictionary *)command
          asyncWithCompletionHandler:(MICommandCompletionHandler)handler;

#pragma mark Instance methods specific to a bitmapcontext object

/// Get pixel data from the context of the bitmapcontext
-(NSDictionary *)handleGetPixelDataCommand:(NSDictionary *)commandDict;

#pragma mark Instance methods specific to a pdfcontext object

/// Object handle commands specific to the pdf context objects.
-(NSDictionary *)handleFinalizePageAndStartNew:(NSDictionary *)commandDict;

#pragma mark Instance methods specific to a imagefilterchain object

/**
 @brief Render the filter chain into its render destination.
 @param command Dictionary describing source/dest rects & filter props to modify
 @discussion All the entries in the dictionary in this sitation are optional.
 The filter properties to modify is an array of filter properties, one array
 entry per property to be modified.
 
 Each array entry is a dictionary. The dictionary contains keys/values to
 identify the CIFilter object that will have a property set, the key used
 to assign the property to the dictionary and the value to be assigned. If
 the value is not a NSNumber or a NSString type then a class key will also be
 specified so that the correct object can be converted from the dictionary
 value to be assigned to the filter to the correct type. If the class is
 CIImage then there are two other possible keys relating to making an image
 into a static image or not, and temporarily overriding the static image option
 and forcing the image to be updated befor the next filter chain render.
*/
-(NSDictionary *)handleRenderFilterChainCommand:(NSDictionary *)commandDict;

// Currently not sure if it is sensible to provide an async version of
// handleRenderFilterChain.
//-(NSDictionary *)handleRenderFilterChainCommand:(NSDictionary *)commandDict
//                    asyncWithCompletionHandler:(CommandCompletionHandler)handler;

@end
