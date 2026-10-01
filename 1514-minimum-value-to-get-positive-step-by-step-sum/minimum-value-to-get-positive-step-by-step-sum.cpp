class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum=0, mini=INT_MAX;
        for(int x:nums){
            sum+=x;
            mini=min(mini,sum);
            cout<<sum<<" "<<mini<<" "<<x<<endl;
        }
        if(mini>=1) return 1;
        return abs(mini)+1;
    }
};