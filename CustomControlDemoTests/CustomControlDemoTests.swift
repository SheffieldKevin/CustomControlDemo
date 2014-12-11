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
    let movieURL = NSBundle(forClass: CustomControlDemoTests.self).URLForResource("410_clip4", withExtension:"mov")!
    override func setUp() {
        super.setUp()
        // Put setup code here. This method is called before the invocation of each test method in the class.
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }

/*
    func functionToTestPerformance(#movieAsset:AVURLAsset, index:Int) -> Void {
        let generator = AVAssetImageGenerator(asset: movieAsset)
        var actualTime:CMTime = CMTimeMake(0, 600)
        let image = generator.copyCGImageAtTime(
            CMTimeMake(index * 600 + 30, 600),
            actualTime: &actualTime, error: nil)
        //        println("Test2: width: \(CGImageGetWidth(image))")
    }
    
    func testAVAssetImageGeneratorPerformanc2() {
        let options = [
            AVURLAssetPreferPreciseDurationAndTimingKey: true,
            AVURLAssetReferenceRestrictionsKey:
                AVAssetReferenceRestrictions.RestrictionForbidNone.rawValue
        ]
        
        let asset = AVURLAsset(URL: movieURL, options: options)!
        self.measureBlock() {
            for i in 0..<10 {
                self.functionToTestPerformance(movieAsset: asset, index: i)
            }
        }
    }

    func testAVAssetImageGeneratorPerformance1() {
        let options = [
            AVURLAssetPreferPreciseDurationAndTimingKey: true,
            AVURLAssetReferenceRestrictionsKey:
                AVAssetReferenceRestrictions.RestrictionForbidNone.rawValue
        ]
        
        let asset = AVURLAsset(URL: movieURL, options: options)!
        self.measureBlock() {
            let generator = AVAssetImageGenerator(asset: asset)
            var actualTime:CMTime = CMTimeMake(0, 600)
            for i in 0..<10 {
                let image = generator.copyCGImageAtTime(
                    CMTimeMake(i * 600 + 30, 600),
                    actualTime: &actualTime, error: nil)
                //                println("Test1: width: \(CGImageGetWidth(image))")
            }
        }
    }
*/
/*
    func testReadingThumbnailImageFilePerformance() {
        let testBundle = NSBundle(forClass: CustomControlDemoTests.self)
        let imageName = "DSCN0336"
        let jpegURL = testBundle.URLForResource(imageName, withExtension:"JPG")!
        let imageSource = CGImageSourceCreateWithURL(jpegURL, nil)!
        let thumbnailOptions = [
            String(kCGImageSourceThumbnailMaxPixelSize): 2272,
            String(kCGImageSourceCreateThumbnailFromImageIfAbsent): true
        ]
        
        
        let theContext = CGBitmapContextCreate(nil, 2272, 1704, 8, 4 * 2272,
            CGColorSpaceCreateDeviceRGB(), CGBitmapInfo(2))
        let theRect = CGRectMake(0.0, 0.0, 2272.0, 1704.0)
        let tnCGImage = CGImageSourceCreateThumbnailAtIndex(imageSource,
            0, thumbnailOptions)
        self.measureBlock() {
            let tnCGImage = CGImageSourceCreateThumbnailAtIndex(imageSource,
                0, thumbnailOptions)
            //            CGContextDrawImage(theContext, theRect, tnCGImage)
        }
    }
    
    func testReadingImageFilePerformance() {
        let testBundle = NSBundle(forClass: CustomControlDemoTests.self)
        let imageName = "DSCN0336"
        let jpegURL = testBundle.URLForResource(imageName, withExtension:"JPG")!
        let imageSource = CGImageSourceCreateWithURL(jpegURL, nil)!
        let options = [
            String(kCGImageSourceShouldCache): true
        ]
        
        if let theContext = CGBitmapContextCreate(nil, 2272, 1704, 8, 2272 * 4,
            CGColorSpaceCreateDeviceRGB(), CGBitmapInfo(2)) {
            let theRect = CGRectMake(0.0, 0.0, 21600.0, 10800.0)
            self.measureBlock() {
                let cGImage = CGImageSourceCreateImageAtIndex(imageSource,
                    0, options)
                CGContextDrawImage(theContext, theRect, cGImage)
            }
        }
    }
*/
    /*
    func testUsingCGImageSourceCreateThumbnailAtIndex() -> Void {
        let testBundle = NSBundle(forClass: CustomControlDemoTests.self)
        let jpegWideFileURL = testBundle.URLForResource("world.topo.200402.3x21600x10800",
            withExtension:"jpg")!
        let jpegSquareFileURL = testBundle.URLForResource("VIIRS_3Feb2012_lrg",
            withExtension: "jpg")
        
        if let imageSource = CGImageSourceCreateWithURL(jpegWideFileURL, nil) {
            let thumbnailOptions = [
                String(kCGImageSourceThumbnailMaxPixelSize): 21600.0,
                String(kCGImageSourceCreateThumbnailFromImageIfAbsent): true,
            ]

//          if let tnCGImage = CGImageSourceCreateThumbnailAtIndex(imageSource, 0, thumbnailOptions) {
//              println("World topo. Thumbnail image width: \(CGImageGetWidth(tnCGImage))")
//                println("World topo. Thumbnail image height: \(CGImageGetHeight(tnCGImage))")
//          } else {
//                println("Could not create thumbnail image.")
//          }

            let imageOptions = [
                String(kCGImageSourceShouldCache): true
            ]

            if let cgImage:CGImageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, imageOptions) {
                println("World topo. Image width: \(CGImageGetWidth(cgImage))")
                println("World topo. Image height: \(CGImageGetHeight(cgImage))")
            } else {
                println("Could not create image.")
            }
        }

        let jpegSmallFileURL = testBundle.URLForResource("DSCN0336",
            withExtension: "JPG")
        if let imageSourceSmall = CGImageSourceCreateWithURL(jpegSmallFileURL, nil) {
            let thumbnailOptions = [
                String(kCGImageSourceThumbnailMaxPixelSize): 2272.0,
                String(kCGImageSourceCreateThumbnailFromImageAlways): true,
            ]
            let tnCGImage = CGImageSourceCreateThumbnailAtIndex(imageSourceSmall,
                0, thumbnailOptions)
            println("DSCN0336: Thumbnail image width: \(CGImageGetWidth(tnCGImage))")
            println("DSCN0336: Thumbnail image height: \(CGImageGetHeight(tnCGImage))")
            
            let imageOptions = [
                String(kCGImageSourceShouldCache): true
            ]
            let cgImage:CGImageRef = CGImageSourceCreateImageAtIndex(imageSourceSmall,
                0, imageOptions)
            println("DSCN0336: Image width: \(CGImageGetWidth(cgImage))")
            println("DSCN0336: Image height: \(CGImageGetHeight(cgImage))")
        }

    }
*/
}
