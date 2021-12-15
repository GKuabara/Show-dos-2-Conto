#include "player.hpp"

Player::Player() {}

Player::Player(string name, char player_key) {
    this->name = name;
    this->player_key = player_key;    
    this->points = 0;
}

string Player::getName() {
    return this->name;
}

long Player::getPoints() {
    return this->points;
}

void Player::updatePoints(long points) {
    this->points += points;
    if (this->points < 0) this->points = 0;
}

void Player::updateKey(char player_key) {
    this->player_key = player_key;
}

char Player::getKey() {
    return this->player_key;
}