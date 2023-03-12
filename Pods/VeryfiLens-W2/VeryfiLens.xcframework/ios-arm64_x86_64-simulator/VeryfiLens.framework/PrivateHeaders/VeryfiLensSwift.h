//
//  VeryfiLensSwiftHeaders.h
//  Veryfi-Lens
//
//  Created by Alex Levnikov on 3.06.21.
//  Copyright © 2021 Veryfi. All rights reserved.
//

#ifndef VeryfiLensSwiftHeaders_h
#define VeryfiLensSwiftHeaders_h

#import <VeryfiLens/VeryfiLens-Swift.h>
#import "VeryfiLensSwift.h"
#import "AWSS3/AWSS3.h"
#import "CoreLocation/CoreLocation.h"

#pragma mark -
#pragma mark - ReachabilityHelper

@protocol Credentials;

SWIFT_CLASS("ReachabilityHelper")
@interface ReachabilityHelper : NSObject<Reachable>
@end

#pragma mark -
#pragma mark - Region

SWIFT_CLASS("Region")
@interface Region : NSObject<NSSecureCoding>
@property (nonatomic) NSString * _Nullable bucketName;
@property (nonatomic) NSString * _Nullable bucketRegion;
@property (nonatomic) NSString * _Nullable bucket;
@property (nonatomic) NSString * _Nullable poolRegion;
@property (nonatomic) NSNumber * _Nullable lat;
@property (nonatomic) NSNumber * _Nullable lng;
@property (nonatomic) NSString * _Nullable poolId;
@property (nonatomic) NSString * _Nullable folder;
@property (nonatomic) NSString * _Nullable logBucket;
@property (nonatomic) NSString * _Nullable logBucketRegion;
@property (nonatomic) CLLocation * _Nullable location;

- (instancetype _Nonnull )initWithBucketName: (NSString * _Nullable) bucketName
                      bucketRegion: (NSString * _Nullable) bucketRegion
                            bucket: (NSString * _Nullable) bucket
                        poolRegion: (NSString * _Nullable) poolRegion
                               lat: (NSNumber * _Nullable) lat
                               lng: (NSNumber * _Nullable) lng
                            poolId: (NSString * _Nullable) poolId
                            folder: (NSString * _Nullable) folder
                         logBucket: (NSString * _Nullable) logBucket
                   logBucketRegion: (NSString * _Nullable) logBucketRegion;

- (instancetype _Nonnull )initWithJson: (NSDictionary * _Nonnull) json;

- (BOOL)isEqualToRegion: (Region * _Nullable)region;
@end

#pragma mark -
#pragma mark - ScanSettings

SWIFT_CLASS("ScanSettings")
@interface ScanSettings : NSObject
@property (nonatomic) BOOL borderDetection;
@property (nonatomic) NSNumber * _Nullable  imageRotation;
@property (nonatomic) NSString * _Nullable deviceOrientation;

- (instancetype _Nullable)initWithBorderDetection:(BOOL)borderDetection
                          imageRotation:(NSNumber * _Nullable)imageRotation
                      deviceOrientation:(NSString * _Nullable)deviceOrientation;
- (NSDictionary *_Nonnull)dictionary;
@end

#pragma mark -
#pragma mark - Constants

SWIFT_CLASS("Constants")
@interface Constants : NSObject
+ (NSString * _Nonnull) PackageCounterTimeStamp;
+ (NSString * _Nonnull) PackageCounterPackageIDs;

+ (NSString * _Nonnull) WebsiteURL;
+ (NSString * _Nonnull) LensWebsiteURL;

+ (NSString * _Nonnull) GreenColorHEX;
+ (NSString * _Nonnull) PurpleColorHEX;
+ (NSString * _Nonnull) BlueColorHEX;

+ (NSString * _Nonnull) ReceiptsEndpoint;
+ (NSString * _Nonnull) DocumentsEndpoint;
+ (NSString * _Nonnull) DocumentReadyEndpoint;
+ (NSString * _Nonnull) ValidateEndpoint;
+ (NSString * _Nonnull) BizCardsEndpoint;

+ (NSString * _Nonnull) PartnerDocumentsEndpoint;
+ (NSString * _Nonnull) PartnerBizCardsEndpoint;
+ (NSString * _Nonnull) PartnerValidateEndpoint;
+ (NSString * _Nonnull) PartnerDocumentReadyEndpoint;

+ (NSString * _Nonnull) SlackNotificationURL;

+ (NSString * _Nonnull) AnalyticsAPI;
+ (NSString * _Nonnull) AnalyticsPrefix;

