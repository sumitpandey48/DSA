class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0)
                nums[i] *= -1;
        }
        long long mini = INT_MAX;
        int minindex = 0;
        int m = 100000;
        for (int i = 0; i < n; i++) {
            if (nums[i] < mini) {
                mini = nums[i];
                minindex = i;
            }
        }
        nums[minindex] = m;
        sort(nums.begin(), nums.end());
        long long prod = 1LL * nums[n - 1] * nums[n - 2] * nums[n - 3];
        return prod;
    }
};