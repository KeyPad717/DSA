class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(), count=1, ele=nums[0],idx=0,f=0;
        if(n==1)    return 1;
        for(int i=1;i<n;i++){
            if(nums[i]==-101)   {
                idx=i;
                break;
            }
            if(ele!=nums[i]){
                ele=nums[i];
            }
            else{
                f++;
                int x=nums[i];
                nums.erase(nums.begin()+i);
                nums.push_back(-101);
                i--;
            }
        }
        if(f==0)    return n;
        return idx;
    }
};