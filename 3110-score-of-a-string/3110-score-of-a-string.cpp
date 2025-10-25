class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] > s[i + 1]) {
                score += s[i] - s[i + 1];
            } else {
                score += s[i + 1] - s[i];
            }
        }
        return score;
    }
};