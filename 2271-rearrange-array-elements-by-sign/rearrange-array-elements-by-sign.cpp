class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums){
        vector<int> v(nums.size(),0);
        int pos=0, neg=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                v[neg]=nums[i];
                neg+=2;
            }
            else{
                v[pos]=nums[i];
                pos+=2;
            }
        }
        return(v);
    }
};