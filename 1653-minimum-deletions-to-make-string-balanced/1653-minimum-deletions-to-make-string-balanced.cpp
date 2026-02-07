class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int cntA = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                cntA++;
            }
        }
        int mini = min(cntA, n - cntA);
        int cntB = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == 'a') {
                cntA--;
            } else {
                cntB++;
            }
            mini = min(mini, cntA + cntB);
        }
        return mini;
    }
};