class Solution {
public:
    int findIndex(vector<int>& nums, int target, bool first) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                ans = mid;
                if (first) high = mid - 1;  // search left half
                else low = mid + 1;         // search right half
            } 
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return { findIndex(nums, target, true), findIndex(nums, target, false) };
    }
};
