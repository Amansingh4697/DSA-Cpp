/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* LCA(TreeNode* root,TreeNode* p,TreeNode* q){
     if(root == NULL){
        return NULL;
     }
     if(root == p || root == q){
        return root;
     }
     TreeNode* left =  LCA(root->left,p,q);
     TreeNode* right = LCA(root->right,p,q);
     if(left != NULL && right != NULL){
        return root;
     }
     else if(left != NULL && right == NULL){
        return left;
     }
     else if(left == NULL && right != NULL){
        return right;
     }
     else{
        return NULL;
     }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        return LCA(root,p,q);
    }
};
