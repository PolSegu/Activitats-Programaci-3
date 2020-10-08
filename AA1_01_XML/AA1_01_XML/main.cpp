//First exercice

#include <iostream> 
#include <vector> 
#include <fstream> 
#include <sstream> 
#include <list> 
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"
#include "enemy.h"
#include "weapon.h"

int main()
{
	rapidxml::xml_document<> doc;
	std::ofstream file("config.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	rapidxml::xml_node<>* pRoot = doc.first_node();

	std::list<enemy> enemyList;

	for (rapidxml::xml_node<>* pNode = pRoot->first_node("Enemy"); pNode; pNode = pNode->next_sibling())
	{
		std::cout << pNode->name() << ':' << '\n';

		for (rapidxml::xml_node<>* pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling())
		{
			std::cout << pNodeI->name() << ':' << pNodeI->value() << '\n';
		};
		std::cout << '\n';
	}

	/*
	rapidxml::xml_node<> *pRoot = doc.first_node();
	std::list<enemy> enemyList
	
	enemyList.vit = doc;
	*/

	return 0;
}



































