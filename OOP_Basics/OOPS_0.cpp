#include<iostream>
using namespace std;
#define ll long long

class hero{
    public:
    int health;
    string name;
    static int time;

    // multiple constructors with diff types of parameters
    // is called constructor overloading.(eg of polymorphism)
    hero(){}
    hero(int health,string name){  // parametrised constructor.
        this->health=health;
        this->name=name;
    }
    // this keyword is a pointer to current obj.
    hero(int h){ // easier way to above constructor 
        health=h;
    }
    hero(hero &h){  // khud ka bnaya hua copy constructor
        this->health=h.health;
        this->name=h.name;
    }

    ~hero(){ // destructor
        cout<<"destructor bhai called"<<endl;
    }

    static int demo(){ // static func can only access static data mem.
        return time;
    }

    int help(){
        return this->time;
    }
};

int hero :: time=3; // val will be same for all obj of this class

int main(){
    hero ramesh;
    hero h(ramesh); // copy constructor (default)
    hero s=h; // copy constructor (default)
    cout<<s.health<<' '<<s.name<<endl;

    // default copy constructor does shallow copying
}

int main(){
    hero h1;
    hero *h2=new hero;

    // manual destructor call
    delete h2;
}
// for statically allocated obj destructor is automatically called 
// when the obj scope dies out

// static keyword helps to create a property which can be 
//accessed without any obj creation 

// The concepts of shallow copy and deep copy in Object-Oriented Programming (OOP) refer to how objects are duplicated, particularly when an object contains references (or pointers) to other objects.