class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                nums[i] = nums[i] * (-1);
            }
        }
        sort(nums.begin(), nums.end());
        vector<int> a(n);
        int even = 0, odd = 1;

        for (int i = n / 2; i < n; i++) {
            if (even < n) {
                a[even] = nums[i];
                even += 2;
            }
        }
        for (int i = 0; i < n / 2; i++) {
            if (odd < n) {
                a[odd] = nums[i];
                odd += 2;
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long sq = (long long)a[i] * (long long)a[i];
            if (i % 2 == 0) {
                ans += sq;
            } else {
                ans -= sq;
            }
        }
        return ans;
    }
};