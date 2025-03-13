#include<iostream>
using namespace std;

// Doubly LL

class node{
    public:
    int data;
    node *next;
    node *prev;

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
    temp->prev=tail;
    tail->next=temp;
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

void insInMiddle(int n,int x){
    if(n==1){
        node *temp=new node(x);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }else{
        node *cpy=head;
        for(int i=0;i<n-2;i++){
            cpy=cpy->next;
        }
        if(cpy==tail){
            insAtT(x);
        }else{
            node *temp=new node(x);
            temp->next=cpy->next;
            cpy->next->prev=temp;
            temp->prev=cpy;
            cpy->next=temp;
        }
    }
}

void Delete(int n){
    if(n==1){
        node *temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        temp->prev=NULL;
        delete temp;
    }else{
        node *cpy=head;
        for(int i=0;i<n-2;i++){
            cpy=cpy->next;
        }
        if(cpy->next==tail){
            node *temp=cpy->next;
            cpy->next=NULL;
            temp->prev=NULL;
            delete temp;
            tail=cpy;
        }else{
            node *temp=cpy->next;
            cpy->next=cpy->next->next;
            cpy->next->prev=cpy;
            temp->next=NULL;
            temp->prev=NULL;
            delete temp;
        }
    }
}

int main(){
    int n;cin>>n;
    DLLinT(n);
    insAtT(6);
    printDLL();
    insInMiddle(6,10);
    printDLL();
    Delete(1);
    printDLL();
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    cout<<"sab sahi chal rha h"<<endl;
}