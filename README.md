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


### Príncipios básicos: ###
#### Partida: ####

#### Jogo: ####

#### Contagem de pontos: ####

#### Duplicar: ####

#### Triplicar ####

## Sobre o código: ##

### Documentação: ###

### Como compilar: ##

### Classes criadas: ###

#### Card:
Tad criado para armazenar os dados que compôem uma carta sendo eles seu valor e seu naipe.
##### Funções:
###### card:
É o construtor, recebe um valor e um naipe como parãmetros e cria um card usando-os.
Recebe: Int, String
Retorna: Nada

###### Get_suit:
Retorna o naipe da carta.

Recebe: Nada
Retorna: String

###### Get_valor:
Retorna o valor da carta

Recebe: Nada
Retorna: Int

###### get_nome_completro:
Retorna qual a carta em questão no formato:"nome" de "naipe".

Recebe: Nada
Retorna: String

###### get_nome:
Retorna o conteúdo da variável nome

Recebe: Nada
Retorna: String 

###### get_numero:
Retorna o valor guardado na variável número.

Recebe: Nada
Retorna: Char
######  get_naipe:
Retorna o valor na variável naipe:

Recebe: Nada
Retorna: Char
###### operator ==:
Retorna true se as cartas forem de pontuação equivalente. Utiliza o operator>.

Recebe: Const Card&
Retorna: bool

##### operator >:
Retorna verdadeiro se a carta em questão for maior em pontuação que a carta passada como parâmetro.

Recebe: Const Card&
Retorna: bool



#### Deck:
Armazena um vector de cards que compôem o baralho da partida.
##### Funções:
###### myrandom:
Define a distribuição probabilística para o embaralhamento do vector que contém as cartas.

Recebe: Int;

Retorna: Int;

###### create_hand:
Pega os doze primeiros cards do vector Deck e os distribui em quatro vectors para servirem de mãos para os players.

Recebe: Vector<card>
  
Retorna: Nada
###### shuffle:
Embaralha o vector de cards em função da distribuição representada por myrandom. Logo após chama a função create_hand.

Recebe: Vector<card>
  
Retorna: Nada
  
###### Deck:
É o construtor do deck que gera um vector de cards em ordem e logo depois utiliza a função shuflle para embaralha-las.

Recebe: Nada

Retorna: Nada

# User Stories:

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