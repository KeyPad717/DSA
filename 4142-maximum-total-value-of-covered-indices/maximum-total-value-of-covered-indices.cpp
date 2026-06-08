class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        long long ans=0, l=0,r=0, n=nums.size();
        while(l<n-1 && r<n){
            r=l+1;
            if(s[l]=='0' && s[r]=='0'){
                l++;
                continue;
            }
            else if(s[l]=='1'){
                l++;
                continue;
            }
            else{
                long long f=0, idx, mini=INT_MAX;
                while(r<n && s[r]!='0'){
                    //cout<<l<<" "<<r<<" "<<mini<<" "<<idx<<endl;
                    if(nums[r]<mini){
                        mini=nums[r];
                        idx=r;
                        r++;
                    }
                    else    r++;
                }
                if(nums[l]>mini){
                    s[l]='1';
                    s[idx]='0';
                }
                l=r;
            }
        }
        for(long long i=0;i<n;i++){
            if(s[i]=='1')   ans+=nums[i];
        }
        return ans;
    }
};