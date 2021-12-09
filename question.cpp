#include "question.hpp"

Question::Question(string question, string right_answer, vector<string> alternatives) {
    this->question = question;
    this->right_answer = right_answer;
    this->alternatives = alternatives;
}

void Question::shuffleAnswers() {
    random_shuffle(alternatives.begin(), alternatives.end());
}

string Question::getQuestion() {
    return question;
}

vector<string> Question::getAlternatives() {
    shuffleAnswers();
    return alternatives;
}

bool Question::validateAnswer(char alternative) {
    int idx = alternative - 97;
    return (right_answer.compare(alternatives[idx]) == 0) ? true : false;
}