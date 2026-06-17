class Solution {
public:
    bool checkGoodInteger(int n) {
        long long sum = 0,sumSq = 0;
        while(n>0){
            int a = n % 10;
            sum += a;
            sumSq+= (a * a);
            n = n/10;
        }
        return sumSq - sum >= 50;
    }
};