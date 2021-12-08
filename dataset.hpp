#ifndef _DATASET_H_
#define _DATASET_H_

#include "question.h"
#include <set>

using namespace std;

class Dataset {
    private:
        set<Question::Question> questions;
    
    public:
        Dataset(string filename);
        Question getRandomQuestion();
};

#endif