// Fill out your copyright notice in the Description page of Project Settings.


#include "../BlueprintFunctionLibrary/BPFL_GameUtils.h"
#include "../Define.h"

EPlayMode UBPFL_GameUtils::GetPlayMode(UObject* WorldContext)
{
	TEnumAsByte<EWorldType::Type> EWorldTypeToByte = WorldContext->GetWorld()->WorldType;

	int WorldTypeTointeger = (int)EWorldTypeToByte.GetValue();
	return (EPlayMode)WorldTypeTointeger;
}

void UBPFL_GameUtils::MessageBox(FString In_TitleName, EMessageBoxType MessageType, FString In_MessageStr, FVector2D TextScale)
{
	FString Result = "";
	FString MessageTypeByString = StaticEnum<EMessageBoxType>()->GetNameStringByValue(static_cast<int64>(MessageType));
	Result.Append("[" + MessageTypeByString + "]" + " " + In_TitleName + " : " + In_MessageStr);

	FColor MessageColor = FColor::Cyan;
	switch (MessageType)
	{
	case EMessageBoxType::LOG:
		MessageColor = FColor::Cyan;
		break;
	case EMessageBoxType::SUCCESS:
		MessageColor = FColor::Green;
		break;
	case EMessageBoxType::WARNING:
		MessageColor = FColor::Yellow;
		break;
	case EMessageBoxType::ERROR: case EMessageBoxType::NULLPTR: case EMessageBoxType::EMPTY:
		MessageColor = FColor::Red;
		break;
	default:
		MessageColor = FColor::Cyan;
		SET_WARN_COLOR(COLOR_CYAN);
		break;
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, MessageColor, Result, false, TextScale);
	GLog->Log(Result);
}

FName UBPFL_GameUtils::GetStreamingLevelNameFromActor(AActor* Actor)
{
	if (Actor != nullptr)
	{
		return Actor->GetLevel()->GetOuter()->GetFName();
	}
	return FName();
}

void UBPFL_GameUtils::SetVector_X(UPARAM(ref, DisplayName = "Input Vector") FVector& In_Vector, float X)
{
	In_Vector.X = X;
}
void UBPFL_GameUtils::SetVector_Y(UPARAM(ref, DisplayName = "Input Vector") FVector& In_Vector, float Y)
{
	In_Vector.Y = Y;
}
void UBPFL_GameUtils::SetVector_Z(UPARAM(ref, DisplayName = "Input Vector") FVector& In_Vector, float Z)
{
	In_Vector.Z = Z;
}
void UBPFL_GameUtils::SetRotator_X(UPARAM(ref, DisplayName = "Input Rotator") FRotator& In_Rotator, float Roll)
{
	In_Rotator.Roll = Roll;
}
void UBPFL_GameUtils::SetRotator_Y(UPARAM(ref, DisplayName = "Input Rotator") FRotator& In_Rotator, float Pitch)
{
	In_Rotator.Pitch = Pitch;
}
void UBPFL_GameUtils::SetRotator_Z(UPARAM(ref, DisplayName = "Input Rotator") FRotator& In_Rotator, float Yaw)
{
	In_Rotator.Yaw = Yaw;
}