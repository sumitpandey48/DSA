class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst,
                           vector<int>& wd) {
        int ans = INT_MAX;
        int n = lst.size();
        int m = wst.size();

        for (int i = 0; i < n; i++) {
            int a = lst[i] + ld[i];
            for (int j = 0; j < m; j++) {
                int b = max(a, wst[j]);
                ans = min(ans, b + wd[j]);
            }
        }
        for (int i = 0; i < m; i++) {
            int c = wst[i] + wd[i];
            for (int j = 0; j < n; j++) {
                int d = max(c, lst[j]);
                ans = min(ans, d + ld[j]);
            }
        }
        return ans;
    }
};