#include <fstream>
#include <iostream>
#include <sstream>

#include <string>
#include <algorithm>
#include <array>
#include <iomanip>
#include <utility>
#include <iostream>
#include <stdexcept>

int main(){
    std::ifstream infile("text_1.txt");

    std::string line;

    std::string a, b, c;
    int score = 0;
    while (std::getline(infile, line))
    {
        std::istringstream iss1(line);
        iss1 >> a;
        std::getline(infile, line);
        std::istringstream iss2(line);
        iss2 >> b;
        std::getline(infile, line);
        std::istringstream iss3(line);
        iss3 >> c;
        std::cout << a << " " << b << " " << c  << std::endl;
    }
    std::cout << "score == " << score << std::endl;
    return (0);
}