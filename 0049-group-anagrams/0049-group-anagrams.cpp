class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;
        for (int i = 0; i < n; i++) {
            string a = strs[i];
            sort(begin(a), end(a));
            mpp[a].push_back(strs[i]);
        }
        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};