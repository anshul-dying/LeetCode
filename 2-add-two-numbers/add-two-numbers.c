struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL; 
    struct ListNode* temp = NULL; 
    struct ListNode* curr = NULL; 
    int carry = 0; 

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry; 
        if (l1 != NULL) {
            sum += l1->val; 
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val; 
            l2 = l2->next;
        }

        carry = sum / 10; 
        sum = sum % 10; 

        temp = (struct ListNode*)malloc(sizeof(struct ListNode)); 
        temp->val = sum;
        temp->next = NULL;

        if (head == NULL) {
            head = temp; 
            curr = head; 
        } else {
            curr->next = temp; 
            curr = temp; 
        }
    }

    return head;
}