//
//  ViewController.swift
//  CustomControlDemo
//
//  Created by Kevin Meaney on 06/11/2014.
//  Copyright (c) 2014 Kevin Meaney. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    let jsonRenderer = CustomDial(frame: CGRectZero)
    var sliderControl:UISlider = UISlider(frame: CGRectZero)

    override func viewDidLoad() {
        super.viewDidLoad()
        view.addSubview(jsonRenderer)
        view.addSubview(sliderControl)
        sliderControl.addTarget(self, action: "controlValueChanged:",
                                forControlEvents: .ValueChanged)
        jsonRenderer.addTarget(self, action: "controlValueChanged:",
                                forControlEvents: .ValueChanged)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    func controlValueChanged(control: UIControl) {
        if let slider = control as? UISlider {
            // println("Range slider value changed: \(slider.value)")
            jsonRenderer.currentValue = CGFloat(slider.value)
            jsonRenderer.drawTrack()
        }
        else if let customDial = control as? CustomDial {
            // println("Custom dial value changed: \(customDial.currentValue)")
            sliderControl.value = Float(customDial.currentValue)
            jsonRenderer.drawTrack()
        }
    }

    override func viewDidLayoutSubviews() {
        self.jsonRenderer.frame = CGRect(x: 20, y: 20, width: 200, height: 200)
        self.sliderControl.frame = CGRect(x: 20, y: 240, width: 200, height: 20)
        jsonRenderer.currentValue = CGFloat(self.sliderControl.value)
        jsonRenderer.drawTrack()
    }
}
