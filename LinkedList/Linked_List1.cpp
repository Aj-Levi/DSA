#include<iostream>
using namespace std;
#define ll long long 

// singly LL

class node{
    public:
    int data;
    node *next;

    node(int x){
        this->data=x;
        this->next=NULL;
    }
    ~node(){
        cout<<"hello"<<endl;
    }
};

void insAthead(node **head,int x){
    node *temp=new node(x);
    temp->next=(*head);
    (*head)=temp;
}

void insAttail(node **tail,int x){
    node *temp=new node(x);
    (*tail)->next=temp;
    (*tail)=temp;
}

void SLLinH(node **head,node **tail,int n){
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        if(i==0){
            node *temp=new node(x);
            (*tail)=temp;
            (*head)=temp;
        }
        else insAthead(head,x);
    }
}

void SLLinT(node **head,node **tail,int n){
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        if(i==0){
            node *temp=new node(x); // finally acchi chize start hogyi :)
            (*tail)=temp;
            (*head)=temp;
        }
        else insAttail(tail,x);
    }
}

void printSLL(node *head){
    node *copyhead=head;
    while(copyhead!=NULL){
        cout<<copyhead->data<<' ';
        copyhead=copyhead->next;
    }
    cout<<endl;
}

void insInMiddle(node **head,node **tail,int n,int x){
    if(n==1) insAthead(head,x);
    else{
        node *copyHead=(*head);
        for(int i=0;i<n-2;i++){
            copyHead=copyHead->next;
        }
        node *temp=new node(x);
        node *destcopyHead=copyHead->next;
        copyHead->next=temp;
        temp->next=destcopyHead;

        // updating tail when ins at end 
        if(copyHead==(*tail)) (*tail)=temp;
    }
}

void Delete(node **head,node **tail,int n){
    node *copyhead=(*head);
    if(n==1){
        (*head)=(*head)->next;
        copyhead->next=NULL; // just for safety while deleting 
        delete copyhead;
    }
    else{
        for(int i=0;i<n-2;i++){
            copyhead=copyhead->next;
        }
        node *temp=copyhead->next;
        if(copyhead->next==(*tail)) (*tail)=copyhead;
        copyhead->next=copyhead->next->next;
        temp->next=NULL;
        delete temp;
    }
}

int main(){
    int n;cin>>n;
    node *head=NULL;
    node *tail=NULL;
    SLLinT(&head,&tail,n);
    printSLL(head);
    insInMiddle(&head,&tail,5,5);
    printSLL(head);
    Delete(&head,&tail,5);
    printSLL(head);
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
}