// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

//=============================================================================
// BlendSpaceFactoryNew
//=============================================================================

#pragma once
#include "BlendSpaceFactoryNew.generated.h"

UCLASS(hidecategories=Object, MinimalAPI)
class UBlendSpaceFactoryNew : public UFactory
{
	GENERATED_UCLASS_BODY()

	UPROPERTY()
	class USkeleton*	TargetSkeleton;

	// Begin UFactory Interface
	virtual bool ConfigureProperties() override;
	virtual UObject* FactoryCreateNew(UClass* Class,UObject* InParent,FName Name,EObjectFlags Flags,UObject* Context,FFeedbackContext* Warn) override;
	// Begin UFactory Interface

private:
	void OnTargetSkeletonSelected(const FAssetData& SelectedAsset);

private:
	TSharedPtr<SWindow> PickerWindow;
};



