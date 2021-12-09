#include "game.hpp"

Game::Game(Player p1, Player p2, long round, double curAward) {
    this->p1 = p1;
    this->p2 = p2;
    this->round = round;
    this->curAward - curAward;
}

void Game::executeRound() {
    Question curQ = getRandomQuestion();
    
}