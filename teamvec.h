#ifndef TEAMVEC_H
#define TEAMVEC_H

#include "team.h"

// Opaque dynamic vector type: a growable array of Team pointers.

typedef struct teamvec TeamVec;

// TODO: implemente tv_create -- aloca o TAD e um vetor inicial pequeno (ex.: 4 times)
TeamVec* tv_create();

// TODO: implemente tv_insert -- se o vetor estiver cheio, dobre a capacidade
// (realloc) antes de inserir o novo time
void tv_insert(TeamVec* v, Team* t);

// TODO: implemente tv_size -- retorna o número de times atualmente guardados
int tv_size(TeamVec* v);

// TODO: implemente tv_get -- retorna o time na posição i
Team* tv_get(TeamVec* v, int indice);

// TODO: implemente tv_free -- libera cada time guardado, o vetor interno e depois o TAD
void tv_free(TeamVec* v);

#endif
