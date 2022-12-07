#include <fstream>
#include <iostream>
#include <sstream>

#include <string>
#include <map>
#include <vector>
#include <list>

int main(){
    std::ifstream infileTmp("text_1.txt");

    std::string line;
    std::list<std::string> pwd;

    std::string a;

    std::map<std::string, long int> directories;
    directories.insert(std::pair<std::string, long int>("/", 0));
    while (std::getline(infileTmp, line)){
        std::istringstream iss(line);
        iss >> a;
        if (a == "dir"){
            iss >> a;
            /* addig director */
            directories.insert(std::pair<std::string, long int>(a, 0));
        }
    }

    std::ifstream infile("text_1.txt");

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
            for (std::string n : pwd){
                std::map<std::string, long int>::iterator it;
                int check = 0;
                for (it = directories.begin(); it != directories.end(); it++){
                    if (n == it->first){
                        it->second += size;
                        check = 1;
                    }
                }
                if (check == 0){
                    std::cout << "name [" << n << "]\n";
                }
            }
        }
        else if (a == "$"){
            iss >> a;
            if (a == "cd")
            {
                iss >> a;
                if (a == ".."){
                    pwd.pop_back();
                }
                else {
                    pwd.push_back(a);
                }
            }
        }
    }

    int long score = 0;
    std::map<std::string, long int>::iterator it;
    for (it = directories.begin(); it != directories.end(); it++){
        if (it->second <= 100000){
            score += it->second;
            // std::cout << "name [" << it->first << "] size [" << it->second << "]\n";
        }
    }
    std::cout << "1score [" << score << "]\n";
    return (0);
}

