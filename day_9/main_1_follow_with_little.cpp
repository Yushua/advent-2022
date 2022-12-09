#include <fstream>
#include <iostream>
#include <sstream>

#include <string>

int map[1000][1000];
int S[]= {500, 500};
int H[]= {500, 500};
int L[]= {500, 500};

void checkL(){
    int yH = H[0];
    int xH = H[1];
    int yL = L[0];
    int xL = L[1];
    int y = yH - yL;
    int x = xH - xL;

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
    return ;
}

/* instead of using the H_lastPosition
instead I need to check WHERE L is, I know its not there, so then need to know WHERE its not exacly, and then move accordingly

for example, if H and L are on the same Y, then I should move towards it. maybe substracting it and then adding it to L
same with if they're on the same X, subtract Y
if now, then substract ALL both of them? or I could just do that always?

what if the answer is that the position change needs to be in checkL for example xH = 4 and lx = 2 after xH moved one right. then xH - xL = 2 and add that to xL will get me 4

if xH was 2 and lX 4 then xH - lX = -2 and add that to lX == yL BUT, then I need to substract or add so it doesn't BECOME the same one

however doing so seems to cause a problem, it keeps.. not doing the logic, so whats the logic then?
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
