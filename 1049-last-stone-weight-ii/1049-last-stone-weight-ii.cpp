class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int i = 0;i <n;i++){
             sum+=stones[i];
        }
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        for(int i = 0;i <= n;i++){
            dp[i][0] = true;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j<=sum;j++){
                if(stones[i-1]<=j){
                  dp[i][j] = dp[i-1][j-stones[i-1]]||dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int ans = INT_MAX;
        for(int j = 0;j<=sum;j++){
          if(dp[n][j]){
            ans = min(ans,abs(sum-2*j));
          }
        }
        return ans;
    }
};