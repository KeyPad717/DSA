class Solution {
public:
    long long minEnergy(int n1, int brightness1, vector<vector<int>>& intervals) {
        long long n=n1;
        long long brightness=brightness1;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=res[res.size()-1][1]){
                res[res.size()-1][1]=max(intervals[i][1], res[res.size()-1][1]);
            }
            else{
                res.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        // for(long long i=0;i<intervals.size();i++){
        //     cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        // }
        long long bulb=0, len=0;
        while(len<brightness){
            bulb++;
            len+=3;
        }
        long long ans=0;
        for(long long i=0;i<res.size();i++){
            ans+=abs(res[i][1]-res[i][0])+1;
        }
        return ans*bulb;
    }
};