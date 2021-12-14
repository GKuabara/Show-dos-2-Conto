#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "arts.hpp"
#include "player.hpp"
#include "dataset.hpp"

using namespace std;

class Game {
    private:
        Player p1, p2;
        Dataset questions_data;
        long cur_round, cur_award, max_pontuation;

        string getQuestionLevel();

    public:
        Game(string dataset_file_path);
        void configureSettings();
        Player configurePlayer();

        void executeGame();
        void executeNewRound();
        
        long getCurAward();
};

#endif