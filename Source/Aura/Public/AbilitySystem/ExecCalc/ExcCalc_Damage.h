// No-Copyright

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "ExcCalc_Damage.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UExcCalc_Damage : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	
	UExcCalc_Damage();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
