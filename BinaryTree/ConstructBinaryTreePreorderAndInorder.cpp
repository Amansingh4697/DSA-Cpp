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
    TreeNode* constructTree(vector<int>  &preorder,int Prestart,int PreEnd, vector<int> &inorder,int Instart,int Inend,map<int,int> &hashInorder){
      if(Prestart>PreEnd || Instart>Inend){
        return NULL;
      }
      TreeNode* node = new TreeNode(preorder[Prestart]);
      int inRoot = hashInorder[node->val];
      int numsLeft = inRoot-Instart;
      node->left = constructTree(preorder,Prestart+1,Prestart+numsLeft,inorder,Instart,inRoot-1,hashInorder); 
      node->right = constructTree(preorder,Prestart+numsLeft+1,PreEnd,inorder,inRoot+1,Inend,hashInorder);
      return node; 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> hashInorder;
        for(int i = 0;i<inorder.size();i++){
            hashInorder[inorder[i]] = i; 
        }
       TreeNode* root =  constructTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,hashInorder);
       return root;
    }
};
