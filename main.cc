#include<iostream>

#include"LanguageModel.h"

using namespace std;

int main()
{
	int i_lmn = 4;
	LanguageModel* lm = new LanguageModel();
	lm->init("/home/xwang/0-Workspace/10.hiero/4.corpus/en.giga.xh.v2.lc.o4.lm.gz", i_lmn);
	//lm->Load();
	
	string context("scientists to death");
	string word("early");
	cout << lm->getLMProb(context, word, i_lmn) << endl;
	
	cout << "over" << endl;
	return 0;
}
