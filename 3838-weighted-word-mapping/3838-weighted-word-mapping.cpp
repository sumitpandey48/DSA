class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (string& word : words) {
            int Sum = 0;
            for (char& ch : word) {
                Sum += weights[ch - 'a'];
            }
            ans += 'z' - Sum % 26;
        }
        return ans;
    }
};