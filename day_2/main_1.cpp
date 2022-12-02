#include <fstream>
#include <iostream>
#include <sstream>

#include <string>

/*
A = rock = X = 1
B = paper = Y = 2
C = Scissors = Z = 3

Lost = 0 = X
Draw = 3 = Y
Win = 6 = Z

*/
int main(){
    std::ifstream infile("text_1.txt");

    std::string line;

    char a, b;
    int i;
    int score = 0;
    while (std::getline(infile, line))
    {
        std::istringstream input(line);
        input >> a >> b;
        std::cout << "[" << b << "][" << a << "]" << score << std::endl;
        //lose
        if (b == 'X'){
            score += 1;
            if (a == 'A'){
                score += 3;
            }
            else if (a == 'C'){
                score += 6;
            }
        }//draw
        else if (b == 'Y'){
            score += 2;
            if (a == 'B'){
                score += 3;
            }
            else if (a == 'A'){
                score += 6;
            }
        }//win
        else if (b == 'Z'){
            score += 3;
            if (a == 'C'){
                score += 3;
            }
            else if (a == 'B'){
                score += 6;
            }
        }
    }
    std::cout << "score [" << score << "]\n";
    return (0);
}