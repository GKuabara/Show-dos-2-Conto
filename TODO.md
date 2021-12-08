TODO

- criar classe jogador
- criar classe UI: proxima pergunta, opções
- criar classe dataset com perguntas e respostas
  - vetor pares pergunta <string>: unordered_map {a: <string>, b:<string>, c:<string>, d<string>}} 
  - 
- definir como armazenar perguntas e respostas

classe Pergunta: 
    string pergunta
    string resposta

    vetor string possibilidades

    randomizar() -> vetor string
    checarResposta(char ) -> bool

classe Dataset:
    set de muitas Perguntas

    sortearPergunta() -> retorna uma pergunta e elimina ela do set

classe Jogador:
    string nome
    double dinheiro_ganhado
    long sequencia
    char tecla

    responderPergunta()
    pegarPontuacao()
    atualizarPontuacao()
    atualzarSequencia()
    atualizarTecla()

classe Jogo: 
    Jogador p1_klink, p2_charlim
    long rodada_atual
    long recompensa_rodada * (DEFINE * rodada_atual)
    
    realizarRodada()
        - sortear pergunta
        - contar o tempo até soltar a pergunta (esperando a comepetição dos usuários)
        - checar quem digitou primeiro

classe Menu:

