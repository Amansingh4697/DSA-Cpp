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
class QueueNode{
public:
TreeNode* node;
int vertical;
int level;
};
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<QueueNode> qe;
        qe.push({root,0,0});
        map<int,map<int,multiset<int>>> mpp;
        while(!qe.empty()){
            int size = qe.size();
            for(int i = 0;i<size;i++){
                TreeNode* temp = qe.front().node;
                int v = qe.front().vertical;
                int l = qe.front().level;
                qe.pop();
                mpp[v][l].insert(temp->val);
                if(temp->left) qe.push({temp->left,v-1,l+1});
                if(temp->right) qe.push({temp->right,v+1,l+1});
            }
        }
        for(auto it : mpp){
            vector<int> temp;
            for(auto it2: it.second){
                for(auto val:it2.second){
                    temp.push_back(val);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
