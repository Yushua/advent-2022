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

    /* name, size, dir in it */
    std::map<std::string, long int> dirSize;
    std::map<std::string, std::list<std::string>> dirDirInIt;
    std::string filesIn;
    std::getline(infile, line);

    /* name, the size of this director */
    dirSize.insert(std::pair<std::string, long int>("/", 0));

    /* name, directories in it */
    dirDirInIt.insert(std::pair<std::string, std::list<std::string>>("/", {}));

    std::string a;
    std::istringstream iss(line);
    std::list<std::string> position {"/"};
    std::string currentDir = "/";
    iss >> a;
    while (std::getline(infile, line))
    {
        if (a == "$"){
            iss >> a;
            if (a == "ls"){
                while (true){
                    std::istringstream iss(line);
                    /* if its money, go back and continue again */
                    if (a == "$"){
                        break ;
                    }
                    if (a == "dir"){
                        
                    }
                }

            }
        }
    }
    return (0);
}

