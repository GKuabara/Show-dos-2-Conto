#include "arts.hpp"
#include "question.hpp"

void printAdvice() {
    cout << system("clear") << "\rRecomendamos que jogue com o terminal em tela cheia para melhor experiência";
}

/**
 * Função printWelcome:
 * Imprime a tela inicial do jogo e as instruções
 */
void printWelcome() {
    cout << system("clear") << "\r" << R"(
             ____    __                                  __                          ___                              __             
            /\  _`\ /\ \                                /\ \                       /'___`\                           /\ \__          
            \ \,\L\_\ \ \___     ___   __  __  __       \_\ \    ___     ____     /\_\ /\ \        ___    ___     ___\ \ ,_\   ___   
             \/_\__ \\ \  _ `\  / __`\/\ \/\ \/\ \      /'_` \  / __`\  /',__\    \/_/// /__      /'___\ / __`\ /' _ `\ \ \/  / __`\ 
               /\ \L\ \ \ \ \ \/\ \L\ \ \ \_/ \_/ \    /\ \L\ \/\ \L\ \/\__, `\      // /_\ \    /\ \__//\ \L\ \/\ \/\ \ \ \_/\ \L\ \
               \ `\____\ \_\ \_\ \____/\ \___x___/'    \ \___,_\ \____/\/\____/     /\______/    \ \____\ \____/\ \_\ \_\ \__\ \____/
                \/_____/\/_/\/_/\/___/  \/__//__/       \/__,_ /\/___/  \/___/      \/_____/      \/____/\/___/  \/_/\/_/\/__/\/___/ 

    )" << PINK << R"(
                Seja Bem Vinde ao nosso jogo, no qual acertando as questões,
                progressivamente ganha dinheiro (pouco... bem pouco),
                mas o suficiente para garantir a sua próxima refeição no bandeco ;)

                O jogo funciona da sequinte maneira:
                A cada rodada há uma contagem regressiva para mostrar uma questão na tela,
                e cada jogador deve clicar na sua tecla correspondente a alternativa para responder a questão antes do outro jogador.
                Então é revelada a resposta correta e se o jogador que teclou primeiro acertou,
                caso tiver acertado, o mesmo ganha pontos, se errar, perde pontos.
                Assim, repete-se a rodada até que um dos jogadores atinja uma determinada pontuação.

                Aperte ENTER para iniciar o jogo!
    )" << RESET;
}

void printCountdown() {
    cout << system("clear") << "\r" << R"(
                              _____ 
                             |___ / 
                               |_ \ 
                              ___) |
                             |____/ 
        
    )" << sleep(1) << system("clear") << "\r" << R"(
                              ____  
                             |___ \ 
                               __) |
                              / __/ 
                             |_____|

    )" << sleep(1) << system("clear") << "\r" << R"(
                              _ 
                             / |
                             | |
                             | |
                             |_|
                                
    )" << RESET << sleep(1) << system("clear");
}

/**
 * Função printPoints:
 *  Imprime as pontuações dos jogadores
 */
void printPoints(string name1, string name2, int p1, int p2) {
    system("clear");
    cout << ORANGE << R"(
 ____    ___                                     
/\  _`\ /\_ \                                    
\ \ \L\ \//\ \      __      ___     __     _ __  
 \ \ ,__/ \ \ \   /'__`\   /'___\ /'__`\  /\`'__\
  \ \ \/   \_\ \_/\ \L\.\_/\ \__//\ \L\.\_\ \ \/ 
   \ \_\   /\____\ \__/.\_\ \____\ \__/.\_\\ \_\ 
    \/_/   \/____/\/__/\/_/\/____/\/__/\/_/ \/_/ 
    )" << RESET;

    cout << "\r\n" << name1 << ": " << p1 << endl;
    cout << "\r" << name2 << ": " << p2 << endl;
    sleep(3);
    system("clear");
}

/**
 * Função printEnd:
 * Parâmetro:
 *      - p: nome do vencedor
 *  Imprime a tela final do jogo
 */
void printEnd(string p) {
    cout << "Parabénsss!!!\n" << p << " ganhou o Jogo!";
    cout << MAGENTA << R"(
                                ___                                                                   
                               /\_ \                                                                  
             __  __    ___     \//\ \      __   __  __     __        _____      __     _ __    __     
            /\ \/\ \  /'___\     \ \ \   /'__`\/\ \/\ \  /'__`\     /\ '__`\  /'__`\  /\`'__\/'__`\   
            \ \ \_/ |/\ \__/      \_\ \_/\  __/\ \ \_/ |/\ \L\.\_   \ \ \L\ \/\ \L\.\_\ \ \//\ \L\.\_ 
             \ \___/ \ \____\     /\____\ \____\\ \___/ \ \__/.\_\   \ \ ,__/\ \__/.\_\\ \_\\ \__/.\_\
              \/__/   \/____/     \/____/\/____/ \/__/   \/__/\/_/    \ \ \/  \/__/\/_/ \/_/ \/__/\/_/
                                                                       \ \_\                          
                                                                        \/_/                           

                                                   ___                              __             
                                                 /'___`\                           /\ \__          
              ___     __      ____     __       /\_\ /\ \        ___    ___     ___\ \ ,_\   ___   
             /'___\ /'__`\   /',__\  /'__`\     \/_/// /__      /'___\ / __`\ /' _ `\ \ \/  / __`\ 
            /\ \__//\ \L\.\_/\__, `\/\ \L\.\_      // /_\ \    /\ \__//\ \L\ \/\ \/\ \ \ \_/\ \L\ \
            \ \____\ \__/.\_\/\____/\ \__/.\_\    /\______/    \ \____\ \____/\ \_\ \_\ \__\ \____/
             \/____/\/__/\/_/\/___/  \/__/\/_/    \/_____/      \/____/\/___/  \/_/\/_/\/__/\/___/ 
                                                                                                                    
    )" << RESET;
}

