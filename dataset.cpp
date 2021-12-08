#include "dataset.hpp"
#include "json.hpp"

using json = nlohmann::json;

namespace ns {
    void to_json(json& j, const person& p) {
        j = json{{"name", p.name}, {"address", p.address}, {"age", p.age}};
    }

    void from_json(const json& j, Question::Question& p) {
        j.at("question").get_to(p.name);
        j.at("address").get_to(p.address);
        j.at("age").get_to(p.age);
    }
} // namespace ns

Dataset(string filename) {
    
}

Question Dataset::getRandomQuestion() {
    auto it = questions.begin();
    int random = rand() % questions.size();
    return *(it + random);
}