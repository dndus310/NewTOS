// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../Define.h"
#include "BPFL_GameUtils.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class THECAREVR_API UBPFL_GameUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

// SET
	UFUNCTION(BlueprintCallable)
	static void SetVector_X(UPARAM(ref, DisplayName = "Input Vector") FVector& In_Vector, float X);
	
	UFUNCTION(BlueprintCallable)
	static void SetVector_Y(UPARAM(ref, DisplayName = "Input Vector") FVector& In_Vector, float Y);
	
	UFUNCTION(BlueprintCallable)
	static void SetVector_Z(UPARAM(ref, DisplayName = "Input Vector") FVector& In_Vector, float Z);

	UFUNCTION(BlueprintCallable)
	static void SetRotator_X(UPARAM(ref, DisplayName = "Input Rotator") FRotator& In_Rotator, float Roll);

	UFUNCTION(BlueprintCallable)
	static void SetRotator_Y(UPARAM(ref, DisplayName = "Input Rotator") FRotator& In_Rotator, float Pitch);

	UFUNCTION(BlueprintCallable)
	static void SetRotator_Z(UPARAM(ref, DisplayName = "Input Rotator") FRotator& In_Rotator, float Yaw);


// GET
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContext"))
	static EPlayMode GetPlayMode(UObject* WorldContext);

	UFUNCTION(BlueprintPure)
	static float GetVector_X(UPARAM(ref, DisplayName = "Input Vector") FVector& In_Vector) { return In_Vector.X; };

	UFUNCTION(BlueprintPure)
	static float GetVector_Y(UPARAM(ref, DisplayName = "Input Vector") FVector& In_Vector) { return In_Vector.Y; };

	UFUNCTION(BlueprintPure)
	static float GetVector_Z(UPARAM(ref, DisplayName = "Input Vector") FVector& In_Vector) { return In_Vector.Z; };

	UFUNCTION(BlueprintPure)
	static float GetRotator_X(UPARAM(ref, DisplayName = "Input Rotator") FRotator& In_Rotator) { return In_Rotator.Roll; };

	UFUNCTION(BlueprintPure)
	static float GetRotator_Y(UPARAM(ref, DisplayName = "Input Rotator") FRotator& In_Rotator) { return In_Rotator.Pitch; };

	UFUNCTION(BlueprintPure)
	static float GetRotator_Z(UPARAM(ref, DisplayName = "Input Rotator") FRotator& In_Rotator) { return In_Rotator.Yaw; };

	UFUNCTION(BlueprintCallable)
	static void MessageBox(FString In_TitleName = "Title", EMessageBoxType MessageType = EMessageBoxType::LOG, FString In_MessageStr = "", FVector2D TextScale = FVector2D(1,1));

	UFUNCTION(BlueprintPure)
	static FName GetStreamingLevelNameFromActor(AActor* Actor);
};
