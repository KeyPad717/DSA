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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2)   return list1;
        if(!list1)  return list2;
        if(!list2)  return list1;
        ListNode* dummy = new ListNode();
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* temp3=dummy;
        while(temp1 && temp2){
            if(temp1->val == temp2->val){
                ListNode* x=temp1;
                ListNode* y=temp2;
                temp1=temp1->next;
                temp2=temp2->next;
                temp3->next=x;
                x->next=y;
                y->next=nullptr;
                temp3=y;
            }
            else if(temp1->val < temp2->val){
                temp3->next=temp1;
                ListNode* x=temp1;
                temp1=temp1->next;
                x->next=nullptr;
                temp3=x;
            }
            else{
                temp3->next=temp2;
                ListNode* x=temp2;
                temp2=temp2->next;
                x->next=nullptr;
                temp3=x;
            }
        }
        while(temp1){
            temp3->next=temp1;
            temp3=temp3->next;
            temp1=temp1->next;
        }
        while(temp2){
            temp3->next=temp2;
            temp3=temp3->next;
            temp2=temp2->next;
        }
        return dummy->next;
    }
};