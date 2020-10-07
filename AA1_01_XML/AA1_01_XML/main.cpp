//First exercice

#include <iostream> 
#include <vector> 
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"

int main()
{
	rapidxml::xml_document<> doc;

	std::ifstream file ("config.xml");
	std::string str;
	print(std::back_inserter(str), doc, 0);
	file.close();

	std::cout << str;



}



































