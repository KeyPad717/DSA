class Solution {
public:
    int missingNumber(vector<int>& nums){
        //better approach :- hashing
        //this is the optimal one 

        int sum=0,exp=0,n=nums.size();
        exp = (n*(n+1))/2;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
        }
        return(exp-sum);

        //but it can overflow for large int value, so 
        //XOR method is more optimal than this approach
        
    }
};