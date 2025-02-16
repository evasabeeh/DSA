class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *curr = head;
        int count = 0;
        while (curr && count < k)
        {
            curr = curr->next;
            count++;
        }

        if (count == k)
        {        // reverse first k nodes
            ListNode *prev = reverseKGroup(curr, k);
            while (count--)
            {
                ListNode *temp = head->next;
                head->next = prev;
                prev = head;
                head = temp;
            }
            head = prev;
        }
        return head;
    }
};

/*  this work only when last <k nodes can be reversed
Node *kReverse(Node *head, int k)
{
    // base call
    if (head == NULL)
    return NULL;

    // step1: reverse first k nodes
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step2: Recursion dekhlega aage ka
    if (next != NULL)
    {
        head->next = kReverse(next, k);
    }

    // step3: return head of reversed list
    return prev;
}

*/