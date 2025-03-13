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

void printSLL(node *tail){
    while(tail!=NULL){
        cout<<tail->data<<' ';
        tail=tail->next;
    }
    cout<<endl;
}

unordered_map<node *,int> m;

bool detectAndRemoveCycle(node *head){ // O(n) : time and space comp.
    bool ans=false;
    node *prev=NULL;
    while(head!=NULL){
        if(!m[head]) m[head]=1,prev=head,head=head->next;
        else{
            ans=true;break;
        }
    }
    if(prev!=NULL) prev->next=NULL;
    return ans;
}

// Floyd's cycle detection.

bool cycleDetection(node *head){ // TC:O(n) , SC:O(1)
    if(head==NULL) return NULL;

    node *slow=head;
    node *fast=head;

    while(fast!=NULL && slow!=NULL){
        fast=fast->next;
        if(fast!=NULL) fast=fast->next;
        slow=slow->next;
        if(slow==fast) return true;
    }

    return false;
}

node *intersection(node *head){
    if(head==NULL) return NULL;

    node *slow=head;
    node *fast=head;

    while(fast!=NULL && slow!=NULL){
        fast=fast->next;
        if(fast!=NULL) fast=fast->next;
        slow=slow->next;
        if(slow==fast) return slow;
    }

    return NULL;
}

node *begginingOfCycle(node *head){
    node *intersec=intersection(head);

    if(intersec==NULL){
        cout<<"Loop doesn't exist";
        return NULL;
    }

    node *slow=head;

    while(slow!=intersec){
        slow=slow->next;
        intersec=intersec->next;
    }

    return slow;
}

int main(){
    node *head=NULL;
    node *tail=NULL;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        node *temp=new node(x);
        if(i==0) head=temp,tail=temp;
        else tail->next=temp,tail=temp;
    }
    node *copyhead=head->next;
    tail->next=copyhead;
    cout<<(cycleDetection(head)?"yes":"no")<<endl;
    cout<<begginingOfCycle(head)->data<<endl;
    //printSLL(head);
}