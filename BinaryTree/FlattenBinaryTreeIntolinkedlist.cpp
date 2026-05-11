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
//Appraoch1
class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
       if(root == NULL){
        return;
       }
       flatten(root->right);
       flatten(root->left);
       root->right = prev;
       root->left = nullptr;
       prev = root;
    }
};
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
//Appraoch2
class Solution {
public:
    // TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
    //    if(root == NULL){
    //     return;
    //    }
    //    flatten(root->right);
    //    flatten(root->left);
    //    root->right = prev;
    //    root->left = nullptr;
    //    prev = root;
    if(root == NULL){
        return;
    }
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* curr = st.top();
        st.pop();
        if(curr->right){
            st.push(curr->right);
        }
        if(curr->left){
            st.push(curr->left);
        }
        if(!st.empty()){
            curr->right = st.top();
        }
        curr->left = NULL;
    }
    }
};
//Approach3
if(root == NULL) return;
    TreeNode* curr = root;
    while(curr != NULL){
        if(curr->left != NULL){
            TreeNode* prev = curr->left;
            while(prev->right){
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
