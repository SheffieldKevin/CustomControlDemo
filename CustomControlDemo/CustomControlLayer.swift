//  CustomControlLayer.swift
//  CustomControlDemo
//
//  Copyright (c) 2015 Zukini Ltd.

import UIKit
import MovingImagesiOS

class CustomControlLayer: CALayer {
    weak var numericDial: CustomDial?
    let simpleRenderer: MISimpleRenderer = MISimpleRenderer()
    let drawDict: [String:AnyObject]!
    
    init(drawDictionary: [String : AnyObject]) {
        self.drawDict = drawDictionary
        super.init()
    }
    
    required init(coder aDecoder: NSCoder) {
        self.drawDict = aDecoder.decodeObjectForKey("draw_dictionary") as!
            [String : AnyObject]
        super.init(coder: aDecoder)
    }
    
    override func drawInContext(ctx: CGContext!) {
        if let theDial = numericDial {
            CGContextSaveGState(ctx)
            CGContextTranslateCTM(ctx, 0.0, theDial.bounds.size.height)
            CGContextScaleCTM(ctx, 1.0, -1.0);
            let currentVal:NSNumber = NSNumber(
                double: Double(theDial.currentValue))
            let controlText = NSString(format: "%1.3f", currentVal.floatValue)
            let variables = [
                "controlValue" : currentVal,
                "controltext" : controlText
            ]
            self.simpleRenderer.variables = variables
            self.simpleRenderer.drawDictionary(self.drawDict, intoCGContext: ctx)
            CGContextRestoreGState(ctx)
        }
    }
}
