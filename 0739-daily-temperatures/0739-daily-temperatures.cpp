class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int>ans(n,0);
        stack<pair<int,int>>s;

        for(int i = n-1;i>=0;i--){
            while(!s.empty() && s.top().first<= temp[i]) s.pop();
            
            if(!s.empty()) ans[i] = s.top().second - i;

            s.push({temp[i],i});
        }
        return ans;
    }
};