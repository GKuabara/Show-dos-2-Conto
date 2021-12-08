#ifndef _QUESTIONS_H_
#define _QUESTIONS_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

class Question {
    private:
        string question;
        string right_answer;
        vector<string> alternatives;
    
        vector<string> shuffleAnswers();

    public:
        Question(string question, string right_answer, vector<string> alternatives);
        string getQuestion();
        vector<string> getAlternatives();
        bool validateAnswer(char alternatives);  
};


#endif