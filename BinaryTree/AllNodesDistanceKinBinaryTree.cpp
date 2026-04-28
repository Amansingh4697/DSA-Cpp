/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void marksParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parents_marks){
        if(root == NULL){
            return ;
        }
        if(root->left){
            parents_marks[root->left] = root;
        }
        if(root->right){
            parents_marks[root->right] = root;
        }
        marksParent(root->left,parents_marks);
        marksParent(root->right,parents_marks);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == NULL){
            return {};
        }
        unordered_map<TreeNode*,TreeNode*> parent_marks;
        marksParent(root,parent_marks);
        unordered_map<TreeNode*,bool> visited;
        visited[target] = true;
        queue<TreeNode*> qe;
        qe.push(target);
        int currlen = 0;
        while(!qe.empty()){
            int size = qe.size();
            if(currlen++ == k){
                break;
            } 
            for(int i = 0;i<size;i++){
                TreeNode* node = qe.front();
                qe.pop();
                if(node->left && !visited[node->left]){
                    qe.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    qe.push(node->right);
                    visited[node->right] = true;
                }
                if(parent_marks[node] && !visited[parent_marks[node]]){
                    qe.push(parent_marks[node] );
                    visited[parent_marks[node] ] = true;
                }
            }       
    }
    vector<int> res;
    while(!qe.empty()){
        res.push_back(qe.front()->val);
        qe.pop();
    }
    return res;
    }
};
