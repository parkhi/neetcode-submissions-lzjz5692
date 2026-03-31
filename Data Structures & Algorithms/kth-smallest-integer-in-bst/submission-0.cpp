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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> tmp(2);
        tmp[0] = k;
        tmp[1] = -1;
        inorder(root, tmp);

        return tmp[1];
    }

private:
    void inorder(TreeNode* node, vector<int>& tmp){
        if(!node) return;

        inorder(node->left, tmp);

        if(tmp[0] != 0){
            tmp[0]--;
        }
        cout<<"tmp[0] is "<<tmp[0]<<endl;

        if(tmp[0] == 0){
            if(tmp[1] < 0){
                tmp[1] = node->val;
            }
            return;
        }

        inorder(node->right, tmp);
    }
};
