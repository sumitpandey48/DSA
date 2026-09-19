class Solution {
public:
    int dp[201][10001];
    bool solve(vector<int>& nums, int n, int sum) {
        if (sum == 0)
            return true;
        if (n == 0)
            return false;

        if (dp[n][sum] != -1)
            return dp[n][sum];

        if (nums[n - 1] <= sum) {
            return dp[n][sum] = solve(nums, n - 1, sum - nums[n - 1]) ||
                                solve(nums, n - 1, sum);
        } else {
            return dp[n][sum] = solve(nums, n - 1, sum);
        }
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int x : nums) {
            total += x;
        }
        if (total % 2 != 0) {
            return false;
        }
        memset(dp, -1, sizeof(dp));
        return solve(nums, nums.size(), total / 2);
    }
};