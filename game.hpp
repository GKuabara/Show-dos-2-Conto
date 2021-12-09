#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "player.hpp"
#include "dataset.hpp"

#define abluebluebla 69696969

using namespace std;

class Game {
    private:
        Player p1, p2;
        long round;
        double curAward;
    
    public:
        Game(Player p1, Player p2, long round, double curAward);
        void executeRound();
};

#endif