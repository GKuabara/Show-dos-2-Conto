#include "game.hpp"

#include <chrono>
#include <thread>
#include <mutex>
#include <math.h>

char curr_player = ';', ans = 'x';
bool got_key = false;
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
    if (this->max_pontuation <= 0) {
        cout << "A pontuação máxima deve ser maior do que 0!!\nPor favor, insira novamente";
        cin >> this->max_pontuation;
    }
}

Player Game::configurePlayer(char player_key) {
    printPlayerSetting();

    string name;
    cout << "\rDigite o nome do Jogador: ";
    cin >> name;
    cout << "Chave associada: " << player_key << "\n"; 
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

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
        cout << endl << "\rResposta correta!!! :D" << endl;
        cout << "\rMais " << (pow(2, cur_question.getQuestionLevel())) << " pontos para o jogador "
        << (curr_player == this->p1.getKey() ? this->p1.getName() : this->p2.getName()) << endl << '\r';
    
        if (curr_player == this->p1.getKey()) this->p1.updatePoints(pow(2, cur_question.getQuestionLevel()));
        else this->p2.updatePoints(pow(2, cur_question.getQuestionLevel()));
    
    } else {
        cout << endl << "\rResposta incorreta!!! :(" << endl << '\n';

        if (curr_player == this->p1.getKey()) this->p1.updatePoints(-1);
        else this->p2.updatePoints(-1);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    return;
}

void getKeyRush(char player_key, char op) {
    char c = 0;
    inputMutex.lock();
    
    while (c != player_key and c != op and c != 'x') {
        if (got_key == true) {
            inputMutex.unlock();
            return;
        }

        c = getchar();

        if (c == player_key or c == op) {
            got_key = true;
            curr_player = c;
        } else  {
            cout << '\b';
        }  
    }

    cout << endl << '\r';
    inputMutex.unlock();
}

void readAnswer() {
    cin.clear();

    cout << "\n\rDigite a resposta:\t", ans = getchar();
    while (ans < 'a' or ans > 'd') {
        cout << "\n\rResposta inválida, digite novamente: ", ans = getchar();
        cout << endl;
    }
}

void Game::executeNewRound() {
    Question cur_question = questions_data.getRandomQuestion(this->getQuestionLevel());

    printCountdown();
    printQuestion(cur_question, this->cur_round);
    cout << "\n\r[f - Jogador 1] vs [j - Jogador 2]: \t"; 

    system("stty raw");
    fflush(stdin);

    thread p1t(getKeyRush, this->p1.getKey(), this->p2.getKey()), p2t(getKeyRush, this->p2.getKey(), this->p1.getKey());
    p1t.join(), p2t.join();

    if (curr_player == 'f') cout << "\n\r" << this->p1.getName() << " responde!\n";
    else if (curr_player == 'j') cout << "\n\r" << this->p2.getName() << " responde!\n";

    thread answer(readAnswer);
    answer.join();

    Game::checkAns(cur_question);
    system("stty cooked");
    printPoints(this->p1.getName(), this->p2.getName(), this->p1.getPoints(), this->p2.getPoints());

    ans = 'x';
    curr_player = ';';
    got_key = false;
}

void Game::executeGame() {
    printAdvice();
    printWelcome();
    char enter;
    while (enter = std::getchar()) {
        if (enter == '\r' or enter == '\n') break;
    } 

    this->configureSettings();

    this->p1 = this->configurePlayer('f');
    this->p2 = this->configurePlayer('j');

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