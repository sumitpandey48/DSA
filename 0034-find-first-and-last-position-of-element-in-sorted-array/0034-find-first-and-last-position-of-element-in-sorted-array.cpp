class Solution {
public:
    int firstOccurence(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstOccurence(nums, target);
        if (first == n || nums[first] != target) {
            return {-1, -1};
        }
        int last = firstOccurence(nums, target + 1) - 1;
        return {first, last};
    }
};
