class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            maxi = max(maxi, x);
            mini = min(mini, x);
        }
        return 1L * k * (maxi - mini);
    }
};