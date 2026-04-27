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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<pair<TreeNode*,long>> qe;
        qe.push({root,0});
        int ans = 0;
        while(!qe.empty()){
            int size = qe.size();
            int mmin = qe.front().second;
            int firstidx;
            int lastidx;
            for(int i = 0;i<size;i++){
                TreeNode* node = qe.front().first;
                int currid = qe.front().second - mmin;
                qe.pop();
                if(i == 0) firstidx = currid;
                if(i == size-1) lastidx = currid;
                if(node->left) qe.push({node->left,1L*2*currid + 1});
                if(node->right)  qe.push({node->right,1L*2*currid + 2});
                ans = max(ans,(lastidx-firstidx + 1 ));
            }
        }
        return ans;
    }
};
