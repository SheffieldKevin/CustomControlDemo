//  MIJSONConstants.h
//  MovingImages
//
//  Created by Kevin Meaney on 10/09/2013.
//  Copyright (c) 2013-2014 Kevin Meaney. All rights reserved.

// In the comments if a parameter is shown in [] like [blendmode] then it means
// that is an optional property. If an optional property is not specified then
// the current context value is used. Otherwise the property is required.

// If the character | is displayed between two required properties then only
// one of the required properties is needed. For example radius|radiuses
// indicates that one of radius or radiuses is required but not both. If you
// provide both then the behaviour is undefined.

@import Foundation;

/**
 @name The following are used to define the keys in a JSON object
 @discussion In "Made of" any component in square brackets is an optional
 component. For example [blendmode] is an optional value. Where | is in
 the components list items on either side of the | are mutually exclusive.
 For example in the rounded rectangle one of radius or radiuses is required
 but if both are specified radiuses will be ignored.
*/

#pragma mark - Draw element related property keys and values.

/// The debug name of the element. "elementdebugname". string
extern NSString *const MIJSONKeyElemenetDebugName;

#pragma mark Element type Key, followed by the element type values.

/// The type of element to be created. "elementtype". string
extern NSString *const MIJSONKeyElementType;

/**
 @brief The element type is an array of elements. "arrayofelements"
 @discussion Made of: { array of elements, [fillcolor], [strokecolor],
 [linewidth], [blendmode] [transformation] [affinetransform] }
*/
extern NSString *const MIJSONValueArrayOfElements;

/**
 @brief The element type fill rectangle. "fillrectangle"
 @discussion Made of: { rect, [fillcolor], [blendmode], [transformation]
 [affinetransform] }
*/
extern NSString *const MIJSONValueRectangleFillElement;

/**
 @brief The element type stroke rectangle. "strokerectangle"
 @discussion Made of: { rect, [strokecolor], [linewidth], [blendmode],
 [transformation] [affinetransform] }
*/
extern NSString *const MIJSONValueRectangleStrokeElement;

/**
 @brief The element type fill oval. "filloval"
 @discussion Made of: { rect, [fillcolor], [blendmode], [transformation]
 [affinetransform] }
*/
extern NSString *const MIJSONValueOvalFillElement;

/**
 @brief The element type stroke oval. "strokeoval"
 @discussion Made of: { rect, [strokecolor], [linewidth], [blendmode],
 [transformation] [affinetransform] }
 */
extern NSString *const MIJSONValueOvalStrokeElement;

/**
 @brief The element type line. "drawline"
 @discussion Made of: { startpoint, endpoint, [strokecolor], [linewidth],
 [linecap], [blendmode], [transformation] [affinetransform] }
*/
extern NSString *const MIJSONValueLineElement;

/**
 @brief The element type array of lines. "drawlines"
 @discussion Made of an array of points. { points, [strokecolor], [linewidth],
 [linecap], [blendmode], [transformation] [affinetransform] }
 Each pair of points represents a startpoint and an endpoint, so the number of
 points must be even.
*/
extern NSString *const MIJSONValueLineElements;

/**
 @brief The element type fill round cornered rectangle. "fillroundedrectangle"
 @discussion Made of: { rect, radius|radiuses, [strokecolor], [blendmode],
 [transformation] [affinetransform] }
*/
extern NSString *const MIJSONValueRoundedRectangleFillElement;

/**
 @brief The element type stroke round cornered rectangle. "strokeroundedrectangle"
 @discussion Made of: { rect, radius|radiuses, [strokecolor], [linewidth],
 [blendmode], [transformation] [affinetransform] }
*/
extern NSString *const MIJSONValueRoundedRectangleStrokeElement;

/**
 @brief The element type fill the path. "fillpath"
 @discussion Made of: { arrayofpathelements, [fillcolor], [blendmode],
 [transformation] [affinetransform] }
*/
extern NSString *const MIJSONValuePathFillElement;

/**
 @brief The element type stroke the path. "strokepath"
 @discussion Made of: { arrayofpathelements, [linewidth], [linecap], [linejoin],
 [miter], [strokecolor], [blendmode], [transformation] [affinetransform] }
*/
extern NSString *const MIJSONValuePathStrokeElement;

/**
 @brief The element type stroke and fill the path. "fillandstrokepath"
 @discussion Made of: { arrayofpathelements, [linewidth], [linecap], [linejoin],
 [miter], [strokecolor], [blendmode], [transformation], [affinetransform]
 [fillcolor] }
*/
extern NSString *const MIJSONValuePathFillAndStrokeElement;

/**
 @brief The basic draw string element type. "drawbasicstring"
 @discussion Made of: { stringtext, point, postscriptfontname, fontsize,
 [fillcolor], [arrayofpathelements], [textalignment] [strokecolor],
 [stringstrokewidth], [blendmode], [transformation] [affinetransform] }
*/
extern NSString *const MIJSONValueBasicStringElement;

/**
 @brief The element type linear gradient fill. "lineargradientfill"
 @discussion Made of: { line, arrayofcolors, arrayoflocations, startpoint,
 arrayofpathelements }
 Performs a gradient fill by specifying a line along which the colour gradient
 is interpolated. Colors are specified at specific locations along the line and
 the gradient is interpolated between those points. The drawing of the gradient
 is clipped to an area defined by the startpoint and arrayofpathelements in
 exactly the same way the path is defined for the path fill element drawing
 command.
*/
extern NSString *const MIJSONValueLinearGradientFill;

/**
 @brief The element type radial gradient fill. "radialgradientfill"
 @discussion Made of: { line, arrayofcolors, arrayoflocations, startpoint,
 arrayofpathelements }
 Performs a gradient fill by specifying two circles with different centers and
 radii between which the gradient is interpolated. Colors are specified at
 positions between the circles and the gradient is interpolated between the
 circles.
 The drawing of the gradient is clipped to an area defined by the startpoint and
 arrayofpathelements in exactly the same way the path is defined for the path
 fill element drawing command.
*/
extern NSString *const MIJSONValueRadialGradientFill;

/**
 @brief The element type draw image. "drawimage"
 @discussion Made of: { sourceobject, destinationrectangle, [imageindex],
 [sourcerectangle], [blendmode], [transformation], [affinetransform] 
 [interpolationquality] }.
 The draw image element type action draws onto the context. The source of the
 image to draw is the object specified by the objectreference. If the source is
 a image importer then the imageindex should be specified but defaults to 0. If
 the source rectangle is not specified then it is assumed that all of the source
 image is wanted.
*/
extern NSString *const MIJSONValueDrawImage;

#pragma mark The Path related element type values.

/**
 @brief Move to a new position to start a new subpath. "pathmoveto"
 @discussion Made of: { point }. This element is required after the
 pathrectangle, pathroundedrectangle, pathoval path element types if the
 next path element type is a line, or a curve unless you want a line drawn
 from an unknown location on one the previous objects to your next position.
*/
extern NSString *const MIJSONValuePathMoveTo;

/**
 @brief The line element type that is part of a path. "pathlineto"
 @discussion Made of: { endpoint } The start point is the current point of
 the context, this could be the end point of a previous line or curve or that
 specified by "pathmoveto"
*/
extern NSString *const MIJSONValuePathLine;

/**
 @brief The bezier curve that is part of a path. "pathbeziercurve"
 @discussion Made of: { controlpoint1, controlpoint2, endpoint } The start
 point is the current point of the context, this could be the end point of a
 previous line or curve or that specified by "pathmoveto"
*/
extern NSString *const MIJSONValuePathBezierCurve;

