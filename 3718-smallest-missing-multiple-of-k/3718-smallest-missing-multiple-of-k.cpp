class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        for (int i = 1; i <= INT_MAX; i++) {
            int cnt = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == (k * i))
                    cnt++;
            }
            if (cnt == 0)
                return k * i;
        }
        return -1;
    }
};