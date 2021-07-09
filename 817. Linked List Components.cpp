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
    int numComponents(ListNode *head, vector<int> &nums)
    {
        unordered_set<int> subset;
        for (auto it : nums)
            subset.insert(it);
        int cnt = 0;
        int chain = 0;
        while (head != NULL)
        {
            if (subset.find(head->val) != subset.end())
            {
                if (chain == 0)
                {
                    cnt++;
                    chain++;
                }
                else
                {
                    chain++;
                }
            }
            else
            {
                chain = 0;
            }
            head = head->next;
        }
        return cnt;
    }
};