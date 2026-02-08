class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size(),count=0;
        double sum=0,avg=0;
        for(int i=1;i<n;i++){
            sum+=nums[i];
        }
        //cout<<sum;
        for(int i=0;i<n-1;i++){
            if(i==0){
                avg=sum/(n-i-1);
                if(nums[i]>avg) count++;
                continue;
            }
            // if(i==n-2){
            //     avg=nums[n-1];
            //     if(nums[i]>avg) count++;
            //     break;
            // }
            sum-=nums[i];
            avg=sum/(n-i-1);
            if(nums[i]>avg) count++;
        }
        return count;
    }
};