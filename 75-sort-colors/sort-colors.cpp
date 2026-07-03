class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0, o=0, t=0, i=0;
        for(int x:nums){
            if(x==0)    z++;
            else if(x==1)   o++;
            else            t++;
        }
        while(z--){
            nums[i]=0;
            i++;
        }
        while(o--){
            nums[i]=1;
            i++;
        }
        while(t--){
            nums[i]=2;
            i++;
        }
    }
};