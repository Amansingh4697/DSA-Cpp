/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isLeaf(Node* root){
        return (root->left == NULL && root->right == NULL);
    }
    void leftBoundaryElement(Node* root,vector<int> &res){
        if(root == NULL) return;
        Node* curr = root->left;
        while(curr){
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    void rightBoundaryElement(Node* root,vector<int> &res){
        if(root == NULL) return;
        Node* curr = root->right;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for(int i = temp.size()-1;i>=0;i--){
            res.push_back(temp[i]);
        }
    }
    void leafNodes(Node* root ,vector<int> &res ){
        if(root == NULL) return;
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        leafNodes(root->left ,res);
        leafNodes(root->right ,res);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        if(root == NULL) return res;
        if(!isLeaf(root))res.push_back(root->data);
        leftBoundaryElement(root,res);
        leafNodes(root,res);
        rightBoundaryElement(root,res);
        return res;
    }
};
