class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left=*max_element(weights.begin(), weights.end()), right=accumulate(weights.begin(), weights.end(),0), n=weights.size();
        while(left<=right){
            int mid=left+(right-left)/2, minWeight=0, day=1;
            //cout<<"a "<<left<<" "<<mid<<" "<<right<<endl;
            for(int i=0;i<n;i++){
                if(minWeight+weights[i]<=mid){
                    minWeight+=weights[i];
                }
                else if(minWeight+weights[i]>mid){
                    day++;
                    minWeight=weights[i];
                }
               // cout<<weights[i]<<" "<<minWeight<<" "<<day<<" "<<days<<endl;
            }
            //cout<<day<<endl;
            //cout<<left<<" "<<mid<<" "<<right<<" "<<day<<" "<<days<<endl;
            if(day<=days)    right=mid-1;
            else            left=mid+1;
        }
        return left;
    }
};