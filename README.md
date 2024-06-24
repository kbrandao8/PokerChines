# Trabalho-Pratico
Trabalho Prático para a disciplina de Programação e Desenvolvimento de Sostware II - Jogo de Poker Chinês

## O Jogo ##

O jogo foi programado em c++, para ter o prompt de comando, ou o Windows PowerShell.

Foi construído com base nas regras do

### As cartas: ##

O Poker Chinês utiliza um baralho padrão para o jogo, o que totaliza 52 cartas. As cartas podem ser jogadas de três formas diferentes:
* Unitária;
* Dupla (Duas cartas com o mesmo número e naipes diferentes);
* Trinca (Trinca cartas com o mesmo número e naipes diferentes);
* Um "Jogo de cinco" (Cinco cartas combinadas que equivalem às mãos do Poker convencional):
> * Royal Flush;
> * Straight Flush;
> * Quadra;
> * Full House;
> * Flush;
> * Sequência.

### Princípios básicos: ###
#### Partida: ####
* O jogo de poker chinês é jogado pquatro jogadores.
* Cada jogador recebe 13 cartas de um baralho padrão de 52 cartas.
* A partida se inicia com a jogada da pessoa que saiu com a carta 3 de ouros.
* O jogador que inicia a rodada, pode jogar uma carta individual, uma dupla, uma trinca, ou um jogo de cinco cartas respeitando as mãos do poker, sendo os demais obrigados a seguir essa mão até o fim da rodada.

#### Jogo: ####
* O objetivo do jogo é descartar o maior número de cartas possíveis antes dos demais jogadores.
* No início de cada rodada é determinada qual será a regra da rodada (trinca, dupla...)
* A rodada finaliza quando um ou mais jogares ficam sem cartas.
#### Contagem de pontos: ####
* O Número de cartas restantes na mão de cada jogador após o fim da rodada é somado na sua pontuação final
* O jogo termina quando um jogados chega aos 25 pontos ou mais.
* O jogador que tiver menos ponto é o vencedor so jogo.

# Modelagem
### Requisitos
#### Requisitos Funcionais
> 1. Personalização de Nomes dos Jogadores
> 2. Embaralhamento e Distribuição de Cartas
> 3. Visualização das Cartas na Mão do Jogador
> 4. Determinação do Primeiro Jogador
> 5. Mão da Rodada e Validade das Jogadas
> 6. Pontuação e Acumulação de Pontos
> 7. Finalização e Encerramento do Jogo

#### Requisitos Não Funcionais
> 1. Usabilidade
> 2. Manutenção


### User Story 01:

**Como um** jogador, **Quero** personalizar o nome dos jogadores, **Para que** eu possa identificar facilmente quem é quem no jogo.

**Critérios de Aceitação:**

> 1. Deve haver uma opção para inserir nomes personalizados para cada jogador.
> 2. Os nomes personalizados devem ser exibidos durante o jogo.
> 3. Os nomes devem ser salvos e exibidos corretamente em cada rodada e partida.

### User Story 02:

**Como um** jogador, **Quero** que o baralho seja embaralhado e as cartas sejam distribuídas aleatoriamente, **Para que** o jogo seja justo.

**Critérios de Aceitação:**

> 1. O baralho deve conter 52 cartas antes de ser embaralhado.
> 2. As cartas devem ser embaralhadas aleatoriamente.
> 3. Cada jogador deve receber 13 cartas após o embaralhamento.
> 4. As cartas devem ser distribuídas no início de cada partida.
> 5. Nenhuma carta deve ser duplicada entre as mãos dos jogadores.
> 6. O embaralhamento deve produzir diferentes sequências de cartas a cada execução do programa.

### User Story 03:

**Como um** jogador, **Quero** ver as cartas na minha mão, **Para que** eu possa tomar decisões informadas durante o jogo.

**Critérios de Aceitação:**

