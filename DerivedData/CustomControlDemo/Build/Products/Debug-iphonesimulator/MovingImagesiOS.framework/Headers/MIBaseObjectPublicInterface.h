//
//  MIBaseObjectPublicInterface.h
//  MovieMaker
//
//  Created by Kevin Meaney on 09/05/2014.
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

@import Foundation;

@class MIContext;
@protocol MICreateCGImageInterface;
@protocol MICIRenderDestinationInterface;

#import "MIContext.h" // REMOVE Only needed for macro, remove when finished.

/**
 @brief A public interface for MIBaseObject classes and objects handling commands.
 @discussion The part of the base object interface that is public.
 The result dictionary from all these commands is similar. All have a error
 property whose value indicates the type of error, 0 is no error. To get the
 error code use MIGetErrorCodeFromReplyDictionary. For commands which return a
 value or a collection of values the dictionary also contains result properties.
 There is always a result string but other values are possible please see
 the functions in MIReplyDictionary.h for to access the data.

 The command dict passed into all these methods provides the information
 necessary to perform the command.
*/
@protocol MIBaseObjectPublicInterface <NSObject>

@required

/**
 @brief A method to handle commands relevant to inherited classes of MIBaseObject.
 @discussion Determines the type of sub command from the contents of the
 inputDictionary and performs the sub command.
 @param inputDict: Containing information necessary to perform the sub command.
 @param context: The context to perform the command in.
 @result A reply dictionary. Containing information about whether the
 sub command completed successfully, and a return value.
*/
+(NSDictionary *)handleClassCommand:(NSDictionary *)inputDict
                          inContext:(MIContext *)context;


/**
 @brief A command method handler relevant to objects that inherit from MIBaseObject.
 @discussion Determines the type of command from the contents of the
 inputDict and performs the command.
 @param inputDict Containing information necessary to perform the sub command.
 @result A reply dictionary. Containing information about whether the
 sub command completed successfully, and a return value.
*/
-(NSDictionary *)handleObjectCommand:(NSDictionary *)inputDict;

@end

/**
 @brief Return an object identified by the contents of the dictionary.
 @param objectDict The dictionary that identifies the object to be returned
 @result The requested object or nil if the reference was invalid.
*/
id MIGetObjectFromDictionary(MIContext *context, NSDictionary *objectDict);

/**
 @brief Return the class from the object type.
 @param type Specifies the type of the class we are looking for.
 @result The requested object or nil if it couldn't be found.
*/
Class MIGetClassForObjectType(NSString *objectType);

/// Find object defined by dict, conforming to protocol MICreateCGImageInterface
id <MICreateCGImageInterface>
FindObjectFromDictionaryConformingToCreateCGImageProtocol(MIContext *context,
                                                          NSDictionary *dict);

/// Find object defined by dict, conforming to  MICIRenderDestinationInterface
id <MICIRenderDestinationInterface>
FindObjectFromDictionaryConformingToRenderDestinationProtocol(MIContext *context,
                                                              NSDictionary *dict);

