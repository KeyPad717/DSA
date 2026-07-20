class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>> temp;
        for(int i=0;i<intervals.size();i++){
            temp.push_back({intervals[i][1],intervals[i][0]});
        }
        sort(temp.begin(),temp.end());
        int cnt=0, finTime=temp[0].first;
        for(int i=1;i<temp.size();i++){
            if(temp[i].second>=finTime){
                finTime=temp[i].first;
            }
            else    cnt++;
        }
        return cnt;
    }
};