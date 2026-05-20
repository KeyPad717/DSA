class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long mul=1LL*m*k;
        if(mul>n)   return -1;
        int left=*min_element(bloomDay.begin(),bloomDay.end());
        int right=*max_element(bloomDay.begin(),bloomDay.end());
        while(left<=right){
            int mid=left+(right-left)/2, bou=0, adj=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    adj++;
                    if(adj==k){
                        bou++;
                        adj=0;
                    }
                }
                else{
                    adj=0;
                }
            }
            //cout<<left<<" "<<mid<<" "<<right<<" "<<bou<<" "<<m<<endl;
            if(bou<m){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return left;
    }
};