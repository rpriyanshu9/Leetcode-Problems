/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return head;
        int len = 0;
        int j = 0;
        ListNode *temp = head, *new_head = NULL;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        k %= len;
        if (k == 0)
            return head;
        temp = head;
        ListNode *tempNxt = NULL;
        while (temp != NULL)
        {
            j++;
            if (j == (len - k))
            {
                if (temp->next != NULL)
                    new_head = temp->next;
                else
                    new_head = head;
                tempNxt = temp->next;
                temp->next = NULL;
                break;
            }
            temp = temp->next;
        }
        while (tempNxt->next != NULL)
        {
            tempNxt = tempNxt->next;
        }
        tempNxt->next = head;
        return new_head;
    }
};