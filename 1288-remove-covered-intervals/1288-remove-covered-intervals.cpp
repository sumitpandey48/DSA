class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        auto m = [](vector<int> & a, vector<int> & b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            } else {
                return a[0] < b[0];
            }
        };
        sort(begin(intervals), end(intervals), m);
        ans.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            if (ans.back()[0] <= intervals[i][0] && ans.back()[1] >= intervals[i][1]) {
                continue;
            }
            ans.push_back(intervals[i]);
        }
        return ans.size();
    }
};