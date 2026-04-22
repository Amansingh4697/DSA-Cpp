#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

bool getpath(TreeNode<int> *root,int x,vector<int> &ans){
	if(!root){
		return false;
	}
	ans.push_back(root->data);
	if(root->data == x){
		return true;
	}
	if(getpath(root->left,x,ans) || getpath(root->right,x,ans)){
		return true;
	}
	ans.pop_back();
	return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> ans;
	getpath(root,x,ans);
	return ans;
}
