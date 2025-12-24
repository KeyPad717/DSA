class Solution {
public:
    int solver(vector<int>& arr, int k, int n, vector<vector<int>> &dp) {
        if (n == 0) return k == 0;
        if (dp[n][k] != -1) return dp[n][k];

        int count = solver(arr, k, n - 1, dp);

        if (arr[n - 1] <= k) {
            count += solver(arr, k - arr[n - 1], n - 1, dp);
        }

        return dp[n][k] = count;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int range = accumulate(nums.begin(), nums.end(), 0);

        if (target < -range || target > range) return 0;
        if ((target + range) % 2 != 0) return 0;

        int sum = (target + range) / 2;
        if (sum < 0) return 0;   

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return solver(nums, sum, n, dp);
    }
};
