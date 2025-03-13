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

node *getmid(node *head){
    node *slow=head;
    node *fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}

node *rev(node *head){
    node *prev=NULL;
    node *curr=head;

    while(curr!=NULL){
        node *dest=curr->next;
        curr->next=prev;
        prev=curr;
        curr=dest;
    }

    return prev;
}

bool chkpalindrome(node *head){
    node *mid=getmid(head);
    node *temp=rev(mid->next);
    mid->next=temp;

    node *start=mid->next;
    while(start!=NULL){
        if(start->data != head->data){
            return false;
        }
        start=start->next;
        head=head->next;
    }
    return true;
}

int main(){
    node *head=NULL;
    node *tail=NULL;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        node *temp=new node(x);
        if(i==0){
            head=temp;
            tail=temp;
        }
        else tail->next=temp,temp=tail;
    }

    cout<<(chkpalindrome(head)?"yes":"no")<<endl;
}