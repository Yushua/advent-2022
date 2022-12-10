#include <fstream>
#include <iostream>
#include <sstream>

#include <string>
std::string map[1][40];

int main(){
    std::ifstream infile("text_1.txt");

    std::string line;
    int cycle = 0;
    int position = 1;
    int check = 20;
    int loops = 0;
    int score = 0;
    for (int x = 0; x < 40; x++){
        map[0][x] = ".";
    }
    int y = 0;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        std::string exection;
        int increase;
        iss >> exection;
        if (exection == "noop"){
            loops = 1;
            increase = 0;
        }
        else if (exection == "addx"){
            loops = 2;
            iss >> increase;
        }
        for (int i = 0; i < loops; i++){
            if (cycle%40 == 0 && cycle > 0){
                for (int x = 0; x < 40; x++){
                    std::cout << map[0][x];
                }
                for (int x = 0; x < 40; x++){
                    map[0][x] = ".";
                }
                std::cout << "\n";
            }
            int pos = cycle%40;
            if (position - 1 == pos || position == pos || position + 1 == pos){
                map[y][pos] = "#";
            }
            else{
                map[y][pos] = ".";
            }
            if (cycle >= 20){
                if (cycle == check || cycle == 20){
                    check += 40;
                    score += (cycle * position);
                }
            }
            cycle += 1;
        }
        if (cycle == check || cycle == 20){
            check += 40;
            score += (cycle * position);
        }
        position += increase;
        // std::cout << " X == " << position << std::endl;
    }
    for (int x = 0; x < 40; x++){
        std::cout << map[0][x];
    }
    std::cout << "\n\n";
    std::cout << "score " << cycle << std::endl;
    return (0);
}