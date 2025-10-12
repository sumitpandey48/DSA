class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxSum = 0, maxi = INT_MIN;
        int minSum = 0, mini = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            maxSum += nums[i];
            maxi = max(maxi, maxSum);
            if (maxSum < 0) {
                maxSum = 0;
            }

            minSum += nums[i];
            mini = min(mini, minSum);
            if (minSum > 0) {
                minSum = 0;
            }
            total += nums[i];
        }
        if (maxi < 0)
            return maxi;
        int ans = total - mini;
        return max(maxi, ans);
    }
};