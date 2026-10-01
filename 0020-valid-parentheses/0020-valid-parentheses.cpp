class Solution {
public:
    bool isValid(string s) {
        string st = "";
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push_back(c);
            } else {
                if (st.empty())
                    return false;

                if (c == ')' && st.back() == '(')
                    st.pop_back();
                else if (c == '}' && st.back() == '{')
                    st.pop_back();
                else if (c == ']' && st.back() == '[')
                    st.pop_back();
                else
                    return false;
            }
        }
        return st.empty();
    }
};