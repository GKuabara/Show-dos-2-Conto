#ifndef _DATASET_H_
#define _DATASET_H_

#include "question.hpp"
#include <set>
#include <unordered_map>
#include <string>
#include <vector>

class Dataset {
    private:
        unordered_map<int,  std::vector<Question>> questions;
    
    public:
        Dataset();
        Dataset(string filename);
        Question getRandomQuestion(string level_str);
};

#endif