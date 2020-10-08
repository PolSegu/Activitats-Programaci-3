#include <forward_list>
#include "weapon.h"

struct enemy
{
	int hp;
	int damage;
	int defense;
	float atackSpeed;
	int xp;
	std::forward_list<weapon>  weaponSet;

	enemy(int inHp, int inDefense, float inAtackSpeed, int inDamage, int inXp, std::forward_list<weapon> inWeaponSet) : 
		hp(inHp), damage(inDamage), defense(inDefense), atackSpeed(inAtackSpeed), xp(inXp), weaponSet(inWeaponSet)
	{};


};

struct Enemies
{
	std::forward_list<enemy> enemyList;

};

