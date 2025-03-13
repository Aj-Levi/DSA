#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int x){
        this->data=x;
        this->next=NULL;
    }
};

node *head=NULL;
node *tail=NULL;

void insAtT(int x){
    node *temp=new node(x);
    tail->next=temp;
    tail=temp;
}

void SLLinT(int n){
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(i==0){
            node *temp=new node(x);
            tail=temp;
            head=temp;
        }
        else insAtT(x);
    }
}

int getlen(){
    node *cpy=head;
    int res=0;
    while(cpy!=NULL){
        res++;
        cpy=cpy->next;
    }
    return res;
}

node *middle(){
    int len=getlen();
    int move=len/2;
    node *cpy=head;
    for(int i=0;i<move;i++){
        cpy=cpy->next;
    }
    return cpy;
}

node *middle_optimised(){
    if(head==tail) return head;
    if(head->next==tail) return tail;
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL) fast=fast->next;
        slow=slow->next;
    }
    return slow;
}

void printSLL(){
    node *cpy=head;
    while(cpy!=NULL){
        cout<<cpy->data<<' ';
        cpy=cpy->next;
    }
    cout<<endl;
}

node* kReverse(node* head, int k) {
    //base call
    if(head == NULL) {
        return NULL;
    }
    
    //step1: reverse first k nodes
    node* next = NULL;
    node* curr = head;
    node* prev = NULL;
    int count= 0;
    
    while( curr != NULL && count < k ) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    //step2: Recursion dekhlega aage ka 
    if(curr != NULL) {
        head -> next = kReverse(next,k);
    }
    
    //step3: return head of reversed list
    return prev;
}

int main(){
    int n;cin>>n;
    SLLinT(n);
    printSLL();
    node *temp=kReverse(head,3);
    while(temp!=NULL){
        cout<<temp->data<<' ';
        temp=temp->next;
    }
    cout<<endl;
    // printSLL();
    //cout<<middle_optimised()->data<<endl;
    cout<<"sab sahi chal rha h"<<endl;
    return 0;
}