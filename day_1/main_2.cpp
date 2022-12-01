#include <fstream>
#include <iostream>
#include <sstream>

#include <string>
#include <algorithm>
#include <array>

int main(){
    std::ifstream infile("text_2");

    std::string line;

    int a;
    int i;
    std::array<int, 3> max = {0, 0, 0};
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        if (!(iss >> a)){
            for (int y = 0; y < 3; y++){
                if (i > max[y])
                    max[y] = i;
                    break;
            }
            std::sort(max.begin(), max.end());
            i = 0;
            }
        else{
            i += a;
        }
    }
    int store = 0;
    for (auto a : max) {
            std::cout << "max [" << a << "]\n";
            store += a;
        }
    std::cout << "store [" << store << "]\n";
    return (0);
}
