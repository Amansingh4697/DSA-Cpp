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
    void findPaths(TreeNode* root,string &path,vector<string> &res){
        if(root == NULL){
            return;
        }
        int l = path.size(); 
        path += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            res.push_back(path);
        }
        else{
            path += "->";
            findPaths(root->left,path,res);
            findPaths(root->right,path,res);
        }  
        path.resize(l);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        vector<string> res;
        findPaths(root,path,res);
        return res;
    }
};
