#ifndef _QUESTION_H_
#define _QUESTION_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

class Question {
    public:
        string question;
        int right_answer_id;
        vector<string> alternatives;
        int level;
    
        Question(string question, int right_answer_id, vector<string> alternatives, int level);
        void shuffleAnswers();
        bool validateAnswer(char alternatives);
        
        string getQuestion();
        int getQuestionLevel();
        string questionLevelDescription();
        vector<string> getAlternatives();
};

#endif