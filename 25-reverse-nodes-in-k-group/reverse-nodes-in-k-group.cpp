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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {

        //Base case
        if(head == nullptr)
        {
            return nullptr;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        ListNode* check = head;
        for(int i = 0; i < k; i++)
        {
            if(check==nullptr)
            {
                return head;
            }
            check = check->next;
        }

        int count = 0;
        while(curr != nullptr && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(next != nullptr)
            head->next = reverseKGroup(next, k);

        return prev;
    }
};