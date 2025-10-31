class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = 1, maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            left *= nums[i];
            right *= nums[n - 1 - i];
            maxi = max({maxi, left, right});

            if (left == 0)
                left = 1;
            if (right == 0)
                right = 1;
        }
        return maxi;
    }
};