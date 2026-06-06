class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n  = nums.size();
        int ls = 0,rs = 0;
        vector<int>ans(n);
        for(int i = 0;i<n;i++){
            ans[i] = ls;
            ls += nums[i];
        }
        for(int i = n-1;i>=0;i--){
            ans[i] = abs(ans[i]-rs);
            rs+=nums[i];
        }
        return ans;
    }
};