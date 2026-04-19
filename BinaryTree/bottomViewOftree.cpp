/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> res;
        if(root == nullptr) return res;
        map<int,int> mpp;
        queue<pair<Node*,int>> qe;
        qe.push({root,0});
        while(!qe.empty()){
            int size = qe.size();
            for(int i = 0;i<size;i++){
                auto it = qe.front();
                qe.pop();
                Node* temp = it.first;
                int line = it.second;
                mpp[line] = temp->data;
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
