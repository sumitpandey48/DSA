class Solution {
public:
    int solve(vector<int>& nums, int i, int sum, int target) {
        int n = nums.size();
        if (i == n) {
            if (sum == target) {
                return 1;
            }
            return 0;
        }
        int x = solve(nums, i + 1, sum + nums[i], target);
        int y = solve(nums, i + 1, sum - nums[i], target);

        return x + y;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, 0, target);
    }
};