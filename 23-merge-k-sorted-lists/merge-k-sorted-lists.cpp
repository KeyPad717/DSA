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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, 
                        greater<pair<int,ListNode*>>> minHeap;
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        for(int i=0;i<lists.size();i++){
            ListNode* temp=lists[i];
            if(temp==nullptr)   continue;
            minHeap.push({temp->val, temp});
        }
        while(minHeap.size()){
            int val1=minHeap.top().first;
            ListNode* temp=minHeap.top().second;
            minHeap.pop();
            ListNode* newNode=new ListNode(val1);
            tail->next=newNode;
            tail=tail->next;
            if(temp->next){
                temp=temp->next;
                minHeap.push({temp->val,temp});
            }  
        }
        return dummy->next;
    }
};