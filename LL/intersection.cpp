// https://leetcode.com/problems/intersection-of-two-linked-lists/

public
class Solution
{
public
    ListNode getIntersectionNode(ListNode headA, ListNode headB)
    {
        ListNode a = headA;
        ListNode b = headB;

        while (a != b)
        {
            if (a == null)        // when one list ends, then make the list equal to the same other list, so they will end up on same, intersection node later when moved forward
            {
                a = headB;
            }
            else
                a = a.next;

            if (b == null)
            {
                b = headA;
            }
            else
                b = b.next;
        }
        return a; // when a==b, we get intersection point
    }
}