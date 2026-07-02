class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mp;
        int ele;
        for(int x:nums){
            mp[x]++;
        }
        for(auto x:mp){
            if(x.second==1){
                ele=x.first;
            }
        }
        return ele;
    }
};