/**
 @brief The quadratic curve that is part of a path. "pathquadraticcurve"
 @discussion Made of: { controlpoint1, endpoint } The start
 point is the current point of the context, this could be the end point of a
 previous line or curve or that specified by "pathmoveto"
*/
extern NSString *const MIJSONValuePathQuadraticCurve;

/**
 @brief A rectangle that is part of a path. "pathrectangle"
 @discussion Made of: { rect }
*/
extern NSString *const MIJSONValuePathRectangle;

/**
 @brief A rounded rectangle that is part of a path. "pathroundedrectangle"
 @discussion Made of: { rect radius|radiuses }
*/
extern NSString *const MIJSONValuePathRoundedRectangle;

/**
 @brief An oval that is part of a path. "pathoval"
 @discussion Made of: { rect }
*/
extern NSString *const MIJSONValuePathOval;

/**
 @brief An arc that is part of a path. "patharc"
 @discussion Made of: { center, radius, startangle, endangle,
 clockwise }. "center" is a point specifying the center of the circle that
 the arc is part of, "radius" is the radius of the circle, "startangle" and
 "endangle" are measured in radians and 0 is at 3 O'clock. "clockwise" is a bool
 indicating whether the arc is drawn in a clockwise or anticlockwise. Default
 is NO.
*/
extern NSString *const MIJSONValuePathArc;

/**
 @brief Add an arc to a point using tangents. "patharc"
 @discussion Made of: { radius, tangentpoint1, tangentpoint2 }. "radius" is
 the radius of the circle that that the arc is part of. "tangentpoint1" is the
 point through which the tangent line from the current point is defined. The
 point "tangentpoint2" is the end point of the arc.
*/
extern NSString *const MIJSONValuePathAddArcToPoint;

/**
 @brief Close the current sub path. "closesubpath"
 @discussion Made of: doesn't have any properties.
*/
extern NSString *const MIJSONValueCloseSubPath;

#pragma mark Geometry related keys go here.

/**
 @brief The key for representing an array of elements. "arrayofelements"
 @discussion  Made of: { array of elements, [linewidth], [linecap], [linejoin],
 [miter], [strokecolor], [fillcolor], [blendmode] }
*/
extern NSString *const MIJSONKeyArrayOfElements;

/**
 @brief The variables dictionary
 @discussion This dictionary contains properties whose keys are the variable
 names and values are numeric values that the variables are replaced with
 when the expression evaluator is called.
*/
extern NSString *const MIJSONKeyVariablesDictionary;

/// The key for representing an array of path elements. "arrayofpathelements"
extern NSString *const MIJSONKeyArrayOfPathElements;

/// The key for representing a rectangle. "rect". Made of: { origin, size }.
extern NSString *const MIJSONKeyRect;

/// The key for representing the size of a rectangle: "size". { width, height }.
extern NSString *const MIJSONKeySize;

/// The key for representing the height of size: "height". float
extern NSString *const MIJSONKeyHeight;

/// The key for representing the width of size: "width". float
extern NSString *const MIJSONKeyWidth;

/// The key for representing the origin of a rectangle: "origin". { x, y }
extern NSString *const MIJSONKeyOrigin;

/// The key for representing a point in the context: "point". { x, y }
extern NSString *const MIJSONKeyPoint;

/// The key for representing a line: "line". { startpoint, endpoint }
extern NSString *const MIJSONKeyLine;

/// The key for representing points: "points". [ array of points ]
extern NSString *const MIJSONKeyPoints;

/// The key for representing the start point: "startpoint". { x, y }
extern NSString *const MIJSONKeyStartPoint;

/// The key for representing the end point: "endpoint". { x, y }
extern NSString *const MIJSONKeyEndPoint;

/// The key for representing the centre of an arc/circle. "centerpoint". { x, y }
extern NSString *const MIJSONKeyCenterPoint;

/// The key for centre of second circle in radial grad. "centerpoint2". { x, y }
extern NSString *const MIJSONKeyCenterPoint2;

/// The key for the starting angle for an arc. "startangle". float in radians
extern NSString *const MIJSONKeyStartAngle;

/// The key for the ending angle for an arc. "endangle". float in radians
extern NSString *const MIJSONKeyEndAngle;

/// The key for whether the arc is drawn clockwise or not. "clockwise". { BOOL }
extern NSString *const MIJSONKeyDrawArcClockwise;

/// The key for the first control point of a curve: "controlpoint1". { x, y }
extern NSString *const MIJSONKeyControlPoint1;

/// The key for the second control point of a curve: "curvepoint2". { x, y }
extern NSString *const MIJSONKeyControlPoint2;

/// The key for the first tangent point used in addarctopoint "tangentpoint1".
extern NSString *const MIJSONKeyTangentPoint1;

/// The key for the second tangent point used in addarctopoint "tangentpoint1".
extern NSString *const MIJSONKeyTangentPoint2;

/// The x position in a point: "x". float
extern NSString *const MIJSONKeyX;

/// The y position in a point: "y". float
extern NSString *const MIJSONKeyY;

/// The radius of a circle: "radius". float
extern NSString *const MIJSONKeyRadius;

/// The radius of a second circle used in radial gradient. "radius2". float
extern NSString *const MIJSONKeyRadius2;

/**
 @brief Radiuses. "radiuses"
 @discussion A radius for each corner of a rounded rectangle. First corner is
 bottom right and then in the order of an anti-clockwise direction.
 Made of: { radius, radius, radius, radius }
*/
extern NSString *const MIJSONKeyRadiuses;

/**
 @brief Line cap key: "linecap". string
 @discussion One of these strings: "kCGLineCapButt", "kCGLineCapRound",
 "kCGLineCapSquare".
*/
extern NSString *const MIJSONKeyLineCap;

/**
 @brief Line join key: "linejoin". string
 @discussion One of these strings: "kCGLineJoinMiter", "kCGLineJoinRound"
 "kCGLineJoinBevel" }
*/
extern NSString *const MIJSONKeyLineJoin;

/**
 @brief Gradient drawing options key: "gradientoptions". Array of strings
 @discussion If this dictionary entry doesn't exist then it is assumed that
 the drawing of the gradient does not extend beyond the start and end circles.
 If the length of the array is zero then it is also assumed that the drawing
 does not extend beyond the start and end circles. Otherwise the drawing is
 extended depending on the values in the array. There are only two valid
 values. Unknown values will be ignored.
*/
extern NSString *const MIJSONKeyGradientDrawOptions;

/// The line width key: "linewidth" float
extern NSString *const MIJSONKeyLineWidth;

/// The miter key: "miter". float
extern NSString *const MIJSONKeyMiter;

/**
 @brief The source rectangle: "sourcerectangle". { origin, size }
 @discussion When drawing an image into a graphic context, the source rectangle
 specifies the rectangle within the source image to draw from. The source
 rectangle is specified in the coordinate system of the source image. This is
 usually top left as 0,0.
*/
extern NSString *const MIJSONKeySourceRectangle;

/**
 @brief The destination rectangle: "destinationrectangle". { origin, size }
 @discussion When drawing an image into a graphic context, the destination
 rectangle specifies the area within the destination context that the image
 will be drawn to. The destination rectangle is specified in the coordinate
 system of the destination context. (If the destination context is rotated then
 the destination rect will be treated as a bounding box).
*/
extern NSString *const MIJSONKeyDestinationRectangle;

/* Apply the alpha value to the graphics context as a whole. This key is
 duplicated as the alpha value value is one of the components of a colour.
*/
// NSString *const MIJSONKeyAlpha = @"alpha"; // { float 0..1 }

/**
 @brief The blend mode applied to the graphics context. "blendmode"
 @discussion Made of: { string } Each blend mode value is specified by a string.
 All the possible values of blend mode are specified with values like
 "kCGBlendModeNormal", "kCGBlendModeMultiply" ... etc.
*/
extern NSString *const MIJSONKeyBlendMode;

