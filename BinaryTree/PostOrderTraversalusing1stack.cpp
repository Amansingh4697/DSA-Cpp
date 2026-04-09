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
//    void postorder(TreeNode* root,vector<int> &ans){
//     if(root == nullptr) return;
//     postorder(root->left,ans);
//     postorder(root->right,ans);
//     ans.push_back(root->val);
//    }
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // postorder(root,ans);
        // return ans;
        // vector<int> ans;
        // if(root == nullptr) return ans;
        
        // stack<TreeNode*> st1;
        // stack<TreeNode*> st2;
        // st1.push(root);
        // while(!st1.empty()){
        //     TreeNode* node = st1.top();
        //     st1.pop();
        //     st2.push(node);
        //     if(node->left != nullptr) st1.push(node->left); 
        //     if(node->right != nullptr) st1.push(node->right);
        // }
        // while(!st2.empty()){
        //     TreeNode* node = st2.top();
        //     st2.pop();
        //     ans.push_back(node->val);
        // }
        // return ans;

        vector<int> ans;
        if(root == nullptr) return ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr!=NULL || !st.empty()){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode* temp = st.top()->right;
                if(temp == NULL){
                 temp = st.top();
                 st.pop();
                 ans.push_back(temp->val);
                 while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                 }
                }
                else{
                    curr = temp;
                }
            }
        }
        return ans;
    }
};
