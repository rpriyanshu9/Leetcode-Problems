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
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> res, possible;
        res.push_back(0);
        possible.push_back(head->val);
        head = head->next;
        while (head != NULL)
        {
            if (head->val > possible.back())
            {
                int i = res.size() - 1;
                while (possible.size() != 0 && head->val > possible.back())
                {
                    if (res[i] != 0)
                    {
                        i--;
                        continue;
                    }
                    else
                    {
                        res[i--] = head->val;
                        possible.pop_back();
                    }
                }
                possible.push_back(head->val);
            }
            else
            {
                possible.push_back(head->val);
            }
            res.push_back(0);
            head = head->next;
        }
        return res;
    }
};