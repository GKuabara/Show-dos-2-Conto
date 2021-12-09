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
        double points;
        long sequence;
        vector<char> keys;
    
    public:
        Player(string name, int points, long sequence, vector<char> keys);
        double getPoints();
        void updatePoints(double points);
        void updateSequence(long sequence);
        void updateKeys(vector<char> keys);  
};

#endif