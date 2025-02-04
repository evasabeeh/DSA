class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next)              // for even and odd number of nodes in LL
            return slow->next;
        else
            return slow;
    }
};