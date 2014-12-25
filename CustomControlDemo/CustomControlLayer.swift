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
    let jsonResource: String?

    private func _doinit() {
        if let theJsonFile = self.jsonResource {
            let mainBundle = NSBundle.mainBundle();
            let jsonURL = mainBundle.URLForResource(theJsonFile,
                withExtension: "json")
            let inStream = NSInputStream(URL: jsonURL!)!
            inStream.open()
            let container:AnyObject = NSJSONSerialization.JSONObjectWithStream(
                        inStream,
                options:NSJSONReadingOptions(rawValue:0),
                  error:nil)!
            let drawDict:NSDictionary = container as NSDictionary
            self.simpleRenderer.setDrawDictionary(drawDict)
        }
    }
    
    init(jsonResource:String) {
        self.simpleRenderer = MISimpleRenderer(MIContext: MIContext())
        self.jsonResource = jsonResource
        super.init()
        self._doinit()
    }
    
    required init(coder aDecoder: NSCoder) {
        self.simpleRenderer = MISimpleRenderer(MIContext: MIContext())
        self.jsonResource = aDecoder.decodeObjectForKey("json_resource") as String?
        super.init(coder: aDecoder)
        self._doinit()
    }

    override func drawInContext(ctx: CGContext!) {
        if let theDial = numericDial? {
            CGContextSaveGState(ctx)
            CGContextTranslateCTM(ctx, 0.0, theDial.bounds.size.height)
            CGContextScaleCTM(ctx, 1.0, -1.0);
            let currentVal:NSNumber = NSNumber(double: Double(theDial.currentValue))
            let controlText = NSString(format: "%1.3f", currentVal.floatValue)
            let variables:NSDictionary = ["controlValue":currentVal,
                                          "controltext":controlText]
            self.simpleRenderer.variables = variables
            self.simpleRenderer.drawIntoCGContext(ctx, isFlipped: false)
            CGContextRestoreGState(ctx)
        }
    }
}
