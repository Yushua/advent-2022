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

    std::string a;
    int score = 0;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        iss >> a;
        std::string string1;
        std::string string2;
        int len1 = a.length();
        int len2 = len1 / 2;
        string1 = a.substr(0, len2);
        string2 = a.substr(len2, len1);
        std::size_t found = string1.find_first_of(string2);
        char c = string1[found];
        int i = 0;
        if (c >= 'a' && c <= 'z'){
            i = c - 96;
        }
        else {
            i = c - 38;
        }
        std::cout << i << std::endl;
        score += i;
        // std::cout << string1 << " " << string2 << " " << found << " " << c << " " << i << std::endl;
    }
    std::cout << "score == " << score << std::endl;
    return (0);
}