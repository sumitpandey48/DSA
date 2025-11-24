class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> st(arr.begin(), arr.end());

        int cntMiss = 0;
        int num = 1;

        while (cntMiss < k) {
            if (st.find(num) == st.end()) {
                cntMiss++;
                if (cntMiss == k) {
                    return num;
                }
            }
            num++;
        }
        return num;
    }
};