/// The interpolation quality key. "interpolationquality". Made of: { string }
extern NSString *const MIJSONKeyInterpolationQuality;

#pragma mark Context Transformation related keys and values.

/**
 @brief Context Transformation. "contexttransformation"
 @discussion Should not be applied at the same time as applying an affine
 transform. The context transformation is made up of an array of
 translation, scale, rotation actions.
 Because the order in which transformations are applied to the
 context's current transformation matrix (CTM) is important and that multiple
 transformations may need to be applied to achieve the desired final
 transformation. The order in which each transforation is specified in the
 array is important. Each element in the array is a dictionary. Each dictionary
 contains a key MIJSONKeyTransformationType which can be one of three values:
 MIJSONValueTranslation, MIJSONValueScale, MIJSONValueRotation.
*/
extern NSString *const MIJSONKeyContextTransformation;

/**
 @brief The type of transformation to be performed. "transformationtype"
 @discussion The value for the key MIJSONKeyTransformationType will be one of
 MIJSONValueTranslation, MIJSONValueScale, MIJSONValueRotation.
*/
extern NSString *const MIJSONKeyTransformationType;

/// The translate value for the MIJSONKeyTransformationType key. "translate"
extern NSString *const MIJSONValueTranslate;

/// The scale value for the MIJSONKeyTransformationType key. "scale"
extern NSString *const MIJSONValueScale;

/// The rotate value for the MIJSONKeyTransformationType key. "rotate"
extern NSString *const MIJSONValueRotate;

/// The transform value for MIJSONKeyTransformationType key. "affinetransform"
extern NSString *const MIJSONValueAffineTransform;

/// Translate the graphic context key: "translation". { x, y }
extern NSString *const MIJSONKeyTranslation;

/// Scale the graphic context key: "scale". { x, y }
extern NSString *const MIJSONKeyScale;

/// Rotate the graphic context key: "rotation". In radians. { float }
extern NSString *const MIJSONKeyRotation;

/**
 @brief Apply affine Transform. "affinetransform". { m11, m12, m21, m22, tX, tY }
 @discussion Applying the affine transform should not be done in combination
 with MIJSONKeyContextTransformation.
*/
extern NSString *const MIJSONKeyAffineTransform;

#pragma mark NSAffineTransform property keys

/// The key for representing m11 in an affine transform. "m11". { float }
extern NSString *const MIJSONKeyAffineTransformM11;

/// The key for representing m12 in an affine transform. "m12". { float }
extern NSString *const MIJSONKeyAffineTransformM12;

/// The key for representing m21 in an affine transform. "m21". { float }
extern NSString *const MIJSONKeyAffineTransformM21;

/// The key for representing m22 in an affine transform. "m22". { float }
extern NSString *const MIJSONKeyAffineTransformM22;

/// The key for representing tX in an affine transform. "tx". { float }
extern NSString *const MIJSONKeyAffineTransformtX;

/// The key for representing tX in an affine transform. "ty". { float }
extern NSString *const MIJSONKeyAffineTransformtY;

#pragma mark The Line cap constants.

/// The Butt line cap value for key: MIJSONKeyLineCap. "kCGLineCapButt"
extern NSString *const MIJSONValueLineCapButt;

/// The Round line cap value for key: MIJSONKeyLineCap. "kCGLineCapRound"
extern NSString *const MIJSONValueLineCapRound;

/// The Square line cap value for key: MIJSONKeyLineCap. "kCGLineCapSquare"
extern NSString *const MIJSONValueLineCapSquare;

#pragma mark The line join constants.

/// The Miter line join value for key: MIJSONKeyLineJoin. "kCGLineJoinMiter"
extern NSString *const MIJSONValueLineJoinMiter;

/// The Round line join value for key: MIJSONKeyLineJoin. "kCGLineJoinRound"
extern NSString *const MIJSONValueLineJoinRound;

/// The Bevel line join value for key: MIJSONKeyLineJoin. "kCGLineJoinBevel"
extern NSString *const MIJSONValueLineJoinBevel;

/**
 The draw before start gradient option for key: MIJSONKeyGradientDrawingOptions.
 value: "kCGGradientDrawsBeforeStartLocation"
*/
extern NSString *const MIJSONValueGradientDrawBeforeStart;

/**
 The draw after end gradient drawing option key: MIJSONKeyGradientDrawingOptions.
 value: "kCGGradientDrawsBeforeStartLocation"
*/
extern NSString *const MIJSONValueGradientDrawAfterEnd;

/// The even-odd rule value for key: MIJSONKeyClippingRule. "evenoddrule"
extern NSString *const MIJSONValueEvenOddClippingRule;

/// The non-zero winding number rule: MIJSONKeyClippingRule. "nonwindingrule"
extern NSString *const MIJSONValueNonWindowRule;

#pragma mark The Blend Mode constants.

/// Blend mode normal value for key: MIJSONKeyBlendMode. "kCGBlendModeNormal"
extern NSString *const MIJSONValueBlendModeNormal;

/// Blend mode multiply value for key: MIJSONKeyBlendMode."kCGBlendModeMultiply"
extern NSString *const MIJSONValueBlendModeMultiply;

/// Blend mode screen value for key: MIJSONKeyBlendMode. "kCGBlendModeScreen"
extern NSString *const MIJSONValueBlendModeScreen;

/// Blend mode overlay value for key: MIJSONKeyBlendMode. "kCGBlendModeOverlay"
extern NSString *const MIJSONValueBlendModeOverlay;

/// Blend mode darken value for key: MIJSONKeyBlendMode. "kCGBlendModeDarken"
extern NSString *const MIJSONValueBlendModeDarken;

/// Blend mode lighten value for key: MIJSONKeyBlendMode. "kCGBlendModeLighten"
extern NSString *const MIJSONValueBlendModeLighten;

/// Blend mode color dodge value for key: MIJSONKeyBlendMode. "kCGBlendModeColorDodge"
extern NSString *const MIJSONValueBlendModeColorDodge;

/// Blend mode color burn value for key: MIJSONKeyBlendMode. "kCGBlendModeColorBurn"
extern NSString *const MIJSONValueBlendModeColorBurn;

/// Blend mode soft light value for key: MIJSONKeyBlendMode. "kCGBlendModeSoftLight"
extern NSString *const MIJSONValueBlendModeSoftLight;

/// Blend mode hard light value for key: MIJSONKeyBlendMode. "kCGBlendModeHardLight"
extern NSString *const MIJSONValueBlendModeHardLight;

/// Blend mode difference value for key: MIJSONKeyBlendMode. "kCGBlendModeDifference"
extern NSString *const MIJSONValueBlendModeDifference;

/// Blend mode exclusion value for key: MIJSONKeyBlendMode. "kCGBlendModeExclusion"
extern NSString *const MIJSONValueBlendModeExclusion;

/// Blend mode hue value for key: MIJSONKeyBlendMode. "kCGBlendModeHue"
extern NSString *const MIJSONValueBlendModeHue;

/// Blend mode saturation value for key: MIJSONKeyBlendMode. "kCGBlendModeSaturation"
extern NSString *const MIJSONValueBlendModeSaturation;

/// Blend mode color value for key: MIJSONKeyBlendMode. "kCGBlendModeColor"
extern NSString *const MIJSONValueBlendModeColor;

/// Blend mode luminosity value for key: MIJSONKeyBlendMode. "kCGBlendModeLuminosity"
extern NSString *const MIJSONValueBlendModeLuminosity;

/// Blend mode clear value for key: MIJSONKeyBlendMode. "kCGBlendModeClear"
extern NSString *const MIJSONValueBlendModeClear;

