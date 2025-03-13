#include<iostream>

class node{
    public:
    int data;
    node *next;

    node(int d){
        this->data=d;
        this->next=NULL;
    }
};

node *merge(node *h1,node *h2){
    node *head=NULL;
    node *tail=NULL;
    while(h1!=NULL && h2!=NULL){
        if(h1->data < h2->data){
            if(head==NULL) head=h1,tail=h1;
            else{
                tail->next=h1;
                tail=h1;
            }
            h1=h1->next;
        }else{
            if(head==NULL) head=h2,tail=h1;
            else{
                tail->next=h2;
                tail=h2;
            }
            h2=h2->next;
        }
    }
    if(h1==NULL){
        while(h2!=NULL){
            tail->next=h2;
            tail=h2;
            h2=h2->next;
        }
    }
    if(h2==NULL){
        while(h1!=NULL){
            tail->next=h1;
            tail=h1;
            h1=h1->next;
        }
    }
    return head;
}