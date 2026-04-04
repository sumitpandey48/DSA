class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        
        vector<int> left(n), right(n);
        stack<pair<int,int>> sLeft, sRight;

        // Previous Less Element (strictly smaller)
        for(int i = 0; i < n; i++){
            int cnt = 1;
            while(!sLeft.empty() && sLeft.top().first > arr[i]){
                cnt += sLeft.top().second;
                sLeft.pop();
            }
            sLeft.push({arr[i], cnt});
            left[i] = cnt;
        }

        // Next Less Element (less than or equal)
        for(int i = n - 1; i >= 0; i--){
            int cnt = 1;
            while(!sRight.empty() && sRight.top().first >= arr[i]){
                cnt += sRight.top().second;
                sRight.pop();
            }
            sRight.push({arr[i], cnt});
            right[i] = cnt;
        }

        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans = (ans + (long long)arr[i] * left[i] * right[i]) % mod;
        }

        return ans;
    }
};