# Trabalho-Pratico
Trabalho Prático para a disciplina de Programação e Desenvolvimento de Sostware II - Jogo de Poker Chinês

## O Jogo ##

O jogo foi programado em c++, para ter o prompt de comando, ou o Windows PowerShell.

Foi construído com base nas regras do

### As cartas: ##

O Poker Chinês utiliza um baralho padrão para o jogo, o que totaliza 52 cartas. As cartas podem ser jogadas de três formas diferentes:
> * Unitária;
> * Dupla (Duas cartas com o mesmo número e naipes diferentes);
> * Trinca (Trinca cartas com o mesmo número e naipes diferentes);
> * Um "Jogo de cinco" (Cinco cartas combinadas que equivalem às mãos do Poker convencional):
>> * Royal Flush;
>> * Straight Flush;
>> * Quadra;
>> * Full House;
>> * Flush;
>> * Sequência.


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

- Eu enquanto...