/// Blend mode copy value for key: MIJSONKeyBlendMode. "kCGBlendModeCopy"
extern NSString *const MIJSONValueBlendModeCopy;

/// Blend mode source in value for key: MIJSONKeyBlendMode. "kCGBlendModeSourceIn"
extern NSString *const MIJSONValueBlendModeSourceIn;

/// Blend mode source out value for key: MIJSONKeyBlendMode. "kCGBlendModeSourceOut"
extern NSString *const MIJSONValueBlendModeSourceOut;

/// Blend mode source atop value for key: MIJSONKeyBlendMode. "kCGBlendModeSourceAtop"
extern NSString *const MIJSONValueBlendModeSourceAtop;

/// Blend mode destination over value for key: MIJSONKeyBlendMode. "kCGBlendModeDestinationOver"
extern NSString *const MIJSONValueBlendModeDestinationOver;

/// Blend mode destination in value for key: MIJSONKeyBlendMode. "kCGBlendModeDestinationIn"
extern NSString *const MIJSONValueBlendModeDestinationIn;

/// Blend mode destination out value for key: MIJSONKeyBlendMode. "kCGBlendModeDestinationOut"
extern NSString *const MIJSONValueBlendModeDestinationOut;

/// Blend mode destination atop value for key: MIJSONKeyBlendMode. "kCGBlendModeDestinationAtop"
extern NSString *const MIJSONValueBlendModeDestinationAtop;

/// Blend mode XOR value for key: MIJSONKeyBlendMode. "kCGBlendModeXOR"
extern NSString *const MIJSONValueBlendModeXOR;

/// Blend mode plus darker value for key: MIJSONKeyBlendMode. "kCGBlendModePlusDarker"
extern NSString *const MIJSONValueBlendModePlusDarker;

/// Blend mode plus lighter value for key: MIJSONKeyBlendMode. "kCGBlendModePlusLighter"
extern NSString *const MIJSONValueBlendModePlusLighter;

#pragma mark Interpolation quality values

/**
 @brief The context default interpolation quality value.
 @discussion For key: MIJSONKeyInterpolationQuality. "kCGInterpolationDefault"
*/
extern NSString *const MIJSONValueInterpolationDefault;

/**
 @brief The none interpolation quality value.
 @discussion For key: MIJSONKeyInterpolationQuality. "kCGInterpolationNone"
*/
extern NSString *const MIJSONValueInterpolationNone;

/**
 @brief The low interpolation quality value.
 @discussion For key: MIJSONKeyInterpolationQuality. "kCGInterpolationLow"
*/
extern NSString *const MIJSONValueInterpolationLow;

/**
 @brief The medium interpolation quality value.
 @discussion For key: MIJSONKeyInterpolationQuality. "kCGInterpolationMedium"
*/
extern NSString *const MIJSONValueInterpolationMedium;

/**
 @brief The high interpolation quality value.
 @discussion For key: MIJSONKeyInterpolationQuality. "kCGInterpolationHigh"
*/
extern NSString *const MIJSONValueInterpolationHigh;

#pragma mark Color related keys and values.

/**
 @brief Fill color. "fillcolor"
 @discussion The colorcolorprofilename specifies the color space. Whether
 the color space is grayscale, rgb, cmyk etc. This defines what color components
 are required. The Alpha color component which is valid in all color spaces is
 a optional value and defaults to 1.0.
 RGB color is made of: { colorcolorprofilename, red, green, blue, [alpha] }
 Grayscale color is made of: { colorcolorprofilename, gray, [alpha] }
 CMYK color is made of: { colorcolorprofilename, cyan, magenta, yellow,
 cmykblack, [alpha] }
*/
extern NSString *const MIJSONKeyFillColor;

/**
 @brief Stroke color. "strokecolor"
 @discussion The colorcolorprofilename specifies the color space. Whether
 the color space is grayscale, rgb, cmyk etc. This defines what color components
 are required. The Alpha color component which is valid in all color spaces is
 a optional value and defaults to 1.0.
 RGB color is made of: { colorcolorprofilename, red, green, blue, [alpha] }
 Grayscale color is made of: { colorcolorprofilename, gray, [alpha] }
 CMYK color is made of: { colorcolorprofilename, cyan, magenta, yellow,
 cmykblack, [alpha] }
*/
extern NSString *const MIJSONKeyStrokeColor;

/// The red component of a color. "red" { float 0.0 ... 1.0 }
extern NSString *const MIJSONKeyRed;

/// The green componenent of a color. "green". { float 0.0 ... 1.0}
extern NSString *const MIJSONKeyGreen;

/// The blue componenent of a color. "blue". { float 0.0 ... 1.0 }
extern NSString *const MIJSONKeyBlue;

/// The gray component of a color. "gray". { float 0.0 ... 1.0 }
extern NSString *const MIJSONKeyGray;

/// The alpha component of a color. Default: 1. "alpha". { float 0.0 ... 1.0 }
extern NSString *const MIJSONKeyAlpha;

/// The cyan component of a CMYK color. "cyan". { float 0.0 ... 1.0 }
extern NSString *const MIJSONKeyCyan;

/// The magenta component of a CMYK color. "magenta". { float 0.0 ... 1.0 }
extern NSString *const MIJSONKeyMagenta;

/// The yellow component of a CMYK color. "yellow". { float 0.0 ... 1.0 }
extern NSString *const MIJSONKeyYellow;

/// The black component of a CMYK color. "cmykblack". { float 0.0 ... 1.0 }
extern NSString *const MIJSONKeyCMYKBlack;

/**
 @brief The color profile name for the color. "colorcolorprofilename"
 @discussion Suitable values (from CGColorSpace.h are:
 kCGColorSpaceGenericGray, kCGColorSpaceGenericRGB, kCGColorSpaceGenericCMYK
 kCGColorSpaceGenericRGBLinear, kCGColorSpaceAdobeRGB1998, kCGColorSpaceSRGB,
 kCGColorSpaceGenericGrayGamma2_2.
*/
extern NSString *const MIJSONKeyColorColorProfileName;

/// The key representing an array of colors. "arrayofcolors"
extern NSString *const MIJSONKeyArrayOfColors;

/// The string: "stringtext". Made of: { string }
extern NSString *const MIJSONKeyStringText;

/**
 @brief The post script font name: "postscriptfontname". Made of: { string }.
 @discussion The draw string text command requires one of "postscriptfontname"
 or "userinterfacefont" to create the font to draw with.
*/
extern NSString *const MIJSONKeyStringPostscriptFontName;

/// The font size: "fontsize". Made of: { float 1.0 ... 1000.0 }.
extern NSString *const MIJSONKeyStringFontSize;

/**
 @brief The stroke width, default is zero. "stringstrokewidth"
 @discussion Negative values will mean the text is drawn as normal then the
 the text will be stroked with the absolute value of the stroke width. If this
 key is specified then you should also specify strokecolor, if not then the
 stroke color of the context will be used.
*/
extern NSString *const MMSJONKeyStringStrokeWidth;

/*
 @brief A shadow specification to use when drawing objects or text. "shadow"
 @discussion The shadow specification requires a specified shadow color which
 is specified using the fillcolor key, a blur value and an offset which
 specifies where the shadow is drawn relative to the object to be drawn.
*/
extern NSString *const MIJSONKeyShadow;

/*
 @brief A clipping specification used to clip the drawing to.
 @discussion The clipping specification defines a path defines within which to
 clip the drawing to. The specification also defines an option as to which
 rule is used to calculate the combination of the current clipping path with
 the previous. Default is the nonzero winding number rule.
*/
extern NSString *const MIJSONKeyClippingpath;

/*
 @brief Use an image as a mask. Dictionary spec for applying the image mask.
 @discussion The dictionary specification for applying an image as a mask takes
 an object dictionary from which to get the image, an optional image index
 property and a rectangle which is where the mask image will be applied. The
 image mask and the current clipping path will be blended together.
 */
