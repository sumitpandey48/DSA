class Solution {
public:
    double angleClock(int hour, int minutes) {
        double total_hour = double(hour) + double(minutes)/60;
        double ans = abs(total_hour* 30 - minutes*6);
        if(ans>180){
            ans  = 360 - ans;
        }
        return ans;
    }
};