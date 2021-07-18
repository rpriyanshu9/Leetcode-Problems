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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
            return head;
        ListNode *res = NULL, *prev = NULL, *tempLL = NULL, *temp = head, *tempLLHead = NULL;
        bool ans = false;
        int ptr = 0;
        while (temp != NULL)
        {
            ptr++;
            if (ptr == 1)
            {
                tempLL = new ListNode(temp->val);
                tempLLHead = tempLL;
                temp = temp->next;
                continue;
            }
            ListNode *temp1 = new ListNode(temp->val);
            temp1->next = tempLL;
            tempLL = temp1;
            if (ptr == k)
            {
                ptr = 0;
                if (!ans)
                {
                    res = tempLL;
                    ans = true;
                }
                if (prev != NULL)
                {
                    prev->next = tempLL;
                }
                tempLLHead->next = temp->next;
                prev = tempLLHead;
            }
            temp = temp->next;
        }
        return res;
    }
};