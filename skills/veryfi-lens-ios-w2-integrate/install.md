# Install

W2 UI binary. No dedicated SPM repo. Client settings type: `VeryfiLensSettings()`. Do not use `VeryfiLensW2Settings`. Cloud extraction. `w2` is not an `.inApp` type.

The page-detector type list used by Remote Models includes `w2` along with receipts and bank statements. That list is compiled for Remote Models. This flavor is a separate binary. The exact bundled model filename is **Unconfirmed**.

## Artifact and import

| | |
|--|--|
| Pod | `VeryfiLens-W2` |
| CocoaPods repo | `veryfi-lens-cocoapods-w2` |
| Dedicated SPM | **No** |
| XCFramework file name | `VeryfiLens.xcframework` |
| Swift import | `VeryfiLens` |

```swift
import VeryfiLens
```



## Swift Package Manager

No dedicated SPM repo is published for this flavor. `supportsSPM` does not include it. Do not add `https://repo.veryfi.com/shared/lens/veryfi-lens-spm.git`. That URL is the Full UI binary.

Install with CocoaPods or by embedding the XCFramework Veryfi supplied for this flavor.


## CocoaPods

Public docs call CocoaPods deprecated and prefer SPM where a package exists. CocoaPods remains the pipeline path for this flavor.

```ruby
source 'https://repo.veryfi.com/shared/lens/veryfi-lens-podspec.git'
source 'https://github.com/CocoaPods/Specs.git'

target 'YourApp' do
  use_frameworks!
  pod 'VeryfiLens-W2'
end
```

Public pages pin a version with `pod 'VeryfiLens-W2', 'x.x.x.x', :linkage => :dynamic`. The current version number is **Unconfirmed** here. Use the version Veryfi gave the customer.


## Manual XCFramework

Embed `VeryfiLens.xcframework`. The pod name selects the flavor. Embedding a Full `VeryfiLens.xcframework` does not turn it into this product.

## Permissions

| Key | When |
|-----|------|
| `NSCameraUsageDescription` | Camera |
| `NSPhotoLibraryUsageDescription` | Gallery is on in this recipe |
| `NSPhotoLibraryAddUsageDescription` | Only if gallery backup is on. This recipe sets it false |
| `NSLocationWhenInUseUsageDescription` | Only if location is on. This recipe sets it false |

Do not add Contacts or Calendar usage strings unless product confirms those features ship in this flavor. The legacy framework README lists them. That list is **Unconfirmed** and likely stale.

iOS 13+ for UIKit Lens. SwiftUI helpers are documented as iOS 15+.

## App size

When installed size matters, recommend the **Remote Models** flavor. A specific flavor embeds its models in the binary. Remote Models keeps that binary smaller and downloads most of the heavy model resources after install, only for the features the host turned on.

Bank-check TIFF follows that split. `retrieveCheckTiffIsOn` is not supported on the Checks-specific flavor yet, because the TIFF model is large. Remote Models downloads it after install.

Measure the final build product, once with this Veryfi Lens SDK linked and once without it. The distributed XCFramework is a fat artifact that includes every architecture and platform slice. That file size is not the size added to the installed app. Store delivery can shrink the download further.

Flavor tables and the artifact-versus-app explanation: [SDK binary sizes](https://docs.veryfi.com/lens/mobile/settings/sdk_binary_sizes/).


## Public installation page

Public installation URL was not fetched. **Unconfirmed** docs page. Pod name is `VeryfiLens-W2`. Do not install `veryfi-lens-spm`.

## Optional local evidence

These paths are evidence from the Veryfi Lens iOS source tree. They are not part of this skill pack. Ignore them when this folder is the only checkout. Nothing in the integration depends on opening them.

- `fastlane/swift/FastlaneSwiftRunner/SPM.swift — repo names and XCFramework file names`
- `fastlane/swift/FastlaneSwiftRunner/Pipeline.swift — supportsSPM and supportsCocoaPods`
- `fastlane/swift/FastlaneSwiftRunner/Cocoapods.swift — pod repos and XCFramework file names`
- `fastlane/swift/FastlaneSwiftRunner/Builder.swift — FrameworkType raw values (pod names)`
- `Veryfi-Lens/Public/VeryfiLens.swift — UI entry point compiled into this module`
- `Veryfi-Lens/Public/Model/VeryfiLensSettings.swift — public UI settings`
- `VeryfiLensEngine/Shared/Models/DocumentType.swift — w2`
- `Veryfi-Lens/Helpers/RemoteModels/RemoteModelConditions.swift — page-detector type list, Remote Models compile`
- `Veryfi-Lens/Public/Model/VeryfiLensSettings.swift — packageMaxScans default 10`
