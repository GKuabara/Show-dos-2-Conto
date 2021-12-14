#include "arts.hpp"

void printAdvice() {
    cout << system("clear") << "Recomendamos que jogue com o terminal em tela cheia para melhor experiência";
}

void printWelcome() {
    cout << system("clear") << R"(
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
    cout << system("clear") << R"(
                              _____ 
                             |___ / 
                               |_ \ 
                              ___) |
                             |____/ 
        
    )" << sleep(1) << system("clear") << R"(
                              ____  
                             |___ \ 
                               __) |
                              / __/ 
                             |_____|

    )" << sleep(1) << system("clear") << R"(
                              _ 
                             / |
                             | |
                             | |
                             |_|
                                
    )" << RESET << sleep(1) << system("clear");
}

void printPoints(string name1, string name2, double p1, double p2) {
    cout << name1 << p1 << endl << name2 << p2 << sleep(3) << system("clear");
}

void printEnd(string p) {
    cout << "Parabénsss!!!\n" << p << "\nGanhou o Jogo";
}

int main() {
    printAdvice();
    //printWelcome();
    printCountdown();
    //printPoints("Ku", "Juninho", 5, 4);
    //printEnd("Ku");

    return 0;
}