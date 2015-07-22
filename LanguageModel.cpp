/* 
* LanguageModel.cpp  -  Language Model 
* 
* Copyright (C) 2006 by Yang Liu <yliu@ict.ac.cn>  
Multilingual Interaction Technology and Evaluation Laboratory, ICT, CAS 
 
* Begin       : 04/13/2006 
* Last Change : 04/13/2006 
* 
* This program is free software; you can redistribute it and/or 
* modify it under the terms of the GNU Lesser General Public 
* License as published by the Free Software Foundation; either 
* version 2.1 of the License, or (at your option) any later version. 
* 
* This program is distributed in the hope that it will be useful, 
* but WITHOUT ANY WARRANTY; without even the implied warranty of 
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
* GNU General Public License for more details. 
* 
* You should have received a copy of the GNU Lesser General Public 
* License along with this program; if not, write to the Free Software 
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA. 
*/   
   
#include <iostream>   
#include <cmath>   
#include <cfloat>   
#include <strstream>   
#include <vector>   
#include "LanguageModel.h"   
   
using namespace std;   
   
/************************************************  
  construction function  
************************************************/   
LanguageModel::LanguageModel()   
{   
   
}   
   
/************************************************  
  destruction function  
************************************************/   
LanguageModel::~LanguageModel()   
{   
        cout << "Exit SRI language model ... ";   
   
        //sriUnloadLM(lmPtr);   
	deleteLM(this->m_lmPtr);
   
        cout << "done!\n";   
}   
   
/************************************************  
 initialization  
************************************************/   
void LanguageModel::init(const char* fileName,int lmngram)   
{   
    cout << "Init SRI langauge model ... ";   
   
    //lmPtr = sriLoadLM(fileName, 1, lmngram, 1, 0);   
     this->m_lmPtr = initLM(lmngram);
     readLM(this->m_lmPtr, fileName);

    cout << "done!\n";   
}   
   
/************************************************  
  return the Language Model probability log(p)  
************************************************/   
double LanguageModel::getLMProb(const string &context, const string &word, int n)   
{   
    double prob = 0;   
    vector<string> wordVec1, wordVec2, wordVec;   
   
    istrstream buf1(context.c_str());   
    string w;   
    while (buf1 >> w)   
    {   
        wordVec1.push_back(w);   
    }   
   
    if(wordVec1.size()==0)   
         wordVec1.push_back(" ");   
   
    istrstream buf2(word.c_str());   
    while (buf2 >> w)   
    {   
        wordVec2.push_back(w);   
    }   
   
    int i;  
        // last n-1 words    
    for (i = (wordVec1.size() >= n - 1) ? wordVec1.size() - n + 1 : 0;    
         i < wordVec1.size();   
         i++)   
    {   
        wordVec.push_back(wordVec1[i]);   
    }   
    // push other words   
    for (i = 0; i < wordVec2.size(); i++)   
    {   
        wordVec.push_back(wordVec2[i]);   
    }   
   
    // compute probability   
    if (n > wordVec.size())   
    {   
   
        double p = getProb(context,word, n);   
        return p;   
    }   
   
    for (i = n - 1; i < wordVec.size(); i++)   
    {   
        string word2 = wordVec[i],   
               context2;   
   
   	int i_context_len = 0;
        for (int j = i - n + 1; j < i; j++)   
        {   
            context2 += wordVec[j];   
	    i_context_len++;
   
            if (j != i - 1)   
            {   
                context2 += " ";   
            }   
        }   
   
        double p = getProb(context2, word2, i_context_len);   
   
        if (p==0)   
            cout<<"context" <<context2 <<" "<<"word"<<" "<<word2<<" "<<p<<endl;   
   
        prob += p;   
    }   
   
    return prob;   
}   
   
/************************************************  
  return Language Model probability  
************************************************/   
double LanguageModel::getProb(const string &context, const string &word, const int& i_context_len)   
{   
    double prob = 0;   
    string s = context + " " + word;
   	
    //prob = sriWordProb(lmPtr, word.c_str(), context.c_str()) / log10(2.718);   
    prob = getNgramProb(this->m_lmPtr, s.c_str(), i_context_len+1) / log10(2.718);

    return prob;   
}
