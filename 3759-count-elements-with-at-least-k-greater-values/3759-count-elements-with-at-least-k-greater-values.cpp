class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if (k == 0)
            return nums.size();

        sort(nums.begin(), nums.end(), greater<int>());
        int temp = nums[k - 1];
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] < temp) {
                return nums.size() - i;
            }
        }
        return 0;
    }
};