extern NSString *const MIJSONKeyApplyImageMask;

/**
 @brief The shadow offset. "offset"
 @discussion The offset (a point { x, y }) defining where the shadow is drawn
 relative to the object being drawn.
*/
extern NSString *const MIJSONKeyShadowOffset;

/// The blur value. { float } specifying how much the edges to be blurred.
extern NSString *const MIJSONKeyBlur;

/// The clipping rule. { string enum } Non winding rule or the even-odd rule.
extern NSString *const MIJSONKeyClippingRule;

/**
 @brief The array of locations along a line for a gradient fill."arrayoflocations"
 @discussion The line is specified by a starting point and an end point. At
 each location along a line a color is specified and the gradient fill is
 interpolated as colors between the specified color locations along that line.
 See MIJSONKeyArrayOfColors and MIJSONValueLinearGradientFill.
*/
extern NSString *const MIJSONKeyArrayOfLocations;

#pragma mark Sytem User Interface font key and font constant values.

/**
 @brief Specify a user interface type font to draw text. "userinterfacefont"
 @discussion Instead of using the postscript font name to select the font to
 draw with we can select one of the different user interface font type to
 draw with. I'm intending this feature to help people who might want to mock
 together a UI interface quickly using smig.
*/
extern NSString *const MIJSONKeyUIFontType;

/// The user font. "kCTFontUIFontUser". For key MIJSONKeyUIFontType.
extern NSString *const MIJSONValueUIFontUser;

/// A fixed pitch font. "kCTFontUIFontUserFixedPitch".For key MIJSONKeyUIFontType
extern NSString *const MIJSONValueUIFontFixedPitch;

/// The system font. "kCTFontUIFontSystem". For key: MIJSONKeyUIFontType.
extern NSString *const MIJSONValueUIFontSystem;

/// Emphasized system font. "kCTFontUIFontEmphasizedSystem".
extern NSString *const MIJSONValueUIFontEmphasizedSystem;

/// Small system font. "kCTFontUIFontSmallSystem". For key: MIJSONKeyUIFontType
extern NSString *const MIJSONValueUIFontSmallSystem;

/// Small emphasized system font. "kCTFontUIFontSmallEmphasizedSystem"
extern NSString *const MIJSONValueUIFontSmallEmphasizedSytem;

/// Mini system font. "kCTFontUIFontMiniSystem". For key: MIJSONKeyUIFontType
extern NSString *const MIJSONValueUIFontMiniSystem;

/// Mini emphasized system font. "kCTFontUIFontMiniEmphasizedSystem".
extern NSString *const MIJSONValueUIFontMiniEmphasizedSystem;

/// Views font. "kCTFontUIFontViews". For key: MIJSONKeyUIFontType
extern NSString *const MIJSONValueUIFontViews;

/// Application font. "kCTFontUIFontApplication". For key: MIJSONKeyUIFontType
extern NSString *const MIJSONValueUIFontApplication;

/// Label font. "kCTFontUIFontLabel". For key: MIJSONKeyUIFontType
extern NSString *const MIJSONValueUIFontLabel;

/// Menu title font. "kCTFontUIFontMenuTitle". For key: MIJSONKeyUIFontType
extern NSString *const MIJSONValueUIFontMenuTitle;

/// Menu item font. "kCTFontUIFontMenuItem". For key: MIJSONKeyUIFontType
extern NSString *const MIJSONValueUIFontMenuItem;

/// Window title font. "kCTFontUIFontWindowTitle". For key: MIJSONKeyUIFontType
extern NSString *const MIJSONValueUIFontWindowTitle;

/// Push button font. "kCTFontUIFontWindowTitle". For key: MIJSONKeyUIFontType
extern NSString *const MIJSONValueUIFontPushButton;

/// System detail font. "kCTFontUIFontSystemDetail". For key: MIJSONKeyUIFontType
extern NSString *const MIJSONValueUIFontSystemDetail;

/// System emphasized detail font. "kCTFontUIFontEmphasizedSystemDetail".
extern NSString *const MIJSONValueUIFontEmphasizedSystemDetail;

/// System emphasized detail font. "kCTFontUIFontToolbar".
extern NSString *const MIJSONValueUIFontToolbar;

/// Small toolbar font. "kCTFontUIFontSmallToolbar". For key: MIJSONKeyUIFontType
extern NSString *const MIJSONValueUIFontSmallToolbar;

/// Message font. "kCTFontUIFontMessage". For key: MIJSONKeyUIFontType
extern NSString *const MIJSONValueUIFontMessage;

/// Tool tip font. "kCTFontUIFontTooTip". For key: MIJSONKeyUIFontType
extern NSString *const MIJSONValueUIFontToolTip;

/// Control content font. "kCTFontUIFontControlContent".
extern NSString *const MIJSONValueUIFontControlContent;

// Key and Values related to text alignment for paragraph attributes.

#pragma mark Text alignment key and values.

/**
 @brief Specify the text drawing alignment. "textalignment"
 @discussion The default alignment is left, other options are right,
 center, justified, natural.
*/
extern NSString *const MIJSONKeyTextAlignment;

/// Left text align. "kCTTextAlignmentLeft". For key: MIJSONKeyTextAlignment
extern NSString *const MIJSONValueTextAlignLeft;

/// Right text align. "kCTTextAlignmentRight". For key: MIJSONKeyTextAlignment
extern NSString *const MIJSONValueTextAlignRight;

/// Center text align. "kCTTextAlignmentCenter". For key: MIJSONKeyTextAlignment
extern NSString *const MIJSONValueTextAlignCenter;

/// Justified text align. "kCTTextAlignmentCenter".For key:MIJSONKeyTextAlignment
extern NSString *const MIJSONValueTextAlignJustified;

/// Natural text align. "kCTTextAlignmentNatural".For key:MIJSONKeyTextAlignment
extern NSString *const MIJSONValueTextAlignNatural;

#pragma mark - Base object identifier.

/**
 @brief The key to get a dictionary for obtaining a source object "sourceobject"
 @discussion The dictionary contains keys like MIJSONKeyObjectReference
 which are used to find the relevant object. Made of:
 { objectreference | (objecttype && objectname) | (objecttype && objectindex ) }
*/
extern NSString *const MIJSONKeySourceObject;

/**
 @brief The key to a dictionary for getting the receiver object "receiverobject"
 @discussion The dictionary contains keys like MIJSONKeyObjectReference
 which are used to find the relevant object. Made of:
 { objectreference | (objecttype && objectname) | (objecttype && objectindex ) }
*/
extern NSString *const MIJSONKeyReceiverObject;

/**
 @brief The key to get a dictionary for obtaining a secondary object. "secondaryobject"
 @discussion The dictionary can contain the same properties as the keys
 in the source object dictionary. 
*/
extern NSString *const MIJSONKeySecondaryObject;

/// A base object reference to refer to a base object. "objectreference". { int }.
extern NSString *const MIJSONKeyObjectReference;

/**
 @brief The name of a base object. "objectname"
 @discussion Used in combination with "objecttype" to find a base object.
*/
extern NSString *const MIJSONKeyObjectName;

/**
 @brief The type of a base object. "objecttype"
 @discussion Used in combination with "objectname" to find a base object.
*/
extern NSString *const MIJSONKeyObjectType;

/**
 @brief Index into the list of objects of objects belong to a type. "objectindex"
 @discussion This is the most unreliable way to find an object because as soon
 as another object of the same type has been deleted the index may change.
 Perhaps the only time to use this option is when your wanting to iterate through
 the list of objects of a particular type and get the object reference for later
 use.
*/
extern NSString *const MIJSONKeyObjectIndex;

