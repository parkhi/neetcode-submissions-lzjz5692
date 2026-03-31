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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode* head = nullptr, *tail = nullptr;

        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;

        while((l1 != nullptr) || (l2 != nullptr))
        {
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;

            if(sum > 9)
            {
                carry = sum / 10;
                sum = sum % 10;
            }
            else
            {
                carry = 0;
            }

            ListNode* a = new ListNode(sum);

            if(!head)
            {
                head = a;
                tail = a;
            }
            else
            {
                tail->next = a;
                tail = tail->next;
            }

            l1 = l1?l1->next:nullptr;
            l2 = l2?l2->next:nullptr;
        }
        if(carry)
        {
            ListNode* a = new ListNode(carry);

            if(!head)
            {
                head = a;
                tail = a;
            }
            else
            {
                tail->next = a;
                tail = tail->next;
            }
        }
        
        return head;
    }
};
