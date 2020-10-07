#include <forward_list>
#include "weapon.h"
struct enemy
{
	int hp;
	int defence;
	float atackSpeed;
	int damage;
	int xp;
	std::forward_list<weapon>  weaponSet;


};