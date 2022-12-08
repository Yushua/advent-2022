#include <fstream>
#include <iostream>
#include <sstream>

#include <string>

int map[99][99];

/* looking UP from THIS three */
int checkUp(int y, int x, int pos){
    int count = 0;
    if (y == 0)
        return count;
    y--;
    count++;
    while (y > 0){
        if (map[y][x] >= pos){
            return (count);
        }
        count++;
        y--;
    }
    return (count);
}

/* looking DOWN from THIS three */
int checkDown(int y, int x, int pos){
    int count = 0;
    if (y == 99 - 1)
        return count;
    y += 1;
    count++;
    while (y < 99 - 1){
        if (map[y][x] >= pos){
            return (count);
        }
        count++;
        y++;
    }
    return (count);
}

/* looking LEFT from THIS three */
int checkLeft(int y, int x, int pos){
    int count = 0;
    if (x == 0)
        return count;
    x--;
    count++;
    while (x > 0){
        if (map[y][x] >= pos){
            return (count);
        }
        count++;
        x--;
    }
    return (count);
}

/* looking RIGHT from THIS three */
int checkRight(int y, int x, int pos){
    int count = 0;
    if (x == 99 - 1)
        return count;
    x += 1;
    count++;
    while (x < 99 - 1){
        if (map[y][x] >= pos){
            // std::cout << "right " << map[y][x] << std::endl;
            return (count);
        }
        count++;
        x++;
    }
    return (count);
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
        for (int y = 0; y < 99; y++){
            for(int x = 0; x < 99; x++){
                int pos = map[y][x];
                int view = 1;
                // std::cout << "poss == [" << pos << "] ";
                int tmp;
                tmp = checkUp(y, x, pos);
                // std::cout << "u[" << tmp << "]";
                view *= tmp;
                tmp = checkDown(y, x, pos);
                // std::cout << "d[" << tmp << "]";
                view *= tmp;
                tmp = checkLeft(y, x, pos);
                // std::cout << "l[" << tmp << "]";
                view *= tmp;
                tmp = checkRight(y, x, pos);
                // std::cout << "r[" << tmp << "]";
                view *= tmp;
                // std::cout << " view [" << view << "]\n";
                if (view > max){
                    max = view;
                }
            }
            // std::cout << "\n\n";
        }
    }
    std::cout << "max [" << max << "]\n";
    return (0);
}
