//  MIHandleCommands.h
//  Created by Kevin Meaney on 23/07/2013.
//  Copyright (c) 2014 Kevin Meaney. All rights reserved.

@import Foundation;
@import CoreGraphics;

@class MIContext;

/**
 @brief Command completion handler block definition. success is async op succeed.
 @discussion For the handle...Command asynchronous methods a completion handler
 can be called. The completion handler takes a single BOOL parameter and this
 parameter reflects whether the asynchronous command completed successfully or
 not.
*/
typedef void (^MICommandCompletionHandler)(BOOL success);


MIContext *MICreateContext();

/**
 @brief Handle a single command.
 @discussion The command parameter should contains all the information needed to
 perform the command.
 @param command The command to be handled described by a NSDictionary.
 @param context The context within which the command should be performed. If nil
 then commands will be performed within the default context.
 @result A reply dictionary with properties specifying whether the command
 completed successfully or not, and a reply value.
*/
NSDictionary *MIMovingImagesHandleCommand(MIContext *context,
                                          NSDictionary *command);

/**
 @brief Handle the list of commands which can be run sync or ascynchronously.
 @discussion If commands are to be run asynchronously then you can also pass
 in a completion handler which will be run on the main queue when the commands
 complete. If the commands are to be run synchronously or don't need to run a
 completion handler then just pass in nil.
 @param commands A dictionary with option properties & command list property.
 @param context The context within which the commands should be handled. If nil
 then commands will be performed within the default context.
 @param handler The completion handler, can be nil.
 @result A dictionary. If the commands are run synchronously then dictionary
 returns whether the commands successfully completed, and contains optional
 results. If the commands are run asychronously then the dictionary will return
 whether setting up the commands to run asynchronously or not was successful.
*/
NSDictionary *MIMovingImagesHandleCommands(MIContext *context,
                                           NSDictionary *commands,
                                           MICommandCompletionHandler handler);

/**
 @brief Create a CGImage using object represented by objectDict and image index.
 @discussion The image index is ignored, if the object that the image is
 requested from doesn't handle multiple images. The can't be this object
 is an object that can't be the image source. This will be the
 owner object meaning you can't get an image from an object your currently
 drawing to.
 @param context The context which contains the object to get image from.
 @param objectDict  A dictionary with info to find the image source object
 @param imageOptions  An image options dictionary. Contents depends on receiver.
 @param cantBeThisObject    This object is not available to get the image from
 */
CGImageRef MICreateImageFromObjectAndOptions(MIContext *context,
                                         NSDictionary *objectDict,
                                         NSDictionary *imageOptions,
                                         id cantBeThisObject) CF_RETURNS_RETAINED;

/**
 @brief Create a CGImage based on the properties of the image dictionary.
 @discussion MICreateImageFromDictionary will first see if it can obtain an
 image from the image collection in the context, but if the image identifier key
 is not specified then MICreateImageFromDictionary will determine the object to
 create the image and get the image options from the image dictionary and then
 call MICreateImageFromObjectAndOptions to create the image.
*/
CGImageRef MICreateImageFromDictionary(MIContext *context,
                                       NSDictionary *imageDict,
                                       id cantBeThisObject) CF_RETURNS_RETAINED;
