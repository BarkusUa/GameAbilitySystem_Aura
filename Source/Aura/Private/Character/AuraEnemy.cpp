// No-Copyright


#include "Character/AuraEnemy.h"

#include "Aura/Aura.h"

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void AAuraEnemy::HighlightActor()
{
	UE_LOG(LogTemp, Warning, TEXT("highlighted"))
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(Custom_Depth_Red);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(Custom_Depth_Red);
}

void AAuraEnemy::UnHighlightActor()
{
	UE_LOG(LogTemp, Warning, TEXT("unhighlighted"))
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}
