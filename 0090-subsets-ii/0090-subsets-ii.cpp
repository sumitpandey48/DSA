class Solution {
public:
    set<vector<int>> s;
    void solve(vector<int> ip, vector<int> op) {
        if (ip.size() == 0) {
            s.insert(op);
            return;
        }

        vector<int> op1 = op;
        vector<int> op2 = op;

        op2.push_back(ip[0]);

        ip.erase(ip.begin());

        solve(ip, op1);
        solve(ip, op2);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> op;
        solve(nums, op);

        vector<vector<int>> ans;
        for (auto& i : s) {
            ans.push_back(i);
        }

        return ans;
    }
};
