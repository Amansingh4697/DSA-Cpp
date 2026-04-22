/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
     void findpaths(Node* root ,vector<vector<int>> &res,vector<int> ans){
       if(root == NULL){
           return;
       }
       ans.push_back(root->data);
       if(root->left == NULL && root->right == NULL){
           res.push_back(ans);
       }
       else{
           findpaths(root->left,res,ans);
           findpaths(root->right,res,ans);
       }
       ans.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> res;
        vector<int> ans;
        if(root == NULL) return res;
        findpaths(root,res,ans);
        return res;
    }
};
