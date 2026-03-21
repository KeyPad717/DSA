class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long n=nums.size();
        long long l=0,r=0,sum=0,maxi=1;
        while(r<n){
            sum+=nums[r];
            while((r-l+1)*nums[r]>sum+k){
                //cout<<sum<<endl;
                sum-=nums[l];
                l++;
            }
            maxi=max(maxi,(r-l+1));
            r++;
        }
        return maxi;
    }
};