#include <fstream>
#include <iostream>
#include <sstream>

#include <string>

int main(){
    std::ifstream infile("text_1.txt");

    std::string line;

    int a;
    int i;
    int max = 0;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        if (!(iss >> a)){
            std::cout << "[" << i << "]\n";
            if (i > max)
                max = i;
            i = 0;
            }
        else{
            i += a;
        }
    }
    std::cout << "max [" << max << "]\n";
    return (0);
}

