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
1. Ao iniciar o jogo, temos uma tela inicial que fornece as instruções para os dois jogadores enquanto espera a tecla 'ENTER' ser digitada.
2. Uma tela é impressa para definir com quantos pontos o jogo termina, após isso, tem início as rodadas de perguntas.
3. É feita uma contagem regressiva para mostrar uma pergunta.
4. Uma pergunta é mostrada e os dois jogadores devem apertar uma tecla pré-determinada para que tenham o direito para responder a pergunta.
5. O jogador que clica mais rapidamente na sua devida tecla adquire o direito de responder a perguntar por um determinado período de tempo.
6. Durante esse intervalo de tempo, após o jogador ter adquirido o direito de resposta, ele deve selecionar uma das alternativas.
7. Caso selecionado corretamente, o jogador adquire pontos, caso erre ou a expire o tempo, ele perde uma pequena quantidade de pontos.
8. É disponibilizado na tela se a resposta está correta e a pontuação atual dos jogadores.
9. Caso um dos jogadores tenham obtido determinada pontuação definida no início do jogo, tal jogador ganha e o jogo é encerrado.
10. Se nenhum dos jogadores obteve a pontuação de vitória, então mais rodadas são executadas (volta para o passo 2).

# Implementação

## Data Set
Criamos um arquivo .json a partir de um arquivo .txt com multíplas perguntas do jogo "Show do Milhão". A partir desse aqrquivo .json, fazemos a leitura dele armazenando todas as perguntas, com suas respectivas alternativas e resposta, num unsorted_map, com as chaves sendo a dificuldade da pergunta (Easy, Normal, Hard) cujo valores são vetores de Objetos da classe "Question" que contém todas as informações das perguntas. Assim, quando uma pergunta é sorteada, acessamos a questão através da dificuldade e então diretamente pelo índice no vetor.

## Questões
Cada questão tem sua dificuldade a qual é atribuida uma pontuação, cada nível de dificuldade corresponde a um valor inteiro: 0, 1, 2. Dessa forma, a quantidade de pontos que equivale a uma questão corresponde ao cálculo 2^(nível).

## Arts
Arquivo que contém as funções que usamos para estilizar o nosso jogo, com ASCII arts para deixar o jogo mais agradável aos olhos e intuitivo.

## Player
Contém poucos métodos, basicamente para manusear a quantidade de pontos que cada jogador tem.

## Game
Parte mais importante do projeto, nessa classe determinamos a quantidade de pontos que é necessária para ganhar o jogo, a determinação das teclas de cada jogador e posteriormente a execução das rodadas que ficam em loop até que algum dos jogadores atinja a pontuação necessária para vitória. Cada rodada é executada da seguinte forma: é feito uma contagem regressiva de 3 segundos e mostra-se a pergunta para os jogadores. A partir desse momento, inicia-se uma thread para cada jogador as quais leem a entrada do teclado. Dependendo de qual tecla for acionada, uma threads aciona o semáforo mutex, travando a thread ou continuando sua execução e definindo qual jogador tem a prioridade para responder a pergunta. Em seguida, o jogador com prioridade de resposta escolhe uma alternativa. Enquanto isso, existe uma outra thread já iniciada no começo do jogo que fica a todo momento verificando se uma resposta foi dada por algum dos jogadores. Então, atualiza-se a pontuação do jogador e caso o jogo não tenha finalizado, inicia-se outra rodada.

## Threads e Semáforos
No projeto usamos praticamente 3 threads junto de semáforos:

- Ao início de cada rodada, é escolhida uma pergunta aleatoriamente. No momento logo em seguida um semáforo é ativado para atualizar as variáveis globais que armazenam qual a resposta certa da pergunta e o nível da pergunta.

- A primeira seria a thread correspondente a função checkAns() que usamos para checar constantemente se a resposta da questão foi respondida por qualquer dos jogadores. Essa thread fica em loop constante realizando operações sobre o semáforo que corresponde ao acesso a variável global da resposta (região crítica). No início da iteração, é realizado uma operação wait(), dando acesso exclusivo a esta thread para fazer a verificação se uma resposta foi dada por algum dos jogadores. Caso uma resposta tenha sido dada, verifica se a resposta dada está correta e atualiza os pontos do jogador. Após isso, no final da iteração, realiza uma operação post() sobre o semáforo para liberar outra thread.

- A segunda e terceira thread correspondem a função getKeyRush() são uma de cada jogador que são iniciadas a cada rodada quando a pergunta já foi exposta na tela. Então, as threads servem para disputa dos jogadores para ver quem vai responder a pergunta. Na execução da thread, o semáforo mutex é bloqueado e é feito um loop que espera uma das teclas de algum jogador serem ativadas. Então, a variável global que diz qual jogador tem direito a resposta (região crítica) é atualizada. Após isso, o mutex é desbloqueado, encerrando a execução dessas threads.

- Após ser selecionado qual jogador vai responder a pergunta, é chamada a função readAnswer() que realiza a operação wait() sobre o semáforo que diz respeito ao acesso a variável que armazena a resposta da pergunta. Então, é lida a resposta do jogador, liberando o semáforo.

# Como Jogar: Compilação e Execução
Para jogar, basta clonar o repositório e rodar na sua máquina localmente. Ao entrar no repositório do jogo, o projeto contém uma Makefile a qual é usada para compilar e executar o programa com os comandos:
`make all && make run`
Note que ao compilar terá alguns 'warnings' que são devidos as ASCII arts que são usadas no jogo, mas que não representam nenhum problema na execução.
