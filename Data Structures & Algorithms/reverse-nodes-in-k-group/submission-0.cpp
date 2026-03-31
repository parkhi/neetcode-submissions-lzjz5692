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
    ListNode* reverseList(ListNode* head) {
        ListNode* a = nullptr, *b,*c;

        if(!head || !head->next)
            return head;
        
        b = head;
        c = head->next;

        while( b != nullptr)
        {
            b->next = a;
            a = b;
            b = c;

            if(c)
                c = c->next;
        }

        return a;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* nextList = nullptr , *tail = head, *newHead = nullptr, *prevTail = nullptr;
        ListNode* finalHead = nullptr;
        if(!head || !head->next)
            return head;

        while(tail)
        {
            for(int i=1; i<k ; i++)
            {
             if(tail)
                tail = tail->next;
            }

            if(tail)
            {
                ListNode* temp = tail;
                tail = temp->next;
                temp->next = nullptr;

                newHead = reverseList(head);

                if(!finalHead)
                    finalHead = newHead;
                if(prevTail)
                    prevTail->next = newHead;

                head->next = tail;
                prevTail = head;
                head = head->next;
                tail = head;     
            } 
        } 

        return finalHead;      
    }
};
