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
    // void findIdentical(TreeNode* p, TreeNode* q,bool &flag){
    //     if(p == NULL && q == NULL){
    //         return;
    //     }
    //     if(p == NULL && q != NULL){
    //         flag = false;
    //         return ;
    //     }
    //     if(q == NULL && p != NULL){
    //         flag = false;
    //         return ;
    //     }
    //     if(p->val != q->val){
    //         flag = false;
    //         return ;
    //     }
    //     findIdentical(p->left,q->left,flag);
    //     findIdentical(p->right,q->right,flag);
    // }
    bool isSameTree(TreeNode* p, TreeNode* q) {
    //     bool flag = true;
    //    findIdentical(p,q,flag);
    //    return flag;
    if(q == NULL || p == NULL){
        return (p == q);
    }
    return (q->val == p->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
