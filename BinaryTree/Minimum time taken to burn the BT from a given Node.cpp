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
   void markParent(Node* root,unordered_map<Node*,Node*> &parent_track){
       if(root == NULL){
           return;
       }
       if(root->left){
           parent_track[root->left] = root;
       }
       if(root->right){
           parent_track[root->right] = root;
       }
       markParent(root->left,parent_track);
       markParent(root->right,parent_track);
   }
   void  findTargetNode(Node* root,int target,Node* &targetNode){
       if(root == NULL){
           return;
       }
       if(root->data == target){
           targetNode = root;
       }
       findTargetNode(root->left,target,targetNode);
       findTargetNode(root->right,target,targetNode);
   }
    int minTime(Node* root, int target) {
        // code here
      if(root == NULL) return 0;
      unordered_map<Node*,Node*> parent_track;
      markParent(root,parent_track);
      Node* targetNode = NULL;
      findTargetNode(root,target,targetNode);
      queue<Node*> qe;
      qe.push(targetNode);
      unordered_map<Node*,bool> visited;
      visited[targetNode] = true;
      int currtime = 0;
      while(!qe.empty()){
          int size = qe.size();
          bool flag = false;//only increment if catches fire
          for(int i = 0;i<size;i++){
              Node* temp = qe.front();
              qe.pop();
              if(temp->left && !visited[temp->left]){
                  qe.push(temp->left);
                  visited[temp->left] = true;
                  flag = true;
              }
              if(temp->right && !visited[temp->right]){
                  qe.push(temp->right);
                  visited[temp->right] = true;
                  flag = true;
              }
              if(parent_track[temp] && !visited[parent_track[temp]]){
                  qe.push(parent_track[temp]);
                  visited[parent_track[temp]] = true;
                  flag = true;
              }
          }
          if(flag) currtime++;
      }
      return currtime;
    }
};
