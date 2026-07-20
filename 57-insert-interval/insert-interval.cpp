class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int a=intervals[0][0], b=intervals[0][1];
        res.push_back({a,b});
        for(int i=1;i<intervals.size();i++){
            int sz=res.size()-1;
            a=res[sz][0], b=res[sz][1];
            int c=intervals[i][0], d=intervals[i][1];
            if(c<=b){
                res[sz][1]=max(b,d);
            }
            else{
                res.push_back({c,d});
            }
        }
        return res;
    }
};