class Solution {
public:
    ListNode* revHelper(ListNode* head){
        if(!head || !head->next)    return head;
        ListNode* newHead=revHelper(head->next);
        ListNode* front=head->next;
        head->next=nullptr;
        front->next=head;
        return newHead;
    }
    ListNode* reverseList(ListNode* head) {//recursive
        return revHelper(head);
    }
};