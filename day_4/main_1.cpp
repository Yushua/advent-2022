#include <fstream>
#include <sstream>

#include <string>
#include <algorithm>
#include <array>
#include <iomanip>
#include <utility>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iterator>

int main(){
    std::ifstream infile("text_1.txt");

    std::string line;

    std::string string;
    int score = 0;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        iss >> string;
        int a1, b1, a2, b2;
        int i = 0;
        i = string.find("-");
        i++;
        a1 = atoi(string.substr(0, i).c_str());
        string.erase(0, i);

        i = string.find(",");
        i++;
        b1 = atoi(string.substr(0, i).c_str());
        string.erase(0, i);

        i = string.find("-");
        i++;
        a2 = atoi(string.substr(0, i).c_str());
        string.erase(0, i);
        
        b2 = atoi(string.c_str());
        std::cout << a1 << " " << b1 << " " << a2 << " " << b2 << std::endl;
        if ((a1 < a2 || a1 == a2) && (b1 > b2 || b1 == b2)){
            score += 1;
        }
        else if ((a2 < a1 || a2 == a1) && (b2 > b1 || b2 == b1)){
            score += 1;
        }
    }
    std::cout << "score == " << score << std::endl;
    return (0);
}