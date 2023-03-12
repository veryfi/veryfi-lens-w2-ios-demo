# Installing VeryfiLens.xcframework

1. Drag and drop VeryfiLens.framework into your solution.

2. Go to Target > General, then under "Embedded Binaries" add VeryfiLens.framework by pressing "+"

3. Add the following to your app's plist:

```
<key>NSCameraUsageDescription</key>
<string>Scan Documents</string>
<key>NSLocationAlwaysAndWhenInUseUsageDescription</key>
<string>Helps to identify places around you</string>
<key>NSLocationWhenInUseUsageDescription</key>
<string>Helps to identify places around you</string>
<key>NSPhotoLibraryAddUsageDescription</key>
<string>Access Photo Gallery for Document Backups</string>
<key>NSPhotoLibraryUsageDescription</key>
<string>Access Photo Gallery for Document Uploads</string>
<key>NSContactsUsageDescription</key>
<string>Add your ___@veryfi.cc assigned email address for reference</string>
<key>NSCalendarsUsageDescription</key>
<string>Enrich your data with Calendar business meetings and events</string>
```

4. Review the sample code provided in _Scanner Demo/ViewController.swift_ to learn how to instantiate the _Camera_ and _Wombat_.
_Camera_ is the UI/UX experience and _Wombat_ is the uploader.



# Run VeryfiLens.xcframework on simulator
1. Using Cocoapods:
    - Add pod 'AWSS3' to your Podfile
    - Run `pod install`
2. Not using Cocopods
    - Drag and drop AWSCore.framework and AWSS3.framework into your solution.
    - Inside your _Target_ > _General_, under "Embedded Binaries" add them by pressing "+"


# How to Prep your Solution for iTunes

### 1. YOUR TARGET BUILD SETTINGS

- Enable Bitcode —> NO
- Always Embed Swift Standard libraries —> NO

### 2. YOUR TARGET BUILD PHASES

- Make sure VeryfiLens.xcframework is listed in “Embedded Frameworks”


# How to use the VeryfiLens.xcframework

## Email Support

Send all bugs and enquiries to:

**support@veryfi.com**

- Support goes to Veryfi's intercom which is staffed 24x7 and generates ticket # so it can be traced back

- Make sure the from email address is your company's domain. We have rules set up to route communications to the appropriate people

**Inside the email include:**

1. What the problem is and what the expected outcome should be

2. Steps to replicate it and/or

3. Include a video to eliminate bottlenecks in communication

## Emergencies Only

- Ernest's cell #: +1 (650) 450-8033

- Dmitry's cell #: +1 (650) 450-7746
