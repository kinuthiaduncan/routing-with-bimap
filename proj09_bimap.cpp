#include<iostream>
#include "proj09_bimap.h"
#include<algorithm>
#include<sstream>
#include<iterator>
using std::ostream_iterator;
using std::ostringstream;
using namespace std;

template<typename T>
string vector2string(vector<T> v){
    ostringstream oss;
    copy(v.begin(), v.end(), ostream_iterator<string>(oss, ","));
    string result = oss.str();

    return result.substr(0, result.size()-1);
}

bool BiMap::add(string, string){

}

string vector2string(vector<T> v){
    ostringstream oss;
    string result = oss.str();
    return result.substr(0, result.size()-1);
}

int main(){
    BiMap biMap;
    biMap.add("test", "test");
}