/**
 @brief The image index key: "imageindex". int
 @discussion An index into a list of images in a "imageimporter" or a
 "imageexporter" object.
*/
extern NSString *const MIJSONKeyImageIndex;

/**
 @brief The secondary image index key: "secondaryimageindex". int
 @discussion An index into a list of images in a "imageimporter", or
 "imageexporter" object.
*/
extern NSString *const MIJSONKeySecondaryImageIndex;

/**
 @brief Copy metadata when adding an image to the exporter. "grabmetadata"
 @discussion The image exporter addimage command can optionally copy the metadata
 along with the image when getting the image from an image importer. If this
 property has a value of YES then the metadata is copied, otherwise not. If
 this option is not part of the command the default value is NO.
*/
extern NSString *const MIKSONKeyGrabMetadata;

#pragma mark - Run commands from list property keys and values.

/**
 @brief The list of commands to be run. The value is an array. "commands"
 @discussion A property key whose property value is an array of commands.
 Each command in the array is a dictionary which has properties which
 describes the command to be run.
*/
extern NSString *const MIJSONKeyCommands;

/**
 @brief The commands to run after synchronous command. "asynccompletioncommands"
 @discussion A property key whose property value is a dictionary. The dictionary
 has exactly the same structure as the dictionary for running commands.
*/
extern NSString *const MIJSONKeyAsyncCompletionCommands;

/**
 @brief Should the commands after a failed command be executed. "stoponfailure"
 @discussion A property key whose property value is "YES" or "NO". If yes then
 if the running of a command fails then don't run any further commands and
 return. Default value is YES.
*/
extern NSString *const MIJSONKeyStopOnFailure;

/**
 @brief Indicates what should be returned from running the commands. "returns"
 @discussion A property key whose property value is one of the following strings
 "lastcommandresult", "listofresults", "noresults" which indicates what should
 be returned from running the list of commands. If the commands are being run
 asychronously and the property value for this key is not "noresults" then
 the property "saveresultsto" needs to be set.
*/
extern NSString *const MIJSONKeyReturns;

/**
 @brief Should the commands be run asynchronously or not. "runasynchronously"
 @discussion A property key whose property value is "YES" or "NO" indicating
 whether the commands in the command list should be run asynchronously or not.
 Defaults to NO.
*/
extern NSString *const MIJSONKeyRunAsynchronously;

/**
 @brief Specify where the output of results of running the commands be saved to.
 @discussion  A property key whose property value is a file path which specifies
 where the results should be saved to. If the command is run async and the
 property "returns" does not have value "noresults" then this property is required.
 This is also an optional property if the command is run asynchronously. If the
 file already exists then the new content will be appended, if not the file will
 be created and then written to.
*/
extern NSString *const MIJSONKeySaveResultsTo;

/**
 @brief Specify the file type the output of results should be. "saveresultstype"
 @discussion  A property key whose property value is either "jsonfile",
 "propertyfile", "jsonstring" or, "dictionaryobject"
*/
extern NSString *const MIJSONKeySaveResultsType;

/**
 @brief The path to a file on disk where the data is obtained from. "getdatafrom"
 @discussion  A property key whose property value is a path to a file on disk.
*/
extern NSString *const MIJSONKeyGetDataFrom;

/**
 @brief Specify the file or data type the input data source is. "getdatatype"
 @discussion A property key whose property value is either "jsonfile",
 "propertyfile", "jsonstring" or, "dictionaryobject".
*/
extern NSString *const MIJSONKeyGetDataType;

/**
 @brief The data to be input. Either a json object or a dictionary. "inputdata"
 @discussion Used in the MIImageExporter object when adding metadata properties
 to the image exporter object or an image in the image exporter object.
*/
extern NSString *const MIJSONKeyInputData;

/**
 @brief A list of clean up commands. Optional. "cleanupcommands"
 @discussion 
*/
extern NSString *const MIJSONKeyCleanUpCommands;

/// The string value of yes. "YES"
extern NSString *const MIJSONValueYes;

/// The string value for no. "NO"
extern NSString *const MIJSONValueNo;

/**
 @brief Return the result of the last command only "lastcommandresult"
 @discussion Value for key MIJSONKeyReturns indicating that the result of
 the last command to be run should be returned.
*/
extern NSString *const MIJSONValueReturnLastCommand;

/**
 @brief Return the results of all commands that are run in a list. "listofresults"
 @discussion Value for key MIJSONKeyReturns indicating that the results of all
 commands should be returned in a list.
*/
extern NSString *const MIJSONValueReturnListOfResults;

/// Value for key MIJSONKeyReturns indicating don't produce output. "noresults"
extern NSString *const MIJSONValueReturnNone;

#pragma mark - Command specific property keys and values.

/**
 @brief The property key for the command to be performed. "command"
 @discussion Commands are e.g.: getproperty, create, etc. After determining what
 should handle the command the next step is to determine what is the command 
 to be performed. The value associated with this key determines what command that
 is. The values follow.
*/
extern NSString *const MIJSONKeyCommand;

/// The get property value for the MIJSONKeyCommand key. "getproperty"
extern NSString *const MIJSONValueGetPropertyCommand;

/// The get properties value for the MIJSONKeyCommand key. "getproperties"
extern NSString *const MIJSONValueGetPropertiesCommand;

/// The set property value for the MIJSONKeyCommand key. "setproperty"
extern NSString *const MIJSONValueSetPropertyCommand;

/// The set properties value for the MIJSONKeyCommand key. "setproperties"
extern NSString *const MIJSONValueSetPropertiesCommand;

/// The create value for the MIJSONKeyCommand key. "create"
extern NSString *const MIJSONValueCreateCommand;

/// The close value for the MIJSONKeyCommand key. "close"
extern NSString *const MIJSONValueCloseCommand;

/// The close all value for the MIJSONKeyCommand key. "closeall"
extern NSString *const MIJSONValueCloseAllCommand;

/// The calculate the graphic size of text command. "calculategraphicsizeoftext"
extern NSString *const MIJSONValueCalculateGraphicSizeOfTextCommand;

/// The render filter chain command. "renderfilterchain"
extern NSString *const MIJSONValueRenderFilterChainCommand;

/**
 @brief The addimage value for the MIJSONKeyCommand key. "addimage".
 @discussion The addimage command is handled by an "imageexporter" type object
 only. The addimage command takes a required option of "secondaryobject" and
 an optional option of "grabmetadata". The secondary object is the source of
 the image and "grabmetadata" indicates whether to get the metadata from the
 source at the same time. Also takes an optional secondaryimageindex.
*/
extern NSString *const MIJSONValueAddImageCommand;

/**
 @brief The export image value for the MIJSONKeyCommand key. "export".
 @discussion The export command is handled by an "imageexporter" type object
 only. The export command takes no options.
*/
extern NSString *const MIJSONValueExportCommand;

/**
 @brief The draw element value for the MIJSONKeyCommand key. "drawelement".
 @discussion The draw element command is handled by a "bitmapcontext" object.
 The command takes a dictionary describing how to draw the element.
*/
extern NSString *const MIJSONValueDrawElementCommand;

/**
 @brief The snapshot command. Handled by a bitmapcontext object. "snapshot"
 @discussion The snapshot command takes an object (bitmapcontext object)
 and an option "snapshotaction" which has one of three values: "takesnapshot",
 "drawsnapshot", "clearsnapshot". 
*/
extern NSString *const MIJSONValueSnapshotCommand;

/**
 @brief Finalize the current page in the pdf and start a new page. "finalizepage"
 @discussion When you have finished drawing to one page, and wish to start 
 drawing to the next page use this command. If you are drawing to the last page
 there is no need to close send this command as when you request that the
 pdf context base object is closed, the page will be ended, the pdf context
 document will be closed and saved to disk.
*/
extern NSString *const MIJSONValueFinalizePageCommand;

