class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0,count=0,maxi=0,f=0;
        if(k==0){
            for(int i=1;i<n;i++){
                if(nums[i]==1){
                    if(nums[i-1]==nums[i]){
                        count++;
                        maxi=max(maxi,count);
                    }
                }
                else{
                    if(nums[i-1]==1){
                        count++;
                        maxi=max(maxi,count);
                    }
                    count=0;
                }
            }
            if(nums[n-1]==1)    maxi++;
            return maxi;
        }
        while(j<n){
            if(nums[j]==0){
                while(count<(k+1) && j<n){
                    if(nums[j]==0) count++;
                    if(j==n-1){
                        if(count>=k)    break;
                        else{
                            maxi=max(maxi,j-i+1);
                            f++;
                            break;
                        }
                    }
                    if(count==(k+1))    break;
                    j++;
                }
                if(f!=0)    break;
                if(count>k){
                    j=j-1;
                    count=k;
                } 
                cout<<i<<" "<<nums[i]<<" "<<j<<" "<<nums[j]<<endl;
                maxi=max(maxi,j-i+1);

                while(count==k && j<n){
                    if(nums[i]==0){
                        i++;
                        break;
                    }
                    i++;
                }
                j=i;
                count=0;
            }
            else    j++;
        }
        return maxi;
    }
};