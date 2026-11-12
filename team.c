#include "team.h"
#include <stdlib.h>
#include <string.h>

// TODO: defina aqui os campos de "struct team"
// struct team {
//     ...
// };

struct team {
    int id;
    char* nome;
    int vitorias;
    int empates;
    int derrotas;
    int gols_marcados;
    int gols_sofridos;
};

Team* team_create(int id, const char* nome) {
    Team* t = (Team*) malloc(sizeof(Team));
    if (t == NULL) return NULL;

    t->id = id;
    
    t->nome = (char*) malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(t->nome, nome);

    t->vitorias = 0;
    t->empates = 0;
    t->derrotas = 0;
    t->gols_marcados = 0;
    t->gols_sofridos = 0;

    return t;
}

int team_get_id(Team* t) { return t->id; }
char* team_get_name(Team* t) { return t->nome; }
int team_get_wins(Team* t) { return t->vitorias; }
int team_get_draws(Team* t) { return t->empates; }
int team_get_losses(Team* t) { return t->derrotas; }
int team_get_goals_scored(Team* t) { return t->gols_marcados; }
int team_get_goals_conceded(Team* t) { return t->gols_sofridos; }

void team_free(Team* t) {
    if (t != NULL) {
        if (t->nome != NULL) {
            free(t->nome);
        }
        free(t);
    }
}
