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

    std::map<std::string, long int>::iterator it;
    int size_space = 70000000;
    int spaceLeft = 1316134911;
    int sizeCut;

    for (it = directories.begin(); it != directories.end(); it++){
        if (it->first == "/"){
            size_space -= it->second;
        }
        else {
            int store = it->second - (30000000 - size_space);
            if (store < spaceLeft && store >= 0){
                spaceLeft = store;
                sizeCut = it->second;
            }
        }
    }
    std::cout << "cut = [" << sizeCut << "]\n";
    return (0);
}

