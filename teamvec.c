#include "teamvec.h"
#include <stdlib.h>

// TODO: defina aqui os campos de "struct teamvec" -- pense no que o TAD
// precisa guardar para saber quantos times tem e quanto espaço ainda sobra
// struct teamvec {
//     ...
// };

#define CAP_INICIAL 10

struct teamvec {
    Team** times;
    int tam;
    int cap;
};

TeamVec* tv_create() {
    TeamVec* v = (TeamVec*) malloc(sizeof(TeamVec));
    if (v == NULL) return NULL;

    v->tam = 0;
    v->cap = CAP_INICIAL;
    v->times = (Team**) malloc(v->cap * sizeof(Team*));

    return v;
}

void tv_insert(TeamVec* v, Team* t) {
    if (v->tam == v->cap) {
        v->cap *= 2;
        v->times = (Team**) realloc(v->times, v->cap * sizeof(Team*));
    }

    v->times[v->tam] = t;
    v->tam++;
}

int tv_size(TeamVec* v) {
    return v->tam;
}

Team* tv_get(TeamVec* v, int indice) {
    if (indice >= 0 && indice < v->tam) {
        return v->times[indice];
    }
    return NULL;
}

void tv_free(TeamVec* v) {
    if (v != NULL) {
        for (int i = 0; i < v->tam; i++) {
            team_free(v->times[i]);
        }
        free(v->times);
        free(v);
    }
}
