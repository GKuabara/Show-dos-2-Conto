// Gabriel Alves Kuabara - nUSP 11275043
// Bernardo Marques Costa - nUSP 11795551
// Victor Henrique da Silva - nUSP 11795759

#include "question.hpp"
#include "json.hpp"

using json = nlohmann::json;

/**
 * Construtora da classe Question:
 * - Parâmetros: 
 *      - question: frase da pergunta
 *      - right_answer_id: índice do vetor das possíveis respostas que contém a resposta verdadeira
 *      - alternatives: vetor com todas as frases de possíveis respostas
 *      - level: dificuldade da pergunta
 */
Question::Question(string question, int right_answer_id, vector<string> alternatives, int level) {
    this->question = question;
    this->right_answer_id = right_answer_id;
    this->alternatives = alternatives;
    this->level = level;
}

/**
 * Função getQuestion:
 * Retorno: string da pergunta 
 */
string Question::getQuestion() {
    return question;
}

/**
 * Função getter getAlternatives
 * - Retorno: vetor que contém todas as 4 alternativas
 */
vector<string> Question::getAlternatives() {
    return alternatives;
}

/**
 * Função validateAnswer:
 * - Parâmetro: alternativa - representa a letra da alternativa respondida pelo jogador
 * - Retorno: boleano identificando se a alternativa selecionada é a verdadeira
 */
bool Question::validateAnswer(char alternative) {
    int idx = alternative - 97;
    return right_answer_id == idx;
}

/**
 * Função getter getQuestionLevel:
 * - Retorno: nível da questão
 */
int Question::getQuestionLevel() {
    return this->level;
}

/**
 * Função questionLevelDescription:
 * Realiza a conversão do nível de dificuldade em inteiro para a descrição em string em PT-BR
 */
string Question::questionLevelDescription() {
    if (this->level == 0) return "Fácil";
    else if (this->level == 1) return "Médio";
    return "Difícil";
}