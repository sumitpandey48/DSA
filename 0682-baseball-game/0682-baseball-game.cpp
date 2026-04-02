class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;

        for (int i = 0; i < ops.size(); i++) {
            string op = ops[i];
            if (op == "C") {
                s.pop();
            } else if (op == "D") {
                s.push(2 * s.top());
            } else if (op == "+") {
                int top1 = s.top();
                s.pop();
                int top2 = s.top();
                s.push(top1);
                s.push(top1 + top2);
            } else {
                s.push(stoi(op));
            }
        }
        int sum = 0;
        while (!s.empty()) {
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};