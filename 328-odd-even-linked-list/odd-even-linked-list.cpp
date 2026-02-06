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
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr) return head;
        ListNode* temp1=head;
        ListNode* temp2=head->next;
        ListNode* oddHead=temp1;
        ListNode* evenHead=temp2;
        while(temp1!=nullptr && temp2!=nullptr && temp2->next!=nullptr && temp1->next!=nullptr){
            temp1->next=temp1->next->next;
            temp2->next=temp2->next->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(temp1->next==nullptr){
            temp2=nullptr; 
            temp1->next=evenHead;
        }
        else{
            temp1->next=evenHead;
        }
        return head;
    }
};