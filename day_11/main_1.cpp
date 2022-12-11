#include <fstream>
#include <iostream>
#include <sstream>

#include <string>
#include <map>
#include <tuple>
#include <list>

/* how worried you are about each item. */

std::list<std::string> items;

/* name, items */
std::map<std::string, std::list<std::string>> items_monkeys;
/* name, times*/
std::map<std::string, int> monkeys_used;

int main(){
    std::ifstream infile("text_1.txt");

    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        std::string a;
        iss >> a;
        if (a == "Monkey"){
            iss >> a;
            std::list<std::string> pair;
            monkeys_used.insert(std::pair<std::string, long int>(a, 0));
            items_monkeys.insert(std::pair<std::string, std::list<std::string>>(a, pair));
        }
    }
    /* write it all out */
}
