#pragma once

#include "CoreMinimal.h"
#include "Misc/Paths.h"
#include "Modules/ModuleManager.h"
#include "GDALHeaders.h"

class UNREALGDAL_API FUnrealGDALModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	
	//Configures the GDAL data directory and registers all GDAL drivers
	//This function must be called by any module that consumes the GDAL/OGR API and must be inlined under Windows due to DLL boundary issues
	void InitGDAL();
	
	//Our custom error handler for logging errors emitted by GDAL
	static void GDALErrorHandler(CPLErr err, int num, const char* message);
};
