//
//  CustomControlLayer.swift
//  CustomControlDemo
//
//  Created by Kevin Meaney on 06/11/2014.
//  Copyright (c) 2014 Kevin Meaney. All rights reserved.
//

import UIKit
import MovingImagesiOS

class CustomControlLayer: CALayer {
    weak var numericDial: CustomDial?
    let simpleRenderer: MISimpleRenderer

    init(drawDictionary: [String : AnyObject]) {
        self.simpleRenderer = MISimpleRenderer(drawDictionary: drawDictionary)
        super.init()
    }

    required init(coder aDecoder: NSCoder) {
        let dict = aDecoder.decodeObjectForKey("draw_dictionary") as NSDictionary
        self.simpleRenderer = MISimpleRenderer(drawDictionary: dict)
        super.init(coder: aDecoder)
    }

    override func drawInContext(ctx: CGContext!) {
        if let theDial = numericDial? {
            CGContextSaveGState(ctx)
            CGContextTranslateCTM(ctx, 0.0, theDial.bounds.size.height)
            CGContextScaleCTM(ctx, 1.0, -1.0);
            let currentVal:NSNumber = NSNumber(
                                        double: Double(theDial.currentValue))
            let controlText = NSString(format: "%1.3f", currentVal.floatValue)
            let variables:NSDictionary = ["controlValue":currentVal,
                                          "controltext":controlText]
            self.simpleRenderer.variables = variables
            self.simpleRenderer.drawIntoCGContext(ctx)
            CGContextRestoreGState(ctx)
        }
    }
}
