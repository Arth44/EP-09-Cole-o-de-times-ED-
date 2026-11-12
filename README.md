# EP 09 — Coleção de times

**Disciplina:** Estruturas de Dados — Instituto Federal do Espírito Santo (Ifes)  
**Módulo:** Vetores dinâmicos  

## Cenário

Este EP é o primeiro passo rumo ao Trabalho Prático **"Campeonato Computacional de Futebol"**.
Aqui você só cadastra os times inscritos, sem processar nenhuma partida ainda.

Cada time possui um registro com:

- `id`
- `name`
- cinco estatísticas: vitórias, empates, derrotas, gols marcados e gols sofridos

Todas as estatísticas começam zeradas — elas só serão atualizadas quando o campeonato
processar resultados de partidas, assunto de um módulo futuro (a partir de novembro).

Como não se sabe de antemão quantos times existem no arquivo de entrada, em vez de um
vetor de tamanho fixo, usa-se a mesma técnica de **vetor dinâmico** deste módulo, agora
aplicada a um registro (`struct`), e não a um `float` isolado.

## Como se calcula a classificação

### Saldo de Gols (S)

```
S = GM - GS
```

Não é lido do arquivo — é calculado na hora de imprimir.

### Pontos Ganhos (PG)

```
PG = 3*V + E
```

Também calculado, nunca armazenado no registro.

Neste EP, `V`, `E`, `D`, `GM` e `GS` de todo time começam em `0` — então `S` e `PG`
também saem `0` na tabela. As fórmulas acima já são as mesmas que valerão quando as
estatísticas passarem a ser atualizadas, em módulo futuro.

## Requisitos técnicos

### TAD `Team` (tipo opaco)

Campos (todos `int`, exceto `name`, que é string):

- `id`
- `name`
- `wins`
- `draws`
- `losses`
- `goals_scored`
- `goals_conceded`

Saldo e pontos **não** entram no registro — são calculados a partir dos outros campos.

Funções:

- `team_create(id, name)` — zera as 5 estatísticas
- 7 acessos (um por campo)
- `team_free`

Os campos só existem dentro de `team.c`, nunca em `team.h` nem em `main.c`.

### TAD `TeamVec` (tipo opaco)

Vetor dinâmico de `Team *` (ponteiros, não valores), com as funções:

- `tv_create`
- `tv_insert`
- `tv_size`
- `tv_get`
- `tv_free`

Mesma técnica do exemplo de vetor dinâmico de `float` visto em aula, inclusive a
realocação automática que dobra a capacidade quando o vetor enche.

A struct guarda três coisas: número atual de elementos, capacidade do vetor e o próprio
vetor alocado — só que agora de `Team *`, não de `float`.

### Leitura

Leia os times de um arquivo texto `teams.csv`, uma linha por time, no formato `id, nome`,
sem estatísticas (elas são zeradas por `team_create`), sem assumir nenhum número fixo de
times. Insira cada time lido com `tv_insert` até o arquivo acabar.

### Saída

Imprima a tabela de classificação:

```
ID | Time | V | E | D | GM | GS | Saldo | Pontos
```

na mesma ordem em que os times foram lidos do arquivo — sem ordenar.

## Exemplo de execução

```bash
$ gcc main.c -o main
$ ./main
```

A saída é a tabela de classificação com os times lidos de `teams.csv`.

## Código base

A leitura do arquivo e a impressão da tabela já vêm prontas no `main.c`. O que falta,
e é o conteúdo deste módulo, são os dois TADs: `Team` (em `team.h`/`team.c`) e
`TeamVec` (em `teamvec.h`/`teamvec.c`). Em ambos, só as assinaturas das funções estão
prontas — a definição da `struct` e o corpo de cada função são o exercício.

## Arquivos fornecidos

| Arquivo | Descrição |
|---|---|
| `team.h` | Tipo opaco `Team`, com as assinaturas do construtor (`team_create(id, name)`), dos 7 acessos (um por campo) e do destrutor |
| `team.c` | Definição de `struct team` e corpo das funções. Os campos só existem aqui |
| `teamvec.h` | Tipo opaco `TeamVec` (vetor dinâmico de `Team *`), com as assinaturas das 5 funções do TAD |
| `teamvec.c` | Definição de `struct teamvec` e corpo das 5 funções. Estrutura interna do TAD só aqui |
| `main.c` | Já completo: lê `teams.csv`, cria cada time com `team_create` e imprime a tabela usando só os acessos de `team.h` e as funções de `teamvec.h` |
| `Makefile` | Compila os quatro arquivos juntos (`make`) |
| `teams.csv` | Os 10 times do Campeonato Computacional de Futebol, usados no exemplo de execução |

## Compilação

Com `Makefile`:

```bash
make
./main
```

Ou manualmente:

```bash
gcc main.c team.c teamvec.c -o main
./main
```


## Times (teams.csv)

Os 10 times do Campeonato Computacional de Futebol:

1. JAVAlis
2. ESCorpiões
3. SemCTRL
4. GOrilas
5. PYthons
6. SeQueLas
7. NETunos
8. LOOPardos
9. RUSTicos
10. REACTivoS
