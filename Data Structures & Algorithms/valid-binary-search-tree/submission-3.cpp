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
    bool isValidBST(TreeNode* root) {
        return isvalid(root, LONG_MIN, LONG_MAX);      
    }

private:
    bool isvalid(TreeNode* root, long left, long right)
    {
        if(!root)
            return true;
        
        if( (root->val > left) &&
            (root->val < right) &&
            (!root->left || (root->val > root->left->val)) &&
            (!root->right || (root->val < root->right->val)) &&
            isvalid(root->left, left, root->val) &&
            isvalid(root->right, root->val, right)
        ){
            return true;
        }

        return false;
    }
};
