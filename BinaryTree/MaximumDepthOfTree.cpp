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
    // void  findMaxDepth(TreeNode* root,int cnt,int &maxCnt)  {
    //     if(root == NULL){
    //         maxCnt = max(cnt , maxCnt);
    //         return;
    //     }
    //     findMaxDepth(root->left,cnt + 1,maxCnt);
    //     findMaxDepth(root->right,cnt + 1,maxCnt);
    // }
    int maxDepth(TreeNode* root) {
        // int maxCnt = 0;
        // if(root == NULL) return maxCnt;
        // findMaxDepth(root,0,maxCnt);
        // return maxCnt;
        if(root == NULL) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return 1 + max(l,r);
    }
};