+ (NSString * _Nonnull) IntercomURL;

+ (NSString * _Nonnull) LocationSavePath;
+ (NSString * _Nonnull) CropTipsSavePath;

+ (NSString * _Nonnull) FeedbackEmail;

+ (int) ConfidenceLevel;
+ (int) BrightnessLevel;
+ (int) BlurThreshold;

+ (int) MaxImageSize;

+ (NSString * _Nonnull) ReimbursableKey;
@end

#pragma mark -
#pragma mark - AWSUploader

SWIFT_CLASS("AWSUploader")
@interface AWSUploader : NSObject
@property (nonatomic) id<Reachable> _Nullable reachability;

-(void)uploadFile: (NSURL *_Nonnull)fileURL
           forKey: (NSString *_Nonnull)awsKey
   withIdentifier: (NSString *_Nonnull)identifier
          regions: (Region * _Nullable) region
   accelerateMode: ( BOOL) accelerateMode
progressHandler:(nullable void (^)(float fractionCompleted)) progressHandler
completionHandler:(nullable void (^)(NSError *_Nullable error)) completionHandler;

-(BOOL)isUploading;
-(BOOL)isUploadingFileWithIdentifier: (NSString *_Nonnull) identifier;

@end

#pragma mark -
#pragma mark - LogHelper

SWIFT_PROTOCOL("LogHelperDelegate")
@protocol LogHelperDelegate <NSObject>
- (void)didFinishUploadingLog:(NSString * _Nullable) fileName error: (NSString * _Nullable) errorString;
@end

typedef SWIFT_ENUM(NSInteger, LogFile, closed) {
    LogFileDebug = 0,
    LogFileVideo = 1,
    LogFileCroppedImage = 2,
    LogFileOriginalImage = 3,
    LogFileStitchedImage = 4,
    LogFileOriginalImageHEIC = 5,
};

#pragma mark -
#pragma mark - LogSettings

SWIFT_CLASS("LogSettings")
@interface LogSettings : NSObject
@property (nonatomic) bool isLogConsoleOn;
@property (nonatomic) bool isLogDebugOn;
@property (nonatomic) bool isLogImageCroppedOn;
@property (nonatomic) bool isLogImageOriginalOn;
@property (nonatomic) bool isLogImageStitchedOn;
@property (nonatomic) bool isLogVideoOn;

- (instancetype _Nonnull)initWithJSON: (NSDictionary * _Nonnull) json;
@end

SWIFT_CLASS("LogHelper")
@interface LogHelper : NSObject
@property (nonatomic, weak) id<LogHelperDelegate> _Nullable delegate;
+ (instancetype _Nonnull)shared;
- (void)startWithSettings: (LogSettings * _Nonnull) settings userName: (NSString * _Nonnull) userName clientID: (NSString * _Nonnull) clientID url: (NSString * _Nonnull) url configuration: (NSDictionary * _Nonnull) configuration;
- (void)finishForPackageID: (NSString * _Nonnull) packageID region: (Region * _Nullable) region;

- (void)addLog:(NSString *_Nonnull)log;
- (void)addCroppedImage:(UIImage *_Nonnull)image;
- (void)addOriginImage:(UIImage *_Nonnull)image;
- (void)addStitchedImage:(UIImage *_Nonnull)image;

- (NSString *_Nonnull) pathToFile:(LogFile)file;
- (NSArray <NSString *>*_Nonnull)logFiles;
- (void) clear;
@end

#pragma mark -
#pragma mark - UserInfoProvider

SWIFT_PROTOCOL("UserInfoProviderDelegate")
@protocol UserInfoProviderDelegate <NSObject>
@optional
- (void)userInfoProviderAssessDenied;
@end

#pragma mark -
#pragma mark - EncryptionSettings

SWIFT_CLASS("EncryptionSettings")
@interface EncryptionSettings : NSObject
@property (nonatomic, readonly) bool isPackageEncryptionOn;
@property (nonatomic, readonly) NSString * _Nullable packageKey;
@property (nonatomic, readonly) NSString * _Nullable creditCardKey;
@property (nonatomic, readonly) NSString * _Nullable cropKey;
@property (nonatomic, readonly) NSString * _Nullable stitchingKey;
@property (nonatomic, readonly) NSString * _Nullable codeKey;

- (instancetype _Nonnull)initWithJSON: (NSDictionary * _Nonnull) json;
@end



#pragma mark -
#pragma mark - UserInfo

