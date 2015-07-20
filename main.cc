#include<iostream>

#include"srilm.h"

using namespace std;

int main()
{
	string str_lm_file("/home/xwang/2-Corpus/eng.fbis_xh.lm.o4.gz");
	int i_lm_order = 4;
	Ngram* ngram = initLM(i_lm_order);
	readLM(ngram, str_lm_file.c_str());
	
	string context1("I think you should");
	string context2("you can ");
	string word("do");

	cout << sriGetProb(ngram, word.c_str(), context1.c_str(), i_lm_order) << endl;
	cout << sriGetProb(ngram, word.c_str(), context2.c_str(), i_lm_order) << endl;
	cout << "work done." << endl;
	return 0;
}
