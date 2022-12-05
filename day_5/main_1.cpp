#include <fstream>
#include <iostream>
#include <sstream>

#include <string>
#include <map>
#include <vector>


int main(){
    std::ifstream infile("text_1.txt");

    std::string line;
    std::map<std::string, std::string> cargo;

    // cargo.insert(std::pair<std::string, std::string>("1", "ZN"));
    // cargo.insert(std::pair<std::string, std::string>("2", "MCD"));
    // cargo.insert(std::pair<std::string, std::string>("3", "P"));

    cargo.insert(std::pair<std::string, std::string>("1", "RNFVLJSM"));
    cargo.insert(std::pair<std::string, std::string>("2", "PNDZFJWH"));
    cargo.insert(std::pair<std::string, std::string>("3", "WRCDG"));
    cargo.insert(std::pair<std::string, std::string>("4", "NBS"));
    cargo.insert(std::pair<std::string, std::string>("5", "MZWPCBFN"));
    cargo.insert(std::pair<std::string, std::string>("6", "PRMW"));
    cargo.insert(std::pair<std::string, std::string>("7", "RTNGLSW"));
    cargo.insert(std::pair<std::string, std::string>("8", "QTHFNBV"));
    cargo.insert(std::pair<std::string, std::string>("9", "LMHZNF"));
    std::map<std::string, std::string>::iterator itrr;
    for (itrr = cargo.begin(); itrr != cargo.end(); ++itrr){
        std::cout << "start " << itrr->second << std::endl;
    }
    std::cout << "now\n";
    while (std::getline(infile, line))
    {
        std::string l, ll, lll;
        std::string posa, posb;
        int amounth;

        std::istringstream iss(line);
        iss >> l >> amounth >> ll >> posa >> lll >> posb;
        std::cout << amounth << " " << posa << " " << posb << "]\n";

        std::map<std::string, std::string>::iterator itr;

        std::string movea;
        for (itr = cargo.begin(); itr != cargo.end(); ++itr){
            if (itr->first == posa){
                // std::cout << "before 1 " << itr->second << std::endl;
                movea = itr->second.substr(itr->second.size() - amounth, itr->second.size());
                int i = 0;
                while (i < amounth){
                    itr->second.pop_back();
                    i++;
                }
                // std::cout << "after 1 " << itr->second << " store [" << movea << "]" << std::endl;
                break ;
            }
        }
        std::map<std::string, std::string>::iterator itrn;
        for (itrn = cargo.begin(); itrn != cargo.end(); ++itrn){
            if (itrn->first == posb){
                // std::cout << "before 2 " << itrn->second << " add [" << movea << "]" << movea.size() << std::endl;
                int y = 0;
                int size = movea.size();
                while (y < size){
                    itrn->second += movea.back();
                    movea.pop_back();
                    y++;
                }
                // itrn->second += movea;
                // std::cout << "after 2 " << itrn->second << "\n" << std::endl;
                break ;
            }
        }
    }
    std::cout << "now\n";
    std::map<std::string, std::string>::iterator itr;
    std::string result = "";
    for (itr = cargo.begin(); itr != cargo.end(); ++itr){
        std::cout << itr->second << std::endl;
        result += itr->second.back();
    }
    std::cout << "result " << result << std::endl;
    return (0);
}
