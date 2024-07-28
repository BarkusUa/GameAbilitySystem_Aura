// No-Copyright


#include "AbilitySystem/Abilities/ArcaneShards.h"

FString UArcaneShards::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float CoolDown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(
			TEXT(""
		"<Title>ARCANE SHARDS</>"
		"\n"
		"\n"
		"<Small>Level: </><Level>%d</>"//Level
		"\n"
		"<Small>Mana Cost: </><ManaCost>%.1f</>"//ManaCost
		"\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>"//Cooldown
		"\n"
		"\n"
		"<Default>Summon shards of arcane energy and causing </><Damage>%d</><Default> arcane damage with a knockback power.</>")//Damage
		,Level, ManaCost, CoolDown, ScaledDamage);
	}
	else
	{
		return FString::Printf(
			TEXT(""
		"<Title> ARCANE SHARDS</>"
		"\n"
		"\n"
		"<Small>Level: </><Level>%d</>"//Level
		"\n"
		"<Small>Mana Cost: </><ManaCost>%.1f</>"//ManaCost
		"\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>"//Cooldown
		"\n"
		"\n"
		"<Default>Summon %d additional arcane shards inside of the magic cirle causing </><Damage>%d</><Default> arcane damage with a knockback power.</>")//projectile number and damage
		, Level, ManaCost, CoolDown, FMath::Min(Level, MaxNumShards - 1), ScaledDamage);
	}
}

FString UArcaneShards::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float CoolDown = GetCooldown(Level);
	return FString::Printf(
			TEXT(""
		"<Title> NEXT LEVEL/>"
		"\n"
		"\n"
		"<Small>Level: </><Level>%d</>"//Level
		"\n"
		"<Small>Mana Cost: </><ManaCost>%.1f</>"//ManaCost
		"\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>"//Cooldown
		"\n"
		"\n"
		"<Default>Summon %d arcane shards inside of the magic cirle causing </><Damage>%d</><Default> arcane damage with a knockback power.</>")//projectile number and damage
		, Level, ManaCost, CoolDown, FMath::Min(Level, MaxNumShards), ScaledDamage);
}
