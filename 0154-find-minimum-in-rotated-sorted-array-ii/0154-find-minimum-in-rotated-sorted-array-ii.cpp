class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If mid element is greater than rightmost, min is in the right half
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }

            // If mid element is smaller than rightmost, min is in the left half(including mid)
            else if (nums[mid] < nums[right]) {
                right = mid;
            }
            // If mid equals rightmost, shrink search space
            else {
                right--;
            }
        }
        return nums[left]; // left == right => minimum element
    }
};