class Solution {
public:
    int findmax(vector<int>& piles) {
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }
    long long findHours(vector<int>& piles, int hourly) {
        long long totalH = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalH += ceil((double)piles[i] / (double)hourly);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = findmax(piles);
        while (left <= right) {
            int mid = (left + right) / 2;
            long long totalH = findHours(piles, mid);
            if (totalH <= h) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};