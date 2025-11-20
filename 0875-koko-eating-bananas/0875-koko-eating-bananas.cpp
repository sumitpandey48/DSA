class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);

        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalHours = findHours(piles, mid);

            if (totalHours <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    long long findHours(vector<int>& piles, int hourly) {
        long long totalHours = 0;
        int n = piles.size();

        for (int i = 0; i < n; i++) {
            totalHours += ceil((double)piles[i] / (double)hourly);
        }
        return totalHours;
    }

    int findMax(vector<int>& piles) {
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }
};
