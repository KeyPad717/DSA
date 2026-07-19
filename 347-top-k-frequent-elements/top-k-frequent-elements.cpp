class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        vector<int> res;
        int i=0;
        for(int x:nums){
            mp[x]++;
        } 
        for(auto x:mp){
            //if(minHeap.size())  cout<<"a:"<<minHeap.top().first<<" "<<minHeap.top().second<<endl;
            minHeap.push({x.second,x.first});
            //cout<<"b:"<<minHeap.top().first<<" "<<minHeap.top().second<<endl;
            if(minHeap.size()>k)    minHeap.pop();
            //cout<<"c:"<<minHeap.top().first<<" "<<minHeap.top().second<<endl;
        }
        while(minHeap.size()){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};