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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> stack_l1, stack_l2;
        while (l1 != NULL)
        {
            stack_l1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            stack_l2.push(l2->val);
            l2 = l2->next;
        }
        int x = stack_l1.top();
        int y = stack_l2.top();
        stack_l1.pop();
        stack_l2.pop();
        ListNode *prev = new ListNode((x + y) % 10);
        int carry = (x + y) / 10;
        while (!stack_l1.empty() && !stack_l2.empty())
        {
            int num = stack_l1.top() + stack_l2.top() + carry;
            carry = num / 10;
            num %= 10;
            ListNode *tmp = new ListNode(num);
            tmp->next = prev;
            prev = tmp;
            stack_l1.pop();
            stack_l2.pop();
        }
        while (!stack_l1.empty())
        {
            int num = stack_l1.top() + carry;
            carry = num / 10;
            num %= 10;
            ListNode *tmp = new ListNode(num);
            tmp->next = prev;
            prev = tmp;
            stack_l1.pop();
        }
        while (!stack_l2.empty())
        {
            int num = stack_l2.top() + carry;
            carry = num / 10;
            num %= 10;
            ListNode *tmp = new ListNode(num);
            tmp->next = prev;
            prev = tmp;
            stack_l2.pop();
        }
        ListNode *res;
        if (carry)
        {
            res = new ListNode(carry);
            res->next = prev;
        }
        else
        {
            res = prev;
        }
        return res;
    }
};