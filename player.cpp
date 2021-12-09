#include "player.hpp"

Player::Player(string name, int points, long sequence, vector<char> keys) {
    this->name = name;
    this->points = points;
    this->sequence = sequence;
    this->keys = keys;
}

double Player::getPoints() {
    return this->points;
}

void Player::updatePoints(double points) {
    this->points = points;
}

void Player::updateSequence(long sequence) {
    this->sequence = sequence;
}

void Player::updateKeys(vector<char> keys) {
    this->keys = keys;
}