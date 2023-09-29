// Copyright Abdallah Saeed


#include "Character/AuraEnemy.h"
#include "Aura/Aura.h"

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void AAuraEnemy::HighlightActor()
{
	if(GetMesh() && Weapon)
	{
		GetMesh()->SetRenderCustomDepth(true);
		GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
		
		Weapon->SetRenderCustomDepth(true);
		Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	}
}

void AAuraEnemy::UnHighlightActor()
{
	if(GetMesh() && Weapon)
	{
		GetMesh()->SetRenderCustomDepth(false);
		Weapon->SetRenderCustomDepth(false);
	}
}
