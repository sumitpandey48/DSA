class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int> ans;

       int m = p.size(),n = s.size();

       vector<int> freqP(26,0);

          for(char ch : p)
            freqP[ch-'a']++;

        for(int i=0;i<=n-m;i++){
           vector<int> freqS(26,0);

            for(int j=i;j<i+m;j++)
                freqS[s[j]-'a']++;

            if(freqS==freqP)
                ans.push_back(i);
        }

        return ans;
    }
};