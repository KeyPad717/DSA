class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        int n=nums.size();
        int ind=0,flag=0;
        for(int i=n-1;i>=0;i--){
            mp[nums[i]]++;
            if(mp[nums[i]]>=2){
                flag++;
                ind=i;
                break;
            }
        }
        if(flag==0)   return 0;
        return ((ind/3)+1);
    }
};