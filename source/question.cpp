#include "question.hpp"
#include "json.hpp"

using json = nlohmann::json;

Question::Question(string question, int right_answer_id, vector<string> alternatives, int level) {
    this->question = question;
    this->right_answer_id = right_answer_id;
    this->alternatives = alternatives;
    this->level = level;
}

string Question::getQuestion() {
    return question;
}

vector<string> Question::getAlternatives() {
    return alternatives;
}

bool Question::validateAnswer(char alternative) {
    int idx = alternative - 97;
    return right_answer_id == idx;
}

int Question::getQuestionLevel() {
    return this->level;
}

string Question::questionLevelDescription() {
    if (this->level == 0) return "Fácil";
    else if (this->level == 1) return "Médio";
    return "Difícil";
}