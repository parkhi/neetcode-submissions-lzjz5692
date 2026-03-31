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
using namespace std;
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSerialize(root, res);

        return join(res, ",");        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data, ',');
        int i = 0;

        return dfsDeserialize(vals, i);        
    }

private: 
    TreeNode* dfsDeserialize(vector<string>& vals, int& i){
        if(vals[i] == "N")
        {
            i++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left = dfsDeserialize(vals, i);
        node->right = dfsDeserialize(vals, i);

        return node;
    }

    void dfsSerialize(TreeNode* root, vector<string>& res){

        if(!root){
           res.push_back("N");
           return;
        }

        res.push_back(to_string(root->val));

        dfsSerialize(root->left, res);
        dfsSerialize(root->right, res);
    }

    vector<string> split(const string &s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> res;

        while(getline(ss, item, delim)) {
            res.push_back(item);
        }
        return res;
    }

    string join(const vector<string>& elems, const string& delim) {
        ostringstream ss;

        for(const auto &elem: elems) {
            ss << elem;
            ss << delim;
        }

        return ss.str();
    }
};
