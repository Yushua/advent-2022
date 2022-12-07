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
    std::list<std::string> allDir;

    std::string a;

    std::map<std::string, long int> dirSize;
    std::map<std::string, long int> dirSizeExtra;
    allDir.push_back("/");
    while (std::getline(infile, line))
    {
        /* plan d, 
        
        when you see dir you add to it
        when c you add - to it to know that. you are now in that multi thread
        
        this way by adding to it, you always know ALL the directories you're in
        
        then when its .. you remove till you find -
        
        */

        std::istringstream iss(line);
        iss >> a;
        if (a.find_first_of("0123456789") != std::string::npos)
        {
            int long size = atoi(a.c_str());
            for (std::string n : position){
                std::map<std::string, long int>::iterator it;
                for (it = dirSize.begin(); it != dirSize.end(); it++){
                    if (n == it->first){
                        it->second += size;
                    }
                }
            }
            /* adding all to the*/
            for (std::string n : allDir){
                std::map<std::string, long int>::iterator it;
                for (it = dirSizeExtra.begin(); it != dirSizeExtra.end(); it++){
                    if (n == it->first){
                        it->second += size;
                    }
                }
            }
        }
        else if (a == "dir"){
            iss >> a;
            /* now havin added the dir */
            allDir.push_back(a);
        }
        else if (a == "$"){
            iss >> a;
            if (a == "cd")
            {
                iss >> a;
                if (a == ".."){
                    position.pop_back();
                    //loop through all dir, until you see -
                    while (allDir.back() != "-"){
                        allDir.pop_back();
                    }
                }
                else {
                    position.push_back(a);
                    allDir.push_back("-");
                    dirSize.insert(std::pair<std::string, long int>(a, 0));
                    dirSizeExtra.insert(std::pair<std::string, long int>(a, 0));
                }
            }
        }
    }

    int long score = 0;
    std::map<std::string, long int>::iterator it;
    for (it = dirSize.begin(); it != dirSize.end(); it++){
        if (it->second <= 100000){
            score += it->second;
            // std::cout << "name [" << it->first << "] size [" << it->second << "]\n";
        }
    }
    std::cout << "1score [" << score << "]\n";
    for (it = dirSizeExtra.begin(); it != dirSizeExtra.end(); it++){
        if (it->second <= 100000){
            score += it->second;
            // std::cout << "name [" << it->first << "] size [" << it->second << "]\n";
        }
    }
    std::cout << "2score [" << score << "]\n";
    return (0);
}

