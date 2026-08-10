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
    unordered_map<int,int> mp;
    int index = 0, n;
    TreeNode* buildTheTree(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if(start > end) return nullptr;

        int rootVal = preorder[index++];
        TreeNode* node = new TreeNode(rootVal);
        int pos = mp[rootVal];
        node->left = buildTheTree(preorder, inorder, start, pos-1);
        node->right = buildTheTree(preorder, inorder, pos+1, end);

        return node;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = preorder.size();
        for(int i = 0 ; i < n ; i++){
            mp[inorder[i]] = i;
        }
        return buildTheTree(preorder, inorder, 0, n-1);
    }
};
