#include <fstream>
#include <iostream>
#include <sstream>

#include <string>

int map[99][99];

/* looking UP from THIS three */
int checkUp(int y, int x, int pos){
    y -= 1;
    while (y >= 0){
        if (map[y][x] >= pos){
            // std::cout << "up " << map[y][x] << std::endl;
            return (1);
        }
        y--;
    }
    return (-1);
}

/* looking DOWN from THIS three */
int checkDown(int y, int x, int pos){
    y += 1; //going one more else you're on the same one
    while (y < 99){
        if (map[y][x] >= pos){
            // std::cout << "down " << map[y][x] << std::endl;
            return (1);
        }
        y++;
    }
    return (-1);
}

/* looking LEFT from THIS three */
int checkLeft(int y, int x, int pos){
    x -= 1;
    while (x >= 0){
        if (map[y][x] >= pos){
            // std::cout << "left " << map[y][x] << std::endl;
            return (1);
        }
        x--;
    }
    return (-1);
}

/* looking RIGHT from THIS three */
int checkRight(int y, int x, int pos){
    x += 1;
    while (x < 99){
        if (map[y][x] >= pos){
            // std::cout << "right " << map[y][x] << std::endl;
            return (1);
        }
        x++;
    }
    return (-1);
}

int main(){
    std::ifstream infile("text_1.txt");
    std::string line;
    int size = 99;
    int height = 99;
    int max = 0;
    {
        int y = 0;
        while (std::getline(infile, line))
        {
            for(int x = 0; x < 99; x++){
                map[y][x] = line[x] - '0';
            }
            y++;
        }
    }
    /* check the trees that have to be checked
        so no outer edges */
    int score = 99 * 99;
    {
        for (int y = 1; y < 99; y++){
            for(int x = 1; x < 99; x++){
                int pos = map[y][x];
                if (checkUp(y, x, pos) == 1 && checkDown(y, x, pos) == 1 && checkLeft(y, x, pos) == 1 && checkRight(y, x, pos) == 1){
                    score--;
                }
            }
            // std::cout << "\n\n";
        }
    }
    std::cout << "score [" << score << "]\n";
    return (0);
}
