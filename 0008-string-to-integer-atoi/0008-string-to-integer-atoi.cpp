class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ')
            i++;
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }
        long ans = 0;
        while (s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');

            if (ans * sign <= INT_MIN)
                return INT_MIN;
            if (ans * sign >= INT_MAX)
                return INT_MAX;
            i++;
        }
        return (int)(ans * sign);
    }
};