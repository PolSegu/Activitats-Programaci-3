//First exercice

#include <iostream> 
#include <vector> 
#include <list> 
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"

int main()
{
	rapidxml::xml_document<> doc;

	std::ifstream file ("config.xml");
	std::string str;
	rapidxml::print(std::back_inserter(str), doc, 0);
	file.close();

	std::cout << str;


	/*
	rapidxml::xml_node<> *pRoot = doc.first_node();
	std::list<enemy> enemyList
	
	enemyList.vit = doc

	*/

	return 0;
}



































