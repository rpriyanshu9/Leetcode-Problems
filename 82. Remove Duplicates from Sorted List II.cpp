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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        ListNode *res = head, *prev = NULL;
        while (head != NULL)
        {
            ListNode *temp = head;
            int value = temp->val;
            int cnt = 0;
            while (temp != NULL && temp->val == value)
            {
                cnt++;
                temp = temp->next;
            }
            if (cnt > 1)
            {
                if (prev != NULL)
                    prev->next = temp;
                else
                    res = temp;
            }
            else
            {
                head->next = temp;
                prev = head;
            }
            head = temp;
        }
        return res;
    }
};