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
    vector<int> topView(Node *root) {
        // code here
    vector<int> res;
    if(root == NULL) return res;
     map<int,int> mpp;
     queue<pair<Node*,int>> qe;
     qe.push({root,0});
     while(!qe.empty()){
         int size = qe.size();
         for(int i = 0;i<size;i++){
             auto it = qe.front();
             qe.pop();
             int line = it.second;
             Node* temp = it.first;
             if(mpp.find(line) == mpp.end()){
                 mpp[line] = temp->data;
             }
             if(temp->left) qe.push({temp->left,line-1});
             if(temp->right) qe.push({temp->right,line+1});
         }
     }
     for(auto it : mpp){
         res.push_back(it.second);
     }
     return res;
    }
};
