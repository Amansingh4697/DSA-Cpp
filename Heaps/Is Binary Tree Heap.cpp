/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  int countNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
   bool checkCBT(Node* root,int N,int i){
    if(root == NULL){
        return true;
    }
    if(i>=N){
        return false;
    }
    return checkCBT(root->left,N,2*i+1) && checkCBT(root->right,N,2*i+2);
   }
    bool isMaxOrder(Node* root){
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        if(root->right == NULL){
            return (root->data > root->left->data);
        }
        else{
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            if(left && right && root->data > root->left->data &&root->data > root->right->data){
                return true;
            }else{
                return false;
            }
        }
    }
    bool isHeap(Node* tree) {
        // code here
        Node* temp = tree;
        if(temp == NULL) return true;
        int N = countNodes(temp);
        temp = tree;
        if(checkCBT(temp,N,0) && isMaxOrder(temp)){
            return true;
        }
        return false;
    }
};
