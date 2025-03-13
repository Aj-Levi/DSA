#include<iostream>

class node{
    public:
    int data;
    node* next;

    node(int d){
        this->data=d;
        this->next=NULL;
    }
};

node *getmid(node *head){
    if(head==NULL) return NULL;

    node *slow=head;
    node *fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}

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
            if(head==NULL) head=h2,tail=h2;
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

node* mergesort(node *head){
    if(head==NULL || head->next==NULL) return head;

    node *mid=getmid(head);
    node *dest=mid->next;
    node *lft=head;
    mid->next=NULL;
    lft = mergesort(lft);
    dest = mergesort(dest);
    return merge(lft,dest);
}