#ifndef SRILMWRAP_H
#define SRILMWRAP_H

#include"Ngram.h"

#ifdef __cplusplus
  extern "C" {
#else
    typedef struct Ngram Ngram; /* dummy type to stand in for class */
#endif

Ngram* initLM(int order);
void deleteLM(Ngram* ngram);
int readLM(Ngram* ngram, const char* filename);
float sriGetProb(Ngram* ngram, const char* word, const char* context, int order);
unsigned getIndexForWord(const char* s);

#ifdef __cplusplus
  }
#endif

#endif