> 1. As cartas na mão de cada jogador devem ser exibidas de forma clara e legível.
> 2. Cada carta deve mostrar seu valor e naipe.
> 3. A mão deve ser exibida após a distribuição das cartas.
> 4. O jogador deve ser notificado de sua vez de jogar.
> 5. Após cada rodada deve ficar exibido quais as cartas ainda disponíveis na mão do jogador.
> 6. Após jogar uma carta, ela deve ser exibida na mesa para todos os jogadores.

### User Story 04:

**Como um** jogador, **Quero** saber quem deve iniciar a rodada, **Para que** eu possa saber minha hora de jogar.

**Critérios de Aceitação:**

> 1. Para primeira rodada da partida, o jogador que tiver em mãos a carta 3 de ouros deve começar a jogar.
> 2. Nas demais rodadas, o vencedor da última rodada, ou partida, é quem deve começar o jogo.
> 3. A ordem dos jogadores segue o sentido horário.
> 4. O sistema deve sinalizar qual o próximo a jogar.

### User Story 05:

**Como um** jogador, **Quero** saber qual é a “mão da rodada”, **Para que** eu possa escolher quais cartas irei jogar.

**Critérios de Aceitação:**

> 1. O jogador que inicia a rodada determina qual será a “mão da rodada”.
> 2. As “mãos da rodada” determinam o tipo de jogo que cada jogador deve jogar: uma carta individual, uma dupla, ou cinco cartas que formam uma das mãos do poker.
> 3. O valor da mão da rodada é determinado pelo naipe e valor da carta de maior valor, respeitando a ordem das mãos do poker (caso de cinco cartas).
> 4. O sistema deve exibir para os jogadores qual a “mão da rodada” atual.
> 5. O sistema não deve permitir jogadas que não respeitem a “mão da rodada” vigente.

### User Story 06:

**Como um** jogador, **Quero** poder escolher a(s) carta(s) que irei jogar, **Para que** eu possa fazer minhas jogadas,

**Critérios de Aceitação:**

1. O jogador não pode jogar uma carta, ou conjunto de cartas,  que não correspondem as regras da “mão da rodada”.
2. O jogador não pode jogar uma carta, ou conjunto de cartas, que não seja maior que a do jogador anterior.
3. Uma mensagem deve ser exibida informando o jogador caso a sua jogada seja proibida.

### User Story 07:

**Como um** jogador, **Quero** poder pular a rodada, **Para que** eu possa aplicar minha estratégia de jogo para a próxima rodada ou caso eu não tenha cartas que correspondem a “mão da rodada”.

**Critérios de Aceitação:**

1. O primeiro jogador não pode pular a rodada.
2. O jogador que pular a rodada só poderá jogar novamente na próxima rodada.
3. O jogador pode pular a rodada mesmo tento cartas possíveis de serem jogadas.
4. Quando sobrar apenas um jogador ele ganha a rodada e inicia a próxima.

### User Story 08:

**Como um** jogador, **Quero** que minhas cartas sejam removidas após cada partida, **Para que** o jogo possa continuar sem interferências das rodadas anteriores.

**Critérios de Aceitação:**

1. As mãos dos jogadores devem ser limpas após cada partida.
2. As novas cartas devem ser distribuídas corretamente na próxima rodada.

### User Story 09:

**Como um** jogador, **Quero** que os pontos sejam acumulados ao longo de várias partidas, **Para que** eu possa ver quem está ganhando ao longo do jogo.

**Critérios de Aceitação:**

1. Os pontos devem ser atualizados corretamente após cada partida.
2. O sistema deve manter um registro da pontuação total de cada jogador.
3. As pontuações de todos os jogadores devem ser exibidas claramente após cada partida.
4. A pontuação acumulada em cada partida é igual ao número de cartas restantes nas mãos dos jogadores.
5. Uma partida termina após a rodada em que um ou mais jogadores não tiverem mais cartas.

### User Story 10:

**Como um** jogador, **Quero** poder decidir quando o jogo deve terminar, **Para que** possamos parar de jogar quando quisermos.

**Critérios de Aceitação:**

