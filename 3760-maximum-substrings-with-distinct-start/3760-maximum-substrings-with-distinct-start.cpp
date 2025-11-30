class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> st;
        int cnt = 0;
        for (char c : s) {
            if (st.find(c) == st.end()) {
                cnt++;
                st.insert(c);
            }
        }
        return cnt;
    }
};