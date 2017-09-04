#include <iostream>
#include "normalheader.h"
#include "TestClassesIncluder.h"
TEST(testConst,t){
    class testIi{
        int *a ;
    public:
        testIi(int v):a(&v){
            cout<<"ori:"<<hex<<a ;
        } ;
        const int *CreturnA(){
            return a ;
        }
        int *returnAC() const {
            return a ;
        }
    };
    testIi c(4) ;
    cout<<"\nCreturnA:"<<c.returnAC() <<"\nreturnAC:"<<c.CreturnA();
}
//test each models
TEST_F(TestReadAndPrintLines,ReadAndPrint){
    //simpleReader
    SimpleReader sr(*in);
    sr.PrintAll() ;
    in->clear() ;
    in->seekg(0) ;
    //LineIterator
    LineIterator lineIterator(*in) ;
    LineIterator endOfFile;
    vector<string> v(lineIterator,endOfFile) ;
    sort(v.begin(),v.end()) ;
    copy(v.begin(),v.end(),ostream_iterator<string>(cout,"\n"));
    in->clear() ;
    in->seekg(0) ;
    //StrTableIterator
    vector<char> strtab ;
    char c;
    while(in->get(c)){
        strtab.push_back(c) ;
    }
    typedef vector<char>::iterator strtab_iterator ;
    vector<pair<strtab_iterator,strtab_iterator>> lines ;
    strtab_iterator start =  strtab.begin() ;
    while (start != strtab.end()){
        strtab_iterator next = find(start, strtab.end(), '\n');
        if(next!=strtab.end()){
            ++next ;
        }
        lines.push_back(make_pair(start,next)) ;
        start = next ;
    }
    sort(lines.begin() , lines.end() , strtab_cmp()) ;
    for_each(lines.begin() , lines.end() , strtab_print(cout)) ;
}
//test all
GTEST_API_ int main(int argc,char ** argv) {
    testing::InitGoogleTest(&argc,argv) ;
    return RUN_ALL_TESTS();
}