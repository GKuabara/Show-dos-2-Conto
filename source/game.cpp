#include "game.hpp"
#include <chrono>
#include <thread>
#include <mutex>
#include <math.h>

char curr_player = ';', ans = 'x';
mutex inputMutex;

Game::Game(string dataset_file_path) {
    this->cur_round = 0;
    this->cur_award = 0;
    this->max_pontuation = 0;
    
    this->questions_data = Dataset(dataset_file_path);
}

void Game::configureSettings() {
    printSettings();

    cout << "\rPontuação máxima: ";
    cin >> this->max_pontuation;
}

Player Game::configurePlayer() {
    printPlayerSetting();

    string name;
    cout << "\rDigite o nome do Jogador: ";
    cin >> name;

    char player_key;
    cout << "\rTecla associada: ";
    cin >> player_key;

    return Player(name, player_key);
}

string Game::getQuestionLevel() {
    long x = this->p1.getPoints() + this->p2.getPoints() - int(this->max_pontuation / 2);
    if (x < 0) return "Easy";
    else if (x == 0) return "Medium";
    return "Hard";
}

bool Game::gameOver() {
    return (this->p2.getPoints() >= this->max_pontuation) or (this->p1.getPoints() >= this->max_pontuation);
}

void Game::checkAns(Question cur_question) {
    if (cur_question.validateAnswer(ans)) {
        cout << endl << "\rRESPOSTA CORRETA!" << endl;
        cout << "\rMais " << (pow(2, cur_question.getQuestionLevel())) << " pontos para o jogador "
        << (curr_player == this->p1.getKey() ? this->p1.getName() : this->p2.getName()) << endl << '\r';
    
        if (curr_player == this->p1.getKey()) this->p1.updatePoints(pow(2, cur_question.getQuestionLevel()));
        else this->p2.updatePoints(pow(2, cur_question.getQuestionLevel()));
    
    } else {
        cout << endl << "\rRESPOSTA INCORRETA!" << endl << '\r';

        if (curr_player == this->p1.getKey()) this->p1.updatePoints(-1);
        else this->p2.updatePoints(-1);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    return;
}

void getKeyRush(char player_key, char op) {
    char c = 0;
    inputMutex.lock();

    while (c != player_key and c != op and c != 'x') {
        c = getchar();
        if (c == 'x') {
            inputMutex.unlock();
            return;
        }

        if (c == player_key) {
            curr_player = player_key;
            ungetc('x', stdin);
        } else if (c == op) {
            ungetc(op, stdin);
            inputMutex.unlock();
            return;
        } else    
            cout << '\b';
    }

    cout << endl << '\r';
    inputMutex.unlock();
}

void readAnswer() {
    cout << "\rENTER VALUE:\t";
    while (ans < 'a' or ans > 'd')
        cout << '\b', ans = getchar();
}

void Game::executeNewRound() {
    Question cur_question = questions_data.getRandomQuestion(this->getQuestionLevel());

    printCountdown();
    printQuestion(cur_question, this->cur_round);
    
    system("stty raw");
    thread p1t(getKeyRush, this->p1.getKey(), this->p2.getKey()), p2t(getKeyRush, this->p2.getKey(), this->p1.getKey());
    p1t.join(), p2t.join();
    
    while (curr_player == ';'); // travando a main

    thread answer(readAnswer);
    answer.join();
    for (int i = 0; i < 50; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if (ans != 'x') break;
    }

    Game::checkAns(cur_question);
    system("stty cooked");

    printPoints(this->p1.getName(), this->p2.getName(), this->p1.getPoints(), this->p2.getPoints());

    ans = 'x';
    curr_player = ';';
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
        this->executeNewRound();
    }

    string winner = (this->p1.getPoints() >= this->max_pontuation) ? this->p1.getName() : this->p2.getName();
    printEnd(winner);
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}

long Game::getCurAward() {
    return this->cur_award;
}