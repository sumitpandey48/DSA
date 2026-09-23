class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l = 0;
        long long sum = 0;
        long long ans = 0;
        unordered_map<int,int>mp;
        for(int r = 0;r < nums.size();r++){
            sum+=nums[r];
            mp[nums[r]]++;

            if(r-l+1==k){
              if(mp.size() == k){
                ans = max(ans,sum);
              }
              mp[nums[l]]--;

              if(mp[nums[l]] == 0){
                mp.erase(nums[l]);
              }
              sum-=nums[l++];
            }
        }
        return ans;
    }
};