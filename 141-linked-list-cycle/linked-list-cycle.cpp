/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)   return false;
        if(head->next==nullptr) return false;
        ListNode* slow=head->next;
        ListNode* fast=head->next->next;
        if(slow==fast)  return true;
        while(fast && fast->next && slow!=fast){
            if(slow==fast)  return true;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow==fast)  return true;
        return false;
    }
};