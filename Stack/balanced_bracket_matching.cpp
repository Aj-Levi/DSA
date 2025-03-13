#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <iomanip>
#include <ios>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <numeric>
#include <unordered_map>
using namespace std;

string is_balanced(string str){
    unordered_map<char,int>m;
    m.insert(make_pair('[',-1));
    m.insert(make_pair('{',-2));
    m.insert(make_pair('(',-3));
    m.insert(make_pair(']',1));
    m.insert(make_pair('}',2));
    m.insert(make_pair(')',3));
    stack<char>st;
    for(auto &value : str){
        if(m[value]<0){
            st.push(value);
        }else{
            if(st.empty()){
                return "NO";
            }else{
                if((m[value]+m[st.top()])==0){
                    st.pop();
                }else{
                    return "NO";
                }
            }
        }
    }
    if(st.empty()){
        return "YES";
    }else{
        return "NO";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        cout << is_balanced(str) << endl;
    }

}