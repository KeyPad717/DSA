#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(int x:nums){
            mp[x]++;
        }
        for(auto x:mp){
            minHeap.push({x.second,-x.first});
        }
        while(minHeap.size()){
            int freq=minHeap.top().first;
            int ele=minHeap.top().second;
            minHeap.pop();
            while(freq!=0) {
                freq--;
                res.push_back(-ele);
            }
        }
        return res;
    }
};