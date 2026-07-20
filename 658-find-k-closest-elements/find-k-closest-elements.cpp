class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        priority_queue<pair<int,int>> maxHeap;
        for(int i=0;i<arr.size();i++){
            maxHeap.push({abs(arr[i]-x),arr[i]});
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        while(maxHeap.size()){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};
