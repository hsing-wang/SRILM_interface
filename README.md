
A c++ interface for SRILM, which is adaptd from https://github.com/desilinguist/swig-srilm.


Language files are adapted from http://read.pudn.com/downloads74/sourcecode/chinese/264707/CAMEL/Camel_linux/LanguageModel.h__.htm 
		and http://read.pudn.com/downloads74/sourcecode/chinese/264707/CAMEL/Camel_linux/LanguageModel.cpp__.htm


How to use it?
1. g++ srilm.h srilm.cc main.cc -I /home/xwang/1-Tools/srilm/include ./lib/i686-m64/liboolm.a ./lib/i686-m64/libdstruct.a ./lib/i686-m64/libmisc.a ./lib/i686-m64/liblattice.a ./lib/i686-m64/libflm.a -lpthread
2. ./a.out

