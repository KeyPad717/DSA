class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> v;
        int n=nums.size(),f=0,pos=0;
        for(int i=1;i<n;i++){
            if(nums[i]>=nums[i-1])   f++;
            else    pos=i;
        }
        if(n-1==f)  return true;
        for(int i=pos;i<n;i++){
            v.push_back(nums[i]);
        }
        for(int i=0;i<pos;i++){
            v.push_back(nums[i]);
        }
        f=0;
        for(int i=1;i<n;i++){
            if(v[i]>=v[i-1])   f++;
        }
        if(n-1==f)  return true;
        return false;
    }
};