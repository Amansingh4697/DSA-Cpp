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
   int countNodes(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
   bool checkCBT(TreeNode* root,int N,int i){
    if(root == NULL){
        return true;
    }
    if(i>=N){
        return false;
    }
    return checkCBT(root->left,N,2*i+1) && checkCBT(root->right,N,2*i+2);
   }
    bool isCompleteTree(TreeNode* root) {
        TreeNode* temp = root;
        int N = countNodes(temp);
        temp = root;
        return checkCBT(temp,N,0);
    }
};
