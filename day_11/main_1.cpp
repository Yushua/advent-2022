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
            a.pop_back();
            std::list<std::string> pair;
            monkeys_used.insert(std::pair<std::string, int>(a, 0));
            items_monkeys.insert(std::pair<std::string, std::list<std::string>>(a, pair));
        }
        else if (a == "Starting"){
            std::list<std::string> items;
            iss >> a;
            while (iss >> a){
                items.push_back(a);
            }
        }
    }
    /* write it all out */
    std::map<std::string, int>::iterator it;
    for (it = monkeys_used.begin(); it != monkeys_used.end(); it++){
        std::cout << "name: " << it->first << " used: " << it->second << std::endl;
    }
    std::map<std::string, std::list<std::string>>::iterator itt;
    for (itt = items_monkeys.begin(); itt != items_monkeys.end(); itt++){
        std::cout << "name: " << itt->first << " [";
        for (std::string n : itt->second){
            std::cout << n << " ";
        }
        std::cout << "]\n";
    }
    /* loop through for (std::string n : allDir) items_monkey->second*/
}
