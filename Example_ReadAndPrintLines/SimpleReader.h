//
// Created by lingran_lab_win7 on 2017/8/15.
//

#ifndef GENERICPROGRAMMINGANDTHESTL_SIMPLEREADER_H
#define GENERICPROGRAMMINGANDTHESTL_SIMPLEREADER_H

#include "../normalheader.h"

class SimpleReader {
private:
    vector<string> vct_string;
    istream *is_in;
    string temp;
public:
    SimpleReader() : is_in(&cin) {};

    SimpleReader(istream &in) : is_in(&in) {
        in.clear() ;
        in.seekg(0) ;
        while (getline(in, temp)) {
            vct_string.push_back(temp);
        }
        sort(vct_string.begin(), vct_string.end());
    };

    string PrintAll();
};


#endif //GENERICPROGRAMMINGANDTHESTL_SIMPLEREADER_H
