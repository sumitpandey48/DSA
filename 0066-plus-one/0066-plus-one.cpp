class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        vector<int> result;
        result.push_back(1);
        for (int i = 0; i < n; i++) {
            result.push_back(digits[i]);
        }
        return result;
    }
};
