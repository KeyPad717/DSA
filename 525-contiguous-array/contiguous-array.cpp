class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(), len=0, sum=0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            if(nums[i]==0)  nums[i]=-1;
        }
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==0){
                len=max(len,i+1);
            }
            int rem=sum;
            if(mp.find(rem)!=mp.end()){
                len=max(len,i-mp[rem]);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        return len;
    }
};