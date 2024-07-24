// No-Copyright


#include "AbilitySystem/Abilities/AuraFireBolt.h"

#include "AuraGameplayTags.h"
#include "Kismet/KismetSystemLibrary.h"

FString UAuraFireBolt::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float CoolDown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(
			TEXT(""
		"<Title>FIRE BOLT</>"
		"\n"
		"\n"
		"<Small>Level: </><Level>%d</>"//Level
		"\n"
		"<Small>Mana Cost: </><ManaCost>%.1f</>"//ManaCost
		"\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>"//Cooldown
		"\n"
		"\n"
		"<Default>Launches a bolt of fire, explodes on impact and dealing damage</><Damage>%d</><Default>fire damage with a chance to burn</>")//Damage
		,Level, ManaCost, CoolDown, ScaledDamage);
	}
	else
	{
		return FString::Printf(
			TEXT(""
		"<Title> FIRE BOLT</>"
		"\n"
		"\n"
		"<Small>Level: </><Level>%d</>"//Level
		"\n"
		"<Small>Mana Cost: </><ManaCost>%.1f</>"//ManaCost
		"\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>"//Cooldown
		"\n"
		"\n"
		"<Default>Launches %d bolts of fire, explodes on impact and dealing </><Damage>%d</><Default>fire damage with a chance to burn</>")//projectile number and damage
		, Level, ManaCost, CoolDown, FMath::Min(Level, NumProjectiles), ScaledDamage);
	}
}

FString UAuraFireBolt::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float CoolDown = GetCooldown(Level);
	return FString::Printf(
		TEXT(""
	"<Title> NEXT LEVEL: </>"
	"\n"
	"\n"
	"<Small>Level: </><Level>%d</>"//Level
	"\n"
	"<Small>Mana Cost: </><ManaCost>%.1f</>"//ManaCost
	"\n"
	"<Small>Cooldown: </><Cooldown>%.1f</>"//Cooldown
	"\n"
	"\n"
	"<Default>Launches %d bolts of fire, explodes on impact and dealing </><Damage>%d</><Default>fire damage with a chance to burn</>")//projectile number and damage
	, Level, ManaCost, CoolDown, FMath::Min(Level, NumProjectiles), ScaledDamage);
}

void UAuraFireBolt::SpawnProjectiles(const FVector& ProjectileTargetLocation, const FGameplayTag& SocketTag,
	bool bOverridePitch, float PitchOverride, AActor* HomingTarget)
{
	const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority();
	if (!bIsServer) return;
	
	const FVector SocketLocation = ICombatInterface::Execute_GetCombatSocketLocation(GetAvatarActorFromActorInfo(), SocketTag);
	FRotator Rotation = (ProjectileTargetLocation - SocketLocation).Rotation();
	if (bOverridePitch) Rotation.Pitch = PitchOverride;

	const FVector Forward = Rotation.Vector();
	const FVector LeftOfSpread = Forward.RotateAngleAxis(-ProjectileSpread / 2.f, FVector::UpVector);
	const FVector RightOfSpread = Forward.RotateAngleAxis(ProjectileSpread / 2.f, FVector::UpVector);

	//NumProjectiles = FMath::Min(MaxNumProjectiles, GetAbilityLevel());
	if (NumProjectiles > 1)
	{
		const float DeltaSpread = ProjectileSpread / (NumProjectiles - 1);
		for (int32 i = 0; i < NumProjectiles; i++)
		{
			const FVector Direction = LeftOfSpread.RotateAngleAxis(DeltaSpread * i, FVector::UpVector);
			const FVector Start = SocketLocation + FVector(0, 0, 10);
			UKismetSystemLibrary::DrawDebugArrow(
				GetAvatarActorFromActorInfo(),
				Start,
				Start + Direction * 55.f,
				5,
				FLinearColor::Red,
				120,
				2);
		}
	}
	else
	{
		const FVector Start = SocketLocation + FVector(0, 0, 10);
		UKismetSystemLibrary::DrawDebugArrow(
			GetAvatarActorFromActorInfo(),
			SocketLocation,
			SocketLocation + Forward * 55.f,
			5,
			FLinearColor::Red,
			120,
			2);
	}

	UKismetSystemLibrary::DrawDebugArrow(GetAvatarActorFromActorInfo(), SocketLocation, SocketLocation + Rotation.Vector() * 100.f, 5, FLinearColor::White, 120, 2);
	UKismetSystemLibrary::DrawDebugArrow(GetAvatarActorFromActorInfo(), SocketLocation, SocketLocation + LeftOfSpread * 100.f, 5, FLinearColor::Gray, 120, 2);
	UKismetSystemLibrary::DrawDebugArrow(GetAvatarActorFromActorInfo(), SocketLocation, SocketLocation + RightOfSpread * 100.f, 5, FLinearColor::Green, 120, 2);
}
