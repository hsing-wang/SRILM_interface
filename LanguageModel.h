/*
* LanguageModel.h  -  Language Model
*
* Copyright (C) 2006 by Zhongjun He <zjhe@ict.ac.cn> 
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
#ifndef LANGUAGE_MODEL_H 
#define LANGUAGE_MODEL_H 
 
#include <string> 
//#include "lmsridll.h" 
#include"srilm.h"

using namespace std; 
 
class LanguageModel 
{ 
public: 
 
	// construction function 
	LanguageModel(); 
 
	// destruction function 
	~LanguageModel(); 
 
	// initialization  
	void init(const char* fileName, int lmngram); 
	 
	// return the Language Model probability log(p), default is 3-gram 
	double getLMProb(const string &context, const string &word, int n = 3); 
 
private: 
 
	Ngram *m_lmPtr;   // LM pointer 
	 
	// return LM probability log(p) 
	double getProb(const string &context, const string &word, const int& i_context_len); 
}; 
 
#endif
