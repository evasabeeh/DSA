// https://takeuforward.org/linked-list/length-of-loop-in-linked-list


class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast){

                int count = 0;
                slow = slow -> next;

                while(slow != fast){
                    count++;
                    slow = slow -> next;
                }
                return count;        // length of loop

/*
                ListNode *temp = head;
                while (temp != slow)
                {
                    temp = temp -> next;
                    slow = slow -> next;
                }
                return slow;          // start point of loop

*/
            }
        }
        return false;
    }
};