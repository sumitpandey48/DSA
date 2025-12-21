class Solution {
public:
    string reverseWords(string s) {
        vector<string> w;
        string word = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (!word.empty()) {
                w.push_back(word);
                word = "";
            }
        }
        if (!word.empty()) {
            w.push_back(word);
        }
        reverse(w.begin(), w.end());

        string ans = "";
        for (int i = 0; i < w.size(); i++) {
            ans += w[i];
            if (i < w.size() - 1) {
                ans += " ";
            }
        }
        return ans;
    }
};