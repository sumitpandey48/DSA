class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        for (int i = 0; i <= n - m; i++) {
            int temp = i;
            int j = 0;
            for (j = 0; j < m; j++) {
                if (haystack[temp] != needle[j])
                    break;
                temp++;
            }
            if (j == m)
                return i;
        }
        return -1;
    }
};