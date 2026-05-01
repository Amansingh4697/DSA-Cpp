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
   TreeNode* constructTree(vector<int>  &postorder,int Poststart,int PostEnd, vector<int> &inorder,int Instart,int Inend,map<int,int> &hashInorder){
      if(Poststart>PostEnd || Instart>Inend){
        return NULL;
      }
      TreeNode* node = new TreeNode(postorder[PostEnd]);
      int inRoot = hashInorder[node->val];
      int numsRight = Inend-inRoot;
      node->left = constructTree(postorder,Poststart,PostEnd-numsRight-1,inorder,Instart,inRoot-1,hashInorder); 
      node->right = constructTree(postorder,Poststart-numsRight,PostEnd-1,inorder,inRoot+1,Inend,hashInorder);
      return node; 
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         map<int,int> hashInorder;
        for(int i = 0;i<inorder.size();i++){
            hashInorder[inorder[i]] = i; 
        }
        TreeNode* root = constructTree(postorder,0,postorder.size()-1, inorder,0,inorder.size()-1,hashInorder);
        return root;
    }
};
