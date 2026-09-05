class Solution {
public:
    int calGCD(int a, int b){
        return gcd(a,b);
    }
    int maxValidSplits(vector<int>& nums) {
        vector<int> temp(nums.begin(),nums.end());
        int maxi=0;
        for(int j=0;j<nums.size();j++){
            temp.erase(temp.begin()+j);
            int n=temp.size();
            vector<int> prefGCD(n,-1), suffGCD(n,-1);
            prefGCD[0]=temp[0];
            suffGCD[n-1]=temp[n-1];
            for(int i=1;i<n-1;i++){
                prefGCD[i]=calGCD(temp[i],prefGCD[i-1]);
            }
            for(int i=n-2;i>=1;i--){
                suffGCD[i]=calGCD(temp[i],suffGCD[i+1]);
            }
            int cnt=0;
            for(int i=0;i<n-1;i++){
                if(prefGCD[i]==suffGCD[i+1])    cnt++;
            }
            maxi=max(maxi,cnt);
            temp.insert(temp.begin()+j,nums[j]);   
        }
        int n=nums.size();
        vector<int> prefGCD(n,-1), suffGCD(n,-1);
        prefGCD[0]=nums[0];
        suffGCD[n-1]=nums[n-1];
        for(int i=1;i<n-1;i++){
            prefGCD[i]=calGCD(nums[i],prefGCD[i-1]);
        }
        for(int i=n-2;i>=1;i--){
            suffGCD[i]=calGCD(nums[i],suffGCD[i+1]);
        }
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(prefGCD[i]==suffGCD[i+1]){
                cnt++;
            }    
        }
        maxi=max(maxi,cnt);
        return maxi;
    }
};