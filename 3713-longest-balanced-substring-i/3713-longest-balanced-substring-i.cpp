class Solution {
public:
    bool isBalanced(vector<int>& freq) {
        int v = 0;
        for (int k = 0; k < 26; k++) {
            if (freq[k] > 0) {
                if (v == 0) {
                    v = freq[k];
                } else if (freq[k] != v)
                    return false;
            }
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                if (isBalanced(freq)) {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }
        return maxi;
    }
};
