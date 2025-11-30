class Solution {
public:
    int maxDistinct(string s) {
        vector<bool> used(256, false);
        int count = 0;

        for (char c : s) {
            if (!used[c]) {
                used[c] = true;
                count++;
            }
        }
        return count;
    }
};