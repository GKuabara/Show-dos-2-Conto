# Show-dos-2-Conto
Game developed to SSC0140 - Operational System I course from University of São Paulo

# Portuguese Version

# Alunos
* Gabriel Alves Kuabara - nUSP 11275043
* Bernardo Marques Costa - nUSP 
* Victor Henrique da Silva - nUSP

# Introdução
Este jogo foi criado a fim de praticar os conhecimentos adquiridos na disciplina já mencionada. Mais especificamente, aplicamos nele principalmente os nossos conhecimentos de semáforos e threads de maneira divertida, interativa e didática.

# Funcionamento
O funcionamento do jogo acontece da seuinte maneira:
1. Ao iniciar o jogo, temos uma tela inicial que fornece as instruções para os dois jogadores enquanto espera uma tecla ser digitada para que inicie o jogo de fato.
2. É feita uma contagem regressiva para mostrar uma pergunta.
3. Uma pergunta é mostrada e os dois jogadores devem apertar uma tecla pré-determinada para que tenham o direito para responder a pergunta.
4. O jogador que clica mais rapidamente na sua devida tecla adquire o direito de responder a perguntar por um determinado período de tempo.
5. Durante esse intervalo de tempo, após o jogador ter adquirido o direito de resposta, ele deve selecionar uma das alternativas.
6. Caso selecionado corretamente, o jogador adquire pontos, caso erre ou a expire o tempo, ele perde uma pequena quantidade de pontos.
7. É disponibilizado na tela a resposta correta e a pontuação atual dos jogadores.
8. Caso um dos jogadores tenham obtido determinada pontuação, tal jogador ganha e o jogo é encerrado.
9. Se nenhum dos jogadores obteve a pontuação de vitória, então mais rodadas são executadas (volta para o passo 2).

# Implementação

## Data Set
Criamos um arquivo .json a partir de um arquivo .txt com multíplas perguntas do jogo "Show do Milhão". A partir desse aqrquivo .json, fazemos a leitura dele armazenando todas as perguntas, com suas respectivas alternativas e resposta, num unsorted_map, com as chaves sendo a dificuldade da pergunta (Easy, Normal, Hard) cujo valores são vetores de Objetos da classe "Question" que contém todas as informações das perguntas. Assim, quando uma pergunta é sorteada, acessamos a questão através da dificuldade e então diretamente pelo índice no vetor.