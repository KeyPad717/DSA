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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)    return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* temp1=odd;
        ListNode* temp2=even;
        while(temp1 && temp1->next){
            //cout<<temp1->val<<" "<<temp2->val<<endl;
            if(temp1->next->next==nullptr){
                break;
            }
            temp1->next=temp1->next->next;
            temp1=temp1->next;
            if(temp2->next) {
                temp2->next=temp2->next->next;
                temp2=temp2->next;
            }
            else    {
                temp2->next=nullptr;
                break;
            }
            //cout<<temp1->val<<" "<<temp2->val<<endl;
        }
        temp1->next=even;
        return head;
    }
};