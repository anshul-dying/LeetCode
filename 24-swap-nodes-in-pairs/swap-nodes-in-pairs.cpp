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
    ListNode* swapPairs(ListNode* head) 
    {
        //Create dummy Node which next value will be pointing to Head of modified list
        ListNode* dummy = new ListNode(0);
        dummy->next = head;   
        ListNode* prev = dummy;

        while(prev->next != nullptr && prev->next->next != nullptr)
        {
            ListNode* curr = prev->next;
            ListNode* next = prev->next->next;

            //Swap curr and next
            curr->next = next->next;
            next->next = curr;
            prev->next = next;

            prev = curr;
        }

        ListNode* newHead = dummy->next;    
        delete dummy;
        return newHead;
    }
};