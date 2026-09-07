class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(auto x:mp){
            int f=0;
            for(int i=0;i<x.second.size()-1;i++){
                if(((x.second[i])+1) != (x.second[i+1]))    f++;
            }
            if(f==0)    cnt++;
        }
        return cnt;
    }
};