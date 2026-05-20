class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int left=1, right = *max_element(piles.begin(), piles.end());;
        while(left<=right){
            int mid=left+(right-left)/2;
            long long sum=0LL;
            for(int i=0;i<n;i++){
                sum += (piles[i] + mid - 1) / mid;
                // if(piles[i]<mid)    sum+=1;
                // else if(piles[i]%mid==0)    sum+=piles[i]/(mid);
                // else                sum+=(piles[i])/(mid)+1;
                //alternative better :- 
            }
            if(sum>h)  left=mid+1;
            else{
                right=mid-1;
            }
        }
        return left;
    }
};