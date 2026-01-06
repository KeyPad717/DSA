class Solution {
public:
    bool check(vector<int>& nums) {
        int f=0;
        vector<int> v;
        for(int i=0; i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1]){
                f++;
            }
        }
        if(f==nums.size()-1){
            return(true);
        }
        for(int i=0; i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                for(int j=i+1;j<nums.size();j++){
                    v.push_back(nums[j]);
                    nums.erase(nums.begin()+j);
                    j--;
                }
                break;
            }
        }
        for(int i=0; i<nums.size();i++){
            v.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            i--;
        }
        f=0;
        for(int i=0; i<v.size()-1;i++){
            if(v[i]<=v[i+1]){
                f++;
            }
        }
        if(f==v.size()-1){
            return(true);
        }
        return(false);
    }
};