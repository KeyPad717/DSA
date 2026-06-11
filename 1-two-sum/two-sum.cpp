class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> idx(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), 
            [&](int a, int b){
                return nums[a] < nums[b];
            });

        auto left = idx.begin();
        auto right = idx.end() - 1;
        while (left != right) {
            if (nums[*left] + nums[*right] == target)
                return {*left, *right};
            else if (nums[*left] + nums[*right] > target)
                right -= 1;
            else
                left += 1;
        }
        return {*left, *right};
    }
};