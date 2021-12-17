// Gabriel Alves Kuabara - nUSP 11275043
// Bernardo Marques Costa - nUSP 11795551
// Victor Henrique da Silva - nUSP 11795759

#include "game.hpp"
#include "question.hpp"

#include <chrono>
#include <thread>
#include <mutex>
#include <semaphore.h>
#include <math.h>

/**
 * @curr_player: armazena qual o jogador que responde naquela rodada
 * @ans: armazenar resposta inserida pelo jogador
 * @got_key: garante que não haja input desnecessário
 * @input_mutex: mutex que protege a região crítica
 */
char curr_player = ';', ans = 'x';
bool got_key = false;
mutex input_mutex;

/**
 * @sem: semáforo que irá proteger as variáveis a seguir
 * @right_ans_idx: cópia global da alternativa certa
 * @question_level: cópia global da dificuldade da pergunta, usada para dar a pontuação
 */
sem_t sem;
int right_ans_idx, question_level;

/**
 * Construtora da classe Game:
 * - Parâmetro: 
 *      - dataset_file_path: caminho para os arquivos do dataset, para que ele possa ser carregado
 */
Game::Game(string dataset_file_path) {
    this->cur_round = 0;
    this->cur_award = 0;
    this->max_pontuation = 0;
    
    this->questions_data = Dataset(dataset_file_path);
}

/**
 * Função configureSettings:
 */
void Game::configureSettings() {
    printSettings();

    // Recebe a pontuação na qual o jogo termina
    cout << "\rPontuação máxima: ";
    cin >> this->max_pontuation;
    if (this->max_pontuation <= 0) {
        cout << "A pontuação máxima deve ser maior do que 0!!\nPor favor, insira novamente";
        cin >> this->max_pontuation;
    }
}

/**
 * Função configurePlayer:
 * Parâmetro:
 *      - player_key: tecla que o jogador deve apertar para que possa responder
 */
Player Game::configurePlayer(char player_key) {
    printPlayerSetting();

    // Recebe o apelido do jogador 
    string name;
    cout << "\rDigite o nome do Jogador: ";
    cin >> name;
    cout << "Chave associada: " << player_key << "\n"; 
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    return Player(name, player_key);
}

/**
 * Função getter getQuestionLevel:
 * Retorno: string que identifica o nível da próxima pergunta
 */
string Game::getQuestionLevel() {
    // A dificuldade depende do estado em que o jogo está
    // Quanto mais avançado (mais pontos), mais difícil
    long x = this->p1.getPoints() + this->p2.getPoints() - int(this->max_pontuation / 2);
    if (x < 0) return "Easy";
    else if (x == 0) return "Medium";
    return "Hard";
}

/**
 * Função gamerOver:
 * Retorno: booleano indicando se o jogo chegou ou não ao fim
 */
bool Game::gameOver() {
    // Chega no final apenas quando um dos jogadores atinge a pontuação máxima
    return (this->p2.getPoints() >= this->max_pontuation) or (this->p1.getPoints() >= this->max_pontuation);
}

/**
 * Função checkAns:
 *  Cria uma thread que fica verificando se a resposta foi inserida e, caso tenha sido, se está certa ou não.
 *  Atualiza as pontuações dos jogadores também. 
 */
void Game::checkAns() {
    thread ( [this] {
        while (true) {
            // Região crítica
            sem_wait(&sem);
            if (ans == 'x') {
                sem_post(&sem);
                continue;
            } else if ((ans - 'a') == right_ans_idx) {
                cout << endl << "\rResposta correta!!! :D" << endl;
                cout << "\rMais " << (pow(2, question_level)) << " pontos para o jogador "
                << (curr_player == this->p1.getKey() ? this->p1.getName() : this->p2.getName()) << endl << '\r';
            
                if (curr_player == this->p1.getKey()) this->p1.updatePoints(pow(2, question_level));
                else this->p2.updatePoints(pow(2, question_level));
            
            } else {
                cout << endl << "\rResposta incorreta!!! :(" << endl << '\n';

                if (curr_player == this->p1.getKey()) this->p1.updatePoints(-1);
                else this->p2.updatePoints(-1);
            }

            ans = 'x';
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            sem_post(&sem);
        }
    }).detach();
}

/**
 * Função getKeyRush:
 *  Função que é executada em duas threads diferentes. Responsável por decidir qual será o 
 *  jogador que vai responder
 */
void getKeyRush(char player_key, char op) {
    char c = 0;

    // Região crítica: atualiza a variável @curr_player, global
    input_mutex.lock();
    
    // Quando recebe o input para sair ou a tecla de um dos jogadores, atualiza e termina
    while (c != player_key and c != op and c != 'x') {
        if (got_key == true) {
            input_mutex.unlock();
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
    input_mutex.unlock();
}

/**
 * Função readAns:
 *  Recebe a resposta do usuário para que pergunta que aparece na tela.
 */
void readAnswer() {
    cin.clear();

    sem_wait(&sem);
    cout << "\n\rDigite a resposta:\t", ans = getchar();
    while (ans < 'a' or ans > 'd') {
        cout << "\n\rResposta inválida, digite novamente: ", ans = getchar();
        cout << endl;
    }
    sem_post(&sem);
}

/**
 * Função executeNewRound:
 *  Função responsável por realizar uma nova rodada
 */
void Game::executeNewRound() {
    // Escolhe a nova pergunta
    Question cur_question = questions_data.getRandomQuestion(this->getQuestionLevel());
    
    // Atualiza região crítica
    sem_wait(&sem);
    right_ans_idx = cur_question.getAnsIdx();
    question_level = cur_question.getQuestionLevel();
    sem_post(&sem);

    // Imprime a contagem regressiva e, depois, a pergunta escolhida
    printCountdown();
    printQuestion(cur_question, this->cur_round++);
    cout << "\n\r[f - Jogador 1] vs [j - Jogador 2]: \t"; 

    // Troca o modo do terminal para que os inputs sejam processados sem esperar pelo "enter" (não passa por processamento do SO)
    system("stty raw");
    fflush(stdin);

    // Duas threads, uma para cada player, vão disputar para ver qual jogador vai responder
    thread p1t(getKeyRush, this->p1.getKey(), this->p2.getKey()), p2t(getKeyRush, this->p2.getKey(), this->p1.getKey());
    p1t.join(), p2t.join();

    if (curr_player == 'f') cout << "\n\r" << this->p1.getName() << " responde!\n";
    else if (curr_player == 'j') cout << "\n\r" << this->p2.getName() << " responde!\n";

    // Jogador mais rápido responde
    readAnswer();

    system("stty cooked");
    printPoints(this->p1.getName(), this->p2.getName(), this->p1.getPoints(), this->p2.getPoints());

    // Reseta as variáveis globais para a nova rodada
    curr_player = ';';
    got_key = false;
}

/**
 * Função executeGame:
 *  Função principal do jogo, onde ocorre a configuração dos players e 
 *  as novas rodadas são executadas enquanto necessário
 */
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

    // Inicializa o semáforo que irá proteger as regiões críticas
    sem_init(&sem, 0, 1);
    checkAns();

    // Inicia o jogo
    while (!this->gameOver()) {
        this->executeNewRound();
    }

    string winner = (this->p1.getPoints() >= this->max_pontuation) ? this->p1.getName() : this->p2.getName();
    printEnd(winner);
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}