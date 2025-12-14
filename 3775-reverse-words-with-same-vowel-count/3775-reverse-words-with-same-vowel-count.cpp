class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), i = 0;
        string ans = "", first = "";

        while (i < n && s[i] == ' ') {
            i++;
        }
        while (i < n && s[i] != ' ') {
            first += s[i++];
        }

        int target = 0;
        for (char c : first)
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                target++;
            }
        ans += first;

        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;
            if (i >= n)
                break;

            string word = "";
            while (i < n && s[i] != ' ')
                word += s[i++];

            int cnt = 0;
            for (char c : word)
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    cnt++;

            if (cnt == target)
                reverse(word.begin(), word.end());
            ans += " " + word;
        }
        return ans;
    }
};
