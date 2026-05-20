class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size(), maxi=piles[0], ans=INT_MAX;
        for(int i=1;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        int left=1, right=maxi;
        while(left<=right){
            int mid=left+(right-left)/2;
            long long sum=0LL;
            for(int i=0;i<n;i++){
                if(piles[i]<mid)    sum+=1;
                else if(piles[i]%mid==0)    sum+=piles[i]/(mid);
                else                sum+=(piles[i])/(mid)+1;
                // cout<<left<<" "<<mid<<" "<<right<<" "<<piles[i]<<" "<<mid<<" "<<(piles[i])/(mid)<<" "<<sum<<endl;
            }
            if(sum>h)  left=mid+1;
            else{
                ans=min(mid,ans);
                right=mid-1;
            }
        }
        return ans;
    }
};