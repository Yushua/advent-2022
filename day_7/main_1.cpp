#include <fstream>
#include <iostream>
#include <sstream>

#include <string>
#include <map>
#include <vector>
#include <list>

int main(){
    std::ifstream infile("text_1.txt");

    std::string line;
    std::list<std::string> position;

    std::string a;

    std::map<std::string, long int> dirSize;
    while (std::getline(infile, line))
    {
        
        std::istringstream iss(line);
        iss >> a;
        if (a == "$"){
            iss >> a;
            if (a == "cd"){
                iss >> a;
                if (a == ".."){
                    position.pop_back();
                }
                else {
                    position.push_back(a);
                    dirSize.insert(std::pair<std::string, long int>(a, 0));
                }
            }
            else if (a == "ls"){
                if (a.find_first_of("0123456789") == std::string::npos){
                    int long size = atoi(a.c_str());
                    for (std::string n : position){
                        std::map<std::string, long int>::iterator it;
                        for (it = dirSize.begin(); it != dirSize.end(); it++){
                            if (n == it->first){
                                it->second += size;
                            }
                        }
                    }

                }
            }
        }
    }
    std::map<std::string, long int>::iterator it;
    for (it = dirSize.begin(); it != dirSize.end(); it++){
        std::cout << "name [" << it->first << "] size [" << it->second << "]\n";
    }
    return (0);
}

