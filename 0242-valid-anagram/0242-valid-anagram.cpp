class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        unordered_map<char,int>cntS;
        unordered_map<char,int>cntT;
        int i = 0;
        while(i<s.size()){
            cntS[s[i]]++;
            cntT[t[i]]++;
            i++;
        }
        
        return cntS == cntT;
    }
};