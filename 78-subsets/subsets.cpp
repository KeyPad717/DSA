class Solution {
public:

    void helper(int index,
                vector<int>& nums,
                vector<int>& current,
                vector<vector<int>>& result) {

        // Base case:
        // One subset formed.
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }

        // Exclude current element
        helper(index + 1, nums, current, result);

        // Include current element
        current.push_back(nums[index]);
        helper(index + 1, nums, current, result);
        current.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> current;

        helper(0, nums, current, result);

        return result;
    }
};