SWIFT_CLASS("UserInfo")
@interface UserInfo : NSObject
@property (nonatomic) NSArray <Region * >* _Nullable regions;
@property (nonatomic) LogSettings * _Nullable logSettings;
@property (nonatomic) EncryptionSettings * _Nullable encryptionSettings;
@property (nonatomic) BOOL isUserValid;

- (instancetype _Nonnull)initWithJSON: (NSDictionary * _Nonnull) json;

- (Region * _Nullable)region;
@end

#pragma mark -
#pragma mark - UserInfoProvider

SWIFT_CLASS("UserInfoProvider")
@interface UserInfoProvider : NSObject

@property (nonatomic, weak) UIViewController <UserInfoProviderDelegate> * _Nullable delegate;

+ (instancetype _Nonnull)shared;

- (void)checkCredentials: (id<Credentials> _Nonnull) credentials withCompletion: (void(^_Nonnull)(BOOL)) completion;

- (BOOL)isClientVeryfi;
- (BOOL)isVeryfiProduct;
- (BOOL)isValidClientID: (NSString * _Nonnull) clientID;
- (UserInfo *_Nullable)userInfo;
@end

#pragma mark -
#pragma mark - UserSettings


@interface UserSettings : NSObject<NSSecureCoding>

@property BOOL saveScanToGallery;
@property BOOL detectDocumentEdges;
@property BOOL detectBlur;
@property BOOL detectAmbience;
@property BOOL autoDocumentCapture;
@property BOOL afterScanCloseUI;

@property BOOL collectExtraMetaCategory;
@property BOOL collectExtraMetaTags;
@property BOOL collectExtraMetaProject;
@property BOOL collectExtraMetaCostCode;
@property BOOL collectExtraMetaNotes;

@property NSString * _Nonnull documentTypeRaw;

- (DocumentType)documentType;
- (NSString *_Nonnull)documentTypeNameFromRaw: (NSString * _Nonnull) documentTypeRaw;

@end

#pragma mark -
#pragma mark - UserSettingsProvider

SWIFT_CLASS("UserSettingsProvider")
@interface UserSettingsProvider : NSObject

@property (nonatomic) UserSettings * _Nonnull settings;

+ (instancetype _Nonnull)shared;
- (instancetype _Nonnull )init NS_UNAVAILABLE;
- (BOOL)whoWithApp:(BOOL)appSetting orUser:(BOOL)userSetting;

@end

//#pragma mark -
//#pragma mark - Credentials
//
//SWIFT_PROTOCOL("Credentials")
//@protocol Credentials <NSObject>
//
//@property NSString * _Nonnull clientId;
//@property NSString * _Nonnull username;
//@property NSString * _Nonnull apiKey;
//@property NSString * _Nonnull url;
//
//
//- (instancetype _Nonnull)initWithClientId:(NSString * _Nonnull)clientId
//                        username:(NSString * _Nonnull)username
//                          apiKey:(NSString * _Nonnull)apiKey
//                             url:(NSString * _Nonnull)url;
//@end

#pragma mark -
#pragma mark - NetworkHelper

SWIFT_CLASS("NetworkHelper")
@interface NetworkHelper : NSObject

@property (nonatomic) id<Credentials> _Nonnull credentials;
@property (nonatomic) BOOL simulateServerError;
@property (nonatomic) BOOL simulateNilResposeFromServer;

- (instancetype _Nonnull )init NS_UNAVAILABLE;
- (instancetype _Nonnull )initWithCredentials: (id<Credentials> _Nonnull) credentials;

- (void)processDocumentWithBucket:(NSString * _Nonnull) bucket
                           awsKey: (NSString * _Nonnull) awsKey
                     documentType: (NSString * _Nonnull) documentType
                       completion:(void(^_Nonnull)(NSDictionary * _Nullable, NSError * _Nullable)) completion;
- (void)processDictationWithParams:(NSDictionary * _Nonnull) params
                        completion:(void(^_Nonnull)(NSDictionary * _Nullable, NSError * _Nullable)) completion;
- (void)documentReadyPackageID:(NSString * _Nonnull) packageID
                           engine:(DataExtractionEngine) engine
                     documentType:(NSString * _Nonnull) documentType
                       completion:(void(^_Nonnull)(NSDictionary * _Nullable, NSError * _Nullable)) completion;

- (void)uploadToCustomAPIWithURL:(NSURL * _Nonnull) url
                      packageURL:(NSURL * _Nonnull)packageURL
                     packagePath:(NSString * _Nonnull)packagePath
                        mimeType:(NSString * _Nonnull)mimeType
                      completion:(void(^_Nonnull)(NSDictionary * _Nullable, NSError * _Nullable)) completion;

