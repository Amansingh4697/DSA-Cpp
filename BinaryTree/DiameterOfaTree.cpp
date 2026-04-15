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
    // int findHeight(TreeNode* root){
    //     if(root == NULL){
    //         return 0;
    //     }
    //     int  lh = findHeight(root->left);
    //     int  rh = findHeight(root->right);
    //     return 1 + max(lh,rh);
    // }
    // void findDiameter(TreeNode* root,int &diameter){
    //     if(root == NULL) return;
    //     int lh = findHeight(root->left);
    //     int rh = findHeight(root->right);
    //     int h = lh + rh;
    //     diameter = max(diameter,h);
    //     findDiameter(root->left,diameter);
    //     findDiameter(root->right,diameter);
    // }
    int findMaxDiameter(TreeNode* root,int &diameter){
            if(root == NULL){
            return 0;
        }
        int  lh = findMaxDiameter(root->left,diameter);
        int  rh = findMaxDiameter(root->right,diameter);
        diameter = max(diameter,lh+rh);
        return 1 + max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
       int diameter = 0;
    //    findDiameter(root,diameter);
      int maxHeight =  findMaxDiameter(root,diameter);
       return diameter;
    }
};
