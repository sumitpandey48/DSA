class Solution {
public:
    void solve(vector<int> op, vector<int> nums, vector<vector<int>>& m) {
        if (nums.size() == 0) {
            m.push_back(op);
            return;
        }

        vector<int> op1 = op;
        vector<int> op2 = op;

        op2.push_back(nums[0]);
        nums.erase(nums.begin());

        solve(op1, nums, m);
        solve(op2, nums, m);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> m;
        vector<int> op;
        solve(op, nums, m);
        return m;
    }
};