@end

#pragma mark -
#pragma mark - API

SWIFT_CLASS("Validator")
@interface Validator : NSObject
@property (nonatomic) BOOL shouldSimulateServerError;
@property (nonatomic) BOOL shouldSimulateNilResponse;
- (instancetype _Nonnull )initWithCredentials: (id<Credentials> _Nonnull) credentials;
- (void)validateWithCompletion: (void(^_Nonnull)(NSDictionary * _Nullable, NSError * _Nullable)) completion;

@end

#pragma mark -
#pragma mark - LocationHelper

SWIFT_CLASS("LocationHelper")
@interface LocationHelper : NSObject

+ (instancetype _Nonnull)shared;
- (instancetype _Nonnull )init NS_UNAVAILABLE;
- (CLLocation * _Nullable)location;
- (NSDictionary *_Nonnull)locationJSON;
- (void)updateLocation;
@end

#pragma mark -
#pragma mark - CreditCard

SWIFT_CLASS("CreditCard")
@interface CreditCard : NSObject
@property (nonatomic) NSString * _Nullable number;
@property (nonatomic) NSString * _Nullable date;
@property (nonatomic) NSString * _Nullable date2;
@property (nonatomic) NSString * _Nullable name;
@property (nonatomic) NSString * _Nullable type;
@property (nonatomic) NSString * _Nullable cvv;
@property (nonatomic) UIImage * _Nullable image;
-(NSDictionary * _Nonnull)json;
@end

#pragma mark -
#pragma mark - OCRResult

SWIFT_CLASS("OCRResult")
@interface OCRResult : NSObject
@property (nonatomic) NSString * _Nullable ocrText;
@property (nonatomic) double  ocrScore;
@property (nonatomic) NSString * _Nullable ocrUuid;
@property (nonatomic) NSString * _Nullable ocrImage;
-(NSDictionary * _Nonnull)json;
@end

#pragma mark -
#pragma mark - Scan

SWIFT_CLASS("Scan")
@interface Scan : NSCoder
@property (nonatomic) UIImage * _Nullable image;
@property (nonatomic) CreditCard * _Nullable creditCard;
@property (nonatomic) NSURL * _Nullable fileURL;
@property (nonatomic) NSString * _Nullable imageSource;
@property (nonatomic) NSNumber * _Nullable imageBrightnessValue;
@property (nonatomic) CLLocation * _Nullable location;
@property (nonatomic) ScanSettings * _Nullable scanSettings;
@property (nonatomic) NSNumber * _Nullable rotationIndex;
@property (nonatomic) NSNumber * _Nullable imageCompressionQuality;
@property (nonatomic) BOOL isImageBlurred;
@property (nonatomic) BOOL isDocumentDetected;
@property (nonatomic) BOOL isRotationDetected;
@property (nonatomic) BOOL compressIt;
@property (nonatomic) NSNumber * _Nullable originalImageMaxSizeInMB;
@property (nonatomic) NSString * _Nullable notes;
@property (nonatomic) VeryfiLensCostCode * _Nullable costCode;
@property (nonatomic) VeryfiLensCPModel * _Nullable fusedCP;
@property (nonatomic) NSArray <VeryfiLensTag *> * _Nullable tags;
@property (nonatomic) VeryfiLensCategory * _Nullable category;
@property (nonatomic) BOOL torchMode;
@property (nonatomic) BOOL afterSubmitCloseUI;
@property (nonatomic) NSString * _Nullable packageId;
@property (nonatomic) NSNumber * _Nullable totalImagesToUpload;
@property (nonatomic) NSNumber * _Nullable index;
@property (nonatomic) BOOL isImageCorrected;
@property (nonatomic) NSString * _Nullable dictation;
- (instancetype _Nonnull )initWithDocumentType:(DocumentType) documentType;
-(NSDictionary * _Nonnull)json;
@end

#pragma mark -
#pragma mark - CustomPackageInfo

SWIFT_CLASS("CustomPackageInfo")
@interface CustomPackageInfo : NSObject
@property (nonatomic) NSString * _Nullable notes;
@property (nonatomic) VeryfiLensCostCode * _Nullable costCode;
@property (nonatomic) VeryfiLensCPModel * _Nullable fusedCP;
@property (nonatomic) NSArray <VeryfiLensTag *> * _Nullable tags;
@property (nonatomic) VeryfiLensCategory * _Nullable category;
@end

