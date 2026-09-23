class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0, sum = 0;
        int ans = 0;
        for (int r = 0; r < arr.size(); r++) {
            sum += arr[r];

            if (r - l + 1 == k) {

                if (sum >= (long long)k * threshold) {
                    ans++;
                }
                sum -= arr[l++];
            }
        }
        return ans;
    }
};