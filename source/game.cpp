#include "game.hpp"
#include <chrono>
#include <thread>

Game::Game(string dataset_file_path) {
    this->cur_round = 0;
    this->cur_award = 0;
    this->max_pontuation = 0;
    
    this->questions_data = Dataset(dataset_file_path);

}

void Game::configureSettings() {
    printSettings();

    cout << "Pontuação máxima: ";
    cin >> this->max_pontuation;
}

Player Game::configurePlayer() {
    printPlayerSetting();

    string name;
    cout << "Digite o nome do Jogador: ";
    cin >> name;

    char player_key;
    cout << "Tecla associada: ";
    cin >> player_key;

    return Player(name, player_key);
}

string Game::getQuestionLevel() {
    long x = this->p1.getPoints() + this->p2.getPoints() - int(this->max_pontuation / 2);
    if (x < 0) return "Easy";
    else if (x == 0) return "Medium";
    return "Hard";
}

void Game::executeNewRound() {
    Question cur_question = questions_data.getRandomQuestion(this->getQuestionLevel());

    printCountdown();
    printQuestion(cur_question, this->cur_round);
}

bool Game::gameOver() {
    return (this->p2.getPoints() >= this->max_pontuation) or (this->p1.getPoints() >= this->max_pontuation); 
}

void Game::executeGame() {
    printAdvice();

    printWelcome();
    char enter;
    while (enter = std::getchar()) {
        if (enter == '\r' or enter == '\n') break;
    } 

    this->configureSettings();

    this->p1 = this->configurePlayer();
    this->p2 = this->configurePlayer();

    while (!this->gameOver()) {
        enter = '0';
        this->executeNewRound();
        cout << "ENTER VALUE: " << enter << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        while (enter != '\r' and enter != '\n') {
            enter = std::getchar();
        } 
    }
}

long Game::getCurAward() {
    return this->cur_award;
}