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
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *start = head, *curr = head, *previous = NULL;
        while (curr != NULL)
        {
            ListNode *nxt = curr->next;
            ListNode *temp = start, *prev = NULL;
            bool flag = 0;
            while (temp != curr)
            {
                if (temp->val <= curr->val)
                {
                    prev = temp;
                    temp = temp->next;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                previous->next = curr->next;
                if (prev != NULL)
                {
                    prev->next = curr;
                }
                else
                {
                    start = curr;
                }
                curr->next = temp;
            }
            else
            {
                previous = curr;
            }
            curr = nxt;
        }
        return start;
    }
};