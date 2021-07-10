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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int sz = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            sz++;
            temp = temp->next;
        }
        vector<ListNode *> res;
        if (k >= sz)
        {
            for (int i = 0; i < k; i++)
            {
                if (head != NULL)
                {
                    res.push_back(new ListNode(head->val));
                    head = head->next;
                }
                else
                {
                    res.push_back(nullptr);
                }
            }
        }
        else
        {
            int len = sz / k;
            int xtra = sz % k;
            ListNode *nexxt = NULL;
            for (int i = 0; i < k; i++)
            {
                ListNode *tmp;
                nexxt == NULL ? tmp = head : tmp = nexxt;
                res.push_back(tmp);
                int j = 1;
                while (j < len)
                {
                    tmp = tmp->next;
                    j++;
                }
                if (xtra > 0)
                {
                    tmp = tmp->next;
                    xtra--;
                }
                nexxt = tmp->next;
                tmp->next = nullptr;
            }
        }
        return res;
    }
};