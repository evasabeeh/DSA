
Node<int>* solve(Node<int> *first, Node<int> *second)
{
    if(first -> next == NULL){
        first -> next = second;
        return first;
    }

    Node *curr1 = first;
    Node *next1 = curr1->next;

    Node *curr2 = second;
    Node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {

        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            // add node in between the first list
            curr1->next = curr2;
            curr2->next = next1;

            // update ptrs
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 =  next1 -> next;

            if(next1 == NULL){
                curr1 -> next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    if (first == NULL)
        return second;

    if (second == NULL)
        return first;

    if (first->data <= second->data)
    {
        solve(first, second);
    }
    else
    {
        solve(second, first);
    }
}





/*#include<bits/stdc++.h>
using namespace std;

struct node{
    struct node* next;
    int data;
};

struct node* ll1=NULL;          //initialise LL1
struct node* ll2=NULL;          //initialise LL2

void insert(struct node** head, int idx, int x){
    struct node* newNode=new node();
    newNode->data=x;
    if(head==NULL){              //LL is empty
        *head=newNode;
        newNode->next=NULL;
    }
    else if(idx==1){             //at beginning
        newNode->next=*head;
        *head=newNode;
    }
    else{                        //at end or given position
        struct node* temp=*head;
        for(int i=2;i<idx;i++){
            if(temp->next!=NULL){
                temp=temp->next;
            }
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}
struct node* merge(struct node* ll1, struct node* ll2) {   //recursion approach
    struct node* head=NULL;                                //merge two sorted lists
    if(ll1==NULL)
        return ll2;
    else if(ll2==NULL)
        return ll1;

    if(ll1->data<=ll2->data){
        head=ll1;               //assign node of ll to head
        head->next=merge(ll1->next, ll2);
    }
    else{
        head=ll2;
        head->next=merge(ll1, ll2->next);
    }
    return head;
}
void printList(struct node* head){
    if(head==NULL){
        cout<<"NULL"<<endl;;
    }
    else{
        cout<<head->data<<"->";
        printList(head->next);
    }
}

int main(){
    insert(&ll1, 1, 18);
    insert(&ll1, 2, 90);
    insert(&ll1, 3, 66);
    insert(&ll1, 4, 74);
    insert(&ll2, 1, 6);
    insert(&ll2, 2, 10);
    insert(&ll2, 3, 18);
    insert(&ll2, 4, 33);
    struct node* mergedList=NULL;      //initialising a merged list
    struct node* h=merge(ll1, ll2);
    printList(h);                      //displaying merged list
    
    return 0;
}*/

