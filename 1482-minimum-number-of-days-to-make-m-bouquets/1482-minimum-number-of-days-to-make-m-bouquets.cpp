class Solution {
public:
    int possible(vector<int>& bloomDay, int day, int m, int k) {
        int cnt = 0;
        int bouquets = 0;
        int n = bloomDay.size();

        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                bouquets += cnt / k;
                cnt = 0;
            }
        }
        bouquets += cnt / k;

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long flowers = 1LL * m * k;
        int n = bloomDay.size();

        if (flowers > n) {
            return -1;
        }

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini, high = maxi;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (possible(bloomDay, mid, m, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
