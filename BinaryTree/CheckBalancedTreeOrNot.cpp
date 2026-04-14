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
    // int depth(TreeNode* root){
    //     if(root == NULL) return 0;
    //     int l  = depth(root->left);
    //     int r = depth(root->right);
    //     return 1 + max(l,r);
    // }
    int dfsHeight(TreeNode* root){
        if(root == NULL) return 0;
        int l = dfsHeight(root->left);
        if(l == -1) return -1;
        int r = dfsHeight(root->right);
        if(r == -1) return -1;
        if(abs(l-r)>1) return -1;
        return 1 + max(l,r);
    }
public:
    bool isBalanced(TreeNode* root) {
        // if(root == NULL) return true;
        // int l = depth(root->left);
        // int r = depth(root->right);
        // if(abs(l-r)>1) return false;
        // bool left = isBalanced(root->left);
        // bool right = isBalanced(root->right);
        // if(!left || !right) return false;
        // return true;
        return dfsHeight(root) != -1;
    }
};
