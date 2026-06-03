class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst,
                           vector<int>& wd) {
        int n = lst.size();
        int m = wst.size();
        int l = INT_MAX;
        int w = INT_MAX;
        int lw = INT_MAX;
        int wl = INT_MAX;
        for (int i = 0; i < n; i++) {
            l = min(l, lst[i] + ld[i]);
        }
        for (int i = 0; i < m; i++) {
            w = min(w, wst[i] + wd[i]);
            lw = min(lw, max(wst[i], l) + wd[i]);
        }
        for (int i = 0; i < n; i++) {
            wl = min(wl, max(lst[i], w) + ld[i]);
        }
        return min(lw, wl);
    }
};