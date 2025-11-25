class Solution {
public:
    int findmax(vector<int>& nums) {
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

    int countPartitions(vector<int>& nums, int maxSum) {
        int n = nums.size();
        int partitions = 1;
        long long subArraySum = 0;

        for (int i = 0; i < n; i++) {
            if (subArraySum + nums[i] <= maxSum) {
                subArraySum += nums[i];
            } else {
                partitions++;
                subArraySum = nums[i];
            }
        }
        return partitions;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = findmax(nums);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int high = sum;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (countPartitions(nums, mid) <= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};