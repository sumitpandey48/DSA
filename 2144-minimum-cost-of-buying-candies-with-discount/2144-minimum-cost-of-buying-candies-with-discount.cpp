class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end());
        int cst = 0, cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (cnt < 2) {
                cst += cost[i];
                cnt++;
            } else {
                cnt = 0;
            }
        }
        return cst;
    }
};