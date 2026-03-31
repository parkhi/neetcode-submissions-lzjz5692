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
    int maxDia = 0;
    int maxDepth(TreeNode* root) {
        int hl = 0, hr = 0, maxh = 0;

        if(!root)
            return 0;

        hl = maxDepth(root->left);
        hr = maxDepth(root->right);

        maxh = hl>hr? hl+1 : hr+1;

        return maxh;       
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int hl = 0, hr = 0, dia = 0;
        
        if(!root)
            return 0;

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        hl = maxDepth(root->left);
        hr = maxDepth(root->right);

        dia = hl+hr;

        if(dia > maxDia)
            maxDia = dia;

        return maxDia;

    }
};
