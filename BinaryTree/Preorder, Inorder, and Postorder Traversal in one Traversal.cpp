/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
    stack<pair<TreeNode*,int>> st;
    st.push({root,1});
    while(!st.empty()){
        if(st.top().second == 1){
            preorder.push_back(st.top().first->data);
            st.top().second++;
            if(st.top().first->left != NULL){
                st.push({st.top().first->left,1});
            }
        }
        else if(st.top().second == 2){
            inorder.push_back(st.top().first->data);
            st.top().second++;
             if(st.top().first->right != NULL){
                st.push({st.top().first->right,1});
            }
        }
        else if(st.top().second == 3) {
            postorder.push_back(st.top().first->data);
            st.pop();
        }
    }
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
   return ans;
}
