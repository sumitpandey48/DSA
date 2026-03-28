class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int mat[1001][1001] = {0};

        for (auto& t : trust) {
            mat[t[0] - 1][t[1] - 1] = 1;
        }

        stack<int> s;
        for (int i = 0; i < n; i++) {
            s.push(i);
        }

        while (s.size() > 1) {
            int A = s.top();
            s.pop();
            int B = s.top();
            s.pop();
            s.push(mat[A][B] ? B : A);
        }

        int c = s.top();
        for (int i = 0; i < n; i++) {
            if (i != c && (mat[c][i] || !mat[i][c]))
                return -1;
        }
        return c + 1;
    }
};
