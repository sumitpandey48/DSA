class Solution {
public:
    int findmax(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

    int SumByD(vector<int>& nums, int div) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += ((nums[i] + div - 1) / div);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if (n > threshold) {
            return -1;
        }
        int low = 1, high = findmax(nums);

        while (low <= high) {
            int mid = (low + high) / 2;
            if (SumByD(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};