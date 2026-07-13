class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto x:mp){
            if(x.second>ceil(n/3)){
                res.push_back(x.first);
            }
        }
        return res;
    }
};