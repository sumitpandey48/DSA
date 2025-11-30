class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int mini = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            if (mpp.find(a) != mpp.end()) {
                mini = min(mini, i - mpp[a]);
            }
            long long r = 0;
            int b = a;
            while (b > 0) {
                r = r * 10 + b % 10;
                b /= 10;
            }
            mpp[r] = i;
        }
        if (mini == INT_MAX) {
            return -1;
        }
        return mini;
    }
};