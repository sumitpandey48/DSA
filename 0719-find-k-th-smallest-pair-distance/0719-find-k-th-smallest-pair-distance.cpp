class Solution {
public:
    int cntPairs(vector<int>& nums, int mid) {
        int n = nums.size();
        int cnt = 0, j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && nums[j] - nums[i] <= mid) {
                j++;
            }
            cnt += j - i - 1;
        }
        return cnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = nums[n - 1] - nums[0];

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int count = cntPairs(nums, mid);
            if (count >= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};