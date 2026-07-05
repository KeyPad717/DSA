class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())    return 0;
        map<int,int> mp;
        int len=1, maxi=1, prev, f=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto x:mp){
           if(f==0){
            f++;
            prev=x.first;
            continue;
           } 
           if(x.first==prev)    continue;
           else if(x.first==prev+1){
            len++;
           }
           else{
            len=1;
           }
           prev=x.first;
           maxi=max(maxi,len);
        }
        maxi=max(maxi,len);
        return maxi;
    }
};