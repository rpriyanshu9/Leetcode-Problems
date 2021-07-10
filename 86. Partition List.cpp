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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *less_than = new ListNode();
        ListNode *greater_than = new ListNode();
        ListNode *res = less_than, *gtres = greater_than;
        ListNode *temp = head;
        while (temp != NULL)
        {
            if (temp->val < x)
            {
                less_than->next = new ListNode(temp->val);
                less_than = less_than->next;
            }
            else
            {
                greater_than->next = new ListNode(temp->val);
                greater_than = greater_than->next;
            }
            temp = temp->next;
        }
        less_than->next = gtres->next;
        return res->next;
    }
};