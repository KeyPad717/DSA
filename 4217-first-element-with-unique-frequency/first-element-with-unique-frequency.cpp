class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n=nums.size(),count=0;
        unordered_map<int,int> mp,mp1;
        vector<int> v,v1;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto &p:mp){
            mp1[p.second]++;
        }
        for(auto &p:nums){
            if(mp1[mp[p]]==1){
                return p;
            }
        }
        return -1;
    }
};