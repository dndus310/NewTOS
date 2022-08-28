// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Define.generated.h"

/**
 * 
 */
UENUM()
enum class ERelational
{
	OR UMETA(DisplayName = "OR"),
	AND UMETA(DisplayName = "AND")
};
UENUM()
enum class EStartMode
{
	SingleMode = 0,
	MultiMode = 1,
};


ENUM(BlueprintType)
enum class EMessageBoxType : uint8
{
	LOG UMETA(DisplayName = "NONE"),
	SUCCESS UMETA(DisplayName = "SUCCESS"),
	WARNING UMETA(DisplayName = "WARNING"),
	ERROR UMETA(DisplayName = "ERROR"),
	NULLPTR UMETA(DisplayName = "NULLPTR"),
	EMPTY UMETA(DisplayName = "EMPTY")
};

UENUM(BlueprintType)
enum class ESelectedLanguage : uint8
{
	KR = 0 UMETA(DisplayName = "KR"),
	EN UMETA(DisplayName = "EN"),
	SPN UMETA(DisplayName = "SPN"),
	JP UMETA(DisplayName = "JP")
};

UENUM(BlueprintType)
enum class EPlayMode : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Game UMETA(DisplayName = "Game"),
	Editor UMETA(DisplayName = "Editor"),
	PIE UMETA(DisplayName = "PIE"),
	EditorPreview UMETA(DisplayName = "EditorPreview"),
	GamePreview UMETA(DisplayName = "GamePreview"),
	GameRPC UMETA(DisplayName = "GameRPC"),
	Inactive UMETA(DisplayName = "Inactive")
};

UENUM(BlueprintType)
enum class EHandPoseType : uint8
{
	Normal = 0 UMETA(DisplayName = "Normal"),
	AllGrab	UMETA(DisplayName = "AllGrab"),
	BrushGrab UMETA(DisplayName = "BrushGrab"),
	SphereGrab UMETA(DisplayName = "SphereGrab"),
	ChrGrab UMETA(DisplayName = "ChrGrab"),
	LaternGrab UMETA(DisplayName = "LaternGrab"),
	CylinderGrab UMETA(DisplayName = "CylinderGrab"),
	PZHintGrab UMETA(DisplayName = "PZHintGrab"),
	PointGrab UMETA(DisplayName = "PointGrab"),
	TriggerGrab UMETA(DisplayName = "TriggerGrab"),
	All UMETA(DisplayName = "All")
};


UENUM(BlueprintType)
enum class ESubLevelType : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Main = 1 UMETA(DisplayName = "Main"),
	PoliceCarInside = 2 UMETA(DisplayName = "PoliceCarInside"),
	Hospital_00 = 3 UMETA(DisplayName = "Hospital_00"),
	Hospital_01 = 4 UMETA(DisplayName = "Hospital_01"),
	Hospital_02 = 5 UMETA(DisplayName = "Hospital_02"),
	Hospital_03 = 6 UMETA(DisplayName = "Hospital_03"),
	All = 7 UMETA(DisplayName = "All")
};

UENUM(BlueprintType)
enum class ESceneObjectType : uint8
{
	Main = 0 UMETA(DisplayName = "Main"),
	Dummy = 1 UMETA(DisplayName = "Dummy"),
	Deco = 2 UMETA(DisplayName = "Deco"),
	Memo = 3 UMETA(DisplayName = "Memo"),
	Picture = 4 UMETA(DisplayName = "Picture")
};

UENUM(BlueprintType)
enum class ESceneObjectMat : uint8
{
	Default = 0 UMETA(DisplayName = "Default"),
	Glass UMETA(DisplayName = "Glass"),
	Plastic UMETA(DisplayName = "Plastic"),
	Can UMETA(DisplayName = "Can"),
	Metal UMETA(DisplayName = "Metal")
};

UENUM(BlueprintType)
enum class ESceneAchievement : uint8
{
	Default = 0 UMETA(DisplayName = "Default"),
	Emma UMETA(DisplayName = "Emma"),
	Dylan UMETA(DisplayName = "Dylan"),
	Morris_Aaliya UMETA(DisplayName = "Morris_Aaliya")
};






USTRUCT()
struct FStageSetting
{
	GENERATED_USTRUCT_BODY()
public:
	float MaxFazeTime;
	int SpawnCount;
};
USTRUCT()
struct FStageData
{
	GENERATED_USTRUCT_BODY()
public:
	TArray<FStageData> StageArray;
};

USTRUCT()
struct FTracePosition
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY()
		TArray<FVector> TracePositions;
	FTracePosition()
	{
		TracePositions.Empty();
	}
};
USTRUCT()
struct FTraceData
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY()
		TMap < FString, FTracePosition> TraceMap;
	FTraceData()
	{
		TraceMap.Empty();
	}
};

USTRUCT(BlueprintType)
struct FOptionData
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		ESelectedLanguage ELanguageType = ESelectedLanguage::KR;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		bool IsBGM = true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		bool IsSFX = true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		bool IsHaptic = true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite) // false = FreeMove
		bool IsMovementType = false;
	UPROPERTY(EditAnywhere,BlueprintReadWrite) // false = Quick, false = Smooth
		bool IsTurnType = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MoveSpeed = 50.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TurnSpeed = 50.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TurnAngle = 45.0f;

};
USTRUCT(BlueprintType)
struct FMasterObjects
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<class AMasterObject*> MasterObjects = {};

};

USTRUCT(BlueprintType)
struct FObject_SFX_Info
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Break = "";
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName NormalHit = "";
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Dent = "";

};


USTRUCT(BlueprintType)
struct FSceneMeshType
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMesh* SM = NULL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMesh* SK = NULL;
};

USTRUCT(BlueprintType)
struct FObjectInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSceneMeshType MeshType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ESceneObjectType ESceneObjectType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName AttachKeyName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Weight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ESceneObjectMat EObjectMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EHandPoseType EHandPose;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PoseAlpha;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FName> EventTagNames;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ESceneAchievement EAchieveCharacter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FObject_SFX_Info SFX_Info;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName SuccessComment;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName FailComment;

};

