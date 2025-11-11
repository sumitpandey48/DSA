class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            int cnt = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] == nums[i]) {
                    cnt++;
                    if (cnt == 3) {
                        int d = 2 * (j - i);
                        mini = min(mini, d);
                        break;
                    }
                }
            }
        }
        if (mini == INT_MAX) {
            return -1;
        }
        return mini;
    }
};