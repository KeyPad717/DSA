class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> maxHeap;
    int k1;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            maxHeap.push(nums[i]);
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        k1=k;
    }
    int add(int val) {
        maxHeap.push(val);
        if(maxHeap.size()>k1)   maxHeap.pop();
        int x=maxHeap.top();
        return x;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */