class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (char ch : s) {
            string rev = "";
            if (ch == ')') {
                while (st.top() != '(') {
                    rev += st.top();
                    st.pop();
                }
                st.pop();
                for (char c : rev) {
                    st.push(c);
                }
            } else {
                st.push(ch);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};