#pragma mark -
#pragma mark - PackageInfo

SWIFT_CLASS("PackageInfo")
@interface PackageInfo : NSObject
@property (nonatomic) NSString * _Nonnull documentPath;
@property (nonatomic) NSString * _Nonnull packageID;
@property (nonatomic) NSString * _Nonnull packageDirectory;
@property (nonatomic) NSString * _Nonnull counterPath;
@property (nonatomic) NSString * _Nonnull packageFullName;
@property (nonatomic) NSString * _Nonnull packagePath;
@property (nonatomic) NSString * _Nonnull zipName;
@property (nonatomic) NSString * _Nonnull zipPath;
@property (nonatomic) NSString * _Nonnull thumbnailPath;
@property (nonatomic) NSString * _Nonnull packageThumbnailPath;
@property (nonatomic) NSString * _Nonnull originalImagePath;
@property (nonatomic) NSString * _Nonnull originalPDFPath;

- (instancetype _Nonnull )initWithIdentifier:(NSString *_Nonnull) identifier
                                 forUsername:(NSString *_Nonnull) username;

- (NSString * _Nonnull)originalPath;
- (NSArray<NSString *> * _Nonnull)imagePaths;
- (BOOL)containsPDF;
- (BOOL)exist;
- (int)scanInPackage;
@end

#pragma mark -
#pragma mark - Package

SWIFT_CLASS("Package")
@interface Package : NSObject

@property (nonatomic) BOOL shouldCreatePDF;
@property (nonatomic) float densityMultiplier;
@property (nonatomic) PackageInfo * _Nonnull info;

- (instancetype _Nonnull )initWithIdentifier:(NSString *_Nonnull) identifier
                                 forUsername:(NSString *_Nonnull) username;

- (void)addScan:(Scan *_Nonnull) scan
        atIndex:(int) index;

- (BOOL)prepareForUpload;

- (void)save;

- (void)clear;

- (void)deleteZip;

- (UIImage * _Nullable)imageForIndex:(int)index;

- (NSMutableDictionary * _Nullable)metadataForIndex:(int)index;

@end

#pragma mark -
#pragma mark - PDFHelper

SWIFT_CLASS("PDFHelper")
@interface PDFHelper : NSObject
+ (void) createPDFFromImages:(NSArray< UIImage *> *_Nonnull) images densityMultiplier: (CGFloat) densityMultiplier;
+ (NSString * _Nullable)pdfPath;
@end

#pragma mark -
#pragma mark - Packager

SWIFT_CLASS("Packager")
@interface Packager : NSObject
+ (instancetype _Nonnull)shared;

- (instancetype _Nonnull)init NS_UNAVAILABLE;

- (void)createPackageWithUserName: (NSString * _Nonnull) userName
                       mergeScans: (BOOL) mergeScans
                returnStitchedPDF: (BOOL) mergeScans
stitchedPDFPixelDensityMultiplier: (CGFloat) stitchedPDFPixelDensityMultiplier
                    isPrivateData: (BOOL) isPrivateData
            barcodeExtractionIsOn: (BOOL) barcodeExtractionIsOn
                    galleryBackup: (BOOL) galleryBackup
                customPackageInfo: (CustomPackageInfo * _Nullable) customPackageInfo
                         completion: (void (^_Nonnull)(NSArray * _Nonnull packages)) completion;

- (void)addScan:(Scan * _Nonnull) scan;

- (void)updateScan: (Scan *_Nonnull ) scan atIndex: (NSInteger) index;

- (NSArray <Scan*>* _Nonnull)scans;

- (BOOL)canAddScan;

- (BOOL)hasContent;

- (int)sessionScanCount;

- (void)updateSessionScanCount;

- (void)removeLastScan;

- (void)removeAtIndex: (NSUInteger) index;

- (void)removeAll;

- (void)sanity;
@end

#pragma mark -
#pragma mark - ExposedViewController

SWIFT_PROTOCOL("ExposedViewController")
@protocol ExposedViewController <NSObject>
@property (nonatomic) void(^ _Nullable closeBlock)(BOOL);
@end

#pragma mark -
#pragma mark - PackageHelper

SWIFT_CLASS("PackageHelper")
@interface PackageHelper : NSObject
+ (NSArray *_Nonnull)getPackageIdsForUserName:(NSString *_Nullable) userName;
@end

#pragma mark -
#pragma mark - ShieldViewController

SWIFT_CLASS("ShieldViewController")
@interface ShieldViewController : UIViewController<ExposedViewController>
@end

