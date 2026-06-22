class Solution {
public:
    int maxNumberOfBalloons(string text) {
       int m[26] = {0};
       for( const char &ch : text){
           m[ch-'a']++;
       }
       int cnt = INT_MAX;
       cnt = min(cnt,m['b'-'a']);
       cnt = min(cnt,m['a'-'a']);
       cnt = min(cnt,m['l'-'a']/2);
       cnt = min(cnt,m['o'-'a']/2);
       cnt = min(cnt,m['n'-'a']);

       return cnt;

    }
};