class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        for(auto x:mp){
            if(x.second>(nums.size()/2))   return x.first;
        }
        return -1;
    }
};