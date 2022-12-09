#include <fstream>
#include <iostream>
#include <sstream>

#include <string>

int map[1000][1000];
int S[]= {500, 500};
int H[]= {500, 500};
int L[]= {500, 500};

bool checkCordinates(int y, int x, int cy, int cx){
    if (y == cy && x == cx){
        return (true);
    }
    return (false);
}

void checkL(){
    int yH = H[0];
    int xH = H[1];
    int yL = L[0];
    int xL = L[1];
    int y = yH - yL;
    int x = xH - xL;
    if (checkCordinates(yL, xL, yH - 1, xH - 1) || checkCordinates(yL, xL, yH - 1, xH) || checkCordinates(yL, xL, yH - 1, xH + 1)
        || checkCordinates(yL, xL, yH, xH - 1) || checkCordinates(yL, xL, yH, xH + 1)
        || checkCordinates(yL, xL, yH + 1, xH - 1) || checkCordinates(yL, xL, yH + 1, xH) || checkCordinates(yL, xL, yH + 1, xH + 1))
        {
            std::cout << "hey\n";
            return ;
        }
    else{
        if (y < 0){
            y++;
        }
        else if (y > 0){
            y--;
        }
        L[0] += y;
        if (x < 0){
            x++;
        }
        else if (x > 0){
            x--;
        }
        L[1] += x;
        map[L[0]][L[1]] = 1;
    }
    return ;
}

/* instead of using the H_lastPosition
so i'm using the follow_with_little logic, but

the first BUT WHEN i MOVE, I NEED TO MAKE SURE NOT TO GET IN THE EXACT POSITION, thats why I need to check first all around. only then maybe?
*/

void directionRight(int move){
    for (int i = 0; i < move; i++){
        H[1]++;
        checkL();
        std::cout << L[0] << " " << L[1] <<" | right " << H[0] << " " << H[1]  << std::endl;
    }
}

void directionLeft(int move){
    for (int i = 0; i < move; i++){
        H[1]--;
        checkL();
        std::cout << L[0] << " " << L[1] <<" | right " << H[0] << " " << H[1]  << std::endl;
    }
}

void directionUp(int move){
    for (int i = 0; i < move; i++){
        H[0]--;
        checkL();
        std::cout << L[0] << " " << L[1] <<" | right " << H[0] << " " << H[1]  << std::endl;
    }
}

void directionDown(int move){
    for (int i = 0; i < move; i++){
        H[0]++;
        checkL();
        std::cout << L[0] << " " << L[1] <<" | right " << H[0] << " " << H[1]  << std::endl;
    }
}

int main(){
    std::ifstream infile("text_1.txt");

    std::string line;
    for (int y = 0; y < 1000 ; y++){
        for(int x = 0; x < 1000; x++){
            map[y][x] = 0;
        }
    }
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        std::string direction;
        int move;
        iss >> direction >> move;

        if (direction == "R"){
            directionRight(move);
        }
        else if (direction == "L"){
            directionLeft(move);
        }
        else if (direction == "U"){
            directionUp(move);
        }
        else if (direction == "D"){
            directionDown(move);
        }
    }
    int score = 0;
    for (int y = 0; y < 1000 ; y++){
        for(int x = 0; x < 1000; x++){
            if (map[y][x] == 1){
                score++;
            }
        }
    }
    std::cout << "score " << score << std::endl;
    return (0);
}
