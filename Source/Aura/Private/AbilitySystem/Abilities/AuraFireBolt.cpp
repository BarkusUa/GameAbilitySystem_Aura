// No-Copyright


#include "AbilitySystem/Abilities/AuraFireBolt.h"

#include "AuraGameplayTags.h"

FString UAuraFireBolt::GetDescription(int32 Level)
{
	const int32 Damage = GetDamageByDamageType(Level, FAuraGameplayTags::Get().Damage_Fire);
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
		,Level, ManaCost, CoolDown, Damage);
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
		, Level, ManaCost, CoolDown, FMath::Min(Level, NumProjectiles), Damage);
	}
}

FString UAuraFireBolt::GetNextLevelDescription(int32 Level)
{
	const int32 Damage = GetDamageByDamageType(Level, FAuraGameplayTags::Get().Damage_Fire);
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
	, Level, ManaCost, CoolDown, FMath::Min(Level, NumProjectiles), Damage);
}