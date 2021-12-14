#include <iostream>

#include "question.hpp" 
#include "dataset.hpp"
#include "json.hpp"

int main(int argc, char *argv[]) {
    Dataset d = Dataset("questions.json");
    for (int i = 0; i < 10; i++) {
        Question q = d.getRandomQuestion("Easy");
        q.printQuestion();
    }

    return 0;
}