class Solution {
public:
    int findmax(vector<int>& weights) {
        int maxi = INT_MIN;
        for (int i = 0; i < weights.size(); i++) {
            maxi = max(maxi, weights[i]);
        }
        return maxi;
    }

    int findDays(vector<int>& weights, int cap) {
        int days = 1, load = 0;
        int n = weights.size();

        for (int i = 0; i < n; i++) {
            if (load + weights[i] > cap) {
                days++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int d) {
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
        }

        int low = findmax(weights), high = sum;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (findDays(weights, mid) <= d) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
