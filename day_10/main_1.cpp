#include <fstream>
#include <iostream>
#include <sstream>

#include <string>

int main(){
    std::ifstream infile("text_1.txt");

    std::string line;
    int cycle = 0;
    int X = 1;
    int check = 20;
    int loops = 0;
    int score = 0;
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
            if (cycle >= 20){
                if (cycle == check || cycle == 20){
                    check += 40;
                    std::cout << "result == " << cycle * X << " X == " << X << std::endl;
                    score += (cycle * X);
                }
            }
            cycle += 1;
        }
        if (cycle == check || cycle == 20){
            check += 40;
            std::cout << "result == " << cycle * X << " X == " << X << std::endl;
            score += (cycle * X);
        }
        X += increase;
    }
    std::cout << "score " << score << std::endl;
    return (0);
}