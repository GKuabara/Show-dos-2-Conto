#ifndef _ARTS_H 
#define _ARTS_H

#include <iostream>
#include <cstdio>
#include <unistd.h>

#include "question.hpp"

using namespace std;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define PINK        "\033[38;5;206m" /* Pink */
#define GRAY        "\033[38;5;59m"  /* Gray */
#define GOLD        "\033[38;5;214m" /* Gold */
#define BROWN       "\033[38;2;135;103;47m"
#define ORANGE      "\033[38;2;255;185;79m"


// Messages
void printAdvice();
void printWelcome();
void printCountdown();
void printPoints(string name1, string name2, int p1, int p2);
void printEnd(string p);

void printQuestion(Question q, long round_id);

void printSettings();
void printPlayerSetting();

#endif 