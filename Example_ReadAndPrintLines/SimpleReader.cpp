//
// Created by lingran_lab_win7 on 2017/8/15.
//


#include "SimpleReader.h"

string SimpleReader::PrintAll() {
    copy(vct_string.begin(),vct_string.end(),ostream_iterator<string>(cout,"\n"));
    return std::__cxx11::string();
}
