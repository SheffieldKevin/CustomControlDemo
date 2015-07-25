//
//  CustomControlDemoTests.swift
//  CustomControlDemoTests
//
//  Created by Kevin Meaney on 06/11/2014.
//  Copyright (c) 2014 Kevin Meaney. All rights reserved.
//

import UIKit
import CoreGraphics
import ImageIO
import XCTest

class CustomControlDemoTests: XCTestCase {
    //    let testBundle = NSBundle(forClass: CustomControlDemoTests.self)
    let movieURL = NSBundle(
        forClass: CustomControlDemoTests.self).URLForResource("410_clip4",
            withExtension:"mov")!
    override func setUp() {
        super.setUp()
    }
    
    override func tearDown() {
        super.tearDown()
    }
}
