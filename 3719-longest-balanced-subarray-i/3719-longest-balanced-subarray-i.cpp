class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mpp;
            int e = 0, o = 0;

            for (int j = i; j < n; j++) {
                if (mpp[nums[j]] == 0) {
                    if (nums[j] % 2 == 0)
                        e++;
                    else
                        o++;
                }
                mpp[nums[j]]++;

                if (e == o) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};