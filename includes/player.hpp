#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

class Player {
    private:
        string name;
        long points;
        char player_key;
    
    public:
        Player();
        Player(string name, char player_key);
        long getPoints();
        void updatePoints(long points);
        void updateKey(char player_key);  
};

#endif