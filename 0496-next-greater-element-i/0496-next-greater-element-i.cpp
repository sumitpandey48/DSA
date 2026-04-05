class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mpp;

        for (int j = 0; j < nums2.size(); j++) {
            int a = nums2[j];
            while (!st.empty() && st.top() < a) {
                mpp[st.top()] = a;
                st.pop();
            }
            st.push(a);
        }
        while (!st.empty()) {
            mpp[st.top()] = -1;
            st.pop();
        }
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};