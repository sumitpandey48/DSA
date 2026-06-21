class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0;
        int cnt = 0;
        for (char move : moves) {
            if (move == 'L') {
                x--;
            } else if (move == 'R')
                x++;
            else if (move == 'D')
                y--;
            else if (move == 'U')
                y++;
            else
                cnt++;
        }
        return abs(x) + abs(y) + cnt;
    }
};