/**
 @brief The get pixel data for the MIJSONKeyCommand key. "drawelement".
 @discussion The get pixel data command is handled by a "bitmapcontext" object.
 The command takes a jsonstring defining the rectangle where to get the pixel
 data from.
*/
extern NSString *const MIJSONValueGetPixelDataCommand;

/**
 @brief The property key for the option property key. "propertykey"
 @discussion The property value for this key is the property key. Confusing
 I know, but read on. If this key is used in a getproperty command then it
 specifies the property of the class, framework or object that we want the value
 for. If this key is used with the setproperty command then it specifies the
 property to be assigned, and it also requires the MIJSONPropertyValue key
 whose value is the value to be assigned.
*/
extern NSString *const MIJSONPropertyKey;

/**
 @brief The property key for the option property value. "propertyvalue"
 @discussion The property value for this key is the property value. 
 This key is required for the setproperty command which needs to know which 
 property to set which is defined with the MIJSONPropertyKey and the value
 to be set which is the property value for this property key.
 */
extern NSString *const MIJSONPropertyValue;

/**
 @brief The property version. "version"
 @discussion A readonly property. This is a property value for property
 with key "propertykey" used in the "getproperty" command. This property is
 associated with the framework and returns the version number of the
 MovingImages framework.
 */
extern NSString *const MIJSONPropertyVersion;

/**
 @brief The property number of objects. "numberofobjects"
 @discussion A readonly property. This is a property value for property
 with key "propertykey" used in the "getproperty" command. This property is
 associated with a class or the framework and returns either the total number of
 base objects or the number of base object belong to a particular class/type.
*/
extern NSString *const MIJSONPropertyNumberOfObjects;

/**
 @brief The dictionary property key.
 @discussion If the property key starts with "dictionary" then this indicates
 that this is the beginning of a key path that makes it possible to drill down
 into a structure of dictionaries and arrays. Used for accessing image metadata.
*/
extern NSString *const MIJSONPropertyDictionary;

/**
 @brief The property number of images for the key "propertykey". "numberofimages"
 @discussion A readonly property of an imageimporter, or an imageexporter object.
 The returned value is the number of images in the object.
 */
extern NSString *const MIJSONPropertyNumberOfImages;

/**
 @brief The JSON string property. "jsonstring"
 @discussion When information is requested from MovingImages like when the
 getproperties command is called then this property value indicates that the
 information should be returned as a JSON string. The json string option can
 also be used when performing commands. For example the draw element
 command of the bitmap context object can source the draw element data from a
 string, a json file or a plist file. In that situation this property value is
 used as a property key with the value being a json string which is the draw
 data.
 */
extern NSString *const MIJSONPropertyJSONString;

/**
 @brief The JSON file path property. "jsonfile"
 @discussion When information is requested from MovingImages like when the
 getproperties command is called then this property value indicates that the
 information should be saved to a file in json format. The json file option can
 also be used when  performing commands. For example the draw element
 command of the bitmap context object can source the draw element data from a
 string, a json file or a plist file. In that situation this property value is
 used as a property key with the value being the path to the file which is the
 drawing data.
 */
extern NSString *const MIJSONPropertyJSONFilePath;

/**
 @brief The property "property file path". "propertyfile"
 @discussion When information is requested from MovingImages like when the
 getproperties command is called then this property value indicates that the
 information should be saved to a file in plist format. The plist file option can
 also be used when  performing commands. For example the draw element
 command of the bitmap context object can source the draw element data from a
 string, a json file or a plist file.  In that situation this property value is
 used as a property key with the value being the path to the file which is the
 drawing data.
 */
extern NSString *const MIJSONPropertyPropertyFilePath;

/**
 @brief The Property dictionary object. "dictionaryobject"
 @discussion Send or receive a dictionary representation of some data. The
 alternatives are a jsonstring string, a json file or a property list file.
 The dictionary object will be the most efficient of them.
 */
extern NSString *const MIJSONPropertyDictionaryObject;

/**
 @brief The property key for the option file. "file".
 @discussion The property value is a path to a file on disk. The path should NOT
 be relative to any location unless you specify the tilde character "~" in the
 path which will refer to the current users home directory.
 */
extern NSString *const MIJSONPropertyFile;

/**
 @brief The property key for the option file type. "utifiletype"
 @discussion The property value is the export file type. The values are one from
 a list of values. This list can be obtained from the image importer, or the
 image exporter types depending on whether you are after the list of possible
 image file types that can be imported or exported. To obtain the list you use
 the getproperty command. Typical values are public.jpeg, public.png,
 public.tiff, com.compuserve.gif and more.
 */
extern NSString *const MIJSONPropertyFileType;

/**
 @brief The property image exporter types. "imageexporttypes"
 @discussion A readonly property. This a a property value for property with key
 "propertykey" used in the "getproperty" command. The imageexporter class is
 the only thing that handles this property.
*/
extern NSString *const MIJSONPropertyAvailableExportTypes;

/**
 @brief The export file path. "exportfilepath"
 @discussion A readwrite property of the image export object. Partial paths
 apart from the tilde being expanded to the users home directory are not
 valid. The return value will always be a full path.
*/
extern NSString *const MIJSONPropertyExportFilePath;

/**
 @brief Is the image export object in a state it can export. "canexport"
 @discussion A readonly property of the image export object. Returns whether
 the image exporter object is in a state or not that it can export a image file.
*/
extern NSString *const MIJSONPropertyCanExport;

/**
 @brief The export compression quality. "exportcompressionquality"
 @discussion Property of the image exporter object and applies to individual
 images so the image index also needs to be specified when setting the
 compression quality. A value of 0.0 indicates minimum file size, minimum
 quality, a value of 1.0 indicates maximize image quality. Almost no difference
 between 0.9 and 1.0 in terms of image quality, but file size difference is large
 */
extern NSString *const MIJSONPropertyExportCompressionQuality;

/**
 @brief The source status. Applies to imageimporter objects. "imagesourcestatus"
 @discussion This is a status code you can get from a imageimporter object
 indicating the status of the object, or the status of attempting to get an
 image or image information for an image at index image index.
*/
extern NSString *const MIJSONPropertyImageSourceStatus;

/**
 @brief Allow created cgimages to be floating point. "allowfloatingpointimages"
 @discussion A read/write property of the image importer object. It is a BOOL
 value. If the image file format allows it, and the image data is stored as
 floating point values then the pixels for the created CGImageRef object will be
 backed by floating point values.
 */
extern NSString *const MIJSONPropertyAllowFloatingPointImages;

/**
 @brief The image source file. Applies to imageimporter objects. "sourcefilepath"
 @discussion This is the source file path that the image importer object imported
 when it was created.
*/
// extern NSString *const MIJSONPropertySourceFilePath;

/**
 @brief The image file formats that we can import. "imageimporttypes"
 @discussion Applies to the imageimporter class. Returns a space delimited list
 of uti file types that list what image formats an imageimporter object can
 import.
*/
extern NSString *const MIJSONPropertyImageImportTypes;

/**
 @brief Should an image be taken of a context after drawing to it. "createimage"
 @discussion When a context is drawn to, or has a filter chain render to the
 context this property which takes a BOOL value indicates whether a image
 should be generated as part of the command. This will save the image being
 generated on the main queue at a point when it might be time critical to draw
 the image. Default value is NO/false.
*/
extern NSString *const MIJSONPropertyCreateImage;

/**
 @brief The different possible bitmap contexts. "bitmappresets"
 @discussion Applies to the bitmapcontext class. Returns a space delimited list
 of bitmap context presets that lists the full range of available presets. The
 presets cover a range of channel bit depths, color space, float or int values
 for each channel etc..
*/
extern NSString *const MIJSONPropertyPresets;

