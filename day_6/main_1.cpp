#include <fstream>
#include <iostream>
#include <sstream>

#include <string>

bool uniqueCharacters(std::string str)
{
    for (int i = 0; i < str.length() - 1; i++) {
        for (int j = i + 1; j < str.length(); j++) {
            if (str[i] == str[j]) {
                return false;
            }
        }
    }
    return true;
}

int main(){
    std::ifstream infile("text_1.txt");

    std::string line;

    std::string a;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        iss >> a;
        int x = 0;
        while (x + 4 < a.size()){
            std::string sub = a.substr(x,4);
            if (uniqueCharacters(sub) == true){
                std::cout << sub << " " << x + 4 << std::endl;
                break ;
            }
            x++;
        }
    }
    return (0);
}

