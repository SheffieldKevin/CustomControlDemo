//  CustomDial.swift
//  CustomControlDemo
//
//  Created by Kevin Meaney on 06/11/2014.
//  Copyright (c) 2014 Kevin Meaney. All rights reserved.

import UIKit

class CustomDial: UIControl {
    var currentValue = CGFloat(0.5)
    let minimumValue = CGFloat(0.0)
    let maximimValue = CGFloat(1.0)

    let customControlLayer: CustomControlLayer
    
    class func dictionaryFromJSONResource(jsonResource: String) ->
                                                        [String : AnyObject]? {
        let mainBundle = NSBundle.mainBundle();
        let jsonURL = mainBundle.URLForResource(jsonResource,
            withExtension: "json")
        let inStream = NSInputStream(URL: jsonURL!)!
        inStream.open()
        let container:AnyObject? = NSJSONSerialization.JSONObjectWithStream(
                                        inStream,
                                options:NSJSONReadingOptions(rawValue:0),
                                  error:nil)
        if let theContainer: AnyObject = container {
            return container as? [String : AnyObject]
        }
        else
        {
            return Optional.None
        }
    }

    override init(frame: CGRect) {
        let drawDict = CustomDial.dictionaryFromJSONResource("drawarc")!
        self.customControlLayer = CustomControlLayer(drawDictionary: drawDict)
        super.init(frame: frame)
        self.customControlLayer.numericDial = self
        self.customControlLayer.contentsScale = UIScreen.mainScreen().scale
        self.layer.addSublayer(customControlLayer)
        
        drawTrack()
    }
    
    required init(coder: NSCoder) {
        let drawDict = CustomDial.dictionaryFromJSONResource("drawarc")!
        self.customControlLayer = CustomControlLayer(drawDictionary: drawDict)
        super.init(coder: coder)
        self.customControlLayer.numericDial = self
        self.customControlLayer.contentsScale = UIScreen.mainScreen().scale
        self.layer.addSublayer(customControlLayer)
        
        drawTrack()
    }

    func drawTrack() {
        CATransaction.begin()
        CATransaction.setDisableActions(true)
        customControlLayer.frame = bounds
        customControlLayer.setNeedsDisplay()
        CATransaction.commit()
    }

    override func beginTrackingWithTouch(touch: UITouch,
                               withEvent event: UIEvent) -> Bool
    {
        setCurrentValueFromLocation(touch.locationInView(self))
        return true
    }
    
    override func continueTrackingWithTouch(touch: UITouch,
                                  withEvent event: UIEvent) -> Bool
    {
        setCurrentValueFromLocation(touch.locationInView(self))
        return true
    }
    
    private func currentValueFromLocation(location: CGPoint) -> CGFloat?
    {
        if !self.bounds.contains(location) {
            // If current location is not within bounds of control then exit
            return Optional.None
        }

        // The order that the parameters that are being passed into atan2 are
        // reversed. Plus I'm negating the y value. I want the angle
        // equal to zero to point upwards and the rotation direction to be
        // clockwise. These two changes produces the desired result.
        //
        // This is made even more complicated because atan2 takes y as the
        // first value, and x as the second. For more info about atan2 type
        // man atan2 in the terminal.
        let angle = CGFloat(atan2(location.x - (frame.width / 2),
                                  (frame.height / 2) - location.y))
        
        var value = angle * 2.0 / (3.0 * CGFloat(M_PI)) + 0.5
        value = max(self.minimumValue, min(self.maximimValue, value))
        return value
    }

    private func setCurrentValueFromLocation(location : CGPoint) {
        if let theValue = self.currentValueFromLocation(location) {
            self.currentValue = theValue
            sendActionsForControlEvents(.ValueChanged)
            drawTrack()
        }
    }
}
