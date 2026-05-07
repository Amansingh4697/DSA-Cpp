/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    TreeNode* node = NULL;
    string res = "";
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string res = "";
        queue<TreeNode*> qe;
        qe.push(root);
        while(!qe.empty()){
            int size  = qe.size();
            for(int i = 0;i<size;i++){
                TreeNode* currNode = qe.front();
                qe.pop();
                if(currNode == NULL){
                    res.append("#,");
                }
                else{
                    res.append(to_string(currNode->val)+',');
                }
                if(currNode!=NULL){
                    qe.push(currNode->left);
                    qe.push(currNode->right);
                }
            }  
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> qe;
        qe.push(root);
        while(!qe.empty()){
            int size = qe.size();
            for(int i = 0;i<size;i++){
                TreeNode* currNode = qe.front();
                qe.pop();
                getline(s,str,',');
                if(str == "#"){
                    currNode->left = NULL;
                }
                else{
                    TreeNode* node = new TreeNode(stoi(str));
                    currNode->left = node;
                    qe.push(node);
                }
                getline(s,str,',');
                if(str == "#"){
                    currNode->right = NULL;
                }
                else{
                    TreeNode* node = new TreeNode(stoi(str));
                    currNode->right = node;
                    qe.push(node);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
