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
    void reorderList(ListNode *head)
    {
        stack<ListNode *> stack_;
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            stack_.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *next_, *created_ = NULL;
        if (fast == NULL)
        {
            next_ = slow;
        }
        else
        {
            next_ = slow->next;
            slow->next = NULL;
            created_ = slow;
        }
        while (!stack_.empty())
        {
            ListNode *curr = stack_.top();
            stack_.pop();
            curr->next = next_;
            next_ = next_->next;
            curr->next->next = created_;
            created_ = curr;
        }
    }
};