/**
 @brief The different possible blend modes for drawing with. "bitmapblendmodes"
 @discussion Applies to the bitmapcontext class. Returns a space delimited list
 of blend modes that lists the full range of blend modes. See apple
 documentation for a description of the full range of core graphics blend modes.
 In the repository "using-movingimages" I've combined the images 
 horizontaltestpattern.png and verticaltestpattern.png using all the blend modes
 the output is in bitmapcontext/images. The source images are in
 miscellaneous/images.
*/
extern NSString *const MIJSONPropertyBlendModes;

/**
 @brief The user interface fonts to draw with. "userinterfacefonts"
 @discussion Applies to the bitmapcontext class, but the user interface fonts
 can be used to draw in a bitmapcontext, a nsgraphicscontext, or a pdf context
 object.
*/
extern NSString *const MIJSONPropertyUserInterfaceFonts;

/**
 @brief The preset used to create the bitmap context with. "preset"
 @discussion The property used when creating a bitmap context. The preset
 property of a bitmap context object can also be requested.
*/
extern NSString *const MIJSONPropertyPreset;

/**
 @brief The color profile of a bitmap context object. "colorprofile"
 @discussion When a bitmap context is created, it is created with a colorprofile.
 There is a default color profile for each preset but the profile can be
 overridden by specifying the colorprofile property and assigning a profile
 name. For a bitmap context created in the rgb color space the default profile
 is kCGColorSpaceSRGB, but this can be overridden with kCGColorSpaceGenericRGB,
 kCGColorSpaceGenericRGBLinear, kCGColorSpaceAdobeRGB1998 profile.
*/
extern NSString *const MIJSONPropertyColorProfile;

/**
 @brief The bits per component readonly property of a bitmap. "bitspercomponent"
 @discussion This returns the bit depth of each color component of a pixel in a
 bitmap context.
*/
extern NSString *const MIJSONPropertyBitsPerComponent;

/**
 @brief The bits per pixel readonly property of a bitmap object. "bitsperpixel"
 @discussion This returns the bit depth of a pixel in a bitmap context.
*/
extern NSString *const MIJSONPropertyBitsPerPixel;

/**
 @brief The bytes per row readonly property of a bitmap object."bytesperrow"
 @discussion This returns the bytes per row of a bitmap context.
*/
extern NSString *const MIJSONPropertyBytesPerRow;

/**
 @brief The color space name property of a bitmap context object. "colorspacename"
 @discussion This returns the colorspace name of the bitmap context.
*/
extern NSString *const MIJSONPropertyColorSpaceName;

/**
 @brief The bitmap & alpha info of a bitmap context object. "alphaandbitmapinfo"
 @discussion This returns the bitmap info and alpha info of the bitmap context.
*/
extern NSString *const MIJSONPropertyAlphaAndBitmapInfo;

/**
 @brief The drawing instructions for the draw element command. "drawinstructions"
 @discussion The value for this key is a dictionary describing what and how
 to draw. Handled by the bitmap context.
*/
extern NSString *const MIJSONPropertyDrawInstructions;

/**
 @brief The snap shot action to take. "snapshotaction"
 @discussion The value for this key is a string with one of three values.
 "takesnapshot", "drawsnapshot", or "clearsnapshot". This is an option of the
 snapshot command which is handled by the bitmapcontext object.
*/
extern NSString *const MIJSONPropertySnapshotAction;

/**
 @brief The take snap shot action. "takesnapshot"
 @discussion This is the take snap shot value for the snap shot action property.
 If the snapshotaction property has this value set as part of the snapshot
 command then a snapshot of the receiver bitmap context will be taken.
*/
extern NSString *const MIJSONValueTakeSnapshot;

/**
 @brief The draw snap shot action. "drawsnapshot"
 @discussion This is the draw snap shot value for the snap shot action property.
 If the snapshotaction property has this value set as part of the snapshot
 command then a previously taken snapshot of the bitmap context will be drawn
 back into the bitmap context. The whole of the bitmap context is redrawn and
 done so using the copy blend mode.
*/
extern NSString *const MIJSONValueDrawSnapshot;

/**
 @brief The clear snap shot action. "clearsnapshot"
 @discussion This is the clear snap shot value for the snap shot action property.
 If the snapshotaction property has this value set as part of the snapshot
 command then a previously taken snap shot will be cleared. This is basically
 just to help keep memory usage down but the snapshot will be automatically
 scrubbed when the bitmapcontext object is deallocated.
*/
extern NSString *const MIJSONValueClearSnapshot;

/**
 @brief The list of image filters readonly property. "imagefilters"
 @discussion This property is handled by the core image class only. The return
 value for requesting this property is a list of the available core image filters.
*/
extern NSString *const MIJSONPropertyImageFilters;

/**
 @brief The location and size of the window on screen. "windowrectangle"
 @discussion The initial location and size of the window when creating the
 window and the property to use to resize/move the window.
*/
extern NSString *const MIJSONPropertyWindowRectangle;

/**
 @brief Should the created window be borderless. "borderlesswindow" YES/NO
 @discussion When creating a nsgraphicscontext base object, should the
 associated window be borderless or not. YES means borderless.
*/
extern NSString *const MIJSONPropertyBorderlessWindow;

/**
 @brief The filter category to get core image filter list from. "filtercategory"
 @discussion When requesting the list of image filters property you can limit
 the list of filters returned to those belonging to the category specified by
 this property. This is an optional property of the getproperty command
 dictionary when requesting filters from the core image class.
*/
extern NSString *const MIJSONPropertyFilterCategory;

/**
 @brief Attributes of a image filter readonly property. "imagefilterattributes"
 @discussion Every core image filter has a collection of attributes that are
 needed for setting up the filter to work as desired. The property value returned
 for this property key is a description of the filter attributes. Min/Max values,
 default value, identity value, value type etc. The results for this property can
 be returned as a jsonstring, or to a property list or json file, but defaults to
 returning a jsonstring.
 */
extern NSString *const MIJSONPropertyImageFilterAttributes;

/**
 @brief The dictionary describing the image filter chain. "imagefilterchaindict"
 @discussion The property value is a dictionary that contains all the information
 for creating the image filter chain. It contains properties like the render
 destination, a list of the filters in the filter chain, whether the rendering
 should happen using the srgb color profile, and whether the rendering should
 be done in software instead of on the GPU.
*/
extern NSString *const MIJSONPropertyImageFilterChain;

/**
 @brief The dictionary containing optional properties. "renderinstructions"
 @discussion When rendering the filter chain to the render destination, it
 is possible to modify properties of the filters in the filter chain, and it
 is possible to specify the source rectangle to crop the source image, and
 to specify the destination rectangle within the context of the object drawing
 in. The render instructions contains this information. If the current filter
 properties are correct and the default source and destination rectangles are
 correct then this dictionary is not needed.
*/
extern NSString *const MIJSONPropertyRenderInstructions;

/**
 @brief The filter name option when requesting filter attributes. "filtername"
 @discussion The image filter attributes property needs to know which filter
 you want to know the attributes of. You specify the filter name using this
 option key and assigning to the value the filter name itself.
*/
extern NSString *const MIJSONPropertyImageFilterName;

/**
 @brief Should the core image filter chain do a software render. "softwarerender"
 @discussion When rendering the core image filter chain, the filter chain can
 be rendered in software or rendered on the GPU. This is a readwrite property
 of the imagefilterchain object.
*/
extern NSString *const MIJSONPropertySoftwareRender;

/// Is core image filter chain rendering in srgb space. "use_srgbcolorspace"
extern NSString *const MIJSONPropertyUseSRGBColorSpace;