//
// Created by lingran_lab_win7 on 2017/8/16.
//

#ifndef GENERICPROGRAMMINGANDTHESTL_TESTREADANDPRINTLINES_H
#define GENERICPROGRAMMINGANDTHESTL_TESTREADANDPRINTLINES_H

#include "../../normalheader.h"

class TestReadAndPrintLines : public ::testing::Test {

protected:
    string filePath = "F:/clion_projects_folder/STLBooks/"
            "GenericProgrammingAndTheSTL/Example_ReadAndPrintLines/res/testReader.txt";
    ifstream *in;

    TestReadAndPrintLines() {

    }

    virtual void SetUp() {
        in = new ifstream(filePath, ios::in);
        if(!in->is_open()){
            cout << "Error opening file";
            exit (1);
        }
    }

    virtual void Teardown(){
        in->close() ;
        in = NULL ;
    }
};

#endif //GENERICPROGRAMMINGANDTHESTL_TESTREADANDPRINTLINES_H
