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
// ListNode* revList(ListNode* &head)
// {
//     ListNode* prev = nullptr;
//     ListNode* curr = head;
//     ListNode* next = nullptr;

//     while(curr != nullptr)
//     {
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }

//     return prev;
// }

typedef ListNode Node;
class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        // int numOfNodes = 0;
        // ListNode* temp = head;
        // while(temp != nullptr)
        // {
        //     temp=temp->next;
        //     numOfNodes++;
        // }
        // int k = numOfNodes-n+1;

        // //First Element
        // if(k == 1)
        // {
        //     Node* temp1 = head;
        //     head = head->next;

        //     delete temp1;

        //     return head;
        // }
        // //Last element
        // if(k == numOfNodes)
        // {
        //     Node* prev = nullptr;
        //     Node* curr = head;
        //     while(curr->next != nullptr)
        //     {
        //         prev = curr;
        //         curr = curr->next;
        //     }

        //     prev->next = nullptr;
        //     delete curr;
        //     return head;
        // }

        // //Somewhere between
        // int num = 1;
        // Node* prev = nullptr;
        // Node* curr = head;
        // while(num != k)
        // {
        //     prev = curr;
        //     curr = curr->next;
        //     num++;
        // }
        // prev->next = curr->next;
        // delete curr;
        // return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        Node* fast = dummy;
        Node* slow = dummy;

        for(int i = 0; i <= n; i++)
        {
            if (fast == nullptr) 
            { // List has fewer than n+1 nodes
            return head;
            }
            fast = fast->next;
        }

        while(fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        Node* toDelete = slow->next;
        slow->next = slow->next->next;

        delete toDelete;
        Node* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};