#include<bits/stdc++.h>
using namespace std;
                                                //remove nodes except leader
ListNode* reverseList(ListNode* head){          //head: 5->2->13->3->8   => ans: 13 -> 8
    ListNode* curr=head;
    ListNode* prev=NULL;

    while(curr!=NULL){
        ListNode* forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
    }
    head=prev;
    return head;
}
ListNode* removeNodes(ListNode* head) {
    head=reverseList(head);
    ListNode* maxx=head;
    ListNode* curr=head->next;

    while(curr!=nullptr){
        if(maxx->val>curr->val){
            maxx->next=curr->next;
        }
        else{
            maxx=curr;
        }
        curr=curr->next;
    }
    return reverseList(head);
}