//
//#pragma mark -
//#pragma mark - VeryfiLensCurrency
//
//SWIFT_CLASS("VeryfiLensCurrency")
//@interface VeryfiLensCurrency : NSObject<NSCoding>
//
//@property NSString * _Nonnull code;
//@property NSString * _Nonnull name;
//@property NSString * _Nonnull symbol;
//@property BOOL isRecent;
//
//- (instancetype _Nonnull)initWithDictionary:(NSDictionary * _Nullable)dictionary;
//
//- (NSDictionary * _Nonnull)asDict;
//+ (NSDictionary * _Nonnull)getDeviceCurrencyInfo;
//@end
//
//#pragma mark -
//#pragma mark - VeryfiLensTag
//
//SWIFT_CLASS("VeryfiLensTag")
//@interface VeryfiLensTag : NSObject<NSSecureCoding>
//@property NSNumber * _Nonnull tagId;
//@property NSString * _Nonnull name;
//@property VeryfiLensCurrency * _Nonnull currency;
//@property double spent;
//@property int receiptsCount;
//@property NSString * _Nonnull status;
//@property NSString * _Nonnull type;
//
//- (instancetype _Nonnull)initWithDictionary:(NSDictionary * _Nonnull)dictionary;
//
//- (NSString * _Nonnull)getFormattedTotalWithCurrency;
//- (BOOL)wasSourcedExternally;
//@end
//
//
//
//#pragma mark -
//#pragma mark - VeryfiLensCategory
//
//SWIFT_CLASS("VeryfiLensCategory")
//@interface VeryfiLensCategory : NSObject<NSSecureCoding>
//
//@property NSNumber * _Nonnull categoryId;
//@property NSString *_Nonnull name;
//@property double monthlyBudget;
//@property VeryfiLensCurrency * _Nonnull currency;
//@property double spent;
//@property int receiptsCount;
//@property NSString * _Nonnull type;
//@property NSString * _Nonnull mimo;
//
//- (instancetype _Nonnull)initWithDictionary:(NSDictionary * _Nonnull)dictionary;
//
//+ (NSDictionary * _Nonnull)types;
//+ (NSString * _Nonnull)getTypeNameFromTypeKey:(NSString * _Nonnull)typeId;
//
//@end
//
//#pragma mark -
//#pragma mark - VeryfiVeryfiLensCPModelLensCategory
//
//typedef SWIFT_ENUM(NSInteger, CustomerOrProject, closed) {
//    kCustomer = 0,
//    kProject = 1
//};
//
//SWIFT_CLASS("VeryfiLensCPModel")
//@interface VeryfiLensCPModel: NSObject<NSSecureCoding>
//
//@property CustomerOrProject primaryCP;
//@property NSNumber * _Nonnull customerId;
//@property NSString * _Nonnull customerName;
//@property NSNumber * _Nullable projectId;
//@property NSString * _Nullable projectName;
//
//- (instancetype _Nonnull)initWithDictionary:(NSDictionary *_Nonnull)dictionary;
//- (NSString * _Nonnull)fusedId;
//- (NSString * _Nonnull)displayName;
//
//@end
//
//#pragma mark -
//#pragma mark - VeryfiCostCode
//
//SWIFT_CLASS("VeryfiCostCode")
//@interface VeryfiCostCode : NSObject
//@property (nonatomic) bool hasCostCode;
//@property (nonatomic) NSNumber * _Nullable costCodeId;
//@property (nonatomic) NSString * _Nullable code;
//@property (nonatomic) NSString * _Nullable desc;
//@property (nonatomic) NSString * _Nullable name;
//@property (nonatomic) NSString * _Nullable type;
//
//- (instancetype _Nonnull)initWithDictionary: (NSDictionary * _Nonnull) dictionary;
//@end

#pragma mark -
#pragma mark - Utilities

SWIFT_CLASS("Utilities")
@interface Utilities: NSObject
+ (NSString *_Nonnull) mimeTypeFor:(NSURL *_Nullable)url;
+ (NSString *_Nonnull) randomStringWithLength:(int)length;
@end


typedef SWIFT_ENUM(NSInteger, SimulatedErrorType, closed) {
    SimulatedErrorTypeNotifyServerBeforeUpload = 0,
    SimulatedErrorTypeAWS = 1,
    SimulatedErrorTypeNoReachable = 2,
    SimulatedErrorTypeHasPackagePingedAPI = 3,
    SimulatedErrorTypeCustomAPI = 4,
    SimulatedErrorTypeNotifyServerToProcessDocuments = 5,
    SimulatedErrorTypePackageIsNotPrepared = 6,
};

