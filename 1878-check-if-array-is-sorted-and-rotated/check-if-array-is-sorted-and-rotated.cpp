class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size(),f=0,pos=0;
        for(int i=1;i<n;i++){
            if(nums[i]>=nums[i-1])   f++;
            else    pos=i;
        }
        if(n-1==f)  return true;
        f=0;
        int i=pos,j=-1;
        while(i!=j){
            if(i==pos)  j=i;
            if(i==n-1){
                if(nums[i]<=nums[0]){
                    f++;
                    i=0;
                    continue;
                }
                else break;
            }
            if(nums[i]<=nums[i+1]){
                f++;
                i++;
            }
            else break;
        }
        if(f==n-1)  return true;
        return false;
    }
};