// No-Copyright


#include "AbilitySystem/Abilities/Electrocute.h"

FString UElectrocute::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float CoolDown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(
			TEXT(""
		"<Title>ELECTROCUTE</>"
		"\n"
		"\n"
		"<Small>Level: </><Level>%d</>"//Level
		"\n"
		"<Small>Mana Cost: </><ManaCost>%.1f</>"//ManaCost
		"\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>"//Cooldown
		"\n"
		"\n"
		"<Default>Emits ligthning beam repeatedly casuing </><Damage>%d</><Default> electro damage with an end of stun</>")//Damage
		,Level, ManaCost, CoolDown, ScaledDamage);
	}
	else
	{
		return FString::Printf(
			TEXT(""
		"<Title> ELECTROCUTE</>"
		"\n"
		"\n"
		"<Small>Level: </><Level>%d</>"//Level
		"\n"
		"<Small>Mana Cost: </><ManaCost>%.1f</>"//ManaCost
		"\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>"//Cooldown
		"\n"
		"\n"
		"<Default>Emits ligthning beam propogeting %d additional targets nearby, repeatedly casuing  </><Damage>%d</><Default> electro damage with an end of stun</>")//projectile number and damage
		, Level, ManaCost, CoolDown, FMath::Min(Level, MaxNumShockTarget - 1), ScaledDamage);
	}
}

FString UElectrocute::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float CoolDown = GetCooldown(Level);
	{
		return FString::Printf(
			TEXT(""
		"<Title> NEXT LEVEL</>"
		"\n"
		"\n"
		"<Small>Level: </><Level>%d</>"//Level
		"\n"
		"<Small>Mana Cost: </><ManaCost>%.1f</>"//ManaCost
		"\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>"//Cooldown
		"\n"
		"\n"
		"<Default>Emits ligthning beam propogeting %d additional targets nearby, repeatedly casuing  </><Damage>%d</><Default> electro damage with an end of stun</>")//projectile number and damage
		, Level, ManaCost, CoolDown, FMath::Min(Level, MaxNumShockTarget - 1), ScaledDamage);
	}
}
