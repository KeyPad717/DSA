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
        for(int i=1;i<=numRows;i++){
            vector<int> temp;
            for(int j=1;j<=i;j++){
                temp.push_back(value(i,j));
            }
            res.push_back(temp);
        }
        return res;
    }
};