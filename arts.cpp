#include "arts.hpp"

void printWelcome() {
    cout << R"(
 ____    __                                  __                          ___                              __             
/\  _`\ /\ \                                /\ \                       /'___`\                           /\ \__          
\ \,\L\_\ \ \___     ___   __  __  __       \_\ \    ___     ____     /\_\ /\ \        ___    ___     ___\ \ ,_\   ___   
 \/_\__ \\ \  _ `\  / __`\/\ \/\ \/\ \      /'_` \  / __`\  /',__\    \/_/// /__      /'___\ / __`\ /' _ `\ \ \/  / __`\ 
   /\ \L\ \ \ \ \ \/\ \L\ \ \ \_/ \_/ \    /\ \L\ \/\ \L\ \/\__, `\      // /_\ \    /\ \__//\ \L\ \/\ \/\ \ \ \_/\ \L\ \
   \ `\____\ \_\ \_\ \____/\ \___x___/'    \ \___,_\ \____/\/\____/     /\______/    \ \____\ \____/\ \_\ \_\ \__\ \____/
    \/_____/\/_/\/_/\/___/  \/__//__/       \/__,_ /\/___/  \/___/      \/_____/      \/____/\/___/  \/_/\/_/\/__/\/___/ 
                                                                                                                                                                                                                                                  
    )" << '\n' << PINK << R"(
        Seja Bem Vinde ao nosso jogo, no qual acertando as questões,
        progressivamente ganha dinheiro (pouco... bem pouco),
        mas o suficiente para garantir a sua próxima refeição no bandeco ;)

        O jogo funciona da sequinte maneira:
        A cada rodada há uma contagem regressiva para mostrar uma questão na tela,
        e cada jogador deve clicar na sua tecla correspondente a alternativa para responder a questão antes do outro jogador.
        Então é revelada a resposta correta e se o jogador que teclou primeiro acertou,
        caso tiver acertado, o mesmo ganha pontos, se errar, perde pontos.
        Assim, repete-se a rodada até que um dos jogadores atinja uma determinada pontuação.
    )" << RESET;
}

void printCountdown() {
    cout << R"(
                              _____ 
                             |___ / 
                               |_ \ 
                              ___) |
                             |____/ 
        
    )" << sleep(1) << R"(
                              ____  
                             |___ \ 
                               __) |
                              / __/ 
                             |_____|

    )" << sleep(1) << R"(
                              _ 
                             / |
                             | |
                             | |
                             |_|
                                
    )" << RESET;
}

void printPoints(string name1, string name2, double p1, double p2) {
    cout << name1, p1 << endl << name2, p2;
}

void printEnd(string p) {
    cout << "Parabénsss!!!\n" << p << "\nGanhou o Jogo";
}