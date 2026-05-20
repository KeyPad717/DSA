class Solution {
public:
    
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int n = bloomDay.size();

        int flowers = 0;
        int bouquets = 0;

        for (int i = 0; i < n; i++) {

            if (bloomDay[i] <= day) {
                flowers++;
            } 
            else {
                flowers = 0;
            }

            if (flowers == k) {
                bouquets++;
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long need = 1LL * m * k;

        if (need > bloomDay.size()) {
            return -1;
        }

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (canMake(bloomDay, m, k, mid)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};