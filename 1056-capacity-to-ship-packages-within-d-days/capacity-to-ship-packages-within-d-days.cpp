class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        int n = weights.size();

        while (left <= right) {

            int mid = left + (right - left) / 2;

            int day = 1;
            int load = 0;

            for (int i = 0; i < n; i++) {

                if (load + weights[i] > mid) {
                    day++;
                    load = weights[i];
                }
                else {
                    load += weights[i];
                }
            }

            if (day <= days) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};