#pragma mark -
#pragma mark - PackageUploader

SWIFT_CLASS("PackageUploader")
@interface PackageUploader: NSObject
@property (nonatomic, weak) id <VeryfiLensDelegate> _Nullable delegate;
@property (nonatomic) BOOL simulateServerError;
@property (nonatomic) SimulatedErrorType simulateErrorType;
@property (nonatomic) VeryfiLensSettings * _Nonnull settings;
@property (nonatomic) BOOL isProcessing;

- (instancetype _Nonnull)initWithCredentials: (VeryfiLensCredentials * _Nonnull) credentials
                                    settings: (VeryfiLensSettings * _Nonnull) settings;
- (void)updateSettings:(VeryfiLensSettings * _Nonnull)settings;
- (void)upload:(NSString * _Nonnull)packageID;
- (void)clear:(NSString * _Nonnull)packageID;
@end

#pragma mark -
#pragma mark - Analytics

typedef SWIFT_ENUM(NSInteger, AnalyticsEvent, closed) {
    AnalyticsEventSessionStart,
    AnalyticsEventSessionEnd,
    AnalyticsEventScreenShow,
    AnalyticsEventCameraShow,
    AnalyticsEventCameraClose,
    AnalyticsEventCameraCloseConfirmation,
    AnalyticsEventCameraMenuOpen,
    AnalyticsEventCameraMenuClose,
    AnalyticsEventCameraDocumentTypeSelected,
    AnalyticsEventCameraGalleryOpen,
    AnalyticsEventCameraCapture,
    AnalyticsEventCameraRecordStart,
    AnalyticsEventCameraRecordEnd,
    AnalyticsEventCameraAutocaptureStart,
    AnalyticsEventCameraAutocaptureEnd,
    AnalyticsEventVoiceOpen,
    AnalyticsEventVoiceClose,
    AnalyticsEventVoiceStart,
    AnalyticsEventVoiceEnd,
    AnalyticsEventVoiceMicAccessStatus,
    AnalyticsEventVoiceRecognitionAccessStatus,
    AnalyticsEventVoiceRetry,
    AnalyticsEventVoiceSubmit,
    AnalyticsEventVoiceFail,
    AnalyticsEventLrStart,
    AnalyticsEventLrEnd,
    AnalyticsEventUpfrontExpand,
    AnalyticsEventUpfrontCollapse,
    AnalyticsEventUpfrontShow,
    AnalyticsEventUpfrontAddCategory,
    AnalyticsEventUpfrontAddTag,
    AnalyticsEventUpfrontAddCustomer,
    AnalyticsEventUpfrontAddCostCode,
    AnalyticsEventUpfrontAddNotes,
    AnalyticsEventBrowseOpen,
    AnalyticsEventBrowseImportDocument,
    AnalyticsEventBrowseClose,
    AnalyticsEventGalleryOpen,
    AnalyticsEventGalleryImportImage,
    AnalyticsEventGalleryClose,
    AnalyticsEventSubmitPackageSubmitted,
    AnalyticsEventSubmitDocumentDetectionStatus,
    AnalyticsEventSubmitNoDocumentAlertShow,
    AnalyticsEventSubmitBlurAlertShow,
    AnalyticsEventSubmitShareLogs,
    AnalyticsEventSubmitAddDocument,
    AnalyticsEventSubmitDocumentRotate,
    AnalyticsEventSubmitDocumentScrolled,
    AnalyticsEventSubmitDocumentRemove,
    AnalyticsEventSubmitDocumentCrop,
    AnalyticsEventSubmitDocumentCountTapped,
    AnalyticsEventMenuOptionSelected,
    AnalyticsEventSettingsDocDetectionChanged,
    AnalyticsEventSettingsBlurDetectionChanged,
    AnalyticsEventSettingsAutotorchChanged,
    AnalyticsEventSettingsAutocaptureChanged,
    AnalyticsEventSettingsBackupChanged,
    AnalyticsEventSettingsAutocloseChanged,
    AnalyticsEventSettingsUpfrontCategoryChanged,
    AnalyticsEventSettingsUpfrontTagsChanged,
    AnalyticsEventSettingsUpfrontProjectsChanged,
    AnalyticsEventSettingsUpfrontCostCodesChanged,
    AnalyticsEventSettingsUpfrontNotesChanged,
    AnalyticsEventSettingsContactSupport,
    AnalyticsEventEmailOpen,
    AnalyticsEventEmailClose,
    AnalyticsEventEmailCopyEmail,
    AnalyticsEventEmailAddContact,
    AnalyticsEventShieldOpen,
    AnalyticsEventShieldClose,
    AnalyticsEventShieldLearnMore,
    AnalyticsEventCropShow,
    AnalyticsEventCropGuideShow,
    AnalyticsEventCropAlertShow,
    AnalyticsEventVeryfiLensSuccess,
    AnalyticsEventVeryfiLensError,
    AnalyticsEventNotificationInternalError,
    AnalyticsEventCpp,
    AnalyticsEventHeadlessUpload
};

