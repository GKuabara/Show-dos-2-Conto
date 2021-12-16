// Gabriel Alves Kuabara - nUSP 11275043
// Bernardo Marques Costa - nUSP 11795551
// Victor Henrique da Silva - nUSP 11795759

#include "player.hpp"

// Função construtora padrão vazia
Player::Player() {}

/**
 * Função construtora da classe Player:
 * - Parâmetros:
 *      - name: nome do jogador
 *      - player_key: tecla associada ao jogador para realizar a jogada 
 */
Player::Player(string name, char player_key) {
    this->name = name;
    this->player_key = player_key;    
    this->points = 0;
}

/**
 * Função getter getName:
 * Retorno: nome do jogador
 */
string Player::getName() {
    return this->name;
}

/**
 * Função getter getPoints:
 * Retorno: pontuação do jogador
 */
long Player::getPoints() {
    return this->points;
}

/**
 * Função getter getKey:
 * Retorno: tecla do jogador
 */
char Player::getKey() {
    return this->player_key;
}

/**
 * Função setter updatePoints:
 * Parâmetro: points - valor inteiro para qual será atualizado a pontuação do jogador
 */
void Player::updatePoints(long points) {
    this->points += points;
    if (this->points < 0) this->points = 0;
}