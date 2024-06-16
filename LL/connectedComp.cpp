#include<bits/stdc++.h>
using namespace std;
                                                              //Count connected components 0,1 and 3,4,5: values are connected if they appear consecutively
int numComponents(ListNode* head, vector<int>& nums) {        //head: 0->1->2->3->4->5   nums=[0,3,1,4,5]
    int count=0;
    ListNode* temp=head;

    if(head==nullptr)
    return 0;

    while(temp!=nullptr){
        if(find(nums.begin(), nums.end(), temp->val)!=nums.end()){
            count++;
            while(temp->next!=nullptr&&find(nums.begin(), nums.end(), temp->next->val)!=nums.end()){
                temp=temp->next;
            }
        }
        temp=temp->next;
    }
    return count;
}