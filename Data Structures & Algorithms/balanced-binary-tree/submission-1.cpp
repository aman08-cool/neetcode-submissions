/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    int dfs(TreeNode* node, int& ans) {
        if (!node) return 0;

        int lh = dfs(node->left, ans);
        int rh = dfs(node->right, ans);
        ans = max(ans, abs(lh - rh));
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans <= 1;
    }
};