1. Deve haver uma opção para encerrar o jogo após cada partida.
2. Ao encerrar o jogo, as pontuações finais devem ser exibidas e o jogador com menor pontuação declarado vencedor.
3. O sistema deve confirmar a intenção do jogador antes de encerrar o jogo.
4. Para o caso de empate, o sistema deve exibir todos os “vencedores”.
5. Após uma partida, se um dos jogadores termina com uma pontuação final igual ou maior a 25, o jogo acaba.




# Sobre o código:

### Documentação: ###

### Como compilar: ##

### Classes criadas: ###

#### Card:
**Atributos:**
* Suit suit - Armazena o naipe da carta (Copas, Ouros, Paus, Espadas).
* Rank rank - Armazena o valor da carta (2, 3, 4, ..., 10, Valete, Rainha, Rei, Ás).

**Métodos:**
* Card(Suit suit, Rank rank) - Construtor que inicializa uma carta com um naipe e um valor específicos.
* Suit getSuit() const - Retorna o naipe da carta.
* Rank getRank() const - Retorna o valor da carta.
* std::string toString() const - Retorna uma representação em string da carta, no formato "Valor de Naipe".

#### Deck:

**Atributos:**

* std::vector<Card> cards - Vetor que armazena as cartas do baralho.
* size_t currentCardIndex - Índice da carta atual a ser distribuída.

**Métodos:**

* Deck() - Construtor que inicializa o baralho com todas as cartas e as embaralha.
* void shuffle() - Embaralha as cartas do baralho.
* Card dealCard() - Distribui uma carta do topo do baralho e a remove do vetor.
* bool isEmpty() const - Verifica se o baralho está vazio.
* void reset() - Reseta o baralho para o estado inicial (todas as cartas presentes e embaralhadas).



Lista da Classe GameRound
Atributos:

Card handOfRound - Armazena a carta da "mão da rodada".
Métodos:

GameRound() - Construtor que inicializa a "mão da rodada" com uma carta padrão (2 de Copas).
void setHandOfRound(const Card& card) - Define a carta da "mão da rodada".
Card getHandOfRound() const - Retorna a carta da "mão da rodada".
bool isValidMove(const std::vector<Card>& cards) const - Verifica se um movimento é válido com base na "mão da rodada".

Lista da Classe Player
Atributos:

std::string name - Nome do jogador.
std::vector<Card> hand - Vetor que armazena a mão de cartas do jogador.
Métodos:

Player(const std::string& name) - Construtor que inicializa o jogador com um nome.
std::string getName() const - Retorna o nome do jogador.
void setName(const std::string& playerName) - Define o nome do jogador.
std::vector<Card> getHand() const - Retorna a mão de cartas do jogador.
void setHand(const std::vector<Card>& cards) - Define a mão de cartas do jogador.
void addToHand(const Card& card) - Adiciona uma carta à mão do jogador.
void removeFromHand(const Card& card) - Remove uma carta da mão do jogador.
void clearHand() - Limpa a mão do jogador.
std::vector<Card> playCards() - Faz o jogador jogar as cartas da mão.
bool hasCards() const - Verifica se o jogador ainda tem cartas na mão.







Lista da Classe pokerChines
Atributos:

std::vector<Player> players - Vetor que armazena os jogadores.
Deck deck - Baralho de cartas.
GameRound currentGameRound - Rodada atual do jogo.
int currentRoundStarter - Índice do jogador que começa a rodada.
int winnerIndex - Índice do jogador vencedor da rodada.
int currentRound - Número da rodada atual.
std::vector<int> scores - Vetor que armazena as pontuações dos jogadores.
Métodos:

pokerChines(const std::vector<std::string>& playerNames) - Construtor que inicializa o jogo com os nomes dos jogadores.
void playGame() - Inicia o jogo.
void dealCards() - Distribui as cartas para os jogadores.
void determineRoundStarter() - Determina quem começa a rodada.
void determineHandOfRound() - Determina a "mão da rodada".
void playRound() - Joga uma rodada.
bool isValidMove(const std::vector<Card>& cards) - Verifica se uma jogada é válida.
bool promptEndGame() - Pergunta se o jogo deve terminar.
void displayScores() - Exibe as pontuações dos jogadores.