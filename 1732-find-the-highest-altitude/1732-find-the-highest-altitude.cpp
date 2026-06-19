class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> prefixSum(n);

        prefixSum[0] = gain[0];
        int maxi = max(0,prefixSum[0]);
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + gain[i];
            maxi = max(maxi, prefixSum[i]);
        }
        return maxi; 
    }
};