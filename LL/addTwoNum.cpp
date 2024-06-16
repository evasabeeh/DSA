#include<bits/stdc++.h>
using namespace std;
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head=nullptr;
    stack<int> a, b;
    while(l1!=nullptr){
        a.push(l1->val);
        l1=l1->next;
    }
    while(l2!=nullptr){
        b.push(l2->val);
        l2=l2->next;
    }
    int carry=0;
    queue<int> q;
    while(!a.empty()||(!b.empty())||carry!=0){
        int x=(!a.empty())?a.top():0;
        int y=(!b.empty())?b.top():0;
        if(!a.empty())
        a.pop();
        if(!b.empty())
        b.pop();

        int sum=x+y+carry;
        int add=sum%10;
        carry=sum/10;

        ListNode* node=new ListNode(add);
        node->next=head;
        head=node;
    }
    return head;
}
int main(){
    ListNode* head=addTwoNumbers(l1, l2);
    while(head!=nullptr){
        cout<<head->val;
        head=head->next;
    }
    return 0;
}