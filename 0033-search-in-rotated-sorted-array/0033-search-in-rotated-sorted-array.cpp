class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // return if target is found at mid
            if (nums[mid] == target) {
                return mid;
            }

            // check if left half is sorted
            if (nums[mid] >= nums[left]) {
                // check if target lies here
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            // or check if right half is sorted
            if (nums[mid] <= nums[right]) {
                // check if target lies here
                if (nums[mid] <= target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};