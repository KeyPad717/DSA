class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0,n=nums.size(), maxi=0;
        if(n==1)    return nums[0]==1?1:0;
        while(i<n && j<n){
            while(i<n && nums[i]==0)   i++;
            if(i>=n)    continue;
            j=i+1;
            while(j<n && nums[j]==1)   j++;
            maxi=max(maxi,j-i);
            i=j;
        }
        return maxi;
    }
};