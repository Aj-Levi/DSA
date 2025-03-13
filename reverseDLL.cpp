#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *prev;
    node *next;

    node(int x){
        this->data=x;
        this->next=NULL;
        this->prev=NULL;
    }
};

node *head=NULL;
node *tail=NULL;

void insAtT(int x){
    node *temp=new node(x);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void DLLinT(int n){
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(i==0){
            node *temp=new node(x);
            head=temp;
            tail=temp;
        }
        else insAtT(x);
    }
}

void printDLL(){
    node *copyhead=head;
    while(copyhead!=NULL){
        cout<<copyhead->data<<' ';
        copyhead=copyhead->next;
    }
    cout<<endl;
}

void printrev(){
    node *copytail=tail;
    while(copytail!=NULL){
        cout<<copytail->data<<' ';
        copytail=copytail->prev;
    }
    cout<<endl;
}

void rev(){
    node *copyhead=head;
    while(copyhead!=NULL){
        swap(copyhead->next,copyhead->prev);
        copyhead=copyhead->prev;
    }
    swap(head,tail);
}

int main(){
    int n;cin>>n;
    DLLinT(n);
    //printDLL();
    rev();
    printDLL();
    //printrev();
}