#include "UnrealGDAL.h"
#include "GDALHelpers.h"

#define LOCTEXT_NAMESPACE "FUnrealGDALModule"

void FUnrealGDALModule::StartupModule() {
	this->InitGDAL();
}

// void FUnrealGDALModule::ShutdownModule() 
// {
// 	GDALDestroy();
// }

void FUnrealGDALModule::InitGDAL()
{
	//Point GDAL to the path containing its runtime data files
	FString dataDir = FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectDir(), TEXT("Binaries"), TEXT("Data"), TEXT("GDAL")));
	CPLSetConfigOption("GDAL_DATA", TCHAR_TO_UTF8(*dataDir));
	
	//Register all GDAL format drivers
	GDALAllRegister();
	
	//Install our GDAL error handler
	CPLSetErrorHandler(FUnrealGDALModule::GDALErrorHandler);
}

void FUnrealGDALModule::GDALErrorHandler(CPLErr err, int num, const char* message) {
	UE_LOG(LogTemp, Error, TEXT("%s"), UTF8_TO_TCHAR(message))
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FUnrealGDALModule, UnrealGDAL)