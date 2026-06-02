class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int ans = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        for (int i = 0; i < n; i++) {
            int landFinish = landStartTime[i] + landDuration[i];
            for (int j = 0; j < m; j++) {
                int waterStart = max(landFinish, waterStartTime[j]);
                int finalFinish = waterStart + waterDuration[j];
                ans = min(ans, finalFinish);
            }
        }
        for (int i = 0; i < m; i++) {
            int waterFinish = waterStartTime[i] + waterDuration[i];
            for (int j = 0; j < n; j++) {
                int landStart = max(waterFinish, landStartTime[j]);
                int finalFinish = landStart + landDuration[j];
                ans = min(ans, finalFinish);
            }
        }

        return ans;
    }
};