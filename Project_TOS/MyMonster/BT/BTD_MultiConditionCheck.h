// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_BlackboardBase.h"
#include "MyMonster/Monster.h"
#include "Define.h"
#include "BTD_MultiConditionCheck.generated.h"


/**
 * 
 */


/**
 * 
 */
UCLASS()
class PROJECT_TOS_API UBTD_MultiConditionCheck : public UBTDecorator_BlackboardBase
{
	GENERATED_BODY()
public:
	virtual void OnNodeActivation(FBehaviorTreeSearchData& SearchData) override;
	virtual void OnNodeDeactivation(FBehaviorTreeSearchData& SearchData, EBTNodeResult::Type NodeResult) override;
	virtual void OnNodeProcessed(FBehaviorTreeSearchData& SearchData, EBTNodeResult::Type& NodeResult) override;
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<EMonsterState> ConditionArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Relational(OnlyTrue)"))
		ERelational ECurrentRelational;
};
