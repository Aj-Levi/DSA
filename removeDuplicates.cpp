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

void removeDuplicateSortedLL(node *head){
    if(head==NULL) return;

    node *curr=head;
    while(curr!=NULL){
        if(curr->next!=NULL && curr->data==curr->next->data){
            node *nextkanext=curr->next->next;
            curr->next->next=NULL;
            delete curr->next;
            curr->next=nextkanext;
        }else{
            curr=curr->next;
        }
    }
}

// unsorted LL

// O(n^2) approach

void app1(node *head)
{
    node *outer = head;
    while (outer != NULL)
    {
        node *prev = outer;
        node *inner = outer->next;
        while (inner != NULL)
        {
            if (inner->data == outer->data)
            {
                node *curr = inner;
                inner = inner->next;
                curr->next = NULL;
                delete curr;
                prev->next = inner;
            }
            else
                prev = inner, inner = inner->next;
        }
        outer = outer->next;
    }
}

// O(n) approach
unordered_map<int,bool> m;

void app2(node *head){
    node *temp=head;
    while(temp!=NULL){
        m[temp->data]=false;
        temp=temp->next;
    }

    node *curr=head->next;
    node *prev=head;
    m[prev->data]=true;

    while(curr!=NULL){
        if(m[curr->data]==true){
            node *dest=curr->next;
            curr->next=NULL;
            delete curr;
            prev->next=dest;
            curr=dest;
        }
        else m[curr->data]=true,prev=curr,curr=curr->next;
    }
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
    // removeDuplicateSortedLL(head);
    app2(head);
    printSLL(head);
}