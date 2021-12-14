#include "player.hpp"

Player::Player() {}

Player::Player(string name, char player_key) {
    this->name = name;
    this->player_key = player_key;    
    this->points = 0;
}

long Player::getPoints() {
    return this->points;
}

void Player::updatePoints(long points) {
    this->points = points;
}

void Player::updateKey(char player_key) {
    this->player_key = player_key;
}