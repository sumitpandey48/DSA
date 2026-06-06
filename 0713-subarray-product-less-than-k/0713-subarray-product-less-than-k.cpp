class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int curProd = 1;
            for (int j = i; j < n; j++) {
                curProd *= nums[j];
                if (curProd >= k)
                    break;
                cnt++;
            }
        }
        return cnt;
    }
};