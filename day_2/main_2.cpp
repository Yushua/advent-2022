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
            if (a == 'A'){
                score += 3;
            }
            else if (a == 'B'){
                score += 1;
            }
            else if (a == 'C'){
                score += 2;
            }
        }//draw
        else if (b == 'Y'){
            score += 3;
            if (a == 'A'){
                score += 1;
            }
            else if (a == 'B'){
                score += 2;
            }
            else if (a == 'C'){
                score += 3;
            }
        }//win
        else if (b == 'Z'){
            score += 6;
            if (a == 'A'){
                score += 2;
            }
            else if (a == 'B'){
                score += 3;
            }
            else if (a == 'C'){
                score += 1;
            }
        }
    }
    std::cout << "score [" << score << "]\n";
    return (0);
}
