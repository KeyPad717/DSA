class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int,int>> merged;
        merged.push_back({intervals[0][0], intervals[0][1]});
        for(int i=1;i<intervals.size();i++){
            int a=merged.back().first;
            int b=merged.back().second;
            int c=intervals[i][0];
            int d=intervals[i][1];
            //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
            if(c<=a && b<=d){
                //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                merged.back().first=c;
                merged.back().second=d;
            }
            else if(a<=c && d<=b){
                continue;
            }
            else{
                merged.push_back({c,d});
            }
        }
        // for(auto x:merged){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        return merged.size();
    }
};