typedef SWIFT_ENUM(NSInteger, AnalyticsParam, closed) {
    AnalyticsParamsSource,
    AnalyticsParamsVersion,
    AnalyticsParamsType,
    AnalyticsParamsDocumentQueue,
    AnalyticsParamsAction,
    AnalyticsParamsDocumentType,
    AnalyticsParamsDuration,
    AnalyticsParamsProgress,
    AnalyticsParamsStatus,
    AnalyticsParamsError,
    AnalyticsParamsTotalFrames,
    AnalyticsParamsMergedFrames,
    AnalyticsParamsSelectedItem,
    AnalyticsParamsHasValue,
    AnalyticsParamsRotationNumber,
    AnalyticsParamsIndex,
    AnalyticsParamsCategory,
    AnalyticsParamsTag,
    AnalyticsParamsCustomer,
    AnalyticsParamsCostCode,
    AnalyticsParamsNotes
};

typedef SWIFT_ENUM(NSInteger, VeryfiLensResponseStatus, closed) {
    VeryfiLensResponseStatusStart,
    VeryfiLensResponseStatusInProgress,
    VeryfiLensResponseStatusSuccess,
    VeryfiLensResponseStatusFail,
    VeryfiLensResponseStatusException,
    VeryfiLensResponseStatusError,
    VeryfiLensResponseStatusClear,
    VeryfiLensResponseStatusClose
};

typedef SWIFT_ENUM(NSInteger, AnalyticsErrorType, closed) {
    AnalyticsErrorTypeException,
    AnalyticsErrorTypeError,
    AnalyticsErrorTypeFailure,
};

SWIFT_CLASS("Analytics")
@interface Analytics: NSObject
+ (instancetype _Nonnull)shared;
+ (NSString * _Nonnull)stringParameter: (AnalyticsParam) param;
- (void)logEvent:(AnalyticsEvent) event params: (NSDictionary * _Nullable) params;
- (void)errorWithType: (AnalyticsErrorType) type
              message: (NSString *_Nonnull) message
            packageId: (NSString *_Nullable) packageId
         documentType: (DocumentType) documentType
             userName: (NSString *_Nonnull) userName;
@end

#pragma mark -
#pragma mark - Gallery

SWIFT_CLASS("Gallery")
@interface Gallery: NSObject
+ (void)saveImage: (UIImage * _Nonnull) image toAlbum: (NSString *_Nonnull) albumTitle;
@end

#pragma mark -
#pragma mark - DeviceInfo

SWIFT_CLASS("DeviceInfo")
@interface DeviceInfo: NSObject
+ (NSString * _Nonnull)orientationWithDirection: (BOOL) showDirection;
+ (NSString * _Nonnull)platform;
+ (NSString * _Nonnull)deviceName;
+ (NSString * _Nonnull)appVersion;
+ (NSString * _Nonnull)osVersion;
+ (NSString * _Nonnull)uuid;
+ (NSString * _Nonnull)carrierName;
+ (NSString * _Nonnull)gpsSignalQualityForHorizontalAccuracy: (CGFloat) horizontalAccuracy;
+ (NSString * _Nonnull)countryBasedOnLanguage: (BOOL) basedOnLanguage;
@end

#pragma mark -
#pragma mark - UnitTestsHelper

SWIFT_CLASS("UnitTestsHelper")
@interface UnitTestsHelper: NSObject
+ (BOOL)isUnitTestRunning;
@end

#pragma mark -
#pragma mark - VeryfiLensResponse

SWIFT_CLASS("VeryfiLensResponse")
@interface VeryfiLensResponse: NSObject
- (NSDictionary * _Nonnull)json;
@end

SWIFT_CLASS("VeryfiLensCloseResponse")
@interface VeryfiLensCloseResponse: VeryfiLensResponse
- (instancetype _Nonnull)initWithQueueCount:(NSInteger)queueCount scanCount: (NSInteger)scanCount;
@end



#endif /* VeryfiLensSwiftHeaders_h */
