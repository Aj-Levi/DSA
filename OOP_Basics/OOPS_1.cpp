#include <iostream> // toggle word wrap for better experience :)
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

class hero{
    public:
        int* health; // when an obj is created then this ptr will be NULL by default, so make sure to allocate memory dynamically before storing data in it.
        string name; 
        char level;
    
        hero(int h,string n,char l){
            this->health=new int;
            *(this->health)=h;
            this->name=n;
            this->level=l;
        }

        void sethealth(int h){
            this->health=new int;
            *(this->health)=h;
        }
        void setname(string str){
            this->name=str;
        }
        int gethealth(){
            return *(this->health);
        }
        string getname(){
            return this->name;
        }
        void print(){
            cout<<"name : "<<this->name<<endl;
            cout<<"health : "<<*(this->health)<<endl;
            cout<<"level : "<<this->level<<endl;
        }
};

void solve(){
    hero hello(18,"abhijeet",'A');
    hello.print();
    cout<<"--------"<<endl;
    hero ramesh(hello); // we have not made any copy constructor therefore the default copy constructor will be called 

    // the default copy constructor does shallow copying -> that is changing the value of any *pointer* data member reflects the change in  all the copies also irregardless of wether the change was made in original or the copy obj.

    // self define copy constructor does deep copying.
    ramesh.print();cout<<"--------"<<endl;
    *(ramesh.health)=1000;
    hello.print();cout<<"--------"<<endl;
    ramesh.print();
    return;
}