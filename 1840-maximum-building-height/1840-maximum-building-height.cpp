class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& res) {

        res.push_back({1, 0});
        sort(res.begin(), res.end());
        if (res.back()[0] != n)
            res.push_back({n, n - 1});

        int m = res.size();

        for (int i = 1; i < m; i++) {
            int d = res[i][0] - res[i - 1][0];

            res[i][1] = min(res[i][1], res[i - 1][1] + d);
        }

        for (int i = m - 2; i >= 0; i--) {
            int d = res[i + 1][0] - res[i][0];

            res[i][1] = min(res[i][1], res[i + 1][1] + d);
        }

        int ans = 0;

        for (int i = 1; i < m; i++) {
            int d = res[i][0] - res[i - 1][0];
            int h1 = res[i - 1][1];
            int h2 = res[i][1];
            int x = ((h1 + h2 + d) / 2);
            ans = max(ans, x);
        }

        return ans;
    }
};