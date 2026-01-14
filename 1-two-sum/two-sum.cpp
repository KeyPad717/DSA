class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //better approach
        map<int,int> mp;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            int p=target - nums[i];
            auto it = mp.find(p);
            if(it!=mp.end()){
                v.push_back(i);
                v.push_back(it->second);
                break;
            }
            mp[nums[i]]=i;
        }
        return(v);
    }
};