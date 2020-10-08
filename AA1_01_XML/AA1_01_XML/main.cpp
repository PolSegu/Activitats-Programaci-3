//First exercice

#include <iostream>
#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"
#include <fstream>
#include <sstream>
#include <list>
#include "enemy.h"

void showFile(rapidxml::xml_node<>* pRoot)
{
    std::string strWeapon("weapon");

    std::list<enemy> enemyList;

    for (rapidxml::xml_node<>* pEnemy = pRoot->first_node("enemy"); pEnemy; pEnemy = pEnemy->next_sibling())
    {
        std::cout << pEnemy->first_attribute()->value() << ':' << '\n';

        for (rapidxml::xml_node<>* pAtr = pEnemy->first_node(); pAtr; pAtr = pAtr->next_sibling())
        {
            std::cout << "\t" << pAtr->name() << ':' << pAtr->value() << '\n';
            if (strWeapon.compare(pAtr->name()) == 0)
            {
                for (rapidxml::xml_node<>* pWeaponAtr = pEnemy->first_node(); pWeaponAtr; pWeaponAtr = pWeaponAtr->next_sibling())
                {
                    std::cout << "\t\t" << pWeaponAtr->name() << std::endl;
                }
            }
        }
        std::cout << '\n';
    }
}

void saveEnemies(Enemies* enemies, rapidxml::xml_node<>* pRoot)
{
    std::string strWeapon("weapon");

    std::forward_list<enemy> enemyList;     // Temp list
    std::forward_list<weapon> weaponSet;    // Temp list

    int hp, dmg, def, exp, i, j;         // Enemy stats
    float aspd;                         // ...

    int id, range;                      // Weapon stats
    std::string type;                   // ...

    for (rapidxml::xml_node<>* pEnemy = pRoot->first_node("enemy"); pEnemy; pEnemy = pEnemy->next_sibling())
    {
        // pEnemy->first_attribute()->name();   // No cal guardar el nom o tipus de monstre
        i = 0;
        for (rapidxml::xml_node<>* pAtr = pEnemy->first_node(); pAtr; pAtr = pAtr->next_sibling())
        {
            switch (i)
            {
            case 0:
                hp = atoi(pAtr->value());
                break;
            case 1:
                def = atoi(pAtr->value());
                break;
            case 2:
                aspd = atof(pAtr->value());
                break;
            case 3:
                dmg = atoi(pAtr->value());
                break;
            case 4:
                exp = atoi(pAtr->value());
                break;
            default:    // Weapon or error
                if (strWeapon.compare(pAtr->name()) == 0)
                {
                    j = 0;
                    for (rapidxml::xml_node<>* pWeaponAtr = pAtr->first_node(); pWeaponAtr; pWeaponAtr = pWeaponAtr->next_sibling())
                    {
                        switch (j)
                        {
                        case 0:
                            id = atoi(pWeaponAtr->value());
                            break;
                        case 1:
                            type = pWeaponAtr->value();
                            break;
                        case 2:
                            range = atoi(pWeaponAtr->value());
                            break;

                        default:
                            std::cout << "ERROR: File format (weapon) --> " << pAtr->name() << std::endl;
                            break;
                        }

                        j++;
                    }
                    weaponSet.push_front(weapon(id, type, range));
                }
                else
                {
                    std::cout << "ERROR: File format --> " << pAtr->name() << std::endl;
                }
                break;
            }

            i++;
        }

        enemyList.push_front(enemy(hp, def, aspd, dmg, exp, weaponSet));   // Insert info into enemies variable
        weaponSet.clear();
    }

    enemies->enemyList = enemyList;
}

void showEnemies(Enemies enemies)
{
    for (enemy e : enemies.enemyList)
    {
        std::cout << "\nHP: " << e.hp << "\nDEF: " << e.defense << "\nASPD: " << e.atackSpeed << "\nDMG: " << e.damage << "\nEXP: " << e.xp << std::endl;
        std::cout << "Weapon Set: " << std::endl;
        for (weapon w : e.weaponSet)
        {
            std::cout << "\n\tID: " << w.id << "\n\tTYPE: " << w.type << "\n\tRANGE: " << w.range << std::endl;
        }
    }
}

//First exercice
int main()
{
    rapidxml::xml_document<> doc;
    std::ifstream file("config.xml");
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
    doc.parse<0>(&content[0]);

    rapidxml::xml_node<>* pRoot = doc.first_node();

    Enemies enemies;
    std::forward_list<weapon> weaponSet;

    //showFile(pRoot);

    saveEnemies(&enemies, pRoot);

    showEnemies(enemies);

    return 0;
}



































