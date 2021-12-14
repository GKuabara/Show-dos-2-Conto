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

// Debug
void Question::printQuestion() {
    cout << this->question << endl;
    cout << "A) " << this->alternatives[0] << endl;
    cout << "B) " << this->alternatives[1] << endl;
    cout << "C) " << this->alternatives[2] << endl;
    cout << "D) " << this->alternatives[3] << endl;
    cout << "RESPOSTA: " << this->alternatives[this->right_answer_id];
}