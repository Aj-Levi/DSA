#include<bits/stdc++.h>
using namespace std;

class person{
    public:
    string name;
    int age;
};

class student : public person{
    public: 
    int Class;
    private:
    int rollno;

    public:
    string getname(){
        return name;
    }
};

int main(){
    person p1;
    p1.name="hitesh";
    p1.age=18;
    student s1;
    s1.name="hello";
    cout<<s1.getname()<<endl;
}