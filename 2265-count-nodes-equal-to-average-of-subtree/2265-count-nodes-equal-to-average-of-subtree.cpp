/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> dfs(TreeNode* root, int& cnt) {
        if (root == nullptr) {
            return {0, 0};
        }
        pair<int, int> left = dfs(root->left, cnt);
        pair<int, int> right = dfs(root->right, cnt);

        int sum = left.first + right.first + root->val;
        int nodes = left.second + right.second + 1;

        if (sum / nodes == root->val)
            cnt++;

        return {sum, nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        dfs(root, cnt);
        return cnt;
    }
};