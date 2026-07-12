class Solution {
public:
    long long value(long long row, long long col){
        row--;
        col--;
        long long ans=1;
        for(int i=1;i<=col;i++){
            ans*=row;
            ans/=i;
            row--;
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for(int i=2;i<=numRows;i++){
            vector<int> temp;
            long long ans=1;
            temp.push_back(ans);
            for(int j=1;j<i;j++){
                ans*=(i-j);
                ans/=j;
                temp.push_back(ans);
            }
            res.push_back(temp);
        }
        return res;
    }
};