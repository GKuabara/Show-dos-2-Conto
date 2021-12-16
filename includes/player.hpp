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
        
        string getName();
        long getPoints();
        char getKey();
        
        void updatePoints(long points);
};

#endif