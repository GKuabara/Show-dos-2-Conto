#include <iostream>

#include "arts.hpp"
#include "question.hpp" 
#include "dataset.hpp"
#include "player.hpp"
#include "game.hpp"
#include "json.hpp"


#include <chrono>
#include <thread>


int main(int argc, char *argv[]) {
    Game g = Game("dataset/questions.json");

    g.executeGame();

    return 0;
}