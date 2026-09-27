class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        long long n=nums.size(), maxi=0;
        for(long long i=0;i<n;i++){
            long long sum=0;
            set<long long> st;
            for(long long j=i;j<n;j++){
                st.insert((((2*nums[j])%k)+k)%k);
                sum+=nums[j];
                if((((sum%k)+k)%k)==0) maxi=max(maxi,j-i+1);
                else{
                    int test=((sum%k)+k)%k;
                    if(st.find(test)!=st.end()){
                        maxi=max(maxi,j-i+1);
                    }
                }
            }
        }
        return maxi;
    }
};