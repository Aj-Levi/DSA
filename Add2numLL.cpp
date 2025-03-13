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

node *sum(node *h1,node *h2){
    int carry=0,chk=0;
    node *head=NULL;
    while(h1!=NULL && h2!=NULL){
        node *temp=new node((h1->data+h2->data+carry)%10);
        carry=(h1->data+h2->data+carry)/10;
        if(chk==0) head=temp,chk++;
        else temp->next=head,head=temp;
        h1=h1->next;h2=h2->next;
    }
    while(h1!=NULL){
        node *temp=new node((h1->data+carry)%10);
        carry=(h1->data+carry)/10;
        if(chk==0) head=temp,chk++;
        else temp->next=head,head=temp;
        h1=h1->next;
    }
    while(h2!=NULL){
        node *temp=new node((h2->data+carry)%10);
        carry=(h2->data+carry)/10;
        if(chk==0) head=temp,chk++;
        else temp->next=head,head=temp;
        h2=h2->next;
    }
    if(carry!=0){
        node *temp=new node(carry);
        temp->next=head;
        head=temp;
    }
    return head;
}

int main(){
    int n1,n2;cin>>n1>>n2;
    node *head1=NULL;
    for(int i=0;i<n1;i++){
        int x;cin>>x;
        node *temp=new node(x);
        if(i==0) head1=temp;
        else temp->next=head1,head1=temp;
    }
    node *head2=NULL;
    for(int i=0;i<n2;i++){
        int x;cin>>x;
        node *temp2=new node(x);
        if(i==0) head2=temp2;
        else temp2->next=head2,head2=temp2;
    }
    node *ans=sum(head1,head2);
    while(ans!=NULL){
        cout<<ans->data;
        ans=ans->next;
    }
    cout<<endl;
}