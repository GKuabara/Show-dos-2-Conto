#ifndef _QUESTION_H_
#define _QUESTION_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

class Question {
    // private:
    public:
        string question;
        int right_answer_id;
        vector<string> alternatives;
        int level;
    
        Question(string question, int right_answer_id, vector<string> alternatives, int level);
        void shuffleAnswers();
        string getQuestion();
        vector<string> getAlternatives();
        bool validateAnswer(char alternatives);

};

#endif