class Solution
{
public:
    Node *segregate(Node *head)
    {
        Node *zero = new Node(-1);   // to traverse each list seperately for 0's, 1's, 2's
        Node *one = new Node(-1);
        Node *two = new Node(-1);

        Node *tempzero = zero, *tempone = one, *temptwo = two;   // to store start point of each list
        while (head)
        {
            Node *newNode = new Node(head->data);
            if (head->data == 0)
            {
                zero->next = newNode;
                zero = zero->next;
            }
            else if (head->data == 1)
            {
                one->next = newNode;
                one = one->next;
            }
            else if (head->data == 2)
            {
                two->next = newNode;
                two = two->next;
            }
            head = head->next;
        }

        tempzero = tempzero -> next;    // to remove -1
        tempone = tempone -> next;
        temptwo = temptwo -> next;

        one->next = temptwo;
        two->next = nullptr;
        zero->next = tempone;

        return tempzero
    }
};
