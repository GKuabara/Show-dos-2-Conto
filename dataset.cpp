#include <fstream>
#include <string>
#include <random>
#include <ctime>

#include "dataset.hpp"
#include "json.hpp"

using json = nlohmann::json;

static int convertLevelToInt(string l) {
    if (l.compare("Easy") == 0) return 0;
    else if (l.compare("Medium") == 0) return 1;
    return 2;
}

// Load dataset of Question from json file 
Dataset::Dataset(string filename) {
    std::ifstream i(filename);
    json j;
    i >> j;
    
    this->questions[convertLevelToInt("Easy")] = vector<Question> ();
    this->questions[convertLevelToInt("Medium")] = vector<Question> (); 
    this->questions[convertLevelToInt("Hard")] = vector<Question> (); 
    
    for (auto it = j.begin(); it != j.end(); ++it) {
        vector<string> options {j[it.key()]["options"][0], j[it.key()]["options"][1], j[it.key()]["options"][2], j[it.key()]["options"][3]};
        Question q = Question(j[it.key()]["question"], j[it.key()]["answer"], options, convertLevelToInt(j[it.key()]["level"]));
        questions[q.level].push_back(q);
    }
}

template<typename S>
auto selectRandom(const S &s, size_t n) {
    auto it = std::begin(s);
    std::advance(it,n);
    return it;
}

Question Dataset::getRandomQuestion(string level_str) {
    int level = convertLevelToInt(level_str);
    std::srand(std::time(nullptr));
    vector<Question> leveled_questions = questions[level];
    
    int question_id = std::rand() % leveled_questions.size();
    Question q = leveled_questions[question_id];
    questions[level].erase(questions[level].begin() + question_id);

    return q;
}