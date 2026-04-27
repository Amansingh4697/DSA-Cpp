/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/


class Solution {
  public:
   int findisSumProperty(Node* root,bool &flag){
       if(root == NULL){
           return 0;
       }
       if(root->left == NULL && root->right == NULL ){
           return root->data;
       }
      int lh = findisSumProperty(root->left,flag);
      int rh = findisSumProperty(root->right,flag);
      if(root->data != (lh+rh)){
          flag = false;
      }
      return root->data;
   }
    bool isSumProperty(Node *root) {
        // code here
        if(!root){
            return true;
        }
        bool flag = true;
        findisSumProperty(root,flag);
        return flag;
    }
};
