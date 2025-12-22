class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<int> L(nums.begin(), nums.begin()+n), R(nums.begin()+n, nums.end());
        vector<vector<int>> ls(n+1), rs(n+1);
        int m = n;
        for(int mask=0; mask<(1<<m); ++mask){
            int k = __builtin_popcount(mask), s = 0;
            for(int i=0;i<m;++i) if(mask>>i & 1) s += L[i];
            ls[k].push_back(s);
        }
        for(int mask=0; mask<(1<<m); ++mask){
            int k = __builtin_popcount(mask), s = 0;
            for(int i=0;i<m;++i) if(mask>>i & 1) s += R[i];
            rs[k].push_back(s);
        }
        for(int k=0;k<=n;++k) sort(rs[k].begin(), rs[k].end());
        int ans = INT_MAX;
        for(int k=0;k<=n;++k){
            auto &A = ls[k];
            auto &B = rs[n-k];
            for(int a : A){
                int target = (total/2) - a;
                auto it = lower_bound(B.begin(), B.end(), target);
                if(it != B.end()){
                    int s1 = a + *it;
                    ans = min(ans, abs(total - 2*s1));
                }
                if(it != B.begin()){
                    int s1 = a + *prev(it);
                    ans = min(ans, abs(total - 2*s1));
                }
            }
        }
        return ans;
    }
};
