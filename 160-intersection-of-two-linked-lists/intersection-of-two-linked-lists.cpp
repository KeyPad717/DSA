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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        int lenA=1, lenB=1, diff;
        while(tempA){
            lenA++;
            tempA=tempA->next;
        }
        while(tempB){
            lenB++;
            tempB=tempB->next;
        }
        tempA=headA;
        tempB=headB;
        if(lenA==lenB){
            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempA;
        }
        else if(lenA>lenB){
            while(lenA!=lenB){
                lenA--;
                tempA=tempA->next;
            }
            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempA;
        }
        //else part
        while(lenA!=lenB){
            lenB--;
            tempB=tempB->next;
        }
        while(tempA!=tempB){
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;
    }
};