/**
 * Função printQuestion:
 * Parâmetro:
 *      - q: questão que será impressa
 *      - round_id: rodada em questão
 */
void printQuestion(Question q, long round_id) {
    cout << system("clear");
    
    vector<string> alternatives = q.getAlternatives();

    cout << "\r[ Pergunta " << round_id << " ] - Nível: " << q.questionLevelDescription() << "\n";
    cout << q.getQuestion() << endl;
    for (int i = 0; i < alternatives.size(); ++i) 
        cout << BOLDYELLOW <<"(" << char('a' + i) << ") " << alternatives[i] << endl;
    cout << RESET;
}

void printSettings() {
    cout << system("clear") << BOLDMAGENTA << R"(
             ____            __    __                                  
            /\  _`\         /\ \__/\ \__  __                           
            \ \,\L\_\     __\ \ ,_\ \ ,_\/\_\    ___      __     ____  
             \/_\__ \   /'__`\ \ \/\ \ \/\/\ \ /' _ `\  /'_ `\  /',__\ 
               /\ \L\ \/\  __/\ \ \_\ \ \_\ \ \/\ \/\ \/\ \L\ \/\__, `\
               \ `\____\ \____\\ \__\\ \__\\ \_\ \_\ \_\ \____ \/\____/
                \/_____/\/____/ \/__/ \/__/ \/_/\/_/\/_/\/___L\ \/___/ 
                                                          /\____/      
                                                          \_/__/ 
    )" << RESET;
}

void printPlayerSetting() {
    cout << system("clear") << BLUE << R"(
 ____                       ___                                               ____    ___                                     
/\  _`\                   /'___\ __                                          /\  _`\ /\_ \                                    
\ \ \/\_\    ___     ___ /\ \__//\_\     __   __  __  _ __    __     _ __    \ \ \L\ \//\ \      __     __  __     __   _ __  
 \ \ \/_/_  / __`\ /' _ `\ \ ,__\/\ \  /'_ `\/\ \/\ \/\`'__\/'__`\  /\`'__\   \ \ ,__/ \ \ \   /'__`\  /\ \/\ \  /'__`\/\`'__\
  \ \ \L\ \/\ \L\ \/\ \/\ \ \ \_/\ \ \/\ \L\ \ \ \_\ \ \ \//\ \L\.\_\ \ \/     \ \ \/   \_\ \_/\ \L\.\_\ \ \_\ \/\  __/\ \ \/ 
   \ \____/\ \____/\ \_\ \_\ \_\  \ \_\ \____ \ \____/\ \_\\ \__/.\_\\ \_\      \ \_\   /\____\ \__/.\_\\/`____ \ \____\\ \_\ 
    \/___/  \/___/  \/_/\/_/\/_/   \/_/\/___L\ \/___/  \/_/ \/__/\/_/ \/_/       \/_/   \/____/\/__/\/_/ `/___/> \/____/ \/_/ 
                                         /\____/                                                            /\___/            
                                         \_/__/                                                             \/__/       
    )" << RESET;
}   


void printQuitOption() {
    cout << system("clear") << ORANGE << R"(
 ____                                                            __                                                
/\  _`\                                                         /\ \                  __                           
\ \ \L\_\    ___     ___     __   _ __   _ __    __      ___    \_\ \    ___         /\_\    ___      __     ___   
 \ \  _\L  /' _ `\  /'___\ /'__`\/\`'__\/\`'__\/'__`\  /' _ `\  /'_` \  / __`\       \/\ \  / __`\  /'_ `\  / __`\ 
  \ \ \L\ \/\ \/\ \/\ \__//\  __/\ \ \/ \ \ \//\ \L\.\_/\ \/\ \/\ \L\ \/\ \L\ \       \ \ \/\ \L\ \/\ \L\ \/\ \L\ \
   \ \____/\ \_\ \_\ \____\ \____\\ \_\  \ \_\\ \__/.\_\ \_\ \_\ \___,_\ \____/       _\ \ \ \____/\ \____ \ \____/
    \/___/  \/_/\/_/\/____/\/____/ \/_/   \/_/ \/__/\/_/\/_/\/_/\/__,_ /\/___/       /\ \_\ \/___/  \/___L\ \/___/ 
                                                                                     \ \____/         /\____/      
                                                                                      \/___/          \_/__/ 
    )" << RESET;
}