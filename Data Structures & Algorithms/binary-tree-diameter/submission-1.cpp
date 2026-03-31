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
    int maxDepth(TreeNode* root, int& res) {
        int hl = 0, hr = 0, maxh = 0;

        if(!root)
            return 0;

        hl = maxDepth(root->left, res);
        hr = maxDepth(root->right, res);
        maxh = max(hl, hr) + 1;
        res = max(res, hl+hr);

        return maxh;       
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        
        if(!root)
            return 0;

        maxDepth(root, res);

        return res;
    }
};
