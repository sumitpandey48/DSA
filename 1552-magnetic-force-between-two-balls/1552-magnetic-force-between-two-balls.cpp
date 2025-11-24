class Solution {
public:
    int canPlace(vector<int>& position, int m, int d) {
        int cnt = 1;
        int lastpos = position[0];
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastpos >= d) {
                cnt++;
                lastpos = position[i];
            }
            if (cnt >= m)
                return 1;
        }
        return 0;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1, high = position.back() - position.front();

        while (low <= high) {
            int mid = (low + high) / 2;

            if (canPlace(position, m, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};