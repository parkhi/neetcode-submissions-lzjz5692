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
    vector<int> rightSideView(TreeNode* root) {
        
        int level = 0;
        queue<TreeNode*> nodes;
        vector<int> result;
        TreeNode* temp;

        if(root != nullptr)
        {
            nodes.push(root);
        }

        while(!nodes.empty())
        {
            vector<TreeNode*> curlist;
            while(!nodes.empty())
            {
                temp = nodes.front();
                nodes.pop();
                curlist.push_back(temp);
            }
            result.push_back(temp->val);

            for(auto node: curlist)
            {
                if(node->left)
                {
                    nodes.push(node->left);
                }
                if(node->right)
                {
                    nodes.push(node->right);
                }
            }
        }
        
        return result;
    }
};
