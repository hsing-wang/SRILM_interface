#include "Prob.h"
#include "Ngram.h"
#include "Vocab.h"
#include "File.h"

#include "srilm.h"
#include <cstdio>
#include <cstring>
#include <cmath>

Vocab *swig_srilm_vocab;
const float BIGNEG = -99;

// Initialize the ngram model
Ngram* initLM(int order) {
  swig_srilm_vocab = new Vocab;
  return new Ngram(*swig_srilm_vocab, order);
}

// Delete the ngram model
void deleteLM(Ngram* ngram) {
  delete swig_srilm_vocab;
  delete ngram;
}

// Get index for given string
unsigned getIndexForWord(const char *s) {
	unsigned ans;
	ans = swig_srilm_vocab->addWord((VocabString)s);
	if(ans == Vocab_None) {
		printf("Trying to get index for Vocab_None.\n");
	}
        return ans;
}

float sriGetProb(Ngram* ngram, const char* word, const char* context, int order)
{
	unsigned int word_index = getIndexForWord(word);
	const char* words[7]; //max order is 7
        unsigned int indices[order];
        int numparsed;
        char* scp;
        float ans;
        
        // Duplicate string so that we don't mess up the original
        scp = strdupa(context);
                                                                                                                     
        // Parse the given string into words
        numparsed = Vocab::parseWords(scp, (VocabString *)words, order);

        // Get indices for the words obtained above, if you don't find them, then add them
        // to the vocabulary and then get the indices.
        swig_srilm_vocab->getIndices((VocabString *)words, (VocabIndex *)indices, order);       
	ans = ngram->wordProb(word_index, indices);
	return ans;
	
}

// Read in an LM file into the model
int readLM(Ngram* ngram, const char* filename) {
    File file(filename, "r");
    if(file.error()) {
        fprintf(stderr,"Error:: Could not open file %s\n", filename);
        return 0;
    }
    else
        return ngram->read(file, 0);
}



